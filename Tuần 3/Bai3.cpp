#include <string>
#include <iostream>
using namespace std;

string timeConversion(string s) {
    int len = s.length();
    string a = s.substr(len-2, 2);
    string b = s.substr(0,2);
    string c = s.substr(2, 6);
    if (a=="PM")
    {
        if (b!="12")
        {
            int tmp = stoi(b) + 12;
            b = to_string(tmp);
        }
        
    }
    else 
    {
        if (b == "12")
        {
            b="00";
        }
    }
    return b+c;

}

int main()
{
    string s;
    cin >> s;
    
    cout << timeConversion(s) << endl;
    return 0;
}
