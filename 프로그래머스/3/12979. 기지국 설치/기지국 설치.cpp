#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    int range = 2 * w + 1;
    int apart_idx = 1;
    int station_idx = 0;
    
    while (apart_idx <= n) {
        // 전파 닿는 곳 넘어감
        if (station_idx < stations.size() && apart_idx >= stations[station_idx] - w) {
            apart_idx = stations[station_idx] + w + 1;
            station_idx++;
        }
        // 기지국 설치
        else {
            answer++;
            apart_idx += range;
        }
    }

    return answer;
}