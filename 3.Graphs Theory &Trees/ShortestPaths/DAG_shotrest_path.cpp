#include <bits/stdc++.h>

#define ll long long int
#define INF 1e18

using namespace std;
const int MAXN = 100100;
ll n, m;

vector<vector<pair<ll, ll>>> adj;
vector<ll> sortedNodes;
bool visited[MAXN];
ll dist[MAXN];

void topoSort(ll u)
{
    visited[u] = true;
    for (auto v : adj[u])
    {
        if (!visited[v.first])
        {
            topoSort(v.first);
        }
    }
    sortedNodes.push_back(u);
}

// zero based is used
void DAG_shortestPath()
{
    for (ll i = 0; i < n; i++)
    {
        if (!visited[i])
            topoSort(i);
    }
    reverse(sortedNodes.begin(), sortedNodes.end());

    for (int i = 0; i < n; i++)
        dist[i] = INF;

    // zero based if you want to use one based just start with i = 1 end with i<=n
    dist[sortedNodes[0]] = 0;
    for (auto u : sortedNodes)
    {
        for (auto v : adj[u])
        {
            if (dist[v.first] > dist[u] + v.second)
            {
                dist[v.first] = dist[u] + v.second;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    adj.resize(n);
    ll u, v, w;
    for (ll i = 0; i < n; i++)
    {
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
    }
    DAG_shortestPath();
    for (ll i = 0; i < n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}
/*
4 4
1 2 2
1 3 6
2 4 3
3 4 -5
*/