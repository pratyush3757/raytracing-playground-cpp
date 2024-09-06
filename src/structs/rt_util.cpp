#include "rt_util.hpp"

#include <cmath>
/*  Compares doubles with relative tolerence to their magnitudes
   *  The source I first referred to write this:
   *  https://embeddeduse.com/2019/08/26/qt-compare-two-floats/
   *  But the reason to follow this approach is given here:
   *  https://realtimecollisiondetection.net/blog/?p=89
   *  https://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/
   */
bool equal(const double d1, const double d2) {
    static constexpr double epsilon = 1.0e-04f;
    if (std::fabs(d1 - d2) <= epsilon) {
        return true;
    }
    return std::fabs(d1 - d2) <= epsilon * std::fmax(std::fabs(d1), std::fabs(d2));
}
