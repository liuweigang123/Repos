#include<iostream>
#include<math.h>
#include<string>
using namespace std;
typedef struct {
	int weight;
	int parent, lchild, rchild;
} HTnode, *HuffmanTree;
typedef char **HuffmanCode;
int Select(HuffmanTree &HT, int n,int s1, int s2) {
	int k=0, l=0;
	for (int i = 0; i < n; i++) {
		if (HT->parent == 0) {
			if (HT[i].weight < k) {
				l = k;
				k = i;
			}
			else if (HT[i].weight < l) {
				l = i;
			}
		}
	}
	s1 = k;
	s2 = l;
	return s1, s2;
}
void HuffmanCodeing(HuffmanTree &HT, HuffmanCode &HC, int *w, int n) {
	HTnode *p;
	int m;
	char *cd;
	int i, s1, s2;
	if (n <= 1)	return;
	m = 2 * n - 1;
	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTnode));//malloc the storage and the 0 is out of use£»
	for (p = HT, i = 1; i <= n; ++i, ++p, ++w) *p = { *w,0,0,0 };
	for (; i <= m; ++i, ++p) *p = { 0,0,0,0 };
	for (i = n + 1; i < m; ++i) {
		Select(HT, i - 1, s1, s2);
		HT[s1].parent = i; HT[s2].parent = i;
		HT[i].lchild = s1; HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}//finish the HuffmanTree;
	HC = (HuffmanCode)malloc((n + 1) * sizeof(char*));
	cd = (char*)malloc(n * sizeof(char));
	cd[n - 1] = "\0";
}
