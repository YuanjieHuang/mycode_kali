　　//类DivideByZeroException是用户定义的类，用于表示除0错
　　class DivideByZeroException {
　　public:
　　    DivideByZeroException(): message( "attempted to divide by zero" ) { }
　　    const char *what() const { return message; }
　　private:
　　    const char *message;
　　};
　　
