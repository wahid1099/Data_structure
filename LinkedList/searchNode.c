#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node {

    int data;
    struct Node *next;
};
//for creating a new node
struct Node *createNode(int value){
    struct Node *newnode =(struct Node*) malloc(sizeof(struct Node));
    if(newnode==NULL){
         printf("Memory allocation failed\n");
        exit(1);
    }

    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

//for inserting a node at the node of created node
void insertAtEnd(struct Node **head,int value){

   struct Node *newNode = createNode(value);
   if(*head==NULL) {
    *head=newNode;
    return;
   }
   struct Node *current = *head;
   while(current->next!=NULL){
    current = current->next;
   }
   current->next = newNode;


}

void printList(struct Node *head){
    struct Node *current = head;
    while(current!= NULL){
        printf("%d ->",current->data);
        current =current->next;


    }
    printf("NULL\n");
}
 
 // Search a node
bool searchNode(struct Node** head_ref, int key) {
  struct Node* current = *head_ref;

  while (current != NULL) {
    if (current->data == key) return true;
      current = current->next;
  }
  return false;
}
int main()
{

    struct Node *head=NULL;
    int n;

 
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        int value;
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        insertAtEnd(&head, value);




    }

    printf("Linked List: ");
    printList(head);
    int val;

       printf("Enter the value you want to search : ");

    scanf("%d", &val);
    bool res =searchNode (&head , val );
    if(res){
        printf("found...");
    }else {
        printf("Not found...");

    }

 
 
  return 0;
}