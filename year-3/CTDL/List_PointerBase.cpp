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
    Node *next;
};

typedef Node *List;
typedef Node *Position;

void insert(List &L, ElementType e, Position p) {
    Position newItem = new Node();
    newItem->e = e;
    newItem->next = nullptr;

    if (L == nullptr || p == nullptr) {
        newItem->next = L;
        L = newItem;
    } 
	else {
        newItem->next = p->next;
        p->next = newItem;
    }
}

void deleteNode(List &L, Position p) {
    if (L == nullptr || p == nullptr) return;

    if (p == L) {
        L = p->next;
        delete p;
    } 
	else {
        Position prevP = L;
        while (prevP != nullptr && prevP->next != p) {
            prevP = prevP->next;
        }
        if (prevP != nullptr) {
            prevP->next = p->next;
            delete p;
        }
    }
}

void display(List L) {
    while (L != nullptr) {
        cout << "id: " << L->e.id << " - name:" << L->e.name << "\n";
        L = L->next;
    }
}

Position find(List L, int id) {
    while (L != nullptr && L->e.id != id) {
        L = L->next;
    }
    return L;
}

void freeList(List &L) {
    while (L != nullptr) {
        Position temp = L;
        L = L->next;
        delete temp;
    }
}

int main() {
    List stdList = nullptr;
    ElementType e1 = {1, "Nguyen Van A"};
    ElementType e2 = {2, "Nguyen Van B"};
    ElementType e3 = {3, "Nguyen Van C"};
    ElementType e4 = {4, "Nguyen Van D"};

    insert(stdList, e1, nullptr);
    insert(stdList, e2, nullptr);
    insert(stdList, e3, nullptr);
    insert(stdList, e4, nullptr);

    cout << "The list is:\n";
    display(stdList);

    Position item = find(stdList, 4);
    deleteNode(stdList, item);

    cout << "The list is:\n";
    display(stdList);

    freeList(stdList);
    return 0;
}
