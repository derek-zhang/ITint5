/*
 ����: Annie Kim, anniekim.pku[at]gmail.com
 ʱ��: Sep 17, 2013
 ��Ŀ: �����ཻ
 �Ѷ�: Easy
 ����: http://www.itint5.com/oj/#14
 ����: 
 ��n�����Ҷ˵㶼Ϊ���������䣬�ж�ÿ�������Ƿ���������ĳ�������ཻ������˵��غ�Ҳ���ཻ����

 Solution: ����������˵�������򣬲����մ�С����˳����б�����
           ���������м�¼ĿǰΪֹ������Ҷ˵㡣
           �ж������Ƿ��ཻ����ֻ���жϵ�ǰ�������˵��Ƿ�С�ڻ��������Ҷ˵㡣
*/

/*
struct Interval {
    int start; //������˵�
    int end;   //�����Ҷ˵�
};
*/

bool compare(pair<int, Interval> a, pair<int, Interval> b) {
    return a.second.start < b.second.start;
}

// intervals����n������
// �����ŵ�isIntersected��(�ѷ���ռ�,����Ҫpush_back)
// isIntersected[i]��ʾ��i�������Ƿ������������ཻ
void intersected(vector<Interval> &intervals, vector<bool> &isIntersected) {
    int N = intervals.size();
    if (N == 0) return;

    pair<int, Interval> itvl[N];
    for (int i = 0; i < N; ++i)
        itvl[i] = make_pair(i, intervals[i]);
    sort(itvl, itvl + N, compare);
    
    int max_end = 0;
    isIntersected[itvl[0].first] = false;
    for (int i = 1; i < N; ++i)
    {
        if (itvl[i].second.start <= itvl[max_end].second.end)
            isIntersected[itvl[i].first] = isIntersected[itvl[max_end].first] = true;
        if (itvl[max_end].second.end < itvl[i].second.end)
            max_end = i;
    }
}