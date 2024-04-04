#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void findUniqueElement(const vector<int>& A, const vector<int>& B) {
    unordered_set<int> setA(A.begin(), A.end());
    for (int num : B) {
        if (setA.find(num) == setA.end()) {
            cout << num << endl;
            return;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> A(n), B(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < n + 1; ++i) {
        cin >> B[i];
    }

    findUniqueElement(A, B);

    return 0;
}