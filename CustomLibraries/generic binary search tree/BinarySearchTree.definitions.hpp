#ifndef BinarySearchTree_definitions_hpp
#define BinarySearchTree_definitions_hpp

#include <vector>
#include <iostream>
#include <BinaryNode.declarations.hpp>
#include <BinarySearchTree.declarations.hpp>
using namespace std;

template <class Any>
BinarySearchTree<Any>::BinarySearchTree()
	: root(NULL),
	  duplicatesallowed(false)
{
}

template <class Any>
const BinarySearchTree<Any>& BinarySearchTree<Any>::operator=(const BinarySearchTree& rhs)
{
	if(this != rhs)
	{
		makeempty();
		root = clone(rhs.root);
	}
}

template <class Any>
BinarySearchTree<Any>::~BinarySearchTree()
{
	makeempty();
}

template <class Any>
bool BinarySearchTree<Any>::isempty()
{
	return isempty(root);
}

template <class Any>
bool BinarySearchTree<Any>::isempty(BinaryNode<Any>* bn)
{
	return !((bool) bn);
}

template <class Any>
void BinarySearchTree<Any>::makeempty()
{
	makeempty(root);
}

template <class Any>
void BinarySearchTree<Any>::makeempty(BinaryNode<Any>* bn)
{
	if(bn)
	{
		makeempty(bn->pleftchild);
		makeempty(bn->prightchild);
		delete bn;
	}
	bn = NULL;
}

template <class Any>
BinaryNode<Any>* BinarySearchTree<Any>::clone()
{
	return clone(root);
}

template <class Any>
BinaryNode<Any>* BinarySearchTree<Any>::clone(BinaryNode<Any>* bn)
{
	if(bn)
		return new BinaryNode<Any>(bn->element, clone(bn->pleftchild), clone(bn->prightchild));
	return NULL;
}

template <class Any>
void BinarySearchTree<Any>::allowduplicates(bool t_f = true)
{
	//cerr<<"isempty() = "<<isempty()<<endl;
	if(isempty())
		duplicatesallowed = t_f;
	else
		;	// throw BSTnotemptyException;	//TODO
}

template<class Any>
const BinaryNode<Any>* BinarySearchTree<Any>::insert(const Any& object)
{
	return insert(root, object);
}

template<class Any>
const BinaryNode<Any>* BinarySearchTree<Any>::insert(BinaryNode<Any>*& helper, const Any& object)
{
	if(!helper)
	{
		helper = new BinaryNode<Any>(object, 1, NULL, NULL);
		return helper;
	}
	else
	{
		
		if(object < helper->element)
			return insert(helper->pleftchild, object);
		else if(helper->element < object)
			return insert(helper->prightchild, object);
		else
		{
			if(duplicatesallowed)
				helper->multiplicity++;
			else
				;
			return helper;
		}
	}
}

template<class Any>
void BinarySearchTree<Any>::remove(Any& object)
{
	removelazy(object);
}

template<class Any>
void BinarySearchTree<Any>::removelazy(const Any& object)
{
	removelazy(root, object);
}

#define REMOVELAZYTHRESHOLD (-11)
template<class Any>
void BinarySearchTree<Any>::removelazy(const BinaryNode<Any>* helper, const Any& object)
{
	
}

template<class Any>
void BinarySearchTree<Any>::removehard(Any& object)
{
	removehard(root, object);
}

template<class Any>
void BinarySearchTree<Any>::removehard(BinaryNode<Any>*& helper, Any& object)
{
	if(!helper)
		return;
	else if(object < helper->element)
		removehard(helper->pleftchild, object);
	else if(helper->element < object)
		removehard(helper->prightchild, object);
	else
		if(helper->isfullnode())
		{
			BinaryNode<Any>* temp = findminbinarynode(helper->prightchild);
			helper->element = temp->element;
			helper->multiplicity = temp->multiplicity;
			removehard(temp, temp->element);
		}
		else
		{
			BinaryNode<Any>* temp = helper;
			helper = helper->pleftchild ? helper->pleftchild : helper->prightchild;
			delete temp;
		}
}

template<class Any>
BinaryNode<Any>* BinarySearchTree<Any>::findminbinarynode(BinaryNode<Any>* helper) const
{
	if(!helper)
		return NULL;	// throw NodeNotFoundException
	if(!helper->pleftchild)
		return helper;
	else
		return findminbinarynode(helper->pleftchild);
}

template<class Any>
const vector<const Any&>& BinarySearchTree<Any>::traversalinorder() const
{
	vector<const Any&> order;
	traversalinorder(root, order);
	return order;
}

template<class Any>
void BinarySearchTree<Any>::traversalinorder(BinaryNode<Any>* bn, vector<const Any&>& order)
{
	if(!bn)
		return;
	traversalinorder(bn->pleftchild, order);
	order.push_back(bn->element);
	traversalinorder(bn->prightchild, order);
}

template<class Any>
void BinarySearchTree<Any>::printtraversalinorder()
{
	//cerr<<"duplicatesallowed = "<<duplicatesallowed<<endl;
	if(duplicatesallowed)
		printtraversalinorderduplicatesallowed(root);
	else
		printtraversalinorderduplicatesnotallowed(root);
}

template<class Any>
void BinarySearchTree<Any>::printtraversalinorderduplicatesallowed(BinaryNode<Any>* bn)
{
	if(!bn)
		return;
	printtraversalinorderduplicatesallowed(bn->pleftchild);
	if(bn->multiplicity > 0)
		cout<<"\t"<<bn->element<<"\tx\t"<<bn->multiplicity<<endl;
	printtraversalinorderduplicatesallowed(bn->prightchild);
}

template<class Any>
void BinarySearchTree<Any>::printtraversalinorderduplicatesnotallowed(BinaryNode<Any>* bn)
{
	if(!bn)
		return;
	printtraversalinorderduplicatesnotallowed(bn->pleftchild);
	cout<<"\t"<<bn->element<<endl;
	printtraversalinorderduplicatesnotallowed(bn->prightchild);
}

#endif
