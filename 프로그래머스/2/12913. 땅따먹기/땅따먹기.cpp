#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    for (int i = 1; i < land.size(); i++) {
        for (int j = 0; j < 4; j++) {
            int max = 0;
            for (int k = 0; k < 4; k++) {
                // 같은 열 제외
                if (j == k)
                    continue;
                
                // 같은 열 아니면
                if (max < land[i - 1][k])
                    max = land[i - 1][k];
            }
            land[i][j] += max;
        }
    }

    return *max_element(land[land.size() - 1].begin(), land[land.size() - 1].end());
}