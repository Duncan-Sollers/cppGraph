#include <iostream>
#include <string>

#include "DirectedGraph.h"
#include "UndirectedGraph.h"
//using Node = char;
int main() {
  DirectedGraph DG;
  DG.addEdge('A', 'B');
  DG.addEdge('A', 'C');
  DG.addEdge('A', 'D');
  DG.addEdge('B', 'F');
  DG.printADJ();
  std::cout << std::endl;
  // std::cout << std::boolalpha << DG.bfs("A", "F") << std::endl;
  // std::cout << std::boolalpha << DG.bfs("F", "A") << std::endl;
  DirectedGraph DGT = DG.transpose();
  DGT.printADJ();
  std::cout << std::endl;
  DirectedGraph DGTT;
  DGTT.addEdge('A' + 0, 'A' + 1);
  DGTT.addEdge('A' + 1, 'A' + 2);
  DGTT.addEdge('A' + 2, 'A' + 3);
  //DGTT.addEdge('A' + 3, 'A' + 4);
  DGTT.addEdge('A' + 4, 'A' + 5);
  DGTT.addEdge('A' + 5, 'A' + 1);
  DGTT.addEdge('A' + 5, 'A' + 2);
  DGTT.printADJ();
  
  std::vector<Node> result = DGTT.topologicalSort();
  std::cout << "Topological sorting of the graph: ";
  for (auto i : result) {
    std::cout << i << "=>";
  }
  
  std::map<Node, AdjList> adjList = DGTT.getADJ();

  

  DGTT.topologicalSort();

  /*
  gph::UndirectedGraphAdjMtx graph;
  std::cout << "Hello World!\n";
  graph.addEdge(0, 1);
  graph.addEdge(0, 2);
  graph.addEdge(2, 3);
  graph.addEdge(2, 4);
  graph.addEdge(4, 5);
  graph.addEdge(5, 6);
  graph.addEdge(5, 7);
  graph.print();

  gph::UndirectedGraphAdjList graphL;
  graphL.addEdge(0, 1);
  graphL.addEdge(0, 2);
  graphL.addEdge(2, 3);
  graphL.addEdge(2, 4);
  graphL.addEdge(4, 5);
  graphL.addEdge(5, 6);
  graphL.addEdge(5, 7);
  graphL.print();

  if (graphL.checkForCycle()) {
    std::cout << "Cycle detected in the graph." << std::endl;
  } else {
    std::cout << "No cycle detected in the graph." << std::endl;
  }


  std::cout << std::boolalpha << "BFS (0,7) => " << graphL.bfs(1, 2)
            << std::endl;
  std::set<int> set;
  bool found = false;
  graphL.dfs(1, 2, set, found);
  std::cout << std::boolalpha << "DFS (0,7) => " << found << std::endl;

  gph::UndirectedGraphAdjList graphC;
  graphC.addEdge(0, 1);
  graphC.addEdge(0, 3);
  graphC.addEdge(1, 5);
  graphC.addEdge(5, 9);
  graphC.addEdge(9, 10);
  graphC.addEdge(10, 6);
  graphC.addEdge(5, 4);
  graphC.addEdge(4, 3);
  graphC.addEdge(3, 7);
  graphC.addEdge(4, 8);
  graphC.addEdge(2, 2);
  graphC.print();

  if (graphC.checkForCycle()) {
    std::cout << "Cycle detected in the graph." << std::endl;
  } else {
    std::cout << "No cycle detected in the graph." << std::endl;
  }
  */
}
