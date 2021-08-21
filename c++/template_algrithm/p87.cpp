print (int n) 
{    
     int i;
     if (n != 0)  {
         print(n-1);
         for (i = 1; i <= n; i++)
	         printf("%d", n);
	     printf("\n");
     }
}
