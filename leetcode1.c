#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int val;
    struct Node* next;
};

void dfs(int src, struct Node** g, int* nodes, int* vis, int* nodeCount) {
    if (vis[src])
        return;
    vis[src] = 1;

    nodes[*nodeCount] = src;
    (*nodeCount)++;

    struct Node* current = g[src]->next;
    while (current != NULL) {
        int x = current->val;
        dfs(x, g, nodes, vis, nodeCount);
        current = current->next;
    }
}

int countCompleteComponents(int n, int** edges, int edgesSize, int* edgesColSize) {
    struct Node** g = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) {
        g[i] = (struct Node*)malloc(sizeof(struct Node));
        g[i]->next = NULL;
    }

    // Construct adjacency list representation of the graph
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->val = v;
        newNode->next = g[u]->next;
        g[u]->next = newNode;

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->val = u;
        newNode->next = g[v]->next;
        g[v]->next = newNode;
    }

    int* vis = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        vis[i] = 0;
    }

    int res = 0;

    for (int i = 0; i < n; i++) {
        if (vis[i] == 0) {
            int* nodes = (int*)malloc(n * sizeof(int));
            int nodeCount = 0;
            dfs(i, g, nodes, vis, &nodeCount);

            int count = 0;

            for (int j = 0; j < nodeCount; j++) {
                int pathNode = nodes[j];
                struct Node* current = g[pathNode]->next;
                int neighborCount = 0;

                while (current != NULL) {
                    neighborCount++;
                    current = current->next;
                }

                if (neighborCount >= nodeCount - 1) {
                    count++;
                }
            }

            if (count == nodeCount) {
                res++;
            }

            free(nodes);
        }
    }

    for (int i = 0; i < n; i++) {
        struct Node* current = g[i];
        while (current != NULL) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }

    free(g);
    free(vis);

    return res;
}
