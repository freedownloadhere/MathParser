#pragma once
#include "Pch.hpp"

class Allocator {
public:
	using Dtor = void(*)(void*);

	Allocator(std::size_t howManyBytes) 
		: m_size(howManyBytes), m_bytes(new std::uint8_t[howManyBytes]) {}

	~Allocator() {
		delete[] m_bytes;
	}

	template<class T, class ...CtorParams>
	T* allocate(CtorParams ...params) {
		if (m_idx + sizeof(T) > m_size)
			throw std::bad_alloc();

		void* ptr = m_bytes + m_idx;
		new (ptr) T(std::forward<CtorParams>(params)...);

		Dtor dtor = [](void* ptr) { reinterpret_cast<T*>(ptr)->~T(); };
		m_allocations.emplace_back(ptr, dtor);

		m_idx += sizeof(T);
		return reinterpret_cast<T*>(ptr);
	}

	void reset() {
		m_idx = 0;
		for (const auto& [ptr, dtor] : m_allocations)
			dtor(ptr);
		m_allocations.clear();
	}
	
private:
	struct m_Allocation {
		void* ptr;
		Dtor dtor;
		m_Allocation(void* _ptr, Dtor _dtor) : ptr(_ptr), dtor(_dtor) {}
	};

	std::uint8_t* m_bytes;
	std::size_t m_size;
	std::size_t m_idx;
	std::vector<m_Allocation> m_allocations;
};
