#include <iostream>
using namespace std;

// para casos de arrays já ordenados ele executa uma complexidade O(n)
int* optimizedBubbleSort(int array[], int n) {
    bool hasSwap = true;
    for (int i = 0; i < n-1 && hasSwap; i++) {
        hasSwap = false;
        for (int j = 0; j < n-1; j++) {
            if (array[j] > array[j+1]) {
                int aux = array[j];
                array[j] = array[j+1];
                array[j+1] = aux;
                hasSwap = true;
            }
        }
    }
    return array;
}

int* bubbleSort(int array[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1; j++) {
            if (array[j] > array[j+1]) {
                int aux = array[j];
                array[j] = array[j+1];
                array[j+1] = aux;
            }
        }
    }
    return array;
}

int main() {
    int n = 5;
    int array[n] = {5,9,2,7,1};
    int* orderedArray = optimizedBubbleSort(array, n);
    
    cout << "|";
    for(int i = 0; i < 5; i++) {
        cout << array[i] << "|";
    }

    cout << endl;
    return 0;
}