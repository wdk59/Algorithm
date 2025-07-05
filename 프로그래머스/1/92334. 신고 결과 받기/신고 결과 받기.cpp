#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    // 명단 인덱스 기억
    unordered_map<string, int> id_list_idx;
    for (int i = 0; i < id_list.size(); i++)
        id_list_idx[id_list[i]] = i;
    
    // 신고한 사람과 신고된 사람 map
    unordered_map<string, set<string>> map_report;
    for (auto rep: report) {
        stringstream ss(rep);
        string from, to;
        ss >> from >> to;
        
        map_report[to].insert(from);
    }
    
    for (auto reporter: map_report) {
        if (reporter.second.size() >= k) {
            for (auto it_reported: reporter.second) {
                answer[id_list_idx[it_reported]]++;
            }
        }
    }
    
    return answer;
}