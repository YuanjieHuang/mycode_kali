#include <iostream.h>
#include "stack.h"
#include "position.h"

//全局变量
int **maze, m;
Stack<Position> *path;  //指向栈的指针

bool InputMaze()
{
    cout << "Enter maze size" << endl;
    cin >> m;
    Make2DArray(maze, m+2, m+2);
    cout << "Enter maze in row major order" << endl;
    for (int i=1; i<=m; i++)
        for (int j=1; j<=m; j++) cin >> maze[i][j];
    return true;
}

//查找从 (1,1)到(m,m)的路径：成功时返回 true, 否则返回false
bool FindPath()  
{   
    path = new Stack<Position>(m * m - 1);

    //初始偏移量
    Position offset[4];
    offset[0].row = 0; offset[0].col = 1; 	//右
    offset[1].row = 1; offset[1].col = 0; 	//下
    offset[2].row = 0; offset[2].col = -1; 	//左
    offset[3].row = -1; offset[3].col = 0; 	//上
   
    //初始四周墙
    for (int i = 0; i <= m+1; i++) {
        maze[0][i] = maze[m+1][i] = 1; 	//上下
        maze[i][0] = maze[i][m+1] = 1; 	//左右
    }

    Position here;
    here.row = 1;
    here.col = 1;
    maze[1][1] = 1; //避免回到入口
    int option = 0; //下次移动
    int LastOption = 3;
    
    //查找一条路径
    while (here.row != m || here.col != m) {	//不存在
        //找相邻单元
        int r, c;      
        while (option <= LastOption) {
            r = here.row + offset[option].row;
            c = here.col + offset[option].col;
            if (maze[r][c] == 0) break;
            option++; //下一选择
    }

    //找到相邻单元?
    if (option <= LastOption) {    //进到maze[r][c]
        path->Push(here);
        here.row = r; here.col = c;
        maze[r][c] = 1;        //设为 1避免再次访问
        option = 0;
    }
    else {      //路径没有找到, 则回溯
        if (path->IsEmpty()) return false;
        Position next;
        path->TopandPop(next);
        if (next.row == here.row)
            option = 2 + next.col - here.col;
        else option = 3 + next.row - here.row;
        here = next;
    }
    }

    return true;  //到了出口
}
