#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int number;
    int totalChildInSubtree;
    string line;
    double fraction;
    char character;
    Node *parent;
    Node *leftChild;
    Node *rightChild;
    int height;

    Node()
    {
        parent = nullptr;
        leftChild = nullptr;
        rightChild = nullptr;
        totalChildInSubtree = 0;
    }
};

class binaryTree
{
public:
    Node *root;
    binaryTree()
    {
        root = nullptr;
    }

    void insertInBinaryTree(int value, int parent, int child);
    void levelOrderTraversal(Node *current);
    void preOrderTraversal(Node *current);
    void inOrderTraversal(Node *current);
    void postOrderTraversal(Node *current);
    Node *findByInOrderTraversal(int data, Node *current);
    Node *findByLevelOrderTraversal(int data);
    Node *findByPreOrderTraversal(int data, Node *current);
    Node *findByPostOrderTraversal(int data, Node *current);
    int findHeight(Node *current);
    Node *minimumValueInBinarySearchTree(Node *current);
    Node *maximumValueInBinarySearchTree(Node *current);
    int findMaximumValueInPath(int x, int y, Node *temp);
    void insertInBinarySearchTree(Node *temp, int value);
    Node *insertInBinarySearchTreeAndGetNewnode(Node *temp, int value);
    Node *searchByBinarySearchTree(Node *temp, int value);
    void sortingUsingBinarySearchTree(Node *temp, vector<int> &sorted);
    Node *findSuccessorFromBinarySearchTree(Node *current);
    Node *findPredecessorFromBinarySearchTree(Node *current);
    void deleteFromBinarySearchTree(int value);
    Node *insertInBinarySearchTreeAndGetNewnode(Node *temp, int value);
    Node *insertInBinarySearchTreeAndGetNewNode(Node *temp, int value);
};
int main()
{
    binaryTree bst;
    int totalNode;
    cin >> totalNode;
    while (totalNode--)
    {
        int num;
        cin >> num;
        bst.insertInBinarySearchTree(bst.root, num);
    }
    bst.levelOrderTraversal(bst.root);
}

void binaryTree::insertInBinaryTree(int value, int parent, int child)
{
    Node *newNode = new Node();
    newNode->number = value;
    if (parent == 0)
    {
        if (root == nullptr)
        {
            root = newNode;
            return;
        }
        else
        {
            cout << "Error: Root node already exists." << endl;
            delete newNode;
            return;
        }
    }

    queue<Node *> tree;
    tree.push(root);
    while (!tree.empty())
    {
        Node *current = tree.front();
        tree.pop();

        if (current->number == parent)
        {
            if (child == 1)
            {
                if (current->leftChild == nullptr)
                {
                    current->leftChild = newNode;
                    newNode->parent = current;
                    return;
                }
                else
                {
                    cout << "Error: Left child already exists for parent " << parent << endl;
                    delete newNode;
                    return;
                }
            }
            else if (child == 2)
            {
                if (current->rightChild == nullptr)
                {
                    current->rightChild = newNode;
                    newNode->parent = current;
                    return;
                }
                else
                {
                    cout << " Error: Right child already exists for parent " << parent << endl;
                    delete newNode;
                    return;
                }
            }
        }
        if (current->leftChild != nullptr)
        {
            tree.push(current->leftChild);
        }
        if (current->rightChild != nullptr)
        {
            tree.push(current->rightChild);
        }
    }
    cout << "Error: Parent " << parent << " not found in the tree" << endl;
    delete newNode;
}

void binaryTree::preOrderTraversal(Node *current)
{
    if (current == nullptr)
    {
        return;
    }
    cout << current->number << endl;

    preOrderTraversal(current->leftChild);
    preOrderTraversal(current->rightChild);
}

Node *binaryTree::findByPreOrderTraversal(int data, Node *current)
{
    if (current == nullptr)
        return nullptr;

    if (current->number == data)
        return current;

    Node *foundNode = findByPreOrderTraversal(data, current->leftChild);
    if (foundNode != nullptr)
        return foundNode;
    return findByPreOrderTraversal(data, current->rightChild);
}

void binaryTree::inOrderTraversal(Node *current)
{
    if (current == nullptr)
    {
        return;
    }
    inOrderTraversal(current->leftChild);
    cout << current->number << endl;
    inOrderTraversal(current->rightChild);
}

Node *binaryTree::findByInOrderTraversal(int data, Node *current)
{
    if (current == nullptr)
    {
        return nullptr;
    }
    Node *foundNode = findByInOrderTraversal(data, current->leftChild);
    if (foundNode != nullptr)
        return foundNode;
    if (current->number == data)
        return current;
    Node *foundNode2 = findByInOrderTraversal(data, current->rightChild);
    if (foundNode2 != nullptr)
        return foundNode2;

    return nullptr;
}

void binaryTree::postOrderTraversal(Node *current)
{
    if (current == nullptr)
    {
        return;
    }
    postOrderTraversal(current->leftChild);
    postOrderTraversal(current->rightChild);
    cout << current->number << endl;
}

Node *binaryTree::findByPostOrderTraversal(int data, Node *current)
{
    if (current == nullptr)
        return nullptr;
    Node *foundNode = findByPostOrderTraversal(data, current->leftChild);
    if (foundNode != nullptr)
        return foundNode;
    Node *foundNode2 = findByPostOrderTraversal(data, current->rightChild);
    if (foundNode2 != nullptr)
        return foundNode2;
    if (current->number == data)
        return current;

    return nullptr;
}

int binaryTree::findHeight(Node *current)
{
    if (current == nullptr)
        return -1;

    int leftChildHeight = findHeight(current->leftChild);
    int rightChildHeight = findHeight(current->rightChild);
    return max(leftChildHeight, rightChildHeight);
}

void binaryTree::levelOrderTraversal(Node *current)
{
    if (current == nullptr)
        return;
    queue<Node *> tree;
    tree.push(current);
    while (!tree.empty())
    {
        Node *temp = tree.front();
        tree.pop();
        cout << temp->number << endl;
        cout << temp->height << endl;
        if (temp->leftChild != nullptr)
            tree.push(temp->leftChild);
        if (temp->rightChild != nullptr)
            tree.push(temp->rightChild);
    }
}

Node *binaryTree::findByLevelOrderTraversal(int data)
{
    if (root == nullptr)
        return nullptr;
    queue<Node *> tree;
    tree.push(root);
    while (!tree.empty())
    {
        Node *temp = tree.front();
        tree.pop();

        if (temp->number == data)
            return temp;
        if (temp->leftChild != nullptr)
            tree.push(temp->leftChild);
        if (temp->rightChild != nullptr)
            tree.push(temp->rightChild);
    }
    return nullptr;
}

void binaryTree::insertInBinarySearchTree(Node *temp, int value)
{
    Node *newNode = new Node();
    newNode->number = value;
    if (temp == nullptr)
    {
        root = newNode;
        newNode->height = 0;
    }
    else
    {
        while (1)
        {
            if (temp->number > value)
            {
                temp->totalChildInSubtree++;
                if (temp->leftChild == nullptr)
                {
                    temp->leftChild = newNode;
                    newNode->parent = temp;
                    temp = newNode;
                    for (int i = 0;; i++)
                    {
                        temp->height = i;
                        if (temp->parent == nullptr)
                            break;
                        else
                            temp = temp->parent;
                    }
                    break;
                }
                else
                    temp = temp->leftChild;
            }
            else
            {
                temp->totalChildInSubtree++;
                if (temp->rightChild = nullptr)
                {
                    temp->rightChild = newNode;
                    newNode->parent = temp;
                    temp = newNode;
                    for (int i = 0;; i++)
                    {
                        temp->height = i;
                        if (temp->parent == nullptr)
                            break;
                        else
                            temp = temp->parent;
                    }
                    break;
                }
                else
                    temp = temp->rightChild;
            }
        }
    }
}

Node *binaryTree::searchByBinarySearchTree(Node *temp, int value)
{
    while (temp != nullptr and temp->number != value)
    {
        if (temp->number > value)
        {
            temp = temp->leftChild;
        }
        else
        {
            temp = temp->rightChild;
        }
    }
    return temp;
}

Node *binaryTree::minimumValueInBinarySearchTree(Node *current)
{
    while (current->leftChild != nullptr)
    {
        current = current->leftChild;
    }
    return current;
}

Node *binaryTree::maximumValueInBinarySearchTree(Node *current)
{
    while (current->rightChild != nullptr)
    {
        current = current->rightChild;
    }
    return current;
}

void binaryTree::sortingUsingBinarySearchTree(Node *current, vector<int> &sorted)
{
    if (current == nullptr)
        return;

    sortingUsingBinarySearchTree(current->leftChild, sorted);
    sorted.push_back(current->number);
    sortingUsingBinarySearchTree(current->rightChild, sorted);
}

Node *binaryTree::findSuccessorFromBinarySearchTree(Node *current)
{
    if (current == nullptr)
    {
        cout << "No Successor" << endl;
        return nullptr;
    }

    if (current->rightChild != nullptr)
    {
        return minimumValueInBinarySearchTree(current->rightChild);
    }

    Node *currentParent = current->parent;
    while (currentParent != nullptr && current->number > currentParent->number)
    {
        currentParent = currentParent->parent;
    }

    if (currentParent == nullptr)
    {
        cout << "No Successor" << endl;
        return nullptr;
    }

    return currentParent;
}

Node *binaryTree::findPredecessorFromBinarySearchTree(Node *current)
{
    if (current == nullptr)
    {
        cout << "No Predecessor" << endl;
        return nullptr;
    }

    if (current->leftChild != nullptr)
    {
        return maximumValueInBinarySearchTree(current->leftChild);
    }

    Node *currentParent = current->parent;
    while (currentParent != nullptr && current->number < currentParent->number)
    {
        currentParent = currentParent->parent;
    }

    if (currentParent == nullptr)
    {
        cout << "No Predecessor" << endl;
        return nullptr;
    }

    return currentParent;
}

void binaryTree::deleteFromBinarySearchTree(int value)
{
    Node *target = searchByBinarySearchTree(root, value);
    if (target == nullptr)
    {
        cout << "Node doesn't exist" << endl;
        return;
    }

    Node *targetParent = target->parent;

    if (target->leftChild == nullptr && target->rightChild == nullptr)
    {
        if (targetParent == nullptr)
        {
            delete root;
            root = nullptr;
        }
        else if (targetParent->leftChild == target)
        {
            targetParent->leftChild = nullptr;
            delete target;
        }
        else
        {
            targetParent->rightChild = nullptr;
            delete target;
        }
    }
    else if (target->leftChild == nullptr || target->rightChild == nullptr)
    {
        Node *child = (target->leftChild != nullptr) ? target->leftChild : target->rightChild;

        if (targetParent == nullptr)
        {
            delete root;
            root = child;
            child->parent = nullptr;
        }
        else if (targetParent->leftChild == target)
        {
            targetParent->leftChild = child;
            child->parent = targetParent;
            delete target;
        }
        else
        {
            targetParent->rightChild = child;
            child->parent = targetParent;
            delete target;
        }
    }
    else
    {
        Node *targetSuccessor = findSuccessorFromBinarySearchTree(target);
        if (target->parent == nullptr)
        {
            targetSuccessor->leftChild = target->leftChild;
            target->leftChild->parent = targetSuccessor;
            target->rightChild->parent = nullptr;
            root = target->rightChild;
            delete target;
        }
        else if (target == targetParent->rightChild)
        {
            targetParent->rightChild = target->rightChild;
        }
        else
        {
            targetParent->leftChild = target->rightChild;
        }
        target->rightChild->parent = targetParent;
        targetSuccessor->leftChild = target->leftChild;
        target->leftChild->parent = targetSuccessor;
    }
}

int binaryTree::findMaximumValueInPath(int x, int y, Node *temp)
{
    int large;
    while (1)
    {
        if (x < temp->number && y < temp->number)
        {
            temp = temp->leftChild;
        }
        else if (x > temp->number && y > temp->number)
        {
            temp = temp->rightChild;
        }
        else if (x < temp->number && y == temp->number)
        {
            return y;
        }
        else
        {
            large = y;
            while (temp != nullptr && temp->number != y)
            {
                if (temp->number > y)
                {
                    large = max(large, temp->number);
                    temp = temp->leftChild;
                }
                else
                {
                    large = max(large, temp->number);
                    temp = temp->rightChild;
                }
            }
            return large;
        }
    }
}

Node *binaryTree::insertInBinarySearchTreeAndGetNewNode(Node *temp, int value) {
    Node *newNode = new Node();
    newNode->number = value;
    if (temp == nullptr) {
        root = newNode;
        newNode->height = 0;
    } else {
        while (1) {
            if (temp->number > value) {
                temp->totalChildInSubtree++;
                if (temp->leftChild == nullptr) {
                    temp->leftChild = newNode;
                    newNode->parent = temp;
                    temp = newNode;
                    for (int i = 0;; i++) {
                        temp->height = i;
                        if (temp->parent == nullptr)
                            break;
                        else
                            temp = temp->parent;
                    }
                    break;
                } else
                    temp = temp->leftChild;
            } else {
                temp->totalChildInSubtree++;
                if (temp->rightChild == nullptr) {
                    temp->rightChild = newNode;
                    newNode->parent = temp;
                    temp = newNode;
                    for (int i = 0;; i++) {
                        temp->height = i;
                        if (temp->parent == nullptr)
                            break;
                        else
                            temp = temp->parent;
                    }
                    break;
                } else
                    temp = temp->rightChild;
            }
        }
    }
    return newNode;
}
