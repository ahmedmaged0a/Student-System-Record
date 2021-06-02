#include "interface.h"
void system_mode(void){
    system_init();
    int mode;
	printf("Please Enter Your Mode (Admin Or User ?)\n 1-write \"1\".For Admin\n 2-Write \"2\" For User\n");
	scanf("%d",&mode);
	if (mode !=2 && mode !=1){
		printf("Error!\nPlease Enter Mode Again:\n");
		scanf("%d",&mode);
	}
	switch(mode){
	case 1:
		admin();
		break;
	case 2:
		user();
		break;
	default:
		break;
	}
}
void admin(){
	char admin_passwword[20];
	printf("Enter Admin Password: \n");
	scanf("%s",admin_passwword);
	if(check_admin(admin_passwword)== 1){
		printf("Password Is True.\n Welcome To Admin Mode (*_*)\n");
		admin_choose();
	}
	else{
		printf("Wrong Password!\n");
		admin();
	}
}
void admin_choose(){
	printf("1.Add student record.\n");
	printf("2.Remove Student Record.\n");
	printf("3.Change Student Name.\n");
	printf("4.Change Student password.\n");
	printf("5.Change Student degree.\n");
	printf("6.View student Record. \n");
	printf("7.Edit admin password. \n");
	printf("8.Return to main menu: \n");
	admin_control();
}
void admin_control(){
	char std_name[20];
	char std_password[20];
	char admin_password[20];
	int std_id;
	int std_degree;
	int choose;
	printf("Please Enter Your Choose From \"1\" To \"8\": ");
	scanf("%d",&choose);
	switch(choose){
	case 1:
		printf("Enter Student Name: \n");
		scanf("%s",std_name);
		printf("Enter Student password: \n");
		scanf("%s",std_password);
		printf("Enter Student id: \n");
		scanf("%d",&std_id);
		printf("Enter Student degree: \n");
		scanf("%d",&std_degree);
		if(add_new_student(std_name,std_password,std_degree,std_id))
			printf("Student has been Added Successfully(*_*)\n");
		else
			printf("Sorry!There is no empty place\n");
		break;
	case 2:
		printf("Enter Student Id: \n");
		scanf("%d",&std_id);
		if(remove_student(std_id))
			printf("Student has been removed Successfully\n");
		else
			printf("Wrong ID!\n");
		break;
	case 3:
		printf("Enter the student ID:\n");
		scanf("%d",&std_id);
		printf("Enter New Student Name: \n");
		scanf("%s",std_name);
		if(change_student_name(std_id,std_name)){
			printf("Name has been changed successfully\n");
		}
		else{
			printf("Wrong ID\n");
		}
		break;
	case 4:
        printf("Enter the student ID:\n");
            scanf("%d",&std_id);
		printf("Enter New Student password: \n");
		scanf("%s",std_password);
		if(change_student_password(std_id,std_password)){
			printf("password has been changed successfully\n");
		}
		else{
			printf("Wrong ID\n");
		}
		break;
	case 5:
        printf("Enter the student ID:\n");
            scanf("%d",&std_id);
		printf("Enter New Student degree: \n");
		scanf("%d",&std_degree);
		if(change_student_degree(std_id,std_degree)){
			printf("degree has been changed successfully\n");
		}
		else{
			printf("Wrong ID\n");
		}
		break;



	case 6 :
		printf("Enter student id:\n ");
		scanf("%d",&std_id);
		student_record(std_id);
		break;
	case 7:
		printf("Enter The new Admin password: \n");
		scanf("%s",admin_password);
		change_admin_password(admin_password);
		break;
	case 8:
		system_mode();
		break;
	default:
		printf("Wrong Choose!\n");
		break;
	}
	admin_choose();
}
void user(){
	int std_id;
	char std_password[20];
	printf("Please Enter Your ID: \n");
	scanf("%d",&std_id);
	printf("Please Enter Your Password: \n");
	scanf("%s",std_password);
	if(check_student(std_id,std_password)){
		user_choose();
		user_control(std_id);
	}
	else{
		printf("Wrong ID!!");
	}
}
void user_choose(){
	printf("1-View Your Record:\n");
	printf("2-Edit Your password:\n");
	printf("3-Return to main menu:\n");
}
void user_control(int std_id){
	char std_password[20];
	int choose;
	printf("Enter 1 Or 2 \n");
	scanf("%d",&choose);
	switch(choose){
	case 1:
		student_record(std_id);
		break;
	case 2:
		printf("Enter New password:\n ");
		scanf("%s",std_password);
		change_student_password(std_id,std_password);
		break;
	case 3:
		system_mode();
		break;
	default:
		printf("Wrong choose!\n");
		break;
	}
}