#include <vector>

#define INF 1e9

struct EdgeInputType {
  int from;
  int to;
  size_t time;
};

struct LineInputType {
  std::vector<int> nodes;
  size_t interval;
};

class Subway {

  struct PossibleArrivalTime {
    size_t first_arrival;
    size_t interval;
  };

  struct Edge {
    int to;
    size_t time_needed = INF;
    std::vector<PossibleArrivalTime> train_arrival_time;
  };

  struct Node {
    int index;
    std::vector<size_t> edges_index;
    std::vector<Edge> edges;
    bool used;
    int prev_node;
    size_t user_arrival_time = INF;
  };
  struct NodeDistComparator {
    bool operator()(Node *t1, Node *t2);
  };

  void add_edge(const EdgeInputType &);
  void label_line(const LineInputType &);
  static size_t min_next_station_time(const Edge &edge, size_t start_time);
//  std::vector<int> dijkstra(int from, int to, size_t arrival);
 public:
  Subway(int n, const std::vector<EdgeInputType> &edges, const std::vector<LineInputType> &lines);

  std::vector<int> shortest_way(int from, int to, size_t arrival_time);

 private:
  std::vector<Node> nodes_;
};