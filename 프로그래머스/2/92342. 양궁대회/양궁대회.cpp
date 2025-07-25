#include <vector>

using namespace std;

// 각 점수의 정답 배열을 0으로 초기화
vector<int> peach;  // info 담을 예정
vector<int> lion = {0,0,0,0,0,0,0,0,0,0,0};
vector<int> answer = {0,0,0,0,0,0,0,0,0,0,0};

int maxScore = 0; // 최대점수

void scoring(){
    int lScore = 0; // 라이언 점수
    int pScore = 0; // 어피치 점수
    
    // 둘 다 0일때를 제외하고, 라이언은 더 잘해야만 득점
    for(int i = 0; i <= 10; i++){
        if(lion[i] == 0 && peach[i] == 0) continue;
        
        if(lion[i] > peach[i]) lScore += 10 - i;
        else pScore += 10 - i;
    }
    int result = lScore - pScore; // 두 사람의 격차
    
    // 라이언이 이기고, 새로운 점수가 기존 점수보다 크거나 같을 때
    if(result >= maxScore && lScore > pScore) {
    	
        // 점수가 같을 때: 제일 낮은 점수의 개수 비교
        if(result == maxScore) {
            for(int i = 10; i >= 0; i--) {
                if(lion[i] > answer[i]) {
                    answer = lion;
                    return;
                }
              	// 가장 낮은 점수보다 기존의 정답 배열이 더 클 때
                else if(lion[i] < answer[i])
                    return;
            }
        }
        // 새로 구한 최종 점수가 더 클때
        else{
            answer = lion;
        }
        
        maxScore = result; // 점수 갱신
    }
}

void lionShoot(int start, int cnt, int& n){
    // 라이언 화살 다 쏘면 점수 계산
    if(cnt == n){
        scoring();
        return;
    }
    
    // 라이언 화살 쏘기
    for(int i = start; i <= 10; i++) {
        lion[i]++;
        lionShoot(i, cnt + 1, n);
        lion[i]--;
    }
}

vector<int> solution(int n, vector<int> info) {
    peach = info;
    lionShoot(0, 0, n);
    
    // 최종 점수가 0점이라면 실패
    if(maxScore == 0) {
        answer.clear();
        answer.push_back(-1);
    }
    return answer;
}