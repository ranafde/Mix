#include <iostream>
#include <cstring>
using namespace std;

void reverseString(char *str, size_t len)
/*
	Definition(s): str is a pointer to the input String
				   len gives the lenght of the input String
				   
	Loop Invariant: i = 0, j = len -1 [initialization]
				  	for all i,j : if(i<j) then swap (str[i],str[j])

*/
{
	int i, j;
	char temp;
	
	
	if(len == 0){
		cout<<"No input string.";
	}
	
	else{
		i=0;
		j=len-1;
		while(i<j){
			temp = str[i];
			str[i++] = str[j];
			str[j--] = temp;
		}
	}
	
}


int main() {
	// your code goes here
	char str[] = "Reinvent!";
	size_t len = 0;
	len = strlen(str);
	cout<<"String is: "<<str<<endl;
	reverseString(str, len);
	cout<<"Now String is: "<<str;
	return 0;
}