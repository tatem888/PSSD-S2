class Multiples
{

public:
    int number(int min, int max, int factor){

        int maxNumber = max/factor;
        int minNumber = min/factor;
        int output;

        if (min != 0){
            output = maxNumber - minNumber;
        }
        else {
            output = maxNumber + 1;
        }
        return output;
    };
    
};

