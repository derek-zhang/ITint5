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
           2. ���ڻ��Σ��ֱ�������
              a)����i��0��N-1������arr[0]��arr[i]֮�͵����ֵ��������l2r[i]��
              b)����i��N-1��0������arr[i]��arr[N-1]֮�͵����ֵ��������r2l[i]��
              ���ȡl2r[i]+r2l[i+1]�����ֵM_2��
           3. ����M_1��M_2�нϴ��ߡ�
*/

int maxConsSum(const vector<int> &arr) {
    int dp = 0, res = 0;
    for (int i = 0; i < arr.size(); ++i) {
        dp = max(arr[i], dp + arr[i]);
        res = max(dp, res);
    }
    return res;
}

int maxConsSum2(const vector<int> &arr) {
    int N = arr.size();
    if (N == 0) return 0;
    int res = maxConsSum(arr); // �ǻ���

    int l2r[N], r2l[N];
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        l2r[i] = i == 0 ? max(0, arr[i]) : max(l2r[i-1], sum + arr[i]);
        sum += arr[i];
    }
    sum = 0;
    for (int i = N-1; i >= 0; --i) {
        r2l[i] = i == N-1 ? max(0, arr[i]) : max(r2l[i+1], sum + arr[i]);
        sum += arr[i];
    }

    res = max(res, r2l[N-1]);
    for (int i = 0; i < N-1; ++i)
        res = max(res, l2r[i] + r2l[i+1]);
    return res;
}