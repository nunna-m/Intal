//client file for intal library

/*
Intal1: 99999
Intal2: 100001

After increment and decrement (consecutive calls):
Intal1: 100000
Intal1: 99999

After decrement and increment:
Intal2: 100000
Intal2: 100001

Sum: 200000
Diff: 2
Product: 9999999999
Quotient: 1
Power: very big number (too big to display here)
*/

#include <stdio.h>
#include "intal.h"


// int main(int argc, char const *argv[]) {
// 	// char *str1 = "99999";
// 	// char *str2 = "100001";
//     char *str1="1000"; //90000000
//     char *str2="00990";

// 	void *intal1;
// 	void *intal2;
// 	void *sum;
// 	void *diff;
// 	void *product;
// 	void *quotient;
// 	void *exp;

// 	intal1 = intal_create(str1);
// 	intal2 = intal_create(str2);

// 	printf("First intal: %s\n", intal2str(intal1));
// 	printf("Second intal: %s\n", intal2str(intal2));

// 	intal1 = intal_increment(intal1);
// 	intal2 = intal_decrement(intal2);

// 	printf("Two intals after increment and decrement:\n");
// 	printf("%s\n", intal2str(intal1));
// 	printf("%s\n", intal2str(intal2));

//     intal1 = intal_decrement(intal1);
// 	intal2 = intal_increment(intal2);

// 	printf("Max of two intals: %s\n", (intal_compare(intal1, intal2) > 0) ? intal2str(intal1) : intal2str(intal2));
    
// 	sum = intal_add(intal1, intal2);
// 	printf("Sum: %s\n", intal2str(sum));

// 	diff = intal_diff(intal1, intal2);
// 	printf("Diff: %s\n", intal2str(diff));
	
// 	product = intal_multiply(intal1, intal2);
// 	printf("Product: %s\n", intal2str(product));
	
// 	quotient = intal_divide(intal1, intal2);
// 	printf("Quotient: %s\n", intal2str(quotient));
	
// 	exp = intal_pow(intal1, intal2);
// 	printf("%s ^ %s: %s\n", intal2str(intal1), intal2str(intal2), intal2str(exp));

// 	//free memory
// 	intal_destroy(sum);
// 	intal_destroy(diff);
// 	intal_destroy(product);
// 	intal_destroy(quotient);
// 	intal_destroy(exp);
// 	intal_destroy(intal1);
// 	intal_destroy(intal2);
// 	return 0;
// }

int main(int argc, char const *argv[])
{
	void *ptr1,*ptr2,*diff,*sum,*intal1,*intal2,*product;
	// char *str1="100000000000000000000000000000000000000000000000000000000000000000000008957412547896413231218897845987498785125896325478965412501225478541254521";
	// char *str2="231218897845987498785125896325478965412501225478541254521";
	char *str1="1000"; //90000000
	char *str2="00990";
	ptr1=intal_create(str1);
	ptr2=intal_create(str2);

	//intal1=intal_multiply(ptr1,ptr2);
	//printf("%s\n",intal2str(intal1));
	//inlat t=(inlat)ptr2;
	int h=intal_compare(ptr1,ptr2);
	printf("%d\n",h);
	
	intal_destroy(ptr1);
	intal_destroy(ptr2);
	
}