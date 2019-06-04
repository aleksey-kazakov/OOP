#pragma once
#define _NODE_H

template <class NODETYPE> class Tree;
template <class NODETYPE>
class TreeNode
{
	friend class Tree<NODETYPE> ;
public:
	TreeNode(const NODETYPE &);
	NODETYPE get_data();
protected:
	TreeNode* left;           //левый лист
	TreeNode* right;          //правый лист
	TreeNode* parent;         //верхний узел
	NODETYPE data;            //значение
};

template<class NODETYPE>
TreeNode <NODETYPE>::TreeNode(const NODETYPE &a)
{
	data = a;
	left = right = 0;
}
template <class NODETYPE>
NODETYPE TreeNode <NODETYPE>::get_data()
{
	return data;
}
