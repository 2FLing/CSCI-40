#include<iostream>
using namespace std;
struct node
{
	char letter;
	node* next;
};
int main()
{
	node* n=new node;
	node* head=new node;
	node* tail=new node;
	char a = 'A';
	int index;
	head = n;
	tail = n;
	for (index = 0; index <= 25; index++)
	{
		n->letter = a;
		a++;
		n = new node;
		tail->next = n;
		tail = tail->next;
	}
	n->next = NULL;
	for (head; head->next != NULL; head=head->next)
		cout << head->letter << endl;
}
