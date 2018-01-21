#include <iostream>
#include <string>
using namespace std;

int  main()
{
    int n;
    cin>>n;
    string *arr = new string[n];
    for(int i=0;i<n;i++)
    {
        int index;
        string str;
        cin>>index>>str;
        if(i<n/2)
        {
            arr[index] = arr[index] + "-"+" ";
        }
        else
        {
            arr[index ] = arr[index]+ str + " ";
        }
    }
    for(int i=0;i<n;i++)
    cout<<arr[i];
}