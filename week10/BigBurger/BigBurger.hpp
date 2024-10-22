#include <vector>

class BigBurger
{
private:
    /* data */
public:
    int maxWait(std::vector<int> arrival, std::vector<int> service){

        int currentTime = 0;
        int numCustomers = arrival.size();
        int maxWait = 0;

        for (int i = 0; i < numCustomers; i++)
        {
            int currentWait = 0;
            //if current time is before arrival time of next customer set current time to arrival, wait stays 0
            if (currentTime < arrival[i]){
                currentTime = arrival[i];
                
            }
            //else, wait time is difference between current time and arrival time
            else {
                currentWait = currentTime-arrival[i];
            }

            //then, add service time to current time to update current time
            currentTime += service[i];

            //check if this customers wait was longer than current max wait, update if needed
            if (currentWait > maxWait)
            {
                maxWait = currentWait;
            }
        }
        
        return maxWait;
        
    }
};