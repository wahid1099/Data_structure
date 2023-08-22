#include <stdio.h>
#include<stdlib.h>
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

void deleteNodeatpos(struct Node **head,int pos){
    //if list is empty or position is greater than length then do nothing
    struct Node *temp;
    struct Node *prev;
    prev = *head;
    temp=*head;
    if(head==NULL){
        printf("Linked list is empty ....");
        return;
    }

    for(int i=0;i<pos;i++){
        if(i==0 && pos==1){
            *head = (*head)->next;
            free(temp);
        }else{
            if(i==pos-1 && temp){
                prev->next = temp->next;
                free(temp);
            }  else {
                prev = temp;
 
                
                if (prev == NULL)
                    break;
                temp = temp->next;
            }
        }
    }


}


void deleteatbegining(struct Node **head){
            struct Node *ptr;  
            if(head == NULL){
                printf("Head is empty...");
                return;
            }
            ptr=*head;
            *head=ptr->next;
            free(ptr);
            printf("\n Node deleted from the begining ...\n");  

}


void deleteatEnd(struct Node **head){

     struct Node *temp;  
            if(head == NULL){
                printf("Head is empty...");
                return;
            }

            temp=*head;
            while(temp->next->next != NULL){
                temp=temp->next;

            }
            free(temp->next);
            temp->next=NULL;
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
    // printf("Enter the node number you want to delete");
    // int pos;
    // scanf("%d", &pos);
    // deleteNodeatpos(&head,pos);

    printf("Do you want to delete Node at head | last  | specific postion\n 1.Head\n 2.Tail\n3.Specific postion");
    int decision ;
    scanf("%d", &decision);
    if(decision == 1){
        deleteatbegining(&head);
    }else if(decision == 2){
        deleteatEnd(&head);

    }
    else if(decision == 3){
        int pos;
        printf("Enter postion:");
        scanf("%d", &pos);
        deleteNodeatpos(&head,pos);

    }
     printf("Linked List: ");
    printList(head);

     
   
  

     
  return 0;
}