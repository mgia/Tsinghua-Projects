/****************************************************************************** #
#
#
#    main.cpp
#
#    By: Marc G Tan <marc> <findmarcg@gmail.com>
#
#    Created: 2018/01/20 10:28:29 by marc
#    Updated: 2018/01/20 10:28:34 by marc
#
# **************************************************************************** */


#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
int		ft_try_move(int **board, int row, int col, int n);
void    ft_print(int **board, int n);

int		**ft_alloc_board(int n)
{
    int		**board;

    board = (int**)malloc(sizeof(int*)*n);
    for (int i=0;i<n;i++)
    {
        board[i] = (int*)malloc(sizeof(int)*n);
        for (int j=0;j<n;j++)
        cin>>board[i][j];
    }
    return (board);
}

int     ft_is_valid(int **board, int row, int col, int n)
{
    if (board[row][col] == 0)
    return (0);

    int i;
    for (i=0;i<n;i++)
    {
        if (board[row][i] == 2)
            return (0);
        if (board[i][col] == 2)
            return (0);
    }

    int j;
    for (i=row-1,j=col-1; i>=0&&j>=0; i--,j--)
        if (board[i][j] == 2)
            return (0);
    for (i=row+1,j=col+1; i<n&&j<n;i++,j++)
        if (board[i][j] == 2)
            return (0);
    for(i=row-1,j=col+1; i>=0&&j<n; i--,j++)
        if (board[i][j] == 2)
            return (0);
    for(i=row+1,j=col-1; i<n&&j>=0; i++,j--)
        if (board[i][j] == 2)
            return (0);
    return (1);
}

int     ft_count(int **board, int n)
{
    int count = 0;

    for (int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if (board[i][j] == 2) {
                count++;
            }
    return count;
}
int     ft_max(int a, int b)
{
    if (a > b)
        return (1);
    else
        return (0);
}

int     ft_next(int **board, int row, int col, int n)
{
    if (row == (n-1) && col == (n-1))
        return (ft_count(board,n));
    else if ((col + 1) < n)
        return (ft_try_move(board, row, col + 1, n));
    else if ((row + 1) < n)
        return (ft_try_move(board, row + 1, 0, n));
    return (0);
}

int		ft_try_move(int **board, int row, int col, int n)
{
    if (ft_is_valid(board, row, col, n))
    {
        int skip = ft_next(board, row, col, n);
        board[row][col]++;
        int add = ft_next(board, row, col, n);
        board[row][col]--;
        return (ft_max(skip, add) ? skip : add);
    }
    else
        return (ft_next(board, row, col, n));

}

void    ft_print(int **board, int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cout<<board[i][j]<<" ";
        cout<<endl;
    }
}

int     main()
{
    int n;
    int **board;

    cin>>n;
    board = ft_alloc_board(n);
    cout<<ft_try_move(board, 0, 0, n)<<endl;
    return (0);
}
