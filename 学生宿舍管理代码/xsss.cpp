#include <stdio.h>

#include <stdio.h>

#include <stdlib.h>

#include <conio.h>

#include <windows.h>

#include <malloc.h>

#include <string.h>

#include <io.h>

#define N sizeof(struct car)

#define LEN 100

/*欢迎界面*/

void welcomehu()

{

system("cls");

printf("\t\t＃〓§〓〓〓〓〓§〓〓〓〓〓〓§〓〓〓〓〓§〓＃\n");

printf("\t\t  ↓    　↓      ↓    　↓    \n");

printf("\t\t　☆★☆      ☆★☆  　☆★☆  \n");

printf("\t\t--------7--------栋--------宿-------管-------\n");

printf("\t\t　☆★☆  　☆★☆    ☆★☆  　\n");

printf("\t\t  ↓    　↓      ↓    　↓    \n");

printf("\t\t  ※    　※      ※    　※    \n");

printf("\t\t|----------------------------------------------|\n");

printf("\t\t|**********                          **********|\n");

printf("\t\t|***************宿舍管理系统***************|\n");

printf("\t\t|**********                          **********|\n");

flushall();

getch();

system("cls");

}

/*学生信息录入模块*/

struct car

{

int num;          /*学号*/

char classes[10];    /*班级*/

char sushe[10];  /*宿舍*/

char name[20];    /*学生姓名*/

char zhuanye[20];    /*学生专业*/

struct car *next;

};

/*系统密码模块*/

void mimahu()

{

FILE *fp;

int i=0;

char a[6],aa;

char b[6];

fp=fopen("mima.txt","rt");

if(fp==NULL)

{

system("cls");

printf("*******************************************\n");

printf("*      请您输入系统初始密码(六位)        *\n");

printf("*******************************************\n");

fp=fopen("mima.txt","wt");

for(i=0;i<6;i++)

{

aa=getch();

printf("*");

a[i]=aa;

}

fputs(a,fp);

fclose(fp);

}

fgets(a,7,fp);

system("cls");

printf("|--------------------------|\n");

printf("|请输入系统管理员密码:(6位)|\n");

printf("|------------------=====---|\n");

flushall();

for(i=0;i<6;i++)

{

b[i]=getch();

printf("*");

}

if(a[0]==b[0]&&a[1]==b[1]&&a[2]==b[2]&&a[3]==b[3]&&a[4]==b[4]&&a[5]==b[5])

{

system("cls");

printf("---------------------------------\n");

printf("          密码正确！          \n ");

printf("---------------------------------\n");

printf("\n\n*****按任意键进入主菜单*****\n");

printf("---------------------------------\n");

getch();

}

else

{

system("cls");

printf("***************************************************\n");

printf("*                                                *\n");

printf("*      对不起密码错误! 按任意键退出!              *\n");

printf("*                                                *\n");

printf("***************************************************\n");

flushall();

getchar();

exit(1); 

}

}

/*输出模块*/

void output(struct car *p)

{

system("cls");

printf("---------------------------------------------------------\n");

printf("---------------------------------------------------------\n");

printf("\n\n      --学生信息表--    \n\n");

printf("---------------------------------------------------------\n");

printf("---------------------------------------------------------\n");

printf("学号--班级--宿舍--学生姓名--学生专业\n");

printf("---------------------------------------------------------\n");

p=p->next;

while(p!=NULL)

{

printf("%3d %8s %8s %8s  %s\n",p->num,p->classes,p->sushe,p->name,p->zhuanye);

printf("---------------------------------------------------------\n");

p=p->next;

}

printf("按任意键退出！！\n");

getch(); 

}

/*录入模块*/

struct car *build()

{

int i=0;

char flag;

struct car*p,*q,*head;

system("cls");

head=q=(struct car *)malloc(N);

p=(struct car *)malloc(N);

printf("*******************************************\n");

printf("*          录入学生信息                  *\n");

printf("*******************************************\n");

printf("\n              第%d个学生\n",i+1);

printf("*******************************************\n");

printf("\n      学号:");

scanf("%d",&p->num);

printf("---------------------------------\n");

printf("\n      班级:");

scanf("%s",p->classes);

getchar();

printf("---------------------------------\n");

printf("\n      宿舍:");

scanf("%s",&p->sushe);

printf("---------------------------------\n");

printf("\n      学生姓名:");

flushall();

scanf("%s",&p->name);

printf("---------------------------------\n");

printf("\n      学生专业:");

flushall();

scanf("%s",p->zhuanye);

printf("---------------------------------\n");

q->next=p;

q=p;

//system("cls");

for(i=1;;i++)

{

//    q->next=p;

//    q=p;

system("cls");

printf("*******************************************\n");

printf("*          是否继续录入？(Y/N)            *\n");

printf("*******************************************\n");

getchar();

scanf("%s",&flag);

getchar();

if(flag!='y'&&flag!='Y')

break;

//    q->next=p;

//    q=p;

p=(struct car *)malloc(N);

system("cls");

printf("**********************************\n");

printf("\n            第%d个学生\n",i+1);

printf("**********************************\n");

printf("\n      学号:");

scanf("%d",&p->num);

printf("---------------------------------\n");

printf("\n      班级:");

scanf("%s",p->classes);

getchar();

printf("---------------------------------\n");

printf("\n      宿舍号:");

scanf("%s",&p->sushe);

printf("---------------------------------\n");

printf("\n      学生姓名:");

scanf("%s",&p->name);

getchar();

printf("---------------------------------\n");

printf("\n      学生专业:");

scanf("%s",p->zhuanye);

printf("---------------------------------\n");

system("cls");

q->next=p;

q=p;

}

flushall();

p->next=NULL;

//    free(q);

flushall();

output(head);

flushall();

return (head);

}

/*按班级排序*/

struct car *sort(struct car *h)

{    struct car *temp1,*p1,*p2,*min,*temp;

temp=(struct car *)malloc(N);

if(h==NULL)

return h;

for(p1=h;p1!=NULL;p1=p1->next)

{

min=p1;

for(p2=p1;p2!=NULL;p2=p2->next)

if(min->num>p2->num)

min=p2;

if(min!=p1)

{

*temp=*min;

*min=*p1;

*p1=*temp;

temp1=min->next;

min->next=p1->next;

p1->next=temp1;

}

}

printf("\n");

return(h);

}

/*文件保存模块*/

void save_file(struct car *head)

{

struct car *p;

FILE *fp; 

char filename[100];

system("cls");

printf("---------------------------------\n");

printf("\n请输入要保存的文件名:\n");

scanf("%s",filename);

flushall();

printf("---------------------------------\n");

if((fp=fopen(filename,"wt"))==NULL)

{

printf("---------------------------------\n");

printf("\n写文件错误！按任意键退出！！\n");

printf("---------------------------------\n");

getch();

exit(1);

}

for(p=head->next;p!=NULL;p=p->next)

fprintf(fp,"%d %s %s %s %s\n",p->num,p->classes,p->sushe,p->name,p->zhuanye);

printf("---------------------------------\n");

printf("\n文件已保存成功！按任意键返回！\n");

printf("---------------------------------\n");

getch();

fclose(fp);

}

/*文件读取模块*/

struct car *read_file(char name[])

{

struct car *head,*r,*p;

FILE *fp;

system("cls");

if((fp=fopen(name,"rt"))==NULL)

{

printf("---------------------------------\n");

printf("\n\n***您的信息文件为空\n按任意键退出****\n");

printf("---------------------------------\n");

getch();

exit(1);

}

r=head=(struct car *)malloc(N);

//head->next=NULL;

//r=head;

while(!feof(fp))

{

p=(struct car *)malloc(N);

fscanf(fp,"%d %s %s %s %s\n",&p->num,p->classes,&p->sushe,&p->name,p->zhuanye);

//    if(feof(fp))

//    break;

r->next=p;

r=p;

}

r->next=NULL;

//free(p);

fclose(fp);

return(head);

}

/*学生查询模块*/

struct car *find(struct car *p)

{

int num;

char name2[10];

int choice;

system("cls");

printf("#---------------------------------------------------------#\n");

printf("#                    1 按班级查找                      #\n");

printf("#---------------------------------------------------------#\n");

printf("#                    2 按学号查找                    #\n");

printf("#---------------------------------------------------------#\n");

printf("请选择(1或2)");

scanf("%d",&choice);

if(choice==2)

{printf("---------------------------------\n");

printf("请输入你要查找(修改)的学号:  \n");

printf("---------------------------------\n");

scanf("%d",&num);

while(p->next!=NULL)

{

p=p->next;

if(p->num==num)

return p;

}

return NULL;

}

if(choice==1)

{

printf("---------------------------------\n");

printf("请输入你要查找(修改)的班级:  \n");

printf("---------------------------------\n");

scanf("%s",name2);

while(p->next!=NULL)

{

p=p->next;

if(!(strcmp(p->name,name2)))

return p;

}

return NULL;

}

return NULL;

}

/*学生删除模块*/

int shanchu(struct car *p0)

{

int num;

struct car *p;

p=p0->next;

if(p==NULL)

return 0;

system("cls");

printf("---------------------------------\n");

printf("请输入要删除学生学号:\n");

printf("---------------------------------\n");

scanf("%d",&num);

while(p!=NULL)

{

if(p->num==num)

{

p0->next=p->next;

free(p);

return 1;

}

p0=p;

p=p->next;

}

return 0;

}

/*学生增加模块*/

int charu(struct car *p0)

{

struct car *p;

p=(struct car *)malloc(N);

system("cls");

printf("---------------------------------\n");

flushall();

printf("请输入你要增加的学生信息:\n");

printf("---------------------------------\n");

printf("---------------------------------\n");

printf("\n      学号:");

flushall();

scanf("%d",&p->num);

printf("---------------------------------\n");

printf("\n  班级:");

flushall();

scanf("%s",p->classes);

getchar();

printf("---------------------------------\n");

printf("\n    宿舍号:");

flushall();

scanf("%s",&p->sushe);

printf("---------------------------------\n");

printf("\n      学生姓名:");

flushall();

scanf("%s",&p->name);

printf("---------------------------------\n");

printf("\n      学生专业:");

scanf("%s",p->zhuanye);

while(p0->next!=NULL)

p0=p0->next;

p0->next=p;

p->next=NULL;

return 1;

}

/*学生筛选模块*/

void shaixuan(struct car *p0)

{

struct car  *t,*p;

int flag=0;

t=(struct car *)malloc(N);

system("cls");

printf("请输入你要选择学生宿舍\n");

scanf("%s",&t->sushe);

printf("---------------------------------\n");

getchar();

printf("请输入你要选择学生姓名\n");

scanf("%s",&t->name);

printf("---------------------------------\n");

for(p=p0;p!=NULL;p=p->next)

{

system("cls");     

if(p->sushe==t->sushe)

{

flag=1;

printf("---------------------------------------------------------\n");

printf("学号--班级--宿舍号--学生姓名--学生专业\n");

printf("---------------------------------------------------------\n");

printf("%3d %8s %8s %8s %s\n",p->num,p->classes,p->sushe,p->name,p->zhuanye);

printf("---------------------------------------------------------\n");

printf("---------------------------------\n");

printf("\n\n****按任意键继续****\n");

printf("---------------------------------\n");

getch();

}

}

if(flag==0)

{

printf("---------------------------------\n");

printf("该学生信息不存在！");

printf("---------------------------------\n");

printf("\n\n****按任意键返回****\n");

printf("---------------------------------\n");

getch();

}

}

/*修改学生信息模块*/

void xiugai(struct car *p)

{

system("cls");

printf("*******************************************\n");

printf("\n 请输入修改后学生的信息\n");

printf("*******************************************\n");

printf("\n      学号:");

scanf("%d",&p->num);

printf("---------------------------------\n");

printf("\n      班级");

scanf("%s",p->classes);

getchar();

printf("---------------------------------\n");

printf("\n      宿舍号:");

scanf("%s",&p->sushe);

printf("---------------------------------\n");

printf("\n      学生姓名:");

scanf("%s",&p->name);

printf("---------------------------------\n");

printf("\n      学生专业:");

scanf("%s",p->zhuanye);

printf("---------------------------------\n");

}

/*创建用户界面*/

char chuangjian()

{

char flag;

system("cls");

printf("*******************************************\n");

printf("*      您是否要注册新用户（y/n）          *\n");

printf("*******************************************\n");

scanf("%c",&flag);

return flag;

}

/*选择用户界面*/

void  xuanze()

{

system("cls");

printf("*******************************************\n");

printf("*      请选择您要登录的用户名            *\n");

printf("*******************************************\n");

}

/*修改后保存模块*/

void baocun(char a[],struct car *head)

{

char flag;

struct car *p;

FILE *fp;

system("cls");

printf("*******************************************\n");

printf("*          您是否要保存（y/n）            *\n");

printf("*******************************************\n");

getchar();

scanf("%c",&flag);

getchar();

if(flag=='y'||flag=='Y')

{

if((fp=fopen(a,"wt"))==NULL)

{

printf("---------------------------------\n");

printf("\n写文件错误！按任意键退出！！\n");

printf("---------------------------------\n");

getch();

exit(1);

}

for(p=head->next;p!=NULL;p=p->next)

fprintf(fp,"%d %s %s %s %s\n",p->num,p->classes,p->sushe,p->name,p->zhuanye);

system("cls");

printf("*******************************************\n");

printf("*              保存成功！                *\n");

printf("*******************************************\n");

printf("---------------------------------\n");

printf("---------------------------------\n");

printf("\n\n****按任意键返回****\n");

printf("---------------------------------\n");

getch();

fclose(fp);

}

}

void main()

{

struct car *head,*p;

int choice;

char flag;

char name[20];

system("color 0B");

welcomehu();

mimahu();

flag=chuangjian();

if(flag=='y'||flag=='Y')

{

head=build();

save_file(head);

xuanze();

scanf("%s", name);

head=read_file(name);

do

{

system("cls"); 

printf("#                      !!!!!!!!!!                        #\n");

printf("#                    !!!!!!!!!!!!!!                      #\n");

printf("#*****            !!!!宿舍管理系统!!!!              *****#\n");

printf("#-----------------!!!!!!!!!!!!!!!!!!!!--------------------#\n");

printf("#--------------------!!!!!-----!!!!!----------------------#\n");

printf("#---------------------------------------------------------#\n");

printf("#                    1 读取学生信息                      #\n");

printf("#---------------------------------------------------------#\n");

printf("#                    2 查询学生信息                      #\n");

printf("#---------------------------------------------------------#\n");

printf("#                    3 删除学生信息                      #\n");

printf("#---------------------------------------------------------#\n");

printf("#                    4 增加学生信息                      #\n");

printf("#---------------------------------------------------------#\n");

printf("#                    5 排序学生信息                      #\n");

printf("#---------------------------------------------------------#\n");

printf("#                    6 修改学生信息                      #\n");

printf("#---------------------------------------------------------#\n");

printf("#                    7 查找学生信息                      #\n"); 

printf("#---------------------------------------------------------#\n");

printf("#                    0 退出程序                          #\n");

printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");

printf("---------------------------------------------------------\n");

printf("请选择(0--7)");

scanf("%d",&choice);

switch(choice)

{

case 1:  output(head);

break;

case 2:  p=find(head);

if(p)

{

printf("---------------------------------\n");

printf("学号--班级--宿舍号--学生姓名--学生专业\n");

printf("---------------------------------------------------------\n");

printf("%3d %8s %3s %3s  %s\n",p->num,p->classes,p->sushe,p->name,p->zhuanye);

printf("---------------------------------\n");

printf("\n\n****按任意键返回****\n");

printf("---------------------------------\n");

getch();

}

else

{

printf("---------------------------------\n");

printf("该学生信息不存在！");

printf("---------------------------------\n");

printf("\n\n****按任意键返回****\n");

printf("---------------------------------\n");

getch();

}

break;

case 3:  if(shanchu(head))

{

printf("---------------------------------\n");

printf("学生删除成功!\n");

printf("---------------------------------\n");

printf("\n\n****按任意键继续****\n");

printf("---------------------------------\n");

getch();

baocun(name,head);

}

else

{

printf("---------------------------------\n");

printf("没有删除\n");

printf("---------------------------------\n");

printf("\n\n****按任意键返回****\n");

printf("---------------------------------\n");

getch();

}

break;

case 4:  if(charu(head))

{

printf("---------------------------------\n");

printf("学生增加成功!\n");

printf("---------------------------------\n");

printf("\n\n****按任意键继续****\n");

printf("---------------------------------\n");

getch();

baocun(name,head);

}

else

{

printf("---------------------------------\n");

printf("学生增加失败！\n");

printf("---------------------------------\n");

printf("\n\n****按任意键返回****\n");

printf("---------------------------------\n");

getch();

}

break;

case 5:  sort(head);

system("cls");

printf("---------------------------------\n");

printf("学生排序成功!\n");

printf("---------------------------------\n");

printf("\n\n****按任意键返回****\n");

printf("---------------------------------\n");

getch();

break;

case 6:  shaixuan(head);

break;

case 7:  p=find(head);

if(p)

{

xiugai(p);

printf("---------------------------------\n");

printf("学生修改成功!\n");

printf("---------------------------------\n");

printf("\n\n****按任意键继续****\n");

printf("---------------------------------\n");

getch();

baocun(name,head);

}

else

{

printf("---------------------------------\n");

printf("该学生信息不存在！");

printf("---------------------------------\n");

printf("\n\n****按任意键返回****\n");

printf("---------------------------------\n");

getch();

}

break;

case 0:  exit(0);

}

}while(choice!=0);

}

else

{

xuanze();

scanf("%d",&choice);

head=read_file(name);

do

{

system("cls");     

printf("#                      !!!!!!!!!!                        #\n");

printf("#                    !!!!!!!!!!!!!!                      #\n");

printf("#*****            !!!!宿舍管理系统!!!!              *****#\n");

printf("#-----------------!!!!!!!!!!!!!!!!!!!!--------------------#\n");

printf("#--------------------!!!!!-----!!!!!----------------------#\n");

printf("#---------------------------------------------------------#\n");

printf("#                    1 读取学生信息                      #\n");

printf("#---------------------------------------------------------#\n");

printf("#                    2 查询学生信息                      #\n");

printf("#---------------------------------------------------------#\n");

printf("#                    3 删除学生信息                      #\n");

printf("#---------------------------------------------------------#\n");

printf("#                    4 增加学生信息                      #\n");

printf("#---------------------------------------------------------#\n");

printf("#                    5 排序学生信息                      #\n");

printf("#---------------------------------------------------------#\n");

printf("#                    6 修改学生信息                      #\n");

printf("#---------------------------------------------------------#\n");

printf("#                    7 查找学生信息                      #\n"); 

printf("#---------------------------------------------------------#\n");

printf("#                    0 退出程序                          #\n");

printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");

printf("---------------------------------------------------------\n");

printf("请选择(0--7)");

scanf("%d",&choice);

switch(choice)

{

case 1:  output(head);

break;

case 2:  p=find(head);

if(p)

{

printf("---------------------------------\n");

printf("学号--班级--宿舍号--学生姓名--学生专业\n");

printf("---------------------------------------------------------\n");

printf("%3d %8s %3s %3s  %s\n",p->num,p->classes,p->sushe,p->name,p->zhuanye);

printf("---------------------------------\n");

printf("\n\n****按任意键返回****\n");

printf("---------------------------------\n");

getch();

}

else

{

printf("---------------------------------\n");

printf("该学生信息不存在！");

printf("---------------------------------\n");

printf("\n\n****按任意键返回****\n");

printf("---------------------------------\n");

getch();

}

break;

case 3:  if(shanchu(head))

{

printf("---------------------------------\n");

printf("学生删除成功!\n");

printf("---------------------------------\n");

printf("\n\n****按任意键继续****\n");

printf("---------------------------------\n");

getch();

baocun(name,head);

}

else

{

printf("---------------------------------\n");

printf("没有删除\n");

printf("---------------------------------\n");

printf("\n\n****按任意键返回****\n");

printf("---------------------------------\n");

getch();

}

break;

case 4:  if(charu(head))

{

printf("---------------------------------\n");

printf("学生增加成功!\n");

printf("---------------------------------\n");

printf("\n\n****按任意键继续****\n");

printf("---------------------------------\n");

getch();

baocun(name,head);

}

else

{

printf("---------------------------------\n");

printf("学生增加失败！\n");

printf("---------------------------------\n");

printf("\n\n****按任意键返回****\n");

printf("---------------------------------\n");

getch();

}

break;

case 5:  sort(head);

system("cls");

printf("---------------------------------\n");

printf("学生排序成功!\n");

printf("---------------------------------\n");

printf("\n\n****按任意键返回****\n");

printf("---------------------------------\n");

getch();

break;

case 6:  shaixuan(head);

break;

case 7:  p=find(head);

if(p)

{

xiugai(p);                       

printf("---------------------------------\n");

printf("学生修改成功!\n");

printf("---------------------------------\n");

printf("\n\n****按任意键继续****\n");

printf("---------------------------------\n");

getch();

baocun(name,head);

}

else

{

printf("---------------------------------\n");

printf("该学生信息不存在！");

printf("---------------------------------\n");

printf("\n\n****按任意键返回****\n");

printf("---------------------------------\n");

getch();

}

break;           

case 0:  exit(0);

}

}while(choice!=0);

}

}