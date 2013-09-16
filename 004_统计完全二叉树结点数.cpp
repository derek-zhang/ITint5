/*
 ����: Annie Kim, anniekim.pku[at]gmail.com
 ʱ��: Sep 13, 2013
 ��Ŀ: ͳ����ȫ�����������
 �Ѷ�: Medium
 ����: http://www.itint5.com/oj/#4
 ����: 
 ����һ����ȫ�������ĸ���㣬ͳ�Ƹ����Ľ��������
 �����������ΪTreeNode����û��Ҫ֪�������͵Ķ��壬��ʹ������ķ����õ�ĳ���������Ҷ��ӽ�㣬�Լ��ж�ĳ����Ƿ�ΪNULL��
 //��ý��node������ӽ��
 TreeNode getLeftChildNode(TreeNode node);
 //��ý��node���Ҷ��ӽ��
 TreeNode getRightChildNode(TreeNode node);
 //�жϽ��node�Ƿ�ΪNULL
 int isNullNode(TreeNode node);

 Solution: ����Ҫ���������ȫ�����������ʡ�
           �������������ĸ߶ȣ������жϳ����һ������Ҷ�ڵ��λ�ã��Ϳ��Խ��ж��֡�
           ���Ӷ�O(lgn^2)��
*/

// ���ĸ߶ȣ���������
int getHeight(TreeNode node)
{
    int height = 0;
    while (!isNullNode(node)) {
        height++;
        node = getLeftChildNode(node);
    }
    return height;
}

// �߶�Ϊheight�����������ڵ����
int count_perfect_binary_tree_nodes(int height)
{
    return (int)pow(2, height) - 1;
}

int count_complete_binary_tree_nodes(TreeNode root)
{
    int count = 0;
    while (!isNullNode(root))
    {
        int left = getHeight(getLeftChildNode(root));
        int right = getHeight(getRightChildNode(root));
        if (left == right)
        {
            count += count_perfect_binary_tree_nodes(left) + 1;
            root = getRightChildNode(root);
        }
        else
        {
            count += count_perfect_binary_tree_nodes(right) + 1;
            root = getLeftChildNode(root);
        }
    }
    return count;
}