#include <bits/stdc++.h>

#define ll long long int

using namespace std;
int n, m;
const int MAXN = 100100;
bool vistied[MAXN];
vector<vector<ll>> adj, adjT, scc;
vector<ll> sortedNodes;

void topoSortDFS(ll u, const vector<vector<ll>> &curAdj, vector<ll> &res)
{
    vistied[u] = true;
    for (auto child : curAdj[u])
    {
        if (!vistied[child])
        {
            topoSortDFS(child, curAdj, res);
        }
    }
    res.push_back(u);
}

void kosaraju()
{
    // should be zero based
    memset(vistied, 0, sizeof(vistied));
    for (ll i = 0; i < n; i++)
    {
        if (!vistied[i])
        {
            topoSortDFS(i, adj, sortedNodes);
        }
    }
    reverse(sortedNodes.begin(), sortedNodes.end());

    memset(vistied, 0, sizeof(vistied));
    for (ll i = 0; i < n; i++)
    {
        ll u = sortedNodes[i];
        if (!vistied[u])
        {
            scc.push_back(vector<ll>());
            topoSortDFS(u, adjT, scc.back());
        }
    }
}

void read()
{
    cin >> n >> m;
    ll u, v;
    adj.resize(n + 1);
    adjT.resize(n + 1);

    for (ll i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adjT[v].push_back(u);
    }
}

int main()
{
    read();
    kosaraju();
    cout << scc.size() << endl;

    return 0;
}