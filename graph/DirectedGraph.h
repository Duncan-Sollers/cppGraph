#pragma once

#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>

using Node = char;
using AdjList = std::list<Node>;

class DirectedGraph {
 public:
  static const int nodes = 11;
  void addEdge(Node start, Node dest) {
    if (!adjList.contains(start)) {
      AdjList newList = {};
      adjList[start] = newList;
    }
    adjList[start].push_back(dest);
    numEdges++;
    if (!adjList.contains(dest)) {
      AdjList newList = {};
      adjList[dest] = newList;
    }
    // adjList.insert(start, dest);
    //  adjList.insert(dest, start);
  }

  bool bfs(Node start, Node search) {
    std::queue<Node> toSearch;
    std::set<Node> searched;  // ints are nodes
    toSearch.push(start);
    while (toSearch.size() > 0) {
      Node curr = toSearch.front();
      toSearch.pop();
      std::list<Node> list = adjList[curr];
      for (Node i : list) {
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

  bool dfs(Node start, Node search, std::set<Node>& searched, bool& found) {
    searched.insert(start);
    std::list<Node> children = adjList[start];
    for (Node curr : children) {
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

  DirectedGraph transpose() {
    DirectedGraph dg;
    for (const auto& kv : adjList) {
      for (Node curr : kv.second) {
        dg.addEdge(curr, kv.first);
      }
    }
    return dg;
  }

  std::vector<Node> topologicalSort() {
    int V = adjList.size();
    // Vector to store indegree of each vertex
    //std::vector<int> indegree(adjList.size());
    std::map<Node, int> indegree;
    //for (int i = 0; i < V; i++) {
      for (auto kv : adjList) {
        for (Node curr : kv.second) {
          indegree[curr]++;
        }
      }
    //}

    // Queue to store vertices with indegree 0
    std::queue<Node> q;
    //for (int i = 0; i < V; i++) {
    for (auto kv : adjList) {
      if (indegree[kv.first] == 0) {
        q.push(kv.first);
      }
    }
    std::vector<Node> result;
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      result.push_back(node);

      // Decrease indegree of adjacent vertices as the
      // current node is in topological order
      for (auto curr : adjList[node]) {
        indegree[curr]--;

        // If indegree becomes 0, push it to the queue
        if (indegree[curr] == 0) q.push(curr);
      }
    }

    // Check for cycle
    if (result.size() != V) {
      std::cout << "Graphx contains cycle!" << std::endl;
      return {};
    }

    return result;
  }



  /*
  void topologicalSort() { 
    int size = adjList.size(); 
    std::set<Node> visited;
    std::vector<Node> ordering(size);
    int i = size - 1;
    for (const auto& kv : adjList) {
      if (!visited.contains(kv.first)) {

      }
    }
  }
  */

  int getEdges() { return numEdges; }
  std::map<Node, AdjList> getADJ() { return adjList; }

  void printADJ() {
    for (const auto& kv : adjList) {
      for (Node curr : kv.second) {
        std::cout << kv.first << "--->" << curr << std::endl;
      }
    }
  }

 private:
  std::map<Node, AdjList> adjList;
  int numEdges = 0;
};
