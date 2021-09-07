#include <bits/stdc++.h>

#define ll  long long int

using namespace std;

const ll INF = 1e18;

struct node {
    ll val = 0;
};


// 0 based seg tree idx 
// range from l , r-1 so you should ask for l, r+1 if it is inclusive 
class segTree {

private:
    int size = 0;
    vector<node> arr;

    node NEUTRAL_VAL = {0};

    node init_leaf(ll val) {
        return {val};
    }

    node merge(node a, node b) {
        return {a.val + b.val};
    }

    void build(const vector<ll> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int) a.size()) {
                arr[x] = init_leaf(a[lx]);
            }
            return;
        }
        int mid = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, mid);
        build(a, 2 * x + 2, mid, rx);

        arr[x] = merge(arr[2 * x + 1], arr[2 * x + 2]);
    }

    void set(int i, ll v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            arr[x] = init_leaf(v);
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) {
            set(i, v, 2 * x + 1, lx, mid);
        } else {
            set(i, v, 2 * x + 2, mid, rx);
        }
        arr[x] = merge(arr[2 * x + 1], arr[2 * x + 2]);
    }

    node query(int l, int r, int x, int lx, int rx) {
        if (l >= rx || r <= lx) return NEUTRAL_VAL;
        if (lx >= l && rx <= r) return arr[x];

        int mid = (lx + rx) / 2;
        auto ans1 = query(l, r, 2 * x + 1, lx, mid);
        auto ans2 = query(l, r, 2 * x + 2, mid, rx);

        return merge(ans1, ans2);
    }


public:
    segTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        arr.resize(2 * size);
    }

    void build(const vector<ll> &a) {
        build(a, 0, 0, size);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    node query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};


int32_t main() {

    int n, m, v, q, idx, l, r;
    cin >> n >> m;
    segTree st(n);
    vector<ll> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    st.build(vec);
    for (int i = 0; i < m; ++i) {
        cin >> q;
        if (q == 1) {
            cin >> idx >> v;
            st.set(idx, v);
        } else {
            cin >> l >> r;
            auto ans = st.query(l, r);
            cout << ans.val << endl;
        }

    }
    return 0;
}