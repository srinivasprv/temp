#include <iostream>
#include "list.h"

void ll::init(int n)
{
	head=NULL;
}

bool ll::is_element_exist(int position)
{
	node *pres;
	int count;

	pres = head;
	count =0;
	while(pres!=NULL)
	{
		count++;
		pres = pres->next;
	}
	if(position > count)
		return 0;
	else
		return 1;
}

int ll::get_element(int position)
{
	node *pres;

	pres = head;
	for(int i=1;i<position;i++)
		pres = pres->next;

	return(pres->number);
}
void ll::insert_element(int element)
{
	
	node *pres,*prev,*new_node;

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
		while((pres!=NULL))
		{
			prev =pres;
			pres=pres->next;
		}
		prev->next = new_node;
	}
}

void ll::delete_element(int position)
{
	node *pres,*prev;

	pres = head;
	if(position == 1) // delete first node
	{
		head = pres->next;
		delete pres;
	}
	else
	{
		for(int i=1;i<position;i++)
		{
			prev = pres;
			pres = pres->next;
		}
		prev->next = pres->next;
		delete pres;
	}
}
void ll::display_elements()
{
	node *pres;
	pres = head;
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
