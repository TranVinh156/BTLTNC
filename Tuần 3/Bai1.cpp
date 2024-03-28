#include <iostream>
#include <string>
using namespace std;

int main() {
	// Complete the program
    string a, b;
    cin >> a >> b;
    char tmp = b[0];
    string c = a+b;
    int len_a = a.length();
    int len_b = b.length();
    b[0] = a[0];
    a[0] = tmp;
    cout << len_a << " " << len_b << endl;
    cout << c <<endl;
    cout << a << " " << b;
    return 0;
}