题目描述：
现给定一张由方格组成的地图，你站在方格上，而且每步可以从自身这个方格走到相邻的方格上去。每一个方格有一个属性，字符’.’表示方格可以经过，字符’#’表示方格不可以经过经过。现在你有很多的起点方格和很多的终点方格（当然也可能没有起点方格或是终点方格）。起点方格用字符’S’表示，终点方格用’E’表示。起点方格和终点方可以经过的。

现在你可以选择从任意一个起点出发，走到任意一个终点，问从起点走到中点的最短的步数是多少。

输入描述：
第一行是一个正整数n，表示地图的边长。

之后n行，每行n个字符，表示每个方格的属性。

数据范围保证n≤1000。

输出描述：
只有一个整数，如果能从起点走终点，输出最短步数，否则输出-1。

样例输入：
3
S.E
.#.
.S.

样例输出：
2
