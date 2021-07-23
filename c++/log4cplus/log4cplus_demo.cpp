#include <log4cplus/logger.h>
#include <log4cplus/configurator.h>
#include <log4cplus/helpers/loglog.h>
#include <log4cplus/helpers/stringhelper.h>
// #include <log4cplus/helpers/sleep.h>
#include <log4cplus/loggingmacros.h>
#include <iostream>
using namespace log4cplus;
using namespace log4cplus::helpers;
Logger log_1 =  Logger::getInstance(LOG4CPLUS_TEXT("test.log_1"));
Logger log_2 =  Logger::getInstance(LOG4CPLUS_TEXT("test.log_2"));
Logger log_3 =  Logger::getInstance(LOG4CPLUS_TEXT("test.log_3"));
void printMsgs(Logger& logger)
{
    LOG4CPLUS_TRACE_METHOD(logger, LOG4CPLUS_TEXT("printMsgs()"));
    //LOG4CPLUS_DEBUG(logger, "printMsgs()");
    LOG4CPLUS_INFO(logger, "printMsgs()");
    //LOG4CPLUS_WARN(logger, "printMsgs()");
    //LOG4CPLUS_ERROR(logger, "printMsgs()");
    LOG4CPLUS_ERROR_FMT(logger, "printMsgs(%s)", "helloworld");
}
int main()
{
    std::cout<< LOG4CPLUS_TEXT("Entering main()...") << std::endl;
    log4cplus::initialize();
    LogLog::getLogLog()->setInternalDebugging(true);
    Logger root = Logger::getRoot();
    try 
    {
        ConfigureAndWatchThread configureThread(
            LOG4CPLUS_TEXT("log4cplus.properties"), 5 * 1000);
        LOG4CPLUS_WARN(root, "Testing....");
        for(int i=0; i<4; ++i) {
            //printMsgs(log_1);
            printMsgs(log_2);
            //printMsgs(log_3);
            // log4cplus::helpers::sleep(1);
        }
    }
    catch(...) {
        std::cout<< LOG4CPLUS_TEXT("Exception...") << std::endl;
        LOG4CPLUS_FATAL(root, "Exception occured...");
    }
    std::cout<< LOG4CPLUS_TEXT("Exiting main()...") << std::endl;
    return 0;
}
