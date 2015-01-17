/*
Date �� 2015/01/16
��Ŀ������
1.�Ѷ�Ԫ������ת��������˫������
 ��Ŀ��
����һ�ö�Ԫ�����������ö�Ԫ������ת����һ�������˫������
Ҫ���ܴ����κ��µĽ�㣬ֻ����ָ���ָ��
   
  10
  / /
 6 14
 / / / /
4 8 12 16
   
 ת����˫������
4=6=8=10=12=14=16��
   
 �������Ƕ���Ķ�Ԫ������ �ڵ�����ݽṹ���£�
 struct BSTreeNode
{
  int m_nValue; // value of node
  BSTreeNode *m_pLeft; // left child of node
  BSTreeNode *m_pRight; // right child of node
};
*/

/*
����˼·:
1������Ԫ������ת���������˫��������Ҫ������������ķ�����
2����Ҫ�ǿ��������ݽṹ֮���ת�����ص���˫������Ͷ�Ԫ�������Ĵ�����������

*/

/*ͷ�ļ�*/
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
 #include<math.h>
/*macro definition*/

/*architecture definition */
//������
 typedef struct BSTreeNode  
{
  int m_nValue; // value of node
  BSTreeNode *m_pLeft; // left child of node
  BSTreeNode *m_pRight; // right child of node
}BSTreeNode ,*BSTree;

//˫������
 typedef struct DouNode
 {
	int n;
	struct DouNode *prior;
	struct DouNode *next;
 }DouNode, *DouLinkList;

/*variable declaration*/
DouNode *h,*p,*l;

/*function declaration */
 void CreateBSTree(BSTree &T);					//����������
 void InOrderTraverse(BSTree &T);				//�������
 void Visit(int n);								//����������Ȼ�󹹽�˫������
 void Print_DouNode(DouNode * p);				//��ӡ˫������
 /*main function*/
 void main()
 {
	BSTree T;
	h = (DouNode *)malloc(sizeof(DouNode));
	h->next = h;
	h->prior = h;
	p = h;
	CreateBSTree(T);
	InOrderTraverse(T);
	Print_DouNode(h);
 }


/*function definition*/
  void CreateBSTree(BSTree &T)
  {
	int n;
	scanf("%d",&n);
	if(n == 0)
	{
		T  =  NULL;
	}
	else
	{
		T = (BSTree)malloc(sizeof(BSTreeNode)); 
		if(!T)
			exit(OVERFLOW);
		T->m_nValue = n;
		CreateBSTree(T->m_pLeft);
		CreateBSTree(T->m_pRight);
	}
  }

void InOrderTraverse(BSTree &T)
{
	if(T)
	{
		InOrderTraverse(T->m_pLeft);
		Visit(T->m_nValue);
		InOrderTraverse(T->m_pRight);
	}
}

void Visit(int n)
{
	printf("%d",n);
	l = (DouNode *)malloc(sizeof(DouNode));
	l->n = n;
	p->next = l;
	l->prior = p;
	l->next = h;
	h->prior = l;
	p = l;

}
void Print_DouNode(DouNode *q)
{
	q = h->next;
	int i = 0;
	while( q != h)
	{
		printf("%d=",q->n);
		q =q->next;
		i++;
	}
}