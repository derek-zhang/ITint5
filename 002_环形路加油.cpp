/*
 ����: Annie Kim, anniekim.pku[at]gmail.com
 ʱ��: Sep 13, 2013
 ��Ŀ: ����·����
 �Ѷ�: Medium
 ����: http://www.itint5.com/oj/#2
 ����: 
 ��һ�����ι�·����n������վ����i������վ������Ϊa[i]��
 ������һ�����������������������ʼ�����ǿյģ������Ӽ���վi��ʻ������վi+1�����g[i]��
 ���Ƿ��ܹ�ѡ��ĳ������վ��Ϊ��㣬ʹ�����ܹ��ƻ��ι�·��ʻһȦ���ص��ü���վ��
 ʵ�ֺ���int selectGasStation(int a[], int g[], int n)��
 ����������������ļ���վ�����ظü���վ�����(0-based)�����򷵻�-1��
 ��ʾ��n���ܴﵽ106��O(n^2)��ö���㷨�ᳬ��ʱ�����ơ�

 Solution: 
           1. �������ұ�������ס���������ٵ�λ�ã�������һ��λ�ó�����
           2. ����һ������ΪN������v����¼a[i]-g[i]��
              �Ӻ���ǰ��������v��
              ���v[i]С���㣬������v[i-1]�ϲ�����Ϊ��ʱi��������Ϊ��㡣
              ���v[i]��С���㣬����sum������¼��λ��pos���п�����Ϊ��㣩��
              ������v[0]���ڵ����㣬˵������·���Ѿ�û�и���v[i]������0���ɡ�
              ���v[0]+sum>=0�������������ļ���վ������pos��
              ���򣬷���-1��
           3. ����һ������Ϊ2*N-1������v����¼a[i]-g[i]����ת��Ϊ���ԣ���
              ʹ������ָ��start��end��
              ���[start, end]�����С��0����start = end + 1��������
              ֱ���ҵ�����ΪN������[start, end]����������ʹ��ڵ���0���ҵ�����start��
           �������ַ�����ʱ�临�ӶȽ�ΪO(N)��
*/

int selectGasStation_1(const vector<int> &a, const vector<int> &g) {
    int N = a.size();
    int res = 0, min = a[0] - g[0], sum = min;
    for (int i = 1; i < N; ++i)
    {
        sum += a[i] - g[i];
        if (sum < min) {
            min = sum;
            res = i;
        }
    }
    return sum >= 0 ? (res + 1) % N : -1;
}

int selectGasStation_2(const vector<int> &a, const vector<int> &g) {
    int N = a.size();
    int v[N];
    for (int i = 0; i < a.size(); ++i)
        v[i] = a[i] - g[i];
    int sum = 0, pos = -1;
    for (int i = N-1; i > 0; --i)
    {
        if (v[i] >= 0) {
            sum += v[i];
            pos = i;
        } else {
            v[i-1] += v[i];
        }
    }
    if (v[0] >= 0) return 0;
    else if (v[0] + sum >= 0) return pos;
    else return -1;
}

int selectGasStation_3(const vector<int> &a, const vector<int> &g) {
    int N = a.size();
    int v[2 * N];
    for (int i = 0; i < N; ++i)
    {
        v[i] = a[i] - g[i];
        v[i+N] = a[i] - g[i];
    }
    int sum = 0;
    for (int start = 0, end = 0; start <= N && end < 2 * N; end++)
    {
        if (sum + v[end] < 0) {
            start = end + 1;
            sum = 0;
        } else {
            if (end - start == N - 1) 
                return start;
            sum += v[end];
        }
    }
    return -1;
}