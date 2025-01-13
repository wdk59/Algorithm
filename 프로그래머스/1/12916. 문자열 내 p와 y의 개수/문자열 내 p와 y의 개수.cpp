#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    transform(s.begin(), s.end(), s.begin(), ::tolower);
    answer = (count(s.begin(), s.end(), 'p') == count(s.begin(), s.end(), 'y')) ? true : false;

    return answer;
}