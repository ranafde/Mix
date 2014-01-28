#include <iostream>
#include <cstring>

using namespace std;

void removeDuplicate(char *str, int len)
/*
	Definition(s): str is a pointer to the input string
					len defines the length of the input string
					top is a variable that denotes the lenght of unique character string
					flag is a variable to denote if a character already exists. Set if character is present
					else cleared.
					
	Loop invariant:
					ensures 1 <= top <= len 
					for every i: 0 < i < len
						flag = 0;
						for every j: 0 <= j < i
							if(str[i]==str[j]) //duplicate found
								flag = 1;
								break; 
						if(!flag)
						{
							str[j] = str[i];
							++top;
						}
						str[top] = '/0';
						
*/
{
	int i,  top;
	bool flag = false;
	top = 1;
	
	if(len == 0){
		cout<<"No input string.";
	}
	else{
	for(i=1; i<len; ++i){
		int j;
		flag = false;
		for(j=0; j<i; ++j){
			if(str[j]==str[i]) // duplicate found
			{
				flag = true;
				break;
			}
		}
		
		if(!flag){
			str[top] = str[i];
			++top;
		}
	}
	
	str[top]=0;
	}
}
int main() {
	// your code goes here
	char str[] ="abababa";
	cout<<"String is: "<<str<<" Length is: "<<strlen(str);
	removeDuplicate(str, strlen(str));
	cout<<"\nNow the String is: "<<str;
	return 0;
}