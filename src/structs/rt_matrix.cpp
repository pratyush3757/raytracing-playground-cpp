#include "rt_matrix.hpp"
#include "rt_transformations.hpp"

rt_matrix_4 rt_matrix_4::translate(double x, double y, double z) {
    return (rt_transformations::translation(x, y, z) * (*this));
}

rt_matrix_4 rt_matrix_4::scale(double x, double y, double z) {
    return (rt_transformations::scaling(x, y, z) * (*this));
}

rt_matrix_4 rt_matrix_4::rotate_x(double radians) {
    return (rt_transformations::rotation_x(radians) * (*this));
}

rt_matrix_4 rt_matrix_4::rotate_y(double radians) {
    return (rt_transformations::rotation_y(radians) * (*this));
}

rt_matrix_4 rt_matrix_4::rotate_z(double radians) {
    return (rt_transformations::rotation_z(radians) * (*this));
}

rt_matrix_4 rt_matrix_4::shear(double xy, double xz, double yx, double yz, double zx, double zy) {
    return (rt_transformations::shearing(xy, xz, yx, yz, zx, zy) * (*this));
}
