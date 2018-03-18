/****************************************************************************** #
#
#
#    main.cpp
#
#    By: Marc G Tan <marc> <findmarcg@gmail.com>
#
#    Created: 2018/01/20 10:24:58 by marc
#    Updated: 2018/01/20 10:24:58 by marc
#
# **************************************************************************** */


#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>

using namespace std;

int n,map[1010][1010],start_x,start_y,dest_x,dest_y;
char b[1010];
int head, tail;
int next_[4][2] = { {1,0} ,{0,1} ,{-1,0} ,{0,-1} };

struct info {
    int x, y;
    int step;
}   queue[1000010];

void search(int x, int y)
{
    head = 0;
    tail = 1;
    queue[1].x = x;
    queue[1].y = y;
    queue[1].step = 0;
    map[x][y] = 1;
    while (head < tail)
    {
        head++;
        for (int i = 0;i < 4;i++)
        {
            x = queue[head].x + next_[i][0];
            y = queue[head].y + next_[i][1];
            if (!map[x][y] && x > 0 && y > 0 && x <= n&&y <= n)
            {
                tail++;
                queue[tail].x = x;
                queue[tail].y = y;
                map[x][y] = queue[head].step + 1;
                queue[tail].step=queue[head].step + 1;
                if (map[dest_x][dest_y] > 0)
                {
                    cout << map[dest_x][dest_y] << endl;
                    return;
                }
            }
        }
    }
}
int main() {
    while (cin >> n)
    {
        memset(map, 0, sizeof(map));
        memset(queue, 0, sizeof(queue));
        gets(b);
        for (int i = 1;i <= n;i++)
        {
            gets(b);
            for (int j = 1;j <= n;j++)
            map[i][j] = b[j - 1]-'0';
        }
        cin >> start_x >> start_y >> dest_x >> dest_y;
        if (start_x == dest_x&&start_y == dest_y)
            cout << "0" <<endl;
        else
            search(start_x, start_y);
    }
    return 0;
}
