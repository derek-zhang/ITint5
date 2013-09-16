/*
 ����: Annie Kim, anniekim.pku[at]gmail.com
 ʱ��: Sep 13, 2013
 ��Ŀ: �ж�����״̬
 �Ѷ�: Easy
 ����: http://www.itint5.com/oj/#5
 ����: 
 д�����ж�һ��9*9�����������Ƿ�Ϊ�Ϸ���������
 9*9�����水��Row-major order��ʾΪһ��81ά��һά���顣
 ��ʾ����ֱ����һά�����ϲ�������Ҫ�Ƚ�һά���鿽����9*9�Ķ�ά���顣

 Solution: �ο�leetcode�����Valid Sudoku�ⷨ��
*/

int isValidSudoku(int arr[]) {
    const int N = 9;
    int row, col[N] = {0}, box[N] = {0};
    for (int i = 0; i < N; ++i)
    {
        row = 0;
        for (int j = 0; j < N; ++j)
        {
            int index = i * N + j;
            if (arr[index] < 1 || arr[index] > 9)
                return false;
            int bit = 1 << arr[index];
            int box_index = i/3*3 + j/3;

            if (row & bit || col[j] & bit || box[box_index] & bit)
                return false;

            row |= bit;
            col[j] |= bit;
            box[box_index] |= bit;
        }
    }
    return true;
}