#pragma once

class Value {
public:
	enum class Type { LVALUE, RVALUE };



private:
	Type m_type;
};
