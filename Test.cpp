#include "doctest.h"
#include <stdexcept>
#include <iostream>
#include "sources/Fraction.hpp"
#include <sys/time.h>


TEST_CASE("Checks that the variable has been initialized properly and also checks the correctness of operators") {

    Fraction a1(1,5),a2(1,5),a3(2,10),b(3,5),c(4,5),d(1,25);

    SUBCASE("Checks that the variable has been initialized andChecks that the operator ==") {
        CHECK(a1 == a1);
        CHECK(a1 == a2);
        CHECK(a1 == a3);
        CHECK(a1 == 0.2);
    }
    SUBCASE("Checks that the operators +,-,/,* work well") {
        CHECK(a1 + b == c);
        CHECK(a1 + 0.6 == c);

        CHECK(c - b == a1);
        CHECK(0.8 - 0.6 == a1);

        CHECK(d / a1 == a1);
        CHECK(0.04 / a1 == a1);

        CHECK(a1 * a1 == d);
        CHECK(a1 * 0.2 == d);
    }

    SUBCASE("Checks that the operators <,>,<=,>= work well"){
        CHECK(a1>=a2);
        CHECK(a1<=a2);
        CHECK(a1>=0.1);
        CHECK(a1<=0.3);
        CHECK(b>0.2);
        CHECK(0.2<b);
    }
    SUBCASE("Checks that the operators ++,-- work well"){
        CHECK(a1++<++a2);
        CHECK(a1==a3+1);
        CHECK(a2==a3+1);

        CHECK(a1-->--a2);
        CHECK(a1==a3);
        CHECK(a2==a3);
    }
}

TEST_CASE("Classic definition"){
    struct timeval time_now{};
    for (int i=0; i<2 ;i++) {
        gettimeofday(&time_now, nullptr);
        srand(time_now.tv_usec);
        Fraction a(::rand() % 300, 2), b(::rand() % 200, 4), c(::rand() % 100, 5), one(1, 1), zero(0, 1);
        SUBCASE("Commutativity") {
            CHECK(a + b == b + a);
            CHECK(a * b == b * a);
            CHECK(((a >= b && b <= a) || (!(a >= b) && !(b <= a))));
            CHECK(((a > b && b < a) || (!(a > b) && !(b < a))));
            CHECK(((a == b && b == a) || (!(a == b) && !(b == a))));
        }
        SUBCASE("Associativity") {
            CHECK(a + (b + c) == (a + b) + c);
            CHECK(a * (b * c) == (a * b) * c);
        }
        SUBCASE("Distributivity") {
            CHECK(a * (b + c) == (a * b) + (a * c));
        }

        SUBCASE("Additive and multiplicative identity") {
            CHECK(a + 0 == a);
            CHECK(a * 1 == a);
            CHECK(a + zero == a);
            CHECK(a * one == a);
        }
        SUBCASE("Additive and multiplicative inverses") {
            CHECK(a + (-1 * a) == 0);
            if (!(a == 0)) {
                CHECK(a * (1 / a) == 1);
            }
        }
        SUBCASE("Order of operations") {
            CHECK(a + b * c == a + (b * c));
            CHECK(a * b - c == (a * b) - c);
            if (!(c == 0)) {
                CHECK((a * b) / c == a * (b / c));
                CHECK(a + b / c == a + (b / c));
                CHECK(a / c - b == (a / c) - b);
            }
        }
    }
}


TEST_CASE("A number cannot be divided by 0"){
    Fraction a(1,1),zero(0,1);
    CHECK_THROWS(a/0);
    CHECK_THROWS(a/zero);
    CHECK_THROWS(Fraction {1,0});
}


