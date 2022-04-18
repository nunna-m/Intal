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


int main(int argc, char const *argv[]) {
	// char *str1 = "99999";
	// char *str2 = "100001";
    char *str1="1000"; 
    char *str2="00990"; //990

	void *intal1;
	void *intal2;
	void *sum;
	void *diff;
	void *product;
	void *quotient;
	void *exp;

	intal1 = intal_create(str1);
	intal2 = intal_create(str2);

	printf("First intal: %s\n", intal2str(intal1));
	printf("Second intal: %s\n", intal2str(intal2));

	intal1 = intal_increment(intal1);
	intal2 = intal_decrement(intal2);

	printf("Two intals after increment and decrement:\n");
	printf("%s\n", intal2str(intal1));
	printf("%s\n", intal2str(intal2));

	printf("Getting intal1 and intal2 back to original input:\n");
    intal1 = intal_decrement(intal1);
	intal2 = intal_increment(intal2);
	printf("%s\n", intal2str(intal1));
	printf("%s\n", intal2str(intal2));


	printf("Max of two intals: %s\n", (intal_compare(intal1, intal2) > 0) ? intal2str(intal1) : intal2str(intal2));
    
	sum = intal_add(intal1, intal2);
	printf("Sum: %s\n", intal2str(sum));

	diff = intal_diff(intal1, intal2);
	printf("Diff: %s\n", intal2str(diff));
	
	product = intal_multiply(intal1, intal2);
	printf("Product: %s\n", intal2str(product));
	
	quotient = intal_divide(intal1, intal2);
	printf("Quotient: %s\n", intal2str(quotient));
	
	exp = intal_pow(intal1, intal2);
	printf("Power: %s ^ %s: %s\n", intal2str(intal1), intal2str(intal2), intal2str(exp));

	return 0;
}