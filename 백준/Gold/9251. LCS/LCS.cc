#include <iostream>
using namespace std;

int main()
{
  int LCS[1002][1002];
  string str1 = "", str2 = "";
  cin >> str1 >> str2;
  int i, j;
  i = 1;
  while (i <= str1.size())
  {
    j = 1;
    while (j <= str2.size())
    {
      if (str2[j - 1] == str1[i - 1])
      {
        LCS[i][j] = LCS[i - 1][j - 1] + 1;
      }
      else
      {
        LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
      }
      j++;
    }
    i++;
  }
  cout << LCS[i - 1][j - 1];

  return 0;
}