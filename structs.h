#ifndef STRUCTS_H
#define STRUCTS_H

struct coefs
{
    double a;
    double b;
    double c;
};

enum answer_identifier
{
    TWO_ROOTS,
    ONE_ROOT,
    NO_ROOT,
    IMPOSSIBLE_EQUATION,
    INF_ROOTS
};

#endif
