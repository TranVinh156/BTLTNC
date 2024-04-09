#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector <int> A(n);
    vector <int> B(n+1);
    for (int i=0; i<n; i++)
    {
        cin >> A[i];
    }
    for (int i=0; i<n+1; i++)
    {
        cin >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int index = 0;
    for (int i=0; i<n; i++)
    {
        if (A[i] == B[i])
        {
            index++;
        }
        else break;
    }
    cout << B[index] <<endl;
    return 0;
}
