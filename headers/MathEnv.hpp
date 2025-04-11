#pragma once

#include <string>
#include <unordered_map>

#include "VariableMap.hpp"

class MathEnv {
public:
	std::int64_t evaluate(const std::string& toEvaluate);

private:
	VariableMap m_variableMap;
};