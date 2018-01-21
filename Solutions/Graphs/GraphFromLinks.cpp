#include <iostream>
using namespace std;

int main()
{
    int nodes,links;
    cout<<"Enter the number of nodes:";
    cin>>nodes;
    int** graph = new int*[nodes];
    for(int i=0;i<nodes;i++)
        graph[i] = new int[nodes];
    for(int i=0;i<nodes;i++)
        for(int j=0;j<nodes;j++)
            graph[i][j]=0;
    cout<<"Enter the number of links:";
    cin>>links;
    cout<<"Enter the links\n";
    for(int i=0;i<links;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a-1][b-1] = 1;
    }
    cout<<"The directed graph is\n";
    for(int i=0;i<nodes;i++)
    {
        for(int j=0;j<nodes;j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<nodes;i++)
    {
        for(int j=0;j<nodes;j++)
        {
            if(graph[i][j])
            graph[j][i]=graph[i][j];
        }
    }
    cout<<"The undirected graph is\n";
    for(int i=0;i<nodes;i++)
    {
        for(int j=0;j<nodes;j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }    
}