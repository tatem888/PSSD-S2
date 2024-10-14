#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

class CatGame
{
private:
    /* data */
public:
    int getNumber(std::vector<int> coordinates, int X){

        //get mean of all coordinates
        int numCats = coordinates.size();

        std::sort(coordinates.begin(), coordinates.end());
        int medianPosition = coordinates[numCats/2];

       
        //loop over and move cat towards median
        for (int i = 0; i < numCats; i++){
            
            if (coordinates[i] >= medianPosition){
                
                coordinates[i] -= X;
            }
            else {
                coordinates[i] += X;
            } 
        }

        for (int i = 0; i < numCats; i++){
            std::cout << coordinates[i] << std::endl;
        }

        int max = *std::max_element(coordinates.begin(), coordinates.end());
        int min = *std::min_element(coordinates.begin(), coordinates.end());

        return max - min;
    }
};