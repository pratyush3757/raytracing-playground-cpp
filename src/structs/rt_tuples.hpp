#ifndef RT_TUPLES
#define RT_TUPLES

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
  static bool doubleCompare(double d1, double d2) {
    static constexpr double epsilon = 1.0e-04f;
    if (std::fabs(d1 - d2) <= epsilon)
      return true;
    return std::fabs(d1 - d2) <= epsilon * std::fmax(std::fabs(d1), std::fabs(d2));
  }

private:
  std::tuple<double, double, double, double> t;
};

inline bool operator==(const rt_tuple &u, const rt_tuple &v) {
  return rt_tuple::doubleCompare(u.x(), v.x()) &&
         rt_tuple::doubleCompare(u.y(), v.y()) &&
         rt_tuple::doubleCompare(u.z(), v.z());
}

#endif // !RT_TUPLES
