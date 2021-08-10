#include <bits/stdc++.h>

#include <utility>

#define IO  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll  long long int
#define ld long double
#define ld long double
#define EPS 0.00001;
#define INF 1e9
#define N 1000010
ll MOD = 1e9 + 9;
using namespace std;

const int MAXN = 1000010;

typedef vector<ll> row;
typedef vector<row> matrix;

matrix zero(int n, int m) {
    return matrix(n, row(m));
}

matrix identity(int n) {
    matrix I = zero(n, n);
    for (int i = 0; i < n; i++)
        I[i][i] = 1;

    return I;
}

matrix multiply(const matrix &a, const matrix &b) {
    // (n1 x m1 ) . (n2 x m2) -> m1 = n2  cols from a rows from b
    matrix ret = zero(a.size(), b[0].size());
    // for each row in a
    for (int i = 0; i < a.size(); i++) {
        // for each col in b
        for (int j = 0; j < b[0].size(); j++) {
            // number of cols in a  = number of rows in b
            // so for each row in b
            for (int k = 0; k < b.size(); k++) {
                ret[i][j] += (a[i][k] * b[k][j]) % MOD;
                ret[i][j] %= MOD;

            }
        }
    }
    return ret;
}

matrix powMatrix(const matrix &a, ll p) {

    if (p == 0)
        return identity(a.size());
    // if odd (will jusyt happen once at the first)
    // so just add another itertion and solve for p-1
    if (p & 1)
        return multiply(a, powMatrix(a, p - 1));

    return powMatrix(multiply(a, a), p / 2);
}

int main() {
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);
#endif

    while (true) {

        ll n;
        cin >> n;
        if (n == 0) break;

        matrix X = zero(3, 1);
        X[0][0] = 2;
        X[1][0] = 1;
        X[2][0] = 0;

        matrix A = zero(3, 3);
        A[0][0] = A[0][1] = A[0][2] = A[1][0] = A[2][1] = 1;

        A = powMatrix(A, n - 1);
        matrix ret = multiply(A, X);

        cout << ret[2][0] % MOD << endl;
    }
    return 0;
}