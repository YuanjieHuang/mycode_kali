程序清单12-2
// ***************************************************************
// ExcTypeMatching.cpp
// 功能：演示捕获异常时的类型匹配
// ***************************************************************

#include <iostream>
#include <string>

using namespace std;

class BaseException {
public:
	BaseException(const string msg = "") : message(msg) 
    	{ }

    	string what()
	{
        return message;
	}

private:
	string message;
};
 
class DerivedException : public BaseException {
public:
	DerivedException(const std::string msg = "") : BaseException(msg) 
    	{ }
};

int main() 
{
	for (int i =0; i < 2; i++) {
        try {
            if (i % 2 == 0)
			throw BaseException("exception1");
			else
                throw DerivedException("exception2");
		}
        catch(DerivedException e) {
            cout << "caught a derived exception: " << e.what() << endl;
		}
        catch(BaseException e) {
            cout << "caught a base exception: " << e.what() << endl;
        }
	}

	return 0;
} 
