#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#include<dir.h>
#include<stdlib.h>
#define log "c:/log/users/user.txt"
#define ver_log "c:/ass/fix/ver.txt"
void reg_user();
void show_test();
void ver_comp();
void login_user();
void change_user();
void check();

struct vertify{
	char name[20],pass[20];
};
struct user{
	char name[20],pass[20];
};                  int action=0;
void main(){
	    if(action==0){
	    check();}
	    user u; char ch;
	    FILE *name;
	    clrscr();
	    name=fopen(log,"r+b");
	    while(fread(&u,sizeof(user),1,name)==1){
	    printf("Hello ! %s this is main page\n",u.name);
	    }fclose(name);
	    show_test();
	    ch=getch();
	    if(ch=='1') {change_user();main();}
	    getch();


}
void check(){ user u; char ch;
	     action=1;
 clrscr();
	    FILE *check;
	    check=fopen(log,"r+b");
	    if(check==NULL){
		  fclose(check);
		 reg_user();
		 }else{
		 fclose(check);
		 ver_comp();
		 clrscr();
		 login_user();
		 }
 getch();
}

void reg_user(){
		  vertify v;
		  user u;   char pass_again[20];
		  FILE *reg;
		  FILE *fv;
		  mkdir("c:/log");
		  mkdir("c:/log/users");
		  mkdir("c:/ass");
		  mkdir("c:/ass/fix");
     again:       clrscr();
		  printf("REGISTER NEW USER\n");
		  printf("Please Put Correct Info\n");
		  printf("Username: ");	     gets(u.name);
		  printf("Password: ");	     gets(u.pass);
		  printf("Confirm Password: ");gets(pass_again);
		  //vertify file
		  strcpy(v.name,u.name);strcpy(v.pass,u.pass);
		  fv=fopen(ver_log,"w+b");
		  fwrite(&v,sizeof(vertify),1,fv);
		  fclose(fv);
		  //end vertify file
		  if(strcmp(u.pass,pass_again)!=0){
		  printf("Your enter password not match");
		  goto again;
		  }
		  reg=fopen(log,"w+b");
		  fwrite(&u,sizeof(user),1,reg);
		  fclose(reg);
		  main();
}
void show_test(){ user u;
		  FILE *show;
		  show=fopen(log,"r+b");
		  printf("%20s%20s\n","Username","Password");
		  while(fread(&u,sizeof(user),1,show)==1){
		  printf("%20s%20s\n",u.name,u.pass);
		  fclose(show);
		  }
}
void ver_comp(){  user u; vertify v; char ch; char u_name[20],u_pass[20],v_name[20],v_pass[20];
		  FILE *comp_u,*comp_v;
		  comp_u=fopen(log,"r+b");
		  comp_v=fopen(ver_log,"r+b");
		 while(fread(&u,sizeof(user),1,comp_u)==1){strcpy(u_name,u.name);strcpy(u_pass,v.pass);}
		 while(fread(&v,sizeof(vertify),1,comp_v)==1){strcpy(v_name,v.name);strcpy(v_pass,v.pass);}
		 if(strcmp(v_name,u_name)==0){
			if(strcmp(v_pass,v_pass)==0){
			clrscr();
			printf("User Info in protected, Wait 2sec...");
			delay(2000);
			}else{
			fclose(comp_u);fclose(comp_v);
			printf(" Error_User_Info, file maybe changed by hacker.\n Please Contact Developer to fix");
			ch=getch();
			if(ch!=0){exit(0);}}
		  }else{
		  fclose(comp_u);fclose(comp_v);
		  printf(" Error_User_Info, file maybe changed by hacker.\n Please Contact Developer to fix");
		  ch=getch();
		  if(ch!=0) {exit(0);}
}		  }
void login_user(){ char g_name[20],g_pass[20],l_name[20],l_pass[20];
		  user u; char ch;
		FILE *flog;
		flog=fopen(log,"r+b");
		while(fread(&u,sizeof(user),1,flog)==1){
		strcpy(l_name,u.name); strcpy(l_pass,u.pass);
		}
     again:     clrscr();
		printf("LOGIN USER INFO\n");
		printf("Username: ");gets(g_name);
		printf("Password: ");gets(g_pass);
		if(strcmp(l_name,g_name)==0){
			if(strcmp(l_pass,g_pass)==0){
			printf("Login Sucessfully ! wait 2sec...\n");
			delay(2000);
			main();
			}else{clrscr();
			      printf("Password is not correct\n");
			      printf("Press Enter to try again\n");
			      printf("Press Space to register New\n");
			      printf("Press Esc to exit");
			      ch=getch();
			      if(ch==13) {goto again;}
			      if(ch==32) {reg_user();}
			      if(ch==27) {exit(0);}
			}
		}else{   clrscr();
			 printf("Username is not correct\n");
			 printf("Press Enter to try again\n");
			 printf("Press Space to register New\n");
			 printf("Press Esc to exit");
			 ch=getch();
			 if(ch==13) {goto again;}
			 if(ch==32) {reg_user();}
			 if(ch==27) {exit(0);}
		}
}
void change_user(){ user u; char ch_pass[20],cg_pass[20];char ch;
		    vertify v;
		  FILE *check1;
		  FILE *change;
		  FILE *ch_ver;
		  check1=fopen(log,"r+b");
		  while(fread(&u,sizeof(user),1,check1)==1){
		  strcpy(ch_pass,u.pass);
		  }
	 again:   clrscr();
		  printf("CHANGE USER INFO\n");
		  printf("Please Follow this:\n");
		  printf("Old Password: ");gets(cg_pass);
		  if(strcmp(cg_pass,ch_pass)==0){
		  fclose(check1);
		  printf("New Username: ");gets(u.name);
		  printf("New Password: ");gets(u.pass);
		  strcpy(v.name,u.name);strcpy(v.pass,u.pass);
		  change=fopen(log,"w+b");
		  ch_ver=fopen(ver_log,"w+b");
		  fwrite(&u,sizeof(user),1,change);
		  fwrite(&v,sizeof(vertify),1,ch_ver);
		  fclose(change); fclose(ch_ver);
		  }else{ printf("Old Password not correct\n");
			 printf("Press Enter to try old password\n");
			 printf("Press Anykey to exit");
			 ch=getch();
			 if(ch==13) {goto again;}
			 if(ch!=27) {exit(0);}else{main();}
			 }}
