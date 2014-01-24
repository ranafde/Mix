/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Ideone
{
	public static void main (String[] args) throws java.lang.Exception
	{
		int[][] arr2D = new int[][]{{1, 2, 3}, {4, 0, 6}, {7, 8, 9},{10,11,12}};  
   		int rid = -1, cid = -1;
   		
   		System.out.println("The array is:");
		for (int[] arr1D : arr2D) {  
			System.out.println();
   			for (int i : arr1D) {  
      			System.out.print(" "+i);  
   			}	  
		} 
	
		//System.out.println("\nNumber of rows:"+arr2D.length);
		for(int r = 0; r<arr2D.length; r++)
			for(int c = 0; c<arr2D[r].length; c++ )
				if(arr2D[r][c]==0){
					rid = r;
					cid = c;
					break;
				}
		
		if((rid==-1) || (cid ==-1))
			System.out.println("\nNo non zero element.");
		
		else{
			for(int c=0;c<arr2D[0].length;c++)
				arr2D[rid][c] = 0;
			for(int r=0;r<arr2D.length;r++)
				arr2D[r][cid] = 0;
		
		
			System.out.println("\nThe modified array is:");
			
			for (int[] arr1D : arr2D) {  
				System.out.println();
   				for (int i : arr1D) {  
	      			System.out.print(" "+i);  
   				}	  
			} 
		}
	}
}