#include <cstddef>
#include <queue>
#include <algorithm>
#include "Subway.h"

void Subway::add_edge(const EdgeInputType &edge) {
  nodes_[edge.from].edges_index[edge.to] = nodes_[edge.from].edges.size();
  nodes_[edge.from].edges.push_back({edge.to, edge.time});
  nodes_[edge.to].edges_index[edge.from] = nodes_[edge.to].edges.size();
  nodes_[edge.to].edges.push_back({edge.from, edge.time});
}

void Subway::label_line(const LineInputType &line) {
  size_t first_arrival_time = 0;
  for (size_t i = 0; i < line.nodes.size() - 1; i++) {
    Node &line_node = nodes_[line.nodes[i]];
    line_node.edges[line_node.edges_index[line.nodes[i + 1]]].train_arrival_time.push_back({first_arrival_time,
                                                                                            line.interval});
    first_arrival_time += line_node.edges[line_node.edges_index[line.nodes[i + 1]]].time_needed;
  }
  first_arrival_time = 0;
  for (size_t i = line.nodes.size() - 1; i > 0; i--) {
    Node &line_node = nodes_[line.nodes[i]];
    line_node.edges[line_node.edges_index[line.nodes[i - 1]]].train_arrival_time.push_back({first_arrival_time,
                                                                                            line.interval});
    first_arrival_time += line_node.edges[line_node.edges_index[line.nodes[i - 1]]].time_needed;
  }
}

Subway::Subway(int n, const std::vector<EdgeInputType> &edges, const std::vector<LineInputType> &lines) {
  nodes_ = std::vector<Node>(n);
  for (auto &node : nodes_) {
    node.edges_index = std::vector<size_t>(n, INF);
  }
  for (int i = 0; i < n; i++) {
    nodes_[i].index = i;
  }
  for (auto &edge : edges) {
    add_edge(edge);
  }
  for (auto &line : lines) {
    label_line(line);
  }
}

std::vector<int> Subway::shortest_way(int from, int to, size_t arrival_time) {
  std::priority_queue<Node *, std::vector<Node *>, NodeDistComparator> queue;
  nodes_[from].user_arrival_time = arrival_time;
  queue.push(&nodes_[from]);
  while (!queue.empty()) {
    Node *current = queue.top();
    if (current == &nodes_[to])
      break;
    queue.pop();
    if (current->used)
      continue;
    current->used = true;
    for (auto &edge : current->edges) {
      size_t next_station_time = min_next_station_time(edge, current->user_arrival_time);
      if (nodes_[edge.to].user_arrival_time > next_station_time) {
        nodes_[edge.to].user_arrival_time = next_station_time;
        nodes_[edge.to].prev_node = current->index;
        queue.push(&nodes_[edge.to]);
      }
    }
  }
  std::vector<int> path;
  int current = to;
  while (current != from) {
    path.push_back(current);
    current = nodes_[current].prev_node;
  }
  path.push_back(from);
  std::reverse(path.begin(), path.end());
  for (auto &node : nodes_) {
    node.user_arrival_time = INF;
    node.used = false;
  }
  return path;
}

size_t Subway::min_next_station_time(const Subway::Edge &edge, size_t start_time) {
  size_t current_min = INF;
  for (auto train_time : edge.train_arrival_time) {
    size_t next_station;
    if (train_time.first_arrival > start_time) {
      next_station = train_time.first_arrival + edge.time_needed;
    } else {
      next_station = train_time.first_arrival
          + ((start_time - train_time.first_arrival - 1) / train_time.interval + 1) * train_time.interval
          + edge.time_needed;
    }
    current_min = std::min(current_min, next_station);
  }
  return current_min;
}

bool Subway::NodeDistComparator::operator()(Subway::Node *t1, Subway::Node *t2) {
  return t1->user_arrival_time > t2->user_arrival_time;
}