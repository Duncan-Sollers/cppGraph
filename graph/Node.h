#pragma once
#include <string>
#include <set>

template <typename T>
struct Node{
  std::string id;
  std::set<T*> nodesPointingToMe;

  std::set<T*> nodesIAmPointingTo;
};