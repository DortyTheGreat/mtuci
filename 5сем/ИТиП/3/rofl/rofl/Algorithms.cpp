#include  "Algorithms.h"
#include <queue>
#include <limits>
#include <algorithm>
#include <set>
#include <utility>
#include <iostream>

using namespace std;

const int inf = 1001 * 1001 * 1001;

// Алгоритм Дейкстры, O(V^2)
std::vector<int> dijkstra(const std::vector<std::vector<int>>& graph, int src) {
    int V = graph.size();
    std::vector<int> dist(V, std::numeric_limits<int>::max());
    std::vector<bool> visited(V, false);
    dist[src] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push({ 0, src });

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (int v = 0; v < V; ++v) {
            if (graph[u][v] != std::numeric_limits<int>::max() && !visited[v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                pq.push({ dist[v], v });
            }
        }
    }
    return dist;
}

// Алгоритм Дейкстры, O(E * log2(V)) с восстановлением пути
vector<pair<int, int> > dijkstra(const vector<vector<pair<int, int>>>& g, int s) {
    int n = g.size();
    vector<pair<int, int> > d(n, { inf, -1});
    d[s] = { 0, -1 };
    set<pair<int, int> > q;
    q.emplace(0, s);
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (auto e : g[v]) {
            auto u = e.first;
            auto w = e.second;

            if (d[u].first > d[v].first + w) {
                q.erase({ d[u].first, u });
                d[u] = { d[v].first + w, v };
                q.emplace(d[u].first, u);
            }
        }
    }
    return d;
}


// Алгоритм Флойда-Уоршелла
vector<vector<int>> floydWarshall(vector<vector<int>> g) {

    for (int i = 0; i < g.size(); ++i) {
        g[i][i] = 0;
    }

    for (int k = 0; k < g.size(); k++) {
        for (int i = 0; i < g.size(); i++) {
            for (int j = 0; j < g.size(); j++) {
                if (g[i][k] + g[k][j] < g[i][j]) {
                    g[i][j] = g[i][k] + g[k][j];
                }
            }
        }
    }
    return g;
}


pair<int, vector<int>> masha(int start, const std::vector<std::vector<int>>& graph) {
    int n = graph.size();

    int bits_for_index = 1;

    while ((1 << bits_for_index) < n) {
        bits_for_index++;
    }

    vector<vector<pair<int, int >>> state_g(1 << (n + bits_for_index));

    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int from = 0; from < n; ++from) {
            for (int to = 0; to < n; ++to) {
                state_g[mask + (from << n)].push_back({ (mask | (1 << to)) + (to << n), graph[from][to]});
            }
        }
    }

    auto result_d = dijkstra(state_g, (start << n));
    int ans = result_d[(1 << n) - 1 + (start << n)].first;
    int vertex = result_d[(1 << n) - 1 + (start << n)].second;

    vector<int> path;
    while (vertex != -1) {
        cout << (vertex >> n) << endl;
        path.push_back((vertex >> n));
        vertex = result_d[vertex].second;
    }

    
    reverse(path.begin(), path.end());
    path.push_back(start);

    return { ans, path };
}

// Алгоритм перевода из списка смежности в матрицу смежности
vector<vector<int>> to_adjacency_matrix(const vector<vector<pair<int, int >>>& g) {
    vector<vector<int>> ret;

    ret.resize(g.size());

    for (int i = 0; i < g.size(); ++i) {
        ret[i].resize(g.size());
        for (int j = 0; j < g.size(); ++j) {
            ret[i][j] = inf;
        }
    }

    for (int i = 0; i < g.size(); ++i) {
        ret[i].resize(g.size());
        for (int j = 0; j < g[i].size(); ++j) {
            ret[i][g[i][j].first] = g[i][j].second;
            ret[g[i][j].first][i] = g[i][j].second;
        }
    }

    return ret;
}