/*
Date ： 2015/01/16
题目描述：
1.把二元查找树转变成排序的双向链表
 题目：
输入一棵二元查找树，将该二元查找树转换成一个排序的双向链表。
要求不能创建任何新的结点，只调整指针的指向。
   
  10
  / /
 6 14
 / / / /
4 8 12 16
   
 转换成双向链表
4=6=8=10=12=14=16。
   
 首先我们定义的二元查找树 节点的数据结构如下：
 struct BSTreeNode
{
  int m_nValue; // value of node
  BSTreeNode *m_pLeft; // left child of node
  BSTreeNode *m_pRight; // right child of node
};
*/

/*
解题思路:
1，将二元查找树转换成排序的双向链表主要是用中序遍历的方法。
2，主要是考查了数据结构之间的转换。重点是双向链表和二元查找树的创建及遍历。

*/

/*头文件*/
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
 #include<math.h>
/*macro definition*/

/*architecture definition */
//二叉树
 typedef struct BSTreeNode  
{
  int m_nValue; // value of node
  BSTreeNode *m_pLeft; // left child of node
  BSTreeNode *m_pRight; // right child of node
}BSTreeNode ,*BSTree;

//双向链表
 typedef struct DouNode
 {
	int n;
	struct DouNode *prior;
	struct DouNode *next;
 }DouNode, *DouLinkList;

/*variable declaration*/
DouNode *h,*p,*l;

/*function declaration */
 void CreateBSTree(BSTree &T);					//创建二叉树
 void InOrderTraverse(BSTree &T);				//中序遍历
 void Visit(int n);								//遍历二叉树然后构建双向链表
 void Print_DouNode(DouNode * p);				//打印双向链表
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