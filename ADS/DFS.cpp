#include<iostream>
using namespace std;
#define max 100

void dfs(int adj[max][max],int vistied[],int start)
{
    int stack[max],top=-1;
    
    for(int i=0;i<max;i++)
    {
        vistied[i]  = 0;
    }
    
    stack[++top]=start;
    vistied[start]=1;
    
    while(top != -1)
    {
        int current = stack[top--];
        cout<<current;
        cout<<"\t";
        
        for(int i=0;i<max;i++)
        {
            if(adj[current][i] == 1 && !vistied[i])
            {
                stack[++top]=i;
                vistied[i]=1;
                break;
            }
        }
    }
}

int main()
{
    int visted[max]={0},adj[max][max],start,nodes;
    
    cout<<"Enter Nodes: ";
    cin>>nodes;
    
    cout<<"Enter Matrix: ";
    for(int i=0;i<nodes;i++)
    {
        for(int j=0;j<nodes;j++)    
        {
            cin>>adj[i][j];
        }
    }
    
    cout<<"Enter Start(0-"<<nodes-1<<"): ";
    cin>>start;
    
    cout<<"DFS: (0-"<<nodes-1<<"): ";
    dfs(adj,visted,start);
    return 0;
}