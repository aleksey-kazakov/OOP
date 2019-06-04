#pragma once

#define _TREE_H
#include <iostream>
template <class NODETYPE> class Tree;
#include "node.h"

template <class NODETYPE>

class Tree
{
public:
	Tree();                                                    /* ����������� */
	int add(const NODETYPE &);                         /* ��������� ���� */
	void print(TreeNode<NODETYPE>*);                    /* �������� ��� ����� � ����������� ������� */
	bool find(const NODETYPE &);


	TreeNode<NODETYPE> *get_root();                            /* ���������� ��������� �� ������ ������ */
private:
	TreeNode<NODETYPE> *root;                                  /*]������ */
};

template<class NODETYPE>
Tree<NODETYPE>::Tree()
{
	root = 0;                      /* � ������ ������ ����� */
}
template<class NODETYPE>
int Tree<NODETYPE>::add(const NODETYPE &x)
{
	TreeNode<NODETYPE>* n = new TreeNode<NODETYPE>(x);  /* ������� ����� ����, ��� �� ����� ��������� */
	TreeNode<NODETYPE>* ptr;
	TreeNode<NODETYPE>* ptr1;

	n->parent = n->left = n->right = 0;          /* �� - ���� */
	ptr = root;
	ptr1 = root;
	while (ptr != 0) {                     /* ���� �� ����� � ���� ���������� ����� ��� ������ ������ ��������, ��� ������ ���� �������� */
	
		ptr1 = ptr;                 /* ������� �������� ������ ���� */
		if (x < ptr->get_data())  /* �� ����������� ������ ������ - ����� �������� ����� ������ ��������, */
			ptr = ptr->left;
		else
			ptr = ptr->right;   /* ������ - ������ */
	}
	n->parent = ptr1;
	if (ptr1 == 0)                     
		root = n;
	else{
		if (x < ptr1->get_data())
			ptr1->left = n;
		else
			ptr1->right = n;
	}
	return 0;
}
template <class NODETYPE>
bool Tree<NODETYPE>::find(const NODETYPE &x){
	TreeNode<NODETYPE>* n = new TreeNode<NODETYPE>(x);  /* ������� ����� ����, ��� �� ����� ��������� */
	TreeNode<NODETYPE>* ptr;
	TreeNode<NODETYPE>* ptr1;
	bool flag=false;

	n->parent = n->left = n->right = 0;          /* �� - ���� */
	ptr = root;
	while (ptr != 0) {                     /* ���� �� ����� � ���� ���������� ����� ��� ������ ������ ��������, ��� ������ ���� �������� */
		ptr1 = ptr;                 /* ������� �������� ������ ���� */
		if (ptr->data == x) {
			flag = true;
			
		}
		if (x < ptr->get_data()) {  /* �� ����������� ������ ������ - ����� �������� ����� ������ ��������, */
			ptr = ptr->left;
		}
		else {
			ptr = ptr->right;   /* ������ - ������ */
		}
	}
	if (flag == false) std::cout << "FALSE";
	else std::cout << "TRUE";
	
	return flag;
}

template<class NODETYPE>
void Tree<NODETYPE>::print(TreeNode<NODETYPE>* n){
	if (n != 0){
		print(n->left);
		std::cout << n->get_data() << std::endl;
		print(n->right);
	}
}

template<class NODETYPE>
TreeNode<NODETYPE>* Tree<NODETYPE>::get_root(){
	return root;
}
