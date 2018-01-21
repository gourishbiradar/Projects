#include <iostream>
#include <utility>
#include <algorithm>
#include <cmath>
#include <limits>
#include <ctime>
using namespace std;
double getD(pair<int,int> a , pair<int,int> b)
{
    return (sqrt(pow((a.first-b.first),2)+pow((a.second-b.second),2)));
}
int compareX(const void *p1, const void *p2)
{
    pair<int,int> *a = (pair<int,int>*)p1;
    pair<int,int> *b = (pair<int,int>*)p2;
    return (a->first-b->first);
}
int compareY(const void *p1, const void *p2)
{
    pair<int,int> *a = (pair<int,int>*)p1;
    pair<int,int> *b = (pair<int,int>*)p2;
    return (a->second-b->second);
}
double BruteForce(pair<int,int> points[],int n)
{
    double minD = numeric_limits<double>::max();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(minD > getD(points[i],points[j]))
            {
                minD = getD(points[i],points[j]);
            }
        }
    }
    return minD;
}
double stripclosest(pair<int,int> strip[], int n, double d)
{
    double minimum = d;
    qsort(strip,n,sizeof(pair<int,int>),compareY);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n && (strip[j].second - strip[i].second)<minimum;j++)
        {
            if(getD(strip[i],strip[j])<minimum)
                minimum = getD(strip[i],strip[j]);
        }
    }
    return minimum;
}
double solveD(pair<int,int> points[],int n)
{
    if(n<=3)
    return BruteForce(points,n);
    int mid = n/2;
    //The points vector is qsorted based on first(X), the median is n/2
    pair<int,int> median = points[mid];
    //split them in two halves points_l and points_R
    double dl = solveD(points,mid);
    double dr = solveD(points+mid,n-mid);
    double d = min(dl,dr);
    pair<int,int> *strip = new pair<int,int>[n];
    int j = 0;
    for(int i=0;i<n;i++)
    {
        if(abs(points[i].first-median.first)<d)
        {
            strip[j++] = points[i];
        }
    }
    return min(d,stripclosest(strip,j,d));
}
int main()
{
    clock_t t0,t1;
    int n;
    cout<<"Enter the number of points:";
    cin>>n;
    pair<int,int> *points = new pair<int,int>[n];
    cout<<"Enter the x and y coordinates of "<<n<<" points\n";
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        points[i] = make_pair(x,y);
    }
    //brute force O(n^2)
    t0 = clock();
    double Bdistance = BruteForce(points,n);
    t1 = clock();
    double Btt = (double)(t1-t0)/CLOCKS_PER_SEC;
    //Divide and conquer O(n*logn*logn)
    t0 = clock();
    qsort(points,n,sizeof(pair<int,int>),compareX);
    double Ddistance = solveD(points,n);
    t1 = clock();
    double Dtt = (double)(t1-t0)/CLOCKS_PER_SEC;
    cout<<"Brute D:"<<Bdistance<<" in time:"<<Btt<<" and Divide d:"<<Ddistance<<" in time:"<<Dtt;
    return 0;
}