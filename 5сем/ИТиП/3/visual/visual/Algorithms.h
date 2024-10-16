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

// Алгоритм для решения задачи Олм
std::pair<int, std::vector<int>> olya(int start, const std::vector<std::vector<int>>& graph);

// Алгоритм перевода из списка смежности в матрицу смежности
std::vector<std::vector<int>> to_adjacency_matrix(const std::vector<std::vector<std::pair<int, int >>>& g);