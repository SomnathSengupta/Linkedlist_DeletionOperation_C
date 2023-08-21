#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
void Linkedlist_Traversial(struct Node* Head) // This Function will Traverse the list and it will print the list Elements.
{
    struct Node* ptr = Head;
    while (ptr != NULL){
        printf("Element: %d\n", ptr -> data);
        ptr = ptr -> next;
    }
}
struct Node* Deletion_at_Beginnig(struct Node* Head) // This Function will delete the starting node. 
{
    struct Node* ptr = Head;
    Head = Head -> next;
    free(ptr);
    return Head;
}
struct Node* Deletion_at_SpecifiedIndex(struct Node* Head, int index) // This Function will delete a node at specified index.
{
    struct Node* p = Head;
    struct Node* q = Head -> next;
    for (int i=0; i < index -1; i++)
    {
        p = p -> next;
        q = q -> next;
    }
    p -> next = q -> next;
    free(q);
    return Head;
}
struct Node* Deletion_at_Last(struct Node* Head) // This Function will delete the last Node.
{
    struct Node* p = Head;
    struct Node* q = Head -> next;
    while (q -> next != NULL){
        p = p -> next;
        q = q -> next;
    }
    p -> next = NULL;
    free(q);
    return Head;
}
int main()
{
    struct Node *Head, *Second, *Third, *Fourth, *Fifth; // Creation Of Nodes
    // Allocating Memory For Nodes
    Head = (struct Node*)malloc(sizeof(struct Node));
    Second = (struct Node*)malloc(sizeof(struct Node));
    Third = (struct Node*)malloc(sizeof(struct Node));
    Fourth = (struct Node*)malloc(sizeof(struct Node));
    Fifth = (struct Node*)malloc(sizeof(struct Node));
    // Storing the data at the Nodes
    Head -> data = 4;
    Second -> data = 5;
    Third -> data = 6;
    Fourth -> data = 8;
    Fifth -> data = 10;
    // Linking the Nodes
    Head -> next = Second;
    Second -> next = Third;
    Third -> next = Fourth;
    Fourth -> next = Fifth;
    Fifth -> next = NULL;

    Linkedlist_Traversial(Head);   
    
    printf("Now we are going to perform the deletion at the beginning operation:\n"); 
    Head = Deletion_at_Beginnig(Head);
    Linkedlist_Traversial(Head);   

    printf("Now we are going to perform the deletion at specified index operation:\n");  
    Head = Deletion_at_SpecifiedIndex(Head, 1);
    Linkedlist_Traversial(Head);  

    printf("Now we are going to perform the deletion at the last operation:\n"); 
    Head = Deletion_at_Last(Head);
    Linkedlist_Traversial(Head);  
    return 0;
}
