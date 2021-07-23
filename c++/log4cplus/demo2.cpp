#include 
#include 
#include 

using namespace log4cplus;
using namespace log4cplus::helpers;

int main()
{

　　SharedAppenderPtr _append (new ConsoleAppender());
　　_append->setName("append for test");

　　std::string pattern = "%d{%m/%d/%y %H:%M:%S} - %m [%l]%n";
　　std::auto_ptr _layout(new PatternLayout(pattern));
　　_append->setLayout( _layout );
　　Logger _logger = Logger::getInstance("test");
　　_logger.addAppender(_append);
　　_logger.setLogLevel(ALL_LOG_LEVEL);
　　/* log activity */
　　LOG4CPLUS_DEBUG(_logger, "This is the FIRST log message...");
　　LOG4CPLUS_WARN(_logger, "This is the SECOND log message...");

 return 0;
}