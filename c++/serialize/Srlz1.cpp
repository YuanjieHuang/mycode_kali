//Srlz1.cpp： 将一个类的一个对象序列化到文件
   #include <iostream>
   #include <fcntl.h>
   #include <vector>
   #include <stdio.h>
   using namespace std;
 //定义类CA
   //数据成员：int x;
  //成员函数：Serialize：进行序列化函数
  //             Deserialize反序列化函数
  //             Show：数据成员输出函数
  class CA
  {
      private:
          int x;  //定义一个类的数据成员。       public:
          CA()    //默认构造函数
          {
              x = ;
          }
          CA(int y):x(y)    //定义构造函数，用初始化列表初始化数据成员
          {
          }
          virtual ~CA()    //析构函数
          {
          }
  public:
          //序列化函数：Serialize
          //成功，返回0，失败，返回0；
          int Serialize(const char* pFilePath) const
          {
              int isSrlzed = -;
              FILE* fp;   //define a file pointer
              //以读写方式打开文件，并判断是否打开；
  if ((fp = fopen(pFilePath, "w+")) == NULL)
           {
                  printf("file opened failure\n");
                  return -;  //若打开失败，则返回-1；
              }
              //调用fwrite函数，将对象写入文件；
  isSrlzed = fwrite(&x, sizeof(int), , fp);    //判断写入是否成功；
  if ((- == isSrlzed) || ( == isSrlzed))
              {
                  printf("Serialize failure\n");
                  return -;  //若写入失败，则返回-1；
              }
              if(fclose(fp) != ) //关闭文件
              {
                  printf("Serialize file closed failure.\n");
                  return -;
              }
              printf("Serialize succeed.\n");
              return ;   //序列化成功，返回0；
         }           //反序列化函数：
          //成功，返回0，失败，返回-1；
          int Deserialize(const char* pFilePath)
          {
              int isDsrlzed = -;
              FILE* fp;
              //以读写方式打开文件，并判断是否打开；
              if ((fp = fopen(pFilePath, "r+")) == NULL)
              {
                  printf("file opened failure.\n");
                  return -;
              }
                 //调用fread函数，读取文件中的对象 ；
  isDsrlzed = fread(&x, sizeof(int), , fp);
  //判断是否成功读入
              if ((- == isDsrlzed)||( == isDsrlzed))
              {
                  printf("Deserialize failure.\n");
                  return -;    //若读取失败，则返回-1；
              }
              if(fclose(fp) != )
              {
                  printf("Deserialize file closed failure.\n");
                  return -;
              }
              printf("Deserialize succeed.\n");
              return ;        //反序列化成功，则返回0；
  }           //成员对象输出显示函数
          void Show()
          {
              cout<< "in Show():"<< x << endl;
          }
  };

 int main(int argc, char const *argv[])
 {
 CA as();    //定义一个类对象，并初始化；     
 //调用序列化函数，将对象as序列化到文件data.txt中；
 as.Serialize("data.txt");  
 CA ad;        //定义一个类对象，用来记录反序列化对象
 //调用反序列化函数，将文件data.txt中的对象反序列化到ad对象；
 ad.Deserialize("data.txt");  
 ad.Show();    //调用输出显示函数；  
 	return ;  
 }
