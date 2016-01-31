#include <stdio.h>
#include <stdlib.h>

struct node{
    int id;
    int marks;
    struct node* next;
};

struct node *restore(struct node** head);
struct node *search(struct node *head, int id, int *found);

int start_process(){
    struct node *head = NULL;
    struct node *writer = NULL;
    struct node *new = NULL;
    int temp = 0;
    int id,marks;
    int choice = 0;
    int flag = 1;
    
    while(flag){
        printf("1. Restore Previous data\n2. Insert new Node(Auto restore of prev list)\n3. Delete a node\n4. View all nodes\n5. Search using id\n6. Backup and exit\nEnter Your Choice: ");
       
       fflush(stdin);
       scanf("%d", &choice);
       switch(choice){
           case 1:
                writer = restore(&head);
                printf("\nData Restored\n");
                break;
           case 2:
                if(!writer){
                    writer = restore(&head);
                    printf("\nData Restored\n");
                    
                }
                    {
                    int id,marks;
                    new = (struct node*)malloc(sizeof(struct node));
                    
                    writer-> next = new;
                    writer = new;
                    printf("\nEnter id<space>marks : ");
                    scanf("%d %d",&id, &marks);
                    writer-> id = id;
                    writer-> marks = marks;
                    writer-> next = NULL;
                    }
                    if(head == NULL){
                        head = writer;
                    }
                
                break;
           case 3:
                printf("\nEnter the id of the person to be deleted: ");
                scanf("%d",&id);
                {   
                    struct node *node_removed = NULL;
                    int found = 1;
                    new = search(head, id, &found);// storing the address of the predecessor of id
                    if(!found){
                        printf("\nID not found");
                        break;
                    }
                    if(new == NULL){
                        node_removed = head;
                        head = head-> next;
                        free(node_removed);
                        break;
                    }
                    else{
                        node_removed = new-> next;
                    }
                    new-> next = node_removed-> next;
                    free(node_removed);
                }
                break;
                
            case 4:
                    {
                        struct node* walker = head;
                        int counter = 1;
                        while(walker != NULL){
                            printf("%d. ID: %d, Marks: %d\n", counter, walker-> id, walker-> marks);
                            walker = walker-> next;
                            counter++;
                        }
                    }
                    break;
             case 5:
                    {
                        int id;
                        int found = 1;
                        
                        struct node* predecessor = NULL;
                        printf("\nEnter the id to be searched: ");
                        scanf("%d",&id);
                        predecessor = search(head, id, &found);
                        if(!found){
                            printf("\nRecord Not Found\n");
                        }
                        else{
                            printf("Record Found\n");
                            
                            if(predecessor == NULL){
                                printf("ID: %d, Marks: %d", head-> id, head-> marks);
                            }
                            else{
                                predecessor = predecessor-> next;
                                printf("ID: %d, Marks: %d\n", predecessor-> id, predecessor-> marks);
                            }
                        }
                    }
                    break;
                
               case 6:
                    {
                        FILE *f_pointer = fopen("backup_data.txt", "w");
                        struct node *walker = head;
                        
                        while(walker){
                            fprintf(f_pointer,"%d %d\n",walker-> id, walker-> marks);
                            walker = walker-> next;
                        }
                        printf("\nList Backed up to disk");
                        flag = 0;
                        fclose(f_pointer);
                    }
                    break;
               default:
                    printf("\nInvalid Choice");
                    break;
                
       }
    }
}

struct node *restore(struct node** head){
    //Returns the address of the last node
    FILE *f_pointer = NULL;
    struct node *writer = NULL;
    int id, marks;
    
    f_pointer = fopen("backup_data.txt","r");
    while(!feof(f_pointer)){
        fscanf(f_pointer,"%d %d\n",&id,&marks);
        if(!*head){
            *head = (struct node*)malloc(sizeof(struct node));
            writer = *head;
            writer-> id = id;
            writer-> marks = marks;
            writer-> next = NULL;
        }
        else{
            writer-> next = (struct node*)malloc(sizeof(struct node));
            writer = writer-> next;
            writer-> id = id;
            writer-> marks = marks;
            writer-> next = NULL;
        }
        
    }
    fclose(f_pointer);
    
    return writer;
}

struct node *search(struct node *head, int id, int *found){
    //Returns the predecessor of id
    // if head->id == id, returns NULL
    // if not found, sets found to 0
    struct node *walker = head;
    
    if(walker-> id == id){
        return NULL;
    }
    
    while(walker-> next){
        if (walker-> next-> id == id){
            return walker;
        }
        walker = walker-> next;
    }
    
    *found = 0;
    return NULL; 
}

int main(){
    start_process();
}