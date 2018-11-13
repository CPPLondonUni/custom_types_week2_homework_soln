#include <cassert>
#include <iostream>

#include "conversion.hpp"

namespace {


void test_metres_to_feet()
{
    const cpplu::Metres m{1};
    const auto f = cpplu::to_feet(m);
    assert(f.value == 1.0/0.3048);
}

void test_feet_to_metres()
{
    const auto m = cpplu::to_metres(cpplu::Feet{1});
    assert(m.value == 0.3048);
}

void test_metres_add()
{
    using namespace cpplu;

    Metres m{1};
    m.add(Metres{1.5}).add(Feet{1});

    assert(m.value == 2.5 + to_metres(Feet{1}).value);
}

void test_feet_add()
{
    using namespace cpplu;

    Feet f{1};
    f.add(Metres{1.5}).add(Feet{1});

    assert(f.value == 2 + to_feet(Metres{1.5}).value);
}

void test_to_string()
{
    using namespace cpplu;

    const Metres m{3.142};
    assert(to_string(m) == "3.142m");

    const Feet f{-1.234};
    assert(to_string(f) == "-1.234ft");
}

void test_op_add_assign()
{
    {
        cpplu::Metres m{1};
        m += cpplu::Metres{2.5} += cpplu::Feet{1};
        assert(m.value == 3.5 + cpplu::to_metres({1}).value);
    }

    {
        cpplu::Feet f{1};
        f += cpplu::Metres{0.3048} += cpplu::Feet{1};
        assert(f.value == 3.0);
    }
}

void test_user_defined_literals()
{
    using namespace cpplu;

    const auto m = 1.234_m;
    assert(m.value == 1.234);


    const auto f = 1.234_ft;
    assert(f.value == 1.234);
}

}


struct Logger {
    Logger() { std::cout << "Logger created\n"; }

    ~Logger();
};

Logger::~Logger()
{
    std::cout << "Logger destroyed\n";
}

Logger make_logger() { return Logger{}; }

void take_logger(Logger) {}

int main()
{
    test_metres_to_feet();
    test_feet_to_metres();

    test_metres_add();
    test_feet_add();

    test_to_string();

    test_op_add_assign();

    test_user_defined_literals();

    //Logger l1;
    //auto l2 = l1;
    auto l3 = make_logger();
    take_logger(l3);

    return 0;
}