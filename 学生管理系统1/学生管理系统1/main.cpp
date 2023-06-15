#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h>
#include<windows.h>
struct stu {
	int id[10];	//ѧ�� 
	char name[20]; //���� 
	int score; //���� 
};

struct STU
{
	//int data;
	struct stu data;
	struct STU* next;
};
//�����ṹ���ͷ 
struct STU* creatlist()//��������
{
	struct STU* head = (struct STU*)malloc(sizeof(struct STU));
	head->next = NULL;
	return head;
}
//�������
struct STU* createNode(struct stu data)
{
	struct STU* newNode = (struct STU*)malloc(sizeof(struct STU));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
//������
void insertNodeByhead(struct STU* head, struct stu data)
{
	struct STU* newNode = createNode(data);
	newNode->data = data;
	head->next = newNode;
}
//ָ��λ��ɾ��
void deleteNode(struct STU* head, char* name)
{
	struct STU* posNode = head->next;
	struct STU* posFrontNode = head;
	if (posNode == NULL)
	{
		printf("����Ϊ�գ��޷�ɾ����\n");
		return;
	}
	while (strcmp(posNode->data.name, name))
	{
		posFrontNode = posNode;
		posNode = posFrontNode->next;
		if (posNode == NULL)
		{
			printf("δ�ҵ�ָ��λ�ã��޷�ɾ����\n");
			return;
		}
	}
	posFrontNode->next = posNode->next;
	free(posNode);
}
//����
struct STU* searchData(struct STU* head, char* name)
{
	struct STU* p = head->next;
	if (p == NULL)
		return NULL;
	while (strcmp(p->data.name, name))
	{
		p = p->next;
	}
	return p;
}
//�ļ�������
void readFile(struct STU* head, char* fileName)
{
	FILE* fp;
	struct stu data;
	fp = fopen(fileName, "r");
	if (fp == NULL)
	{
		fp = fopen(fileName, "w+");
	}
	while (fscanf(fp, "%d\t%s\t%d\n", &data.id, data.name, &data.score) != EOF)
	{
		insertNodeByhead(head, data);
	}
	fclose(fp);
}
//�ļ�д����
void writeFile(struct STU* head, char* FileName)
{
	FILE* fp;
	fp = fopen(FileName, "w");
	struct STU* p = head->next;
	while (p)
	{
		fprintf(fp, "%d\t%s\t%d\n", p->data.id, p->data.name, p->data.score);
		p = p->next;
	}
	fclose(fp);
}

//��ӡ����
void printlist(struct STU* head)
{
	struct STU* p = head->next;
	printf("ѧ��\t����\t����\n");
	while (p)
	{
		printf("%d\t%s\t%d\n", p->data.id, p->data.name, p->data.score);
		p = p->next;
	}
	printf("\n");
}


void menu()
{

	system("cls");//����
	system("color b");//�޸�������ɫ 
	printf("\n\n\n\n");
	printf("\t************************************\n");
	printf("\t|     ��ӭ����ѧ����Ϣ����ϵͳ     |\n");
	printf("\t|**********************************|\n");
	printf("\t|**        1:¼��ѧ����Ϣ        **|\n");
	printf("\t|**        2:��ʾѧ����Ϣ        **|\n");
	printf("\t|**        3:����ѧ����Ϣ        **|\n");
	printf("\t|**        4:ɾ��ѧ����Ϣ        **|\n");
	printf("\t|**        5:��ѯѧ����Ϣ        **|\n");
	printf("\t|**        6:�޸�ѧ����Ϣ        **|\n");
	printf("\t|**        7:�˳�ѧ��ϵͳ        **|\n");
	printf("\t************************************\n");
	printf("\n  \t��������Ҫ���еĲ�����1~~7����");

}


struct STU* List = creatlist();

void  keydown()
{
	int n = 0;
	struct stu data;
	struct STU* p = NULL;
	scanf("%d", &n);
	switch (n)
	{
		//����һ��ѧ����Ϣ 
	case 1:
		printf("******¼��ѧ����Ϣ******\n");
		printf("��������Ҫ��ӵ�ѧ��ѧ��,������������");
		fflush(stdin);//��ջ����� 
		scanf("%d\t%s\t%d\n", &data.id, data.name, &data.score);
		insertNodeByhead(List, data);
		break;
	case 2:
		printf("******��ʾѧ����Ϣ******\n");
		printlist(List);
		break;
	case 3:
		printf("******����ѧ����Ϣ******\n");
		printf("��������Ҫ��ӵ�ѧ��ѧ��,������������");
		fflush(stdin);//��ջ����� 
		scanf("%d\t%s\t%d\n", &data.id, data.name, &data.score);
		insertNodeByhead(List, data);
		break;
	case 4:
		printf("******ɾ��ѧ����Ϣ******\n");
		printf("����ɾ����ѧ������:");
		scanf("%s", data.name);
		deleteNode(List, data.name);
		break;
	case 5:
		printf("******��ѯѧ����Ϣ******\n");
		printf("������Ҫ���ҵ�ѧ��������");
		scanf("%s", data.name);
		p = searchData(List, data.name);
		if (p == NULL)
		{
			printf("δ�ҵ������Ϣ���޷�ɾ����\n");
			system("pause");
		}
		else
		{
			printf("ѧ��\t����\t����\n");
			printf("%d\t%s\t%d\n", p->data.id, p->data.name, p->data.score);
		}
		break;
	case 6:
		printf("******�޸�ѧ����Ϣ******\n");
		printf("������Ҫ�޸ĵ�ѧ��������");
		scanf("%s", data.name);

		break;
	case 7:
		printf("�Ѿ�����ȫ�˳���");
		system("pause");//��ֹ���� 
		exit(7);
		break;

	default:
		printf("��������,�������룡");
		system("pause");//��ֹ����
		break;


	}
	writeFile(List, "1.txt");
}

int main()
{
	readFile(List, "1.txt");
	while (1)
	{
		menu();
		keydown();
	}
	return 0;
}




