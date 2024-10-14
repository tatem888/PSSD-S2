#include <vector>
#include <string>

class Thimbles
{
    
public:

    int thimbleWithBall(std::vector<std::string> swaps){

        int currentPosition = 1;

        for(int i = 0; i < swaps.size(); i++){
            
            std::string currentSwapString = swaps[i];

            int num1 = currentSwapString[0] - '0';
            int num2 = currentSwapString[2] - '0';

            if (currentPosition == num1){
                currentPosition = num2;
            }
            else if (currentPosition == num2){
                currentPosition = num1;
            }
 
        }

        return currentPosition;
       
    }
    
};

