#include <iostream>
#include "list.h"

ll::ll()
{
	//initialise empty linked list
	head=NULL;
}

bool ll::is_element_exist(int position)
{
	node *pres;
	int count;

	pres = head;
	count =0;
	
	//count no of elems in list
	while(pres!=NULL)
	{
		count++;
		pres = pres->next;
	}
	//if pos out of scope return false
	if(position > count)
		return 0;
	else
		return 1;
}

int ll::get_element(int position)
{
	node *pres;

	pres = head;
	//iterate the list 'pos-1' times to get to node at 'pos' postition
	for(int i=1;i<position;i++)
		pres = pres->next;

	//return the number in the node
	return(pres->number);
}

void ll::insert_element(int element)
{
	//pres: check for null
	//prev: keep the past node
	//now node: node created
	node *pres,*prev,*new_node;

	//create node and update
	new_node = new node[1];
	new_node->number = element;
	new_node->next = NULL;
	pres = head;
	if(pres == NULL) // insert beginning
	{
		head = new_node;
	}
	else
	{
		//iterate to last node using prev
		while((pres!=NULL))
		{
			prev =pres;
			pres=pres->next;
		}
		//insert at end
		prev->next = new_node;
	}
}

void ll::delete_element(int position)
{
	node *pres,*prev;

	pres = head;
	if(position == 1) // delete first node
	{
		//update new head
		head = pres->next;
		delete pres;
	}
	else
	{
		//iterate till the node
		for(int i=1;i<position;i++)
		{
			prev = pres;
			pres = pres->next;
		}
		//update pointers
		prev->next = pres->next;
		//delete the node
		delete pres;
	}
}
void ll::display_elements()
{
	node *pres;
	pres = head;
	//print all elements from head till null
	while(pres!=NULL)
	{
		printf("%d\n",pres->number);
		pres = pres->next;
	}
}
/*
void delete_element(ll **list)
{
	ll *pres,*prev;
	int count_of_nodes,position;

	printf("enter the position to delete the element:");
	scanf("%d",&position);

	pres = *list;
	count_of_nodes = 1;
	if(position == count_of_nodes) // delete first node
	{
		*list=pres->next;
		delete pres;
	}
	else
	{
		while((pres!=NULL)&&(count_of_nodes<position))
		{
			prev =pres;
			pres=pres->next;
			count_of_nodes++;
		}
		if(pres!=NULL) // delete in middle
		{
			prev->next = pres->next;
			delete pres;
		}
	}
}

void remove_duplicates(ll **list)
{
	ll *reference,*scanner,*prev;

	reference = *list;
	if(reference != NULL)
	{
//		while(reference->next !=NULL)
		do
		{
//printf("ref element = %d\n",reference->number);
			if(reference->next==NULL)
				break;
			prev = reference;
			scanner = reference->next;
			do
			{
				if(reference->number == scanner->number)
				{
					prev->next = scanner->next;
					delete scanner;
					scanner = prev->next;
				}
				else
				{
					prev = prev->next;
					scanner = prev->next;
				}
			}while(scanner!=NULL);
			reference = reference->next;
		}while(reference!=NULL);
	}
	else
		printf("list does not have elements\n");
}
*/
