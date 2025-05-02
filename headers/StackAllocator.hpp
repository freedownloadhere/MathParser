#pragma once
#include "Pch.hpp"

template<std::size_t SIZE_BYTES>
class StackAllocator {
public:
	template<class T, class... ConstructParams>
	T* allocate(ConstructParams ...params) {
		static auto destructor = [](void* ptr) { reinterpret_cast<T*>(ptr)->~T(); };
		if (m_idx + sizeof(T) > SIZE_BYTES)
			throw std::bad_alloc();
		T* ptr = reinterpret_cast<T*>(m_bytes + m_idx);
		new (ptr) T(params...);
		m_destructors[m_idx] = destructor;
		m_idx += sizeof(T);
		return ptr;
	};

	void reset() {
		m_idx = 0;
		for (std::size_t i = 0; i < SIZE_BYTES; ++i)
			if (m_destructors[i])
				m_destructors[i](m_bytes + i);
		memset(m_destructors, 0, sizeof(Destructor_t) * SIZE_BYTES);
	}

private:
	using Destructor_t = void(*)(void*);
	std::uint8_t m_bytes[SIZE_BYTES]{};
	// bad
	Destructor_t m_destructors[SIZE_BYTES]{};
	std::size_t m_idx = 0;
};
