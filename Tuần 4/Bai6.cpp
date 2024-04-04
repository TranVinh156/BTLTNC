#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int findMiddleNumbers(const vector<int>& A, const vector<int>& B) {
    int uscln = A[0];
    for (int i = 1; i < A.size(); ++i) {
        uscln = gcd(uscln, A[i]);
    }
    
    int bscnn = B[0];
    for (int i = 1; i < B.size(); ++i) {
        bscnn = lcm(bscnn, B[i]);
    }
    
    int count = 0;
    for (int i = uscln; i <= bscnn; i += uscln) {
        if (bscnn % i == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int n, m;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    cin >> m;
    vector<int> B(m);

    for (int i = 0; i < m; ++i) {
        cin >> B[i];
    }
    
    int result = findMiddleNumbers(A, B);
    cout << result << endl;
    
    return 0;
}
