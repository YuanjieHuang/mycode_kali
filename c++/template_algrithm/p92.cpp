void findpath(int row, int col)
{
    int direct, next_row, next_col, k, l;
    direct = 0;
    while (direct < 4)
    {
        next_row = row + move[direct].vert;
        next_col = col + move[direct].horiz;
        if(maze[next_row][next_col] == 0)  {
            maze[next_row][next_col] = 2;
            if(next_row == MAX_ROW && next_col == MAX_COL)
                print_ans();
            else
                findpath(next_row, next_col);
            maze[next_row][next_col] = 0;
        }
        direct++;
    }
}
