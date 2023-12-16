#include "rt_cannon.hpp"
#include "rt_tuples.hpp"
#include <cstddef>
#include <iostream>

int main(int argc, char **argv) { 
    rt_cannon::projectile proj = rt_cannon::projectile(
        rt_tuple::point(0, 1, 0),
        rt_tuple::normalize(rt_tuple::vector(1, 1, 0))
    );
    
    rt_cannon::environment env = rt_cannon::environment(
        rt_tuple::vector(0, -0.1, 0),
        rt_tuple::vector(-0.01, 0, 0)
    );

    size_t ticks = 0;
    while (proj.get_position().y() > 0) {
        rt_tuple pos = proj.get_position();
        double x, y, z;
        x = pos.x();
        y = pos.y();
        z = pos.z();
        std::cout << "Position: (" << x << ", " << y << ", " << z << ")" << std::endl;
        ticks++;
        proj = rt_cannon::tick(env, proj);
    }
    std::cout << "Ticks taken: " << ticks << std::endl;

    return 0;
}
