#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &vec, int l, int r, int mid)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    vector<int> left(n1 + 1), right(n2 + 1);
    for (int i = 0, j = l; j <= mid; i++, j++)
        left[i] = vec[j];
    for (int i = 0, j = mid + 1; j <= r; i++, j++)
        right[i] = vec[j];

    left[n1] = right[n2] = 1e9;
    int i = 0, j = 0;
    for (int k = l; k <= r; k++)
        if (left[i] <= right[j])
            vec[k] = left[i], i++;
        else
            vec[k] = right[j], j++;
}
void mergeSort(vector<int> &vec, int l, int r)
{

    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(vec, l, mid);
        mergeSort(vec, mid + 1, r);

        merge(vec, l, r, mid);
    }
}
