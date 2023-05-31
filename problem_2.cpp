#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int solve(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> dist(n, vector<int>(n, INF));

    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];
        dist[u][v] = weight;
        dist[v][u] = weight;
    }


    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int minCities = n + 1; // Initialize with a value greater than n
    int city = -1;

    for (int i = 0; i < n; i++) {
        int reachableCities = 0;
        for (int j = 0; j < n; j++) {
            if (dist[i][j] <= distanceThreshold) {
                reachableCities++;
            }
        }
        if (reachableCities <= minCities) {
            minCities = reachableCities;
            city = i;
        }
    }

    return city;
}

// Do not modify the code below
int main() {
    int n, m, distanceThreshold;
    cin >> n >> m >> distanceThreshold;
    vector<vector<int>> edges;
    for (int i = 1; i <= m; i++) {
        int x, y, weight;
        cin >> x >> y >> weight;
        vector<int> f;
        f.push_back(x);
        f.push_back(y);
        f.push_back(weight);
        edges.push_back(f);
    }

    cout << solve(n, edges, distanceThreshold);
}
