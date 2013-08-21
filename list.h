#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <cstdio>
#include <cstdlib>
class list
{
	public:
		virtual void init(int number)=0;
		virtual bool is_element_exist(int position)=0;
		virtual int get_element(int position)=0;
		virtual void insert_element(int number)=0;
		virtual void delete_element(int position)=0;
		virtual void display_elements()=0;
//		virtual void write_output(char *filename)=0;
};
class myarray:public list
{
	public:
//		myarray(int ne);
		int *a;
		int no_of_elements;
		void init(int number);
		bool is_element_exist(int position);
		int get_element(int position);
		void insert_element(int number);
		void delete_element(int position);
		void display_elements();
//		void write_output(char *filename);
};
class node
{
	public:
		int number;
		node *next;
};
class ll:public list
{
	public:
//		ll(int ne);
		node *head;
		void init(int number);
		bool is_element_exist(int position);
		int get_element(int position);
		void insert_element(int number);
		void delete_element(int position);
		void display_elements();
//		void write_output(char *filename);
};
/*
void display_list(ll *list);
//ll* create_list();
void insert_element(ll **list);
void delete_element(ll **list);
void remove_duplicates(ll **list);
int remove_duplicates(int *list,int n);*/
#endif
