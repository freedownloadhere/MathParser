#pragma once
#include "Pch.hpp"

#include "Allocator.hpp"
#include "FuncTable.hpp"
#include "MemoryPool.hpp"
#include "Value.hpp"

class MathEnv {
public:
	std::int64_t evaluate(const std::string& toEvaluate);

private:
	MemoryPool m_mempool;
	FuncTable m_functable;
	Allocator m_allocator;
};