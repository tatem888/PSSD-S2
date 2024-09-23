#include <cstdlib>

class MinimalDifference
{
private:
    int digitSum(int number){

        int digitSum = 0;

        while (number != 0){
            digitSum = digitSum + int(number%10);
            number = int(number/10);
        }

        return digitSum;
    }

public:
    int findNumber(int A, int B, int C){

        int digitSumC = digitSum(C);
        int bestX = A;
        int minDifference = abs(digitSum(A)-digitSumC);

        for (int i = A + 1; i <= B; i++){

            int currentXDigitSum = digitSum(i);
            int currentDifference = abs(currentXDigitSum-digitSumC);
            
            if (currentDifference < minDifference){

                //replace best X and update min diff
                bestX = i;
                minDifference = currentDifference;
            }         
        };
        
        return bestX;
    };

};