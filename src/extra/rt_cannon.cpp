#include "rt_cannon.hpp"

namespace rt_cannon {
    
rt_cannon::projectile tick(rt_cannon::environment env, rt_cannon::projectile proj) {
    rt_tuple position = proj.get_position() + proj.get_velocity();
    rt_tuple velocity = proj.get_velocity() + env.get_gravity() + env.get_wind();
    return rt_cannon::projectile(position, velocity);
}

}
