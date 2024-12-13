// вариант 7

#include <iostream>

bool starts_w_one(int num){
    short last = 0;
    while (num > 0) {
        last = num % 10;
        num /= 10;
    }
    return (last == 1);
}

bool simple(int num){
    for (int i = 2; i <= sqrt(num); i++){
        if (!(num % i)){
            return false;
        }
    }
    return true;
}

struct Node {
    int val;
    Node* next;

    Node(int _val) : val(_val), next(nullptr) {}
};

struct list {
    Node* first;
    Node* last;

    list() : first(nullptr), last(nullptr) {}

    bool is_empty() {
        return first == nullptr;
    }

    void push_back(int _val) {
        Node* p = new Node(_val);
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }

    void print() {
        if (is_empty()) {
            return;
        }
        Node* p = first;
        while (p) {
            std::cout << p->val << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }

    bool has_start_one() {
        if (is_empty()) {
            std::cout << "no entities";
            return false;
            }
        Node* p = first;
        while (p) {
            if (starts_w_one(p->val)){return true;}
            std::cout << p->val << " ";
            p = p->next;
        }
        return false;
    }

    void sort() {
        bool go = true;
        while (go) {
            go = false;
            Node* t = nullptr;
            Node* a = first;
            Node* b = a->next;

            while (b != nullptr) {
                if (a->val > b->val) {
                    if (t == nullptr) {
                        first = b;
                    } else {
                        t->next = b;
                    }

                    a->next = b->next;
                    b->next = a;

                    t = b;
                    b = a->next;

                    go = true;
                } else {
                    t = a;
                    a = b;
                    b = b->next;
                }
            }
        }
}

    void del_three(){
        Node* current = first;
        Node* prev = nullptr;

        while (current) {
            if ((current->val > 3) && current->val % 3 == 0)  {
                if (prev) {
                    prev->next = current->next;
                } else {
                    first = current->next;
                }
                if (current == last) {
                    last = prev;
                }
                Node* temp = current;
                current = current->next;
                delete temp;
            } else {
                if (simple(current->val)) {
                    Node* duplicate = new Node(current->val);
                    duplicate->next = current->next;
                    current->next = duplicate;
                    if (current == last) {
                        last = duplicate;
                    }
                    prev = duplicate;
                    current = duplicate->next;
                } else {
                    prev = current;
                    current = current->next;
                }
            }
        }
    }   
};




int main() {
    list array;
    int n = 5;
    int additional;
    for (int i = 0; i < n; i++){
        std::cin >> additional;
        array.push_back(additional);
    }

    // array.push_back(3);
    // array.push_back(5);
    // array.push_back(23);
    // array.push_back(1);
    // array.push_back(9);
    // array.push_back(27);
    // array.push_back(103);
    // array.push_back(2);
    // array.push_back(3);
    // array.push_back(4);
    array.print();

    if (array.has_start_one()){
        array.sort();
    }else{
        array.del_three();
    }
    array.print();
    return 0;
}