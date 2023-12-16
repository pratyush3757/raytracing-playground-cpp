#include "rt_tuples.hpp"

class rt_color : public rt_tuple {
public:
  rt_color() : rt_tuple(0,0,0,0) {}
  rt_color(double r, double g, double b) : rt_tuple(r, g, b, 0) {}
  
  // Needed to make operator overloads return rt_color instead of rt_tuple
  // Enables casting rt_tuple to rt_color
  rt_color(const rt_tuple &u) : rt_tuple(std::move(u)) {}

  double r() const { return this->x(); }
  double g() const { return this->y(); }
  double b() const { return this->z(); }

};

inline rt_color operator*(const rt_color &u, const rt_color &v) {
  // Hadamard Product or Schur Product
  return rt_color((u.r() * v.r()),
                  (u.g() * v.g()),
                  (u.b() * v.b()));
}
