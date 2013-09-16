/*
 ����: Annie Kim, anniekim.pku[at]gmail.com
 ʱ��: Sep 16, 2013
 ��Ŀ: ������������Ӷκ�
 �Ѷ�: Easy
 ����: http://www.itint5.com/oj/#9
 ����: 
 ��һ������n��Ԫ�ص���β�����Ļ�������arr�����������Ӷκͣ�����նΣ���
 ����������[1, 3, -2, 6, -1]������Ӷκ�Ӧ��Ϊ9����Ӧ���Ӷ�Ϊ[6, -1, 1, 3]��

 Solution: 1. �ǻ��ε����ֱ��Ӧ�á���������Ӷκ͡��Ľⷨ�����ֵΪM_1��
           2. ���ڻ��Σ��������С�����Ӷκ͡�������������ĺ�sum��ȥ��С�����Ӷκ���Ϊ�������ֵM_2��
           3. ����M_1��M_2�нϴ��ߡ�
*/

// ��������Ӷκ�
int maxConsSum(const vector<int> &arr) {
    int dp = 0, res = 0;
    for (int i = 0; i < arr.size(); ++i) {
        dp = max(arr[i], dp + arr[i]);
        res = max(dp, res);
    }
    return res;
}

// ��С�����Ӷκ�
int minConsSum(const vector<int> &arr) {
    int dp = 0, res = 0;
    for (int i = 0; i < arr.size(); ++i) {
        dp = min(arr[i], dp + arr[i]);
        res = min(dp, res);
    }
    return res;
}

// ������������Ӷκ�
int maxConsSum2(const vector<int> &arr) {
    int N = arr.size();
    int sum = 0;
    for (int i = 0; i < N; ++i)
        sum += arr[i];
    int res = maxConsSum(arr); // �ǻ���
    res = max(res, sum - minConsSum(arr)); // ����
    return res;
}