#pragma once

#include <string>
#include <unordered_map>

#include "MemoryPool.hpp"

class MathEnv {
public:
	std::int64_t evaluate(const std::string& toEvaluate);

private:
	MemoryPool m_variableMap;
};