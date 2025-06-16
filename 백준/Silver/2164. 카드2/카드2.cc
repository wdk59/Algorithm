#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 0;
    queue<int> cards;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cards.push(i);

    while (cards.size() > 1) {
        cards.pop();
        cards.push(cards.front());
        cards.pop();
    }

    cout << cards.front();

    return 0;
}
