/*
 ============================================================================
 Name        : linked.c
 Author      : Ahmed ElDakhly
 Date        : 11/9/2019
 Description : Linked List Exercises
 ============================================================================
 */

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "linked.h"
/*******************************************************************************
 *                      Global Variables  		                               *
 *******************************************************************************/
static uint8 MaxPosition=0;
/*******************************************************************************
 *                      Functions Definitions                                   *
 *******************************************************************************/

/*******************************************************************************
 * Function Name:	Create_List
 *
 * Description: 	Create Linked List
 *
 * Inputs:			NULL
 *
 * Return:			pointer to pointer to struct
 *******************************************************************************/
node** Create_List(void)
{
	node ** head=(node **) malloc(sizeof(node*));
	*head=NULL;

	return head;
}

/*******************************************************************************
 * Function Name:	InsertToHead
 *
 * Description: 	Insert Node to Head
 *
 * Inputs:			pointer to pointer to pointer to struct
 * 					uint32
 * 					uint8
 *
 * Return:		    Status
 *******************************************************************************/
Status InsertToList(node ** List,uint32 Data,uint8 Position)
{
	node* ptr=*List;
	Status ReturnVal;
	node * InsertNode = (node *) malloc(sizeof(node));
	InsertNode->data=Data;
	if(((ptr)==NULL))
	{
		if(Position==0)
		{
			(*List)=InsertNode;
			InsertNode->next=NULL;
			ReturnVal=INSERT;
			MaxPosition++;
		}
		else
		{
			ReturnVal=NOT_FOUND_POSITION;
		}
	}
	else
	{
		if(MaxPosition>=Position)
		{
			if(Position==0)
			{
				InsertNode->next=(*List);
				(*List)=InsertNode;
			}
			else if((Position==1)&&(MaxPosition!=2))
			{
				InsertNode->next=(*List)->next;
				(*List)->next=InsertNode;
			}
			else
			{
				for(uint8 i=1;i!=Position;i++)
				{
					if((ptr->next)!=NULL)
					{
						ptr=ptr->next;
					}
				}
				InsertNode->next=ptr->next;
				ptr->next=InsertNode;
			}
			MaxPosition++;
			ReturnVal=INSERT;
		}
		else
		{
			ReturnVal=NOT_FOUND_POSITION;
		}
	}
	return ReturnVal;
}

/*******************************************************************************
 * Function Name:	printList
 *
 * Description: 	Print data in all members of Linked List
 *
 * Inputs:			pointer to pointer to pointer to struct
 *
 * Return:		    NULL
 *******************************************************************************/
void printList(node ** list)
{
	node *ptr = *list;
	printf("[head] =>");

	//start looping from the head until the last node
	while(ptr != NULL)
	{
		printf(" %d =>",ptr->data);
		ptr = ptr->next;
	}

	printf(" [null]\n");
}

/*******************************************************************************
 * Function Name:	DeleteList
 *
 * Description: 	Delete all of Linked List Nodes
 *
 * Inputs:			pointer to pointer to pointer to struct
 *
 * Return:		    NULL
 *******************************************************************************/
void DeleteList(node ** list)
{
	node *DeleteNode=NULL;
	node *Current =*list;

	/*Delete Nodes from the head until the last node*/
	while(Current != NULL)
	{
		DeleteNode=Current;
		Current=Current->next;
		free(DeleteNode);
	}

	printf("List was Deleted\n");
}

/*******************************************************************************
 * Function Name:	DeleteNode
 *
 * Description: 	Delete specific node from Linked List
 *
 * Inputs:			pointer to pointer to pointer to struct
 * 					uint8
 *
 * Return:		    NULL
 *******************************************************************************/
void DeleteNode(node ** list,uint8 Position)
{
	node *DeleteNode;
	node *PreNode=*list;
	if((Position==0)&&(MaxPosition>=1))
	{
		DeleteNode=*list;
		(*list)=(*list)->next;
		free(DeleteNode);
	}
	/*Delete Nodes from the head until the last node*/
	else if((MaxPosition>=Position)&&(MaxPosition!=0))
	{
		for(uint8 i=0;i!=(Position-1);i++)
		{
			PreNode=PreNode->next;
		}
		DeleteNode=PreNode->next;
		PreNode->next=PreNode->next->next;
		free(DeleteNode);
		MaxPosition--;
		printf("Node was deleted\n");
	}
	else
	{
		printf("This Position didn't exist\n");
	}
}

/*******************************************************************************
 * Function Name:	SearchForNode
 *
 * Description: 	Search for Node by its Data
 *
 * Inputs:			pointer to pointer to pointer to struct
 * 					uint32
 *
 * Return:		    NULL
 *******************************************************************************/
void SearchForNode(node ** list,uint32 Data)
{
	uint32 counter=0;
	uint32 flag=0;
	node *SearchNode=*list;
	if(((*list)==NULL))
	{
		printf("This list is empty\n");
	}
	while((SearchNode)!=NULL)
	{
		if((SearchNode->data)!=Data)
		{
			SearchNode=SearchNode->next;
			counter++;
		}
		else
		{
			printf("This data %d exist in node number %d\n",Data,counter);
			flag=1;
			SearchNode=SearchNode->next;
			counter++;
		}
	}
	if(flag==0)
	{
		printf("This data not exist in this list\n");
	}
}

/*******************************************************************************
 * Function Name:	ListSize
 *
 * Description: 	Show Linked List Size
 *
 * Inputs:			pointer to pointer to pointer to struct
 *
 * Return:		    NULL
 *******************************************************************************/
void ListSize(node ** list)
{
	uint8 counter=0;
	node *SearchNode=*list;
	if((*list)==NULL)
	{
		printf("This list is empty\n");
	}
	while((SearchNode->next)!=NULL)
	{
		SearchNode=SearchNode->next;
		counter++;
	}
	counter++;
	printf("This Linked List Size is %d\n",counter);
}

/*******************************************************************************
 * Function Name:	ListReverse
 *
 * Description: 	Reverse Linked List Nodes
 *
 * Inputs:			pointer to pointer to pointer to struct
 *
 * Return:		    NULL
 *******************************************************************************/
void ListReverse(node ** list)
{
	node* preTemp=NULL;
	node* current=(*list);
	node* postTemp=NULL;
	while(current!=NULL)
	{
		postTemp=current->next;
		current->next=preTemp;
		preTemp=current;
		current=postTemp;
	}
	(*list)=preTemp;
}
