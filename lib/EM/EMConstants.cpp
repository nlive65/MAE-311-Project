#include "EMConstants.hpp"
#include <cmath>
double EM::magnitude(EM::cartesian vec){
    return std::sqrt(vec.x*vec.x+vec.y+vec.y+vec.z*vec.z);
}