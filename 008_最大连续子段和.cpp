/*
 ����: Annie Kim, anniekim.pku[at]gmail.com
 ʱ��: Sep 15, 2013
 ��Ŀ: ��������Ӷκ�
 �Ѷ�: Easy
 ����: http://www.itint5.com/oj/#8
 ����: 
 ��һ������n��Ԫ�ص�����arr�����������Ӷκͣ�����նΣ���

 Solution: ��leetcode�е�Maximum Subarray���ƣ�dp����
*/

int maxConsSum(const vector<int> &arr) {
    int dp = 0;
    int res = 0;
    for (int i = 0; i < arr.size(); ++i) {
        dp = max(arr[i], dp + arr[i]);
        res = max(dp, res);
    }
    return res;
}