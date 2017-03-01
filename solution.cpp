//
// Created by 王青龙 on 2017/3/1.
//

#include <vector>
#include "solution.h"

std::string Solution::lcs(std::string str1, std::string str2) {
    if (str1.empty() || str2.empty()) {
        return "";
    }
    int l = (int)str1.size();
    int m = (int)str2.size();
    std::vector<std::vector<int>> matrix(l, std::vector<int>(m, 0));
    for (int i = 0; i < l; ++i) {
        matrix[i][0] = str1[i] == str2[0] ? 1 : 0;
    }
    for (int j = 0; j < m; ++j) {
        matrix[0][j] = str1[0] == str2[j] ? 1 : 0;
    }
    for (int i = 1; i < l; ++i) {
        for (int j = 1; j < m; ++j) {
            if (str1[i] == str2[j]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            }
        }
    }

    int max = 0;
    int end = 0;
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
                end = i;
            }
        }
    }
    return str1.substr(end - max + 1, max);

}
