/*
 ============================================================================
 Name        : linked.h
 Author      : Ahmed ElDakhly
 Date        : 11/9/2019
 Description : Linked List Exercises
 ============================================================================
 */


#ifndef LINKED_H_
#define LINKED_H_

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "std_types.h"

/*******************************************************************************
 *                         Linked List Structures                              *
 *******************************************************************************/
typedef struct ST_Node
{
	uint32 data;
	struct ST_Node * next;
}node;

/*******************************************************************************
 *                         Status Enum                              *
 *******************************************************************************/
typedef enum
{
	INSERT,
	NOT_FOUND_POSITION
}Status;

/*******************************************************************************
 *                      Functions Prototypes                                   *
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
node** Create_List(void);

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
Status InsertToList(node ** List,uint32 Data,uint8 Position);

/*******************************************************************************
 * Function Name:	printList
 *
 * Description: 	Print data in all members of Linked List
 *
 * Inputs:			pointer to pointer to pointer to struct
 *
 * Return:		    NULL
 *******************************************************************************/
void printList(node ** list);

/*******************************************************************************
 * Function Name:	DeleteList
 *
 * Description: 	Delete all of Linked List Nodes
 *
 * Inputs:			pointer to pointer to pointer to struct
 *
 * Return:		    NULL
 *******************************************************************************/
void DeleteList(node ** list);

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
void DeleteNode(node ** list,uint8 Position);

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
void SearchForNode(node ** list,uint32 Data);

/*******************************************************************************
 * Function Name:	ListSize
 *
 * Description: 	Show Linked List Size
 *
 * Inputs:			pointer to pointer to pointer to struct
 *
 * Return:		    NULL
 *******************************************************************************/
void ListSize(node ** list);

/*******************************************************************************
 * Function Name:	ListReverse
 *
 * Description: 	Reverse Linked List Nodes
 *
 * Inputs:			pointer to pointer to pointer to struct
 *
 * Return:		    NULL
 *******************************************************************************/
void ListReverse(node ** list);

#endif /* LINKED_H_ */
