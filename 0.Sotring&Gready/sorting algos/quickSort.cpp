
#include <bits/stdc++.h>

using namespace std;


int paration(vector<int> &vec, int start, int end) {
    int pivot = vec[start];
    int i = start, j = end;

    while (i < j) {
        while (vec[i] <= pivot) i++;
        while (vec[j] > pivot) j--;
        if (i < j) swap(vec[i], vec[j]);
    }
    swap(vec[start], vec[j]);

    return j;
}

void quickSort(vector<int> &vec, int start, int end) {
    if (start < end) {
        int pivot = paration(vec, start, end);
        quickSort(vec, start, pivot);
        quickSort(vec, pivot + 1, end);
    }
}

void quickSort(vector<int> &vec) {
    quickSort(vec, 0, vec.size() - 1);
}
