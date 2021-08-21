template <class Record,class Compare>
int QuickSorter<Record,Compare>::Partition(Record R[], int low, int high) 
{
    Record pivot;			//存放基准值的临时变量
    int i = low-1;		//i为左指针,j为右指针
    int j = high+1;	
    int  pivot = SelectPivot(left, right);	//将基准值存放在临时变量中
    while (1)  {				//开始进行分割,i ,j开始向中间移动, 直到相遇
        //j指针向左移动, 直到找到一个小于等于基准值的记录
        while (Compare::gt(R[--j], R[pivot])) 
            //i指针向右移动, 直到找到一个大于等于基准值的记录
            while (Compare::lt(R[++i], R[pivot]))
                //如果i和j尚未相遇, 就交换
                if (i < j) swap(R[j], R[i]);
                else if  j <> high return j;
                else return j-1;
    }	
}
