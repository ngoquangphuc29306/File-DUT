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

struct ListInfo {
    ElementType *theArray;
    int capacity;
    int count;
};

typedef ListInfo *List;
typedef int Position;

List createList(int capacity) {
    List L = new ListInfo();
    L->count = 0;
    L->capacity = capacity;
    L->theArray = new ElementType[capacity];
    return L;
}

void listInsert(List L, ElementType e, Position p) {
    if (L == nullptr) return;
    if (p > L->count || p < 0 || L->count == L->capacity) {
        cout << "The List is full or the position is wrong!\n";
        return;
    }
    int current = L->count;
    while (current != p) {
        L->theArray[current] = L->theArray[current - 1];
        current--;
    }
    L->theArray[current] = e;
    L->count++;
}

void listDelete(List L, Position p) {
    if (L == nullptr) return;
    if (p >= L->count || p < 0 || L->count == 0) {
        cout << "The List is empty or the position is wrong!\n";
        return;
    }
    int current = p;
    while (current != L->count - 1) {
        L->theArray[current] = L->theArray[current + 1];
        current++;
    }
    L->count--;
}

void listDisplay(List L) {
    if (L == nullptr) return;
    for (int i = 0; i < L->count; i++) {
        cout << i + 1 << "\tid:" << L->theArray[i].id << "\tname:" << L->theArray[i].name << "\n";
    }
}

void freeList(List &L) {
    if (L != nullptr) {
        delete[] L->theArray;
        delete L;
        L = nullptr;
    }
}

int main() {
	fast()
    List L = createList(10);
    ElementType e1 = {100, "Nguyen Van A"};
    ElementType e2 = {101, "Nguyen Van B"};
    ElementType e3 = {102, "Nguyen Van C"};
    ElementType e4 = {103, "Nguyen Van D"};

    listInsert(L, e1, 0);
    listInsert(L, e2, 1);
    listInsert(L, e3, 2);
    listInsert(L, e4, 3);
    listDisplay(L);

    listDelete(L, 2);
    cout << "The List after deleting:\n";
    listDisplay(L);

    freeList(L);
    return 0;
}
