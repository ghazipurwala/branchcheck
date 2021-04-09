#include<bits/stdc++.h>
using namespace std;

template<class T>struct Seg{
    const T INF=INT_MAX;
    T comb(T a,T b){return min(a,b);}
    int n;
    vector<T>seg;
    void init(int _n){n=_n;seg.assign(2*n,INF);}
    void pull(int p){seg[p]=comb(seg[2*p],seg[2*p+1]);}
    void upd(int p,T val){seg[p+=n]=val;for(p>>=1;p;p>>=1){pull(p);}}
    T query(int l,int r){
        T ra=INF,rb=INF;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1){ra=comb(ra,seg[l++]);}
            if(r&1){rb=comb(rb,seg[--r]);}
        }
        return comb(ra,rb);
    }
    void print(){
        for(auto k:seg){cout<<k<<" ";}
    }
};

Seg<int>st;
int main(){
    int n,q;cin>>n>>q;
    st.init(n+1);
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        st.upd(i,a);
    }
    // st.print();
    for(int i=1;i<=q;i++){
         int t,u,v;
         cin>>t>>u>>v;
         if(t==1){
             st.upd(u,v);
         }else{
             cout<<st.query(u,v+1)<<"\n";
         }
    }
    return 0;
}