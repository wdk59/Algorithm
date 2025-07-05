#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    a--; b--;   // 라운드가 1부터 시작하기 때문에, 2로 나눴을 때 같은 라운드인데도 엇갈릴 수 있다. => 1씩 빼줘서 시작 라운드를 0으로 맞춰줌.
    while (a != b) {
        a = a / 2;
        b = b / 2;
        answer++;
    }

    return answer;
}