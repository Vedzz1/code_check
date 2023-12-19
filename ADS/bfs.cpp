#include <iostream>
using namespace std;
#define max 100

void bfs(int adj[max][max],int visited[],int start)
{
    int rare=-1,front=-1,queue[max];
    
    queue[rare++]=start;
    visited[start]=1;
    
    while(front < rare)
    {
        int current=queue[front++];
        cout<<current;
        cout<<"\t";
        
        for(int i=0;i<max;i++)
        {
            if(adj[current][i]==1 && !visited[i])
            {
                queue[rare++]=i;
                visited[i]=1;
            }
        }
    }
    
}

int main()
{
    int start,adj[max][max],visited[max]={0},vertices;
    
    cout<<"\nEnter Number Of Nodes: ";
    cin>>vertices;
    
    cout<<"\nEnter Adjecency Matrix: ";
    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<vertices;j++)
        {
            cin>>adj[i][j];
        }
            
    }
    
    
    cout<<"\nEnter A Starting Vertex (0-"<<vertices-1<<"): ";
    cin>>start;
    
    cout<<"\nBFS: ";
    bfs(adj,visited,start);
    return 0;
}