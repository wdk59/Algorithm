#include <iostream>
#include <string>
using namespace std;

void print(int n) {
    if (n % 3 == 0 && n % 5 == 0)
        cout << "FizzBuzz";
    else if (n % 3 == 0 && n % 5 != 0)
        cout << "Fizz";
    else if (n % 3 != 0 && n % 5 == 0)
        cout << "Buzz";
    else
        cout << n;
}

int main() {
    string a, b, c;
    cin >> a >> b >> c;

    if (a != "Fizz" && a != "Buzz" && a != "FizzBuzz")
        print(stoi(a) + 3);
    else if (b != "Fizz" && b != "Buzz" && b != "FizzBuzz")
        print(stoi(b) + 2);
    else
        print(stoi(c) + 1);

    return 0;
}
