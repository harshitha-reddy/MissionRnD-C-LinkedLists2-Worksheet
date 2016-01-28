/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>
struct node{
	int num;
	struct node *next;
};


struct node * insertAtEveryKthNode(struct node *head, int K) {
	if ((head == NULL) || (K<1))
		return NULL;

	struct node *p, *q, *temp;
	p = head;
	int count = 0;
	while (p != NULL){
		count++;
		q = p;
		p = p->next;
		if (count %K == 0){
			struct node* temp = (struct node*) malloc(sizeof(struct node));
			temp->num = K;
			q->next = temp;
			temp->next = p;
		}
	}
	return head;

}
