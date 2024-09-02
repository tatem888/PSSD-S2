#include <vector>
#include <bits/stdc++.h>
#include <iostream>

class Barbecue
{

public:
    int eliminate(int n, std::vector<int> voter, std::vector<int> excluded){

        std::vector<int> votesCast(n), votesRecieved(n);
        

        //loop to collect vote casters and recievers
        for (int i = 0; i < voter.size(); i++)
        {
            //add to votes cast
            votesCast[voter[i]] ++;

            //add to votes recieved
            votesRecieved[excluded[i]] ++;
        }

        //find max votes recieved
        int maxVotesRecieved = *std::max_element(votesRecieved.begin(), votesRecieved.end());

        std::vector<int> excludedCandidates;

        //add index of highest vote getters to vector
        for (int i = 0; i < n; i++)
        {
            if (maxVotesRecieved == votesRecieved[i])
            {
                excludedCandidates.push_back(i);
            }
            
        }

        //resolve tie

        if (excludedCandidates.size() > 1){
            
            int maxVotesCast = -1;
            int maxVoteCaster = -1;
            

            for (int i : excludedCandidates)
            {
                if (votesCast[i] > maxVotesCast){
                    maxVotesCast = votesCast[i];
                    maxVoteCaster = i;
                }
            }
            excludedCandidates.clear();
            excludedCandidates.push_back(maxVoteCaster);

        }
               


        return excludedCandidates[0];
        
         
    };
    
};
