#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//to calculate a^b
ll binaryexpo(ll a,ll b){
  if(a==1){return 1;}
  ll res=1;
  while(b>0){
    if(b&1){
       res*=a;
    }
    a=a*a;
    b>>=1;
  }
  return res;
}
//binary expo with modulo for large number
ll binpow(ll a,ll b,ll modulo){
  if(a==1){return 1;}
  ll res=1;
  a%=modulo;
  while(b>0){
    if(b&1){
      res=res*a%modulo;
    }
    a=a*a%modulo;
    b>>=1;
  }
  return res;

}

int main(){

}
