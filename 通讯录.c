#include <stdio.h>
#include <stdlib.h>
typedef struct node                           //定义通讯录需要的结构体类型；
{
	int GDtel;
	int YDtel;
	int QQ;
	char sex[10];
	char name[10];
	char email[20];
	char address[20];
	char workplace[20];
	char type[10];
	struct node *next;
}TXL,*PTXL;
struct node *creat(int n)                         //信息录用函数；
{
		int m,z,i;
		PTXL head=NULL,tail=NULL,p;
		FILE *fp;
		TXL Q;
		printf("如果继续请按1，不输入请按0\n");
		scanf("%d",&m);
		if(m==0)
		{
				printf("未录取任何信息\n");
				return NULL;
		}
		if(n==1)                                //手动输入信息；
		{
			printf("请输入姓名\n");
			scanf("%s",&Q.name);
			printf("请输入性别\n");
			scanf("%s",&Q.sex);
			printf("请输入Email\n");
			scanf("%s",&Q.email);
			printf("请输入地址\n");
			scanf("%s",&Q.address);
			printf("请输入工作地址\n");
			scanf("%s",&Q.workplace);
			printf("请输入他/她与您的关系\n");
			scanf("%s",&Q.type);
			printf("请输入固定电话\n");
			scanf("%d",&Q.GDtel);
			printf("请输入移动电话\n");
			scanf("%d",&Q.YDtel);
			printf("请输入QQ\n");
			scanf("%d",&Q.QQ);
			while(m!=0)
			{	
				p=(PTXL)malloc(sizeof(TXL));
				p->GDtel=Q.GDtel;
				p->YDtel=Q.YDtel;
				p->QQ=Q.QQ;
				strcpy(p->name,Q.name);
				strcpy(p->address,Q.address);
				strcpy(p->sex,Q.sex);
				strcpy(p->workplace,Q.workplace);
				strcpy(p->type,Q.type);
				strcpy(p->email,Q.email);
				p->next=NULL;
				if(head==NULL)
					head=tail=p;
				else
				{
					tail->next=p;
					tail=p;
				}
				printf("是否继续输入下一个人的信息？\n");
				printf("继续请按1，退出请按0\n");
				scanf("%d",&m);
				if(m==1)
				{
					printf("请输入姓名\n");
					scanf("%s",&Q.name);
					printf("请输入性别\n");
					scanf("%s",&Q.sex);
					printf("请输入Email\n");
					scanf("%s",&Q.email);
					printf("请输入地址\n");
					scanf("%s",&Q.address);
					printf("请输入工作地址\n");
					scanf("%s",&Q.workplace);
					printf("请输入他/她与您的关系\n");
					scanf("%s",&Q.type);
					printf("请输入固定电话\n");
					scanf("%d",&Q.GDtel);
					printf("请输入移动电话\n");
					scanf("%d",&Q.YDtel);
					printf("请输入QQ\n");
					scanf("%d",&Q.QQ);
				}
			}
				return head;
		}
		if(n==2)                         //从文件中获取信息；
		{	
			fp=fopen("D:\\a.txt","r");
			fscanf(fp,"%d",&z);
			for(i=0;i<z;i++)
			{
				p=(PTXL)malloc(sizeof(TXL));
				fscanf(fp,"%s",&p->name);
				fscanf(fp,"%s",&p->sex);
				fscanf(fp,"%s",&p->address);
				fscanf(fp,"%s",&p->email);
				fscanf(fp,"%d",&p->GDtel);
				fscanf(fp,"%d",&p->YDtel);
				fscanf(fp,"%d",&p->QQ);
				fscanf(fp,"%s",&p->workplace);
				fscanf(fp,"%s",&p->type);
				p->next=NULL;
				if(head==NULL)
					head=tail=p;
				else
				{
					tail->next=p;
					tail=p;
				}
			}
			fclose(fp);
			return head;
		}
}
void Output(PTXL S)                            //文件显示函数；
{
	int n,i;
	FILE *fp;
	PTXL p;
	p=S;
	printf("在页面显示请按1，在文件中显示请按2\n");
	scanf("%d",&n);
	if(n==1)                                 //在操作页面显示；
	{
		i=0;
		while(p)
		{
			i++;
			printf("姓名：%s ",p->name);
			printf("性别：%s ",p->sex);
			printf("移动电话:%d ",p->YDtel);
			printf("固定电话:%d ",p->GDtel);
			printf("QQ：%d ",p->QQ);
			printf("地址：%s ",p->address);
			printf("关系：%s ",p->type);
			printf("email：%s ",p->email);
			printf("工作地址：%s ",p->workplace);
			printf("\n");
			p=p->next;
			if(i%10==0)
			printf("-----------第%d页-------------\n",i/10);
		}
		printf("总共有%d个人的信息\n",i);
	}
	if(n==2)                              //在文档中显示；
	{
		i=0;
		if((fp=fopen("D:\\通讯录.txt","w"))==NULL)
		{ 
			printf("open the file error\n");
			return;
		}
		else
		{
			fp=fopen("D:\\通讯录.txt","w");
			while(p)
			{
				i++;
				fprintf(fp,"%s ",p->name);
				fprintf(fp,"%s ",p->sex);
				fprintf(fp,"%d ",p->YDtel);
				fprintf(fp,"%d ",p->GDtel);
				fprintf(fp,"%d ",p->QQ);
				fprintf(fp,"%s ",p->address);
				fprintf(fp,"%s ",p->type);
				fprintf(fp,"%s ",p->email);
				fprintf(fp,"%s ",p->workplace);
				fprintf(fp,"\n");
				p=p->next;
				if(i%10==0)
					fprintf(fp,"-----------第%d页-------------\n",i/10);
			}
			fprintf(fp,"总共有%d个人的信息\n",i);
			fclose(fp);
		}
	}
}
void Find(PTXL S)                              //信息查找函数；
{
	int a,b=1;
	TXL Q;
	PTXL p;
	while(b)
	{
		p=S;
		printf("您想通过什么来进行查找\n");
		printf("姓名请按1，性别请按2,关系请按3\n");
		scanf("%d",&a);
		switch(a)                            //选择查找类型进行查找；
		{
			case 1:
			{
				printf("输入您想查找的名字：\n");
				scanf("%s",&Q.name);
				while(p)
				{
					if(strcmp(p->name,Q.name)==0)
					{
						printf("%s的相关信息：\n",p->name);
						printf("性别是：%s\n",p->sex);
						printf("地址是%s\n",p->address);
						printf("QQ是:%d\n",p->QQ);
						printf("工作地址是：%s\n",p->workplace );
						printf("固定电话是：%d",p->GDtel);
						printf("移动电话是：%d",p->YDtel);
						printf("email是：%s\n",p->email);
						printf("\n");
						b=0;
					}
					p=p->next;
				}
				if(b==1)
					printf("未查询到此人，请重新输入\n");
				break;
			}
			case 2:
			{
				printf("输入您想查找的性别：\n");
				scanf("%s",&Q.sex);
				while(p)
				{
					if(strcmp(p->sex,Q.sex)==0)
					{
						printf("性别为%s的信息有：\n",Q.sex);
						printf("%s\n",p->name);
						b=0;
					}
					p=p->next;
				}
				if(b==1)
					printf("此性别没有信息，请重新输入\n");
					break;
			}
			case 3:
			{
				printf("请输入您想查找的关系\n");
				scanf("%s",&Q.type);
				while(p)
				{
					if(strcmp(p->type,Q.type)==0)
					{
						printf("关系为%s的信息有：\n",Q.type);
						printf("%s\n",p->name);
						b=0;
					}
					p=p->next;
				}
				if(b==1)
					printf("此关系没有信息，请重新输入\n");
					break;

			}
		}
	}
}
void Change(PTXL S)                            //信息更改函数；
{
	int m,n=0,a=1;
	TXL Q;
	PTXL p;
	p=S;
	printf("输入你想更改人的姓名\n");
	scanf("%s",&Q.name);
	while(p)
	{
		if(strcmp(p->name,Q.name)==0)
		{
			n=1;
			while(a)
			{
				printf("输入你想更改的信息或退出\n");
				printf("退出请按0\n");
				printf("更改请按：姓名1，性别2，地址3，工作地址4\n");
				printf("e_mail 5，跟您的关系6，移动电话7，固定电话8,  QQ 9\n");       
				scanf("%d",&m);
				switch(m)            //选择需要更改的信息进行更改；
				{
					case 0:
						break;
					case 1:
					{
						printf("输入更改后的姓名\n");
						scanf("%s",&Q.name);
						strcpy(p->name,Q.name);
						break;
					}
					case 2:
					{
						printf("输入更改后的性别\n");
						scanf("%s",&Q.sex);
						strcpy(p->sex,Q.sex);
						break;
					}
					case 3:
					{
						printf("输入更改后的地址\n");
						scanf("%s",&Q.address);
						strcpy(p->address,Q.address);
						break;
					}
					case 4:
					{
						printf("输入更改后的工作地址\n");
						scanf("%s",&Q.workplace);
						strcpy(p->workplace,Q.workplace);
						break;
					}
					case 5:
					{
						printf("输入更改后的e_mial\n");
						scanf("%s",&Q.email);
						strcpy(p->email,Q.email);
						break;
					}
					case 6:
					{
						printf("输入更改后的关系\n");
						scanf("%s",&Q.type);
						strcpy(p->type,Q.type);
						break;
					}
					case 7:
					{
						printf("输入更改后的移动电话\n");
						scanf("%d",&Q.YDtel);
						p->YDtel=Q.YDtel;
						break;
					}
					case 8:
					{
						printf("输入更改后的固定电话\n");
						scanf("%d",&Q.GDtel);
						p->GDtel=Q.GDtel;
						break;
					}
					case 9:
					{
						printf("输入更改后的Q\n");
						scanf("%d",&Q.QQ);
						p->QQ=Q.QQ;
						break;
					}
				}
				printf("是否继续更改此人信息？\n");
				printf("是请按1，否请按0\n");
				scanf("%d",&a);
				while(a!=1&&a!=0)
				{
					printf("请重新输入\n");
					scanf("%d",&a);
				}
			}
		}
		p=p->next;
	}
	if(n==0)
	{
		printf("查无此人，请重新输入\n");
		Change(S);                     //如果没有此人重新输入进行更改；
	}
}
PTXL Add(PTXL S)                       //信息添加函数；
{
	int m,a=1;
	TXL Q;
	PTXL p,f,r;
	f=p=S;
		f=(PTXL)malloc(sizeof(TXL));
		printf("输入你想添加的信息\n");
		printf("请输入姓名\n");
		scanf("%s",&Q.name);
		printf("请输入性别\n");
		scanf("%s",&Q.sex);
		printf("请输入Email\n");
		scanf("%s",&Q.email);
		printf("请输入地址\n");
		scanf("%s",&Q.address);
		printf("请输入工作地址\n");
		scanf("%s",&Q.workplace);
		printf("请输入他/她与您的关系\n");
		scanf("%s",&Q.type);
		printf("请输入固定电话\n");
		scanf("%d",&Q.GDtel);
		printf("请输入移动电话\n");
		scanf("%d",&Q.YDtel);
		printf("请输入QQ\n");
		scanf("%d",&Q.QQ);
		f->GDtel=Q.GDtel;
		f->YDtel=Q.YDtel;
		f->QQ=Q.QQ;
		strcpy(f->name,Q.name);
		strcpy(f->address,Q.address);
		strcpy(f->sex,Q.sex);
		strcpy(f->workplace,Q.workplace);
		strcpy(f->type,Q.type);
		strcpy(f->email,Q.email);
		if(S==NULL)
			S=f;
		else
		{
			while(p)
			{
				r=p;
				p=p->next;
			}
			r->next=f;
			f->next=p;
		}
		printf("继续添加请按1，退出请按0\n");
		scanf("%d",&a);
		if(a==1)
			Add(S);
	
}
PTXL Delete(PTXL *S)               //信息删除函数；
{
	int a=1;
	char name[10];
	PTXL p,q;
	while(a)
	{
		p=*S;
		printf("输入你想删除的名字\n");
		scanf("%s",&name);
		while(p!=NULL&&strcmp(p->name,name)!=0)
		{
			q=p;
			p=p->next;
		}
		if(p==*S)
			*S=p->next;
		else if(p==NULL)
		{
			printf("查无此人\n");
		}
		else
		{
			p=p->next;
			q->next=p;
		}
		printf("是否继续删除，继续请按1，退出请按0\n");
		scanf("%d",&a);
		return *S;
	}
}
void Welcome()
{
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("|                欢迎使用通讯系统                 |\n");
	printf("|          ***************************            |\n");
	printf("|          ***************************            |\n");
	printf("|          ***************************            |\n");
	printf("|          ***************************            |\n");
	printf("|          ***************************            |\n");
	printf("|          ***************************            |\n");
	printf("|                                                 |\n");
	printf("|                     ^_^                         |\n");
	printf("|                                                 |\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
}
void Choose()
{
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("|          ********1.信息输入*********            |\n");
	printf("|          ********2.信息输出*********            |\n");
	printf("|          ********3.信息查找*********            |\n");
	printf("|          ********4.信息更改*********            |\n");
	printf("|          ********5.信息添加*********            |\n");
	printf("|          ********6.信息删除*********            |\n");
	printf("|          ********7.退出系统*********            |\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
}
int main()
{
	int n,a,b=1,c=1,m=1;
	PTXL S;
	S=(PTXL)malloc(sizeof(TXL));
	Welcome();
	Choose();
	printf("请选择您要进行的操作\n");
	printf("请先输入通讯信息,请按1\n");
	while(b)
	{
		scanf("%d",&a);
		while(a!=1&&a!=2&&a!=3&&a!=4&&a!=5&&a!=6&&a!=7)
		{
			printf("输入有误，请重新输入\n");
			scanf("%d",&a);
		}
		switch(a)                          //输入按键进行操作选择；
		{

			case 1:
				{
					while(m)
					{
						printf("自己输入请按1，从文件中读取请按2\n");
						scanf("%d",&n);
						if(n==1)
							S=creat(n);
						if(n==2)
							S=creat(n);
						if(S==NULL)
							printf("请先输入或录用信息后进行下一步操作\n");
						if(S!=NULL)
							m=0;
						
					}
					printf("信息已经录用好,请选择下一步（2-7）\n");
					Choose();
					break;
				}
			case 2:
				{
					Output(S);
					printf("信息已显示，请选择下一步（2-7）\n");
					Choose();
					break;
				}
			case 3:
				{	
					Find(S);
					printf("信息查找完毕，请选择下一步（2-7）\n");
					Choose();
					break;
				}
			case 4:
				{
					Change(S);
					printf("信息更改完毕，请选择下一步（2-7）\n");
					Choose();
					break;
				}
			case 5:
				{
					Add(S);
					printf("信息添加完毕，请选择下一步（2-7）\n");
					Choose();
					break;
				}
			case 6:
				{
					Delete(&S);
					printf("信息删除完毕，请选择下一步（2-7）\n");
					Choose();
					break;
				}
			case 7:
				{
					b=0;
					printf("谢谢使用，再见\n");
					break;
				}
		}	
	}	
}