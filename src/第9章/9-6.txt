//文件：9-6.cpp
//石头、剪子、布游戏的主模块
#include "p_r_s.h"

int main(void)
{   outcome  result;
    p_r_s player_choice, machine_choice;

    // seed the random number generator 
    srand(time(NULL));
 
    while((player_choice = selection_by_player()) != quit)
        switch(player_choice) { 
            case paper:    case rock:      case scissor:
                    machine_choice = selection_by_machine();
                    result = compare(player_choice, machine_choice);
                    report(result);  break;
            case game: prn_game_status();  break;
            case help: prn_help();   break;
            default:
                cout<< " PROGRAMMER ERROR：Cannot get to here!\n\n";      
                exit(1);
    }
    prn_game_status(); 
    return 0;
}

