// BinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct BTNode* pLeft;
    struct BTNode* pRight;
    char data;
} BTNode;

BTNode* CreateNode(char data);
void DestroyNode(BTNode* pNode);
void DestroyTree(BTNode* pRootNode);

void PrintPreorderTree(BTNode* pNode);
void PrintInorderTree(BTNode* pNode);
void PrintPostorderTree(BTNode* pNode);

BTNode* CreateNode(char data)
{
    BTNode* pNode = (BTNode*)malloc(sizeof(BTNode));
    if (pNode == NULL)
        return NULL;

    pNode->pLeft = NULL;
    pNode->pRight = NULL;
    pNode->data = data;

    return pNode;
}

void DestroyNode(BTNode* pNode)
{
    free(pNode);
}

void DestroyTree(BTNode* pRoot)
{
    if (pRoot == NULL)
    {
        return;
    }

    DestroyTree(pRoot->pLeft);
    DestroyTree(pRoot->pRight);
    DestroyNode(pRoot);
}

// Preorder Traveral
//         1
//        / \
//       2   5
//      / \ / \
//     3  4 6  7
//
void PrintPreorderTree(BTNode* pNode)
{
    if (pNode == NULL)
        return;

    printf(" %c", pNode->data);
    PrintPreorderTree(pNode->pLeft);
    PrintPreorderTree(pNode->pRight);
}

// Inorder Traveral
//         4
//        / \
//       2   6
//      / \ / \
//     1  3 5  7
//
void PrintInorderTree(BTNode* pNode)
{
    if (pNode == NULL)
        return;

    PrintInorderTree(pNode->pLeft);
    printf(" %c", pNode->data);
    PrintInorderTree(pNode->pRight);
}

// Postorder Traveral
//         7             
//        / \
//       3   6
//      / \ / \
//     1  2 4  5
//
void PrintPostorderTree(BTNode* pNode)
{
    if (pNode == NULL)
        return;

    PrintPostorderTree(pNode->pLeft);
    PrintPostorderTree(pNode->pRight);
    printf(" %c", pNode->data);
}

int main(void)
{
    BTNode* pNode1 = CreateNode('A');
    BTNode* pNode2 = CreateNode('B');
    BTNode* pNode3 = CreateNode('C');
    BTNode* pNode4 = CreateNode('D');
    BTNode* pNode5 = CreateNode('E');
    BTNode* pNode6 = CreateNode('F');
    BTNode* pNode7 = CreateNode('G');

    pNode1->pLeft = pNode2;
    pNode1->pRight = pNode5;

    pNode2->pLeft = pNode3;
    pNode2->pRight = pNode4;

    pNode5->pLeft = pNode6;
    pNode5->pRight = pNode7;

    printf("PreorderTree\t");
    PrintPreorderTree(pNode1);

    printf("\nInorderTree\t");
    PrintInorderTree(pNode1);

    printf("\nPostorderTree\t");
    PrintPostorderTree(pNode1);

    printf("\n\n\n");

    return 0;
}