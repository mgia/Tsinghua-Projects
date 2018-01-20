/****************************************************************************** #
#
#
#    main.cpp
#
#    By: Marc G Tan <marc> <findmarcg@gmail.com>
#
#    Created: 2018/01/20 10:33:40 by marc
#    Updated: 2018/01/20 10:35:22 by marc
#
# **************************************************************************** */


#include <iostream>
using namespace std;

int         ft_is_all_ones(long long n)
{
    while(n>0)
    {
        if(n%10!=1)
        return (0);
        n/=10;
    }
    return (1);
}

int         ft_count_ones(long long n)
{
    int count = 0;

    while(n>0)
    {
        n/=10;
        count++;
    }
    return (count);
}

long long   ft_up(long long n)
{
    long long res=1;
    int len = ft_count_ones(n);
    for(int i=1;i<len;i++)
        res=res*10+1;
    if(res<n)
        res=res*10+1;
    return (res);
}

long long   ft_down(long long n)
{
    long long res=1;
    int len = ft_count_ones(n);
    for(int i=1;i<len;i++)
        res=res*10+1;
    if(res>n)
        res/=10;
    return (res);
}

int         ft_solve(long long n)
{
    if(n == 6)
        return (6);

    long long up = ft_up(n);
    long long down = ft_down(n);
    // cout<<up<<" "<<down<<endl;

    if(up==down)
        return (ft_count_ones(n));
    else if((up-n)<(n-down))
        return ft_count_ones(up)+ft_solve(up-n);
    else
        return ft_count_ones(down)+ft_solve(n-down);
}

int      main(){
    long long n;
    cin>>n;

    cout<<ft_solve(n)<<endl;
    return (0);
}
