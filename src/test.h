#include "solvers.h"

/// @brief This function runs the tests.
/// @param equation_type_ID identifies the tyoe of equation whose tests need to be run.
void test(int equation_type_ID);

/// @brief This function runs the quadratic tests.
/// @param quad_references pointer to the array of structs of references for quadratic equations.
/// @return 1 if test was successful.
/// @return 0 if test was not successful.
int quad_test(const struct Test_setup *quad_references);

/// @brief This function runs the linear tests.
/// @param linear_references pointer to the array of structs of references for linear equations.
/// @return 1 if test was successful.
/// @return 0 if test was not successful.
int linear_test(const struct Test_setup *linear_references);
