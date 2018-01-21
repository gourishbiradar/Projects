#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    ~Graph() { delete []adj;}
    bool isConnected();
    int isEulerian();
    void addEdge(int , int);
    void DFS(int v , bool visited[]);

};

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void Graph::DFS(int v, bool visited[])
{
 visited[v]=true;
 list<int> ::iterator i;
 for(i=adj[v].begin();i!=adj[v].end();i++)
    if(!visited[*i])
        DFS(*i,visited);    
}
bool Graph::isConnected()
{
    bool *visited = new bool[V];
    int i;
    // no node visited yet, so reset visited[]
    for(i=0;i<V;i++)
        visited[i]=false;
    //find a node which has non-zero degree
    for(i=0;i<V;i++)
        if(adj[i].size()!=0)
        break;
    // if there are no edges in graph, NULL graph is also connected hence true
    if(i==V) 
        return true;
    //from the vertex i, do dfs
    DFS(i,visited);
    //check if all non-zero degree vertices are visited
    for(i=0;i<V;i++)
        if(!visited[i] && adj[i].size()>0)
            return false; //found a node with some edge but not visited at all
    return true; //all non-zero nodes are visited hence in a eulerian path
}
int Graph::isEulerian()
{
    /*
    0--> graph is not eulerian
    1--> graph is semi-eulerian (eulerian path exists)
    2--> graph is eulerian (euler circuit exists)
    */
    if(isConnected() == false)
        return 0;
    //Count vertices with odd degree
    int odd = 0;
    for(int i=0;i<V;i++)
        if(adj[i].size()&1)
            odd++;
    //if odd > 2 then graph is not eulerian-->property
    if(odd>2)
        return 0;
    //If odd is 2, then semi-eulerian-->property
    //if odd is 0, then eulerian-->property
    return (odd)?1:2;
}


int main()
{
    int nodes,edges;
    cout<<"Enter the number of nodes:";
    cin>>nodes;
    Graph g(nodes);
    cout<<"Enter the number of edges:";
    cin>>edges;
    cout<<"Enter the edge vertices of "<<edges<<" edges\n";
    for(int i=0;i<edges;i++)
    {
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }
    switch(g.isEulerian())
    {
        case 0:
            cout<<"The graph is not Eulerian\n";
            break;
        case 1:
            cout<<"The graph has a Eulerian Path\n";
            break;
        case 2:
            cout<<"The graph has a Eulerian circuit\n";
            break;
        default:
            cout<<"Some Error in isEulerian function!!\n";
    }
    return 0;
}