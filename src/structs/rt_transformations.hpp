#ifndef RT_TRANSFORMATIONS
#define RT_TRANSFORMATIONS
#include "rt_matrix.hpp"

namespace rt_transformations {
rt_matrix_4 translation(double x, double y, double z);
rt_matrix_4 scaling(double x, double y, double z);
rt_matrix_4 rotation_x(double radians);
rt_matrix_4 rotation_y(double radians);
rt_matrix_4 rotation_z(double radians);
rt_matrix_4 shearing(double xy, double xz, double yx, double yz, double zx, double zy);
}
#endif // !RT_TRANSFORMATIONS
