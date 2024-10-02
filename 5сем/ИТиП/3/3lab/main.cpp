#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define int long long

const int inf = 1001 * 1001 * 1001;

vector<int> dijkstra(const vector<vector<pair<int, int>>>& g, int s) {
    int n = g.size();
    vector<int> d(n, inf);
    d[s] = 0;
    set<pair<int, int> > q;
    q.emplace(0, s);
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (auto [u, w] : g[v]) {
            if (d[u] > d[v] + w) {
                q.erase({d[u], u});
                d[u] = d[v] + w;
                q.emplace(d[u], u);
            }
        }
    }
    return d;
}

vector<vector<int>> to_adjacency_matrix(const vector<vector<pair<int, int >>>& g){
    vector<vector<int>> ret;

    ret.resize(g.size());

    for(int i = 0; i < g.size(); ++i){
        ret[i].resize(g.size());
        for(int j = 0; j < g.size(); ++j){
            ret[i][j] = inf;
        }
    }

    for(int i = 0; i < g.size(); ++i){
        ret[i].resize(g.size());
        for(int j = 0; j < g[i].size(); ++j){
            ret[i][g[i][j].first] = g[i][j].second;
        }
    }

    return ret;
}

vector<vector<int>> floydWarshall(vector<vector<int>> g){

    for(int i = 0; i < g.size(); ++i){
        g[i][i] = 0;
    }

    for(int k=0;k<g.size();k++){
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g.size();j++){
                if(g[i][k] + g[k][j] < g[i][j]){
                    g[i][j] = g[i][k] + g[k][j];
                }
            }
        }
    }
    return g;
}

pair<int, vector<int> > TSP(const vector<vector<int>>& g, int start)
{

    vector<int> vertex;
    for (int i = 0; i < g.size(); i++)
        if (i != start)
            vertex.push_back(i);

    int min_path = inf;
    vector<int> min_path_vec = {-1};

    do {

        int current_pathweight = 0;

        int k = start;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += g[k][vertex[i]];
            k = vertex[i];
        }

        current_pathweight += g[k][start];

        // update minimum

        if (current_pathweight < min_path){
            min_path = current_pathweight;
            min_path_vec = vertex;
            min_path_vec.push_back(start);
        }

    } while (
        next_permutation(vertex.begin(), vertex.end()));

    return {min_path, min_path_vec};
}

void task1(){
    vector<vector<pair<int, int>>> g;

    int n,m,start;
    cin >> n >> m >> start;
    --start;

    g.resize(n);

    for(int i = 0; i < m; ++i){
        int s,e,val;
        cin >> s >> e >> val;
        --s;
        --e;
        g[s].push_back({e,val});
        g[e].push_back({s,val});
    }

    auto paths = dijkstra(g,start);

    cout << endl<<"Djikstra:" << endl;
    for(auto elem : paths){
        cout << elem << " ";
    }

    cout << endl << endl << "FloydWarshall:" << endl;

    auto g_fw = floydWarshall(to_adjacency_matrix(g));


    for(auto elem : g_fw[start]){
        cout << elem << " ";
    }
}

void task2(){
    vector<vector<pair<int, int>>> g;

    int n,m,start;
    cin >> n >> m >> start;
    --start;

    g.resize(n);

    for(int i = 0; i < m; ++i){
        int s,e,val;
        cin >> s >> e >> val;
        --s;
        --e;
        g[s].push_back({e,val});
        g[e].push_back({s,val});
    }

    auto [ans, vec] = TSP(to_adjacency_matrix(g),start);

    cout << endl << ans << endl;

    cout << start+1 << " ";
    for(auto elem : vec){
        cout << elem+1 << " ";
    }
}

signed main()
{
    char c = '?';

    while (1){
        cout << "type 1 to enter task 1, type 2 to enter task 2: ";
        cin >> c;
        if (c == '1'){
            task1();
            return 0;
        }

        if (c == '2'){
            task2();
            return 0;
        }
    }

    return 0;
}
