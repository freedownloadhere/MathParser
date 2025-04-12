#pragma once
#include "Pch.hpp"

#include "Value.hpp"

class Token {
public:
    class Type {
    public:
		static const Type
			Base,
            Equals,
			Add,
			Subtract,
			Multiply,
			Divide,
			Power,
			Number,
			Label,
			BracketLeft,
			BracketRight;

        static const Type* getFromChar(char c);

        std::int32_t getID() const;

        std::string_view getName() const;

        std::int32_t getPrecedence() const;

    private: 
        static inline std::unordered_map<char, const Type*> m_singleCharToToken{};

        Type() = delete;
        Type(const Type&) = delete;
        Type(Type&&) = delete;

        explicit Type(std::string_view name, std::int32_t precedence, char charMapping = 0);

        std::string_view m_name;
        std::int32_t m_precedence;
        std::int32_t m_id;
    };

    Token(const Type* type);
    Token(const std::int64_t number);
    Token(const std::string& label);

    const Type* getType() const;

    void setType(const Type* type);

    RValue* getRValue() const;

    std::string* getLabel() const;

private:
    const Type* m_type = &Type::Base;

    union Contents {
        std::string* m_label;
        RValue* m_rvalue;
    } m_as{};
};