#pragma once
#include "Pch.hpp"

class Value {
public:
	virtual std::int64_t read() const = 0;
	virtual ~Value() = default;

protected:
	Value(std::int64_t value = 0);

	std::int64_t m_value;
};

class LValue : public Value {
public:
	LValue(std::int64_t value = 0);
	
	std::int64_t read() const override;
	void write(std::int64_t value);
};

class RValue : public Value {
public:
	RValue(std::int64_t value = 0);

	std::int64_t read() const override;
};
