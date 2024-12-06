#include <iostream>

#include "Graph.h"

int main() {
  gph::GraphAdjMtx graph;
  std::cout << "Hello World!\n";
  graph.addEdge(0, 1);
  graph.addEdge(0, 2);
  graph.addEdge(2, 3);
  graph.addEdge(2, 4);
  graph.addEdge(4, 5);
  graph.addEdge(5, 6);
  graph.addEdge(5, 7);
  graph.print();

  gph::GraphAdjList graphL;
  graphL.addEdge(0, 1);
  graphL.addEdge(0, 2);
  graphL.addEdge(2, 3);
  graphL.addEdge(2, 4);
  graphL.addEdge(4, 5);
  graphL.addEdge(5, 6);
  graphL.addEdge(5, 7);
  graphL.print();

  std::cout << std::boolalpha << "BFS (0,7) => " << graphL.bfs(1, 2)
            << std::endl;
  std::set<int> set;
  bool found = false;
  graphL.dfs(1, 2, set, found);
  std::cout << std::boolalpha << "DFS (0,7) => " << found << std::endl;
}
