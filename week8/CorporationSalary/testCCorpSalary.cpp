#include <iostream>
#include "CorporationSalary.hpp"

int main(){


    std::vector<std::string> b = {"NYNNYN",
 "NNNNNN",
 "NNNNNN",
 "NNYNNN",
 "NNNNNN",
 "NNNYYN"}
;

    CorporationSalary a;

    std::cout << a.totalSalary(b);
}