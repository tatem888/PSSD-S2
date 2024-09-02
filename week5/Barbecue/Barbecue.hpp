#include <vector>
#include <bits/stdc++.h>

class Barbecue
{

public:
    int eliminate(int n, std::vector<int> voter, std::vector<int> excluded){

        std::vector<int> votesCast(n), votesRecieved(n);
        

        //loop to collect vote casters and recievers
        for (int i = 0; i < n; i++)
        {
            //add to votes cast
            votesCast[voter[i]] = votesCast[voter[i]] + 1;

            //add to votes recieved
            votesRecieved[excluded[i]] = votesRecieved[excluded[i]] + 1;
        }

        int maxVotesRecieved = *std::max_element(votesRecieved.begin(), votesRecieved.end());

        std::vector<int> maxVotesRecievedIndex;

        //add index of highest vote getters to vector
        for (int i = 0; i < n; i++)
        {
            if (maxVotesRecieved == votesRecieved[i])
            {
                maxVotesRecievedIndex.push_back(i);
            }
            
        }

        // if only one highest vote getter, output index

        int output = maxVotesRecievedIndex[0];

        std::vector<int> mostCastValues;

        if (maxVotesRecievedIndex.size() > 1){

            for (int i = 0; i < maxVotesRecievedIndex.size(); i++)
            {
                 mostCastValues.push_back(votesCast[maxVotesRecievedIndex[i]]);
            }
            

        }      
        
        return output;
        
         
    };
    
};
