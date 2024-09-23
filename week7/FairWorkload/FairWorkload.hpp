#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

class FairWorkload
{
private:
    bool greedyPartition(std::vector<int> folders, int workers, int maxWorkLoad){

        //set current work to 0 and start with first worker
        int currentWorkload = 0;
        int worker = 1;
        
        //greedy search to find if workers can form valid partition given the number of workers and the max workload 

        for (int i = 0; i < folders.size(); i++)
        {
            if (currentWorkload + folders[i] > maxWorkLoad){     //if adding another folder would exceed max workload

                //move to next worker and set current folder as current workload
                 worker++;
                 currentWorkload = folders[i];

                 if (worker > workers){ 
                    
                    return false; 
                }  //to many workers are needed, cant partition  
            }
            else {
                //add current folder to workload
                currentWorkload += folders[i];   
            }
        }

        // if loop finished, work was partitioned below max workload
        return true;
    }

public:
    int getMostWork(std::vector<int> folders, int workers){

        //low end of search (max folders in single cabinet)
        int low = *std::max_element(folders.begin(), folders.end());

        //high end of search, sum of all folders
        int high = std::accumulate(folders.begin(),folders.end(),0);

        //binary search
        //While low and high havent converged, find midpoint and check if workers can partition correctly (using greedy search)

        while (low < high) {
            int midPoint = (low+high)/2;

            if (greedyPartition(folders, workers, midPoint)){       //workers can partition, lower max search point
                high = midPoint;
            }                                                       //workers cant partition, raise lowest searchpoint
            else {
                low = midPoint+1;
            }
        }

        //once low and high converge, minimised maximum folder count has been reached
        return low;
        
    };

};