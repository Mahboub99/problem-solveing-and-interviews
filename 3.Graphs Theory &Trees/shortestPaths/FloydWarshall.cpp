#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define INF 1e18

const int MAXN = 100;

ll n, m;
ll adj[MAXN][MAXN], dist[MAXN][MAXN];

void Floyd_Warshall()
{
    // intialize the matirx
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= n; j++)
            if (i == j)
                dist[i][j] = 0;
            else if (adj[i][j])
                dist[i][j] = adj[i][j];
            else
                dist[i][j] = INF;

    for (ll k = 1; k <= n; k++)
        for (ll i = 1; i <= n; i++)
            for (ll j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
void read()
{
    cin >> n >> m;
    ll u, v, w;
    for (ll i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u][v] = adj[v][u] = w;
    }
}

int main()
{
    // just for testing
    read();
    Floyd_Warshall();
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}
/*
     5 6
     1 2 5
     1 4 9
     1 5 1
     5 4 2
     4 3 6
     2 3 2
     */