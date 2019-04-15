//MingkuanPang
//The program can create a linked list of 26 nodes, and then
//fill the list with the letters of the
//alphabet, and then it will print the contents of the
//linked list.
#include<iostream>
using namespace std;
struct Node
{
	char letter;
	Node* next;
};
int main()
{
	int index,index2,index3;
	char letters = 'a';
	Node *data=new Node;
	Node* head =new Node;
	Node* head2 = new Node;
	head=data;
	head2= data;
	for (index = 1; index <= 26; index++)
	{
		Node *new_list = new Node;
		new_list->next =NULL;
		data->next = new_list;
		data = new_list;
	}
	for (index2 = 1; index2 <= 26; index2++)
	{
		head2->letter = letters;
		letters++;
		head2 = head2->next;
	}
	for (head; head->next!= NULL; head = head->next)
	{
		cout << head->letter <<" ";
	}
	return 0;
}