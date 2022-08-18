#include <iostream>
using namespace std;

const int MAX_ARR_SIZE = 15;

/**
 * @brief Merges two different sorted array into one sorted array
*/
void merge(int arr[], const int first, const int mid ,const int last) {
    int tempArr[MAX_ARR_SIZE];

    int first1 = first;
    int last1 = mid;
    int first2 = mid+1;
    int last2 = last;

    int index = first; // index of temp array

    // while both subarrays are not empty, push the
    // smaller item to the tempArr
    while( (first1 <= last1) && (first2 <= last2)) {
        if(arr[first1] <= arr[first2]) {
            tempArr[index] = arr[first1];
            first1++;
        } else {
            tempArr[index] = arr[first2];
            first2++;
        }
        index++;
    }

    // if there is any item in first half of array push it to tempArr
    while(first1 <= last1) {
        tempArr[index] = arr[first1];
        first1++;
        index++;
    }

    // if there is any item in second half of array push it to tempArr
    while(first2 <= last2) {
        tempArr[index] = arr[first2];
        first2++;
        index++;
    }

    // copy the temp array to the original array
    for(index = first; index <= last; index++)
        arr[index] = tempArr[index];
}

/**
 * @brief Sorts the arr[first..last] by
 * 1. Sorting the arr[first..mid]
 * 2. Sorting the arr[mid+1..last]
 * 3. Merging the arr[first..mid] and arr[mid+1..last]
*/
void mergeSort(int arr[], int first, int last) {
    if(first < last) {
        int mid = (first + last) / 2; // get the mid point
        
        mergeSort(arr, first, mid); // sort first half 
        mergeSort(arr, mid+1, last); // sort second half
        merge(arr, first, mid, last); // merge the two halves
    }
    // if(first >= last) there is nothing to do
}

void displayArray(int arr[],int first, int last) {
    for(int i = first; i <= last; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[] = {8,1,4,3,2};
    mergeSort(arr, 0, 4);    
    
    displayArray(arr, 0, 4);
    return 0;
}
