#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int>& a, pair<int,int>& b){
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    int num = 0;
    map<int,int> m;
   
    for(int i = 1; i < s.length(); i++) {
        if(isdigit(s[i])){
            int num = 0;
            //두 자릿수 이상
            while(isdigit(s[i])) {
                num *= 10;
                num += (s[i] - '0');
                i++;
            }
            if(m.find(num) == m.end())
                m[num] = 1;
            else
                m[num]++;
        }
    }
    vector<pair<int, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(),cmp);
   
    for(int i =0; i < v.size(); i++)
        answer.push_back(v[i].first);
    return answer;
}