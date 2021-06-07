#include <iostream>

struct Node
{
    int value;
    Node* left = nullptr;
    Node* right = nullptr;

    // Constructor
    Node() {};

    // Overloaded Constructor
    Node(int value) : value(value) {}

    // Overloaded Constructor
    Node(int value, Node* left, Node* right) : value(value), left(left), right(right) {}
};

void PreOrderPrint(Node* n)
{
    // TODO
    if (n == nullptr)
    {
        std::cout << "null" << std::endl;
        return;
    }

    std::cout << n->value << std::endl;

    PreOrderPrint(n->left);
    PreOrderPrint(n->right);
}

void PostOrderPrint(Node* n)
{
    // TODO
    if (n == nullptr)
        return;

    PostOrderPrint(n->left);
    PostOrderPrint(n->right);

    std::cout << n->value << std::endl;
}

Node* Find(Node* root, int value)
{
    // TODO

    bool isFound = false;

    while (!isFound)
    {
        if (value == root->value)
            isFound = true;
        else if (value < root->value)
        {
            if (root->left != nullptr)
                root = root->left;
            else
                return nullptr;
        }
        else if (value > root->value)
        {
            if (root->right != nullptr)
                root = root->right;
            else
                return nullptr;
        }
    }

    return root;
}

void Insert(Node* root, Node* nodeToInsert)
{
    // TODO

    bool nodeIsInserted = false;

    while (!nodeIsInserted)
    {
        if (nodeToInsert->value == root->value)
            return;
        else if (nodeToInsert->value < root->value)
            if (root->left != nullptr)
                root = root->left;
            else
            {
                root->left = nodeToInsert;
                nodeIsInserted = true;
            }
        else if (nodeToInsert->value > root->value)
            if (root->right != nullptr)
                root = root->right;
            else
            {
                root->right = nodeToInsert;
                nodeIsInserted = true;
            }
    }
}

Node* Find(Node* root, Node* parent, int value)
{
    // TODO

    bool isFound = false;

    while (!isFound)
    {
        if (value == root->value)
            isFound = true;
        else if (value < root->value)
        {
            if (root->left != nullptr)
            {
                root = root->left;

                if (parent->left != root)
                    parent = parent->left;
            }
            else
                return nullptr;
        }
        else if (value > root->value)
        {
            if (root->right != nullptr)
            {
                root = root->right;
            
                if (parent->right != root)
                    parent = parent->right;
            }
            else
                return nullptr;
        }
    }

    return parent;
}

void InsertTree(Node* root, Node* secondRoot)
{
    bool nodesInserted = false;

    Node* tempRoot = secondRoot;
    Node* parent = secondRoot;

    while (!nodesInserted)
    {
        if (secondRoot->value == tempRoot->value)
            nodesInserted = true;

        if (secondRoot->left != nullptr)
        {
            secondRoot = secondRoot->left;
            nodesInserted = false;
        }

        else if (secondRoot->right != nullptr)
        {
            secondRoot = secondRoot->right;
            nodesInserted = false;
        }

        else if (secondRoot->left == nullptr && secondRoot->right == nullptr)
        {
            Insert(root, secondRoot);

            nodesInserted = false;
            secondRoot = tempRoot;
        }
    }
}

Node Remove(Node* root, int value)
{
    // TODO
    Node* parent = Find(root, root, value);
    Node* secondRoot = root;

    //----------------------------------------------- doesn't work redo
    if (parent == root)
    {
        if (root->left != nullptr)
        {
            secondRoot = root;
            root = root->left;
            secondRoot->left = nullptr;
        }
        else if (root->right != nullptr)
        {
            secondRoot = root;
            root = root->right;
            secondRoot->right = nullptr;
        }
    }
    else
    {
        if (parent->left->value == value)
        {
            secondRoot = parent->left;
            parent->left = nullptr;
        }
        else if (parent->right->value == value)
        {
            secondRoot = parent->right;
            parent->right = nullptr;
        }
    }
    //-----------------------------------------------

    if (secondRoot->left != nullptr)
    {
        Insert(root, secondRoot->left);
        secondRoot->left = nullptr;
    }

    if (secondRoot->right != nullptr)
    {
        Insert(root, secondRoot->right);
        secondRoot->right = nullptr;
    }

    return *root;
}

int Height(Node* n)
{
    // TODO
    return 0;
}

int Depth(Node* root, Node* n)
{
    // TODO
    return 0;
}

int main(int argc, char** argv)
{
    Node root = Node(6,
        new Node(4,
            new Node(2, nullptr, nullptr),
            new Node(5, nullptr, nullptr)),
        new Node(8,
            new Node(7, nullptr, nullptr),
            new Node(9, nullptr, nullptr)));

    // TODO:
    // Test the above methods

    std::cout << "PreOrderPrint\n";
    PreOrderPrint(&root);
    std::cout << std::endl;

    std::cout << "PostOrderPrint\n";
    PostOrderPrint(&root);
    std::cout << std::endl;

    Insert(&root, new Node(3));
    Insert(&root, new Node(8));
    Insert(&root, new Node(10));

    std::cout << "PreOrderPrint\n";
    PreOrderPrint(&root);
    std::cout << std::endl;

    Node* foundValue = Find(&root, 10);

    if (foundValue != nullptr)
        std::cout << "Found: " << foundValue->value << std::endl;
    else
        std::cout << "Value Not Found" << std::endl;

    root = Remove(&root, 8);

    std::cout << "PreOrderPrint Tree\n";
    PreOrderPrint(&root);
    std::cout << std::endl;

    return 0;
}