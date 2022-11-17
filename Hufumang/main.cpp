#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Hufumang.h"

using namespace std;
void PreOrderRec(Btree* root);

/* 构造哈夫曼编码树 */
void HuffmanTree(Btree*& huff, int n)
{
    LinkQueue* LQ = new LinkQueue;
    int i = 0;

    //初始化队列
    InitQueue(LQ);

    /* 初始化存放哈夫曼树数组 HuffNode[] 中的结点 */
    for (i = 0; i < n; i++)
    {
        Bnode* node = new Bnode;

        cout << "请输入第" << i + 1 << "个字符和出现频率: " << endl;
        cin >> node->value; //输入字符
        cin >> node->weight;//输入权值
        node->parent = NULL;
        node->lchild = NULL;
        node->rchild = NULL;

        EnterQueue(LQ, node, node->weight);
    }

    PrintQueue(LQ);
    //system("pause");
    //exit(0);

    do {
        Bnode* node1 = NULL;
        Bnode* node2 = NULL;

        if (!IsEmpty(LQ)) {
            PopQueue(LQ, &node1);
            printf("第一个出队列的数：%c, 优先级: %d\n", node1->value, node1->weight);
        }
        else {
            break;
        }

        if (!IsEmpty(LQ)) {
            Bnode* node3 = new Bnode;

            PopQueue(LQ, &node2);
            printf("第二个出队列的数：%c, 优先级: %d\n", node2->value, node2->weight);
            node3->lchild = node1;
            node1->parent = node3;
            node3->rchild = node2;
            node2->parent = node3;
            node3->value = ' ';
            node3->weight = node1->weight + node2->weight;
            printf("合并进队列的数：%c, 优先级: %d\n", node3->value, node3->weight);
            EnterQueue(LQ, node3, node3->weight);
        }
        else {
            huff = node1;
            break;
        }
    } while (1);
}

void PreOrderRec(Btree* root)
{
    if (root == NULL)
    {
        return;
    }

    printf("- %c -", root->value);
    PreOrderRec(root->lchild);
    PreOrderRec(root->rchild);
}

int main(void) {
    Btree* tree = NULL;

    HuffmanTree(tree, 7);
    PreOrderRec(tree);
    system("pause");
    return 0;
}

