#include<stdio.h>
int queue[20],front=-1,rear=-1;
int visited[20],a[20][20],n;
void bfs(int v){
    int i;
    visited[v]=1;
    queue[++rear]=v;
    while(front!=rear){
        v=queue[++front];
        printf("%d ",v);
        for(i=1;i<=n;i++){
            if(a[v][i]==1 && visited[i]==0){
                queue[++rear]=i;
                visited[i]=1;
            }
        }
    }
}
int main(){
    int i,j,v;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter adjacency matrix:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(i=1;i<=n;i++)
        visited[i]=0;
    printf("Enter starting vertex: ");
    scanf("%d",&v);
    printf("BFS traversal: ");
    bfs(v);
    return 0;
}
