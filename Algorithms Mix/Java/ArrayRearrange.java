// Program to shift all even numbers in an array to left and odd to the right. Order of digits is not important.

import java.util.*;
import java.lang.*;
import java.io.*;


class ArrayRearrange
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		int[] array = new int[] {1,2,3,4,5,6,7};
		
		int odd, even;
		odd = 0;
		even = array.length-1;
		int i;
		
		// Code to re-arrange the contents of the array
		i=0;
		while(i<array.length){
			if(array[i]%2!=0){
				odd = i;
				break;
			}
			i++;	
		}
		
		i=array.length-1;
		while(i>=0){
			if(array[i]%2==0){
				even = i;
				break;
			}
			i--;	
		}
		
		while(odd<even){
			if((array[odd]%2!=0) && (array[even]%2==0)){
				// swap contents
				array[odd] = array[odd] + array[even];
				array[even] = array[odd] - array[even];
				array[odd] = array[odd] - array[even];
				odd++;
				even--;
			}
			
			else if(array[odd]%2==0){
				odd++;
			}
			
			else if(array[even]%2!=0){
				even--;
			}
			
			else
				continue;
		}
		for(int val : array)
			System.out.println(val+" ");
		
	}
}