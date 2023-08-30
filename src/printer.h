#ifndef PRINTER_H
#define PRINTER_H

#include "solvers.h"

/// @brief This function prints equation answer through standart output.
/// @param answer_identifier this parameter identifies the amount of roots of the equation.
/// @param x1 first root of the equation that could be printed.
/// @param x2 second root of the equation that could be printed.
/// @return 0 if answer_identifier value is valid.
/// @return -1 if answer_identifier value is invalid.
int print_answer(enum Answer_identifier answer_identifier, double x1, double x2);

#endif
