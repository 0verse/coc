#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/syscall.h>

//#ifdef __cplusplus
//typedef bool b8;
//#else
typedef _Bool b8;
//#endif
typedef int32_t b32;

typedef float f32;
typedef double f64;

typedef intptr_t iptr;
typedef uintptr_t uptr;
typedef ptrdiff_t isize;
typedef size_t usize;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

#define fi else
#define or else if
#define esac default
#define record typedef struct

// https://stackoverflow.com/questions/34007634/macro-foreach-loop-in-c
#define foreach(item, array) \
    for(int keep = 1, \
            count = 0,\
            size = sizeof (array) / sizeof *(array); \
        keep && count != size; \
        keep = !keep, count++) \
      for(item = (array) + count; keep; keep = !keep)

// https://nullprogram.com/blog/2023/10/08/
#define sizeof(x)    (isize)sizeof(x)
#define alignof(x)   (isize)_Alignof(x)
#define countof(a)   (sizeof(a) / sizeof(*(a)))
#define lengthof(s)  (countof(s) - 1)
#define assert(c)  while (!(c)) __builtin_unreachable()

#define s8(s) (s8){(u8 *)s, lengthof(s)}
typedef struct {
    u8  *data;
    isize len;
} s8;

static s8    s8span(u8 *, u8 *);
static b32   s8equals(s8, s8);
static isize s8compare(s8, s8);
static u64   s8hash(s8);
static s8    s8trim(s8);
//static s8    s8clone(s8, arena *);

void print(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}

void println(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
    printf("\n");
}

// https://github.com/Spydr06/BCause/blob/main/src/libb/libb.c
#define syswr(string) (syscall(SYS_write, 1, (string), strlen((string))))
#define sysln(string) (syscall(SYS_write, 1, (string), strlen((string)))) \
                      ;syscall(SYS_write, 1,  "\n",    strlen("\n"     ))
