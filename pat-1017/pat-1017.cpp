#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
#define WMAX 101
#define OPEN 8*3600
#define CLOSE 17*3600
class Cus{
public:
 int arrt;
 int wait;
 int last;
 bool operator <(Cus &c)const{
 return this -> arrt < c.arrt;
 }
};
int wfinish[WMAX];
int n,k;
int h,m,s,l;
int main()
{
 cin>>n>>k;
 Cus* cus = new Cus[n + 1];
 for(int i = 0; i < n ;i++)
 {
 scanf("%02d:%02d:%02d%d",&h,&m,&s,&l);
 cus[i].arrt = h*3600 + m*60 + s;
 cus[i].last = l*60;
 }
 //
 sort(cus,cus+n);
 for(int i = 0;i < k; i++)
 wfinish[i] = OPEN;
 //
 int cnt = 0;
 for(int i = 0; i < n; i++)
 {
 if(cus[i].arrt > CLOSE)
 break;
 cnt++;
 int min_ = 1<<30;
 int f;
 for(int j = 0; j < k; j++)
 if(min_ > wfinish[j])
 min_ = wfinish[j],f = j;
 cus[i].wait = wfinish[f] > cus[i].arrt ? (wfinish[f] - cus[i].arrt) : 0;
 wfinish[f] = wfinish[f] > cus[i].arrt ? (wfinish[f] + cus[i].last) : (cus[i].arrt + cus[i].last);
 }

 double total = 0;
 for(int i = 0; i < cnt; i++)
 total += cus[i].wait;
 printf("%.1lf\n",total/60/cnt);
}
