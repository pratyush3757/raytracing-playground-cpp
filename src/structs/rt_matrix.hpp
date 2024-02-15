#ifndef RT_MATRIX
#define RT_MATRIX


// All Matrix sizes have been defined separately as classes.
// This is to help the compiler optimize the functions for those specific dimensions.
#include "rt_tuples.hpp"
#include <cassert>
#include <cstddef>
class rt_matrix_2 {
public:
  double mat[2][2] = {0};

  rt_matrix_2() = default;
  rt_matrix_2(double u[2][2]) {
    for(size_t i = 0; i < 2; i++) {
      for (size_t j = 0; j < 2; j++) {
        mat[i][j] = u[i][j];
      }
    }
  }

  static rt_matrix_2 id_matrix() {
    rt_matrix_2 res;
    for(size_t i = 0; i < 2; i++) {
      res.mat[i][i] = 1;
    }
    return res;
  }

  static rt_matrix_2 transpose(const rt_matrix_2 &u) {
    rt_matrix_2 res;
    for(size_t i = 0; i < 2; i++) {
      for (size_t j = 0; j < 2; j++) {
        res.mat[j][i] = u.mat[i][j];
      }
    }
    return res;
  }

  static double determinant(const rt_matrix_2 &u) {
    // determinant [[a b][c d]] = ad-bc
    return u.mat[0][0] * u.mat[1][1] - u.mat[0][1] * u.mat[1][0];
  }
};

class rt_matrix_3 {
public:
  double mat[3][3] = {0};

  rt_matrix_3() = default;
  rt_matrix_3(double u[3][3]) {
    for(size_t i = 0; i < 3; i++) {
      for (size_t j = 0; j < 3; j++) {
        mat[i][j] = u[i][j];
      }
    }
  }

  static rt_matrix_3 id_matrix() {
    rt_matrix_3 res;
    for(size_t i = 0; i < 3; i++) {
      res.mat[i][i] = 1;
    }
    return res;
  }

  static rt_matrix_3 transpose(const rt_matrix_3 &u) {
    rt_matrix_3 res;
    for(size_t i = 0; i < 3; i++) {
      for (size_t j = 0; j < 3; j++) {
        res.mat[j][i] = u.mat[i][j];
      }
    }
    return res;
  }

  static rt_matrix_2 submatrix(const rt_matrix_3 &u, size_t row, size_t col) {
    rt_matrix_2 res;
    for(size_t i = 0, res_i = 0; i < 3 && res_i < 2; i++, res_i++) {
      for (size_t j = 0, res_j = 0; j < 3 && res_j < 2; j++, res_j++) {
        if(i == row) {
          i++;
        }
        if(j == col) {
          j++;
        }
        res.mat[res_i][res_j] = u.mat[i][j];
      }
    }
    return res;
  }

  static double minor(const rt_matrix_3 &u, size_t row, size_t col) {
    rt_matrix_2 submat = rt_matrix_3::submatrix(u, row, col);
    return rt_matrix_2::determinant(submat);
  }

  static double cofactor(const rt_matrix_3 &u, size_t row, size_t col) {
    double a = rt_matrix_3::minor(u, row, col);
    if ((row + col) % 2 == 0) {
      return a;
    }
    else {
      return -a;
    }
  }

  static double determinant(const rt_matrix_3 &u) {
    double res = 0;
    for(size_t i = 0; i < 3; i++) {
      res = res + u.mat[0][i] * rt_matrix_3::cofactor(u, 0, i);
    }
    return res;
  }
};

class rt_matrix_4 {
public:
  double mat[4][4] = {0};

  rt_matrix_4() = default;
  rt_matrix_4(double u[4][4]) {
    for(size_t i = 0; i < 4; i++) {
      for (size_t j = 0; j < 4; j++) {
        mat[i][j] = u[i][j];
      }
    }
  }

  static rt_matrix_4 id_matrix() {
    rt_matrix_4 res;
    for(size_t i = 0; i < 4; i++) {
      res.mat[i][i] = 1;
    }
    return res;
  }

  static rt_matrix_4 transpose(const rt_matrix_4 &u) {
    rt_matrix_4 res;
    for(size_t i = 0; i < 4; i++) {
      for (size_t j = 0; j < 4; j++) {
        res.mat[j][i] = u.mat[i][j];
      }
    }
    return res;
  }

  static rt_matrix_3 submatrix(const rt_matrix_4 &u, size_t row, size_t col) {
    rt_matrix_3 res;
    for(size_t i = 0, res_i = 0; i < 4 && res_i < 3; i++, res_i++) {
      for (size_t j = 0, res_j = 0; j < 4 && res_j < 3; j++, res_j++) {
        if(i == row) {
          i++;
        }
        if(j == col) {
          j++;
        }
        res.mat[res_i][res_j] = u.mat[i][j];
      }
    }
    return res;
  }

  static double minor(const rt_matrix_4 &u, size_t row, size_t col) {
    rt_matrix_3 submat = rt_matrix_4::submatrix(u, row, col);
    return rt_matrix_3::determinant(submat);
  }

  static double cofactor(const rt_matrix_4 &u, size_t row, size_t col) {
    double a = rt_matrix_4::minor(u, row, col);
    if ((row + col) % 2 == 0) {
      return a;
    }
    else {
      return -a;
    }
  }

  static double determinant(const rt_matrix_4 &u) {
    double res = 0;
    for(size_t i = 0; i < 4; i++) {
      res = res + u.mat[0][i] * rt_matrix_4::cofactor(u, 0, i);
    }
    return res;
  }

  static bool is_invertible(const rt_matrix_4 &u) {
    return rt_matrix_4::determinant(u) != 0;
  }

  static rt_matrix_4 inverse(const rt_matrix_4 &u) {
    assert(rt_matrix_4::is_invertible(u));

    double determinant = rt_matrix_4::determinant(u);
    rt_matrix_4 res;
    for (size_t i = 0; i < 4; i++) {
      for (size_t j = 0; j < 4; j++) {
        double c = rt_matrix_4::cofactor(u, i, j);
        // Note the j,i not i,j as inverse is transposed
        res.mat[j][i] = c / determinant;
      }
    }
    return res;
  }

  rt_matrix_4 translate(double x, double y, double z);
  rt_matrix_4 scale(double x, double y, double z);
  rt_matrix_4 rotate_x(double radians);
  rt_matrix_4 rotate_y(double radians);
  rt_matrix_4 rotate_z(double radians);
  rt_matrix_4 shear(double xy, double xz, double yx, double yz, double zx, double zy);
};

inline bool operator==(const rt_matrix_2 &u, const rt_matrix_2 &v) {
  for(size_t i = 0; i < 2; i++) {
    for(size_t j = 0; j < 2; j++) {
      if(!rt_tuple::doubleCompare(u.mat[i][j], v.mat[i][j])) {
        return false;
      }
    }
  }
  return true;
}

inline bool operator==(const rt_matrix_3 &u, const rt_matrix_3 &v) {
  for(size_t i = 0; i < 3; i++) {
    for(size_t j = 0; j < 3; j++) {
      if(!rt_tuple::doubleCompare(u.mat[i][j], v.mat[i][j])) {
        return false;
      }
    }
  }
  return true;
}

inline bool operator==(const rt_matrix_4 &u, const rt_matrix_4 &v) {
  for(size_t i = 0; i < 4; i++) {
    for(size_t j = 0; j < 4; j++) {
      if(!rt_tuple::doubleCompare(u.mat[i][j], v.mat[i][j])) {
        return false;
      }
    }
  }
  return true;
}

inline rt_matrix_2 operator*(const rt_matrix_2 &u, const rt_matrix_2 &v) {
  rt_matrix_2 res;
  for(size_t i = 0; i < 2; i++) {
    for(size_t j = 0; j < 2; j++) {
      res.mat[i][j] = u.mat[i][0] * v.mat[0][j]
        + u.mat[i][1] * v.mat[1][j];
    }
  }
  return res;
}

inline rt_matrix_3 operator*(const rt_matrix_3 &u, const rt_matrix_3 &v) {
  rt_matrix_3 res;
  for(size_t i = 0; i < 3; i++) {
    for(size_t j = 0; j < 3; j++) {
      res.mat[i][j] = u.mat[i][0] * v.mat[0][j]
        + u.mat[i][1] * v.mat[1][j]
        + u.mat[i][2] * v.mat[2][j];
    }
  }
  return res;
}

inline rt_matrix_4 operator*(const rt_matrix_4 &u, const rt_matrix_4 &v) {
  rt_matrix_4 res;
  for(size_t i = 0; i < 4; i++) {
    for(size_t j = 0; j < 4; j++) {
      res.mat[i][j] = u.mat[i][0] * v.mat[0][j]
        + u.mat[i][1] * v.mat[1][j]
        + u.mat[i][2] * v.mat[2][j]
        + u.mat[i][3] * v.mat[3][j];
    }
  }
  return res;
}

inline rt_tuple operator*(const rt_matrix_4 &u, const rt_tuple &v) {
  double a[4];
  for(size_t i = 0; i < 4; i++) {
    a[i] = u.mat[i][0] * v.x()
        + u.mat[i][1] * v.y()
        + u.mat[i][2] * v.z()
        + u.mat[i][3] * v.type_val();
  }
  return rt_tuple(a[0], a[1], a[2], a[3]);
}

#endif // !RT_MATRIX
