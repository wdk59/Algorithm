#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int bottom = triangle.size() - 1;
    while (bottom > 0) {
        for (int i = 0; i < triangle[bottom].size() - 1; i++)
            triangle[bottom - 1][i] += max(triangle[bottom][i], triangle[bottom][i + 1]);
        bottom--;
    }
    
    return triangle[0][0];
}