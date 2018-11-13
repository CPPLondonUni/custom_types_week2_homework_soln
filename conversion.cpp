//
// Created by Tristan Brindle on 13/11/2018.
//

#include "conversion.hpp"

#include <sstream>

namespace cpplu {

constexpr double feet_to_metres = 0.3048;
constexpr double metres_to_feet = 1.0/feet_to_metres;

Feet to_feet(Metres m)
{
    return Feet{m.value * metres_to_feet};
}

Metres to_metres(Feet f)
{
    return {f.value * feet_to_metres};
}

Metres& Metres::add(Metres m)
{
    value += m.value;
    return *this;
}

Feet& Feet::add(Feet f)
{
    value += f.value;
    return *this;
}

std::string to_string(Metres m)
{
    //return std::to_string(m.value) + "m";
    std::ostringstream ss;
    ss << m.value << 'm';
    return ss.str();
}

std::string to_string(Feet f)
{
    std::ostringstream ss;
    ss << f.value << "ft";
    return ss.str();
}

Metres& Metres::add(Feet f)
{
    return add(to_metres(f));
}

Feet& Feet::add(Metres m)
{
    return add(to_feet(m));
}

Metres& Metres::operator+=(cpplu::Metres m)
{
    return add(m);
}

Metres& Metres::operator+=(cpplu::Feet f)
{
    return add(f);
}

Feet& operator+=(Feet& lhs, Feet rhs)
{
    return lhs.add(rhs);
}

Feet& operator+=(Feet& lhs, Metres rhs)
{
    return lhs.add(rhs);
}

Metres operator"" _m(long double val)
{
    return Metres{static_cast<double>(val)};
}

Feet operator"" _ft(long double val)
{
    return {static_cast<double>(val)};
}

} // end namespace cpplu