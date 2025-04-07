#pragma once

#include <string>
#include <unordered_map>

class MathEnv {
public:
	int evaluate(const std::string& toEvaluate);

private:
	std::unordered_map<std::string, int> m_variableMap;
};