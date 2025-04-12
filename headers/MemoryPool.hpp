#pragma once
#include "Pch.hpp"

#include "Value.hpp"

class MemoryPool {
public:
	void storeVariable(const std::string& name, std::int64_t value = 0);

	void storeConstant(std::int64_t value = 0);

	std::int64_t readVariable(const std::string& name) const;

	std::int64_t readConstant(std::int64_t value) const;

	void writeVariable(const std::string& name, std::int64_t value);

	LValue* getVariablePtr(const std::string& name);

	RValue* getConstantPtr(std::int64_t value);

private:
	std::unordered_map<std::string, LValue> m_varmap;
	std::unordered_map<std::int64_t, RValue> m_constpool;
};