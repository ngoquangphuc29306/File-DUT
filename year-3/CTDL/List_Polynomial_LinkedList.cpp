#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz size()
#define ll long long
#define faster() ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

struct Node {
    int coef;
    int expo;
    Node* next;
};

typedef Node* POLYNOMIAL;
typedef Node* Position;

POLYNOMIAL create_poly() {
    POLYNOMIAL header_node = new Node();
    header_node->next = nullptr;
    return header_node;
}

Position create_node(int coef, int expo){
	Position new_node = new Node();
	new_node->next = nullptr;
	new_node->coef = coef;
	new_node->expo = expo;
	return new_node;
}

void add_node(POLYNOMIAL poly, int coef, int expo){
	if(coef == 0) return;
	Position current = poly;
	while(current->next != nullptr && current->next->expo > expo){
		current = current->next;
	}
	if(current->next != nullptr && current->next->expo == expo){
		current->next->coef += coef;
	}
	else{
		Position new_node = create_node(coef, expo);
		new_node->next = current->next;
		current->next = new_node;
	}
}

void show_poly(POLYNOMIAL poly) {
    Position p = poly->next;
    while (p != nullptr) {
        cout << p->coef;
        if(p->expo != 0) cout << "x^" << p->expo;
        if(p->next != nullptr) cout << " + ";
        p = p->next;
    }
    cout << "\n";
}

void add_poly(POLYNOMIAL A, POLYNOMIAL B, POLYNOMIAL C){
	Position pA = A->next;
	while(pA != nullptr){
		add_node(C, pA->coef, pA->expo);
		pA = pA->next;
	}
	Position pB = B->next;
	while(pB != nullptr){
		add_node(C, pB->coef, pB->expo);
		pB = pB->next;
	}
}

void mult_poly(POLYNOMIAL A, POLYNOMIAL B, POLYNOMIAL MULT){
	Position pA = A->next;
	while(pA != nullptr){
		Position pB = B->next;
		while(pB != nullptr){
			int coef = pA->coef * pB->coef;
			int expo = pA->expo + pB->expo;
			add_node(MULT, coef, expo);
			pB = pB->next;
		}
		pA = pA->next;
	}
}

void free_poly(POLYNOMIAL &poly){
	Position current = poly;
	while(current != nullptr){
		Position tmp = current;
		current = current->next;
		delete tmp;
	}
	poly = nullptr;
}

int main() {
    POLYNOMIAL A = create_poly();
    POLYNOMIAL B = create_poly();
    POLYNOMIAL C = create_poly();
    POLYNOMIAL MULT = create_poly();

    // A = 4x^3 + 5x - 8
    add_node(A, 4, 3);
    add_node(A, -8, 0);
    add_node(A, 5, 1);

    cout << "A: ";
    show_poly(A);

    // B = 5x^3 + 4x^2 + 3
    add_node(B, 5, 3);
    add_node(B, 4, 2);
    add_node(B, 3, 0);

    cout << "B: ";
    show_poly(B);

    add_poly(A, B, C);
    cout << "C (A+B): ";
    show_poly(C);

    mult_poly(A, B, MULT);
    cout << "MULT (A*B): ";
    show_poly(MULT);

    free_poly(A);
    free_poly(B);
    free_poly(C);
    free_poly(MULT);
    return 0;
}