/*
"Intal" - Library to perform operations on integers of arbitrary length
intal integers -- nonnegative
*/

/*
Function: intal_create
-----------------------
string of digits taken in, converted to integer of type intal
Most significant digit of integer is str[0]
allocates memory for the new intal object this memory is later handled/destroyed through other functions
No limit to the size of the integer that is handled and eventually stored as intal object
memory limitations would be bound by the Operating system in use with the largest prime that can be handled having 24,862,048 digits (as of Apr 2022)
null pointer is returned if string doesn't represent valid nonnegative integer, indicating NaN
args:
    str: array of decimal digit characters (end with NULL char)

returns:
    ptr: pointer to intal object that stores the integer

*/
void* intal_create(const char* str);

/*
Function: intal_destroy
-----------------------
free memory allocated to intal object created in intal_create

Args:
    intal: void* because internal implementation of intal object is abstracted. The intal object is the one created in intal_create
Returns:
    nothing
*/
void intal_destroy(void* intal);

/*
Function: intal2str
-----------------------
convert intal to string format

Args:
    intal: intal object
Returns:
    str: pointer to string of chars. String format of intal, str[0] is the MSB of integer
*/
char* intal2str(void* intal);

/*
Function: intal_increment
-----------------------
increment intal by 1
two cases:
    1. if incremented intal needs more space then new intal object is created and address to the new object is returned
    2. returns same address of input intal with in place increment of intal by 1
Args:
    intal: pointer to intal object
Returns:
    intal: input intal + 1
*/
void* intal_increment(void* intal);
/*
Function: intal_decrement
-----------------------
decrement intal by 1
if intal == 0, returns intal as is (program does not handle nonnegative integers)
two cases otherwise:
    1. if decremented intal needs lesser memory, then new object created to hold decremented intal, input intal memory is freed
    2. input intal decremented in place if memory requirements are same
Args:
    intal: pointer to intal object
Returns:
    intal: input intal - 1
*/
void* intal_decrement(void* intal);

/*
Function: intal_add
-----------------------
add two intals
Args:
    intal1: pointer to intal object 1
    intal2: pointer to intal object 2
Returns:
    intal: pointer to new intal object holding sum of intal1 and intal2
*/
void* intal_add(void* intal1, void* intal2);

/*
Function: intal_diff
-----------------------
absolute difference of intal1 and intal2 |intal1-intal2|
Args:
    intal1: pointer to intal object 1
    intal2: pointer to intal object 2
Returns:
    intal: pointer to new intal object holding absolute difference of intal1 and intal2
*/
void* intal_diff(void* intal1, void* intal2);

/*
Function: intal_multiply
-----------------------
multiply intal1 and intal2
uses Karatsuba algorithm for fast multiplication
Args:
    intal1: pointer to intal object 1
    intal2: pointer to intal object 2
Returns:
    intal: pointer to new intal object holding product of intal1 and intal2
*/
void* intal_multiply(void* intal1, void* intal2);

/*
Function: intal_divide
-----------------------
divide intal1/intal2
null returned if intal2 == 0
Args:
    intal1: pointer to intal object 1
    intal2: pointer to intal object 2
Returns:
    intal: pointer to new intal object holding integral part of quotient of intal1/intal2
*/
void* intal_divide(void* intal1, void* intal2);

/*
Function: intal_compare
-----------------------
compare intal1 and intal2
Args:
    intal1: pointer to intal object 1
    intal2: pointer to intal object 2
Returns:
    int: -1, 0, 1 (one of these three numbers returned)
            0 when both intals equal
            if intal1 > intal2: 1 returned
            if intal2 > intal1: -1 returned
*/
int intal_compare(void* intal1,void* intal2);

/*
Function: intal_pow
-----------------------
intal1 ^ intal2 (to the power of)
0^(intal) = 0
Args:
    intal1: pointer to intal object 1
    intal2: pointer to intal object 2
Returns:
    intal: pointer to new intal object holding power(intal1, intal2)
*/
void* intal_pow(void* intal1, void* intal2);

