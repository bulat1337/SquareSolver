#ifndef STRUCTS_H
#define STRUCTS_H

// rename
// equation_common.h

struct Coefs
{
    double a;
    double b;
    double c;
};

enum Answer_identifier
{
    NONE = -1,
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    INF_ROOTS = 8,
};

#endif
