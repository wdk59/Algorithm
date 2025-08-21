#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string name = "";
    cin >> name;
    cout << (name == "wdk59" ? 1 : 0);
    
    return 0;
}