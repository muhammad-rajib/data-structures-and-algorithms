#include<stdio.h>
#include<stdlib.h>

#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999


struct listNode
{
    int item ; //will be used to store value
    struct listNode *next ; //will keep address of next node
} ;
struct listNode * list ;
int length;

void initializeList()
{
    list = 0 ; //set to NULL
    length=0;
}

int insertItemBegin(int item)
{
    struct listNode * newNode ;
    newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
    newNode->item = item ;
    newNode->next = list ;
    list = newNode ;
    length++;
    return SUCCESS_VALUE ;
}

struct listNode* searchItem(int item)
{
    struct listNode *temp ;
    temp = list ; //start at the beginning
    while (temp != 0)
    {
        if (temp->item == item) return temp ;
        temp = temp->next ; //move to next node
    }
    return 0 ; //0 means invalid pointer in C, also called NULL value in C
}

int GetItem(int position)
{
    if(position<0 || position>=length) return NULL_VALUE;
    struct listNode *temp;
    int count=0;
    temp=list;
    while(count<position)
    {
        temp=temp->next;
        count++;
    }
    return temp->item;
}

void PrintALL()
{
    struct listNode *temp;
    temp = list ; //start at the beginning
    while (temp != 0)
    {
        printf("%d ",temp->item);
        temp = temp->next ; //move to next node
    }
    printf("\n");
}

int deleteFirstOccurrence(int item)
{
    struct listNode *temp, *prev ;
    temp = list ; //start at the beginning
    while (temp != 0)
    {
        if (temp->item == item) break ;
        prev = temp;
        temp = temp->next ; //move to next node
    }
    if (temp == 0) return NULL_VALUE ; //item not found to delete
    if (temp == list) //delete first node
    {
        list = list->next ;
        free(temp) ;
    }
    else
    {
        prev->next = temp->next ;
        free(temp);
    }
    length--;
    return SUCCESS_VALUE ;
}

//Assignment
int insertItemLast(int item) // Insert item at the last position of the list
{
    struct listNode *newNode, *temp;
    newNode = (struct listNode*)malloc(sizeof(struct listNode));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->item = item; // Link the data part
        newNode->next = NULL; 

        temp = list;

        // Traverse to the last node
        while(temp != NULL && temp->next != NULL)
            temp = temp->next;

        temp->next = newNode; // Link address part
        length++;

        return SUCCESS_VALUE;
    }
}

int insertItemAT(int item, int position) // Insert item at the given position of the list
{
    struct listNode *newnode, *curNode;

    if(list == NULL)
    {
        return NULL_VALUE; // no data found
    }
    else if(position == 0)
    {
        insertItemBegin(item);
    }
    else
    {
        newnode = (struct listNode *)malloc(sizeof(struct listNode));
        newnode->item = item;
        curNode = list;
        int i;

        for(i=1; i<=position-1; i++)
        {
            curNode = curNode->next;
        }
        newnode->next = curNode->next;
        curNode->next = newnode;
    }
}

int NumOfItems(int item) // return the number of the occurrence of the given item
{
    int cnt = 0, i = 0;
    struct listNode *temp;
    temp = list;
    while (temp->next != NULL)
    {
        if (temp->item == item)
        {
            cnt++;
        }
        temp = temp->next;
    }
    if (temp->item == item)
    {
        cnt++;
    }
    printf("%d ", cnt);
    printf("\n");
}

int deleteALLOccurrence(int item) // Delete all the occurrence of the given item in the list with preserving order
{
    struct listNode *temp, *prev;
    temp = list;
 
    while (temp != NULL && temp->item == item)
    {
        list = temp->next;
        free(temp);
        temp = list;
        length--;
    }
    // Delete occurrences other than head
    while (temp != NULL)
    {
        while (temp != NULL && temp->item != item)
        {
            prev = temp;
            temp = temp->next;
        }
 
        if (temp == NULL)
            return NULL_VALUE;
 
        // Unlink the node from linked list
        prev->next = temp->next;
        length--;
 
        free(temp); // Free memory
 
        // Update Temp for next iteration of outer loop
        temp = prev->next;
    }
    return SUCCESS_VALUE;
}

int deleteLastOccurrence(int item)// Delete the last occurrence of the given item in the list
{
    struct listNode *current, *prev, *temp;

    current=list;
    prev=NULL;
    temp=NULL;

    while(current!=NULL)
    {
        if(current->next != NULL && current->next->item == item)
        {
        prev=current;
        temp=current->next;
        }
        current=current->next;
    }
    prev->next=temp->next;
    length--;
    return SUCCESS_VALUE ;
}

int deleteFirstItem() // delete the first item of the list
{
    struct listNode *temp;
     
    if (list == NULL)
    {
        printf("List is Empty.");
    }
    else
    {
        temp = list->next;
        free(list);
        list = temp;
        length--;

        return SUCCESS_VALUE;   
    }
}

int deletelastItem() // delete the last item of the list
{
    struct listNode *to_delete, *secondLastNode;

    if(list == NULL)
    {
        printf("List is Empty.");
    }
    else
    {
        to_delete = list;
        secondLastNode = list;

        /* Traverse to the last node of the list */
        while(to_delete->next != NULL)
        {
            secondLastNode = to_delete;
            to_delete = to_delete->next;
        }
        if(to_delete == list)
        {
            list = NULL;
        }
        else
        {
            secondLastNode->next = NULL;
        }
        /* Delete the last item */
        free(to_delete);
        length--;

        return SUCCESS_VALUE ;
    }
}


int main()
{
    char inp1, chk;
    int inp2;
    int s;
    int position;
    initializeList();
    while(1){
        scanf("%c",&inp1);

        switch(inp1)
        {
        case 'I':
            scanf("%d",&inp2);
            s=insertItemBegin(inp2);
            break;
        case 'G':
            scanf("%d",&inp2);
            s=GetItem(inp2);
            printf("%d\n",s);
            break;
        case 'S':
            scanf("%d",&inp2);
            printf("Address: %d\n",searchItem(inp2));
            break;
        case 'R':
            scanf("%d",&inp2);
            s=deleteFirstOccurrence(inp2);
            break;
        case 'P':
            PrintALL();
            break;
        case 'L':
            printf("Length: %d\n",length);
            break;
        
        // Assignments
        case 'A': //insert item last
            scanf("%d",&inp2);
            s=insertItemLast(inp2);
            break;
        case 'B': //insert item at
            scanf("%d",&inp2);
            scanf("%d", &position);
            s=insertItemAT(inp2, position);
            break;
        case 'C': //number of items
            scanf("%d",&inp2);
            s=NumOfItems(inp2);
            break;
        case 'D': //delete all occurrence
            scanf("%d",&inp2);
            s=deleteALLOccurrence(inp2);
            break;
        case 'E': //delete last occurrence
            scanf("%d",&inp2);
            s=deleteLastOccurrence(inp2);
            break;
        case 'F': //delete the fast item
            s=deleteFirstItem();
            break;
        case 'H': //delete the last item
            s=deletelastItem();
            break;
        }
        if(s==NULL_VALUE) break;
    }
}