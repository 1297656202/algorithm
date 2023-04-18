#include <cstdio>
#include <cstring>
#include <algorithm>

char str[1000010];
int n, a[2000100], sa[2000100], typ[2000100], c[1000100], p[2000100], 
sbuc[1000100], lbuc[1000100], name[1000100];

inline int islms(int *typ, int i)
{
	return !typ[i] && (i == 1 || typ[i - 1]);
}

int cmp(int *s, int *typ, int p, int q)
{
	do
	{
		if (s[p] != s[q]) return 1;
		p++;  q++;
	} while (!islms(typ, p) && !islms(typ, q));
	return (!islms(typ, p) || !islms(typ, q) || s[p] != s[q]);
}

void isort(int *s, int *sa, int *typ, int *c, int n, int m)
{
	int i;
	for (lbuc[0] = sbuc[0] = c[0], i = 1; i <= m; i++)
	{
		lbuc[i] = c[i - 1] + 1;
		sbuc[i] = c[i];
	}
	for (i = 1; i <= n; i++)
		if (sa[i]>1 && typ[sa[i] - 1])
			sa[lbuc[s[sa[i] - 1]]++] = sa[i] - 1;
	for (i = n; i >= 1; i--)
		if (sa[i]>1 && !typ[sa[i] - 1])
			sa[sbuc[s[sa[i] - 1]]--] = sa[i] - 1;
}

void build_sa(int *s, int *sa, int *typ, int *c, int *p, int n, int m)
{
	int i;
	for (i = 0; i <= m; i++) c[i] = 0;
	for (i = 1; i <= n; i++) c[s[i]]++;
	for (i = 1; i <= m; i++) c[i] += c[i - 1];
	typ[n] = 0;
	for (i = n - 1; i >= 1; i--)
		if (s[i]<s[i + 1]) typ[i] = 0;
		else if (s[i]>s[i + 1]) typ[i] = 1;
		else typ[i] = typ[i + 1];
		int cnt = 0;
		for (i = 1; i <= n; i++)
			if (!typ[i] && (i == 1 || typ[i - 1])) p[++cnt] = i;
		for (i = 1; i <= n; i++) sa[i] = 0;
		for (i = 0; i <= m; i++) sbuc[i] = c[i];
		for (i = 1; i <= cnt; i++)
			sa[sbuc[s[p[i]]]--] = p[i];
		isort(s, sa, typ, c, n, m);
		int last = 0, t = -1, x;
		for (i = 1; i <= n; i++)
		{
			x = sa[i];
			if (!typ[x] && (x == 1 || typ[x - 1]))
			{
				if (!last || cmp(s, typ, x, last))
					name[x] = ++t;
				else name[x] = t;
				last = x;
			}
		}
		for (i = 1; i <= cnt; i++)
			s[n + i] = name[p[i]];
		if (t<cnt - 1) build_sa(s + n, sa + n, typ + n, c + m + 1, p + n, cnt, t);
		else
			for (i = 1; i <= cnt; i++)
				sa[n + s[n + i] + 1] = i;
		for (i = 0; i <= m; i++) sbuc[i] = c[i];
		for (i = 1; i <= n; i++) sa[i] = 0;
		for (i = cnt; i >= 1; i--)
			sa[sbuc[s[p[sa[n + i]]]]--] = p[sa[n + i]];
		isort(s, sa, typ, c, n, m);
}

int main()
{
	scanf("%s", str);
	n = strlen(str);
	int i;
	for (i = 1; i <= n; i++)
		a[i] = str[i - 1];
	a[++n] = 0;
	build_sa(a, sa, typ, c, p, n, 200);
	for (i = 2; i <= n; i++)
		printf("%d%s", sa[i], i<n ? " " : "\n");
	return 0;
}
