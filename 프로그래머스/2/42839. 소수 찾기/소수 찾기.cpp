#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isPrime(int num) {
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void DFS(string num, int numPos, string now, vector<bool>& visited, vector<int>& primes) {
    now += num[numPos];

    // now가 0, 1인 경우에는 소수가 될 수 없으므로 now가 2 이상일 때만 소수 검사
    if (stoi(now) >= 2) {
        if (isPrime(stoi(now)) && find(primes.begin(), primes.end(), stoi(now)) == primes.end()) {
            primes.push_back(stoi(now));
        }
    }

    for (int i = 0; i < num.length(); i++) {
        if (visited[i] == true) {
            continue;
        }
        visited[i] = true;
        DFS(num, i, now, visited, primes);
        visited[i] = false;
    }
}

int solution(string numbers) {
    int answer = 0;

    vector<bool> visited;
    visited.assign(numbers.length(), false);

    vector<int> primes;
    for (int i = 0; i < numbers.length(); i++) {
        visited[i] = true;
        DFS(numbers, i, "", visited, primes);
        visited[i] = false;
    }

    answer = primes.size();

    return answer;
}