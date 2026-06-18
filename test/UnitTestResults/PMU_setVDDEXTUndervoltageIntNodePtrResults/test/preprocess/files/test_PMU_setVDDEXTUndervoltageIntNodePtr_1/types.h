// CEEDLING NOTICE: This generated file only to be consumed by CMock

#ifndef _TYPES_H_ // Ceedling-generated include guard
#define _TYPES_H_

#include "error_codes.h"
#include "RTE_Components.h"

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

typedef int8_t sint8;
typedef int16_t sint16;
typedef int32_t sint32;
typedef int64_t sint64;

typedef float float32;
typedef double float64;

typedef short FixPoint16;
typedef long FixPoint32;

  typedef FixPoint16 TStdReal;
  typedef FixPoint32 TLongStdReal;
typedef struct StdRealComplex
{
  TStdReal imag;
  TStdReal real;
} TStdRealComplex;

typedef struct
{
  sint16 Real;
  sint16 Imag;
} TComplex;

typedef struct
{
  sint16 A;
  sint16 B;
} TPhaseCurr;

#endif // _TYPES_H_
