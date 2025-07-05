#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isHead(string a, string b) {
    int i = 0;
    for (i = 0; i < a.length(); i++) {
        if (a[i] != b[i])
            break;
    }
    return i == a.length() ? true : false;
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size() - 1; i++) {
        if (phone_book[i + 1].substr(0, phone_book[i].size()) == phone_book[i])
            return false;
    }
    
    return answer;
}