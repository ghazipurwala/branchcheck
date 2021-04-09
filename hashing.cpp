#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
const int mod = 1e9 + 7;
const int base = 33;
int pw[N];
int inv[N];
int hashval[N];
int backhasval[N];
int add(int a, int b, int mod)
{
    int res = (a + b) % mod;
    if (res < 0)
    {
        res += mod;
    }
    return res;
}

int mult(int a, int b, int mod)
{
    int res = (a * 1LL * b) % mod;
    if (res < 0)
    {
        res += mod;
    }
    return res;
}

int power(int a, int b, int mod)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = mult(res, a, mod);
        }
        a = mult(a, a, mod);
        b >>= 1;
    }
    return res;
}

void preval()
{
    pw[0] = 1;
    for (int i = 1; i < N; i++)
    {
        pw[i] = mult(pw[i - 1], base, mod);
    }
    int pw_inv = power(base, mod - 2, mod);
    inv[0] = 1;
    for (int i = 1; i < N; i++)
    {
        inv[i] = mult(inv[i - 1], pw_inv, mod);
    }
}

void buildstring(string s)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        hashval[i] = add((i == 0) ? 0 : hashval[i - 1], mult(pw[i], s[i] - 'a', mod), mod);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        backhasval[i] = add((i == n - 1) ? 0 : hashval[i + 1], mult(pw[n - i - 1], s[i] - 'a', mod), mod);
    }
}

int gethashvalforward(int x, int y)
{
    int res = add(hashval[y], (x == 0) ? 0 : -hashval[x - 1], mod);
    res = mult(res, inv[x], mod);
    return res;
}
int gethasvalbackward(int x, int y,int n)
{
       int res=add(backhasval[x],(y==n-1)?0:-backhasval[y+1],mod);
       res=mult(res,inv[y],mod);
       return res;

}

int main()
{
}