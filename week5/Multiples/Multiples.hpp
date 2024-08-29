#include <math.h>
#include <iostream>
class Multiples
{

public:
    int number(int min, int max, int factor){

        int maxNumber, minNumber, output;
        maxNumber = floor(max/factor);
        minNumber = floor(min/factor);
        
        //std::cout << maxNumber << " " << minNumber;

        
        if (min > 0){
            output = maxNumber - minNumber;
        }
        else {
            output = maxNumber - (minNumber-1);
        }
        return output;
    };
    
};

