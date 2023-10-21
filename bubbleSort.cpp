#include <iostream>
using namespace std;

// para casos de arrays já ordenados ele executa uma complexidade O(n)
int* optimizedBubbleSort(int array[], int n) {
    bool hasSwap = true;
    for (int i = 0; i < n-1 && hasSwap; i++) {
        hasSwap = false;
        for (int j = 0; j < n-1; j++) {
            cout << "entrou" << endl;
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
            cout << "entrou" << endl;
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
    int n = 7;
    int array[n] = {90,80,70,40,30,20,10};;
    int* orderedArray = bubbleSort(array, n);
    
    cout << "|";
    for(int i = 0; i < 7; i++) {
        cout << orderedArray[i] << "|";
    }

    cout << endl;
    return 0;
}