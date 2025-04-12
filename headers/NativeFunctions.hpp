#pragma once
#include "Pch.hpp"

#include "Exception.hpp"
#include "MemoryPool.hpp"
#include "Value.hpp"

namespace NativeFunc {
	Value* ident(MemoryPool& mempool, Value* op);

	Value* add(MemoryPool& mempool, Value* left, Value* right);

	Value* sub(MemoryPool& mempool, Value* left, Value* right);

	Value* mul(MemoryPool& mempool, Value* left, Value* right);

	Value* div(MemoryPool& mempool, Value* left, Value* right);

	Value* pow(MemoryPool& mempool, Value* left, Value* right);

	Value* assign(MemoryPool& mempool, Value* left, Value* right);
}
