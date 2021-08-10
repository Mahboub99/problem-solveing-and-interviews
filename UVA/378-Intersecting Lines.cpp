
#include <bits/stdc++.h>

#define IO  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll  long long int
#define ld long double
#define INF 1e18
#define N 1000010
using namespace std;

ll MOD = 2147483647;

ld EPS = 1e-18;


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    IO;
    int t;
    cin >> t;
    int cnt = 0;
    while (t--) {
        ld arrX[4], arrY[4];
        for (int i = 0; i < 8; ++i) {
            if (i % 2 == 0) cin >> arrX[i / 2];
            else cin >> arrY[i / 2];
        }
        if (cnt == 0) cout << "INTERSECTING LINES OUTPUT" << endl;
        cnt++;
        if (arrX[0] == arrX[1] || arrX[2] == arrX[3]) {
            ld diff1 = arrX[1] - arrX[0];
            ld diff2 = arrX[3] - arrX[2];
            // two line with 90 degree
            if (diff1 == diff2) {
                if (arrX[0] == arrX[2]) {
                    cout << "LINE" << endl;
                } else {
                    cout << "NONE" << endl;
                }

            } else {
                // one line is 90 degree
                if (diff1 == 0) {
                    ld m2 = (arrY[3] - arrY[2]) / (arrX[3] - arrX[2]);
                    ld c2 = arrY[2] - m2 * arrX[2];

                    ld x = arrX[0];
                    ld y = m2 * x + c2;
                    cout << fixed << setprecision(2) << "POINT " << x << " " << y << endl;

                } else {
                    ld m1 = (arrY[1] - arrY[0]) / (arrX[1] - arrX[0]);
                    ld c1 = arrY[0] - m1 * arrX[0];


                    ld x = arrX[2];
                    ld y = m1 * x + c1;
                    cout << fixed << setprecision(2) << "POINT " << x << " " << y << endl;

                }
            }

        } else {

            ld m1 = (arrY[1] - arrY[0]) / (arrX[1] - arrX[0]);
            ld m2 = (arrY[3] - arrY[2]) / (arrX[3] - arrX[2]);

            ld c1 = arrY[0] - m1 * arrX[0];
            ld c2 = arrY[2] - m2 * arrX[2];

            if (abs(m1 - m2) <= EPS) {
                if (abs(c1 - c2) <= EPS) {
                    cout << "LINE" << endl;
                } else {
                    cout << "NONE" << endl;
                }
            } else {
                ld x = (c2 - c1) / (m1 - m2);
                ld y = m1 * x + c1;
                cout << fixed << setprecision(2) << "POINT " << x << " " << y << endl;
            }
        }
        if (t == 0) cout << "END OF OUTPUT" << endl;
    }

    return 0;
}