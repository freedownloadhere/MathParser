#pragma once
#include "Pch.hpp"

#include "MemoryPool.hpp"
#include "Value.hpp"

class FuncTable {
public:
    using UnaryFunc = Value * (*)(MemoryPool&, Value*);
    using BinaryFunc = Value * (*)(MemoryPool&, Value*, Value*);

    FuncTable();

    UnaryFunc getUnary(std::int32_t id);
    BinaryFunc getBinary(std::int32_t id);

private:
    using UnaryFuncTable = std::unordered_map<std::int32_t, UnaryFunc>;
    using BinaryFuncTable = std::unordered_map<std::int32_t, BinaryFunc>;

    UnaryFuncTable m_unaryFuncTable;
    BinaryFuncTable m_binaryFuncTable;
};
