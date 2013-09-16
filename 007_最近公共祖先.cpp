/*
 ����: Annie Kim, anniekim.pku[at]gmail.com
 ʱ��: Sep 12, 2013
 ��Ŀ: �����������
 �Ѷ�: Easy
 ����: http://www.itint5.com/oj/#7
 ����: ��һ������������������������㣬�������������������������ȡ�

 Solution: ����������ڵ������������ĸ߶ȡ�������ʱ�临�Ӷ�O(n)��
*/

/*
// �ڵ㶨��
struct TreeNode {
    TreeNode *parent;
};
*/

// ����node�ڵ������������ĸ߶�
int getHeight(TreeNode *node) {
    int height = 0;
    while (node) {
        height++;
        node = node->parent;
    }
    return height;
}

// ���ؽڵ�node1��node2�������������
TreeNode *getLCA(TreeNode *node1, TreeNode *node2) {
    int height1 = getHeight(node1), height2 = getHeight(node2);
    if (height1 < height2) {
        swap(height1, height2);
        swap(node1, node2);
    }
    int diff = height1 - height2;
    while (diff--)
        node1 = node1->parent;
    while (node1 != node2) {
        node1 = node1->parent;
        node2 = node2->parent;
    }
    return node1;
}