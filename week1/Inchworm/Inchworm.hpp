#include <stdio.h>
#include <math.h>
using namespace std;

class Inchworm {
  public:
  int lunchtime(int branch, int rest, int leaf) {
    
    //init counter for number of leaves
    int interval = rest;
    int numLeavesEaten = 0;

    //iterate through branch till the end of branch 
    for (int i = 0; i <= branch; i += interval){

        if (fmod(i,leaf) == 0){
            numLeavesEaten++;
        }
    }

    return numLeavesEaten;
    }
  
  };