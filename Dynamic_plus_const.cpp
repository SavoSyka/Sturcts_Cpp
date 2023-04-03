#include <iostream>
#include <chrono>
#include <fstream>

struct DynamicArray{
    int* value;
    int size;
    int step;
};

DynamicArray createArray(int size, int step) {
    DynamicArray arr;
    arr.value = new int[size];
    arr.size = size;
    arr.step = step;
    return arr;
}

void deleteArray(DynamicArray arr) {
    delete[] arr.value;
}

void delete_ell(DynamicArray *arr, int index){
    for (int i = index; i < arr->size-1; i++) {
        arr->value[i] = arr->value[i + 1];
    }
    --arr->size;
}

void printArray(DynamicArray arr){
    for (int i = 0; i < arr.size; ++i){
        std::cout<< arr.value[i]<< ' ';
    }
    std::cout<<'\n';
}

DynamicArray resize_const(DynamicArray arr) {
    DynamicArray newArr;
    int newSize = arr.size+arr.step;
    newArr.value = new int[newSize];
    newArr.size = newSize;
    newArr.step = arr.step;
    for (int i = 0; i < arr.size; i++) {
        newArr.value[i] = arr.value[i];
    }
    delete[] arr.value;
    return newArr;
}

int get_value(DynamicArray arr, int index) {
    if (index >= 0 && index < arr.size) {
        return arr.value[index];
    }
    return -1;
}

void push_back(DynamicArray* arr, int value){
    int size = arr->size;
    *arr = resize_const(*arr);
    arr->value[size] = value;

}

void set_value (DynamicArray* arr, int index, int value){
    if (index >= 0 && index < arr->size) {
        arr->value[index] = value;
    }

    else if (index >= 0 && index == arr->size) {
        push_back(arr, value);
    }
    else{
        std::cout<<"Error: Index out of range."<<std::endl;
    }

}


int main() {

    std::ofstream fout("plus_const.py");

    fout << "from matplotlib import pyplot as plt\nimport numpy as np\n";

    fout << "am_of_ells = [";

    int value[] = {100,228,400,1337,1600,3200,5000,7000,10000,15000,20000,
                   25000,35000,45000,60000,75000,95000,115000,140000,165000,
                   195000,225000,250000,295000,335000,375000,420000,465000,499999, 510000

    };
    for ( int i : value ){
        fout << i << " ,";
    }
    fout << "]\n";
    int amount = sizeof(value)/sizeof(int);
    int Size[amount];
    fout << "time = [";
    for( int i:value) {
        DynamicArray arr = createArray(1,1000);

        auto begin = std::chrono::steady_clock::now();
        for (int j = 0; j<i;++j) {
            set_value(&arr, j, j);
            //std::cout<<arr.size<<std::endl;
        }
        //printArray(arr);
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
        fout << time_span.count() << " ,";

        std::cout<<i<<std::endl;
        deleteArray(arr);
    }

    fout << "]\n";
    fout << "plt.grid()";
    fout << "\n";
    fout << "plt.plot(am_of_ells, time, '.')";
    fout << "\n";
    fout << "plt.savefig('plus_const')";
    fout << "\n";
    fout << "plt.show()";
    return 0;
}
