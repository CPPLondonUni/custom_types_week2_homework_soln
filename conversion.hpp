//
// Created by Tristan Brindle on 13/11/2018.
//

#ifndef MODULE2_WEEK2_HOMEWORK_SOLN_CONVERSION_HPP
#define MODULE2_WEEK2_HOMEWORK_SOLN_CONVERSION_HPP

#include <string>

namespace cpplu {

struct Feet;

struct Metres {
    double value = 0.0;

    Metres& add(Metres m);
    Metres& add(Feet f);

    Metres& operator+=(Metres m);
    Metres& operator+=(Feet f);
};

struct Feet {
    double value = 0.0;

    Feet& add(Feet f);
    Feet& add(Metres m);
};

Feet& operator+=(Feet& lhs, Feet rhs);
Feet& operator+=(Feet& lhs, Metres rhs);

Feet to_feet(Metres m);

Metres to_metres(Feet f);

std::string to_string(Metres m);
std::string to_string(Feet f);

Metres operator"" _m(long double val);
Feet operator"" _ft(long double val);

}


#endif //MODULE2_WEEK2_HOMEWORK_SOLN_CONVERSION_HPP
