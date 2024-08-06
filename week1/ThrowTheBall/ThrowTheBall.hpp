#include <stdio.h>
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;

class ThrowTheBall
{
public:
    int timesThrown(int N, int M, int L)
    {

        int numPlayers = N;
        int maxNum = M;
        int passDistance = L;

        int currentPlayer = 0;
        int numPasses = 0;

        // init players vector with 0s (number of recieves per player) and give player 1 one recieve (start with the ball)
        vector<int> players(numPlayers, 0);
        players[currentPlayer] = 1;

        while ((players[currentPlayer]) < maxNum)
        {

            if (players[currentPlayer] % 2 == 0) // Even, Ball goes left
            {
                currentPlayer = (currentPlayer + passDistance) % numPlayers;
                players[currentPlayer]++;
            }

            else // Odd, ball goes right
            {
                currentPlayer = (currentPlayer - passDistance + numPlayers) % numPlayers;
                players[currentPlayer]++;
            }

            numPasses++;
        }

        return numPasses;
    }
};