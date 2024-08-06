#include "AzimuthMonitoring.hpp"
#include <iostream>

int main(){

    AzimuthMonitoring a;

    std::cout << a.getAzimuth({"LEFT"});

    std::cout << fmod(-90,360);
}