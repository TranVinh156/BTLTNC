#include <iostream>
#include <string>

using namespace std;

/*
 * Complete the 'camelcase' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int camelcase(string s) {
    int res = 1;
    for (int i=1; i<s.length(); i++)
    {
        if (s[i] >='A' && s[i] <='Z')
        {
            res++;
        }
    }
    return res;
}

int main()
{
    string s;
    cin >> s;

    int result = camelcase(s);

    cout << result << "\n";

    return 0;
}