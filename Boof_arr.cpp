#include <iostream>
#include <chrono>
#include <fstream>

int* createArray (int size){
    int *arr = new int[size];
    for (int i = 0; i<size; ++i){
        arr[i]=i;
    }
    return arr;
}

void deleteArray(int* arr) {
    delete[] arr;
}
void printArray (int* arr, int size){
    for (int i = 0; i<size; ++i){
        std::cout<<arr[i]<<' ';
    }
    std::cout<<'\n';
}

void delete_ell (int* arr, int &size, int index){
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    --size;
}

/*int Josephus (int* arr, int n, int m, int &first){
    //printArray(arr,n);
    //std::cout<<n<<' '<<m<<' '<< first<<std::endl;
    if (n == 1){
        return arr[0];
    }
    else{
        delete_ell(arr,n,(m-1+first)%n);
        first += (m-1)%n;
        return Josephus(arr,n,m,first);

    }
}*/

int josephus(int* arr, int n, int k) {
    int index = 0;
    for (int size = n; size>0; --size) {
        index = (index + k - 1) % (size);
        for (int j = index; j < size - 1; j++) {
            arr[j] = arr[j + 1];
        }
    }
    return arr[0];
}
int main() {
   /* int size = 41;
    int step = 32;
    int first = 0;
    int* arr = createArray(size);
    //delete_ell(arr,size, 5);
    printArray(arr,size);
    std::cout<<josephus(arr,size,step);*/
    //std::cout<<Josephus(arr,size,step,first);
    std::ofstream fout("Josephus_arr.py");

    fout << "from matplotlib import pyplot as plt\nimport numpy as np\n";

    fout << "am_of_ells = [";

    int value[] = {100,228,400,1337,1600,3200,5000,7000,10000,15000,20000,
                   25000,35000,45000,60000,75000,95000,/*115000,140000,165000,
                   195000,225000,250000,295000,335000,375000,420000,465000,499999, 510000*/

    };
    for ( int i : value ){
        fout << i << " ,";
    }
    fout << "]\n";
    int amount = sizeof(value)/sizeof(int);
    int Size[amount];
    fout << "time = [";
    int step = 3;
    for( int size:value) {
        int* arr = createArray(size);

        auto begin = std::chrono::steady_clock::now();

        josephus(arr, size, step);
        //printArray(arr);
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
        fout << time_span.count() << " ,";

        std::cout<<size<<std::endl;
        deleteArray(arr);
    }
    fout << "]\n";
    fout << "plt.grid()";
    fout << "\n";
    fout << "plt.plot(am_of_ells, time, '.')";
    fout << "\n";
    fout << "plt.savefig('josephus_arr')";
    fout << "\n";
    fout << "plt.show()";
    return 0;
}

