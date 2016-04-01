#include <stdio.h>
#include <stdlib.h>



typedef struct v_node{
    int id;
    int sub_id;
    int marks;
    struct v_node* v_link ;
    struct v_node *h_link_right;
}VNODE;

int state = 0; //Keeps track of the present state

VNODE *restore_backup(char*, int sub_id);
VNODE *insert(VNODE *head, int id, int marks, int sub_id);
int delete(VNODE **head_ptr, int id);
void backup(char *backup_filename, VNODE *head);
VNODE *merge_records_same_subject();
void display(VNODE *head);
void display_db(VNODE *db_head);
void add_another_column(VNODE *db_head, VNODE *new_list);
void merge_different_subjects();

int start_process(){
  main_menu();
}

int main_menu(){
  int choice = 1;
  system("cd mydb");
  printf("\t\t\t\t\tMain Menu");

  while (choice != 0) {
    printf("1. Create a database\n" );
    printf("2. Select from previous databases\n" );

    fflush(stdin);
    scanf("%d", &choice);
    switch(choice){
      case 1:
        create_database();
    }
  }

}

int create_database(){
  char db_name[50];
  char command[60] = "mkdir ";
  int i = 0;

  printf("\nEnter the name of the database: ");
  scanf("%s", db_name);
  while (db_name[i] != '\0') {
    command[i+6] = db_name[i];
    i++;
  }
  command[i] = '\0';

  system(command);

  //Select the database
  {
    char command[60] = "cd ";
    i = 0;
    while(db_name[i] != '\0'){
      command[i+3] = db_name[i];
      i++;
    }
    command[i] = '\0';
  }
  return 0;
}

int main(int argc, char const *argv[]) {
  start_process();
  return 0;
}
