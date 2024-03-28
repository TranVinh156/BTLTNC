#include <string>
#include <iostream>
using namespace std;

string hackerrankInString(string s) {
    int index =0;
    string a = "hackerrank";
    for (int i= 0; i<s.length(); i++)
    {
        if (s[i]==a[index])
        {
            index++;
        }
    }
    if (index == a.length())
    {
        return "YES";
    }
    return "NO";
}

int main()
{
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        string s;
        cin >> s;
        cout << hackerrankInString(s) <<endl;

    }

}