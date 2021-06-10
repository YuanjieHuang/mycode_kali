程序清单3-3
switch (answer){
	case 'a':
	case 'A': 
		cout << "The answer is wrong!" << endl;
		break;
	case 'b': 
	case 'B': 
		cout << "Sorry, you did not get the right answer!" << endl;
		break;
	case 'c': 
	case 'C': 
		cout << "Congratulation! The answer is correct!" << endl;
		break;
	case 'd': 
	case 'D': 
		cout << "Your answer is not the right one!" << endl;
		break;
	case 'e':
	case 'E': 
		cout << "Wrong answer!" << endl;
		break;
	default: 
		cout << "You inputted an invalid answer!" << endl;
		break;
}
