#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <cmath>


class CatGame
{
public:
    int getNumber(std::vector<int> coordinates, int X){

        //get mean of all coordinates
        int numCats = coordinates.size();

        std::sort(coordinates.begin(), coordinates.end());

        float meanPosition = std::round(std::reduce(coordinates.begin(), coordinates.end()) / numCats);
        
        /* 
        int medianPosition;
        if (numCats % 2 ==0){
            medianPosition = (coordinates[numCats/2] + coordinates[numCats/2 - 1]) / 2;
        }
        else{
            medianPosition = coordinates[numCats/2];
        }
        */

       
        //loop over and move cat towards median
        for (int i = 0; i < numCats; i++){
            
            if (coordinates[i] >= meanPosition){
                
                coordinates[i] -= X;
            }
            else {
                coordinates[i] += X;
            } 
        }

        for (int i = 0; i < numCats; i++)
        {
            std::cout << coordinates[i] << " ";
        }
        

        int max = *std::max_element(coordinates.begin(), coordinates.end());
        int min = *std::min_element(coordinates.begin(), coordinates.end());

        return max - min;
    }
};