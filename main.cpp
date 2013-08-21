#include <iostream>
#include "list.h"


void remove_duplicates(list **myobj);
int main(int argc,char *argv[])
{
	FILE *fp=NULL;
	int temp,r;
	int no_of_elements;
	list *myobj;

	if(argc !=3)
	{
		printf("Usage: <exe> <i/p file> <o/p file>\n");
		exit(0);
	}

	printf("please enter for data type 1(array) 2(linkedlist):");
	scanf("%d",&temp);

	if((temp!=1)&&(temp!=2))
	{
		printf("wrong option entered\n Exiting..\n");
		exit(0);
	}
	if((fp= fopen(argv[1],"r"))==NULL)
	{
		printf("cannot open file %s\nExiting..\n",argv[1]);
		exit(0);
	}

	no_of_elements = 0;
	while((r=fscanf(fp,"%d ",&temp))!=EOF)
	{
		no_of_elements++;
	}
	if(temp == 1)
	{
		myobj = new myarray();
		myobj->init(no_of_elements);
	}
	else if(temp == 2)
	{
		myobj = new ll();
		myobj->init(no_of_elements);
	}
	fseek(fp,0L,SEEK_SET);
	for(int i=0;i<no_of_elements;i++)
	{
		fscanf(fp,"%d ",&temp);
		myobj->insert_element(temp);
	}
	fclose(fp);
//	myobj->display_elements();
//printf("\n\n\n printed firsttime\n");
	remove_duplicates(&myobj);
	myobj->display_elements();
//	myobj->write_output(argv[2]);
}


void remove_duplicates(list **pres)
{
	list *myobj;
	int ref_pos,scan_pos,ref_num,scan_num;

	myobj = *pres;

	ref_pos = 1;
	while(myobj->is_element_exist(ref_pos))
	{
		ref_num = myobj->get_element(ref_pos);
//printf("ref pos = %d ref num = %d\n",ref_pos,ref_num);
		scan_pos = ref_pos + 1;
		while(myobj->is_element_exist(scan_pos))
		{
			scan_num = myobj->get_element(scan_pos);
//printf("scan pos = %d scan num = %d\n",scan_pos,scan_num);
			if(ref_num == scan_num)
			{
//printf("deleting %d scan pos\n",scan_pos);
				myobj->delete_element(scan_pos);
			}
			else
				scan_pos++;
		}
		ref_pos++;
	}
	if((ref_pos == 1)&& (scan_pos == 0))
		printf("Sorry there are no elements\n");
}

/*
int main()
{
	ll *head=NULL;
	int *a,no_of_elements;

	printf("enter the no of elements in array:");
	scanf("%d",&no_of_elements);
	a = new int[no_of_elements];
	for(int i=0;i<no_of_elements;i++)
	{
		printf("enter the %d element:",i+1);
		scanf("%d",a+i);
	}
*/
/*
//printf("before create\n");
	head = create_list();
//printf("after create and before display\n");
//	insert_element(&head);
	display_list(head);
//printf("after disp and before rd\n");
//	delete_element(&head);
//	display_list(head);
	remove_duplicates(&head);
//printf("after rd and befor display\n");
	display_list(head);
//printf("after display\n");*/
//	no_of_elements = remove_duplicates(a,no_of_elements);
/*	for(int i=0;i<no_of_elements;i++)
		printf("%d\n",a[i]);
}*/
