#include <iostream>
#include <cstring>
using namespace std;

bool isUnique(char *ptr, size_t len)
/* 
	Definition(s):
				ptr is the pointer to input string
				len is the lenght of input string
				charset a boolean array of size 256	to represent ASCII characters
				val is the decimal value of ASCII character
				
	Loop Invariant:
	requires (charset,256) = fasle.
	for all i < len : val = ptr[i]; 
		if(charset[val] == true) ==> false
	
	Complexity: O(n)
	
*/
{
	bool charset[256];
	size_t i = 0;
	size_t val;
	std::fill_n(charset, 256, false);
	
	while(i<len){
		val = ptr[i];
		if(charset[val] == true)
			return false;
		charset[val] = true;
		i++;
	}
	
	return true;
}

int main() {
	// test code goes here
	char str[16] = "123456789abcde1";
	size_t len = 0;
	len = strlen(str);
	
	cout<<isUnique(str, len);
	
	return 0;
}