#include <string>

class GoodHours
{

public:
    bool checkTime(int h1, int h2, int m1, int m2){

        // case: h1 = h2*m1*m2
        if (h1 == h2*m1*m2){return true;}

        // case: h1*h2 == m1*m2
        if (h1*h2 == m1*m2){return true;}

        // case: h1*h2*m1 == m2
        if (h1*h2*m1 == m2){return true;}
        
        return false;

    }

    int howMany(std::string beforeTime, std::string afterTime){

        //get starting time and assig to variables
        int h1 = beforeTime[0] - 0;
        int h2 = beforeTime[1] - 0;
        //skip the ":"
        int m1 = beforeTime[3] - 0;
        int m2 = beforeTime[4] - 0;

        
        //end time into ints
        int endh1 = afterTime[0] - 0;
        int endh2 = afterTime[1] - 0;
        //skip the ":"
        int endm1 = afterTime[3] - 0;
        int endm2 = afterTime[4] - 0;

        //loop until time == finish time, keepo count of goof times

        int goodTimeCount = 0;

        if (checkTime(h1,h2,m1,m2)){
            goodTimeCount ++;
            printf("goodcheck");
        }


        //while time not equal to end time
        while (h1 != endh1 && h2 != endh2 && m1 != endm1 && m2 != endm2 ){
            
            //increment time 
            if (m2 < 9){
                m2++;
            }
            else if (m1 < 5){
                m1++;
                m2 = 0;
            }
            else if (h2 < 9 && h1 < 2){
                h2++;
                m1 = 0;
                m2 = 0;
            }
            else if (h1 == 2 && h2 < 3){
                h2++;
                m1 = 0;
                m2 = 0;
            }
            else if (h2 < 2){
                h1++;
                h2 = 0;
                m1 = 0;
                m2 = 0;
            }
            else {
                h1 = 0 ;
                h2 = 0;
                m1 = 0;
                m2 = 0;
            }

            //check if good time 
            if (checkTime(h1,h2,m1,m2)){
            goodTimeCount ++;
            }
            std::cout << h1,h2, ":", m1, m2;

        }
        return goodTimeCount;  
    };
    
};

