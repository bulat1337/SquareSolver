#ifndef READERS_H
#define READERS_H

#include "solvers.h"

/// @brief This function reads coefficients and saves them in Coefs struct.
/// @param current_coefs is a pointer to the Coefs struct.
/// @param equation_type_ID identifies the type of the equation:
/// 'q' to read 3 coeffs, 'l' to read 2 coeffs.
/// the function uses read_coef() to read a single coefficient.
void read_coefs_stdin(struct Coefs *current_coefs, int equation_type_ID);

/// @brief This function reads a single coefficient.
/// @param input_src pointer to the source file.
/// @param coef file pointer to the double where coefficient will remain.
void read_coef(FILE* input_src, double *coef);

#endif
