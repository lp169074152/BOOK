#include <stdio.h>
#include <stdlib.h>
typedef struct node                           //����ͨѶ¼��Ҫ�Ľṹ�����ͣ�
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
struct node *creat(int n)                         //��Ϣ¼�ú�����
{
		int m,z,i;
		PTXL head=NULL,tail=NULL,p;
		FILE *fp;
		TXL Q;
		printf("��������밴1���������밴0\n");
		scanf("%d",&m);
		if(m==0)
		{
				printf("δ¼ȡ�κ���Ϣ\n");
				return NULL;
		}
		if(n==1)                                //�ֶ�������Ϣ��
		{
			printf("����������\n");
			scanf("%s",&Q.name);
			printf("�������Ա�\n");
			scanf("%s",&Q.sex);
			printf("������Email\n");
			scanf("%s",&Q.email);
			printf("�������ַ\n");
			scanf("%s",&Q.address);
			printf("�����빤����ַ\n");
			scanf("%s",&Q.workplace);
			printf("��������/�������Ĺ�ϵ\n");
			scanf("%s",&Q.type);
			printf("������̶��绰\n");
			scanf("%d",&Q.GDtel);
			printf("�������ƶ��绰\n");
			scanf("%d",&Q.YDtel);
			printf("������QQ\n");
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
				printf("�Ƿ����������һ���˵���Ϣ��\n");
				printf("�����밴1���˳��밴0\n");
				scanf("%d",&m);
				if(m==1)
				{
					printf("����������\n");
					scanf("%s",&Q.name);
					printf("�������Ա�\n");
					scanf("%s",&Q.sex);
					printf("������Email\n");
					scanf("%s",&Q.email);
					printf("�������ַ\n");
					scanf("%s",&Q.address);
					printf("�����빤����ַ\n");
					scanf("%s",&Q.workplace);
					printf("��������/�������Ĺ�ϵ\n");
					scanf("%s",&Q.type);
					printf("������̶��绰\n");
					scanf("%d",&Q.GDtel);
					printf("�������ƶ��绰\n");
					scanf("%d",&Q.YDtel);
					printf("������QQ\n");
					scanf("%d",&Q.QQ);
				}
			}
				return head;
		}
		if(n==2)                         //���ļ��л�ȡ��Ϣ��
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
void Output(PTXL S)                            //�ļ���ʾ������
{
	int n,i;
	FILE *fp;
	PTXL p;
	p=S;
	printf("��ҳ����ʾ�밴1�����ļ�����ʾ�밴2\n");
	scanf("%d",&n);
	if(n==1)                                 //�ڲ���ҳ����ʾ��
	{
		i=0;
		while(p)
		{
			i++;
			printf("������%s ",p->name);
			printf("�Ա�%s ",p->sex);
			printf("�ƶ��绰:%d ",p->YDtel);
			printf("�̶��绰:%d ",p->GDtel);
			printf("QQ��%d ",p->QQ);
			printf("��ַ��%s ",p->address);
			printf("��ϵ��%s ",p->type);
			printf("email��%s ",p->email);
			printf("������ַ��%s ",p->workplace);
			printf("\n");
			p=p->next;
			if(i%10==0)
			printf("-----------��%dҳ-------------\n",i/10);
		}
		printf("�ܹ���%d���˵���Ϣ\n",i);
	}
	if(n==2)                              //���ĵ�����ʾ��
	{
		i=0;
		if((fp=fopen("D:\\ͨѶ¼.txt","w"))==NULL)
		{ 
			printf("open the file error\n");
			return;
		}
		else
		{
			fp=fopen("D:\\ͨѶ¼.txt","w");
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
					fprintf(fp,"-----------��%dҳ-------------\n",i/10);
			}
			fprintf(fp,"�ܹ���%d���˵���Ϣ\n",i);
			fclose(fp);
		}
	}
}
void Find(PTXL S)                              //��Ϣ���Һ�����
{
	int a,b=1;
	TXL Q;
	PTXL p;
	while(b)
	{
		p=S;
		printf("����ͨ��ʲô�����в���\n");
		printf("�����밴1���Ա��밴2,��ϵ�밴3\n");
		scanf("%d",&a);
		switch(a)                            //ѡ��������ͽ��в��ң�
		{
			case 1:
			{
				printf("����������ҵ����֣�\n");
				scanf("%s",&Q.name);
				while(p)
				{
					if(strcmp(p->name,Q.name)==0)
					{
						printf("%s�������Ϣ��\n",p->name);
						printf("�Ա��ǣ�%s\n",p->sex);
						printf("��ַ��%s\n",p->address);
						printf("QQ��:%d\n",p->QQ);
						printf("������ַ�ǣ�%s\n",p->workplace );
						printf("�̶��绰�ǣ�%d",p->GDtel);
						printf("�ƶ��绰�ǣ�%d",p->YDtel);
						printf("email�ǣ�%s\n",p->email);
						printf("\n");
						b=0;
					}
					p=p->next;
				}
				if(b==1)
					printf("δ��ѯ�����ˣ�����������\n");
				break;
			}
			case 2:
			{
				printf("����������ҵ��Ա�\n");
				scanf("%s",&Q.sex);
				while(p)
				{
					if(strcmp(p->sex,Q.sex)==0)
					{
						printf("�Ա�Ϊ%s����Ϣ�У�\n",Q.sex);
						printf("%s\n",p->name);
						b=0;
					}
					p=p->next;
				}
				if(b==1)
					printf("���Ա�û����Ϣ������������\n");
					break;
			}
			case 3:
			{
				printf("������������ҵĹ�ϵ\n");
				scanf("%s",&Q.type);
				while(p)
				{
					if(strcmp(p->type,Q.type)==0)
					{
						printf("��ϵΪ%s����Ϣ�У�\n",Q.type);
						printf("%s\n",p->name);
						b=0;
					}
					p=p->next;
				}
				if(b==1)
					printf("�˹�ϵû����Ϣ������������\n");
					break;

			}
		}
	}
}
void Change(PTXL S)                            //��Ϣ���ĺ�����
{
	int m,n=0,a=1;
	TXL Q;
	PTXL p;
	p=S;
	printf("������������˵�����\n");
	scanf("%s",&Q.name);
	while(p)
	{
		if(strcmp(p->name,Q.name)==0)
		{
			n=1;
			while(a)
			{
				printf("����������ĵ���Ϣ���˳�\n");
				printf("�˳��밴0\n");
				printf("�����밴������1���Ա�2����ַ3��������ַ4\n");
				printf("e_mail 5�������Ĺ�ϵ6���ƶ��绰7���̶��绰8,  QQ 9\n");       
				scanf("%d",&m);
				switch(m)            //ѡ����Ҫ���ĵ���Ϣ���и��ģ�
				{
					case 0:
						break;
					case 1:
					{
						printf("������ĺ������\n");
						scanf("%s",&Q.name);
						strcpy(p->name,Q.name);
						break;
					}
					case 2:
					{
						printf("������ĺ���Ա�\n");
						scanf("%s",&Q.sex);
						strcpy(p->sex,Q.sex);
						break;
					}
					case 3:
					{
						printf("������ĺ�ĵ�ַ\n");
						scanf("%s",&Q.address);
						strcpy(p->address,Q.address);
						break;
					}
					case 4:
					{
						printf("������ĺ�Ĺ�����ַ\n");
						scanf("%s",&Q.workplace);
						strcpy(p->workplace,Q.workplace);
						break;
					}
					case 5:
					{
						printf("������ĺ��e_mial\n");
						scanf("%s",&Q.email);
						strcpy(p->email,Q.email);
						break;
					}
					case 6:
					{
						printf("������ĺ�Ĺ�ϵ\n");
						scanf("%s",&Q.type);
						strcpy(p->type,Q.type);
						break;
					}
					case 7:
					{
						printf("������ĺ���ƶ��绰\n");
						scanf("%d",&Q.YDtel);
						p->YDtel=Q.YDtel;
						break;
					}
					case 8:
					{
						printf("������ĺ�Ĺ̶��绰\n");
						scanf("%d",&Q.GDtel);
						p->GDtel=Q.GDtel;
						break;
					}
					case 9:
					{
						printf("������ĺ��Q\n");
						scanf("%d",&Q.QQ);
						p->QQ=Q.QQ;
						break;
					}
				}
				printf("�Ƿ�������Ĵ�����Ϣ��\n");
				printf("���밴1�����밴0\n");
				scanf("%d",&a);
				while(a!=1&&a!=0)
				{
					printf("����������\n");
					scanf("%d",&a);
				}
			}
		}
		p=p->next;
	}
	if(n==0)
	{
		printf("���޴��ˣ�����������\n");
		Change(S);                     //���û�д�������������и��ģ�
	}
}
PTXL Add(PTXL S)                       //��Ϣ��Ӻ�����
{
	int m,a=1;
	TXL Q;
	PTXL p,f,r;
	f=p=S;
		f=(PTXL)malloc(sizeof(TXL));
		printf("����������ӵ���Ϣ\n");
		printf("����������\n");
		scanf("%s",&Q.name);
		printf("�������Ա�\n");
		scanf("%s",&Q.sex);
		printf("������Email\n");
		scanf("%s",&Q.email);
		printf("�������ַ\n");
		scanf("%s",&Q.address);
		printf("�����빤����ַ\n");
		scanf("%s",&Q.workplace);
		printf("��������/�������Ĺ�ϵ\n");
		scanf("%s",&Q.type);
		printf("������̶��绰\n");
		scanf("%d",&Q.GDtel);
		printf("�������ƶ��绰\n");
		scanf("%d",&Q.YDtel);
		printf("������QQ\n");
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
		printf("��������밴1���˳��밴0\n");
		scanf("%d",&a);
		if(a==1)
			Add(S);
	
}
PTXL Delete(PTXL *S)               //��Ϣɾ��������
{
	int a=1;
	char name[10];
	PTXL p,q;
	while(a)
	{
		p=*S;
		printf("��������ɾ��������\n");
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
			printf("���޴���\n");
		}
		else
		{
			p=p->next;
			q->next=p;
		}
		printf("�Ƿ����ɾ���������밴1���˳��밴0\n");
		scanf("%d",&a);
		return *S;
	}
}
void Welcome()
{
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("|                ��ӭʹ��ͨѶϵͳ                 |\n");
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
	printf("|          ********1.��Ϣ����*********            |\n");
	printf("|          ********2.��Ϣ���*********            |\n");
	printf("|          ********3.��Ϣ����*********            |\n");
	printf("|          ********4.��Ϣ����*********            |\n");
	printf("|          ********5.��Ϣ���*********            |\n");
	printf("|          ********6.��Ϣɾ��*********            |\n");
	printf("|          ********7.�˳�ϵͳ*********            |\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
}
int main()
{
	int n,a,b=1,c=1,m=1;
	PTXL S;
	S=(PTXL)malloc(sizeof(TXL));
	Welcome();
	Choose();
	printf("��ѡ����Ҫ���еĲ���\n");
	printf("��������ͨѶ��Ϣ,�밴1\n");
	while(b)
	{
		scanf("%d",&a);
		while(a!=1&&a!=2&&a!=3&&a!=4&&a!=5&&a!=6&&a!=7)
		{
			printf("������������������\n");
			scanf("%d",&a);
		}
		switch(a)                          //���밴�����в���ѡ��
		{

			case 1:
				{
					while(m)
					{
						printf("�Լ������밴1�����ļ��ж�ȡ�밴2\n");
						scanf("%d",&n);
						if(n==1)
							S=creat(n);
						if(n==2)
							S=creat(n);
						if(S==NULL)
							printf("���������¼����Ϣ�������һ������\n");
						if(S!=NULL)
							m=0;
						
					}
					printf("��Ϣ�Ѿ�¼�ú�,��ѡ����һ����2-7��\n");
					Choose();
					break;
				}
			case 2:
				{
					Output(S);
					printf("��Ϣ����ʾ����ѡ����һ����2-7��\n");
					Choose();
					break;
				}
			case 3:
				{	
					Find(S);
					printf("��Ϣ������ϣ���ѡ����һ����2-7��\n");
					Choose();
					break;
				}
			case 4:
				{
					Change(S);
					printf("��Ϣ������ϣ���ѡ����һ����2-7��\n");
					Choose();
					break;
				}
			case 5:
				{
					Add(S);
					printf("��Ϣ�����ϣ���ѡ����һ����2-7��\n");
					Choose();
					break;
				}
			case 6:
				{
					Delete(&S);
					printf("��Ϣɾ����ϣ���ѡ����һ����2-7��\n");
					Choose();
					break;
				}
			case 7:
				{
					b=0;
					printf("ллʹ�ã��ټ�\n");
					break;
				}
		}	
	}	
}