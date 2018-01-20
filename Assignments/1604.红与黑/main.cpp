/****************************************************************************** #
#
#
#    main.cpp
#
#    By: Marc G Tan <marc> <findmarcg@gmail.com>
#
#    Created: 2018/01/20 10:30:38 by marc
#    Updated: 2018/01/20 10:30:56 by marc
#
# **************************************************************************** */


#include <iostream>
using namespace std;

char    **ft_alloc_map(int w, int h, int *start_pt)
{
    char **map;

    map = new char*[h];
    for (int i=0;i<h;i++)
    {
        map[i] = new char[w];
        for(int j=0;j<w;j++) {
            cin>>map[i][j];
            if(map[i][j]=='@')
            {
                start_pt[0]=i;
                start_pt[1]=j;
            }
        }
    }
    return (map);
}


void    ft_print(char **map, int w, int h)
{
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++)
            cout<<map[i][j];
        cout<<endl;
    }
}

int     ft_try_move(char **map, int row, int col, int w, int h)
{
    if(row >= h || row < 0 || col >= w || col < 0
        || map[row][col] == '#')
        return (0);

    else if(map[row][col] == '.'|| map[row][col] == '@')
    {
        map[row][col]='#';
        return (1 + ft_try_move(map,row+1,col,w,h)
                + ft_try_move(map, row-1,col,w,h)
                + ft_try_move(map,row,col+1,w,h)
                + ft_try_move(map,row,col-1,w,h));
    }
    return (0);
}

int     main()
{
    int w, h;
    cin>>w>>h;

    char **map;
    int *start_pt;
    start_pt = new int[2];
    map = ft_alloc_map(w,h, start_pt);
    cout<<ft_try_move(map, start_pt[0], start_pt[1], w, h)<<endl;
    return (0);
}
