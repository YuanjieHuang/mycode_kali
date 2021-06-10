程序清单4-14
// ***************************************************************
// hanoi.cpp
// 用递归方式解决汉诺塔问题
// ***************************************************************

#include <iostream>
using namespace std;

//moveTower函数将diskNum个盘从from柱移到to柱，可以借助aux柱
void moveDisk(int diskNum, char from, char to, char aux)
{
	if (diskNum == 1) { // 仅有一个盘时，直接从from柱移到to柱
         cout << "Move disk1 from " << from << " to " << to << "\n";
	} 
	else {    
		// 将diskNum - 1个盘从from柱移到aux柱，借助于to柱
		moveDisk(diskNum - 1, from, aux, to);
		// 将最下面的盘从from柱移到to柱
		cout << "Move disk" << diskNum << " from " << from << " to " << to << "\n";
		// 将diskNum - 1个盘从aux柱移到to柱，借助于from柱
		moveDisk(diskNum - 1, aux, to, from);
    }
}

int main()
{
	// 将6个盘从A柱移到C柱，移动时利用B柱
	moveDisk(6, 'A', 'C', 'B'); 
	
	return 0;
}
