#include <iostream>

int main() {
    int arr[5] = {1,2,3,4,5};

    // print first element
    std::cout << "First Element: " << arr[0] << std::endl;

    // iterate
    for (int i : arr) {
        std::cout << i << std::endl;
    }

    // change value of a position
    arr[1] = 22;
    return 0;
}