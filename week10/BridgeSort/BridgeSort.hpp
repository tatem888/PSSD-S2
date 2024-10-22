#include <map>
#include <string>

class BridgeSort
{
private:
    /* data */
public:
    std::string sortedHand(std::string hand){
        
        //create empty dictionary using map

        std::map<int, std::string> cardMap;

        //loop over hand, every two char is a card
        for (int i = 0; i < hand.length(); i+=2)
        {
            
            //substring of hand
            std::string card = hand.substr(i,2);

            //assign key by suit
            int key;

            switch (hand[i])
            {
            case 'D':
                key = 13;
                break;

            case 'H':
                key = 26;
                break;

            case 'S':
                key = 39;
                break;
            
            case 'C':
                key = 0;
                break;
            }

            char cardNum = hand[i+1];

            //add to key based on card number
            if (cardNum == 'A'){
                key+=14;
            }
            else if (cardNum =='K')
            {
                key+=13;
            }
            else if (cardNum =='Q')
            {
                key+=12;
            }
            else if (cardNum =='J')
            {
                key+=11;
            }
            else if (cardNum =='T')
            {
                key+=10;
            }
            else{
                int num = cardNum - '0';
                key+= num;
            }
            
            //assign card and key to map

            cardMap[key] = card;          
        }

        //go through map and append valid cards to sorted string
        std::string sortedString;

        for (auto& [key,value] : cardMap)
        {
            sortedString.append(value);
        }

        return sortedString;
    }
};

