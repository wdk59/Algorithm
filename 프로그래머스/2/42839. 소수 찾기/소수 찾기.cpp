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

void DFS(string num, string now, vector<bool>& visited, vector<int>& primes) {
    if (now != "" && stoi(now) >= 2) {
        if (isPrime(stoi(now)) && find(primes.begin(), primes.end(), stoi(now)) == primes.end()) {
            primes.push_back(stoi(now));
        }
    }

    for (int i = 0; i < num.length(); i++) {
        if (visited[i] == true) {
            continue;
        }
        visited[i] = true;
        DFS(num, now + num[i], visited, primes);
        visited[i] = false;
    }
}

int solution(string numbers) {
    int answer = 0;

    vector<bool> visited;
    visited.assign(numbers.length(), false);

    vector<int> primes;
    DFS(numbers, "", visited, primes);

    answer = primes.size();

    return answer;
}