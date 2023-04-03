#include <iostream>

#include <iostream>

struct DynamicArray {
    int *value;
    int size;
};

DynamicArray createArray(int size) {
    DynamicArray arr;
    arr.value = new int[size];
    arr.size = size;
    /*for (int i = 0; i < size; i++) {
        value.value[i] = 0;
    }*/
    return arr;
}

void deleteArray(DynamicArray arr) {
    delete[] arr.value;
}

DynamicArray resizeArray(DynamicArray &arr, int newSize) {
    DynamicArray newArr = createArray(newSize);
    for (int i = 0; i < arr.size; i++) {
        newArr.value[i] = arr.value[i];
    }
    delete[] arr.value;
    return newArr;
}

void setArray(DynamicArray arr, int index, int value) {
    if (index >= 0 && index < arr.size) {
        arr.value[index] = value;
        //std::cout << value.value[index] << " ";
    }
    if (index >= 0 && index >= arr.size) {
        arr = resizeArray(arr, arr.size+1);
        arr.value[index] = value;
    }
    //std::cout << '\n';
    for (int i = 0; i < 20; i++) {
        std::cout <<arr.arrp<< " ";
    }
}

int getArray(DynamicArray arr, int index) {
    if (index >= 0 && index < arr.size) {
        return arr.value[index];
    }
    return -1;
}

int main() {
    DynamicArray arr = createArray(10);
    /*for (int i = 0; i < 12; i++) {
        setArray(value, i, i);
    }*/
    setArray(arr, 11, 11);
    std::cout << arr.size << std::endl;
    //resizeArray(value, 20);
    std::cout << arr.size << std::endl;
    for (int i = 0; i < 20; i++) {
        std::cout << getArray(arr, i) << " ";
    }
    deleteArray(arr);

    return 0;
}
