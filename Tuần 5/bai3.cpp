#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    int arr[500];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int x;
    cin>>x;
    vector<int>arr1;
    for(int i=0;i<n;i++)
    {
        if(i!=(x-1))
        {
            arr1.push_back(arr[i]);
        }
    }
    int a,b;
    cin>>a>>b;
    arr1.erase(arr1.begin()+a-1,arr1.begin()+(b-1));
    int len=arr1.size();
    cout << len << endl;
    for(int i=0;i<len;i++)
    {
        cout<<arr1[i]<<" ";
    }
    return 0;
    //return 0;
}
