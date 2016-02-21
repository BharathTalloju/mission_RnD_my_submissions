#include <stdio.h>
#include <stdlib.h>



typedef struct v_node{
    int id;
    int sub_id;
    int marks;
    struct v_node* v_link ;
    struct v_node *h_link_right;
}VNODE;

VNODE *restore_backup(char*, int sub_id);
VNODE *insert(VNODE *head, int id, int marks, int sub_id);
int delete(VNODE **head_ptr, int id);
void backup(char *backup_filename, VNODE *head);
VNODE *merge_records_same_subject();
void display(VNODE *head);
void display_db(VNODE *db_head);
void add_another_column(VNODE *db_head, VNODE *new_list);
void merge_different_subjects();

void start_process(){
    int flag = 1;
    int choice ;
    int sub_id = 0;
    VNODE *head = NULL;
    
    printf("\t\t\t\tWelcome\n\n");
    while(flag == 1){
        
        printf("\n\t\t\tMain Menu"
               "\n1. Enter marks for new subject\n"
               "2. Edit previously backed up file\n"
               "3. Merge and Edit Records of same subject\n"
               "4. Merge records of different subjects\n"
               "5. Exit");
               printf("\nEnter your choice: ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                {
                    printf("\nEnter the subject_id: ");
                    scanf("%d",&sub_id);
                }
                flag = 2;
                break;
            case 2:
                {//Edit previously backed up record
                    int write_pos = 6;
                    int temp,r,end_pos;
                    char backup_filename[40];
                    
                    printf("\nEnter the subject_id: ");
                    scanf("%d",&sub_id);
                    printf("\nEnter the name of the file you want to restore from: ");
                    scanf("%s", backup_filename);
                    
                    head = restore_backup(backup_filename, sub_id);
                }
                flag = 2;
                break;
             case 3:
             {//Merge records
                 head = merge_records_same_subject();
             }
             flag = 2;
             break;
             
             case 4:{
                 //Merge records of different subjects
                 merge_different_subjects();
             }
             break;
             
             case 5:{
                 return;
             }
             default:
                printf("\nInvalid Choice");
                break;
        }
    
    while(flag == 2){
        
        printf("\n1. Display\n"
               "2. Insert\n"
               "3. Delete\n"
               "4. Backup and Exit\n"
               "5. Exit");
       printf("\nEnter your choice: ");
       fflush(stdin);
       scanf("%d",&choice);
       
       switch(choice){
           case 1:
                {//display
                    display(head);
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
                   head-> h_link_right = NULL;
                   head-> v_link = NULL;
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
               char backup_filename[40];
               
               printf("\nEnter the name of the file you want the records to be backed up in: ");
               scanf("%s", backup_filename);
               backup(backup_filename, head);
           }
           flag = 1;
           head = NULL;
           break;
           case 5:
           {//Exit to Main Menu
               flag = 1;
               head = NULL;
           }
           break;
       }
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
    
    if(!f_pointer){
        printf("\nERROR: file %s cannot be opened\nFile may not exist", f_name);
        exit(0);
    }
    fscanf(f_pointer, "%d",&id);
    if(feof(f_pointer)){
        return head;
    }
    fscanf(f_pointer,"%d",&marks);
    writer = (VNODE*)malloc(sizeof(VNODE));
    writer-> h_link_right = NULL;
    writer-> id = id;
    writer-> sub_id = sub_id;
    writer-> marks = marks;
    writer-> v_link = NULL;
    prev = writer;
    head = writer;
    
    while(!(feof(f_pointer))){
    fscanf(f_pointer, "%d %d\n",&id, &marks);
    writer = (VNODE*)malloc(sizeof(VNODE));
    writer-> h_link_right = NULL;
    prev-> v_link = writer;
    writer-> id = id;
    writer-> sub_id = sub_id;
    writer-> marks = marks;
    writer-> v_link = NULL;
    prev = writer;
    if(head == NULL){
        head = writer;
    }
    }
    fclose(f_pointer);
    printf("\n%s restored", f_name);
    return head;
}

VNODE *insert(VNODE *head, int id, int marks, int sub_id){
    //returns &head of the new list
    VNODE *new = NULL;
    VNODE *walker = head;
    VNODE *prev = NULL;
    
    if(head-> id > id){
        new = (VNODE*)malloc(sizeof(VNODE));
        new-> h_link_right = NULL;
        new-> id = id;
        new-> marks = marks;
        new-> sub_id = sub_id;
        new-> v_link = walker;
        return new;
    }
    while(walker-> id < id){
        if(walker-> v_link == NULL){
            new = (VNODE*)malloc(sizeof(VNODE));
            new-> h_link_right = NULL;
            new-> id = id;
            new-> marks = marks;
            new-> sub_id = sub_id;
            new-> v_link = walker-> v_link;
            walker-> v_link = new;
            return head;
        }
        prev = walker;
        walker = walker-> v_link;
    }
    if(walker-> id == id){
        return NULL;
    }
    new = (VNODE*)malloc(sizeof(VNODE));
    new-> h_link_right = NULL;
    new-> id = id;
    new-> marks = marks;
    new-> sub_id = sub_id;
    prev-> v_link = new;
    new-> v_link = walker;
    return head;
}

int delete(VNODE **head_ptr, int id){
    VNODE *walker = *head_ptr;
    VNODE *prev = NULL;
    
    while(walker){
        if(walker-> id == id){
            if(prev == NULL){
                //deleting head node
                walker = walker-> v_link;
                free(*head_ptr);
                *head_ptr = walker;
                return 1;
            }
            prev-> v_link = walker-> v_link;
            free(walker);
            return 1;
        }
        if(walker-> id > id){
            return 0;
        }
        prev = walker;
        walker = walker-> v_link;
    }
    return 0;
}

VNODE *merge_records_same_subject(){
    int sub_id;
    char f1_name[40];
    char f2_name[40];
    char resultant_f_name[40];
    VNODE *head1 = NULL;
    VNODE *head2 = NULL;
    VNODE *head3 = NULL;
    
    printf("\nEnter the subject_id: ");
    scanf("%d",&sub_id);
    {//creating resultant filename
        int temp = sub_id ;
        int writing_index = 6;
        while(temp){
            resultant_f_name[writing_index++] = '0' + (temp%10);
            temp = temp/10;
        }
        resultant_f_name[writing_index++] = '.';
        resultant_f_name[writing_index++] = 't';
        resultant_f_name[writing_index++] = 'x';
        resultant_f_name[writing_index++] = 't';
        resultant_f_name[writing_index] = '\0';
        
    }
    
    printf("\nEnter the name of the first file to merge: ");
    scanf("%s",f1_name);
    printf("\nEnter the name of the second file to merge: ");
    scanf("%s",f2_name);
    
    head1 = restore_backup(f1_name, sub_id);
    head2 = restore_backup(f2_name, sub_id);

    {//merging linked lists
        VNODE *walker1 = head1;
        VNODE *walker2 = head2;
        VNODE *walker3 = NULL;
        
        while(walker1 && walker2){
            if(walker1-> id < walker2-> id){
                if(head3 == NULL){
                    head3 = walker1;
                    walker3 = head3;
                    walker1 = walker1-> v_link;
                    walker3-> v_link = NULL;
                }
                else{
                    walker3-> v_link = walker1;
                    walker3 = walker1;
                    walker1 = walker1-> v_link;
                    walker3-> v_link = NULL;
                }
            }
            else if(walker2-> id < walker1-> id){
                if(head3 == NULL){
                    head3 = walker2;
                    walker2 = walker2-> v_link;
                    head3-> v_link = NULL;
                    walker3 = head3;
                }
                else{
                    walker3-> v_link= walker2;
                    walker3 = walker2;
                    walker2 = walker2-> v_link;
                    walker3-> v_link = NULL;
                }
            }
            else if(walker1-> id == walker2->id){
                VNODE *deleted_node = NULL;
                if(walker1-> marks < walker2-> marks){
                    if(head3 == NULL){
                    head3 = walker1;
                    walker3 = head3;
                    walker1 = walker1-> v_link;
                    walker3-> v_link = NULL;
                }
                else{
                    walker3-> v_link = walker1;
                    walker3 = walker1;
                    walker1 = walker1-> v_link;
                    walker3-> v_link = NULL;
                }
                deleted_node = walker2;
                walker2 = walker2-> v_link;
                free(deleted_node);
                deleted_node = NULL;
                }
                else{
                    if(head3 == NULL){
                        head3 = walker2;
                      walker2 = walker2-> v_link;
                       head3-> v_link = NULL;
                       walker3 = head3;
                    }
                    else{
                        walker3-> v_link= walker2;
                        walker3 = walker2;
                        walker2 = walker2-> v_link;
                        walker3-> v_link = NULL;
                    }
                    deleted_node = walker1;
                    walker1 = walker1-> v_link;
                    free(deleted_node);
                    deleted_node = NULL;
                }
            }
        }
        
        if(walker1){
            walker3-> v_link = walker1;
        }
        if(walker2){
            walker3-> v_link = walker2;
        }
    }
    printf("\nAfter merging: ");
    display(head3);
    
    printf("\nEnter the name of the file you want the records to be backed up in: ");
    scanf("%s", resultant_f_name);
    backup(resultant_f_name, head3);
    return head3;
}

void backup(char *backup_filename, VNODE *head){
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
        reader = reader-> v_link;
    }
    fclose(f_pointer);
    printf("\nRecords backed up in %s", backup_filename);
}

void display(VNODE *head){
    //displays a linked list
    int counter = 1;
    
    if(head == NULL){
        printf("\nNothing to display");
        return;
    }
    while(head){
        printf("\n%d. Student ID: %d  Marks: %d", counter++, head-> id, head-> marks);
        head= head-> v_link;
    }
}

void merge_different_subjects(){
    int flag = 1;
    int choice;
    VNODE *db_head = NULL;
    
    while(flag == 1){
        printf("\n\t\t\tDatabase Menu");
        printf("\n1. Display Database"
               "\n2. Add another column"
               "\n3. Perform queries"
               "\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:{
                //Display Database
                display_db(db_head);
            }
            break;
            
            case 2:{
                //Add another column
                char f_name[40];
                VNODE *new_list = NULL; 
                int sub_id;
                
                printf("\nEnter the subject id: ");
                scanf("%d", &sub_id);
                printf("\nEnter the name of the file : ");
                scanf("%s", f_name);
                
                new_list = restore_backup(f_name, sub_id);
                if(new_list == NULL){
                    //Do Nothing
                }
                else if(db_head == NULL){
                    //First list to be added
                    db_head = new_list;
                }
                else{
                    add_another_column(db_head, new_list);
                }
            }
            break;
            
            case 3:{
                //Perform Queries
                perform_queries(db_head);
            }
            
            default:{
                flag = 2;
            }
            break;
        }
        
    }
    
}

void display_db(VNODE *db_head){
    VNODE *next_row = NULL;
    int count = 0;
    
    if(db_head == NULL){
        printf("\n Nothing to display");
        return;
    }
    
    next_row = db_head;
    while(next_row){
        VNODE *horizontal_walker = NULL;
        
        if(!count++){
            //Printing Table headers
            VNODE *temp = db_head;
            printf("%5s", "ID");
            while(temp){
                printf(" sub%d ", temp-> sub_id);
                temp = temp-> h_link_right;
            }
            printf("\n");
            continue;
        }
        horizontal_walker = next_row;
        next_row = next_row-> v_link;
        
        printf("%5d", horizontal_walker-> id);
        while(horizontal_walker){
            printf(" %5d ", horizontal_walker-> marks);
            horizontal_walker = horizontal_walker-> h_link_right;
        }
        printf("\n");
        
    }
    
}

void add_another_column(VNODE *db_head, VNODE *new_list){
    VNODE *prev_list = db_head;
    VNODE *walker1 = NULL;
    VNODE *walker2 = NULL;
    
    //find the last list of the table
    for(walker2 = db_head ; walker2-> h_link_right ; walker2 = walker2-> h_link_right);
    
    walker1 = new_list;
    for(walker2; walker2 ; walker2 = walker2-> v_link ){
        while(walker1-> id < walker2-> id){
            VNODE *temp = walker1;
            walker1 = walker1-> v_link;
            free(temp);
        }
        if(walker1-> id == walker2-> id){
            walker2-> h_link_right = walker1;
            walker1 = walker1-> v_link;
        }
    }

}

void perform_queries(VNODE *db_head){
    int choice = 0;
    
    
}

int main(){
    start_process();
}