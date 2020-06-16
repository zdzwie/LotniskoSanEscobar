#include "graph.h"

EdgeNode::EdgeNode() {
  this->number = 0;
  this->weight = 0;
  this->next = nullptr;
}

EdgeNode::EdgeNode(int number, int weight) {
  this->number = number;
  this->weight = weight;
  this->next = nullptr;
}

EdgeNode::~EdgeNode() {}

Graph::Graph(bool directed, int nodeNumber) {

  this->directed = directed;
  this->nodeNumber = nodeNumber;

  for (int i = 1; i < nodeNumber + 1; i++)
    this->edges[i] = nullptr;
}

Graph::~Graph() {}

void Graph::InsertEdge(int x, int y, int weight, bool directed) {
  if (x > 0 && x < (this->nodeNumber + 1) && y > 0 &&
      y < (this->nodeNumber + 1)) {

    EdgeNode *edge = new EdgeNode(y, weight);
    edge->next = this->edges[x];
    this->edges[x] = edge;
    if (!directed)
      InsertEdge(y, x, weight, true);
  }
}

void Graph::print() const {
  for (int v = 1; v < this->nodeNumber + 1; v++) {
    if (this->edges[v] != nullptr) {
      std::cout << "Vertex " << v << " has neighbours: " << std::endl;
      EdgeNode *current = this->edges[v];
      while (current != nullptr) {
        std::cout << current->number << std::endl;
        current = current->next;
      }
    }
  }
}

void InitVars(bool discovered[], int distance[], int parent[], int graphSize) {
  for (int i = 1; i < graphSize + 1; i++) {
    discovered[i] = false;
    distance[i] = std::numeric_limits<int>::max();
    parent[i] = -1;
  }
}

void DijkstraAlgorithm(Graph *g, int parent[], int distance[], int start) {

  bool discovered[g->nodeNumber + 1];
  EdgeNode *tmp;

  int vTMP;
  int vNeighbour;
  int weight;
  int smallestDistance;

  InitVars(discovered, distance, parent, g->nodeNumber);

  while (discovered[vTMP] == false) {
    tmp = g->edges[vTMP];

    while (tmp != nullptr) {
      vNeighbour = tmp->number;
      weight = tmp->weight;
      if ((distance[vTMP] + weight) < distance[vNeighbour]) {
        distance[vNeighbour] = distance[vTMP] + weight;
        parent[vNeighbour] = vTMP;
      }
      tmp = tmp->next;
    }

    smallestDistance = std::numeric_limits<int>::max();
    for (int i = 1; i < (g->nodeNumber); i++) {
      if (!discovered[i] && (distance[i] < smallestDistance)) {
        vTMP = i;
        smallestDistance = distance[i];
      }
    }
  }
}

void PrintShortestPath(int v, int parent[], int graphNumber) {
  if (v > 0 && (v < graphNumber + 1) && parent[v] != -1) {
    std::cout << parent[v] << " ";
    PrintShortestPath(parent[v], parent, graphNumber);
  }
}