#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <math.h>
#include <iostream>

class PartySeats
{

public:
    std::vector<std::string> seating(std::vector<std::string> attendees){

        //sort names into boy and girl vector
        std::vector<std::string> boys;
        std::vector<std::string> girls;

        int numberOfGuests = attendees.size();

        if (numberOfGuests < 4){

            std::vector<std::string> output = {};
            return output;
        }
        

        for (int i = 0; i < numberOfGuests; i++)
        {
            std::string s = attendees[i];
            std::stringstream ss(s);

            std::string name, gender;
            
            ss >> name >> gender;

            if(gender == "boy"){
                boys.push_back(name);
            }
            else if (gender == "girl"){
                girls.push_back(name);
            }
            
        }

        //get num of boys and girls
        int numBoys = boys.size();
        int numGirls = girls.size();

        if (numBoys != numGirls){
            std::vector<std::string> output = {};
            return output;
        }

        if (std::fmod(numBoys,2) != 0){
            std::vector<std::string> output = {};
            return output;
        }


        //sort gender vectors
        std::sort(boys.begin(),boys.end());
        std::sort(girls.begin(), girls.end());

        std::cout << boys[0] << boys[1];


        
        std::vector<std::string> output;

        output.push_back("HOST");
        output.push_back("HOSTESS");

        for (int i = 0; i < numBoys; i++)
        {
            bool genderFlip = true;

            if (genderFlip == true){

                output.insert(output.begin()+i+1,boys[i]);
                output.insert(output.begin()+i+1,girls[i]);

            }
            else {
                output.push_back(boys[i]);
                output.push_back(girls[i]);
                
            }

            genderFlip = false;
        }

        return output;
        

    };
};

