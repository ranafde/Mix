#include <iostream>
using namespace std;

// Returns the maximum sum of a contiguous subarray in a one dimensional array. If array contains all negative numbers then returns the least negative number.
long maxSum(long *array, int len){
	long maxSum = 0;
	long maxCur = 0;
	long allNeg = 1;
	long leastNeg = 0;
	int i;
	
	for(i=0; i<len ;i++){
		maxCur = maxCur + array[i];
		
		if(maxCur < 0)
			maxCur = 0;	
		
		if(array[i] >= 0)
			if(allNeg)
				allNeg = 0;
		
		if(array[i] < 0){
			if(leastNeg == 0){ 
				leastNeg = array[i];
			}
			if(leastNeg < array[i]){
				leastNeg = array[i];
			}
		}
		
		if(maxCur > maxSum)
			maxSum = maxCur;
	}

	if(allNeg == 1){
		return leastNeg;
		
	}
	else
		return maxSum;
}
	


int main() {
	// your code goes here
	long val[]={-2, -3, 14, -1, -2, 1, 7, -3};
	cout<<maxSum(val,8);
	return 0;
}