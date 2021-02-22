#include <bits/stdc++.h>

using namespace std;

void insertionSort(vector<int> &vec)
{

    for (int i = 1; i < vec.size(); i++)
    {
        int key = vec[i];
        int j;
        for (j = i - 1; j >= 0 && vec[j] > key; j--)
        {
            vec[j + 1] = vec[j];
        }
        vec[j + 1] = key;
    }
}
void selectionSort(vector<int> &vec)
{

    for (int i = 0; i < vec.size(); i++)
    {
        int minj = i;
        for (int j = i + 1; j < vec.size(); j++)
        {
            if (vec[j] < vec[minj])
                minj = j;
        }
        if (minj != i)
            swap(vec[i], vec[minj]);
    }
}