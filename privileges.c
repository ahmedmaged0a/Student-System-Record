#include "privileges.h"
#include "List.h"
static int get_student(int ID);
static char *admin_password;
List students;

static void saferFree(void **pp);

void system_init(void){
    CreateList(&students);
    set_admin_password();
}


void set_admin_password(){
	admin_password=(char *)malloc(strlen("1111")+1);
	strcpy(admin_password,"1111");
}

int check_admin(char *admin_pass) {
	int check;
	if (strcmp(admin_password, admin_pass) == 0)
		check = 1;
	else{
		check = 0;}
	return check;
}

int check_student(int id,char *password){
    ListEntry std;
	int pos = get_student(id);
	RetrieveList(pos,&std,&students);
	if(strcmp(std.std_password, password) == 0){
        return 1;
	}else{
	    return 0;
	}

}

int add_new_student(char *name,char *password,int degree,int id){
    ListEntry s;

    s.std_name=(char *)malloc(strlen(name)+1);
    strcpy(s.std_name,name);
    s.std_password=(char *)malloc(strlen(password)+1);
    strcpy(s.std_password,password);
    s.std_id=id;
    s.std_degree=degree;

    InsertFront(s, &students);
    return 1;
}

int remove_student(int id){
    ListEntry s;
    int flag = 0;
		if(get_student(id) != -1){
		    RetrieveList(get_student(id), &s, &students);
			safeFree(s.std_name);
			safeFree(s.std_password);
			DeleteList(get_student(id), &s, &students);
		}
	return flag;
}

static void saferFree(void **pp)
{
	if (pp != NULL && *pp != NULL) {
		free(*pp);
		*pp = NULL;
	}
}

int change_student_name(int id,char *name){
    ListEntry s;
	int pos = get_student(id);
		if(pos != -1){
		    RetrieveList(pos, &s, &students);
			s.std_name = realloc(s.std_name,strlen(name)+1);
			strcpy(s.std_name,name);
            return 1;
		}

	return 0 ;
}
int change_student_password(int id,char *password){
    ListEntry s;
    int pos = get_student(id);
    if(pos != -1){
        RetrieveList(pos, &s, &students);
        s.std_password = realloc(s.std_password,strlen(password)+1);
        strcpy(s.std_password,password);
        return 1;
    }

    return 0 ;
}
int change_student_degree(int id,int degree){
    ListEntry s;
    int pos = get_student(id);
    if(pos != -1){
        RetrieveList(pos, &s, &students);
        s.std_degree=degree;
        return 1;
    }

    return 0 ;
}
int  student_record(int id){
    ListEntry s;
	int pos = get_student(id);
		if(pos != -1) {
		    RetrieveList(pos,&s,&students);
            printf("Name: %s\n", s.std_name);
            printf("Password: %s\n", s.std_password);
            printf("degree: %d\n", s.std_degree);
            return 1;
        }
		return 0;

}



void change_admin_password(char *new_password){
	admin_password = realloc(admin_password,strlen(new_password));
	strcpy(admin_password,new_password);
}

static int get_student(int ID)
{
    int i;
    ListEntry s;
    for (i = 0; i < ListSize(&students); i++)
    {
        RetrieveList(i, &s, &students);
        if (s.std_id == ID)
            return i;
    }
    return -1;
}