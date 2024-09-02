#include <math.h>
#include <iostream>
class Multiples
{

public:
    
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

