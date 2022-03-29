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
  assert(subway.shortest_way(0, 4, 11) == std::vector<int>({0,1,4}));
}

void test1grid() {
  std::vector<EdgeInputType> edges;
  for (int i = 0; i <  90; ++i) {
    edges.push_back({i, i+10, 1});
  }
  for (int i = 0; i <  100; ++i) {
    if(i%10 != 9)
      edges.push_back({i, i+1, 1});
  }
  std::vector<LineInputType> lines;
  for (int i = 0; i < 10; ++i) {
    std::vector<int> line_nodes1;
    std::vector<int> line_nodes2;
    for (int j = 0; j < 10; ++j) {
      line_nodes1.push_back(10*j+i);
    }
    for (int j = 0; j < 10; ++j) {
      line_nodes2.push_back(j+10*i);
    }
    lines.push_back({line_nodes1, 1});
    lines.push_back({line_nodes2, 1});
  }

  Subway subway(100, edges, lines);
  assert(subway.shortest_way(0, 9, 1) == std::vector<int>({0,1,2,3,4,5,6,7,8,9}));
  assert(subway.shortest_way(0, 90, 10) == std::vector<int>({0,10,20,30,40,50,60,70,80,90}));
  assert(subway.shortest_way(0, 99, 10).size() == 19);
}


int main() {
  test0();
  test1grid();
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
