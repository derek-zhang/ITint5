/*
 ����: Annie Kim, anniekim.pku[at]gmail.com
 ʱ��: Sep 16, 2013
 ��Ŀ: �������
 �Ѷ�: Easy
 ����: http://www.itint5.com/oj/#10
 ����: 
 ��n��������Ҫ��ɣ����1��n��������֮����һЩ������ϵ���������a����������b��c��
 ��ôֻ�е�����b������c���֮������������a���������е�������ϵ���ж���Щ�����Ƿ��ܹ���ɡ�
 ����ܹ���ɣ������һ���Ϸ�������������С�
 ������
 n=5
 1->2,3
 3->4
 ��������������1����������2������3������3����������4����ô���ںϷ��������������4,3,2,1,5

 Solution: ��������
*/

typedef int JobID;
typedef map<JobID, vector<JobID> > MAP;
typedef MAP::const_iterator Iterator;

/*
 * deps[id]��ʾ����id������������
 * ������ںϷ�������������У�����true�����򷵻�false
 * �Ϸ����������������ڲ���result�У��Ѿ�����ռ䣬����Ҫpush_back��
 */
bool jobSchedule(const map<JobID, vector<JobID> > &deps, int n, vector<JobID> &result) 
{
    MAP notify;
    queue<JobID> q;
    int deps_count[n+1];
    for (int i = 1; i <= n; ++i) 
        deps_count[i] = 0;
    for (Iterator it = deps.begin(); it != deps.end(); ++it)
    {
        JobID id = it->first;
        const vector<JobID> &jobs = it->second;
        int N = jobs.size();
        deps_count[id] = N;
        for (int i = 0; i < N; ++i)
            notify[jobs[i]].push_back(id);
    }
    for (int i = 1; i <= n; ++i) 
        if (deps_count[i] == 0) 
            q.push(i);

    int index = 0;
    while (!q.empty())
    {
        JobID id = q.front(); q.pop();
        result[index++] = id;
        if (notify.find(id) == notify.end())
            continue;
        vector<JobID> &jobs = notify[id];
        for (int i = 0; i < jobs.size(); ++i)
        {
            deps_count[jobs[i]]--;
            if (deps_count[jobs[i]] == 0)
                q.push(jobs[i]);
        }
    }

    return index == n;
}