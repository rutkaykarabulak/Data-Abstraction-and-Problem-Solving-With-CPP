#include <iostream>

using namespace std;

int findLargestIndexOfArray(const int arr[], int last) {
    int largestIndexSoFar = 0;

    for(int i=1; i<last; i++) {
        if(arr[i] > arr[largestIndexSoFar])
            largestIndexSoFar = i;
    }

    return largestIndexSoFar;
}

void recursiveSelectionSort(int arr[], const int& size) {
    if(size > 0) {
        int index = findLargestIndexOfArray(arr, size);
        swap(arr[size-1], arr[index]);
        recursiveSelectionSort(arr, size-1);
    } // if size less than 0, it's a base case
}

void recursiveBubbleSort(int arr[], int size, int pass) {
    if(pass < size) {
        for(int i=0; i<size-pass; i++) {
            if(arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
            }
        }
        recursiveBubbleSort(arr, size, pass+1);
    }
}

int main() {
    int arr[] = {77,1,78,2,0,12};
    recursiveBubbleSort(arr, 6, 1);

    for(int i=0; i<6; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}