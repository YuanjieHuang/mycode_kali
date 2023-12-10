#include <stdarg.h>
#include <stdlib.h>
#include "my_debug.h"
 
#define DEBUG_FILE_PATH  "./mydebug.log"
 
void  __attribute__((no_instrument_function)) 
debug_log(const char *format,...)
{
	FILE *fp;
	va_list ap;
	va_start(ap, format);
	
	fp = fopen(DEBUG_FILE_PATH, "a");
	if(NULL == fp)
	{
		printf("Can not open debug file.\n");
		return;
	}
	vfprintf(fp, format, ap);
	va_end(ap);
	fflush(fp);
	fclose(fp);
}
 
void  __attribute__((no_instrument_function))
__cyg_profile_func_enter(void *this, void *call)
{
	debug_log("Enter\n%p\n%p\n", call, this);
}
 
void  __attribute__((no_instrument_function))
__cyg_profile_func_exit(void *this, void *call)
{
	debug_log("Exit\n%p\n%p\n", call, this);
}
