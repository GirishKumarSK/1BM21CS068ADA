#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int n;

int min (int dist[n], int flag[n]){
    int min = INT_MAX/2, index;
    for (int i=0; i<n; i++){
        if (flag[i]==0 && dist[i]<min){
            min=dist[i];
            index=i;
        }
    }
    return index;
}

void dijkstra (int graph[n][n], int src){

    int dist[n], flag[n], i;

    for (i=0; i<n; i++){
        dist[i]=INT_MAX/2;
        flag[i]=0;
    }
    dist[src]=0;

    for (i=0; i<n; i++){
        int u = min (dist, flag);

        flag[i]=1;
        for (int v=0; v<n; v++){
            if (flag[v]==0 && graph[u][v] && dist[u]!=INT_MAX/2 && dist[u]+graph[u][v] < dist[v])
                dist[v] = dist[u]+graph[u][v];
        }
    }
    printf ("Vertex  Distance\n");
    for (i=0; i<n; i++){
        printf ("%d \t %d\n", i, dist[i]);
    }
}

int main(){

    int i,j;
    printf ("Enter the number of vertices:\n");
    scanf ("%d", &n);
    int graph[n][n];
    printf ("Enter graph in the form of adjecency matrix:\n");
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            scanf ("%d", &graph[i][j]);
        }
    }
    printf ("Enter the source node:\n");
    scanf ("%d", &i);
    dijkstra (graph, i);

    return 0;
}