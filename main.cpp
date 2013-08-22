#include <iostream>
#include "list.h"

//remove duplicates prototype
void remove_duplicates(list **myobj);

//write output prototype
void write_output(list *l, char *filename);


int main(int argc,char *argv[])
{
	FILE *fp=NULL;
	int temp,r,input;
	int no_of_elements;
	list *myobj;

	//usage
	if(argc !=3)
	{
		printf("Usage: <exe> <i/p file> <o/p file>\n");
		exit(0);
	}

	//data structure to use
	printf("please enter for data type 1(array) 2(linkedlist):");
	scanf("%d",&input);

	//check type
	if((input!=1)&&(input!=2))
	{
		printf("wrong option entered\n Exiting..\n");
		exit(0);
	}
	
	//open input file if file exists
	if((fp= fopen(argv[1],"r"))==NULL)
	{
		printf("cannot open file %s\nExiting..\n",argv[1]);
		exit(0);
	}

	no_of_elements = 0;
	//count no of elements
	while((r=fscanf(fp,"%d ",&temp))!=EOF)
	{
		no_of_elements++;
	}
	
	//create object according to option entered above
	if(input == 1)
	{
		myobj = new myarray(no_of_elements);
	}
	else if(input == 2)
	{
		myobj = new ll();
	}
	
	//read and insert numbers into list
	fseek(fp,0L,SEEK_SET);
	for(int i=0;i<no_of_elements;i++)
	{
		fscanf(fp,"%d",&temp);
		myobj->insert_element(temp);
	}
	fclose(fp);

	//remove duplicates
	remove_duplicates(&myobj);
	//myobj->display_elements();
	
	//write output to the file
	write_output(myobj, argv[2]);
	
	return 0;
}


void remove_duplicates(list **pres)
{
	list *myobj;
	//ref: number to compare with
	//scan: number being compared
	int ref_pos,scan_pos,ref_num,scan_num;

	myobj = *pres;

	ref_pos = 1;
	while(myobj->is_element_exist(ref_pos))
	{
		//read the reference number
		ref_num = myobj->get_element(ref_pos);
		
		scan_pos = ref_pos + 1;
		//remove duplicate values of ref found later
		while(myobj->is_element_exist(scan_pos))
		{
			scan_num = myobj->get_element(scan_pos);
			//if duplicate found
			if(ref_num == scan_num)
			{
				//delete from list
				myobj->delete_element(scan_pos);
			}
			else
				scan_pos++;//continue to next elem
		}
		ref_pos++;
	}
	
	//if list is empty
	if((ref_pos == 1)&& (scan_pos == 0))
		printf("Sorry there are no elements\n");
}

void write_output(list *l, char *filename)
{
	FILE *fp;
	list *obj = l;
	int position = 1;
	int number = 0;//temp int to write to file

	//open file in write mode
	if((fp= fopen(filename,"w"))==NULL)
	{
		printf("Cannot create output file %s\n Exiting....\n",filename);
		exit(0);
	}
	
	
	//iterate over list
	while(obj->is_element_exist(position))
	{
		//read elem and write to file
		number = obj->get_element(position);
		fprintf(fp,"%d ",number);
		position++;
	}
	
	//if no elements
	if(position == 1)
		fprintf(fp,"No Elements Exist in input\n");
	fclose(fp);
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
