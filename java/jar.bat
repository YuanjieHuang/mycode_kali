@echo off  
rem  
rem Set BQ_IBS_HOME before running this script.  
rem  
if not "%BQ_IBS%" == "" goto CONT0
 
set BQ_IBS=C:\Users\Administrator\Desktop\javaportPC 

:CONT0  
@echo on  
@java -DBQ_IBS=%BQ_IBS% -jar 44demo.jar 

:END
pause