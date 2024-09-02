#include <math.h>
#include <iostream>
class Multiples
{

public:
    int oldNumber(int min, int max, int factor){

        int maxNumber, minNumber, output;
        
        maxNumber = max/factor;
        minNumber = min/factor;
        
        //std::cout << maxNumber << " " << minNumber;

        
        if (min > 0){
            output = maxNumber - minNumber;
        }
        else {
            output = maxNumber - (minNumber-1);
        }
        return output;
    };
    
    int number(int min, int max, int factor){

        int divisibleCount = 0;
        
        for (int i = min; i <= max; i++)
        {
            if (fmod(i,factor) == 0){
                divisibleCount++;
            }
        }
        
        return divisibleCount;
    }
};

