//To learn more of the number system conversions read:http://www.technical-recipes.com/2012/number-conversions-in-c/

//TODO: add more number systems
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
//Decimal to any base converter
void Dec2base(int num, int base, stringstream& ss)
{
    if(num>=base)
    {
        Dec2base(num/base,base,ss);
    }
    ss << num%base;
}
//Binary to long long int value
long Bin2Dec(string bin)
{
    char* ptr;
    long parsed = strtol(bin.c_str(), &ptr, 2);
    return parsed;
}

int main()
{
    do
    {
        stringstream ss;
        int choice,in;
        string bi;
        cout<<"1. Binary to integer\t2.Integer to binary\t3.Exit\n";
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter the binary number: ";
                cin>>bi;
                cout<<"The binary number "<<bi<<" is integer: "<<Bin2Dec(bi)<<endl;
                break;
            case 2:
                cout<<"Enter the integer value: ";
                cin>>in;
                Dec2base(in,2,ss);
                cout<<"The integer: "<<in<<" is "<<ss.str()<<" in binary\n";
                break;
            case 3:
                cout<<"Thank you!\n";
                return 0;
                break;
            default:
                cout<<"Please enter a valid choice!\n";
        }
    }while(1);
    return 0;
}