#pragma once

#include <string>
#include <unordered_map>

class MathEnv {
public:
	std::int64_t evaluate(const std::string& toEvaluate);
};