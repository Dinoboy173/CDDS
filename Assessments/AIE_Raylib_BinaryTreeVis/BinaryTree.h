/*----------------------------------------
Author: Richard Stern
Description: A simple binary search tree
Date: 17/4/2015
----------------------------------------*/
#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include <map>

class TreeNode;

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	bool IsEmpty() const;
	void Insert(int a_nValue);
	void Remove(int a_nValue);
	TreeNode* Find(int a_nValue);

	void Insert(TreeNode* root, TreeNode* nodeToInsert);

	TreeNode* Remove(TreeNode* root, int value);
	TreeNode* FindParent(TreeNode* root, TreeNode* parent, int value);
	std::pair<TreeNode*, TreeNode*> SplitTree(TreeNode* root, TreeNode* parent, int value);
	void InsertTree(TreeNode* root, TreeNode* secondRoot, int value);

	void PrintOrdered();
	void PrintUnordered();

	void Draw(TreeNode* selected = nullptr);

private:
	//Find the node with the specified value.
	bool FindNode(TreeNode*& ppOutNode);

	//Used to recurse through the nodes in value order and print their values.
	void PrintOrderedRecurse(TreeNode*);
	void PrintUnorderedRecurse(TreeNode*);


	void Draw(TreeNode*, int x, int y, int horizontalSpacing, TreeNode* selected = nullptr);

	//The root node of the tree
	TreeNode* m_pRoot = nullptr;
};

#endif //_BINARYTREE_H_