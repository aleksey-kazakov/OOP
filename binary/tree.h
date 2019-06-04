#pragma once

#define _TREE_H
#include <iostream>
template <class NODETYPE> class Tree;
#include "node.h"

template <class NODETYPE>

class Tree
{
public:
	Tree();                                                    /* конструктор */
	int add(const NODETYPE &);                         /* вставляет узел */
	void print(TreeNode<NODETYPE>*);                    /* печатает все ключи в неубывающем порядке */
	bool find(const NODETYPE &);


	TreeNode<NODETYPE> *get_root();                            /* возвращает указатель на корень дерева */
private:
	TreeNode<NODETYPE> *root;                                  /*]корень */
};

template<class NODETYPE>
Tree<NODETYPE>::Tree()
{
	root = 0;                      /* в начале дерево пусто */
}
template<class NODETYPE>
int Tree<NODETYPE>::add(const NODETYPE &x)
{
	TreeNode<NODETYPE>* n = new TreeNode<NODETYPE>(x);  /* создаем новый узел, его мы будем вставлять */
	TreeNode<NODETYPE>* ptr;
	TreeNode<NODETYPE>* ptr1;

	n->parent = n->left = n->right = 0;          /* он - лист */
	ptr = root;
	ptr1 = root;
	while (ptr != 0) {                     /* идем от корня и ищем подходящее место для нашего нового элемента, оно должно быть свободно */
	
		ptr1 = ptr;                 /* будущий родитель нового узла */
		if (x < ptr->get_data())  /* по определению нашего дерева - слева значение ключа меньше родителя, */
			ptr = ptr->left;
		else
			ptr = ptr->right;   /* справа - больше */
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
	TreeNode<NODETYPE>* n = new TreeNode<NODETYPE>(x);  /* создаем новый узел, его мы будем вставлять */
	TreeNode<NODETYPE>* ptr;
	TreeNode<NODETYPE>* ptr1;
	bool flag=false;

	n->parent = n->left = n->right = 0;          /* он - лист */
	ptr = root;
	while (ptr != 0) {                     /* идем от корня и ищем подходящее место для нашего нового элемента, оно должно быть свободно */
		ptr1 = ptr;                 /* будущий родитель нового узла */
		if (ptr->data == x) {
			flag = true;
			
		}
		if (x < ptr->get_data()) {  /* по определению нашего дерева - слева значение ключа меньше родителя, */
			ptr = ptr->left;
		}
		else {
			ptr = ptr->right;   /* справа - больше */
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
