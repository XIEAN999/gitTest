#include<stdio.h>
#include<stdlib.h>
#include "stdafx.h"
#include "defines.h"

typedef struct Node {
	int key;
	struct Node *lchild;
	struct Node *rchild;
}BSTNode, *BSTree;
int InsertBST(BSTree *bst, int k)
{
	BSTree r, s, pre;
	r = (BSTree)malloc(sizeof(BSTNode));
	r->key = k;
	r->lchild = NULL;
	r->rchild = NULL;
	if (*bst == NULL)
	{
		*bst = r;
		return true;
	}
	pre = NULL;
	s = *bst;
	while (s)
	{
		if (k == s->key)
			return false;
		else if (k < s->key)
		{
			pre = s;
			s = s->lchild;
		}
		else if (k > s->key)
		{
			pre = s;
			s = s->rchild;
		}
	}
	if (k < pre->key) { pre->lchild = r; }
	else pre->rchild = r;
	return true;
}//建立二叉排序树过程
void CreateBST(BSTree *bst)
{
	int key;
	*bst = NULL;
	scanf("%d", &key);
	while (key != -1)
	{
		InsertBST(bst, key);
		scanf("%d", &key);
	}
}//打印二叉排序树
BSTree SearchBST(BSTree bst, int key)
{
	BSTree q;
	q = bst;
	while (q) {
		if (q->key == key) { return q; }
		if (q->key > key) { q = q->lchild; }
		else { q = q->rchild; }
	}
	return NULL;
}//查找