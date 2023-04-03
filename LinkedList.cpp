#include <iostream>

struct ListPair_t{
    int data;
    ListPair_t *next;
};


ListPair_t* add_node ( int data, ListPair_t * const head){
    return new ListPair_t {data, head};

}

ListPair_t* get_adress (ListPair_t * const head, int number){
    auto h = head;
    for( int i = 0; i!=number; ++i) {
        if (h == nullptr) return h;
        h = h->next;
    }
    return h;
}

int get_data (ListPair_t * const head, int number){
    return get_adress(head, number)->data;
}

void PrintList (ListPair_t * const head){
    auto h = head;
    while (h != nullptr){
        std::cout<< h->data<< ' ';
        h = h->next;
    }
    std::cout<<'\n';
}

bool add_after (ListPair_t * const head, int number, int data){
    auto h = head;
    for( int i = 0; i != number; ++i) {
        if ( h->next == nullptr) {
            std::cout<<"List index out of range"<<std::endl;
            return false;
        }
        h = h->next;
        }
    ListPair_t *new_ell = add_node(data, h->next);
    h->next = new_ell;
    return true;
}

void add_after (ListPair_t * const ptr, int data){
    auto new_ell = add_node(data,ptr->next);
    ptr->next = new_ell;
}


void remove_after_first (ListPair_t* head){
    auto h = head->next->next;
    delete head->next;
    head->next = h;
}

bool remove_after (ListPair_t* head, int number){
    auto h = head;
    for( int i = 0; i != number; ++i) {
        if ( h->next == nullptr) {
            std::cout<<"List index out of range"<<std::endl;
            return false;
        }
        h = h->next;
    }
    auto hh = h->next->next;
    delete h->next;
    h->next = hh;
    return true;
}

void remove_after (ListPair_t* ptr){
    auto h = ptr->next;
    ptr->next= ptr->next->next;
    delete h;
}

void remove_all (ListPair_t* head){
    while (head->next!= nullptr){
        remove_after(head,0);
    }
    delete head;
}


int recursion_remove (ListPair_t* head) {
    if (head->next != nullptr) {
        remove_after(head, 0);
        return recursion_remove(head);
    } else {
        delete head;
        return 1;
    }
}

ListPair_t* return_reverse (ListPair_t* head){
    ListPair_t* nextNode = nullptr;
    ListPair_t* prev = nullptr;
    ListPair_t* curr = head;
    while(curr != nullptr) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    head = prev;
    return head;
}

void reverse(ListPair_t** head) {
    ListPair_t* prev = nullptr;
    ListPair_t* curr = *head;
    ListPair_t* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

ListPair_t* recursion_reverse(ListPair_t* curr, ListPair_t* prev = nullptr) {
    if (curr == nullptr) {
        return prev;
    }
    ListPair_t* next = curr->next;
    curr->next = prev;
    return recursion_reverse(next, curr);
}


int len (ListPair_t* head){
    auto h = head;
    int len = 0;
    while (h != nullptr){
         h = h->next;
         ++len;
    }
    return len;
}

void swap_neighbour(ListPair_t* prev) {
    ListPair_t* tmp = prev->next;
    prev->next= prev->next->next;
    tmp->next= prev->next->next;
    prev->next->next=tmp;
}

void swap_1_2 (ListPair_t ** head){
    ListPair_t* frst = *(head);
    ListPair_t* scnd = *(head);
    frst=frst->next;
    scnd->next = scnd->next->next;
    frst->next = scnd;
    *head= frst;
}

void InsertSort(ListPair_t ** head) {
    int size = len(*head);
    int i, j, key = 0, temp = 0;
    for (i = 0; i < size - 1; i++) {
        key = i+1;
        temp = get_data(*head,key);
        for (j = i + 1; j > 0; j--) {
            if (temp < get_data(*head, j-1)){
                if (j == 1) {
                    swap_1_2(head);
                }
                else{
                    swap_neighbour(get_adress(*head,j-2));
                }
            }
        }
    }
}


int main(){
    auto head = add_node(1, nullptr);
    //std::cout<<head<<std::endl;
    head = add_node(2, head);
    head = add_node(4, head);
    add_after(head,0,3);
    head = add_node(5, head);
    add_after(head->next, 8);
    PrintList(head);
    remove_after(head);
    PrintList(head);
    //return_reverse(&head);
    //PrintList(head);
    reverse(&head);
    PrintList(head);
    head = return_reverse(head);
    PrintList(head);
    head = recursion_reverse(head);
    PrintList(head);
    std::cout<<len(head)<<std::endl;
    std::cout<<get_data(head,2)<<std::endl;
    swap_neighbour(head);
    PrintList(head);
    swap_1_2(&head);

    PrintList(head);
    InsertSort(&head);
    PrintList(head);


    InsertSort(&head);
    PrintList(head);

    return 0;
}