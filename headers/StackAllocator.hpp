#pragma once
#include "Pch.hpp"

template<std::size_t SIZE_BYTES>
class StackAllocator {
public:
	template<class T, class... ConstructParams>
	T* allocate(ConstructParams ...params) {
		if (m_idx + sizeof(T) > SIZE_BYTES)
			throw std::bad_alloc();
		T* ptr = reinterpret_cast<T*>(m_bytes + m_idx);
		new (ptr) T(params...);
		m_idx += sizeof(T);
		return ptr;
	};

	void reset() {
		m_idx = 0;
	}

private:
	std::uint8_t m_bytes[SIZE_BYTES]{};
	std::size_t m_idx = 0;
};
