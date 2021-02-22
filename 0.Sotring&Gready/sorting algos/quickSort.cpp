
#include <bits/stdc++.h>

using namespace std;

int partion(vector<int> &vec, int start, int end)
{
    int x = (end - start + 1);
    int random = rand() % x + start;
    swap(vec[end], vec[random]);

    int pivote = vec[end];
    int i = start - 1;

    for (int j = start; j <= end - 1; j++)
    {
        if (vec[j] <= pivote)
        {
            i++;
            if (i != j)
                swap(vec[j], vec[i]);
        }
    }
    swap(vec[end], vec[i + 1]);

    return i + 1;
}
void quickSort(vector<int> &vec, int start, int end)
{

    if (start < end)
    {
        int pivote = partion(vec, start, end);
        quickSort(vec, start, pivote - 1);
        quickSort(vec, pivote + 1, end);
    }
}
