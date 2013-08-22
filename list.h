#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <cstdio>
#include <cstdlib>

//parent class list
class list
{
	public:
		virtual bool is_element_exist(int position)=0;//check if there is elemnt in pos
		virtual int get_element(int position)=0;//get elem from pos
		virtual void insert_element(int number)=0;//insert no to the end of list
		virtual void delete_element(int position)=0;//delete number in specified pos
		virtual void display_elements()=0;//display list
};

//array class
class myarray:public list
{
	public:
		myarray(int ne);
		int *a;//array
		int no_of_elements;//present number of elements
		bool is_element_exist(int position);
		int get_element(int position);
		void insert_element(int number);
		void delete_element(int position);
		void display_elements();
};

//linked list node class
class node
{
	public:
		int number;
		node *next;
};

//linked list class
class ll:public list
{
	public:
		ll();
		node *head;//poiter to head of the ll
		bool is_element_exist(int position);
		int get_element(int position);
		void insert_element(int number);
		void delete_element(int position);
		void display_elements();
};
#endif
