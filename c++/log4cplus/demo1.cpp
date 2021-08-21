#include <log4cplus/log4cplus.h>
#include <log4cplus/logger.h>
#include <log4cplus/configurator.h>
#include <log4cplus/helpers/loglog.h>
#include <log4cplus/helpers/stringhelper.h>
// #include <log4cplus/helpers/sleep.h>
#include <log4cplus/loggingmacros.h>
#include <iostream>
using namespace log4cplus;
using namespace log4cplus::helpers;
int main()
{
    //用Initializer类进行初始化
    log4cplus::Initializer initializer;
 
    //第1步：创建ConsoleAppender
    log4cplus::SharedAppenderPtr appender(new log4cplus::ConsoleAppender());
 
    //第2步：设置Appender的名称和输出格式（SimpleLayout）
    appender->setName(LOG4CPLUS_TEXT("console"));
    appender->setLayout(std::unique_ptr<log4cplus::Layout>(new log4cplus::SimpleLayout));
 
    //第3步：获得一个Logger实例，并设置其日志输出等级阈值
    log4cplus::Logger logger = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT ("test"));
    logger.setLogLevel(log4cplus::INFO_LOG_LEVEL);
 
    //第4步：为Logger实例添加ConsoleAppender
    logger.addAppender(appender);
 
    //第5步：使用宏将日志输出
    LOG4CPLUS_INFO(logger, LOG4CPLUS_TEXT("Hello world"));
 
    return 0;
}
// g++ -llog4cplus -lpthread -o test