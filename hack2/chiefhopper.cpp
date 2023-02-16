#include <iostream>
#include <algorithm>
#include <stdio.h>

#define LL long long
#define getcx getchar//_unlocked

inline void inp( int &n )
 { n=0;int ch=getcx();
   while(ch<'0'||ch>'9') ch=getcx();
   while(  ch >= '0' && ch <= '9' )
      n = (n<<3)+(n<<1) + ch-'0', ch=getcx(); }  

using namespace std;

int n,i,H[100020];
LL ans;

int main(){inp(n);
for (i=1;i<=n;i++) inp(H[i]);
reverse(H+1,H+n+1);
for (i=1;i<=n;i++)
 ans=(ans+(LL)H[i]+1)/2LL;
cout<<ans<<endl;}
