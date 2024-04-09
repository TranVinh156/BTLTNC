#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int x, int y, vector<vector<char>>& rocks) {
    return rocks[y][x] == 'E';
}

bool canEscape(int n, int m, int start, vector<vector<char>>& rocks) {
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
    int W, H;
    cin >> W >> H;
    int start;
    vector<vector<char>> rocks(H, vector<char>(W));
    for (int i = 0; i < W; ++i) {
        for (int j = 0; j < H; ++j) {
            cin >> rocks[i][j];
            if (rocks[i][j]=='Y') start = j;
        }
    }
    
    if (canEscape(H, W, start, rocks)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
