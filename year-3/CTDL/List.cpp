#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz size()
#define ll long long
#define faster() ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

//// Array Implementation
//
//typedef int ElementType;
//typedef int Position;
//
//const int MAX_SIZE = 100;
//
//struct ListInfo{
//	ElementType *theArray; // = malloc(MAX_SIZE*sizeof(ElementType))
//	int count; // So luong phan tu hien co
//	int maxsize; // = MAX_SIZE
//};
//typedef ListInfo* List;
//
////Empty list has allocated array and count = 0
//// Create an empty list
//List MakeEmpty(){
//	List L = new ListInfo;
//	
//	L->theArray = new ElementType[MAX_SIZE];
//	L->count = 0;
//	L->maxsize = MAX_SIZE;
//	
//	return L;
//}
//
//// Insert element e at position p
//void Insert(List L, ElementType e, Position p){
//	if(L == NULL) exit(1);
//	if(p < 0 || p > L->count) exit(1);
//	if(L->count == L->maxsize) exit(1);
//	
//	Position current = L->count;
//	
//	while(current != p){
//		L->theArray[current] = L->theArray[current - 1];
//		current--;
//	}
//	
//	L->theArray[p] = e;
//	L->count++;
//}
//
//void Delete(List L, Position p) {
//    if (L == nullptr)
//        return;
//    if (p < 0 || p >= L->count)
//        return;
//    Position current = p;
//    while (current < L->count - 1) {
//        L->theArray[current] = L->theArray[current + 1];
//        current++;
//    }
//    L->count--;
//}


// Pointer Impelemtation : Linked List

typedef int ElementType;

struct Node{
	ElementType Value;
	Node* next;
};
typedef Node* List;
typedef Node* Position;

// Tao 1 node moi tu thong tin (tuy bai toan) da co
List taoNode(int Value){
	List tmp = new Node();
	tmp->Value = Value;
	tmp->next = NULL;
	return tmp;
}

// Insert E sau node P
void Insert(List &head, ElementType E, Position P){
	List newItem = taoNode(E);
	
	if(head == NULL || P == NULL){
		newItem->next = head;
		head = newItem;
	}
	else{
		newItem->next = P->next;
		P->next = newItem;
	}
}

void Delete(List &head, Position P){
	if(head == NULL || P == NULL){
		return;
	}
	
	if(head == P){
		head = head->next;
		delete P;
		return;
	}
	
	Position prev = head;
	while(prev->next != NULL && prev->next != P){
		prev = prev->next;
	}
	if(prev->next == P){
		prev->next = P->next;
		delete P;
	}
}

void printList(List head){
	List p = head;
	while(p != NULL){
		cout << p->Value << " ";
		p = p->next;
	}
}

//// Neu dung header Node
//List MakeEmpty() {
//    List L = new Node(); // Header Node 
//    L->next = NULL;
//    return L;
//}
//
//void Insert(List L, ElementType E, Position P) {
//    if (P == NULL) return;
//
//    Position newItem = taoNode(E);
//    newItem->next = P->next;
//    P->next = newItem;
//}
//
//void Delete(List L, Position P) {
//    if (P == NULL || L == NULL) return;
//
//    Position prev = L;
//    while (prev->next != NULL && prev->next != P) {
//        prev = prev->next;
//    }
//
//    if (prev->next == P) {
//        prev->next = P->next;
//        delete P;
//    }
//}
//
//void printList(List L) {
//    Position p = L->next;
//    while (p != NULL) {
//        cout << p->Value << " ";
//        p = p->next;
//    }
//    cout << endl;
//}

//// Doubly Linked List
//typedef int ElementType;
//
//struct Node {
//    ElementType Value;
//    struct Node *prev; 
//    struct Node *next; 
//};
//
//typedef struct Node *Position;
//typedef struct Node *List;
//
//
//void Insert(ElementType X, Position P) {
//    Position NewNode = new Node();
//    NewNode->Value = X;
//
//    NewNode->next = P->next;
//    NewNode->prev = P;
//
//    if (P->next != NULL) {
//        P->next->prev = NewNode;
//    }
//
//    P->next = NewNode;
//}
//
//void Delete(Position P) {
//    if (P == NULL) return;
//
//    if (P->prev != NULL) {
//        P->prev->next = P->next;
//    }
//    
//    if (P->next != NULL) {
//        P->next->prev = P->prev;
//    }
//
//    delete P;
//}


// Polunomial Implementation



int main(){
	faster()
	List head = NULL;
	
	Insert(head, 10, NULL);
	Insert(head, 20, head);
	Insert(head, 30, head->next);
	Insert(head, 40, head->next->next);
	
	printList(head);
	cout << endl;
	
//	Position P = head->next;
//
//    Insert(head, 25, P);
//
//    cout << "Sau khi chen 25 sau 20: ";
//    printList(head);
    cout << endl;
    cout << "Sau khi xoa: ";
    
    Delete(head, head->next);
    printList(head);

    return 0;
}
