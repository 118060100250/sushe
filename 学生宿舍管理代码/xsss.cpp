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

/*��ӭ����*/

void welcomehu()

{

system("cls");

printf("\t\t��������������������������������������������\n");

printf("\t\t  ��    ����      ��    ����    \n");

printf("\t\t������      ����  ������  \n");

printf("\t\t--------7--------��--------��-------��-------\n");

printf("\t\t������  ������    ����  ��\n");

printf("\t\t  ��    ����      ��    ����    \n");

printf("\t\t  ��    ����      ��    ����    \n");

printf("\t\t|----------------------------------------------|\n");

printf("\t\t|**********                          **********|\n");

printf("\t\t|***************�������ϵͳ***************|\n");

printf("\t\t|**********                          **********|\n");

flushall();

getch();

system("cls");

}

/*ѧ����Ϣ¼��ģ��*/

struct car

{

int num;          /*ѧ��*/

char classes[10];    /*�༶*/

char sushe[10];  /*����*/

char name[20];    /*ѧ������*/

char zhuanye[20];    /*ѧ��רҵ*/

struct car *next;

};

/*ϵͳ����ģ��*/

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

printf("*      ��������ϵͳ��ʼ����(��λ)        *\n");

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

printf("|������ϵͳ����Ա����:(6λ)|\n");

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

printf("          ������ȷ��          \n ");

printf("---------------------------------\n");

printf("\n\n*****��������������˵�*****\n");

printf("---------------------------------\n");

getch();

}

else

{

system("cls");

printf("***************************************************\n");

printf("*                                                *\n");

printf("*      �Բ����������! ��������˳�!              *\n");

printf("*                                                *\n");

printf("***************************************************\n");

flushall();

getchar();

exit(1); 

}

}

/*���ģ��*/

void output(struct car *p)

{

system("cls");

printf("---------------------------------------------------------\n");

printf("---------------------------------------------------------\n");

printf("\n\n      --ѧ����Ϣ��--    \n\n");

printf("---------------------------------------------------------\n");

printf("---------------------------------------------------------\n");

printf("ѧ��--�༶--����--ѧ������--ѧ��רҵ\n");

printf("---------------------------------------------------------\n");

p=p->next;

while(p!=NULL)

{

printf("%3d %8s %8s %8s  %s\n",p->num,p->classes,p->sushe,p->name,p->zhuanye);

printf("---------------------------------------------------------\n");

p=p->next;

}

printf("��������˳�����\n");

getch(); 

}

/*¼��ģ��*/

struct car *build()

{

int i=0;

char flag;

struct car*p,*q,*head;

system("cls");

head=q=(struct car *)malloc(N);

p=(struct car *)malloc(N);

printf("*******************************************\n");

printf("*          ¼��ѧ����Ϣ                  *\n");

printf("*******************************************\n");

printf("\n              ��%d��ѧ��\n",i+1);

printf("*******************************************\n");

printf("\n      ѧ��:");

scanf("%d",&p->num);

printf("---------------------------------\n");

printf("\n      �༶:");

scanf("%s",p->classes);

getchar();

printf("---------------------------------\n");

printf("\n      ����:");

scanf("%s",&p->sushe);

printf("---------------------------------\n");

printf("\n      ѧ������:");

flushall();

scanf("%s",&p->name);

printf("---------------------------------\n");

printf("\n      ѧ��רҵ:");

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

printf("*          �Ƿ����¼�룿(Y/N)            *\n");

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

printf("\n            ��%d��ѧ��\n",i+1);

printf("**********************************\n");

printf("\n      ѧ��:");

scanf("%d",&p->num);

printf("---------------------------------\n");

printf("\n      �༶:");

scanf("%s",p->classes);

getchar();

printf("---------------------------------\n");

printf("\n      �����:");

scanf("%s",&p->sushe);

printf("---------------------------------\n");

printf("\n      ѧ������:");

scanf("%s",&p->name);

getchar();

printf("---------------------------------\n");

printf("\n      ѧ��רҵ:");

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

/*���༶����*/

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

/*�ļ�����ģ��*/

void save_file(struct car *head)

{

struct car *p;

FILE *fp; 

char filename[100];

system("cls");

printf("---------------------------------\n");

printf("\n������Ҫ������ļ���:\n");

scanf("%s",filename);

flushall();

printf("---------------------------------\n");

if((fp=fopen(filename,"wt"))==NULL)

{

printf("---------------------------------\n");

printf("\nд�ļ����󣡰�������˳�����\n");

printf("---------------------------------\n");

getch();

exit(1);

}

for(p=head->next;p!=NULL;p=p->next)

fprintf(fp,"%d %s %s %s %s\n",p->num,p->classes,p->sushe,p->name,p->zhuanye);

printf("---------------------------------\n");

printf("\n�ļ��ѱ���ɹ�������������أ�\n");

printf("---------------------------------\n");

getch();

fclose(fp);

}

/*�ļ���ȡģ��*/

struct car *read_file(char name[])

{

struct car *head,*r,*p;

FILE *fp;

system("cls");

if((fp=fopen(name,"rt"))==NULL)

{

printf("---------------------------------\n");

printf("\n\n***������Ϣ�ļ�Ϊ��\n��������˳�****\n");

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

/*ѧ����ѯģ��*/

struct car *find(struct car *p)

{

int num;

char name2[10];

int choice;

system("cls");

printf("#---------------------------------------------------------#\n");

printf("#                    1 ���༶����                      #\n");

printf("#---------------------------------------------------------#\n");

printf("#                    2 ��ѧ�Ų���                    #\n");

printf("#---------------------------------------------------------#\n");

printf("��ѡ��(1��2)");

scanf("%d",&choice);

if(choice==2)

{printf("---------------------------------\n");

printf("��������Ҫ����(�޸�)��ѧ��:  \n");

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

printf("��������Ҫ����(�޸�)�İ༶:  \n");

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

/*ѧ��ɾ��ģ��*/

int shanchu(struct car *p0)

{

int num;

struct car *p;

p=p0->next;

if(p==NULL)

return 0;

system("cls");

printf("---------------------------------\n");

printf("������Ҫɾ��ѧ��ѧ��:\n");

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

/*ѧ������ģ��*/

int charu(struct car *p0)

{

struct car *p;

p=(struct car *)malloc(N);

system("cls");

printf("---------------------------------\n");

flushall();

printf("��������Ҫ���ӵ�ѧ����Ϣ:\n");

printf("---------------------------------\n");

printf("---------------------------------\n");

printf("\n      ѧ��:");

flushall();

scanf("%d",&p->num);

printf("---------------------------------\n");

printf("\n  �༶:");

flushall();

scanf("%s",p->classes);

getchar();

printf("---------------------------------\n");

printf("\n    �����:");

flushall();

scanf("%s",&p->sushe);

printf("---------------------------------\n");

printf("\n      ѧ������:");

flushall();

scanf("%s",&p->name);

printf("---------------------------------\n");

printf("\n      ѧ��רҵ:");

scanf("%s",p->zhuanye);

while(p0->next!=NULL)

p0=p0->next;

p0->next=p;

p->next=NULL;

return 1;

}

/*ѧ��ɸѡģ��*/

void shaixuan(struct car *p0)

{

struct car  *t,*p;

int flag=0;

t=(struct car *)malloc(N);

system("cls");

printf("��������Ҫѡ��ѧ������\n");

scanf("%s",&t->sushe);

printf("---------------------------------\n");

getchar();

printf("��������Ҫѡ��ѧ������\n");

scanf("%s",&t->name);

printf("---------------------------------\n");

for(p=p0;p!=NULL;p=p->next)

{

system("cls");     

if(p->sushe==t->sushe)

{

flag=1;

printf("---------------------------------------------------------\n");

printf("ѧ��--�༶--�����--ѧ������--ѧ��רҵ\n");

printf("---------------------------------------------------------\n");

printf("%3d %8s %8s %8s %s\n",p->num,p->classes,p->sushe,p->name,p->zhuanye);

printf("---------------------------------------------------------\n");

printf("---------------------------------\n");

printf("\n\n****�����������****\n");

printf("---------------------------------\n");

getch();

}

}

if(flag==0)

{

printf("---------------------------------\n");

printf("��ѧ����Ϣ�����ڣ�");

printf("---------------------------------\n");

printf("\n\n****�����������****\n");

printf("---------------------------------\n");

getch();

}

}

/*�޸�ѧ����Ϣģ��*/

void xiugai(struct car *p)

{

system("cls");

printf("*******************************************\n");

printf("\n �������޸ĺ�ѧ������Ϣ\n");

printf("*******************************************\n");

printf("\n      ѧ��:");

scanf("%d",&p->num);

printf("---------------------------------\n");

printf("\n      �༶");

scanf("%s",p->classes);

getchar();

printf("---------------------------------\n");

printf("\n      �����:");

scanf("%s",&p->sushe);

printf("---------------------------------\n");

printf("\n      ѧ������:");

scanf("%s",&p->name);

printf("---------------------------------\n");

printf("\n      ѧ��רҵ:");

scanf("%s",p->zhuanye);

printf("---------------------------------\n");

}

/*�����û�����*/

char chuangjian()

{

char flag;

system("cls");

printf("*******************************************\n");

printf("*      ���Ƿ�Ҫע�����û���y/n��          *\n");

printf("*******************************************\n");

scanf("%c",&flag);

return flag;

}

/*ѡ���û�����*/

void  xuanze()

{

system("cls");

printf("*******************************************\n");

printf("*      ��ѡ����Ҫ��¼���û���            *\n");

printf("*******************************************\n");

}

/*�޸ĺ󱣴�ģ��*/

void baocun(char a[],struct car *head)

{

char flag;

struct car *p;

FILE *fp;

system("cls");

printf("*******************************************\n");

printf("*          ���Ƿ�Ҫ���棨y/n��            *\n");

printf("*******************************************\n");

getchar();

scanf("%c",&flag);

getchar();

if(flag=='y'||flag=='Y')

{

if((fp=fopen(a,"wt"))==NULL)

{

printf("---------------------------------\n");

printf("\nд�ļ����󣡰�������˳�����\n");

printf("---------------------------------\n");

getch();

exit(1);

}

for(p=head->next;p!=NULL;p=p->next)

fprintf(fp,"%d %s %s %s %s\n",p->num,p->classes,p->sushe,p->name,p->zhuanye);

system("cls");

printf("*******************************************\n");

printf("*              ����ɹ���                *\n");

printf("*******************************************\n");

printf("---------------------------------\n");

printf("---------------------------------\n");

printf("\n\n****�����������****\n");

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

printf("#*****            !!!!�������ϵͳ!!!!              *****#\n");

printf("#-----------------!!!!!!!!!!!!!!!!!!!!--------------------#\n");

printf("#--------------------!!!!!-----!!!!!----------------------#\n");

printf("#---------------------------------------------------------#\n");

printf("#                    1 ��ȡѧ����Ϣ                      #\n");

printf("#---------------------------------------------------------#\n");

printf("#                    2 ��ѯѧ����Ϣ                      #\n");

printf("#---------------------------------------------------------#\n");

printf("#                    3 ɾ��ѧ����Ϣ                      #\n");

printf("#---------------------------------------------------------#\n");

printf("#                    4 ����ѧ����Ϣ                      #\n");

printf("#---------------------------------------------------------#\n");

printf("#                    5 ����ѧ����Ϣ                      #\n");

printf("#---------------------------------------------------------#\n");

printf("#                    6 �޸�ѧ����Ϣ                      #\n");

printf("#---------------------------------------------------------#\n");

printf("#                    7 ����ѧ����Ϣ                      #\n"); 

printf("#---------------------------------------------------------#\n");

printf("#                    0 �˳�����                          #\n");

printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");

printf("---------------------------------------------------------\n");

printf("��ѡ��(0--7)");

scanf("%d",&choice);

switch(choice)

{

case 1:  output(head);

break;

case 2:  p=find(head);

if(p)

{

printf("---------------------------------\n");

printf("ѧ��--�༶--�����--ѧ������--ѧ��רҵ\n");

printf("---------------------------------------------------------\n");

printf("%3d %8s %3s %3s  %s\n",p->num,p->classes,p->sushe,p->name,p->zhuanye);

printf("---------------------------------\n");

printf("\n\n****�����������****\n");

printf("---------------------------------\n");

getch();

}

else

{

printf("---------------------------------\n");

printf("��ѧ����Ϣ�����ڣ�");

printf("---------------------------------\n");

printf("\n\n****�����������****\n");

printf("---------------------------------\n");

getch();

}

break;

case 3:  if(shanchu(head))

{

printf("---------------------------------\n");

printf("ѧ��ɾ���ɹ�!\n");

printf("---------------------------------\n");

printf("\n\n****�����������****\n");

printf("---------------------------------\n");

getch();

baocun(name,head);

}

else

{

printf("---------------------------------\n");

printf("û��ɾ��\n");

printf("---------------------------------\n");

printf("\n\n****�����������****\n");

printf("---------------------------------\n");

getch();

}

break;

case 4:  if(charu(head))

{

printf("---------------------------------\n");

printf("ѧ�����ӳɹ�!\n");

printf("---------------------------------\n");

printf("\n\n****�����������****\n");

printf("---------------------------------\n");

getch();

baocun(name,head);

}

else

{

printf("---------------------------------\n");

printf("ѧ������ʧ�ܣ�\n");

printf("---------------------------------\n");

printf("\n\n****�����������****\n");

printf("---------------------------------\n");

getch();

}

break;

case 5:  sort(head);

system("cls");

printf("---------------------------------\n");

printf("ѧ������ɹ�!\n");

printf("---------------------------------\n");

printf("\n\n****�����������****\n");

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

printf("ѧ���޸ĳɹ�!\n");

printf("---------------------------------\n");

printf("\n\n****�����������****\n");

printf("---------------------------------\n");

getch();

baocun(name,head);

}

else

{

printf("---------------------------------\n");

printf("��ѧ����Ϣ�����ڣ�");

printf("---------------------------------\n");

printf("\n\n****�����������****\n");

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

printf("#*****            !!!!�������ϵͳ!!!!              *****#\n");

printf("#-----------------!!!!!!!!!!!!!!!!!!!!--------------------#\n");

printf("#--------------------!!!!!-----!!!!!----------------------#\n");

printf("#---------------------------------------------------------#\n");

printf("#                    1 ��ȡѧ����Ϣ                      #\n");

printf("#---------------------------------------------------------#\n");

printf("#                    2 ��ѯѧ����Ϣ                      #\n");

printf("#---------------------------------------------------------#\n");

printf("#                    3 ɾ��ѧ����Ϣ                      #\n");

printf("#---------------------------------------------------------#\n");

printf("#                    4 ����ѧ����Ϣ                      #\n");

printf("#---------------------------------------------------------#\n");

printf("#                    5 ����ѧ����Ϣ                      #\n");

printf("#---------------------------------------------------------#\n");

printf("#                    6 �޸�ѧ����Ϣ                      #\n");

printf("#---------------------------------------------------------#\n");

printf("#                    7 ����ѧ����Ϣ                      #\n"); 

printf("#---------------------------------------------------------#\n");

printf("#                    0 �˳�����                          #\n");

printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");

printf("---------------------------------------------------------\n");

printf("��ѡ��(0--7)");

scanf("%d",&choice);

switch(choice)

{

case 1:  output(head);

break;

case 2:  p=find(head);

if(p)

{

printf("---------------------------------\n");

printf("ѧ��--�༶--�����--ѧ������--ѧ��רҵ\n");

printf("---------------------------------------------------------\n");

printf("%3d %8s %3s %3s  %s\n",p->num,p->classes,p->sushe,p->name,p->zhuanye);

printf("---------------------------------\n");

printf("\n\n****�����������****\n");

printf("---------------------------------\n");

getch();

}

else

{

printf("---------------------------------\n");

printf("��ѧ����Ϣ�����ڣ�");

printf("---------------------------------\n");

printf("\n\n****�����������****\n");

printf("---------------------------------\n");

getch();

}

break;

case 3:  if(shanchu(head))

{

printf("---------------------------------\n");

printf("ѧ��ɾ���ɹ�!\n");

printf("---------------------------------\n");

printf("\n\n****�����������****\n");

printf("---------------------------------\n");

getch();

baocun(name,head);

}

else

{

printf("---------------------------------\n");

printf("û��ɾ��\n");

printf("---------------------------------\n");

printf("\n\n****�����������****\n");

printf("---------------------------------\n");

getch();

}

break;

case 4:  if(charu(head))

{

printf("---------------------------------\n");

printf("ѧ�����ӳɹ�!\n");

printf("---------------------------------\n");

printf("\n\n****�����������****\n");

printf("---------------------------------\n");

getch();

baocun(name,head);

}

else

{

printf("---------------------------------\n");

printf("ѧ������ʧ�ܣ�\n");

printf("---------------------------------\n");

printf("\n\n****�����������****\n");

printf("---------------------------------\n");

getch();

}

break;

case 5:  sort(head);

system("cls");

printf("---------------------------------\n");

printf("ѧ������ɹ�!\n");

printf("---------------------------------\n");

printf("\n\n****�����������****\n");

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

printf("ѧ���޸ĳɹ�!\n");

printf("---------------------------------\n");

printf("\n\n****�����������****\n");

printf("---------------------------------\n");

getch();

baocun(name,head);

}

else

{

printf("---------------------------------\n");

printf("��ѧ����Ϣ�����ڣ�");

printf("---------------------------------\n");

printf("\n\n****�����������****\n");

printf("---------------------------------\n");

getch();

}

break;           

case 0:  exit(0);

}

}while(choice!=0);

}

}