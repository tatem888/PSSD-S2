#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "PrefixFreeSets.hpp"


int main(){

    std::vector<std::string> a = {"topcoder","topcoder","topcoding"}
;

    PrefixFreeSets b;

    std:: cout << b.maxElements(a);


}

