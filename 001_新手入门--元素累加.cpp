/*
 ����: Annie Kim, anniekim.pku[at]gmail.com
 ʱ��: Sep 12, 2013
 ��Ŀ: ��������--Ԫ���ۼ�
 �Ѷ�: Easy
 ����: http://www.itint5.com/oj/#1
 ����: ��һ������n������������arr������������������Ԫ��֮�͡�
       �������м����Լ����ս�������ᳬ��32λ�з������͵ķ�Χ����

 Solution: �ۼӡ�
*/

//����arr������Ԫ��֮��
//����Ҫmain����!
int arrSum(const vector<int> &arr) {
    int sum = 0, N = arr.size();
    for (int i = 0; i < N; ++i)
        sum += arr[i];
    return sum;
}