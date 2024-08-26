#include <string>
#include <stack>

class MagicSpell
{

public:
    std::string fixTheSpell(std::string spell){

        //init stack
        std::stack<char> stack;

        int spellLength = spell.length();


        //fill stack with As and Zs

        for (int i = 0; i < spellLength; i++)
        {
            if (spell[i] == 'A' || spell[i] == 'Z')
            {
                stack.push(spell[i]);
            }
        }

        //pop stack back to decrypt spell
        for (int i = 0; i < spellLength; i++)
        {
            if (spell[i] == 'A' || spell[i] == 'Z')
            {
                spell[i] = stack.top();
                stack.pop();
            }
        }

        return spell;

    };
};