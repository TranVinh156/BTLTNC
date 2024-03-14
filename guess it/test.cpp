#include <iostream>
using namespace std;
int main()
{
    int n =9379;
    int count = 0;
    for (int i=2; i<9379; i++)
    {
        if (n%i==0) break;
        else count++;
    }
    cout << count;
    return 0;
}