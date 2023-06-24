#include <stdio.h>
#include <stdlib.h>

struct node {
  int dest;
  struct node* next;
};

struct list {
  struct node* head;
};

struct graph {
  int V;
  struct list* array;
};

struct node* newNode(int dest) {
  struct node* new = (struct node*) malloc(sizeof(struct node));
  new->dest = dest;
  new->next = NULL;
  return new;
}

struct graph* createGraph(int V) {
  struct graph* graph = (struct graph*) malloc(sizeof(struct graph));
  graph->V = V;
  graph->array = (struct list*) malloc(V * sizeof(struct list));

  for (int i = 0; i < V; i++)
    graph->array[i].head = NULL;

  return graph;
}

void addEdge(struct graph* graph, int src, int dest) {
  struct node* new = newNode(dest);
  new->next = graph->array[src].head;
  graph->array[src].head = new;

  // For an undirected graph, add an edge from dest to src also
  new = newNode(src);
  new->next = graph->array[dest].head;
  graph->array[dest].head = new;
}

int main() {
  int V = 5;
  struct graph* graph = createGraph(V);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 4);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 1, 4);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 4);

  return 0;
}
