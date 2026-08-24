#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz size()
#define ll long long
#define faster() ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

struct ElementType{
	int id;
	string name;
};

struct Node{
	ElementType e;
	Node* next;
	Node* prev;	
};

typedef Node* List;
typedef Node* Position;

List createList() {
    List headerNode = new Node();
    headerNode->next = nullptr;
    headerNode->prev = nullptr;
    return headerNode;
}

void insert(ElementType e, Position p){
	if(p == nullptr) return;
	Position newItem = new Node();
	newItem->e = e;
	newItem->next = p->next;
	newItem->prev = p;
	
	if (p->next != nullptr) {
        p->next->prev = newItem;
    }
    p->next = newItem;
}

void deleteNode(Position p){
	if(p != nullptr){
		if(p->next != nullptr){
			p->next->prev = p->prev;
		}
		if(p->prev != nullptr){
			p->prev->next = p->next;
		}
		delete p;
	}
}

void display(List L) {
    if (L == nullptr) return;
    Position p = L->next;
    while (p != nullptr) {
        cout << "id: " << p->e.id << " - name:" << p->e.name << "\n";
        p = p->next;
    }
}

Position find(List L, int id) {
    if (L == nullptr) return nullptr;
    Position p = L->next;
    while (p != nullptr && p->e.id != id) {
        p = p->next;
    }
    return p;
}

void freeList(List &L) {
    Position current = L;
    while (current != nullptr) {
        Position temp = current;
        current = current->next;
        delete temp;
    }
    L = nullptr;
}

int main() {
    List stdList = createList();
    ElementType e1 = {1, "Nguyen Van A"};
    ElementType e2 = {2, "Nguyen Van B"};
    ElementType e3 = {3, "Nguyen Van C"};
    ElementType e4 = {4, "Nguyen Van D"};

    insert(e1, stdList);
    insert(e2, stdList);
    insert(e3, stdList);
    insert(e4, stdList);

    cout << "The list is:\n";
    display(stdList);

    Position item = find(stdList, 2);
    deleteNode(item);

    cout << "The list is:\n";
    display(stdList);

    freeList(stdList);
    return 0;
}
