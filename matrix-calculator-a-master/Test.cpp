#include "doctest.h"
#include "Matrix.hpp"
using namespace zich;
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include <algorithm>
#include <string>
using namespace std;
TEST_CASE("Good input"){
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> identity2 = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    std::vector<double> identity3 = {4, 0, 0, 0, 4, 0, 0, 0, 4};
    std::vector<double> identity4 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    std::vector<double> identity0 = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    std::vector<double> identity2plus = {4, 1, 1, 1, 4, 1, 1, 1, 4};
    std::vector<double> identity2minus = {2, -1, -1, -1, 2, -1, -1, -1, 2};
    Matrix a{identity, 3, 3};
    Matrix b{identity2, 3, 3};
    Matrix to(identity3,3,3);
    Matrix hi(identity4,3,3);
    Matrix ze(identity0,3,3);
    Matrix plus(identity2plus,3,3);
    Matrix minus(identity2minus,3,3);
    CHECK(a+b==to);
    CHECK(b-a==hi);
    CHECK(a*3==b);
    CHECK(hi*a==hi);
    CHECK(to*0==ze);
    CHECK(b>a);
    CHECK(ze<a);
    CHECK(hi<=to);
    CHECK(a*b>=ze);
    CHECK(hi!=ze);
    CHECK(b++==plus);
    CHECK(b--==minus);
    CHECK_NOTHROW(a*=3);
    CHECK_NOTHROW(a*=b);
    CHECK_NOTHROW(a+=b);
    
}
TEST_CASE("Bad input"){
    std::vector<double> first={1,0,0,1};
    std::vector<double> second={1,4,9,3,1,7,5,0,1};
    Matrix a(first,2,2);
    Matrix b(second,3,3);
    Matrix c;
    
    CHECK_THROWS(c=a*b);
    CHECK_THROWS(c=a+b);
    CHECK_THROWS(c=a-b);
    CHECK_THROWS(CHECK_EQ((a>b),true));
    CHECK_THROWS(CHECK_EQ((a>=b),true));
    CHECK_THROWS(CHECK_EQ((a<b),true));
    CHECK_THROWS(CHECK_EQ((a<=b),true));
    CHECK_THROWS(CHECK_EQ((a==b),true));
    CHECK_THROWS(CHECK_EQ((a!=b),true));
    // CHECK_THROWS((a>=b)==true);
    // CHECK_THROWS((a<b)==true);
    // CHECK_THROWS((a<=b)==true);
    // CHECK_THROWS((a==b)==true);
    // CHECK_THROWS((a!=b)==true);

}