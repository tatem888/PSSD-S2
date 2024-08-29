class Multiples
{

public:
    int number(int min, int max, int factor){

        int maxNumber = max/factor;
        int minNumber = min/factor;

        if (min != 0){
            return maxNumber - minNumber;
        }
        else {
            return maxNumber + 1;
        }
    };
    
};

