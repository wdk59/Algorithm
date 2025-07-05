#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    while (a != b) {
        // a가 홀수, b가 짝수인 경우, 라운드가 엇갈릴 수 있기 때문에 각각 1을 더해준 뒤에 2로 나눔
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        answer++;
    }

    return answer;
}