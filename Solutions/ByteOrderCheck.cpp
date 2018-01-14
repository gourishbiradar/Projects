#include <iostream>
using namespace std;

int main()
{
    union
    {
        short s;
        char c[sizeof(short)];
    }un;
    un.s=0x0102;
    if(sizeof(short)==2)
    {
        if(un.c[0]==1 && un.c[1]==2)
        {
            cout<<"Big endian\n";
        }
        else if(un.c[0]==2 && un.c[1]==1)
        {
            cout<<"Little endian\n";
        }
        else
        cout<<"Unknow!!\n";
    }
    else
    {
        cout<<"Size of short:"<<sizeof(short)<<endl;
    }
    system("pause");
    return 0;
}