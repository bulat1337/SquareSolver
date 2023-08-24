#ifndef STRUCTS_H
#define STRUCTS_H

// todo rename (equation_common.h)

struct coefs
{
    double a;
    double b;
    double c;
};

enum answer_identifier
{
    NONE = -1,
    TWO_ROOTS = 2, // todo
    ONE_ROOT = 1,
    NO_ROOT = 0,
    // IMPOSSIBLE_EQUATION,
    INF_ROOTS = 8,
};

#endif
