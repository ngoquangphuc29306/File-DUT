#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz size()
#define ll long long
#define faster() ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

struct ElementType {
    int id;
    string name;
};

struct Node {
    ElementType e;
    Node* next;
    Node* prev;
};

typedef Node* List;
typedef Node* Position;

List createList() {
    return nullptr;
}

void insert(List &L, ElementType e, Position p) {
    Position newItem = new Node();
    newItem->e = e;
    if (p == nullptr) { //Chen vao dau dslk
        newItem->prev = nullptr;
        newItem->next = L;
        if (L != nullptr) {
            L->prev = newItem;
        }
        L = newItem;
    }
    else {
        newItem->next = p->next;
        newItem->prev = p;
        if (p->next != nullptr) {
            p->next->prev = newItem;
        }
        p->next = newItem;
    }
}

void deleteNode(List &L, Position p) {
    if (p == nullptr) return;
    if (p == L) {
        L = L->next;
        if (L != nullptr) {
            L->prev = nullptr;
        }
    }
    else {
        p->prev->next = p->next;
        if (p->next != nullptr) {
            p->next->prev = p->prev;
        }
    }
    delete p;
}


void display(List L) {
    Position p = L;
    while (p != nullptr) {
        cout << "id: " << p->e.id << " - name: " << p->e.name << endl;
        p = p->next;
    }
}

Position find(List L, int id) {
    Position p = L;
    while (p != nullptr && p->e.id != id) {
        p = p->next;
    }
    return p;
}

void freeList(List &L) {
    while (L != nullptr) {
        Position temp = L;
        L = L->next;
        delete temp;
    }
    L = nullptr;
}


int main() {
    faster();

    List stdList = createList();

    ElementType e1 = {1, "Nguyen Van A"};
    ElementType e2 = {2, "Nguyen Van B"};
    ElementType e3 = {3, "Nguyen Van C"};
    ElementType e4 = {4, "Nguyen Van D"};

    insert(stdList, e1, nullptr);
    insert(stdList, e2, nullptr);
    insert(stdList, e3, nullptr);
    insert(stdList, e4, nullptr);

    cout << "The list is:" << endl;
    display(stdList);

    Position item = find(stdList, 2);

    deleteNode(stdList, item);

    cout << "\nThe list after deleting id = 2:" << endl;
    display(stdList);

    freeList(stdList);

    return 0;
}