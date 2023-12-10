#ifndef __MY_DEBUG_H__
#define __MY_DEBUG_H__
 
#include <stdio.h>
 
void __attribute__((no_instrument_function)) debug_log(const char *format,...);
void __attribute__((no_instrument_function)) __cyg_profile_func_enter(void*, void*);
void __attribute__((no_instrument_function)) __cyg_profile_func_enter(void*, void*);
 
 
#endif