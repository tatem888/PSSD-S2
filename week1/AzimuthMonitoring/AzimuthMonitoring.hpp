#include <vector>
#include <string>
#include <math.h>

class AzimuthMonitoring
{

public:
    int getAzimuth(std::vector<std::string> instructions){

        int direction = 0;

        for (int i = 0; i < instructions.size(); i++)
        {
            std::string currentInstruction = instructions[i];

            if (currentInstruction == "LEFT")
            {
                direction = direction - 90;
            }
            else if (currentInstruction == "RIGHT")
            {
                 direction = direction + 90;
            }
            else if (currentInstruction == "TURN AROUND")
            {
                 direction = direction + 180;
            }
            else if (currentInstruction == "HALT")
            {
                 break;
            }

            // Left X and Right X
            else if (currentInstruction.substr(0,4) == "LEFT")
            {
                int xValue = std::stoi(currentInstruction.substr(5));
                direction = direction - xValue;
            }
            else if (currentInstruction.substr(0,5) == "RIGHT")
            {
                int xValue = std::stoi(currentInstruction.substr(6));
                direction = direction + xValue;
            }
        }

        int output = std::fmod(direction,360);

        if (output < 0)
        {
            output = output + 360;
        }
        

        return output;

    };
    
};

