#include <string>

class DifferentStrings
{
private:
    
public:

    int minimize(std::string A, std::string B){

        //compare a to substrings of b

        int ALength = A.length();
        int BLength = B.length();

        int numberIter = BLength - ALength + 1;
        int minDifference = ALength;

        for (int  i = 0; i < numberIter; i++)
        {
            int substringDifference = 0;

            for (int j = 0; j < ALength; j++)
            {
                if (A[j] != B[i+j])
                {
                    substringDifference++;
                }
                
            }

            if (substringDifference < minDifference){
                minDifference = substringDifference;
            }
        }

        return minDifference;
        
        
    }
    
};
