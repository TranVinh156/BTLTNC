
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int checkA(const vector<int>& a, int n, int k){
    for (int i = 0; i < n; i++)
        if (k % a[i])
            return 0;
    return 1;
}

int checkB(const vector<int>& b, int n, int k){
    for (int i = 0; i < n; i++)
        if (b[i] % k)
            return 0;
    return 1;
}

int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
        cin >> a[a_i];
    }
    vector<int> b(m);
    for(int b_i = 0;b_i < m;b_i++){
        cin >> b[b_i];
    }
    int cnt = 0;
    for (int i = 1; i <= 100; i++)
    if (checkA(a, n, i) && checkB(b, m, i))
        cnt++;
    cout << cnt;
    return 0;
}