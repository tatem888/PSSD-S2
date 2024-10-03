#include <vector>
#include <string>

class CorporationSalary
{
private:

    std::vector<long> caclulatedSalaries;

    long findCurrentSalary(int currentEmployeeNumber, std::vector<std::string>& relations, int numEmployees, std::string& baseEmployee){


        //if already calculated, return
        
        if (caclulatedSalaries[currentEmployeeNumber] != -1)
            return caclulatedSalaries[currentEmployeeNumber];
        
        std::string currentEmployee = relations[currentEmployeeNumber];
        long total = 0;

        //base case (no subordinates)
        if (currentEmployee == baseEmployee){

            //return salary for base employee
            return caclulatedSalaries[currentEmployeeNumber] = 1;
        }


        //else, add and return all subordinates salary
        
        for (int i = 0; i < numEmployees; i++){

            if (currentEmployee[i] == 'Y'){

                total += findCurrentSalary(i,relations, numEmployees, baseEmployee);
                
            };
        }

        return  caclulatedSalaries[currentEmployeeNumber] = total;
    
    }

public:
    long totalSalary(std::vector<std::string> relations){

        int numEmployees = relations.size();
        std::string baseEmployee(numEmployees, 'N');

        long total = 0;

        caclulatedSalaries = std::vector<long>(numEmployees, -1);

        //loop over all employees

        for (int i = 0; i < numEmployees; i++){

            //check current employee salary
            total += findCurrentSalary(i, relations, numEmployees, baseEmployee);

        }

        
    
        return total;
    
    }
};
