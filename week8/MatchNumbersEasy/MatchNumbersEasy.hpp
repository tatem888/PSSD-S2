#include <vector>
#include <string>

class MatchNumbersEasy
{
private:
    /* data */
public:

    std::string maxNumber(std::vector<int> matches, int n){

        
        int zeroCost = matches[0];
        
        //find lowest cost and index after 0
        int lowestCostIndex = 1;
        for (int i = 1; i < matches.size(); i++)
        {
            if (matches[i] <= matches[lowestCostIndex]){

                lowestCostIndex = i;
            }
        }

        int lowestNonZeroCost = matches[lowestCostIndex];
    

        std::string optimal = std::to_string(lowestCostIndex);

        // first number lowest cost, then zeros until n matches used
        if (zeroCost < lowestNonZeroCost){

            //while matches are left, append 0 to optimal
            while (n >= zeroCost){
                optimal.append("0");
                n -= zeroCost;
            }

        }
        else{
            while (n >= lowestNonZeroCost){
                std::string str = std::to_string(lowestCostIndex);
                optimal.append(str);
                n -= lowestNonZeroCost;
            }
        }

        return optimal;
        
    } 
};
