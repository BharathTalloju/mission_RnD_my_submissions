#include <stdio.h>
#include <stdlib.h>

typedef struct v_node{
    int id;
    int sub_id;
    int marks;
    struct v_node* next ;
}VNODE;

VNODE *restore_backup(char*, int sub_id);
VNODE *insert(VNODE *head, int id, int marks, int sub_id);
int delete(VNODE **head_ptr, int id);

void start_process(){
    int flag = 1;
    int choice ;
    int sub_id = 0;
    VNODE *head = NULL;
    char backup_filename[40] = "backup.txt";
    
    printf("\t\t\t\tWelcome\n\n");
    while(flag){
        
        printf("1. Enter marks for new subject\n"
               "2. Edit previously backed up file\n");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                {
                    int write_pos = 6;
                    int temp,r,end_pos;
                    FILE *f_pointer = NULL;
                    printf("\nEnter the subject_id: ");
                    scanf("%d",&sub_id);
                    temp = sub_id;
                    while(temp){
                        r = temp%10;
                        backup_filename[write_pos] = r + '0';
                        temp = temp/10;
                        write_pos++;
                    }
                    backup_filename[write_pos++] = '.';
                    backup_filename[write_pos++] = 't';
                    backup_filename[write_pos++] = 'x';
                    backup_filename[write_pos++] = 't';
                    backup_filename[write_pos] = '\0';
                    
                    //creating file
                    f_pointer = fopen(backup_filename,"w");
                    fclose(f_pointer);
                }
                flag = 0;
                break;
            case 2:
                {
                    int write_pos = 6;
                    int temp,r,end_pos;
                    
                    printf("\nEnter the subject_id: ");
                    scanf("%d",&sub_id);
                    temp = sub_id;
                    while(temp){
                        r = temp%10;
                        backup_filename[write_pos] = r + '0';
                        temp = temp/10;
                        write_pos++;
                    }
                    backup_filename[write_pos++] = '.';
                    backup_filename[write_pos++] = 't';
                    backup_filename[write_pos++] = 'x';
                    backup_filename[write_pos++] = 't';
                    backup_filename[write_pos] = '\0';
                    
                    head = restore_backup(backup_filename, sub_id);
                }
                flag = 0;
                break;
             default:
                printf("\nInvalid Choice");
                break;
        }
    }
    flag = 1;
    while(flag){
        
        printf("\n1. Display\n"
               "2. Insert\n"
               "3. Delete\n"
               "4. Backup and Exit\n");
       printf("\nEnter your choice: ");
       fflush(stdin);
       scanf("%d",&choice);
       
       switch(choice){
           case 1:
                {//display
                    VNODE *walker = head;
                    int counter = 1;
                    
                    if(head == NULL){
                        printf("\nNothing to display");
                    }
                    else{
                    printf("\n\tSubject ID: %d",walker->sub_id);
                    while(walker){
                        printf("\n%d. ID: %5d, Marks: %5d",counter++,walker-> id, walker-> marks);
                        walker = walker-> next;
                    }
                    }
                }
                break;
           case 2:
           {//Insert
               int id,marks;
               VNODE *new_head = NULL;
               printf("\nEnter id<space>marks: ");
               scanf("%d %d",&id,&marks);
               if(head == NULL){
                   head = (VNODE *)malloc(sizeof(VNODE));
                   head-> id = id;
                   head-> marks = marks;
                   head-> sub_id = sub_id;
                   head-> next = NULL;
               }
               else{
               new_head = insert(head, id, marks, sub_id);
               if(new_head == NULL){
                   printf("\nERROR:Marks have already been entered for ID: %d",id);
               }
               else{
                   printf("\nInserted");
                   head = new_head;
               }
               }
           }
           break;
           case 3:
           {//Delete
               int id;
               int exists = 1;
               
               if(head == NULL){
                   printf("\nERROR: No records exist.");
               }
               else{
               printf("\nEnter the ID of the record you'd like to delete: ");
               scanf("%d",&id);
               exists = delete(&head, id);
               if(!exists){
                   printf("\nNo record with the given ID exists");
               }
               else{
                   printf("\nRecord deleted");
               }
               }
               
           } 
           break;
           case 4:
           {//Backup and exit
               FILE *f_pointer = NULL;
               int id,marks;
               VNODE *reader = head;
               f_pointer = fopen(backup_filename, "w");
               
               if(f_pointer == NULL){
                   printf("\nERROR: Cannot create file %s",backup_filename);
                   exit(0);
               }
               
               while(reader){
                   id = reader-> id;
                   marks = reader-> marks;
                   fprintf(f_pointer, "%d %d\n",id, marks);
                   reader = reader-> next;
               }
               fclose(f_pointer);
               printf("\nRecords backed up in %s", backup_filename);
           }
           flag = 0;
           break;
       }
    }
}

VNODE *restore_backup(char *f_name, int sub_id){
    //Restores data from backup file to a linked list and returns address to the head of the linked list.
    
    VNODE *head = NULL;
    VNODE *writer = NULL;
    VNODE *prev = NULL;
    FILE *f_pointer = NULL;
    int id,marks;
    
    f_pointer = fopen(f_name, "r");
    
    fscanf(f_pointer, "%d",&id);
    if(feof(f_pointer)){
        return head;
    }
    fscanf(f_pointer,"%d",&marks);
    writer = (VNODE*)malloc(sizeof(VNODE));
    writer-> id = id;
    writer-> sub_id = sub_id;
    writer-> marks = marks;
    writer-> next = NULL;
    prev = writer;
    head = writer;
    
    while(!(feof(f_pointer))){
    fscanf(f_pointer, "%d %d\n",&id, &marks);
    writer = (VNODE*)malloc(sizeof(VNODE));
    prev-> next = writer;
    writer-> id = id;
    writer-> sub_id = sub_id;
    writer-> marks = marks;
    writer-> next = NULL;
    prev = writer;
    if(head == NULL){
        head = writer;
    }
    }
    
    return head;
}

VNODE *insert(VNODE *head, int id, int marks, int sub_id){
    //returns &head of the new list
    VNODE *new = NULL;
    VNODE *walker = head;
    VNODE *prev = NULL;
    
    if(head-> id > id){
        new = (VNODE*)malloc(sizeof(VNODE));
        new-> id = id;
        new-> marks = marks;
        new-> sub_id = sub_id;
        new-> next = walker;
        return new;
    }
    while(walker-> id < id){
        if(walker-> next == NULL){
            new = (VNODE*)malloc(sizeof(VNODE));
            new-> id = id;
            new-> marks = marks;
            new-> sub_id = sub_id;
            new-> next = walker-> next;
            walker-> next = new;
            return head;
        }
        prev = walker;
        walker = walker-> next;
    }
    if(walker-> id == id){
        return NULL;
    }
    new = (VNODE*)malloc(sizeof(VNODE));
    new-> id = id;
    new-> marks = marks;
    new-> sub_id = sub_id;
    prev-> next = new;
    new-> next = walker;
    return head;
}

int delete(VNODE **head_ptr, int id){
    VNODE *walker = *head_ptr;
    VNODE *prev = NULL;
    
    while(walker){
        if(walker-> id == id){
            if(prev == NULL){
                //deleting head node
                walker = walker-> next;
                free(*head_ptr);
                *head_ptr = walker;
                return 1;
            }
            prev-> next = walker-> next;
            free(walker);
            return 1;
        }
        if(walker-> id > id){
            return 0;
        }
        prev = walker;
        walker = walker-> next;
    }
    return 0;
}

int main(){
    start_process();
}