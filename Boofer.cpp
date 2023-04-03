#include <iostream>
#include <chrono>
#include <fstream>

struct BoofPair_t{
    int data;
    BoofPair_t *next;
};

BoofPair_t* Init (int data){
    auto head = new BoofPair_t {data, nullptr};
    head->next = head;
    return head;
}




BoofPair_t* add_node (BoofPair_t * const head, int data){
    auto new_head = new BoofPair_t {data, head};
    auto h = head;
    while (h->next != head) {
        h = h->next;
    }
        h->next = new_head;

    return new_head;

}

void add_after (BoofPair_t * const ptr, int data){
    auto new_ell = add_node(ptr->next,data);
    ptr->next = new_ell;
}

void remove_after (BoofPair_t** head, BoofPair_t* ptr){
    auto h = ptr->next;
    //std::cout << h << ' ' << h->data << std::endl;

    ptr->next = ptr->next->next;
    //std::cout << ptr->next << ' ' << ptr->next->data << std::endl;

    delete h;
    *head = ptr->next;
}

void remove_all (BoofPair_t* head){
    while (head->next!= head){
        remove_after(&head,head);
    }
    delete head;
}

/*
void remove_after (BoofPair_t** head, int num){
    auto h = *(head + num-1);
    auto ptr = h;
    std::cout << h << ' ' << h->data << std::endl;

    ptr->next = ptr->next->next;
    std::cout << ptr->next << ' ' << ptr->next->data << std::endl;

    delete h;
    *head = ptr->next;
}
*/

BoofPair_t* create_in_order (int size){
    auto head = Init (size-1);
    for (int i = size-1; i>0; --i){
        add_after(head, i-1);
    }
    head = head->next;
    return head;
}


int len (BoofPair_t* head){
    auto h = head;
    int len = 1;
    while (h->next != head){
        h = h->next;
        ++len;
    }
    return len;
}

void PrintBoof (BoofPair_t * const head){
    auto h = head;
    while (h->next != head){
        std::cout<< h->data<< ' ';
        h = h->next;
    }
    std::cout<< h->data<< ' ';
    std::cout<<'\n';
}

int Josephus_recursion (int n, int k){
    if ( n == 0){
        return 0;
    }
    else{
        return (Josephus_recursion(n - 1, k) + k) % n;
    }
}





BoofPair_t* Josephus_boofer_rec (BoofPair_t* head, int size, int step){
    //int size = len(head);
    //PrintBoof(head);
    if (size == 1){
        return head;
    }
    else{
        auto h = head;
        for (int i = 0; i<step-2; ++i){
            h = h->next;
        }
        remove_after(&head,h);
        --size;
        head = h->next;
        //PrintBoof(head);
        return Josephus_boofer_rec(head, size, step);
    }
}

BoofPair_t* Josephus_boofer (BoofPair_t* head, int size, int step){
    while (size > 1){
        auto h = head;
        for (int i = 0; i<step-2; ++i){
            h=h->next;
        }
        remove_after(&head, h);
        --size;
        //PrintBoof(head);
    }
    return head;
}




int main(){
    /*for (int i = 0; i< 5; ++i) {
        auto head = create_in_order(41);
        //remove_after(&head, head->next->next);
        PrintBoof(head);
        std::cout << head<<std::endl;
        remove_all(head);
        std::cout << head<<std::endl;
    }*/
    //std::cout<<Josephus_boofer(head,41,3)->data;
    std::ofstream fout("Josephus_rec.py");

    fout << "from matplotlib import pyplot as plt\nimport numpy as np\n";

    fout << "am_of_ells = [";

    int value[] = {100,228,400,1337,1600,3200,5000,7000,10000,15000,20000,
                   25000,35000,45000,60000,75000,95000,115000,/*140000,165000,
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
        auto head = create_in_order(size);

        auto begin = std::chrono::steady_clock::now();

        head = Josephus_boofer(head,size, step);
        //Josephus_recursion(size,step);
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
        fout << time_span.count() << " ,";

        std::cout<<size<<std::endl;

        delete head;


    }
    fout << "]\n";
    fout << "plt.grid()";
    fout << "\n";
    fout << "plt.plot(am_of_ells, time, '.')";
    fout << "\n";
    fout << "plt.savefig('josephus_rec')";
    fout << "\n";
    fout << "plt.show()";
}