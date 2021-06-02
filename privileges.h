
#ifndef STUDENTRECORD_PRIVILEGES_H
#define STUDENTRECORD_PRIVILEGES_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define safeFree(p) saferFree((void**)&(p))
void system_init(void);
/*
 * discription: create list, and set admin password.
 * return: void.
 */
void set_admin_password();
int check_admin(char *admin_pass);
int check_student(int id,char *password);
int add_new_student(char *name,char *password,int degree,int id);
int remove_student(int id);
void change_admin_password(char *new_password);
int change_student_name(int id,char *name);
int change_student_password(int id,char *password);
int change_student_degree(int id,int degree);
int student_record(int id);
#endif //STUDENTRECORD_PRIVILEGES_H
