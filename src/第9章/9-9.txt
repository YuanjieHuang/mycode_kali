//文件：print.cpp 
//包括所有与输出有关的模块,有prn_game_status、prn_help和report函数
#include "p_r_s.h"

int win_cnt = 0, lose_cnt = 0, tie_cnt = 0; //模块的内部状态

void prn_game_status()
{   cout << endl ;
    cout <<  "GAME STATUS:" << endl; 
    cout <<  "win:  " << win_cnt << endl;
    cout <<  "Lose: " <<  lose_cnt << endl;
    cout <<  "tie:    " <<  tie_cnt << endl;
    cout <<  "Total:" <<  win_cnt + lose_cnt + tie_cnt << endl;
}

void prn_help()
{   cout << endl
         <<  "The following characters can be used:\n"
         <<  "   p  for paper\n"
         <<  "   r   for rock\n"
         <<  "   s   for scissors\n"
         << "   g   print the game status\n"
         << "   h   help, print this list\n"
         << "   q   quit the game\n";
}

void report(outcome result)
{   switch(result) {  
      case win:  ++win_cnt; cout << "You win. \n";   break;
      case lose:  ++lose_cnt; cout << "You lose.\n";   break;
      case tie:    ++tie_cnt;    cout <<"A  tie.\n";   break;
      default:    cout <<
          " PROGRAMMER ERROR：Unexpected result!\n\n";        
          exit(1);
    }
}

