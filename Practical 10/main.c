#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/**
 * @brief Represents a node in the linked list.
 *
 * This structure contains an integer data and a pointer to the next node in the list.
 */
typedef struct Node
{
  int data;
  struct Node *next;
} Node;

// Pointer to the head of the linked list.
Node *head = NULL;

/**
 * @brief Creates a new node with the specified data.
 *
 * @param data The integer data to be stored in the new node.
 * @return Node* Returns a pointer to the newly created node.
 *
 * @return void and If memory allocation fails, the function prints an error message and exits the program.
 */
Node *createNode(int data)
{
  // Allocate memory for the new node
  Node *newNode = (Node *)malloc(sizeof(Node));

  // Check if memory allocation was successful
  if (!newNode)
  {
    printf("Memory allocation failed.\n");
    exit(1);
  }

  // Initialize the node with the given data and set next to NULL
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

/**
 * @brief Inserts a new node at the beginning of the linked list.
 *
 * @param data The integer data to be stored in the new node.
 *
 * @return void
 */
void insertAtBeginning(int data)
{
  // Create a new node with the specified data
  Node *newNode = createNode(data);

  // Set the new node's next pointer to the current head
  newNode->next = head;

  // Update the head to point to the new node
  head = newNode;
}

/**
 * @brief Inserts a new node at the end of the linked list.
 *
 * @param data The integer data to be stored in the new node.
 *
 * @return void
 */
void insertAtEnd(int data)
{
  // Create a new node with the specified data
  Node *newNode = createNode(data);

  // Check if the list is empty
  if (head == NULL)
  {
    head = newNode;
  }
  else
  {
    // Traverse to the end of the list
    Node *current = head;
    while (current->next != NULL)
    {
      current = current->next;
    }
    // Insert the new node at the end of the list
    current->next = newNode;
  }
}

/**
 * @brief Inserts a new node after a node with the specified data in the linked list.
 *
 * @param afterData The data of the node after which to insert the new node.
 * @param data The integer data to be stored in the new node.
 *
 * @return void and If the node with afterData is not found, the function prints an error message.
 */
void insertAfterNode(int afterData, int data)
{
  // Start from the head of the list
  Node *current = head;

  // Find the node with the specified data
  while (current != NULL && current->data != afterData)
  {
    current = current->next;
  }

  // If the node is found
  if (current != NULL)
  {
    // Create a new node with the specified data
    Node *newNode = createNode(data);

    // Insert the new node after the current node
    newNode->next = current->next;
    current->next = newNode;
  }
  else
  {
    // Node with the specified data not found
    printf("Node with data %d not found in the list.\n", afterData);
  }
}

/**
 * @brief Inserts a new node before a node with the specified data in the linked list.
 *
 * @param beforeData The data of the node before which to insert the new node.
 * @param data The integer data to be stored in the new node.
 *
 * @return void and If the node with beforeData is not found, the function prints an error message.
 */
void insertBeforeNode(int beforeData, int data)
{
  // Check if the list is empty
  if (head == NULL)
  {
    printf("The list is empty.\n");
    return;
  }

  // If the head node is the one before which we are inserting
  if (head->data == beforeData)
  {
    insertAtBeginning(data);
    return;
  }

  // Traverse the list to find the node before the one with beforeData
  Node *current = head;
  Node *previous = NULL;

  while (current != NULL && current->data != beforeData)
  {
    previous = current;
    current = current->next;
  }

  // If the node is found
  if (current != NULL)
  {
    // Create a new node with the specified data
    Node *newNode = createNode(data);

    // Insert the new node before the current node
    newNode->next = current;
    previous->next = newNode;
  }
  else
  {
    // Node with the specified data not found
    printf("Node with data %d not found in the list.\n", beforeData);
  }
}

/**
 * @brief Inserts a new node at a specified position in the linked list.
 *
 * @param position The position at which to insert the new node (1-based index).
 * @param data The integer data to be stored in the new node.
 *
 * @return void and If the position is invalid or out of range, the function prints an error message.
 */
void insertAtPosition(int position, int data)
{
  // Validate the position
  if (position < 1)
  {
    printf("Invalid position.\n");
    return;
  }

  // If position is the beginning of the list
  if (position == 1)
  {
    insertAtBeginning(data);
    return;
  }

  // Create a new node with the specified data
  Node *newNode = createNode(data);

  // Traverse to the specified position
  Node *current = head;
  int currentPosition = 1;

  while (current != NULL && currentPosition < position - 1)
  {
    current = current->next;
    currentPosition++;
  }

  // Check if position is within the list range
  if (current == NULL)
  {
    printf("Position out of range.\n");
    free(newNode);
  }
  else
  {
    // Insert the new node at the specified position
    newNode->next = current->next;
    current->next = newNode;
  }
}

/**
 * @brief Searches for a node with the specified data in the linked list.
 *
 * @param data The data to search for.
 *
 * @return Node* Returns a pointer to the node with the specified data, or NULL if not found.
 */
Node *searchNode(int data)
{
  // Start from the head of the list
  Node *current = head;

  // Traverse the list to find the node with the specified data
  while (current != NULL)
  {
    if (current->data == data)
    {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

/**
 * @brief Deletes the node at the beginning of the linked list.
 *
 * @param void
 *
 * @return void and If the list is empty, it prints a message indicating the list is empty.
 */
void deleteAtBeginning(void)
{
  // Check if the list is empty
  if (head == NULL)
  {
    printf("The list is empty.\n");
    return;
  }

  // Save a reference to the current head node
  Node *temp = head;

  // Update the head pointer to the next node
  head = head->next;

  // Free the memory of the old head node
  free(temp);
}

/**
 * @brief Deletes the node at the end of the linked list.
 *
 * @param void
 *
 * @return void and If the list is empty, it prints a message indicating the list is empty.
 */
void deleteAtEnd(void)
{
  // Check if the list is empty
  if (head == NULL)
  {
    printf("The list is empty.\n");
    return;
  }

  // If there is only one node in the list
  if (head->next == NULL)
  {
    free(head);
    head = NULL;
    return;
  }

  // Traverse to the second-to-last node
  Node *current = head;
  while (current->next->next != NULL)
  {
    current = current->next;
  }

  // Free the memory of the last node
  free(current->next);

  // Set the second-to-last node's next pointer to NULL
  current->next = NULL;
}

/**
 * @brief Deletes the node after a node with the specified data in the linked list.
 *
 * @param afterData The data of the node after which to delete the next node.
 *
 * @return void and If the node with afterData or the next node is not found, the function prints an error message.
 */
void deleteAfterNode(int afterData)
{
  // Start from the head of the list
  Node *current = head;

  // Traverse the list to find the node with the specified data
  while (current != NULL && current->data != afterData)
  {
    current = current->next;
  }

  // Check if the node is found and it has a next node
  if (current == NULL || current->next == NULL)
  {
    printf("Node with data %d not found or no node after it.\n", afterData);
    return;
  }

  // Save a reference to the node to be deleted
  Node *temp = current->next;

  // Update the current node's next pointer to skip the deleted node
  current->next = temp->next;

  // Free the memory of the deleted node
  free(temp);
}

/**
 * @brief Deletes the node before a node with the specified data in the linked list.
 *
 * @param beforeData The data of the node before which to delete the previous node.
 *
 * @return void and If the node with beforeData is not found, or the head is the node beforeData,
 * or the list is empty, the function prints an error message.
 */
void deleteBeforeNode(int beforeData)
{
  // Check if the list is empty
  if (head == NULL)
  {
    printf("The list is empty.\n");
    return;
  }

  // Check if the node to delete is before the head
  if (head->data == beforeData)
  {
    printf("Cannot delete a node before the head of the list.\n");
    return;
  }

  // Traverse the list to find the node before the one with beforeData
  Node *current = head;
  Node *previous = NULL;

  while (current->next != NULL && current->next->data != beforeData)
  {
    previous = current;
    current = current->next;
  }

  // Check if the node is found
  if (current->next != NULL && current->next->data == beforeData)
  {
    // Save a reference to the node to be deleted
    Node *nodeToDelete = current;

    // If there is a node before the one to delete
    if (previous == NULL)
    {
      head = current->next;
    }
    else
    {
      previous->next = current->next;
    }

    // Free the memory of the node to be deleted
    free(nodeToDelete);
  }
  else
  {
    // Node with the specified data not found
    printf("Node with data %d not found in the list.\n", beforeData);
  }
}

/**
 * @brief Deletes a node with the specified data from the linked list.
 *
 * @param data The data of the node to delete.
 *
 * @return void and If the node with data is not found, the function prints an error message.
 */
void deleteParticularNode(int data)
{
  // Check if the list is empty
  if (head == NULL)
  {
    printf("The list is empty.\n");
    return;
  }

  // If the head node is the one to delete
  if (head->data == data)
  {
    deleteAtBeginning();
    return;
  }

  // Traverse the list to find the node with the specified data
  Node *current = head;
  Node *previous = NULL;

  while (current != NULL && current->data != data)
  {
    previous = current;
    current = current->next;
  }

  // Check if the node is found
  if (current == NULL)
  {
    printf("Node with data %d not found in the list.\n", data);
  }
  else
  {
    // Update the previous node's next pointer to skip the deleted node
    previous->next = current->next;

    // Free the memory of the node to be deleted
    free(current);
  }
}

/**
 * @brief Prints the entire linked list.
 *
 * @param void
 *
 * @return void
 */
void printList(void)
{
  // Start from the head of the list
  Node *current = head;

  // Check if the list is empty
  if (current == NULL)
  {
    printf("The list is empty.\n");
  }
  else
  {
    // Print each node's data
    printf("Linked List: ");
    while (current != NULL)
    {
      printf("%d ", current->data);
      current = current->next;
    }
    printf("\n");
  }
}

/**
 * @brief Main function that runs the program, providing a menu-driven interface to interact with the linked list.
 *
 * @param void
 *
 * @return int Returns 0 upon successful execution, or 1 if memory allocation fails.
 */
int main(void)
{
  int choice, data, position, afterData, beforeData;
  Node *node;

  while (1)
  {
    printf("\nMenu:\n");
    printf("1. Insert at the beginning\n");
    printf("2. Insert at the end\n");
    printf("3. Insert after a particular node\n");
    printf("4. Insert before a particular node\n");
    printf("5. Insert at a specific position\n");
    printf("6. Search for a particular node\n");
    printf("7. Return a particular node\n");
    printf("8. Delete at the beginning\n");
    printf("9. Delete at the end\n");
    printf("10. Delete after a particular node\n");
    printf("11. Delete before a particular node\n");
    printf("12. Delete a particular node\n");
    printf("13. Print list\n");
    printf("14. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter data to insert at the beginning: ");
      scanf("%d", &data);
      insertAtBeginning(data);
      break;
    case 2:
      printf("Enter data to insert at the end: ");
      scanf("%d", &data);
      insertAtEnd(data);
      break;
    case 3:
      printf("Enter data of the node after which to insert: ");
      scanf("%d", &afterData);
      printf("Enter data to insert: ");
      scanf("%d", &data);
      insertAfterNode(afterData, data);
      break;
    case 4:
      printf("Enter data of the node before which to insert: ");
      scanf("%d", &beforeData);
      printf("Enter data to insert: ");
      scanf("%d", &data);
      insertBeforeNode(beforeData, data);
      break;
    case 5:
      printf("Enter the position to insert at: ");
      scanf("%d", &position);
      printf("Enter data to insert: ");
      scanf("%d", &data);
      insertAtPosition(position, data);
      break;
    case 6:
      printf("Enter data to search for: ");
      scanf("%d", &data);
      node = searchNode(data);
      if (node != NULL)
      {
        printf("Node with data %d found.\n", data);
      }
      else
      {
        printf("Node with data %d not found.\n", data);
      }
      break;
    case 7:
      printf("Enter data of the node to return: ");
      scanf("%d", &data);
      node = searchNode(data);
      if (node != NULL)
      {
        printf("Node with data %d found.\n", data);
      }
      else
      {
        printf("Node with data %d not found.\n", data);
      }
      break;
    case 8:
      deleteAtBeginning();
      printf("Node at the beginning deleted.\n");
      break;
    case 9:
      deleteAtEnd();
      printf("Node at the end deleted.\n");
      break;
    case 10:
      printf("Enter data of the node after which to delete: ");
      scanf("%d", &afterData);
      deleteAfterNode(afterData);
      break;
    case 11:
      printf("Enter data of the node before which to delete: ");
      scanf("%d", &beforeData);
      deleteBeforeNode(beforeData);
      break;
    case 12:
      printf("Enter data of the node to delete: ");
      scanf("%d", &data);
      deleteParticularNode(data);
      break;
    case 13:
      printList();
      break;
    case 14:
      exit(0);
    default:
      printf("Invalid choice. Please try again.\n");
      break;
    }
  }

  getch();
  return 0;
}