#include <bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long

#define  INF 1e9
using namespace std;

const int N = 300009 , Q = 300009 ;
int bsize, inp[N], ans[Q], n, q, result = 0;

struct Query {
    int l, r, id;

    bool operator<(const Query &ob) const {
        if (l / bsize == ob.l / bsize)
            return r < ob.r;
        return l / bsize < ob.l / bsize;
    }
} query[Q];

// You need to update following data structure
// per problem (e.g. use mutliset)
int cnt[300000 + 9], freqCnt[300000 + 9], sz[300000 + 9];

// You need to update these 2 methods per a problem
void add(int idx) {
    int val = inp[idx];
    int f = cnt[val];
    if (result == f) result++;

    cnt[val]++;
    freqCnt[f]--;
    freqCnt[f + 1]++;
}

void remove(int idx) {
    int val = inp[idx];
    int f = cnt[val];
    if (cnt[inp[idx]] == result && freqCnt[f] == 1) {
        result--;
    }
    cnt[val]--;
    freqCnt[f]--;
    freqCnt[f - 1]++;
}

void process() {  // don't change
    sort(query, query + q);
    memset(cnt, 0, sizeof cnt);
    memset(freqCnt, 0, sizeof freqCnt);
    int currL = 0, currR = -1;
    for (int i = 0; i < q; i++) {
        int L = query[i].l;
        int R = query[i].r;
        while (currL > L) add(--currL);
        while (currR < R) add(++currR);
        while (currL < L) remove(currL++);
        while (currR > R) remove(currR--);

        ans[query[i].id] = result;
    }
}

void read() {
    scanf("%d %d", &n, &q);
    bsize = sqrt(n) + 1;

    for (int i = 0; i < n; i++) {
        scanf("%d", &inp[i]);
    }
    for (int i = 0; i < q; i++) {
        int r, l;
        scanf("%d%d", &l, &r);
        query[i].l = l - 1, query[i].r = r - 1;
        query[i].id = i;
        sz[i] = query[i].r - query[i].l + 1;
    }
}

void getAns() {
    process();
    // depends on the problem
    for (int i = 0; i < q; i++) {
        if (ans[i] > (sz[i] + 1) / 2) {
            int rest = sz[i] - ans[i];
            int sol = ans[i] - rest;
            printf("%d\n", sol);
        } else printf("%d\n", 1);

    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);
#endif
    IO;
    read();
    getAns();
    return 0;
}