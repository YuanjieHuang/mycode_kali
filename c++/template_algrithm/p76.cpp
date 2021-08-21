
int safe(int location)	//若状态安全则返回1
{
    if ((goat(location) == cabbage(location))
                      &&(goat(location) != farmer(location)))
        return (0); 		//羊吃白菜
    if ((goat(location) == wolf(location))
                      && (goat(location) != farmer(location)))  
        return (0); 		//狼吃羊
    return (1);				//其他状态是安全的
}
