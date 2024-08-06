#include <vector>
#include <string>
#include <iostream>


class StreetParking {
    public:

    int freeParks(std::string street){

        //get lenght of street
        int streetLength = street.length();

        //make vector for valid parking spots (Valid = 0, invalid = 1)
        std::vector<int> validParking(streetLength,0);

        char currentPosition;

        for (int i = 0; i < streetLength; i++){

            currentPosition = street[i];
            
            if (currentPosition == 'D')
            {
                validParking[i] = 1;
            }

            else if (currentPosition == 'B')
            { 
                validParking.at(i) = 1;

                try{ validParking.at(i-1) = 1;}
                catch(const std::exception& e){}

                try{ validParking.at(i-2) = 1;}
                catch(const std::exception& e){}

            }
            
            else if (currentPosition == 'S') 
            {
                validParking.at(i) = 1;

                try{ validParking.at(i-1) = 1;}
                catch(const std::exception& e){}

                try{ validParking.at(i+1) = 1;}
                catch(const std::exception& e){}

            }
            
        }

        int freeParks = 0;

        for (int i = 0; i < streetLength; i++)
        {
            if (validParking[i] == 0){

                freeParks += 1;
            }
        }       

        return freeParks;   
    }
};