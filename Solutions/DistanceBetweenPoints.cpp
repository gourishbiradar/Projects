#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double x1,y1,x2,y2;
    cout<<"Enter the longitude(x) and latitude(y) of first city:";
    cin>>x1>>y1;
    cout<<"Enter the longitude(x) and latitude(y) of second city:";
    cin>>x2>>y2;
    double distance = sqrt(pow(abs(x1-x2),2)+pow(abs(y1-y2),2));
    cout<<"The shortest distance between the two cities is "<<fixed<<setprecision(4)<<distance;
    return 0;
}