/*
    Code for detecting a cycle in a directed, unweighted graph
    using DFS and Adjacency Matrix.
    This is also the code for detecting the number of
    BACK EDGES in a directed, unweighted graph.
*/

#include <stdio.h>
#include <stdlib.h>
#define init 1
#define wait 2
#define visi 3

int cycle = 0;

//returns 1 if there is a cycle
void DFS(int n, int adj[n][n], int state[n], int v) {
    int i;
    state[v] = wait;
    for (i=0; i<n; i++) {
        if (adj[v][i]==1 && state[i]==wait) {
            cycle = 1;
        }
        if (adj[v][i]==1 && state[i]==init) {
            DFS(n, adj, state, i);
        }
    }
    state[v] = visi;
}

int main() {
    int n; //no. of vertices
    int i, j, edge, origin, dest;
    scanf("%d %d", &n, &edge);
    int adj[n][n]; //adjacency matrix
    int state[n]; //state of the vertex
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
    //nodes are from 1 to N
    for (i=0; i<edge; i++) {
        scanf("%d %d", &origin, &dest);
        adj[origin-1][dest-1] = 1;
    }
    for (i=0; i<n; i++) {
        state[i]=init;
    }
    
    for (i=0; i<n; i++) {
        if (state[i] == init) {
            DFS(n, adj, state, i);
        }
    }

    if (cycle == 1) {
        printf("YES");
    }
    else {
        printf("NO");
    }

    
    return 0;
}


