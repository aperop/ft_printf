////////////////////////////////////
////////////////////////////////////
////////////////////////////////////
#include <stdio.h>
#include "ft_printf.h"
#define PRINT "H2 	1"
int	main()
{
	// printf("\nftprintlen: %d\n\n", ft_printf(PRINT));
	// printf("\nprintlen: %d\n", printf(PRINT));
	printf ("1. Вывод простой строки\n");
	      ft_printf("//////////////\n");

	ft_printf ("1. Вывод простой строки\n");

 printf ("\n2. Вывод целых чисел\n");

 printf ("2.1 Вывод числа 123 с форматом по умолчанию:\n");
 { int d1=123;
   printf ("%d\n",d1);
      ft_printf("//////////////\n");

	ft_printf ("%d\n",d1);

 }
 printf ("\n2.2 Вывод чисел c выравниванием по правому краю:\n");
 { int d1=123, d2=42, d3=1543;
   printf ("%6d\n%6d\n%6d\n",d1,d2,d3);
      ft_printf("//////////////\n");

      ft_printf ("%6d\n%6d\n%6d\n",d1,d2,d3);

 }
 printf ("\n2.3 Вывод чисел c выравниванием по левому краю:\n");
 { int d1=123, d2=42, d3=1543;
   printf ("%-6d\n%-6d\n%-6d\n",d1,d2,d3);
   ft_printf("//////////////\n");
      ft_printf ("%-6d\n%-6d\n%-6d\n",d1,d2,d3);

 }
 printf ("\n2.4 Вывод числа с выводом 0 в недостающих символах:\n");
 { int d1=-123;
   printf ("%06d\n",d1);
      ft_printf("//////////////\n");

      ft_printf ("%06d\n",d1);

 }
 printf ("\n2.5 Вывод числа 123 с заданной шириной 6 символов:\n");
 { int d1=123;
   printf ("%6d\n",d1);
      ft_printf("//////////////\n");

      ft_printf ("%6d\n",d1);

 }
 printf ("\n2.6 Вывод числа 123 с заданной точностью 6 символов:\n");
 { int d1=123;
   printf ("%.6d\n",d1);
      ft_printf("//////////////\n");

      ft_printf ("%.6d\n",d1);

 }
 
 printf ("\n2.11 Вывод целого без знакового числа:\n");
 { unsigned int d1=123;
   printf ("%u\n",d1);
      ft_printf("//////////////\n");

      ft_printf ("%u\n",d1);

 }
 printf ("\n2.13 Вывод целого числа в шестнадцатеричном формате:\n");
 { unsigned int d1=123;
   printf ("%x\n",d1);
      ft_printf("//////////////\n");

      ft_printf ("%x\n",d1);

 }
 printf ("\n2.14 Вывод целого числа в шестнадцатеричном формате:\n");
 { unsigned int d1=123;
   printf ("%#x\n",d1);
      ft_printf("//////////////\n");

      ft_printf ("%#x\n",d1);

 }

 printf ("\n4. Вывод символа 'k':\n");
 { char d1='k';
   printf ("%c\n",d1);
      ft_printf("//////////////\n");

      ft_printf ("%c\n",d1);

 }
 printf ("\n5. Вывод строки 'abc':\n");
 { char d1[4]="abc";
   printf ("%s\n",d1);
      ft_printf("//////////////\n");

      ft_printf ("%s\n",d1);

 }
 printf ("\n6. Вывод указателя:\n");
 { char d1[4]="abc";
   printf ("%p\n",d1);
      ft_printf("//////////////\n");

      ft_printf ("%p\n",d1);

 }
 printf ("\n7. Подсчет выведенных символов:\n");
 {
	 char d1[4]="abc";
   printf(" %d\n", printf ("%p\n",d1));
ft_printf("//////////////\n");
   ft_printf(" %d\n", ft_printf ("%p\n",d1));

   
 }
	return (0);
 }