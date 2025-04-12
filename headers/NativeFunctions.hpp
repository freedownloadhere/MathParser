#pragma once
#include "Pch.hpp"

#include "Exception.hpp"
#include "MemoryPool.hpp"
#include "Value.hpp"

namespace NativeFunc {
	RValue* add(MemoryPool& mempool, Value* left, Value* right);
	
	RValue* sub(MemoryPool& mempool, Value* left, Value* right);

	RValue* mul(MemoryPool& mempool, Value* left, Value* right);

	RValue* div(MemoryPool& mempool, Value* left, Value* right);

	RValue* pow(MemoryPool& mempool, Value* left, Value* right);

	LValue* assign(MemoryPool& mempool, Value* left, Value* right);
}
