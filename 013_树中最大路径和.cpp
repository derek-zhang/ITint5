/*
 ����: Annie Kim, anniekim.pku[at]gmail.com
 ʱ��: Sep 16, 2013
 ��Ŀ: �������·����
 �Ѷ�: Easy
 ����: http://www.itint5.com/oj/#13
 ����: 
 ����һ�����ĸ���㣬����ÿ����㶼����һ������ֵval��
 ����֪����������2�����֮�䶼����Ψһ��һ��·����·��ֵΪ·�������н��ֵ֮�͡�
 ���������·��ֵ������·��Ϊ�գ���
 ������
    -10
  /  |  \
 2   3   4
    / \
   5  -1
      /
     6
    /
   -1
 ����·��ֵΪ13����Ӧ��·��Ϊ5��6֮���·����
 ��չ�������㷨Ҳ�����������һ���ǳ������������⡰����ֱ���������������������·���ĳ��ȵ����ֵ����
 ������Ϊ����ÿ������valֵΪ1����ô���·���൱����·��ֵ����·����

 Solution: LeetCode��Binary Tree Maximum Path Sum����չ���������������Ƕ�������
*/

/*
�����Ķ���(�벻Ҫ�ڴ����ж��������)
struct TreeNode {
    int val;
    vector<TreeNode*> children;  //�ý��Ķ��ӽ��
 };
*/
#include <climits>

int maxTreePathSumRe(TreeNode *root, int &res) {
    if (!root) return res;
    int N = root->children.size();
    int first = 0, second = 0;
    for (int i = 0; i < N; ++i)
    {
        int sum = maxTreePathSumRe(root->children[i], res);
        if (sum > first) {
            second = first;
            first = sum;
        } else if (sum > second) {
            second = sum;
        }
    }
    int maximum = root->val;
    maximum = max(maximum, root->val + first);
    res = max(res, maximum);
    res = max(res, root->val + first + second);
    return maximum;
}

int maxTreePathSum(TreeNode *root) {
    int res = 0;
    maxTreePathSumRe(root, res);
    return res;
}