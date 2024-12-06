#pragma once
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

namespace gph {
class UndirectedGraph {
 public:
  static const int nodes = 11;

 private:
};
class UndirectedGraphAdjMtx
    : UndirectedGraph {  // inheriting from UndirectedGraph
 public:
  void addEdge(int row, int column) {
    adjMatrix[row][column] = true;
    adjMatrix[column][row] = true;
    numOfEdgesTotal++;
  }
  void removeEdge(int row, int column) {
    adjMatrix[row][column] = false;
    adjMatrix[column][row] = false;
    numOfEdgesTotal--;
  }
  void print() {
    for (int i = 0; i < nodes; i++) {
      for (int j = 0; j < nodes; j++) {
        char temp = adjMatrix[i][j] ? '1' : ' ';
        std::cout << temp << " | ";
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
  }

 private:
  // std::vector<std::vector<bool>> adjMatrix = std::vector(nodes,
  // std::vector<bool>(nodes,false)); // using vector in dynamic
  bool adjMatrix[nodes][nodes] = {};
  int numOfEdgesTotal;
};

class UndirectedGraphAdjList
    : UndirectedGraph {  // inheriting from UndirectedGraph
 public:
  void addEdge(int row, int column) {
    adjList[row].push_back(column);
    adjList[column].push_back(row);
    numOfEdgesTotal++;
  }
  void removeEdge(int row, int column) {
    adjList[row].remove(column);
    adjList[column].remove(row);
    numOfEdgesTotal--;
  }

  bool bfs(int start, int search) {
    std::queue<int> toSearch;
    std::set<int> searched;  // ints are nodes
    toSearch.push(start);
    while (toSearch.size() > 0) {
      int curr = toSearch.front();
      toSearch.pop();
      std::list<int> list = adjList[curr];
      for (int i : list) {
        if (i == search) {
          std::cout << "found ";
          return true;
        }
        if (!searched.contains(i)) {
          searched.insert(i);
          toSearch.push(i);
        }
      }
    }
    return false;
  }

  bool dfs(int start, int search, std::set<int>& searched, bool& found) {
    searched.insert(start);
    std::list<int> children = adjList[start];
    for (int curr : children) {
      if (curr == search) {
        std::cout << "found ";
        found = true;
        return true;
      }
      if (!searched.contains(curr)) {
        dfs(curr, search, searched, found);
      }
    }
    return false;
  }
  //                                          key  val
  bool dfsCyclic(int start, std::unordered_map<int, bool>& visited,
                 int parent) {
    visited[start] = true;

    // check all neighbors
    for (int neighbor : adjList[start]) {
      if (!visited[neighbor]) {
        if (dfsCyclic(neighbor, visited, start)) {
          return true;
        }
      }
      // if the neighbor isnt the parent -> cycle
      else if (neighbor != parent) {
        return true;
      }
    }
    return false;
  }

  bool checkForCycle() {
    std::unordered_map<int, bool> visited;
    // checks for cycles
    for (int node = 0; node < nodes; node++) {
      if (!visited[node]) {
        if (dfsCyclic(node, visited, -1)) {
          return true;  // cycle
        }
      }
    }
    return false;  // no cycled
  }

  void print() {
    for (int i = 0; i < nodes; i++) {  // output of I
      std::cout << "Node: " << i << " => [";
      for (int j : adjList[i]) {
        std::cout << j << " , ";
      }
      std::cout << "]" << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
  }

 private:
  std::vector<std::list<int>> adjList = std::vector(nodes, std::list<int>());
  int numOfEdgesTotal = 0;
};

}  // namespace gph
