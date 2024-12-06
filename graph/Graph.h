#pragma once
#include <list>
#include <queue>
#include <set>
#include <vector>

namespace gph {
class Graph {
 public:
 private:
};
class GraphAdjMtx : Graph {  // inheriting from Graph
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
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        char temp = adjMatrix[i][j] ? '1' : ' ';
        std::cout << temp << " | ";
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
  }

 private:
  // std::vector<std::vector<bool>> adjMatrix = std::vector(8,
  // std::vector<bool>(8,false)); // using vector in dynamic
  bool adjMatrix[8][8] = {};
  int numOfEdgesTotal;
};

class GraphAdjList : Graph {  // inheriting from Graph
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
      int cur = toSearch.front();
      toSearch.pop();
      std::list<int> list = adjList[cur];
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

  bool dfs(int start, int search, std::set<int>& searched, bool& found ) {
    searched.insert(start);
    std::list<int> children = adjList[start];
    for (int cur : children) {
      if (cur == search) {
        std::cout << "found ";
        found = true;
        return true;
      }
      if (!searched.contains(cur)) {
        dfs(cur, search, searched, found);
      }
    }
    return false;
  }

  void print() {
    for (int i = 0; i < 8; i++) {  // output of I
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
  std::vector<std::list<int>> adjList = std::vector(8, std::list<int>());
  int numOfEdgesTotal = 0;
};
}  // namespace gph
