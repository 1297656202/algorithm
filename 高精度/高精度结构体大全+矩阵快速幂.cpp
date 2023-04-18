#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;
const int mod=2009;
struct ww {
	typedef long long LL;
	static const int BASE=10000; //高进制
	static const int WIDTH=4; //高进制位数
	vector<int>s;
	ww() { //构造函数：初始赋0
		*this=0;
	}
	ww(const LL& num) { // 构造函数
		*this=num;
	}
	//赋值
	ww operator = (LL num) {
		s.clear();
		do {
			s.push_back(num%BASE);
			num/=BASE;
		} while(num>0);
		return *this;
	}
	ww operator = (const string& str) {
		s.clear();
		int x,len=(str.length()-1)/WIDTH+1;
		for(int i=0; i<len; i++) {
			int end=str.length()-i*WIDTH;
			int start=max(0,end-WIDTH);
			sscanf(str.substr(start,end-start).c_str(),"%d",&x);
			s.push_back(x);
		}
		return *this;
	}
	//比较
	bool operator < (const ww& b) {
		if(s.size()<b.s.size())return true;
		if(s.size()>b.s.size())return false;
		for(int i=s.size()-1; i>=0; i--) {
			if(s[i]<b.s[i])return true;
			if(s[i]>b.s[i])return false;
		}
		return false;
	}
	bool operator >= (const ww& b) {
		return !(*this<b);
	}
	bool operator <= (const ww& b) {
		return !(*this>b);
	}
	bool operator == (const ww& b) {
		if(s.size()!=b.s.size())return false;
		for(int i=0; i<s.size(); i++)
			if(s[i]!=b.s[i])return false;
		return true;
	}
	bool operator != (const ww& b) {
		return !(*this==b);
	}
	bool operator > (const ww& b) {
		return ((*this>=b)&&(*this!=b));
	}
	//+
	ww operator + (ww b) {
		ww c;
		c.s.clear();
		for(int i=0,g=0; ; i++) {
			if(g==0&&i>=s.size()&&i>=b.s.size())break;
			int x=g;
			if(i<s.size())x+=s[i];
			if(i<b.s.size())x+=b.s[i];
			c.s.push_back(x%BASE);
			g=x/BASE;
		}
		return c;
	}
	void operator += (ww b) {
		*this=*this+b;
	}
	ww operator + (const LL& b) {
		ww c;
		c=b;
		c+=*this;
		return c;
	}
	void operator += (const LL& b) {
		*this=*this+b;
	}
	//-
	ww operator - (ww b) {
		ww c;
		c=*this;
		if(c==b) {
			c=0;
			return c;
		}
		for(int i=0; i<c.s.size(); i++) {
			int tmp;
			if(i>=b.s.size())tmp=0;
			else tmp=b.s[i];
			if(c.s[i]<tmp) {
				c.s[i+1]-=1;
				c.s[i]+=BASE;
			}
			c.s[i]-=tmp;
		}
		while(c.s.back()==0&&c.s.size()>1)c.s.pop_back();
		return c;
	}
	void operator -= (ww b) {
		*this=*this-b;
	}
	ww operator - (const LL& b) {
		ww c,d=*this;
		c=b;
		d-=c;
		return d;
	}
	void operator -= (const LL& b) {
		*this=*this-b;
	}
	//*
	ww operator * (LL b) {
		ww c;
		if(b==0) {
			c=0;
			return c;
		}
		c.s.clear();
		for(int i=0; i<s.size(); i++)c.s.push_back(s[i]*b);
		for(int i=0; i<c.s.size()-1; i++) {
			c.s[i+1]+=c.s[i]/BASE;
			c.s[i]%=BASE;
		}
		while(c.s.back()>=BASE) {
			int now=c.s.back();
			c.s.back()%=BASE;
			c.s.push_back(now/BASE);
		}
		return c;
	}
	void operator *= (LL b) {
		*this=*this*b;
	}
	ww operator * (const ww& b) {
		ww c;
		c.s.resize(s.size()+b.s.size());
		for(int i=0; i<s.size(); i++)
			for(int j=0; j<b.s.size(); j++)c.s[i+j]+=s[i]*b.s[j];
		for(int i=0; i<c.s.size()-1; i++) {
			c.s[i+1]+=c.s[i]/BASE;
			c.s[i]%=BASE;
		}
		while(c.s.back()==0&&c.s.size()>1)c.s.pop_back();
		return c;
	}
	void operator *= (const ww& b) {
		*this=*this*b;
	}
	// /
	ww operator / (LL k) {
		LL d=0;
		ww c;
		c=*this;
		for(int i=c.s.size()-1; i>=0; i--) {
			d=d*BASE+c.s[i];
			c.s[i]=d/k;
			d%=k;
		}
		while(c.s.back()==0&&c.s.size()>1)c.s.pop_back();
		return c;
	}
	void operator /= (LL k) {
		*this=*this/k;
	}
	ww Copy(const ww& b,int x) {
		ww t;
		t.s.resize(b.s.size()+x);
		for(int i=0; i<b.s.size(); i++)t.s[i+x]=b.s[i];
		return t;
	}
	ww operator / (const ww& b) {
		ww c,d;
		c.s.resize(s.size()-b.s.size()+1);
		d=*this;
		for(int i=c.s.size()-1; i>=0; i--) {
			ww t;
			t=Copy(b,i);
			while(d>=t) {
				(c.s[i])++;
				d-=t;
			}
		}
		while(c.s.back()==0&&c.s.size()>1)c.s.pop_back();
		return c;
	}
	void operator /= (const ww& b) {
		*this=*this/b;
	}
	//%
	ww operator % (const ww& b) {
		ww c=*this;
		ww d=c/b;
		return c-d*b;
	}
	void operator %= (const ww& b) {
		*this=*this%b;
	}
	ww operator % (const LL& k) {
		ww c=*this;
		ww d=c/k;
		return c-d*k;
	}
	void operator %= (const LL& k) {
		*this=*this%k;
	}
	//±
	ww operator + () {
		return *this;
	}
	ww operator - () {
		ww a=*this;
		return a;
	}
	ww operator ++ () {
		*this+=1;
		return *this;
	}
	const ww operator ++ (int) {
		ww tmp=*this;
		*this=*this+1;
		return tmp;
	}
	ww operator -- () {
		*this-=1;
		return *this;
	}
	const ww operator -- (int) {
		ww tmp=*this;
		*this=*this-1;
		return tmp;
	}
	friend istream& operator >> (istream& input,ww& x) {
		string s;
		if(!(input>>s))return input;
		x=s;
		return input;
	}
	friend ostream& operator << (ostream& output,const ww& x) {
		output<<x.s.back();
		for(int i=x.s.size()-2; i>=0; i--) {
			char buf[20];
			sprintf(buf,"%04d",x.s[i]);
			for(int j=0; j<strlen(buf); j++)output<<buf[j];
		}
		return output;
	}
};
/*ww N;
struct Matrix
{
	int A[3][3];
	Matrix operator * (const Matrix &rhs)
	{
		Matrix res;
		memset(res.A,0,sizeof(res.A));
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				for(int k=0;k<3;k++)
					res.A[i][j]=(res.A[i][j]+A[i][k]*rhs.A[k][j]%mod)%mod;
		return res;
	}
	Matrix operator ^ (ww b)
	{
		Matrix s;
		memset(s.A,0,sizeof(s.A));
		s.A[0][0]=s.A[1][1]=s.A[2][2]=1;
		while(b!=0)
		{
			if(b%2!=0)s=s*(*this);
			(*this)=(*this)*(*this);
			b/=2;
		}
		return s;
	}
};
Matrix A;
int main()
{
	int P;
	cin>>N>>P;
	A.A[0][0]=1;
	A.A[0][1]=A.A[1][1]=P;
	A.A[0][2]=A.A[1][2]=A.A[2][2]=P;
	cout<<(A^N).A[0][2];
	return 0;
}
