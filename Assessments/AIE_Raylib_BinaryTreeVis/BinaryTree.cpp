#include "BinaryTree.h"
#include "TreeNode.h"
#include "raylib.h"
#include <iostream>
#include <cstdlib>

BinaryTree::BinaryTree()
{
    m_pRoot = nullptr;
}

BinaryTree::~BinaryTree()
{
	while(m_pRoot)
	{
		Remove(m_pRoot->GetData());
	}
}

// Return whether the tree is empty
bool BinaryTree::IsEmpty() const 
{ 
	return (m_pRoot == nullptr);
}

void BinaryTree::Insert(TreeNode* root, TreeNode* nodeToInsert)
{
	int _root = 0;
	int insert = 0;

	while (true)
	{
		if (m_pRoot != nullptr) // gets root and insert values into variable for readability
		{
			_root = root->GetData();
			insert = nodeToInsert->GetData(); 
		}

		if (m_pRoot == nullptr) // if theres no root, sets root
		{
			m_pRoot = nodeToInsert;
			m_pRoot->SetLeft(nullptr);
			m_pRoot->SetRight(nullptr);

			return;
		}
		else if (insert == _root)
		{
			return;
		}

		if (insert > _root)
		{
			if (root->HasRight())
			{
				root = root->GetRight(); // goes to right of tree
			}
			else
			{
				root->SetRight(nodeToInsert); // inserts to the right

				//sets children of added node to nullptr
				root = root->GetRight(); 
				root->SetLeft(nullptr);
				root->SetRight(nullptr);

				return;
			}
		}

		if (insert < _root)
		{
			if (root->HasLeft())
			{
				root = root->GetLeft(); // goes to left of tree
			}
			else
			{
				root->SetLeft(nodeToInsert); //inserts to the left

				//sets children of added node to nullptr
				root = root->GetLeft();
				root->SetLeft(nullptr);
				root->SetRight(nullptr);

				return;
			}
		}
	}
}

void BinaryTree::Insert(int a_nValue)
{
	Insert(m_pRoot, new TreeNode(a_nValue));
}

TreeNode* BinaryTree::Find(int a_nValue)
{
	if (m_pRoot != nullptr)
	{
		TreeNode* pParent = FindParent(m_pRoot, m_pRoot, a_nValue); // finds parent of node
		TreeNode* pCurrent = m_pRoot;

		if (pParent->GetLeft() != nullptr && pParent->GetLeft()->GetData() == a_nValue) // if left of parent exists and value == value being looked for
		{
			pCurrent = pParent->GetLeft(); // moves root to left of parent
		}
		else if (pParent->GetRight() != nullptr && pParent->GetRight()->GetData() == a_nValue) // if right of parent exists and value == value being looked for
		{
			pCurrent = pParent->GetRight(); // moves root to right of parent
		}

		return FindNode(pCurrent) ? pCurrent : nullptr; // returns moved root or nullptr
	}
}

bool BinaryTree::FindNode(TreeNode*& OutNode)
{
	if (OutNode == nullptr)
		return false;
	else
		return true;
}

TreeNode* BinaryTree::Remove(TreeNode* root, int value)
{
	if (m_pRoot != nullptr)
	{
		TreeNode* parent = FindParent(root, root, value); // gets parent of node to remove

		if (parent == nullptr) // if nothing return tree
		{
			return root;
		}

		auto roots = SplitTree(root, parent, value); // splits tree into 2 trees

		root = roots.first; // sets root to root
		TreeNode* secondRoot = roots.second; // creates and sets secondRoot to secondRoot

		InsertTree(root, secondRoot, value); // inserts second tree into original tree

		if (root == secondRoot) // removes root node if only node left
		{
			delete root;
			root = nullptr;
		}
		else
		{
			delete secondRoot; // deletes node to remove
		}
	}

	return root;
}

TreeNode* BinaryTree::FindParent(TreeNode* root, TreeNode* parent, int value)
{
	bool isFound = false;

	while (!isFound)
	{
		std::cout << " "; // stops program from breaking

		if (value == root->GetData()) // if root and value are the same, exit loop
		{
			isFound = true;
		}
		else if (value < root->GetData())
		{
			if (root->GetLeft() != nullptr)
			{
				root = root->GetLeft(); // take root down the left of the tree

				if (root->GetData() != value)
				{
					parent = parent->GetLeft(); // take parent down the left of the tree if root isnt value
				}
			}
			else // return nothing if value doesnt exist
			{
				return nullptr;
			}
		}
		else if (value > root->GetData())
		{
			if (root->GetRight() != nullptr)
			{
				root = root->GetRight(); // take root down the right of the tree

				if (root->GetData() != value)
				{
					parent = parent->GetRight(); // take parent down the right of the tree if root isnt value
				}
			}
			else // return nothing if value doesnt exist
			{
				return nullptr;
			}
		}
	}

	return parent;
}

std::pair<TreeNode*, TreeNode*> BinaryTree::SplitTree(TreeNode* root, TreeNode* parent, int value)
{
	TreeNode* secondRoot = root;

	if (root->GetData() != value)
	{
		if (parent->GetLeft() != nullptr && parent->GetLeft()->GetData() == value) // if parent has a left and if the left value == the value being looked for
		{
			secondRoot = parent->GetLeft(); // sets secondRoot to left of parent
			parent->SetLeft(nullptr); // cuts secondRoot off from rest of tree
		}
		else if (parent->GetRight() != nullptr && parent->GetRight()->GetData() == value) // if parent has a right and if the right value == the value being looked for
		{
			secondRoot = parent->GetRight(); // sets secondRoot to right of parent
			parent->SetRight(nullptr); // cuts secondRoot off from rest of tree
		}
	}

	if (secondRoot == root)
	{
		if (root->GetLeft() != nullptr) 
		{
			root = root->GetLeft(); // moves root to left of root
			secondRoot->SetLeft(nullptr); // cuts root off from rest of tree
		}
		else if (root->GetRight() != nullptr)
		{
			root = root->GetRight(); // moves root to right of root
			secondRoot->SetRight(nullptr); // cuts root off from rest of tree
		}
	}

	return std::make_pair(root, secondRoot); // returns boths trees as 1
}

void BinaryTree::InsertTree(TreeNode* root, TreeNode* secondRoot, int value)
{
	bool isInserted = false;

	TreeNode* resetNode = secondRoot; // stored root node of second tree

	while (!isInserted)
	{
		if (secondRoot->GetData() == value && secondRoot->GetLeft() == nullptr && secondRoot->GetRight() == nullptr) // if there is 1 node left in secondRoot and that node == to the value to remove
		{
			isInserted = true;
		}
		else
		{
			if (secondRoot->GetLeft() != nullptr)
			{
				if (secondRoot->GetLeft()->GetLeft() == nullptr && secondRoot->GetLeft()->GetRight() == nullptr) // does the left of the node have children
				{
					Insert(root, secondRoot->GetLeft()); // insert left of node from second tree into original tree
					secondRoot->SetLeft(nullptr); // cuts off inserted node from second tree
					secondRoot = resetNode; // goes back to root node of second tree
				}
				else
				{
					secondRoot = secondRoot->GetLeft(); // go down left of second tree
				}
			}
			else if (secondRoot->GetRight() != nullptr)
			{
				if (secondRoot->GetRight()->GetLeft() == nullptr && secondRoot->GetRight()->GetRight() == nullptr) // does the right of the node have children
				{
					Insert(root, secondRoot->GetRight()); // insert right of node from second tree into original tree
					secondRoot->SetRight(nullptr); // cuts off inserted node from second tree
					secondRoot = resetNode; // does back to root node of second tree
				}
				else
				{
					secondRoot = secondRoot->GetRight(); // go down right of second tree
				}
			}
		}
	}
}

void BinaryTree::Remove(int a_nValue)
{
	m_pRoot = Remove(m_pRoot, a_nValue);
}

void BinaryTree::PrintOrdered()
{
	PrintOrderedRecurse(m_pRoot);
	std::cout << std::endl;
}

void BinaryTree::PrintOrderedRecurse(TreeNode* pNode)
{
	if (pNode == nullptr)
	{
		return;
	}

	std::cout << pNode->GetData() << std::endl;

	PrintOrderedRecurse(pNode->GetLeft());
	PrintOrderedRecurse(pNode->GetRight());
}

void BinaryTree::PrintUnordered()
{
    PrintUnorderedRecurse(m_pRoot);
	std::cout << std::endl;
}

void BinaryTree::PrintUnorderedRecurse(TreeNode* pNode)
{
	if (pNode == nullptr)
	{
		std::cout << std::endl;
		return;
	}

	std::cout << pNode->GetData() << std::endl;

	PrintUnorderedRecurse(pNode->GetRight());
	PrintUnorderedRecurse(pNode->GetLeft());
}

void BinaryTree::Draw(TreeNode* selected)
{
	Draw(m_pRoot, 400, 40, 400, selected);
}

void BinaryTree::Draw(TreeNode* pNode, int x, int y, int horizontalSpacing, TreeNode* selected)
{
	horizontalSpacing /= 2;

	if (pNode)
	{
		if (pNode->HasLeft())
		{
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);
			
			Draw(pNode->GetLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		if (pNode->HasRight())
		{
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);

			Draw(pNode->GetRight(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		pNode->Draw(x, y, (selected == pNode));
	}
}