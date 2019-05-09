//MingkuanPang
//The program can create a linked list of 26 nodes, and then
//fill the list with the letters of the
//alphabet, and then it will print the contents of the
//linked list.
//MingkuanPang
//This program can caculate factorials
// n! = (n-1)! x n and the greatest common factor
//of two numbers.
#include<iostream>
#include<limits.h>
using namespace std;
struct node
{
	char data;
	node* next;
};
int main()
{
	node* head;
	node* n;
	node* tail;
	n = new node;
	head = n;
	tail = n;
	int index;
	char a = 'A';
	for (index = 0; index <= 25; index++)
	{
		n->data = a;
		a++;
		n = new node;
		tail->next = n;
		tail = t->next;
	}
	n->next = NULL;
	tail = head;
	while (t->next != NULL)
	{
		cout << t->data << endl;
		t = t->next;
	}
	return 0;
}
