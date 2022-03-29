#include <iostream>
#include "Subway.h"

int main() {
    int n = 5, m = 5, k = 1, q = 3;
//    std::cin >> n >> m;
    std::vector<Edge> edges;
    for(int i = 0; i < m; ++i) {
        edges.push_back({i, i+1, 1});
    }
    std::vector<std::vector<int>> lines;
    lines.push_back({0,1,2,3,4});
    Subway subway(n, edges, lines);
    std::cout << subway.shortest_way(0, 4, 10) << std::endl;
    std::cout << subway.shortest_way(0, 4, 7) << std::endl;
    std::cout << subway.shortest_way(0, 4, 12) << std::endl;
    return 0;
}
