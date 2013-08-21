#include <iostream>
#include "list.h"

void myarray::init(int n)
{
	no_of_elements = n;
	a = new int[no_of_elements];
	no_of_elements = 0;
}

bool myarray::is_element_exist(int position)
{
	if(position > no_of_elements)
		return 0;
	else
		return 1;
}

int myarray::get_element(int position)
{
	return(a[position-1]);
}

void myarray::insert_element(int element)
{
	a[no_of_elements++] = element;
}

void myarray::delete_element(int position)
{
	for(int i=position-1;i<no_of_elements;i++)
		a[i] = a[i+1];
	no_of_elements--;
}

void myarray::display_elements()
{
	for(int i=0;i<no_of_elements;i++)
		printf("%d\n",a[i]);
}
/*
int remove_duplicates(int *list,int n)
{
	int scanner,reference;
	int orig_length,pres_length;

	reference = 0;
	orig_length = pres_length = n;
	if(n!=0)
	{
		for(int i=reference;i<pres_length-1;i++)
		{
			scanner = i+1;
			do
			{
				if(list[i] == list[scanner])
				{
					for(int k=scanner;k<pres_length-1;k++)
						list[k] = list[k+1];
					pres_length--;
				}
				else
					scanner++;
			}while(scanner<pres_length);
		}
	}
	else
		printf("list does not have elements\n");
	return pres_length;
}
*/
