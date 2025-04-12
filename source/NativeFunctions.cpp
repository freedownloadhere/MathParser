#include "NativeFunctions.hpp"

RValue* NativeFunc::add(MemoryPool& mempool, Value* left, Value* right) {
	std::int64_t lv = left->read();
	std::int64_t rv = right->read();
	lv += rv;
	mempool.storeConstant(lv);
	return mempool.getConstantPtr(lv);
}

RValue* NativeFunc::sub(MemoryPool& mempool, Value* left, Value* right) {
	std::int64_t lv = left->read();
	std::int64_t rv = right->read();
	lv -= rv;
	mempool.storeConstant(lv);
	return mempool.getConstantPtr(lv);
}

RValue* NativeFunc::mul(MemoryPool& mempool, Value* left, Value* right) {
	std::int64_t lv = left->read();
	std::int64_t rv = right->read();
	lv *= rv;
	mempool.storeConstant(lv);
	return mempool.getConstantPtr(lv);
}

RValue* NativeFunc::div(MemoryPool& mempool, Value* left, Value* right) {
	std::int64_t lv = left->read();
	std::int64_t rv = right->read();
	if (rv == 0)
		throw Exception("Divison by zero is undefined");
	lv /= rv;
	mempool.storeConstant(lv);
	return mempool.getConstantPtr(lv);
}

RValue* NativeFunc::pow(MemoryPool& mempool, Value* left, Value* right) {
	std::int64_t lv = left->read();
	std::int64_t rv = right->read();
	if (lv == 0 && rv == 0)
		throw Exception("0^0 is undefined");
	lv = static_cast<std::int64_t>(std::pow(lv, rv));
	mempool.storeConstant(lv);
	return mempool.getConstantPtr(lv);
}

LValue* NativeFunc::assign(MemoryPool& mempool, Value* left, Value* right) {
	LValue* left_lvalue = dynamic_cast<LValue*>(left);
	if (left_lvalue == nullptr)
		throw Exception("Left operand is not an lvalue");
	std::int64_t rv = right->read();
	left_lvalue->write(rv);
	return left_lvalue;
}
