#include <iostream>
using namespace std;

void generateStrings(char arr[], int n, int length, string str = "") {
    if (length == 0) {
        cout << str << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        string newStr = str + arr[i];
        generateStrings(arr, n, length - 1, newStr);
    }
}

int main() {
    char arr[] = {'a', 'b', 'c', 'd'};
    int n = sizeof(arr) / sizeof(arr[0]);
    int length = 3;
    generateStrings(arr, n, length);
    return 0;
}
