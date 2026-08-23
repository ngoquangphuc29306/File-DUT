#include <stdio.h>
#include <stdlib.h>

struct Symbol {
	char * name;
	long value;
};

struct Node {
	struct Node *next;
	Symbol *element;	
};

int main() {
	Symbol oneSym;
	Symbol twoSym;
	Symbol threeSym;
	
	oneSym.name = "One"; oneSym.value = 1;
	twoSym.name = "Two"; twoSym.value = 2;
	threeSym.name = "Three"; threeSym.value = 3;

	Node *nodeA;
	Node *nodeB;
	Node *nodeC;
	
	nodeA = (Node*)malloc(sizeof(Node));
	nodeB = (Node*)malloc(sizeof(Node));
	nodeC = (Node*)malloc(sizeof(Node));
	
	nodeA->element = &oneSym;
	nodeA->next = nodeB;
	
	nodeB->element = &twoSym;
	nodeB->next = nodeC;
	
	nodeC->element = &threeSym;
	nodeC->next = NULL;
	
	Node *nodeP;
	nodeP = nodeA;
	
	while (nodeP != NULL) {
		printf("%ld	%s\n", nodeP->element->value, nodeP->element->name);
		nodeP = nodeP->next;
	}
	return 0;
}