/****************************************************************************** #
#
#
#    main.cpp
#
#    By: Marc G Tan <findmarcg@gmail.com>
#
#    Created: 2018/01/20 10:09:35 by Marc G Tan
#    Updated: 2018/01/20 10:22:26 by Marc G Tan
#
# **************************************************************************** */


#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int n;
int min_dist = INT_MAX;

char** map;
int** map_2;

struct point {
    int x, y, dist;
    char position;
};

int moves[4][2] = {
    {1,0},{0,1},{-1,0},{0,-1}
};

int ft_is_valid(char**map,int x,int y)
{

    if (x < n && x >=0 && y < n && y>=0
        && map[x][y]!='#' && map_2[x][y])
        return (1);

    return (0);

}

void BFS(int start_x,int start_y)
{
    vector<point> queue;

    queue.push_back({start_x,start_y,0,'S'});

    map_2[start_x][start_y] = 0;

    while (queue.size() != 0)
    {
        point first = queue.at(0);
        queue.erase(queue.begin());
        if (first.position=='E')
        {
            if(min_dist > first.dist)
                min_dist = first.dist;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int temp_x = first.x + moves[i][0];
            int temp_y = first.y + moves[i][1];
            if (ft_is_valid(map,temp_x,temp_y))
            {
                queue.push_back({temp_x,temp_y,first.dist+1,map[temp_x][temp_y]});
                map_2[temp_x][temp_y] = 0;
            }
        }
    }
}

int main()
{
    cin >> n;

    map_2 = new int*[n];

    for(int i=0;i<n;i++)
        map_2[i] = new int[n];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            map_2[i][j] = 1;

    map = new char*[n];
    for (int i=0;i<n;i++)
        map[i] = new char[n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin>>map[i][j];

    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(map[i][j] == 'S')
            BFS(i,j);
        }
    }

    if (min_dist == INT_MAX)
        cout << -1;
    else
        cout << min_dist;
    cout << endl;
    return (0);
}
