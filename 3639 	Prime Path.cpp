//============================================================================
// Name         : Riham.cpp
// Author       : Remo
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
typedef	long long			ll;
typedef	long double		Ld;
#define	r(n)				scanf("%d",&n)
#define	rL(n)				scanf("%I64d",&n)
#define	p(n)				printf("%d\n",n)
#define	pL(n)				printf("%I64d",n)
#define	For(i,a,b)			for(int i=a;i<=b;i++)
#define	Set(v,d)			memset(v, d, sizeof(v))
#define	oo					1001  ///infinity
/** ---------------------------Declarations--------------------------- **/
int T,n,m,save;
const int Upperbound=10001;
bitset<Upperbound+1>prime;
/** ----------------------------Functions----------------------------- **/
void Sieve(){
    prime.set();
    prime[0]=prime[1]=0;
    for(int i=2;i*i<=Upperbound;i++)
        if(prime[i])
            for(int j=i*i;j<=Upperbound;j+=i)
                prime[j]=0;
}

void BFS(int s){
	queue<int>q;
	vector<int>d(Upperbound,oo);
	q.push(s);
	d[s]=0;
	while(!q.empty()){
		int v=q.front(); q.pop();
		if(v == m){ save=d[v]; break; }
		int num=v;
		For(i, 0, 9){
			int indx=(num/10)*10+i;
			if(indx>=1000 && prime[indx] && d[indx]==oo){
				q.push(indx);
				d[indx]=d[v]+1;
			}
			indx=(num/100)*100+i*10+(num%10);
			if(indx>=1000 && prime[indx] && d[indx]==oo){
				q.push(indx);
				d[indx]=d[v]+1;
			}
			indx=(num/1000)*1000+i*100+(num%100);
			if(indx>=1000 && prime[indx] && d[indx]==oo){
				q.push(indx);
				d[indx]=d[v]+1;
			}
			indx=i*1000+num%1000;
			if(indx>=1000 && prime[indx] && d[indx]==oo){
				q.push(indx);
				d[indx]=d[v]+1;
			}
		}

	}
}

ll Ipow(int base, int exp)
	{ll result = 1;
	while(exp)
	{if(exp & 1)result*=base;
		exp>>=1;base*=base;}
return result;}
//**********************************************************************************//
int main() {
	//freopen("Output.txt","w",stdout);
	Sieve();
	r(T);
	while(T--){
		r(n),r(m);
		if(n == m){
			puts("0");
			continue;
		}
		int j=n, k=m,Once=0;
		while(j){
			if(j%10 != k%10)
				Once++;
			j/=10, k/=10;
		}
		if(Once == 1){
			puts("1");
			continue;
		}
		BFS(n);
		save? p(save) : puts("Impossible") ;
	}
	return 0;
}

