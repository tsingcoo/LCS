#include <iostream>
#include "solution.h"

int main() {
    Solution s;
    std::string str1 = "abcde";
    std::string str2 = "bebcd";
    std::string res;
    res = s.lcs(str1, str2);
    std::cout << res << std::endl;
    return 0;
}