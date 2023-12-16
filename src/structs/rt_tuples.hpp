#ifndef RT_TUPLES
#define RT_TUPLES

#include <cassert>
#include <cmath>
#include <tuple>

class rt_tuple {
public:
  rt_tuple() : t{0, 0, 0, 0} {}
  rt_tuple(double t0, double t1, double t2, double t3) : t{t0, t1, t2, t3} {}

  static rt_tuple point(double t0, double t1, double t2) {
    return rt_tuple(t0, t1, t2, 1);
  }
  static rt_tuple vector(double t0, double t1, double t2) {
    return rt_tuple(t0, t1, t2, 0);
  }

  double x() const { return std::get<0>(t); }
  double y() const { return std::get<1>(t); }
  double z() const { return std::get<2>(t); }
  double type_val() const { return std::get<3>(t); }
  bool is_point() const { return std::get<3>(t) == 1; }
  bool is_vector() const { return std::get<3>(t) == 0; }

  /*  Compares doubles with relative tolerence to their magnitudes
   *  The source I first referred to write this:
   *  https://embeddeduse.com/2019/08/26/qt-compare-two-floats/
   *  But the reason to follow this approach is given here:
   *  https://realtimecollisiondetection.net/blog/?p=89
   *  https://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/
   */
  static bool doubleCompare(const double d1, const double d2) {
    static constexpr double epsilon = 1.0e-04f;
    if (std::fabs(d1 - d2) <= epsilon) {
      return true;
    }
    return std::fabs(d1 - d2) <= epsilon * std::fmax(std::fabs(d1), std::fabs(d2));
  }

  static double magnitude(const rt_tuple &u) {
    // assert(u.is_vector());
    return std::sqrt((u.x() * u.x()) 
              + (u.y() * u.y()) 
              + (u.z() * u.z())
              + (u.type_val() * u.type_val()));
  }

  static rt_tuple normalize(const rt_tuple &u) {
    const double mag = magnitude(u);
    return rt_tuple((u.x() / mag),
                    (u.y() / mag),
                    (u.z() / mag),
                    (u.type_val() / mag));
  }

  static double dot(const rt_tuple &u, const rt_tuple &v) {
    return ((u.x() * v.x()) 
    + (u.y() * v.y())
    + (u.z() * v.z())
    + (u.type_val() * v.type_val()));
  }

  static rt_tuple cross(const rt_tuple &u, const rt_tuple &v) {
    assert(u.is_vector());
    assert(v.is_vector());
    return rt_tuple::vector((u.y() * v.z() - u.z() * v.y()), 
                            (u.z() * v.x() - u.x() * v.z()), 
                            (u.x() * v.y() - u.y() * v.x()));
  }

private:
  std::tuple<double, double, double, double> t;
};

inline bool operator==(const rt_tuple &u, const rt_tuple &v) {
  return rt_tuple::doubleCompare(u.x(), v.x()) &&
         rt_tuple::doubleCompare(u.y(), v.y()) &&
         rt_tuple::doubleCompare(u.z(), v.z());
}

inline rt_tuple operator+(const rt_tuple &u, const rt_tuple &v) {
  double x = u.x() + v.x();
  double y = u.y() + v.y();
  double z = u.z() + v.z();
  double type_val = u.type_val() + v.type_val();
  // assert(type_val >= 0 && type_val <= 1);
  return rt_tuple(x,y,z,type_val);
}

inline rt_tuple operator-(const rt_tuple &u, const rt_tuple &v) {
  double x = u.x() - v.x();
  double y = u.y() - v.y();
  double z = u.z() - v.z();
  double type_val = u.type_val() - v.type_val();
  // assert(type_val >= 0 && type_val <= 1);
  return rt_tuple(x,y,z,type_val);
}

inline rt_tuple operator-(const rt_tuple &u) {
  return rt_tuple(-u.x(), -u.y(), -u.z(), -u.type_val());
}

inline rt_tuple operator*(const rt_tuple &u, const double v) {
  return rt_tuple(u.x() * v, u.y() * v, u.z() * v, u.type_val() * v);
}

inline rt_tuple operator/(const rt_tuple &u, const double v) {
  return rt_tuple(u.x() / v, u.y() / v, u.z() / v, u.type_val() / v);
}

#endif // !RT_TUPLES
