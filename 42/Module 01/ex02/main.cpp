#include <iostream.h>

int main() {
    std::string str = 'HI THIS IS BRAIN';
    std::string strPTR = &str;
    std::string &strREF = str;

    std::cout << 'Memory adress of str: ' << &str << std::endl << 'Memory access of strPTR: ' << strPTR << std::endl << 'Memory access of strREF: ' << &strREF << std::endl << 'Value of str: ' << str << std::endl << 'Value of strPTR: ' << *strPR <<std:: endl << 'Vaslue of strRef: ' << strREF << std::endl;
}