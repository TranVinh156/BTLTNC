#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int x, int y, vector<vector<int>>& rocks) {
    return rocks[y][x] == 0;
}

bool canEscape(int n, int m, int start, vector<vector<int>>& rocks) {
    int x = start;
    
    for (int y = 1; y < n; ++y) {
        if (x > 0 && isSafe(x - 1, y, rocks)) {
            x--;
        }
        else if (x < m - 1 && isSafe(x + 1, y, rocks)) {
            x++;
        }
        else {
            return false;
        }
    }
    
    return true;
}

int main() {
    int n, m, start;
    cin >> n >> m;
    cin >> start;
    
    vector<vector<int>> rocks(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> rocks[i][j];
        }
    }
    
    if (canEscape(n, m, start, rocks)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
