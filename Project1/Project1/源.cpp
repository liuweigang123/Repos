#include<math.h>
#include<iostream>
using namespace std;
int Violentmatch(char *s, char *p)
{
	int plen = strlen(p);
	int slen = strlen(s);

	int i = 0;
	int j = 0;

	while (i < plen && j < slen)
	{
		if (s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j == plen)
		return i - j;
	else
		return  -1;
}

int kmp_algorithm(char *s, char *p)
{
	int slen = strlen(s);
	int plen = strlen(p);

	int i = 0;
	int j = 0;

	while (i < slen && j < plen)
	{
		if (s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{

		}
	}

}

void getnext(char *p, int next[])
{
	int plen = strlen(p);
	next[0] = -1;
	int k = -1;
	int i = 0;
	while (i < plen - 1)
	{
		if (k == -1 || p[i] == p[k])
		{
			k++;
			i++;
			next[i] = k;
		}
		else
		{
			k = next[k];
		}
	}
}

int main()
{
	//char *p, *s;
	cout << "hello world" << endl;
	//cin >> s;
	//printf("1111");
	//cin >> p;
	//Violentmatch(p, s);
}