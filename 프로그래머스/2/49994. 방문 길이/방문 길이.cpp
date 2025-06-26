#include <string>
#include <vector>
using namespace std;

bool canGo(int toX, int toY) {
    if (toX < -5 || toX > 5 || toY < -5 || toY > 5)
        return false;
    return true;
}

bool isPassed(int x, int y, int toX, int toY, int dir, vector<vector<vector<bool>>>& visited) {
    x += 5; y += 5;
    toX += 5; toY += 5;
    
    if (visited[x][y][dir]) {
        return true;
    } else {
        visited[x][y][dir] = true;
        visited[toX][toY][(dir + 2) % 4] = true;
        return false;
    }
}

int solution(string dirs) {
    int answer = 0;
    
    int dir = 0, x = 0, y = 0, toX = 0, toY = 0;
    vector<vector<vector<bool>>> visited(11, vector<vector<bool>>(11, vector<bool>(4)));
    
    for (int i = 0; i < dirs.length(); i++) {
        toX = x; toY = y;
        
        if (dirs[i] == 'U') {
            dir = 0;
            toY++;
        } else if (dirs[i] == 'D') {
            dir = 2;
            toY--;
        } else if (dirs[i] == 'R') {
            dir = 1;
            toX++;
        } else if (dirs[i] == 'L') {
            dir = 3;
            toX--;
        }
        
        if (canGo(toX, toY)) {
            if (!isPassed(x, y, toX, toY, dir, visited)) answer++;
            
            x = toX; y = toY;
        }
    }
    
    return answer;
}