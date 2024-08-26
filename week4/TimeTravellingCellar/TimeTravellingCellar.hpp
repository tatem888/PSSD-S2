#include <vector>
#include <tuple>
#include <algorithm>

class TimeTravellingCellar
{
private:
    /* data */
public:
    int determineProfit(std::vector<int> profit, std::vector<int> decay){

         
        std::tuple <int,int> profit1;
        std::tuple <int,int> profit2;

        profit1 = std::make_tuple(0,profit[0]);
        profit2 = std::make_tuple(0,0);

        std::tuple <int,int> decay1;
        std::tuple <int,int> decay2;

        decay1 = std::make_tuple(0,decay[0]);
        decay2 = std::make_tuple(0,10001);


        int numberOfCellars = profit.size();


        //loop over profit and decay vectors, store highest and second highest values in respective tuple
        for (int i = 1; i < numberOfCellars; i++)
        {
            
            //profits
            //if current profit is greater than max profit
            if (profit[i] >= std::get<1>(profit1))
            {
                profit1.swap(profit2);

                std::get<0>(profit1) = i;
                std::get<1>(profit1) = profit[i];
            }
            
            //if current profit is 2nd max profit
            else if (profit[i] > std::get<1>(profit2) && profit[i] <= std::get<1>(profit1))
            {
                std::get<0>(profit2) = i;
                std::get<1>(profit2) = profit[i];
            }

            //decay
            //if current decay is smaller than min decay
            if (decay[i] <= std::get<1>(decay1))
            {
                decay1.swap(decay2);

                std::get<0>(decay1) = i;
                std::get<1>(decay1) = decay[i];
            }
            
            //if current decay is 2nd min decay
            else if (decay[i] < std::get<1>(decay2) && decay[i] >= std::get<1>(decay1))
            {
                std::get<0>(decay2) = i;
                std::get<1>(decay2) = decay[i];
  
            }
        
        }

        int output;

        if (std::get<0>(profit1) != std::get<0>(decay1)){

            output = std::get<1>(profit1)-std::get<1>(decay1);
        }
        else 
            output =  std::min((std::get<1>(profit2)-std::get<1>(decay1)),std::get<1>(profit1)-std::get<1>(decay2));

        return output;
    };
    
};

