#include "FairWorkload.hpp"
#include <iostream>

int main(){
    FairWorkload a;

    std::vector<int> b = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };

    std::cout << a.getMostWork(b,3);

}