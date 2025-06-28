#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    
    int c1 = 0, c2 = 0;
    for (string g: goal) {
        if (cards1[c1] == g)
            c1++;
        else if (cards2[c2] == g)
            c2++;
        else
            return "No";
    }
    
    return answer;
}