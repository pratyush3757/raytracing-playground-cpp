#include "rt_transformations.hpp"
#include <cmath>

rt_matrix_4 rt_transformations::translation(double x, double y, double z) {
    rt_matrix_4 id = rt_matrix_4::id_matrix();
    id.mat[0][3] = x;
    id.mat[1][3] = y;
    id.mat[2][3] = z;
    return id;
}

rt_matrix_4 rt_transformations::scaling(double x, double y, double z) {
    rt_matrix_4 id = rt_matrix_4::id_matrix();
    id.mat[0][0] = x;
    id.mat[1][1] = y;
    id.mat[2][2] = z;
    return id;
}

rt_matrix_4 rt_transformations::rotation_x(double radians) {
    rt_matrix_4 id = rt_matrix_4::id_matrix();
    double cosr = std::cos(radians);
    double sinr = std::sin(radians);
    id.mat[1][1] = cosr;
    id.mat[1][2] = -sinr;
    id.mat[2][1] = sinr;
    id.mat[2][2] = cosr;
    return id;
}

rt_matrix_4 rt_transformations::rotation_y(double radians) {
    rt_matrix_4 id = rt_matrix_4::id_matrix();
    double cosr = std::cos(radians);
    double sinr = std::sin(radians);
    id.mat[0][0] = cosr;
    id.mat[0][2] = sinr;
    id.mat[2][0] = -sinr;
    id.mat[2][2] = cosr;
    return id;
}

rt_matrix_4 rt_transformations::rotation_z(double radians) {
    rt_matrix_4 id = rt_matrix_4::id_matrix();
    double cosr = std::cos(radians);
    double sinr = std::sin(radians);
    id.mat[0][0] = cosr;
    id.mat[0][1] = -sinr;
    id.mat[1][0] = sinr;
    id.mat[1][1] = cosr;
    return id;
}

rt_matrix_4 rt_transformations::shearing(double xy, double xz, double yx, double yz, double zx, double zy) {
    rt_matrix_4 id = rt_matrix_4::id_matrix();
    id.mat[0][1] = xy;
    id.mat[0][2] = xz;
    id.mat[1][0] = yx;
    id.mat[1][2] = yz;
    id.mat[2][0] = zx;
    id.mat[2][1] = zy;
    return id;
}
