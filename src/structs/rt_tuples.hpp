#ifndef RT_TUPLES
#define RT_TUPLES

#include <tuple>
#include <cmath>

class rt_tuple {
public:
    rt_tuple() : t{0,0,0,0} {}
    rt_tuple(double t0, double t1, double t2, double t3): t{t0, t1, t2, t3} {}

    double x() const { return std::get<0>(t); }
    double y() const { return std::get<1>(t); }
    double z() const { return std::get<2>(t); }
    
    rt_tuple(rt_tuple &&) = default;
    rt_tuple(const rt_tuple &) = default;
    rt_tuple &operator=(rt_tuple &&) = default;
    rt_tuple &operator=(const rt_tuple &) = default;
    ~rt_tuple();

    static bool doubleCompare(double d1, double d2) 
    {
        static constexpr auto epsilon = 1.0e-05f;
        if (std::abs(d1 - d2) <= epsilon)
            return true;
        return std::abs(d1 - d2) <= epsilon * std::fmax(std::abs(d1), std::abs(d2));
    }
private:
    std::tuple<double, double, double, double> t;
};

inline bool operator==(const rt_tuple& u, const rt_tuple& v) {
    return rt_tuple::doubleCompare(u.x(), v.x()) && 
        rt_tuple::doubleCompare(u.y(), v.y()) && 
        rt_tuple::doubleCompare(u.z(), v.z());
}

#endif // !RT_TUPLES
