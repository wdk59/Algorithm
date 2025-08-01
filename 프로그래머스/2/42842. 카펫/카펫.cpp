#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    
    for (int i = 1; i <= yellow / 2; i++)
        if (yellow % i == 0 && brown == (i + yellow / i) * 2 + 4)
            return { yellow / i + 2, i + 2 };
    
    return { 3, yellow + 2 };
}