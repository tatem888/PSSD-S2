#include <string>
#include <vector>

class Arrows
{

public:
    int longestArrow(std::string s)
    {

        int stringLength = s.length();
        int currentPosition = 0;
        int maxLength = 0;
        int maxArrow = -1;

        while (currentPosition < stringLength)
        {

            // left arrow
            if (s[currentPosition] == '<')
            {
                int currentLength = 1;

                int startCheck = currentPosition + 1;

                if (s[startCheck] = '-' || s[startCheck] == '=')
                {

                    // set search to single or double
                    char singleOrDouble = s[startCheck];

                    // loop until arrow is broken
                    int i = 1;
                    while (s[startCheck + i] == singleOrDouble)
                    {
                        currentLength++;
                        i++;
                    }
                }

                if (currentLength > maxArrow)
                {
                    maxArrow = currentLength;
                }
            }

            // right arrow

            if (s[currentPosition] == '>')
            {
                int currentLength = 1;

                int startCheck = currentPosition - 1;

                if (s[startCheck] = '-' || s[startCheck] == '=')
                {

                    currentLength++;

                    // set search to single or double
                    int singleOrDouble = s[startCheck];

                    // loop until arrow is broken
                    int i = 1;
                    while (startCheck - i == singleOrDouble)
                    {
                        currentLength++;
                        i--;
                    }
                }
        
                if (currentLength > maxArrow)
                {
                    maxArrow = currentLength;
                }
            }

            // increment over the s string
            currentPosition++;
        }

        return maxArrow;
    }
};