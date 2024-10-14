#include <string>

class BlackAndWhiteSolitaire
{

public:
    int minimumTurns(std::string cardFront){

        int numCards = cardFront.length();

        int BFirst = 0;
        int WFirst = 0;

        for (int i = 0; i < numCards; i++){
            
            //even num (first num)
            if (i % 2 == 0){
                if (cardFront[i] != 'B'){ BFirst++;}
                if (cardFront[i] != 'W'){ WFirst++;}
            }
            //odd nums
            else {
                if (cardFront[i] != 'W'){ BFirst++;}
                if (cardFront[i] != 'B'){ WFirst++;}
            } 
        }

        return std::min(BFirst, WFirst);
    }
};