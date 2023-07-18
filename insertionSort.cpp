#include<iostream>
using namespace std;

int* insertionSort(int array[], int n) {
    for (int i = 1; i < n; i++) {
        int value = array[i];
        int j = i - 1;

        while(j >= 0 && array[j] > value) {
            array[j+1] = array[j];
            j = j - 1;
        }
        array[j+1] = value;
    }
    return array;
}

int main() {
    int n = 5;
    int array[n] = {5,9,2,7,1};
    int* orderedArray = insertionSort(array, n);
    
    cout << "|";
    for(int i = 0; i < 5; i++) {
        cout << array[i] << "|";
    }

    cout << endl;
    return 0;
}