#include<bits/stdc++.h>

using namespace std ;

int64_t mulmod(int64_t a, int64_t b, int64_t c)
{
    int64_t x = 0 , y = a%c ;
    while(b>0)
    {
        if(b%2) x = (x+y)%c ;
        y=(y*2)%c;
        b/=2;
    }
    return x%c ;
}

int64_t modulo(int64_t a, int64_t b, int64_t c)
{
    int64_t x = 1 , y = a%c ;
    while( b > 0 )
    {
        if(b%2) x = mulmod(x,y,c) ;
        y=mulmod(y,y,c);
        b/=2;
    }
    return x%c ;
}

bool check(int64_t p, int64_t iteration)
{
    if (p==-1) return 0;
    if(p<2) return false ;
    if(p%2==0&&p!=2) return false ;

    int64_t s = p-1 ;
    while(s%2==0) s/=2;

    for(int64_t i=1;i<=iteration;i++)
    {
        int64_t a = rand() % (p-1)+1 , temp = s ;

        int64_t mod = modulo(a,temp,p);
        while(mod!=1&&mod!=p-1&&temp!=p-1)
        {
            mod = mulmod(mod,mod,p);
            temp*=2;
        }
        if(temp%2==0&&mod!=p-1) return false ;
    }
    //cout << p << '\n';
    return true ;
}

int64_t rev(int64_t x)
{
    int64_t res = 0;
    while (x)
    {
        res *= 10;
        int64_t r = x%10;
        if (r==3 || r==4 || r==7) return -1;
        if (r==6) res += 9;
        else if (r==9) res += 6;
        else res += r;
        x/=10;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int64_t n ;
    cin >> n;
    int64_t num = rev(n);
    if (check(n, 1000) && check(num, 1000)) cout << "yes\n";
    else cout << "no\n";
    return 0 ;
}