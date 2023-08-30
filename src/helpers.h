#ifndef HELPERS_H
#define HELPERS_H
#define DBL_IS_ZERO(d_arg) (bool)(cmp_double(d_arg,0) == 0)

/// @brief This function compares two double variables.
/// @param first_double first comparable variable.
/// @param second_double second comparable variable.
/// @return 0 if two comparable variables are *equal*.
/// @return 1 if first comparable variable is *bigger* then the second one.
/// @return 1 if first comparable variable is *smaller* then the second one.
int cmp_double(const double first_double, const double second_double);

/// @brief This function clears stdin buffer.
void clear_buffer(void);

#endif
