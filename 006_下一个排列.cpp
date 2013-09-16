/*
 ����: Annie Kim, anniekim.pku[at]gmail.com
 ʱ��: Sep 12, 2013
 ��Ŀ: ��һ������
 �Ѷ�: Easy
 ����: http://www.itint5.com/oj/#6
 ����: ����һ������n�����������飬�����������һ�����У���C++ STL�е�next_permutation��������

 Solution: �ο�leetcode��next permutationһ�⡣
*/

bool next_permutation(vector<int> &arr) {
    int index = arr.size() - 2;
    while (index >= 0 && arr[index] >= arr[index+1]) 
        index--;
    if (index < 0)
        return false;
    sort(arr.begin() + index + 1, arr.end());
    int replace = index + 1;
    while (arr[replace] <= arr[index])
        replace++;
    swap(arr[index], arr[replace]);
    return true;
}