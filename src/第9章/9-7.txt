//文件：select.cpp
//包括机器选择selection_by_machine和玩家选择selection_by_player函数的实现
#include "p_r_s.h"

p_r_s selection_by_machine( )
{   int select = (rand( ) * 3 / (RAND_MAX + 1)); //产生0到2之间的随机数

    cout << " I am ";
    switch(select){
        case 0: cout << "paper. "; break;
        case 1: cout << "rock. "; break;
        case 2: cout << "scissor. "; break;
    }

    return ((p_r_s) select); //强制类型转换，将0到2分别转换成paper, rock, scissor
}

p_r_s selection_by_player()
{   char c;
    p_r_s player_choice;

    prn_help(); //显示输入提示
    cout << "please select: "; cin >> c;
    switch(c) {
        case 'p':  player_choice = paper;   cout << "you are paper. "; break;
        case 'r':  player_choice = rock;   cout << "you are rock. "; break;
        case 's':  player_choice = scissor;  cout << "you are scissor. ";break;
        case 'g':  player_choice = game;   break;
        case 'q':  player_choice = quit;  break;
        default :  player_choice = help;  break;
    }
    return player_choice;  
}

