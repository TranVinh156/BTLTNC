#include <iostream>
#include <set>

using namespace std;

int main() {
    int q;
    cin >> q;

    set<int> s;

    while (q--) {
        int type, val;
        cin >> type >> val;

        if (type == 1) {
            s.insert(val);
        } else if (type == 2) {
            s.erase(val);
        } else {
            auto itr = s.find(val);
            if (itr != s.end()) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}
