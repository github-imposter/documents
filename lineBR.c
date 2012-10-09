#include<stdio.h>
#include<string.h>

int main()
{
   FILE *f,*q ;
   f = fopen( "boundary.cpp",  "r") ;
   q=fopen( "boundary.html",  "w") ;
   //int d='<br>';
   int c=getc(f);
   while( c!=EOF )
   {
       if(c=='\n')
       {
           putc('<',q);
           putc('b',q);
           putc('r',q);
           putc('>',q);
       }
        putc(c,q);
       putchar(c);
       c=getc(f);


   }
   fclose(q);
   fclose(f);
   return 0;
}

