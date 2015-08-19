#include <iostream>
#include <cstring>
using namespace std;
int WordAnalysis(char *p,char *q)
{
	char *s=p;
	int num=0;
	while(p<q)
	{
		num=num*10+*p -'0';
		p++;
	}
	if(num<0||num>255) return 0;
	else if(num!=0&&s[0]=='0') return 0;
	return 1;
}
 int isIPAddressValid(char *pszIPAddr)
{
	
    if(pszIPAddr == NULL)
    {
        return 0;
    }
    int size = strlen(pszIPAddr);
    int start = 0;
    while(pszIPAddr[start] == ' ')//ȥ��ǰ��Ŀո�
    {
        ++start;
    }
    int end = size - 1;
    while(pszIPAddr[end] == ' ')//ȥ������Ŀո�
    {
        --end;
    }
    int num = 0;
	int i;
    int pointCount = 0;
    int first = start;
	char *p=pszIPAddr+start,*q=pszIPAddr;//p is the pointer to the word,q point to '.' 
	for(i = start;i <= end;)
	{
	//	p=pszIPAddr+i;
		while(pszIPAddr[i]!='.'&&i<=end)
		{
			++i;
		}
		if(i>end) q=&pszIPAddr[i];// ���һ��q�Ҳ�����.'�������Խ��
		else q=&pszIPAddr[i];
		if(WordAnalysis(p,q)==0) return 0;
		p=q+1;
		++i;
	}
	return 1;
}
 int main()
 {
	 char s[30];
	 
	 gets(s);
	 printf("%d\n",isIPAddressValid(s));
	
	 getchar();
 }

/*
bool isIPAddressValid(const char* pszIPAddr)
{
    if(pszIPAddr == NULL)
    {
        return false;
    }//if
    int size = strlen(pszIPAddr);
    // ȥ��ǰ��0
    int start = 0;
    while(pszIPAddr[start] == ' ')
    {
        ++start;
    }//while
    // ȥ����0
    int end = size - 1;
    while(pszIPAddr[end] == ' ')
    {
        --end;
    }//while
    int num = 0;
    int pointCount = 0;
    int first = start;
    for(int i = start;i <= end+1;++i)
    {
        if(pszIPAddr[i] >= '0' && pszIPAddr[i] <= '9')
        {
            num = num * 10 + pszIPAddr[i] - '0';
        }//if
        else if(pszIPAddr[i] == '.' || i == end + 1)
        {
            if(i == start || (pszIPAddr[i-1] < '0' || pszIPAddr[i-1] > '9'))
            {
                return false;
            }
            // ��֤.����
            if(pszIPAddr[i] == '.')
            {
                ++pointCount;
                if(pointCount > 3)
                {
                    return false;
                }//if
            }//if
            // ��֤����
            if(num > 255 || num < 0)
            {
                return false;
            }//if
            // ��0��ͷ�Ҳ�Ϊ0 ���磺023
            if(num != 0 && pszIPAddr[first] == '0')
            {
                return false;
            }//if
            first = i+1;
            num = 0;
        }//else
        else
        {
            return false;
        }//else
    }//for
    if(pointCount != 3)
    {
        return false;
    }
    return true;
}
*/