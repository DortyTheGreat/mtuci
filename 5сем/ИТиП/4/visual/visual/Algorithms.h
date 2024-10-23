#pragma once
#include <vector>
#include <queue>
#include <limits>

// Алгоритм Дейкстры
std::vector<int> dijkstra(const std::vector<std::vector<int>>& graph, int src);

// Алгоритм Дейкстры, O(E * log2(V)) с восстановлением пути
std::vector<int> dijkstra2(const std::vector<std::vector<std::pair<int, int>>>& g, int s);

// Алгоритм Флойда-Уоршелла
std::vector<std::vector<int>> floydWarshall(std::vector<std::vector<int>> graph);

// Алгоритм Форма-Фалкерсона (макс. выход)
std::pair<int, std::vector<std::vector<int>> > fordFulkerson(std::vector<std::vector<std::pair<int, int>>> graph_adj, int source, int sink);


std::pair<int, std::vector<std::vector<int>> > findMinimalCut(std::vector<std::vector<std::pair<int, int>>> graph_adj, int source, int sink);

std::vector<int> hungarianMethod(const std::vector<std::vector<int>>& costMatrix);


// Алгоритм перевода из списка смежности в матрицу смежности
std::vector<std::vector<int>> to_adjacency_matrix(const std::vector<std::vector<std::pair<int, int >>>& g);