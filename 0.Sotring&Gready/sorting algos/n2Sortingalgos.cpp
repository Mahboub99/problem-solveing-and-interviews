// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector> 

using namespace std;

void bubleSort(vector<int> & vec){
    int  n = vec.size(); 
    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < n - i ;j++){
            if(vec[j] > vec[j+1]) swap(vec[j], vec[j+1]);
        }
    }
}
void insertionSort(vector<int> &vec){
    int  n = vec.size(); 
    for(int  i = 1 ; i < n ; i++){
        int j =  i; 
        while( j > 0 && vec[j-1] > vec[j]){
            swap(vec[j] , vec[j-1]);
            j--;
        }
    }
}
void selectionSort(vector<int>&vec){
    int n = vec.size(); 
    for(int i = 0 ; i < n-1 ; i++){
        int minIdx = i ;
        for(int j = i +1 ; j < n ; j++){
            if(vec[minIdx] > vec[j]) minIdx = j;
        }
        swap(vec[minIdx] , vec[i]);
    }
}


void printVec(vector<int>& vec){
    for(auto &c : vec){
        cout<< c <<" ";
    }
    cout<< endl;
}

int main() {
    // Write C++ code here
    vector<int> vec = { 10 , 9 , 2 , 1 , 11 , 14 , 2 , 12 , 20 ,24 , 7};
    bubleSort(vec); 
    printVec(vec);
    vec = { 10 , 9 , 2 , 1 , 11 , 14 , 2 , 12 , 20 ,24 , 7};
    insertionSort(vec);
    printVec(vec);
    vec = { 10 , 9 , 2 , 1 , 11 , 14 , 2 , 12 , 20 ,24 , 7};
    selectionSort(vec);
    printVec(vec);
    

    return 0;
}
