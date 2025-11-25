#pragma once
#include <stdint.h>
#include <functional>
#include <vector>
#include <tuple>

using std::tuple;
using std::make_tuple;

namespace math {

using i8  = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

using u8  = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

using flt  = double;


template<class Signature>
using Function = std::function<Signature>;


template<typename T>
using Vector = std::vector<T>;

} // namespace math