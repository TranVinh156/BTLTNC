#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int q;
    cin >> q;

    map<string, int> marks;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            string name;
            int score;
            cin >> name >> score;
            marks[name] += score; 
        } else if (type == 2) {
            string name;
            cin >> name;
            marks.erase(name);
        } else {
            string name;
            cin >> name;
            auto it = marks.find(name);
            if (it != marks.end()) {
                cout << it->second << endl; 
            } else {
                cout << "0" << endl; 
            }
        }
    }

    return 0;
}
