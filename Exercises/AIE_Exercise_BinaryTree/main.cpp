#include <iostream>
#include <utility>

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

                if (root->value != value)
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
            
                if (root->value != value)
                    parent = parent->right;
            }
            else
                return nullptr;
        }
    }

    return parent;
}

std::pair<Node*, Node*> SplitTree(Node* root, Node* parent, int value)
{
    Node* secondRoot = root;

    if (root->value != value)
    {
        if (parent->left != nullptr && parent->left->value == value)
        {
            secondRoot = parent->left;
            parent->left = nullptr;
        }
        else if (parent->right != nullptr && parent->right->value == value)
        {
            secondRoot = parent->right;
            parent->right = nullptr;
        }
    }

    if (secondRoot == root)
    {
        if (root->left != nullptr)
        {
            root = root->left;
            secondRoot->left = nullptr;
        }
        else if (root->right != nullptr)
        {
            root = root->right;
            secondRoot->right = nullptr;
        }
    }

    return std::make_pair(root, secondRoot);
}

void InsertTree(Node* root, Node* secondRoot, int value)
{
    bool isInserted = false;

    Node* resetNode = secondRoot;

    while (!isInserted)
    {
        if (secondRoot->value == value && secondRoot->left == nullptr && secondRoot->right == nullptr)
        {
            isInserted = true;
        }
        else
        {
            if (secondRoot->left != nullptr)
            {
                if (secondRoot->left->left == nullptr && secondRoot->left->right == nullptr)
                {
                    Insert(root, secondRoot->left);
                    secondRoot->left = nullptr;
                    secondRoot = resetNode;
                }
                else
                    secondRoot = secondRoot->left;
            }
            else if (secondRoot->right != nullptr)
            {
                if (secondRoot->right->left == nullptr && secondRoot->right->right == nullptr)
                {
                    Insert(root, secondRoot->right);
                    secondRoot->right = nullptr;
                    secondRoot = resetNode;
                }
                else
                    secondRoot = secondRoot->right;
            }
        }
    }
}

Node Remove(Node* root, int value)
{
    // TODO
    Node* parent = Find(root, root, value);
    if (parent == NULL)
        return NULL;

    auto roots = SplitTree(root, parent, value);

    root = roots.first;
    Node* secondRoot = roots.second;

    InsertTree(root, secondRoot, value);

    secondRoot = NULL;

    std::cout << "PreOrderPrint SecondTree\n";
    PreOrderPrint(secondRoot);
    std::cout << std::endl;

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

    root = Remove(&root, 4);

    std::cout << "PreOrderPrint Tree\n";
    PreOrderPrint(&root);
    std::cout << std::endl;

    return 0;
}