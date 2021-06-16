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
	bool nodeIsInserted = false;

	while (!nodeIsInserted)
	{
		if (m_pRoot == nullptr)
		{
			m_pRoot = nodeToInsert;
			m_pRoot->SetLeft(nullptr);
			m_pRoot->SetRight(nullptr);

			nodeIsInserted = true;
		}
		else if (nodeToInsert->GetData() == root->GetData())
			return;
		else if (nodeToInsert->GetData() < root->GetData())
			if (root->HasLeft())
				root = root->GetLeft();
			else
			{
				root->SetLeft(nodeToInsert);
				nodeIsInserted = true;
			}
		else if (nodeToInsert->GetData() > root->GetData())
			if (root->HasRight())
				root = root->GetRight();
			else
			{
				root->SetRight(nodeToInsert);
				nodeIsInserted = true;
			}
	}
}

// Insert a new element into the tree.
// Smaller elements are placed to the left, larger onces are placed to the right.
void BinaryTree::Insert(int a_nValue)
{
	Insert(m_pRoot, new TreeNode(a_nValue));
}

TreeNode* BinaryTree::Find(int a_nValue)
{
	if (m_pRoot != nullptr)
	{
		TreeNode* pParent = Find(m_pRoot, m_pRoot, a_nValue);
		TreeNode* pCurrent = m_pRoot;

		if (pParent->GetLeft() != nullptr && pParent->GetLeft()->GetData() == a_nValue)
			pCurrent = pParent->GetLeft();
		else if (pParent->GetRight() != nullptr && pParent->GetRight()->GetData() == a_nValue)
			pCurrent = pParent->GetRight();

		return FindNode(a_nValue, pCurrent, pParent) ? pCurrent : nullptr;
	}
}

bool BinaryTree::FindNode(int a_nSearchValue, TreeNode*& ppOutNode, TreeNode*& ppOutParent)
{
	if (ppOutNode == nullptr)
		return false;
	else
		return true;
}

TreeNode* BinaryTree::Remove(TreeNode* root, int value)
{
	// TODO
	if (m_pRoot != nullptr)
	{
		TreeNode* parent = Find(root, root, value);

		if (parent == nullptr)
			return root;

		auto roots = SplitTree(root, parent, value);

		root = roots.first;
		TreeNode* secondRoot = roots.second;

		InsertTree(root, secondRoot, value);

		if (root == secondRoot)
		{
			delete root;
			root = nullptr;
		}
		else
			delete secondRoot;
	}

	return root;
}

TreeNode* BinaryTree::Find(TreeNode* root, TreeNode* parent, int value)
{
	// TODO
	bool isFound = false;

	while (!isFound)
	{
		if (value == root->GetData())
			isFound = true;
		else if (value < root->GetData())
		{
			if (root->GetLeft() != nullptr)
			{
				root = root->GetLeft();

				if (root->GetData() != value)
					parent = parent->GetLeft();
			}
			else
				return nullptr;
		}
		else if (value > root->GetData())
		{
			if (root->GetRight() != nullptr)
			{
				root = root->GetRight();

				if (root->GetData() != value)
					parent = parent->GetRight();
			}
			else
				return nullptr;
		}
	}

	return parent;
}

std::pair<TreeNode*, TreeNode*> BinaryTree::SplitTree(TreeNode* root, TreeNode* parent, int value)
{
	TreeNode* secondRoot = root;

	if (root->GetData() != value)
	{
		if (parent->GetLeft() != nullptr && parent->GetLeft()->GetData() == value)
		{
			secondRoot = parent->GetLeft();
			parent->SetLeft(nullptr);
		}
		else if (parent->GetRight() != nullptr && parent->GetRight()->GetData() == value)
		{
			secondRoot = parent->GetRight();
			parent->SetRight(nullptr);
		}
	}

	if (secondRoot == root)
	{
		if (root->GetLeft() != nullptr)
		{
			root = root->GetLeft();
			secondRoot->SetLeft(nullptr);
		}
		else if (root->GetRight() != nullptr)
		{
			root = root->GetRight();
			secondRoot->SetRight(nullptr);
		}
	}

	return std::make_pair(root, secondRoot);
}

void BinaryTree::InsertTree(TreeNode* root, TreeNode* secondRoot, int value)
{
	bool isInserted = false;

	TreeNode* resetNode = secondRoot;

	while (!isInserted)
	{
		if (secondRoot->GetData() == value && secondRoot->GetLeft() == nullptr && secondRoot->GetRight() == nullptr)
		{
			isInserted = true;
		}
		else
		{
			if (secondRoot->GetLeft() != nullptr)
			{
				if (secondRoot->GetLeft()->GetLeft() == nullptr && secondRoot->GetLeft()->GetRight() == nullptr)
				{
					Insert(root, secondRoot->GetLeft());
					secondRoot->SetLeft(nullptr);
					secondRoot = resetNode;
				}
				else
					secondRoot = secondRoot->GetLeft();
			}
			else if (secondRoot->GetRight() != nullptr)
			{
				if (secondRoot->GetRight()->GetLeft() == nullptr && secondRoot->GetRight()->GetRight() == nullptr)
				{
					Insert(root, secondRoot->GetRight());
					secondRoot->SetRight(nullptr);
					secondRoot = resetNode;
				}
				else
					secondRoot = secondRoot->GetRight();
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

}

void BinaryTree::PrintUnordered()
{
    PrintUnorderedRecurse(m_pRoot);
	std::cout << std::endl;
}

void BinaryTree::PrintUnorderedRecurse(TreeNode* pNode)
{

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