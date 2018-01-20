/****************************************************************************** #
#
#
#    main.cpp
#
#    By: Marc G Tan <marc> <findmarcg@gmail.com>
#
#    Created: 2018/01/20 10:39:41 by marc
#    Updated: 2018/01/20 10:40:40 by marc
#
# **************************************************************************** */


#include <iostream>
using namespace std;

int main()
{
    //create board
    //add scores
    //recreate score ranges
    //change board

    char board[10][10];
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            board[i][j]='.';

    int n;
    cin >> n;
    int number;
    int scores[10] = {0};

    for(int i=0;i<n;i++)
    {
        cin>>number;
        number/=10;
        if(number==10)
            scores[9]++;
        else
            scores[number]++;
    }

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<scores[i];j++)
            board[i][j]='@';
    }

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
            cout<<board[i][j];
        cout<<endl;
    }

    return (0);
}
