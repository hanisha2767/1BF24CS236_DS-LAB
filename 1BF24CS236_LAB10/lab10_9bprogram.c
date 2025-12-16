#include<stdio.h>
#define N 10
int visited[N];
int adj[N][N];
int n;

void DFS(int v)
{
    visited[v]=1;
    printf("%d ",v);
    for(int i=0;i<n;i++){
        if(adj[v][i]==1 && !visited[i])
            DFS(i);
    }
}

int main()
{
    int connected = 1;
    printf("enter number of vertices :\n");
    scanf("%d",&n);
    printf("enter adjacency matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            scanf("%d",&adj[i][j]);
    }
    for(int i=0;i<n;i++)
        visited[i]=0;
    printf("DFS traversal  starting from vertex 0:\n");
    DFS(0);
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            connected = 0;
            break;
        }
    }
    if(connected)
        printf("\nThe graph is CONNECTED\n");
    else
        printf("\nThe graph is NOT CONNECTED\n");
    return 0;
}
