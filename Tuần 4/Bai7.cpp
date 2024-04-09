#include <vector>
#include <iostream>

using namespace std;

void canEscape(string *map, int w, int Y, int x, bool &live, int h, vector<vector<bool>> &a)
{
    if (!live)
    {
        if (x < 0 || x == w || a[Y][x])
            return;
        a[Y][x] = true;
        if (Y == h - 1)
        {
            live = true;
            return;
        }
        else
        {
            if ((x <= w - 2) && (map[Y][x + 1] == 'E') && (map[Y + 1][x + 1] != 'R') && !live)
            {
                canEscape(map, w, Y + 1, x + 1, live, h, a);
            }
            if (x >= 1 && map[Y][x - 1] == 'E' && map[Y + 1][x - 1] != 'R' && !live)
            {
                canEscape(map, w, Y + 1, x - 1, live, h, a);
            }
            if (map[Y + 1][x] != 'R' && !live)
            {
                canEscape(map, w, Y + 1, x, live, h, a);
            }
        }
    }
}

int main()
{
    int w, h;
    cin >> w >> h;
    string s[2000];
    for (int i = 0; i < h; i++)
    {
        cin >> s[i];
    }

    int x = s[0].find('Y');

    bool live = false;
    vector<vector<bool>> a(h, vector<bool>(w, false));

    canEscape(s, w, 0, x, live, h, a);
    live ? cout << "YES" : cout << "NO";
    return 0;
}
