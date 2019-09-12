/*
 ============================================================================
 Name        : main.c
 Author      : Ahmed ElDakhly
 Date        : 11/9/2019
 Description : Linked List Exercises
 ============================================================================
 */

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "linked.h"
#include "stdio.h"
#include "stdlib.h"
/*******************************************************************************
 *                       	Main Function		                               *
 *******************************************************************************/
int main(void)
{
	setvbuf(stdout, NULL, _IONBF,0);
	setvbuf(stderr, NULL, _IONBF, 0);
	node** LinkedList=Create_List();
	uint32 Data;
	uint32 Position;
	uint32 Choice;

	while(1)
	{
		printf("Please Select One of these choices\n");
		printf("1 for insert to list\n2 for delete List\n3 for delete node\n4 for print list\n");
		printf("5 for search in list\n6 for show linked list length\n7 for reverse Linked List\n8 to exit\n");
		scanf("%d",&Choice);
		switch(Choice)
		{
		case 1:


			printf("Please enter Data that you want to insert in Linked List\n");
			scanf(" %d",&Data);
			printf("Please enter Position that you want for inserted Data Linked List\n");
			scanf(" %d",&Position);
			InsertToList(LinkedList,Data,Position);
			break;
		case 2:
			DeleteList(LinkedList);
			break;
		case 3:
			printf("Please enter Position that you want for inserted Data Linked List\n");
			scanf(" %d",&Position);
			DeleteNode(LinkedList,Position);
			break;
		case 4:
			printList(LinkedList);
			break;
		case 5:
			printf("Please enter Data that you want to Search about it in Linked List\n");
			scanf(" %d",&Data);
			SearchForNode(LinkedList,Data);
			break;
		case 6:
			ListSize(LinkedList);
			break;
		case 7:
			ListReverse(LinkedList);
			break;
		case 8:
			return 0;
			break;

		}
		printf("__________________________________________________________________________\n");

	}
}
