Class Person{
public:
	char name[20];
	char sex;  //性别, 'F'表示女性, 'M'表示男性
	…
}Person;
        
void DancePartner(Person dancer[],int num)
{	//结构数组dancer中存放跳舞的男女, num是跳舞的人数
	int i;
	Person p;
	CQueue Mdancers,Fdancers;
	Mdancers.MakeEmpty(); 	//男士队列初始化
	Fdancers.MakeEmpty();	//女士队列初始化
	for (i = 0; i < num; i++){	//依次将跳舞者依其性别入队
		p = dancer[i];       
		if (p.sex == 'F')
			Fdancers.EnQueue(p);   //排入女队
		else
			Mdancers.EnQueue(p);   //排入男队
	}
	cout << "The dancing partners are " << endl << endl;
	while(!Fdancers.IsEmpty() && !Mdancers.IsEmpty()){	//依次输入男女舞伴名
		p = Fdancers.DeQueue();     	//女士出队
		cout << p.name;				//打印出队女士名
		p = Mdancers.DeQueue();     	//男士出队
		cout << p.name << endl;    		//打印出队男士名
	}
	if (!Fdancers.IsEmpty()){ 			//输出女士剩余人数及队首女士的名字
		cout << endl << " There are " << Fdancers.currentsize 
			<<" women waitin for the next  round." << endl;
		p = Fdancers.GetFront();  	  //取队首
		cout << p.name << " will be the first to get a partner. " << endl;
	}
	else if (!Mdancers.IsEmpty())  { //输出男士剩余人数及队首女士的名字
		cout << endl<<" There are " << Mdancers.currentsize 
			<< " men waitin for the next  round."<<endl;
		p = Mdancers .GetFront();  //取队首
		cout << p.name << " will be the first to get a partner. " << endl;
	}
}
