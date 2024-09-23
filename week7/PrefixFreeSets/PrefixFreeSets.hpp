#include <string>
#include <vector>
#include <algorithm>

bool isSuffix(std::string a, std::string b){

    //check if a is bigger than b, if so, cannot be a prefix
    if (a.size() > b.size()){ return false; }

    //compare characters of a with the first a.size characters of b

    for (int i = 0; i < a.size(); i++){
        
        if (a[i] != b[i]){
            return false;
        }

    };

    //letters match, return true
    return true;
    

}

class PrefixFreeSets
{

public:
    int maxElements(std::vector<std::string> words){
        
        //sort list alphabetically and get size

        std::sort(words.begin(), words.end());
        int wordsLength = words.size();

        //init optimal subset
        std::vector<std::string> bestSet;


        //iterate over words
        for (int i = 0; i < wordsLength-1; i++){
            
            //compare current word to next word
            bool suffix = isSuffix(words[i], words[i+1]);

            if (not suffix){
                bestSet.push_back(words[i]);
            }
        
        }

        bestSet.push_back(words[wordsLength-1]);

        return bestSet.size();
        
        
        

    };
    
};


