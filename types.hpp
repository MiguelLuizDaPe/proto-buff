#ifndef _types_hpp_include_
#define _types_hpp_include_

#include <cstdint>
#include <cstddef>

using int8 = int8_t;
using uint8 = uint8_t;
using int16 = int16_t;
using uint16 = uint16_t;
using int32 = int32_t;
using uint32 = uint32_t;
using int64 = int64_t;
using uint64 = uint64_t;

using float32 = float;
using float64 = double;

static_assert(sizeof(float32) == 4, "FUCK YOU");
static_assert(sizeof(float64) == 8, "FUCK YOU");

using usize = size_t;
using isize = ptrdiff_t;

static_assert(sizeof(usize) == sizeof(isize), "FUCK YOU");

#endif /* Include guard */
