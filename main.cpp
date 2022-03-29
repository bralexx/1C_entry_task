#include <iostream>
#include <assert.h>
#include "Subway.h"

void print_vector(const std::vector<int> &vec) {
  for (auto i : vec)
    std::cout << i << ' ';
  std::cout << '\n';
}

void test0() {
  std::vector<EdgeInputType> edges;
  for (int i = 0; i <  4; ++i) {
    edges.push_back({i, i + 1, 1});
  }
  edges.push_back({1, 4, 2});
  std::vector<LineInputType> lines;
  lines.push_back({{0, 1, 2, 3, 4}, 1});
  lines.push_back({{1, 4}, 3});

  Subway subway(5, edges, lines);
  assert(subway.shortest_way(0, 4, 9) == std::vector<int>({0,1,2,3,4}));
  assert(subway.shortest_way(0, 4, 10) == std::vector<int>({0,1,4}));
}

void test2() {
  std::vector<EdgeInputType> edges;
  for (int i = 0; i <  4; ++i) {
    edges.push_back({i, i + 1, 1});
  }
  edges.push_back({1, 4, 2});
  std::vector<LineInputType> lines;
  lines.push_back({{0, 1, 2, 3, 4}, 1});
  lines.push_back({{1, 4}, 3});

  Subway subway(5, edges, lines);
  assert(subway.shortest_way(0, 4, 9) == std::vector<int>({0,1,2,3,4}));
  assert(subway.shortest_way(0, 4, 10) == std::vector<int>({0,1,4}));
}


int main() {
  test0();
  int n = 5, m = 5, k = 1, q = 3;
//    std::cin >> n >> m;
  std::vector<EdgeInputType> edges;
  for (int i = 0; i < n - 1; ++i) {
    edges.push_back({i, i + 1, 1});
  }
  edges.push_back({1, 4, 2});
  std::vector<LineInputType> lines;
  lines.push_back({{0, 1, 2, 3, 4}, 1});
  lines.push_back({{1, 4}, 3});
  Subway subway(n, edges, lines);
  print_vector(subway.shortest_way(0, 4, 10));
//    std::cout << subway.shortest_way(0, 4, 7) << std::endl;
//    std::cout << subway.shortest_way(0, 4, 12) << std::endl;
  return 0;
}
