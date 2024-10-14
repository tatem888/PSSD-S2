#include <vector>
#include <numeric>
#include <algorithm>

class CatGame
{
private:
    /* data */
public:
    int getNumber(std::vector<int> coordinates, int X){

        //get mean of all coordinates
        int numCats = coordinates.size();
        int avgPosition = std::reduce(coordinates.begin(), coordinates.end()) / numCats;

       
        //loop over and move cat towards median
        for (int i = 0; i < numCats; i++){
            
            if (coordinates[i] >= X){
                
                coordinates[i] -= X;
            }
            else {
                coordinates[i] += X;
            } 
        }

        int max = *std::max_element(coordinates.begin(), coordinates.end());
        int min = *std::min_element(coordinates.begin(), coordinates.end());

        return max - min;
    }
};