/**
 * @file macros.h
 * 
 * @brief Declaration of most macros of CAMEL.
 *
 * @author Sergio Madrid
 * @date 8/11/2023
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */

#ifndef CAMEL_MACROS
#define CAMEL_MACROS


#include <stdint.h>
#include <stdbool.h>


#define CAMEL_API inline
#define CAMEL_STATIC static


typedef enum CML_Comparison {
    CML_LOWER = -1,
    CML_EQUAL = 0,
    CML_GREATER = 1,
} CML_Comparison;



// Unsigned int types.
typedef uint8_t  u8;  /** @brief Unsigned 8-bit integer. */
typedef uint16_t u16; /** @brief Unsigned 16-bit integer. */
typedef uint32_t u32; /** @brief Unsigned 32-bit integer. */
typedef uint64_t u64; /** @brief Unsigned 64-bit integer. */

// Signed int types.
typedef int8_t  i8;   /** @brief Signed 8-bit integer. */
typedef int16_t i16;  /** @brief Signed 16-bit integer. */
typedef int32_t i32;  /** @brief Signed 32-bit integer. */
typedef int64_t i64;  /** @brief Signed 64-bit integer. */

// Floating point types.
typedef float  f32;   /** @brief 32-bit floating point number. */
typedef double f64;   /** @brief 64-bit floating point number. */

// Boolean types.
typedef _Bool b8;     /** @brief 8-bit boolean. */
typedef i32 b32;      /** @brief 32-bit boolean. */


// Ensure type sizes.
#if defined(__GNUC__) || defined(__clang__)
    /** @brief Static assert macro */
    #define CML_STATIC_ASSERT _Static_assert
#else
    /** @brief Static assert macro */
    #define CML_STATIC_ASSERT static_assert
#endif

// Unsigned int types.
CML_STATIC_ASSERT(sizeof(u8)  == 1, "u8 is not 1 byte.");
CML_STATIC_ASSERT(sizeof(u16) == 2, "u16 is not 2 bytes.");
CML_STATIC_ASSERT(sizeof(u32) == 4, "u32 is not 4 bytes.");
CML_STATIC_ASSERT(sizeof(u64) == 8, "u64 is not 8 bytes.");

// Signed int types.
CML_STATIC_ASSERT(sizeof(i8)  == 1, "i8 is not 1 byte.");
CML_STATIC_ASSERT(sizeof(i16) == 2, "i16 is not 2 bytes.");
CML_STATIC_ASSERT(sizeof(i32) == 4, "i32 is not 4 bytes.");
CML_STATIC_ASSERT(sizeof(i64) == 8, "i64 is not 8 bytes.");

// Floating point types.
CML_STATIC_ASSERT(sizeof(f32) == 4, "f32 is not 4 bytes.");
CML_STATIC_ASSERT(sizeof(f64) == 8, "f64 is not 8 bytes.");

// Boolean types.
CML_STATIC_ASSERT(sizeof(b8)  == 1, "b8 is not 1 byte.");
CML_STATIC_ASSERT(sizeof(b32) == 4, "b32 is not 4 bytes.");


// Maximum and minimum values.
// Unsigned int types.
#define MAX_U8  0xFF                /** @brief Maximum value of u8 */
#define MIN_U8  0x00                /** @brief Minimum value of u8 */
#define MAX_U16 0xFFFF              /** @brief Maximum value of u16 */
#define MIN_U16 0x0000              /** @brief Minimum value of u16 */
#define MAX_U32 0xFFFFFFFF          /** @brief Maximum value of u32 */
#define MIN_U32 0x00000000          /** @brief Minimum value of u32 */
#define MAX_U64 0xFFFFFFFFFFFFFFFF  /** @brief Maximum value of u64 */
#define MIN_U64 0x0000000000000000  /** @brief Minimum value of u64 */

// Signed int types.
#define MAX_I8  0x7F                /** @brief Maximum value of i8 */
#define MIN_I8  0x80                /** @brief Minimum value of i8 */
#define MAX_I16 0x7FFF              /** @brief Maximum value of i16 */
#define MIN_I16 0x8000              /** @brief Minimum value of i16 */
#define MAX_I32 0x7FFFFFFF          /** @brief Maximum value of i32 */
#define MIN_I32 0x80000000          /** @brief Minimum value of i32 */
#define MAX_I64 0x7FFFFFFFFFFFFFFF  /** @brief Maximum value of i64 */
#define MIN_I64 0x8000000000000000  /** @brief Minimum value of i64 */

// Floating point types.
#define MAX_F32 0x7F7FFFFF          /** @brief Maximum value of f32 */
#define MIN_F32 0xFF7FFFFF          /** @brief Minimum value of f32 */
#define MAX_F64 0x7FEFFFFFFFFFFFFF  /** @brief Maximum value of f64 */
#define MIN_F64 0xFFEFFFFFFFFFFFFF  /** @brief Minimum value of f64 */



// Type helper macros.
/** @brief Get the name of a type. */
#define typename(x) _Generic((x),                                        \
        /* Built-in types */                                             \
        void *: "pointer to void", \
        /* CML basic types */                                            \
        u8: "u8", \
        u16: "u16", \
        u32: "u32", \
        u64: "u64", \
        i8: "i8", \
        i16: "i16", \
        i32: "i32", \
        i64: "i64", \
        f32: "f32", \
        f64: "f64", \
        b8: "b8", \
        u8 *: "pointer to u8", \
        u16 *: "pointer to u16", \
        u32 *: "pointer to u32", \
        u64 *: "pointer to u64", \
        i8 *: "pointer to i8", \
        i16 *: "pointer to i16", \
        i32 *: "pointer to i32", \
        i64 *: "pointer to i64", \
        f32 *: "pointer to f32", \
        f64 *: "pointer to f64", \
        b8 *: "pointer to b8", \
        /* CML complex types */ \
        CML_Vector: "CML_Vector", \
        CML_Vector2: "CML_Vector2", \
        CML_Vector3: "CML_Vector3", \
        CML_Vector4: "CML_Vector4", \
        CML_Matrix: "CML_Matrix", \
        CML_Matrix2x2: "CML_Matrix2x2", \
        CML_Matrix2x3: "CML_Matrix2x3", \
        CML_Matrix2x4: "CML_Matrix2x4", \
        CML_Matrix3x2: "CML_Matrix3x2", \
        CML_Matrix3x3: "CML_Matrix3x3", \
        CML_Matrix3x4: "CML_Matrix3x4", \
        CML_Matrix4x2: "CML_Matrix4x2", \
        CML_Matrix4x3: "CML_Matrix4x3", \
        CML_Matrix4x4: "CML_Matrix4x4", \
        default: "unknown")



// Terminal colors.
#define CML_TERMINAL_RED     "\x1b[31m"  /** @brief Red terminal color */
#define CML_TERMINAL_GREEN   "\x1b[32m"  /** @brief Green terminal color */
#define CML_TERMINAL_YELLOW  "\x1b[33m"  /** @brief Yellow terminal color */
#define CML_TERMINAL_BLUE    "\x1b[34m"  /** @brief Blue terminal color */
#define CML_TERMINAL_MAGENTA "\x1b[35m"  /** @brief Magenta terminal color */
#define CML_TERMINAL_CYAN    "\x1b[36m"  /** @brief Cyan terminal color */
#define CML_TERMINAL_RESET   "\x1b[0m"   /** @brief Reset terminal color */



// Platform detection.
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined(_WIN64)
    #define CML_PLATFORM_WINDOWS
#elif defined(__linux__) || defined(__gnu_linux__)
    #define CML_PLATFORM_LINUX
#if defined(__ANDROID__)
    #define CML_PLATFORM_ANDROID
#endif
#elif defined(__unix__)
    #define CML_PLATFORM_UNIX
#elif defined(__APPLE__) || defined(__MACH__)
    #define CML_PLATFORM_APPLE
    #include <TargetConditionals.h>
    #if TARGET_IPHONE_SIMULATOR == 1
        #define CML_PLATFORM_IOS_SIMULATOR
    #elif TARGET_OS_IPHONE == 1
        #define CML_PLATFORM_IOS
    #elif TARGET_OS_MAC == 1
        #define CML_PLATFORM_MAC
    #endif
#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
    #define CML_PLATFORM_FREEBSD
#else
    #error "Unknown platform"
#endif /* Platform detection. */


#endif /* CAMEL_MACROS */
