    #include <iostream>
    using namespace std;

    class demo0{
    public:
       demo0():num(new int(0)){
          cout<<"construct!"<<endl;
       }
       //拷贝构造函数
       demo0(const demo0 &d):num(new int(*d.num)){
          cout<<"copy construct!"<<endl;
       }
       ~demo0(){
          cout<<"class destruct!"<<endl;
       }
    private:
       int *num;
    };
    demo0 get_demo0(){
        return demo0();
    }

    int main(){
        demo0 a = get_demo0();
        return 0;
    }


class demo{
    public:
        demo():num(new int(0)){
            cout<<"construct!"<<endl;
        }
        demo(const demo &d):num(new int(*d.num)){
            cout<<"copy construct!"<<endl;
        }
        //添加移动构造函数
        demo(demo &&d):num(d.num){
            d.num = NULL;
            cout<<"move construct!"<<endl;
        }
        ~demo(){
            cout<<"class destruct!"<<endl;
        }
    private:
        int *num;
    };
    demo get_demo(){
        return demo();
    }
    int main(){
        demo a = get_demo();
        return 0;
    }


class movedemo{
public:
    movedemo():num(new int(0)){
        cout<<"construct!"<<endl;
    }
    //拷贝构造函数
    movedemo(const movedemo &d):num(new int(*d.num)){
        cout<<"copy construct!"<<endl;
    }
    //移动构造函数
    movedemo(movedemo &&d):num(d.num){
        d.num = NULL;
        cout<<"move construct!"<<endl;
    }
public:     //这里应该是 private，使用 public 是为了更方便说明问题
    int *num;
};
int main(){
    movedemo demo;
    cout << "demo2:\n";
    movedemo demo2 = demo;
    //cout << *demo2.num << endl;   //可以执行
    cout << "demo3:\n";
    movedemo demo3 = std::move(demo);
    //此时 demo.num = NULL，因此下面代码会报运行时错误
    //cout << *demo.num << endl;
    return 0;
}
    



class first {
public:
    first() :num(new int(0)) {
        cout << "construct!" << endl;
    }
    //移动构造函数
    first(first &&d) :num(d.num) {
        d.num = NULL;
        cout << "first move construct!" << endl;
    }
public:    //这里应该是 private，使用 public 是为了更方便说明问题
    int *num;
};
class second {
public:
    second() :fir() {}
    //用 first 类的移动构造函数初始化 fir
    second(second && sec) :fir(move(sec.fir)) {
        cout << "second move construct" << endl;
    }
public:    //这里也应该是 private，使用 public 是为了更方便说明问题
    first fir;
};
int main() {
    second oth;
    second oth2 = move(oth);
    //cout << *oth.fir.num << endl;   //程序报运行时错误
    return 0;
}
