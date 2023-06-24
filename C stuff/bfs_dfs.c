#include <stdio.h>
#include <stdlib.h>

int MAX_NODES = 100;


void bfs(int adj_matrix[MAX_NODES][MAX_NODES], int start_node, int num_nodes);

int main()
{
    int adj_matrix[MAX_NODES][MAX_NODES], num_nodes, start_node;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);
    
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            scanf("%d", &adj_matrix[i][j]);
        }
    }
    
    printf("Enter the start node: ");
    scanf("%d",&start_node);
    
    printf("BFS Traversal: ");
    bfs(adj_matrix, start_node, num_nodes);
    
    return 0;
}

void bfs(int adj_matrix[MAX_NODES][MAX_NODES], int start_node, int num_nodes)
{
    int queue[MAX_NODES], front = 0, rear = 0;
    int visited[100] = {0};
    
    queue[rear++] = start_node;
    visited[start_node] = 1;
    
    while (front != rear) {
        int node = queue[front++];
        printf("%d ", node);
        for (int i = 0; i < num_nodes; i++) {
            if (adj_matrix[node][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

void dfs(int adj_matrix[MAX_NODES][MAX_NODES], int start_node, int num_nodes)
{
    int stack[MAX_NODES], top = 0;
    int visited[MAX_NODES] = {0};
    
    stack[top++] = start_node;
    visited[start_node] = 1;
    
    while (top > 0) {
        int node = stack[--top];
        printf("%d ", node);
        for (int i = num_nodes - 1; i >= 0; i--) {
            if (adj_matrix[node][i] && !visited[i]) {
                visited[i] = 1;
                stack[top++] = i;
            }
        }
    }
}




