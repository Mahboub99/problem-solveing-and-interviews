#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IO                        \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

typedef vector<ll> row;
typedef vector<row> matrix;

matrix zero(int n, int m)
{
    return matrix(n, row(m));
}

matrix identity(int n)
{
    matrix I = zero(n, n);
    for (int i = 0; i < n; i++)
        I[i][i] = 1;

    return I;
}

matrix multiply(const matrix &a, const matrix &b)
{
    // (n1 x m1 ) . (n2 x m2) -> m1 = n2  cols from a rows from b
    matrix ret = zero(a.size(), b[0].size());
    // for each row in a
    for (int i = 0; i < a.size(); i++)
    {
        // for each col in b
        for (int j = 0; j < b[0].size(); j++)
        {
            // number of cols in a  = number of rows in b
            // so for each row in b
            for (int k = 0; k < b.size(); k++)
            {
                ret[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return ret;
}

matrix powMatrix(const matrix &a, ll p)
{

    if (p == 0)
        return identity(a.size());
    // if odd (will jusyt happen once at the first)
    // so just add another itertion and solve for p-1
    if (p & 1)
        return multiply(a, powMatrix(a, p - 1));

    return powMatrix(multiply(a, a), p / 2);
}

int main()
{
    IO;
    matrix init = zero(2, 2);
    init[0][1] = 1;
    /*
     0 1 
     0 0
    */
    matrix trans = zero(2, 2);
    trans[0][1] = trans[1][0] = trans[1][1] = 1;
    while (true)
    {
        int n;
        cin >> n;
        matrix ans = multiply(init, powMatrix(trans, n));
        cout << ans[0][0] << endl;
    }
    return 0;
}