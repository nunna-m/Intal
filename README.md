C library to handle mathematical operations on arbitrary length integers.  
Very useful for handling very big integers that are not handled by builtin data types.  

Clone this repository  
cd into Intal folder  
type "make" in cmdline to compile  
check.c is the client file where the main() function takes in input for intals in char *str1 and char *str2  
./intal to run the executable  
  
Sample Input:
cd Intal  
make  
./intal  

Sample Output:  
First intal: 1000  
Second intal: 00990  
Two intals after increment and decrement:  
1001  
00989  
Getting intal1 and intal2 back to original input:  
1000  
00990  
Max of two intals: 1000  
Sum: 1990  
Diff: 10  
Product: 990000  
Quotient: 1  
Power: 1000 ^ 990: 1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000...  

