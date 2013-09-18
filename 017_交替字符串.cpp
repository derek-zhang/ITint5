/*
 ����: Annie Kim, anniekim.pku[at]gmail.com
 ʱ��: Sep 18, 2013
 ��Ŀ: �����ַ���
 �Ѷ�: Easy
 ����: http://www.itint5.com/oj/#17
 ����: 
 ����ַ���str3�ܹ���str1��str2�е��ַ���˳�����γɣ���ô��str3Ϊstr1��str2�Ľ����ַ�����
 ����str1="abc"��str2="def"����ô"adbecf", "abcdef", "abdecf", "abcdef", "adefbc"�ȵȶ�Ϊstr1��str2�Ľ����ַ�����
 
 ����ʽ���ģ�str3�������㷨���£�
 str3=""
 while str1��Ϊ�� or str2��Ϊ��:
     ��str1��str2�����ַ����뵽str3,����str1��str2��ɾ����Ӧ���ַ�
 end

 ����str1, str2,��str3���ж�str3�Ƿ�Ϊstr1��str2�Ľ����ַ�����

 Solution: ��LeetCode��Interleaving String��ͬ��
*/

bool isInterleaving(string &str1, string &str2, string &str3) {
    int N = str1.size(), M = str2.size(), L = str3.size();
    if (N + M != L) return false;

    bool dp[N+1][M+1];
    for (int i = 1; i <= N; ++i)
        dp[i][0] = str1[i-1] == str3[i-1];
    for (int j = 1; j <= M; ++j)
        dp[0][j] = str2[j-1] == str3[j-1];

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            dp[i][j] = dp[i-1][j] && str1[i-1] == str3[i+j-1] || 
            dp[i][j-1] && str2[j-1] == str3[i+j-1];

    return dp[N][M];
}