#include  "Algorithms.h"
#include <queue>
#include <limits>
#include <algorithm>
#include <set>
#include <utility>
#include <iostream>

using namespace std;

const int inf = 1001 * 1001 * 1001;

// �������� ��������, O(V^2)
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

// �������� ��������, O(E * log2(V)) � ��������������� ����
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


// �������� ������-��������
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

// �������� �������� �� ������ ��������� � ������� ���������
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

pair<int, std::vector<std::vector<int>> > fordFulkerson(std::vector<std::vector<std::pair<int, int>>> graph_adj, int source, int sink) {
    int N = graph_adj.size();
    const auto& capacity = to_adjacency_matrix(graph_adj);

    std::vector<std::vector<int>> adj(N);
    for (int from = 0; from < N; ++from) {
        for (const auto& e : graph_adj[from]) {
            int to = e.first;
            adj[from].push_back(to);
            adj[to].push_back(from); // ��������� ����
        }
    }

    std::vector<std::vector<int>> flow;
    flow.resize(N);
    for (int i = 0; i < N; ++i) {
        flow[i].resize(N);
        for (int j = 0; j < N; ++j) {
            flow[i][j] = 0;
        }
    }


    double maxFlow = 0;

    // Ford-Fulkerson algorithm using BFS (Edmonds-Karp implementation)
    while (true) {
        // Find an augmenting path
        std::vector<int> parent(N, -1);
        std::queue<int> q;
        q.push(source);
        parent[source] = -2; // Mark the source node

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                // Check for residual capacity
                if (parent[v] == -1 && capacity[u][v] - flow[u][v] > 0) {
                    parent[v] = u;
                    if (v == sink)
                        break; // Early exit if sink is reached
                    q.push(v);
                }
            }
        }

        // No augmenting path found
        if (parent[sink] == -1)
            break;

        // Find minimum residual capacity along the path
        int pathFlow = inf;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = std::min(pathFlow, capacity[u][v] - flow[u][v]);
        }

        // Update flows along the path
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            flow[u][v] += pathFlow;
            flow[v][u] -= pathFlow; // Update reverse flow
        }

        // Add to max flow
        maxFlow += pathFlow;
    }

    return { maxFlow, flow };
}


std::pair<int, std::vector<std::vector<int>> > findMinimalCut(std::vector<std::vector<std::pair<int, int>>> graph_adj, int source, int sink) {
    
    int N = graph_adj.size();
    const auto& capacity = to_adjacency_matrix(graph_adj);

    // Build adjacency list for the residual graph
    std::vector<std::vector<int>> adj(N);
    for (int from = 0; from < N; ++from) {
        for (const auto& e : graph_adj[from]) {
            int to = e.first;
            adj[from].push_back(to);
            adj[to].push_back(from); // ��������� ����
        }
    }

    std::vector<std::vector<int>> flow = fordFulkerson(graph_adj, source, sink).second;

    // Find vertices reachable from source in residual graph
    std::vector<bool> visited(N, false);
    std::queue<int> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v] && capacity[u][v] - flow[u][v] > 0) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    // Output the minimal cut edges and calculate its capacity
    
    std::vector<std::vector<int>> res;
    int minCutCapacity = 0;
    for (int u = 0; u < N; ++u) {
        if (visited[u]) {
            for (int v = 0; v < N; ++v) {
                if (!visited[v] && capacity[u][v] > 0 && capacity[u][v] != inf) {
                    // Edge u -> v (capacity[u][v])
                    res.push_back({ u + 1, v + 1, capacity[u][v] });
                    minCutCapacity += capacity[u][v];
                }
            }
        }
    }

    return { minCutCapacity, res };
}


std::vector<int> hungarianMethod(const std::vector<std::vector<int>>& costMatrix) {
    int n = costMatrix.size();
    std::vector<int> u(n + 1), v(n + 1), p(n + 1), way(n + 1);
    for (int i = 1; i <= n; i++) {
        p[0] = i;
        std::vector<int> minv(n + 1, std::numeric_limits<int>::max());
        std::vector<char> used(n + 1, false);
        int j0 = 0;
        do {
            used[j0] = true;
            int i0 = p[j0], delta = std::numeric_limits<int>::max(), j1;
            for (int j = 1; j <= n; j++) {
                if (!used[j]) {
                    int cur = costMatrix[i0 - 1][j - 1] - u[i0] - v[j];
                    if (cur < minv[j]) {
                        minv[j] = cur;
                        way[j] = j0;
                    }
                    if (minv[j] < delta) {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }
            for (int j = 0; j <= n; j++) {
                if (used[j]) {
                    u[p[j]] += delta;
                    v[j] -= delta;
                }
                else
                    minv[j] -= delta;
            }
            j0 = j1;
        } while (p[j0]);
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }
    std::vector<int> assignment;
    assignment.resize(n);
    for (int j = 1; j <= n; j++)
        assignment[p[j] - 1] = j - 1;

    return assignment;
}