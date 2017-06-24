/**--------------File Info---------------------------------------------------------------------------------
** File name:               led_display_cfg.h
** Latest modified Date:    2017-6-24(����Ϣ)
** Latest Version:          1.0
** Descriptions:           ͼ�����ϵͳ
**
**--------------------------------------------------------------------------------------------------------
** Created by:              lizexin��GitHub  id: FirendSaber��
** Created date:             2016����һ��ѧ�ڹ���ʵ����
** Version:                 1.0
** Descriptions:            The original version
**
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
** Version:
** Descriptions:
**
*********************************************************************************************************/

#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#include<time.h> 

#define  LEN sizeof(Books_style) 



//��Ա��Ϣ 
typedef struct HUIYUAN
{
	char zhanghao[20];//�˺� 
	char mima[12]; //���� 
	char jyqingkuang[3];//������� 
	double  date_jine; //���ڽ��
	int  jieyueshu;
}HUIY_data;

//ͼ����Ϣ 
typedef struct BOOK
{	
	char num[10];/*���*/
	char name[20];/*����*/
	char author[12];/*����*/		
	char zhanghao1[20];//������
	char zhuangtai[4];//�������
	double yuqimoney;//���ڽ��

	int  cishu;

	struct BOOK *next;
}Books_style;

struct shijian
{
    int nian;
	int yue;
	int ri;
};


void guanliyuan();
void Huiyuan();
void zhuce();
void denglu();
void chajian(char str[],int di);
void show_menu();//��ʾ���˵�
void Show_ALL();//��ʾ�ı����ݣ����ļ�Ϊ�ռ���ӣ�ģ��1��
Books_style *creat();//��������
void input();//Ϊ�ļ�Ϊ��ʱ�����ļ�������ݣ���Ӵ������������ݣ�
void output();//���ļ���ȡ����Ļ��ʾ�ļ����ݣ�����ѯ
void Turn_menu();//ҳ����ת����
void Turn_menu1();//��ʾ����Ա����
void Turn_menu2(char str[],int di);//��¼��ע�����
void Turn_menu3();//��Ա����
void Add_Book();
void Modofy_Book();
void Query_Book();
void Delete_Book();
void fondpaixu_Book();
void lent_book(char str[],int di);
void back_Book(char str[],int di);
void huiyuan_list();
void zhuangt_Book();
void jyqkuang_Book();
void jieyue_Book(char string[],int n);
void jilutime(int n);
void jilutime2();
void jilutime3();
double yuqifond_Book(int n);
void xiugaimima(int n);
void xiugaimima2();
void xianshi();

Books_style *rep;
HUIY_data huiyuan[100];
int r=1;
int shu=0,shu1=0;
struct shijian   first[20],second;


int main()
{

	show_menu();
	
	return 0;
}
//���˵�
void show_menu()
{
	int g,jishu=0;
	
	strcpy(huiyuan[0].zhanghao,"root");
	strcpy(huiyuan[0].mima,"123456");
	system("cls");
	printf("\n\n\t||=======================================||");
	printf("\n\t||     1.�Թ���Ա����ݽ���              ||");
	printf("\n\t||     2.�Ի�Ա����ݽ���                ||");
	printf("\n\t||     3.�˳�                            ||");
	printf("\n\t||=======================================||");
	
	printf("\n���������ѡ��1-3��:");
	scanf("%d",&g);
	
	while(g>3||g<1)
	{	
		printf("����������(1-3):");
		scanf("%d",&g);
		
	}
	switch(g)
	{
		case 1:guanliyuan();break;
		case 2:Huiyuan();break;
		case 3:exit(0);
		default:break;
		
	} 
	Turn_menu();
}


void guanliyuan()
{
	int n;
	system("cls");
		printf("\n\n\t||==================================================||\n");
		printf("\t||            ��ӭ��������ͼ����                    ||\n");
		printf("\t||==================================================||\n");
		printf("\t||		1-��ʾ����                          ||\n");
		printf("\t||		2-���ͼ��                          ||\n");
		printf("\t||		3-�޸�ͼ��                          ||\n");
		printf("\t||		4-ɾ��ͼ��                          ||\n");
		printf("\t||		5-�鼮״̬                          ||\n");
		printf("\t||		6-�������                          ||\n");
		printf("\t||		7-���ڷ���                          ||\n");
		printf("\t||		8-��Ա����                          ||\n");
		printf("\t||		9-�޸�����                          ||\n");
		printf("\t||		10-�˳�                             ||\n");
		printf("\t||==================================================||\n");
		printf("\n���������ѡ��1-10��:");
		scanf("%d",&n);
		
		while(n>10||n<1)
		{	
			printf("����������(1-10):");
			scanf("%d",&n);
		
		}


		switch(n)
		{
			case 1:
				Show_ALL();/*������ʾ����ͼ��Ĺ���*/
				break;
			case 2:
				Add_Book();/*���ͼ����Ϣ*/
				break;
			case 3:
				Modofy_Book();/*�޸�ͼ����Ϣ*/
				break;
			case 4:
				Delete_Book();/*ɾ��ͼ����Ϣ*/
				break;
			case 5:
				zhuangt_Book();/*�鼮״̬ͳ��*/
				break;
			case 6:
				jyqkuang_Book();/*�����������10*/
				break;
			case 7:
				fondpaixu_Book();/*���ڷ�������5*/
				break;
			case 8:
				huiyuan_list();/*��Ա����*/
				break;
			case 9:
				xiugaimima2();/*�޸�����*/
				break;
			case 10:
				Turn_menu();/*�˳�*/
			default:break;
		
		}		
		Turn_menu1();
}




//***********************************************************************************************************************************************************//
void Show_ALL()
{
	char ch;

	
	FILE *fp;
	fp=fopen("F:\\Booklist.txt","r");

	printf("||===================================================||\n");
	printf("||                ��ʾͼ����Ϣ                       ||\n");
	printf("||===================================================||\n");
	
	if(fp==NULL)
	{
		printf("------------------ͼ���б�����Ϊ�գ�--------\n");
		printf("------------------�Ƿ����ͼ�飿Y/N:");
		
		scanf("%c",&ch);
		//���Զ����ɻ��з�
		scanf("%c",&ch);
		while(ch!='Y'&&ch!='y'&&ch!='N'&&ch!='n')
		{
			
				printf("\n���������루Y/N��:");
				scanf("%c",&ch);
				scanf("%c",&ch);
				
		}
				if(ch=='Y'||ch=='y')
				{
					printf("----------------�������ͼ��---------------\n");
					rep=creat();
					input();
				}

				else if(ch=='N'||ch=='n')
				{
					Turn_menu1();
				}
		
	}
	if(fp!=NULL)
	{
		printf("\n-----------------ͼ���б�����-----------------\n\n");
		printf("���\t\t����\t\t\t����\t\t�鼮״̬\t������\n");
		output();	/*��ʾ�ļ�����*/
		Turn_menu1();
	}

}

// (1)   ��������
Books_style *creat()
{
	Books_style *head;
	Books_style *p1,*p2;
	
	
	head=NULL;

	
	printf("������������Ϣ�ԡ�0 0 0������\n");
	printf("���\t����\t����\n");
	

	p1=p2=(Books_style *)malloc(LEN);
	scanf("%s %s %s",p2->num,p2->name,p2->author);	
	strcpy(p2->zhuangtai,"�ɽ� ");
	strcpy(p2->zhanghao1,"        ");
	
	p2->cishu=0;
	shu++;
	while( strcmp(p2->name,"0")!=0  ||strcmp(p2->num,"0")!=0|| strcmp(p2->author,"0")!=0)
	{	
		if(head==NULL)
		{
			head=p2;
			
		}
		else
		{
			p1->next=p2;
		}
		p1=p2;
		p2=(Books_style *)malloc(LEN);
		scanf("%s %s %s",p2->num,p2->name,p2->author);
		strcpy(p2->zhuangtai,"�ɽ�");
		strcpy(p2->zhanghao1," ");
		
		p2->cishu=0;
		shu++;
	}
	p1->next=NULL;
	free(p2);
	
	return head;
}



//  (2)    (����������д���ı�)
void input()/*��������ݲ�����*/
{
	FILE *fp;
	Books_style *p1=rep;
	

	if((fp=fopen("F:\\Booklist.txt","w"))==NULL)
	{
		printf("�����ı�ʧ�ܣ�");
		exit(0);
	}
		for(;p1->next!=NULL;p1=p1->next)
		{
				
				fprintf(fp,"%-8s\t%-20s\t%-12s\t%-4s\t%-10s\n",p1->num,p1->name,p1->author,p1->zhuangtai,p1->zhanghao1);
			
			
			if(ferror(fp))
			{
				printf("����������������д�");
				exit(1);
			}
		}
		//��ʱp1�����ݻ�δ���룬��������������
	
		fprintf(fp,"%-8s\t%-20s\t%-12s\t%-4s\t%-10s\n",p1->num,p1->name,p1->author,p1->zhuangtai,p1->zhanghao1);
		

		fclose(fp);
		
		
}


// (3)    ���ļ����������ʾ����Ļ��   
void output()
{
		FILE *out;
		char ch;

		if((out=fopen("F:\\Booklist.txt","r"))==NULL)
		{
			printf("���ı�ʧ�ܣ�");
			Turn_menu1();
		}
		
		while(!feof(out))
		{
			ch=fgetc(out);
			putchar(ch);
			
		}

		fclose(out);
}

//  (4)    ��תҳ������,ѯ���Ƿ�����������
void Turn_menu()
{
	char ch2;

	printf("\n----------------�Ƿ񷵻���һ��?(Y/N) :");
	scanf("%c",&ch2);
	scanf("%c",&ch2);

	while(ch2!='Y'&&ch2!='y'&&ch2!='N'&&ch2!='n')
	{
		printf("���������루Y/N��:");
		scanf("%c",&ch2);
		scanf("%c",&ch2);
	}	

	if(ch2=='Y'||ch2=='y')
	{
		show_menu();
	}
	if(ch2=='N'||ch2=='n')
	{
		printf("------------------�˳�ϵͳ!---------------------\n");
		exit(0);			
	}
  	
}
void Turn_menu1()
{
	char ch2;


	printf("\n----------------�Ƿ񷵻���һ��?(Y/N) :");
	scanf("%c",&ch2);
	scanf("%c",&ch2);


	while(ch2!='Y'&&ch2!='y'&&ch2!='N'&&ch2!='n')
	{
		printf("���������루Y/N��:");
		scanf("%c",&ch2);
		
	}	

	if(ch2=='Y'||ch2=='y')
	{
		guanliyuan();
	}
	if(ch2=='N'||ch2=='n')
	{
		printf("------------------�˳�ϵͳ!---------------------\n");
		exit(0);			
	}
  	
}
void Turn_menu2(char str[],int di)
{
	char ch2;

	printf("\n----------------�Ƿ񷵻���һ��?(Y/N) :");
	scanf("%c",&ch2);
	scanf("%c",&ch2);

	while(ch2!='Y'&&ch2!='y'&&ch2!='N'&&ch2!='n')
	{
		printf("���������루Y/N��:");
		scanf("%c",&ch2);
		scanf("%c",&ch2);
	}	

	if(ch2=='Y'||ch2=='y')
	{
		chajian(str,di);
	}
	if(ch2=='N'||ch2=='n')
	{
		printf("------------------�˳�ϵͳ!---------------------\n");
		exit(0);			
	}
  	
}

void Turn_menu3()
{
	char ch2;

	printf("\n----------------�Ƿ񷵻���һ��?(Y/N) :");
	scanf("%c",&ch2);
	scanf("%c",&ch2);

	while(ch2!='Y'&&ch2!='y'&&ch2!='N'&&ch2!='n')
	{
		printf("���������루Y/N��:");
		scanf("%c",&ch2);
		scanf("%c",&ch2);
	}	

	if(ch2=='Y'||ch2=='y')
	{
		Huiyuan();
	}
	if(ch2=='N'||ch2=='n')
	{
		printf("------------------�˳�ϵͳ!---------------------\n");
		exit(0);			
	}
  	
}

//***********************************************************************************************************************************************************//


//���ͼ��
void Add_Book()
{
	Books_style *p=rep;
	Books_style *B;
	Books_style *t=rep;

	printf("||===================================================||\n");
	printf("||                ���ͼ����Ϣ                       ||\n");
	printf("||===================================================||\n");

	printf("----------������Ҫ���ı���ӵ�����-----------------\n");
	B=creat();

	if (rep==NULL)//A����Ϊ�յ��������bhead����ahead,ʹ��ʼ��ַ��ȻΪahead(��bhead)��
	{
		rep=B;
	}
	else 
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		
		p->next = B;//B����A
	}

	input();
	printf("\n-------------��ӵ��ļ��ɹ�!-----------------------\n");
	printf("\n  ��ܰ��ʾ:�������ϼ����Ұ�1���ɲ鿴ȫ�ĺ͸���ӵ�����------------\n");
	
} 

//***********************************************************************************************************************************************************//

//�޸�ͼ�� 
void Modofy_Book()
{
	
	int n;
	Books_style Mod_data;

	char num1[10],name1[20],author1[10];
	Books_style  *p=rep;


	int flag=0;
	

	
	printf("||===================================================||\n");
	printf("||                �޸�ͼ����Ϣ                       ||\n");
	printf("||===================================================||\n");

	printf("\n   ----------ԭͼ����Ϣ����------------\n");
	output();

	printf("||==========================================||\n");
	printf("  ||                                          ||\n");
	printf("  || 1��������޸�                            ||\n");
	printf("  || 2���������޸�                            ||\n");
	printf("  ||                                          ||\n");
	printf("  ||==========================================||\n");

	
	printf("\n���������ѡ��1-2��:");
	scanf("%d",&n);
	while(n>2||n<1)
	{	
		printf("����������(1-2):");
		scanf("%d",&n);
	
	}
	
	if(n==1)
	{
		printf("����������Ҫ�޸�ͼ�����ţ�");
		scanf("%s",Mod_data.num);
			
		while (p != NULL)
		{
			if(strcmp(Mod_data.num,p->num)==0)
			{
				flag=1;
				printf("�������Ȿ���޸Ĺ��������:\n");
				printf("��ţ�\n");
				scanf("%s",num1);
				strcpy(p->num,num1);
				printf("������\n");
				scanf("%s",name1);
				strcpy(p->name,name1);
				printf("���ߣ�\n");
				scanf("%s",author1);
				strcpy(p->author,author1);
			}
			p = p->next;
		}	
	}
	p=rep;
	if(n==2)
	{
		printf("����������Ҫ�޸�ͼ���������");
		scanf("%s",Mod_data.name);

		while (p != NULL)
		{
			
			if(strcmp(Mod_data.name,p->name)==0)
			{
				
				flag=1;
				printf("�������Ȿ���޸Ĺ��������:\n");
				printf("��ţ�\n");
				scanf("%s",num1);
				strcpy(p->num,num1);
				printf("������\n");
				scanf("%s",name1);
				strcpy(p->name,name1);
				printf("���ߣ�\n");
				scanf("%s",author1);
				strcpy(p->author,author1);
			}
			p = p->next;
		}
		
	
	}
		if(flag==0)
		{
			printf("û���ҵ���");
		}
		else
		{
			printf("�޸ĺ�Ľ�����£�\n");
			input();
			output();
		}

}


//***********************************************************************************************************************************************************//
//ɾ��ͼ��
void Delete_Book()
{
	int n;
	int flag=0;
	char num2[10],name2[20];
	Books_style  *p=rep;
	Books_style  *p1;

	printf("\n   ----------ԭͼ����Ϣ����------------\n");
	output();

	printf("||==========================================||\n");
	printf("  ||                                          ||\n");
	printf("  || 1�������ɾ��                            ||\n");
	printf("  || 2��������ɾ��                            ||\n");
	printf("  ||                                          ||\n");
	printf("  ||==========================================||\n");

	
	printf("\n���������ѡ��1-2��:");
	scanf("%d",&n);
	while(n>2||n<1)
	{	
		printf("����������(1-2):");
		scanf("%d",&n);
	
	}

	if(n==1)
	{
		printf("����������Ҫɾ����ͼ�����ţ�");
		scanf("%s",num2);
			
		if(strcmp(num2,rep->num)==0)
		{
			flag=1;
			rep=rep->next;
		}
			else
		{
			while((strcmp(num2,p->num)!=0) && p != NULL)
			{
				p1=p;
				p = p->next;
			}	
			flag=1;
			p1->next = p->next;
		}
	}
	p=rep;
	if(n==2)
	{
		printf("����������Ҫɾ����ͼ���������");
		scanf("%s",name2);
		
		if(strcmp(name2,p->name)==0)
		{
			flag=1;
			rep=rep->next;
		}
		else
		{
			while((strcmp(name2,p->name)!=0) && p != NULL)
			{
				p1=p;
				p = p->next;
			}	
			flag=1;
			p1->next= p->next;
		}		
	}
	
	if(flag==0)
	{
		printf("û���ҵ���");	
	}	
	else
		{
			printf("�޸ĺ�Ľ�����£�\n");
			input();
			output();
		}
}

//��Ա�嵥
void huiyuan_list()
{
	int te;
	
	printf("\n����%dλ��Ա\n",r);
	printf("��Ա��:root\t\t����:123456\n");
	for(te=1;te<r;te++)
	{
		printf("��Ա��:%s\t\t����:%s\n",huiyuan[te].zhanghao,huiyuan[te].mima);
	}

}

//״̬���
void zhuangt_Book()
{

	printf("\n\n\t�ݲ��鼮����(��)\t�ѽ������(��)\t�ڹ��鼮��(��)\n");
	printf("\t%d\t%d\t%d",shu,shu1,shu-shu1);

}

//�����������
void jyqkuang_Book()
{
	Books_style  *p=rep;
	Books_style  paixu[100];
	int ci=0,su=0,tu=0,ku=0,t,kawei=0;
	char string[20];

	while(p!=NULL)
	{

		strcpy(paixu[ci].num,p->num);/*���*/
		strcpy(paixu[ci].name,p->name);/*����*/
		strcpy(paixu[ci].author,p->author);/*����*/		
		strcpy(paixu[ci].zhuangtai,p->zhuangtai); //������� 
		paixu[ci].cishu=p->cishu;
		p=p->next;
		ci++;
	}
	ci--;
	for(su=0;su<ci-1;su++)
	{   ku=su;
		for(tu=su+1;tu<ci;tu++)
		if(paixu[tu].cishu>paixu[ku].cishu)
	 	ku=tu;
		if(ku!=su)
		{t=paixu[su].cishu;paixu[su].cishu=paixu[ku].cishu;paixu[ku].cishu=t;
		strcpy(string,paixu[su].num);strcpy(paixu[su].num,paixu[ku].num);strcpy(paixu[ku].num,string);
		strcpy(string,paixu[su].name);strcpy(paixu[su].name,paixu[ku].name);strcpy(paixu[ku].name,string);
		strcpy(string,paixu[su].author);strcpy(paixu[su].author,paixu[ku].author);strcpy(paixu[ku].author,string);}	
	}

	printf("\n------------------����������а�------------------\n");
	printf("\t���\t\t����\t\t\t����\t\t�����Ĵ���\n");
	for(su=0;su<ci;su++)
	{
		if(kawei>=10)
		break;
		
		
		printf("\t%-8s\t%-20s\t%-12s\t%d\n",paixu[su].num,paixu[su].name,paixu[su].author,paixu[su].cishu);
		kawei++;
	}

}

//���ڽ������
void fondpaixu_Book()
{
	int su,ku,tu;
	double t;
	int kawei=0;
	char string[20];
	printf("\n\t------------------���ڽ�����а�----------------------\n");
	for(su=0;su<r-1;su++)
	{   ku=su;
		for(tu=su+1;tu<r;tu++)
		if(huiyuan[tu].date_jine>huiyuan[ku].date_jine)
	 	ku=tu;
		if(ku!=su)
		{t=huiyuan[su].date_jine;huiyuan[su].date_jine=huiyuan[ku].date_jine;huiyuan[ku].date_jine=t;
		strcpy(string,huiyuan[su].zhanghao);strcpy(huiyuan[su].zhanghao,huiyuan[ku].zhanghao);strcpy(huiyuan[ku].zhanghao,string);
		}	
	}
	printf("\n\t������\t\t���ڽ��\n");
	for(su=0;su<r;su++)
	{
		if(kawei>=5)
		break;		
		
		printf("\t%s\t\t%d\n",huiyuan[su].zhanghao,huiyuan[su].date_jine);
		kawei++;
	}
	

}


//�޸��˺�����
void xiugaimima2()
{

	int jishu=0,i;
	char mima2[12],zhanghao1[20];
	int keep=0;
	int flag=1;

	printf("�˺�:");
	scanf("%s",zhanghao1);
	for(i=0;i<r;i++)
	{
		if(strcmp(zhanghao1,huiyuan[i].zhanghao)==0)
		{		
			flag=0	;	
			printf("�����룺");
			scanf("%s",huiyuan[i].mima);
			printf("�ٴ��������룺");
			scanf("%s",mima2);
			while(strcmp(mima2,huiyuan[i].mima)!=0)
			{
				keep++;
				printf("\n�������벻һ��!\n");
				printf("�ٴ��������룺");
				scanf("%s",mima2);
				if(keep>3)
				{
					printf("��������������Զ��˳�");
					Turn_menu3();
				}
			}
			printf("\n\n--------------�޸ĳɹ���--------------------\n\n");
		}
	
	}
	if(flag==1)
	{
		printf("û�и��˺ţ�");
	}
			
}



//***********************************************************************************************************************************************************//
//***********************************************************************************************************************************************************//
//��Ա��Ϣ
void Huiyuan()
{
	int gt;
	
	
	system("cls");
		printf("\n\n\t--------------��ӭ�����¼ҳ��---------------\n\n");
		printf("\n\t||=======================================||");
		printf("\n\t||     1.��¼                            ||");
		printf("\n\t||     2.ע��                            ||");
		printf("\n\t||     3.�˳�                            ||");
		printf("\n\t||=======================================||");
		printf("\n���������ѡ��1-3��:");
			scanf("%d",&gt);
			while(gt>3||gt<1)
			{	
				printf("����������(1-3):");
				scanf("%d",&gt);
			}
			switch(gt)
			{
				case 1:
					denglu();/*��¼*/
					break;
				case 2:
					zhuce();/*ע��*/
					break;
				case 3:
					Turn_menu();/*�˳�*/	
			}
		
		Turn_menu3();
		
		
}
void denglu()
{

	int i;
	char zhanghao1[20],mima1[12];
	int jishu=0,flag=1;
		
	printf("%d",r);
	for(i=0;i<r;i++)
	{
		printf("%s",huiyuan[i].zhanghao);
		printf("\t%s",huiyuan[i].mima);
		printf("\n");
	}
	printf("�˺�:");
	scanf("%s",zhanghao1);
	for(i=0;i<r;i++)
	{
		if(strcmp(zhanghao1,huiyuan[i].zhanghao)==0)
		{	flag=0;
			printf("����:");
			scanf("%s",mima1);

			while(strcmp(mima1,huiyuan[i].mima)!=0)
			{
				printf("�������������룺\n");
				scanf("%s",mima1);
				jishu++;
				if(jishu==3)
				{
					printf("\n\n----------------���������������!----------------------\n");
					Turn_menu();
				}
			}		
		}					
	
	}
	i--;
	if(flag==1)
	{
		printf("û�и��˺ţ�");
	}
	else
		chajian(zhanghao1,i);
}

void chajian(char str[],int di)
{
	int n;
	system("cls");
			printf("\n\n\t||==================================================||\n");
			printf("\t||            ��ӭ��������ͼ����                    ||\n");
			printf("\t||==================================================||\n");
			printf("\t||		1-��ʾ����                          ||\n");
			printf("\t||		2-��ѯͼ��                          ||\n");
			printf("\t||		3-����ͼ��                          ||\n");
			printf("\t||		4-�黹ͼ��                          ||\n");
			printf("\t||		5-�������                          ||\n");
			printf("\t||		6-�޸�����                          ||\n");
			printf("\t||		7-�˳�                              ||\n");
			printf("\t||==================================================||\n");
			printf("\n���������ѡ��1-7��:");
			scanf("%d",&n);
			while(n>7||n<1)
			{	
				printf("����������(1-7):");
				scanf("%d",&n);
			}
			printf("\n%d\n",di);
			switch(n)
			{
				case 1:
					xianshi();/*������ʾ����ͼ��Ĺ���*/
					break;
				case 2:
					Query_Book();/*��ѯͼ����Ϣ*/
					break;
				case 3:
					lent_book(str,di);input();/*����ͼ��*/
					break;
			    case 4:
					back_Book(str,di);input();/*�黹ͼ��*/
					break;
		   	    case 5:
					jieyue_Book(str,di);/*�������*/
					break;
				case 6:	
					xiugaimima(di);/*�޸�����*/
					break;
				case 7:
					Turn_menu3();/*�˳�*/
				default:break;		
			}
						
	Turn_menu2(str,di);
}

void zhuce()
{

	int jishu=0;
	char mima2[12];
	int keep=0,zh=0,ko=0;

			printf("%d",r);
			printf("\n--------------��ӭ����ע��ҳ�棡--------------\n");
			printf("ע���˺ţ�");	
			scanf("%s",huiyuan[r].zhanghao);

			for(zh=0;zh<r;zh++)
			{
				if(strcmp(huiyuan[r].zhanghao,huiyuan[zh].zhanghao)==0)
				{
					printf("\n-----------------���˺��ѱ�ע�ᣡ����----------------\n");
					printf("���������룺");
					printf("ע���˺ţ�");	
					scanf("%s",huiyuan[r].zhanghao);
					zh=-1;
				}
			}

			printf("���룺");
			scanf("%s",huiyuan[r].mima);
			printf("�ٴ��������룺");
			scanf("%s",mima2);
			while(strcmp(mima2,huiyuan[r].mima)!=0)
			{
				keep++;
				printf("\n�������벻һ��!\n");
				printf("�ٴ��������룺");
				scanf("%s",mima2);
				if(keep>3)
				{
					printf("��������������Զ��˳�");
					Turn_menu3();
				}
			}
			printf("\n\n--------------ע��ɹ���--------------------\n\n");
			r++;
			printf("%d",r);
			
}

//��ѯͼ��
void Query_Book()
{
	int n;
	int flag=0;
	char num2[10],name2[20];
	Books_style  *p=rep;

	

	printf("\n\n\t||==========================================||\n");
	printf("\t||                                          ||\n");
	printf("\t|| 1������Ų�ѯ                            ||\n");
	printf("\t|| 2����������ѯ                            ||\n");
	printf("\t||                                          ||\n");
	printf("\t||==========================================||\n");

	
	printf("\n���������ѡ��1-2��:");
	scanf("%d",&n);
	while(n>2||n<1)
	{	
		printf("����������(1-2):");
		scanf("%d",&n);
	
	}
	
	if(n==1)
	{
		printf("����������Ҫ��ѯ��ͼ�����ţ�");
		scanf("%s",num2);
			
		while (p != NULL)
		{	
			if(strcmp(num2,p->num)==0)
			{
				flag=1;
				printf("ѧ�ţ�%s\t������%s\t���ߣ�%s",p->num,p->name,p->author);
				printf("\t�鼮״̬:%s\n",p->zhuangtai);
			}
			p = p->next;
		}	
	}
	p=rep;
	if(n==2)
	{
		printf("����������Ҫ��ѯ��ͼ���������");
		scanf("%s",name2);

		while (p != NULL)
		{
			if(strcmp(name2,p->name)==0)
			{
				flag=1;
				printf("ѧ�ţ�%s\t������%s\t���ߣ�%s",p->num,p->name,p->author);
				printf("\t�鼮״̬:%s\n",p->zhuangtai);
			}
			p = p->next;
		}
		
	}
	p=rep;
	if(flag==0)
	{
		printf("û���ҵ���");	
	}	
	
}


//����ͼ��
void lent_book(char str[],int di)
{
	int n;
	int flag=0;
	char gt,ch;
	char num2[10],name2[20];
	Books_style  *p=rep;

	printf("\n\t----------ԭͼ����Ϣ����------------\n");
	xianshi();
	printf("\n\n\t||==========================================||\n");
	printf("\t||                                          ||\n");
	printf("\t|| 1������Ž���                            ||\n");
	printf("\t|| 2������������                            ||\n");
	printf("\t||                                          ||\n");
	printf("\t||==========================================||\n");

	
	printf("\n���������ѡ��1-2��:");
	scanf("%d",&n);
	while(n>2||n<1)
	{	
		printf("����������(1-2):");
		scanf("%d",&n);
		
	
	}
	
	if(n==1)
	{
		printf("����������Ҫ���ĵ�ͼ�����ţ�");
		scanf("%s",num2);
			
		while (rep != NULL)
		{	
			if(strcmp(num2,rep->num)==0)
			{
				flag=1;
				printf("\n�����ͼ����Ϣ��\n");
				printf("ѧ�ţ�%s\t������%s\t���ߣ�%s",rep->num,rep->name,rep->author);
				printf("\t�鼮״̬:%s\n",rep->zhuangtai);
				if(strcmp(rep->zhuangtai,"�ѽ��")==0)
				{
					
					printf("\n-------------------�����ѱ������----------------------\n");
					Turn_menu2(str,di);
				}
				printf("��ȷ���Ƿ���Ĵ���(Y/N):");
				scanf("%c",&ch);
				scanf("%c",&ch);
				while(ch!='Y'&&ch!='y'&&ch!='N'&&ch!='n')
				{
					printf("���������루Y/N��");
					scanf("%c",&ch);
				
				}	

				if(ch=='Y'||ch=='y')
				{
					strcpy(rep->zhuangtai,"�ѽ��");
					shu1++;
					rep->cishu++;
					strcpy(rep->zhanghao1,str);
					jilutime(di);
					printf("------------------���ĳɹ�!---------------------\n");
					break;
				}
				if(ch=='N'||ch=='n')
				{
					printf("------------------�˳�ϵͳ!---------------------\n");			
				}
				
			}
			rep = rep->next;
		}	
	}
	rep=p;
	if(n==2)
	{
		printf("����������Ҫ���ĵ�ͼ���������");
		scanf("%s",name2);

		while (rep != NULL)
		{
			if(strcmp(name2,rep->name)==0)
			{
				flag=1;
				printf("ѧ�ţ�%s\t������%s\t���ߣ�%s",rep->num,rep->name,rep->author);
				printf("\t�鼮״̬:%s\n",rep->zhuangtai);
				printf("��ȷ���ǲ��Ǵ��飡��Y/N��:");
				scanf("%c",&gt);
				scanf("%c",&gt);
				while(gt!='Y'&&gt!='y'&&gt!='N'&&gt!='n')
				{
					printf("���������루Y/N��");
					scanf("%c",&gt);
					scanf("%c",&gt);
				}	
				if((gt=='Y'||gt=='y'))
				{
					if(strcmp(rep->zhuangtai,"�ѽ��")==0)
					{
						printf("\n-------------------�����ѱ������----------------------\n");
						Turn_menu2(str,di);
					}
					printf("��ȷ���Ƿ���Ĵ���(Y/N):");
					scanf("%c",&ch);
					while(ch!='Y'&&ch!='y'&&ch!='N'&&ch!='n')
					{
						printf("���������루Y/N��");
						scanf("%c",&ch);
						scanf("%c",&ch);
					}	

					if(ch=='Y'||ch=='y')
					{
						strcpy(rep->zhuangtai,"�ѽ��");
						shu++;
						rep->cishu++;
						strcpy(rep->zhanghao1,str);
						jilutime(di);
						printf("------------------���ĳɹ�!---------------------\n");
						break;
					}
					if(ch=='N'||ch=='n')
					{
						printf("------------------�˳�ϵͳ!---------------------\n");
						Turn_menu2(str,di);
						
					}
				}

			}
			rep =rep->next;
		}
		
	}
	rep=p;
	if(flag==0)
	{
		printf("û���ҵ���");	
	}	
	
}


//�黹ͼ��
void back_Book(char str[],int di)
{
	int n;
	int flag=0;
	char gt,ch;
	char num2[10],name2[20];
	Books_style  *p=rep;
	

	printf("\n\t----------������Ϣ����------------\n");
	jieyue_Book(str,di);

	printf("\n\n\t||==========================================||\n");
	printf("\t||                                          ||\n");
	printf("\t|| 1������Ź黹                            ||\n");
	printf("\t|| 2���������黹                            ||\n");
	printf("\t||                                          ||\n");
	printf("\t||==========================================||\n");

	
	printf("\n���������ѡ��1-2��:");
	scanf("%d",&n);
	while(n>2||n<1)
	{	
		printf("����������(1-2):");
		scanf("%d",&n);
	
	}
	
	if(n==1)
	{
		printf("����������Ҫ�黹��ͼ�����ţ�");
		scanf("%s",num2);
			
			
		while (p != NULL)
		{	
			if(strcmp(num2,p->num)==0)
			{
				flag=1;
				printf("\n�����ͼ����Ϣ��\n");
				printf("ѧ�ţ�%s\t������%s\t���ߣ�%s",p->num,p->name,p->author);
				printf("\t�鼮״̬:%s\n",p->zhuangtai);
				if(strcpy(p->zhuangtai,"�ɽ�")==0)
				{
					printf("\n-------------------����δ�������----------------------\n");
					Turn_menu2(str,di);
				}
				printf("��ȷ���Ƿ�黹����(Y/N):");
				scanf("%c",&ch);
				scanf("%c",&ch);
				while(ch!='Y'&&ch!='y'&&ch!='N'&&ch!='n')
				{
					printf("���������루Y/N��");
					scanf("%c",&ch);
					scanf("%c",&ch);
				}	

				if(ch=='Y'||ch=='y')
				{
					strcpy(p->zhuangtai,"�ɽ� ");
					shu1--;
					strcpy(rep->zhanghao1,"   ");
					
					printf("------------------�黹�ɹ�!---------------------\n");
					break;
				}
				if(ch=='N'||ch=='n')
				{
					printf("------------------�˳�ϵͳ!---------------------\n");			
				}
				
			}
			p = p->next;
		}	
	}
	p=rep;
	if(n==2)
	{
		printf("����������Ҫ��ѯ��ͼ���������");
		scanf("%s",name2);

		while (p != NULL)
		{
			if(strcmp(name2,p->name)==0)
			{
				flag=1;
				printf("ѧ�ţ�%s\t������%s\t���ߣ�%s",p->num,p->name,p->author);
				printf("\t�鼮״̬:%s\n",p->zhuangtai);
				
				if(strcpy(p->zhuangtai,"�ɽ�")==0)
				{
					printf("\n-------------------����δ�������----------------------\n");
					Turn_menu2(str,di);
				}
				printf("��ȷ���ǲ��Ǵ��飡��Y/N����");
				scanf("%c",&gt);
				scanf("%c",&gt);
				
				while(gt!='Y'&&gt!='y'&&gt!='N'&&gt!='n')
				{
					printf("���������루Y/N��");
					scanf("%c",&gt);
					scanf("%c",&ch);
				}	
				if((gt=='Y'||gt=='y'))
				{
					printf("��ȷ���Ƿ��黹����(Y/N):%c",&ch);
					while(ch!='Y'&&ch!='y'&&ch!='N'&&ch!='n')
					{
						printf("���������루Y/N��");
						scanf("%c",&ch);
						scanf("%c",&ch);
					}	

					if(ch=='Y'||ch=='y')
					{
						strcpy(p->zhuangtai,"�ɽ� ");
						shu1--;
						strcpy(rep->zhanghao1,"  ");
						
						printf("------------------�黹�ɹ�!---------------------\n");
						break;
					}
					if(ch=='N'||ch=='n')
					{
						printf("------------------�˳�ϵͳ!---------------------\n");
						Turn_menu2(str,di);
						
					}
				}

			}
			p = p->next;
		}
		
	}
	p=rep;
	if(flag==0)
	{
		printf("û���ҵ���");	
	}	
	
}



void jieyue_Book(char string[],int n)
{	
	int zongs=0;
	Books_style  *p=rep;
	double zongmon=0;
	jilutime3();
	
	while (p != NULL)
		{	
			if(strcmp(string,p->zhanghao1)==0)
			{
				printf("\n\n\t���\t\t����\t\t\t����\t\t���ڽ��\n");
				p->yuqimoney=yuqifond_Book(n);
				printf("\t%-8s\t%-20s\t%-12s\t%f\n",p->num,p->name,p->author,p->yuqimoney);
				zongmon=zongmon+p->yuqimoney;
				zongs++;
			}
			p = p->next;
		}
	huiyuan[n].jieyueshu=zongs;
	printf("\n���豾��:%d\n",huiyuan[n].jieyueshu);
	huiyuan[n].date_jine=zongmon;
}


double yuqifond_Book(int n)
{
	int year1;
	int wei;
	double chaoqi=0,sum=0; 

	jilutime2();
	year1=second.nian-first[n].nian;
	if(year1==0)
	{
		for(wei=first[n].yue;wei<second.yue;wei++)
		{
			switch(wei)
			{
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:sum=sum+31;break;
				case 4:
				case 6:
				case 9:
				case 11:sum=sum+30;break;
				case 2:sum=sum+28;break;
			}
		
		}
	
	}
	else
	{
		
		for(wei=first[n].yue;wei<=12;wei++)
		{
			switch(wei)
			{
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:sum=sum+31;break;
				case 4:
				case 6:
				case 9:
				case 11:sum=sum+30;break;
				case 2:sum=sum+28;break;
				default:break;
			}
		
		}	
		
		for(wei=1;wei<second.yue;wei++)
		{
			if(second.yue==1)break;
			switch(wei)
			{
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:sum=sum+31;break;
				case 4:
				case 6:
				case 9:
				case 11:sum=sum+30;break;
				case 2:sum=sum+28;break;
				default:break;
			}	
		}
		
		sum=sum+second.ri;
		sum=sum+year1*365;					
	}

	if(sum>30)
	{
		chaoqi=0.50*sum;
	}

	return chaoqi;
}


void jilutime(int n)
{
	 struct tm *local;
  	 time_t t; 
  	 t=time(NULL); 
  	 local=localtime(&t); 
	 printf ("\n%d-%d-%d  ", 1900+local->tm_year, 1+local->tm_mon,local->tm_mday);
	 printf("%d:%d:%d\n",  local->tm_hour, local->tm_min, local->tm_sec);
	
	 first[n].nian=1900+local->tm_year;
	first[n].yue=1+local->tm_mon;
	first[n].ri=local->tm_mday;
   	
}


void jilutime2()
{
	 struct tm *local;
  	 time_t t; 
  	 t=time(NULL); 
  	 local=localtime(&t); 
	 second.nian=1900+local->tm_year;
	second.yue=1+local->tm_mon;
	second.ri=local->tm_mday;
   	
}


void jilutime3()
{
	 struct tm *local;
  	 time_t t; 
  	 t=time(NULL); 
  	 local=localtime(&t);
	 printf("\n���β�ѯʱ�䣺 ");
	 printf ("%d-%d-%d  ", 1900+local->tm_year, 1+local->tm_mon,local->tm_mday);
	 printf("%d:%d:%d\n",  local->tm_hour, local->tm_min, local->tm_sec);
	
   	
}


void xiugaimima(int n)
{

	int jishu=0;
	char mima2[12];
	int keep=0;
	char mima1[12];

		
			printf("������:");
			scanf("%s",mima1);

			while(strcmp(mima1,huiyuan[n].mima)!=0)
			{
				printf("�������������룺\n");
				scanf("%s",mima1);
				jishu++;
				if(jishu==3)
				{
					printf("\n\n----------------���������������!----------------------\n");
					Turn_menu();
				}
			}		
						
			printf("�����룺");
			scanf("%s",huiyuan[n].mima);
			printf("�ٴ��������룺");
			scanf("%s",mima2);
			while(strcmp(mima2,huiyuan[n].mima)!=0)
			{
				keep++;
				printf("\n�������벻һ��!\n");
				printf("�ٴ��������룺");
				scanf("%s",mima2);
				if(keep>3)
				{
					printf("��������������Զ��˳�");
					Turn_menu3();
				}
			}
			printf("\n\n--------------�޸ĳɹ���--------------------\n\n");
			Turn_menu3();		
}

void xianshi()
{
	Books_style  *p=rep;	
	printf("\n\n\t���\t\t����\t\t\t����\t\t�鼮״̬\n");
	while (p != NULL)
		{	
				printf("\t%-8s\t%-20s\t%-12s\t%-3s \n",p->num,p->name,p->author,p->zhuangtai);
			p = p->next;
		}

}
