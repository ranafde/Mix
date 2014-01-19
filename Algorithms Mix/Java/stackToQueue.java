import java.util.*;
import java.lang.*;
import java.io.*;

class Ideone
{
	static void display(Stack<Integer> S){
		while(!S.isEmpty()){
			System.out.println(S.pop());
		}
	}
	
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Stack<Integer> in = new Stack<Integer>();
		Stack<Integer> out = new Stack<Integer>();
	
		int i;
		for(i=5; i>0; i--){
			Integer value = new Integer(i);
			in.push(value);
		}
		
		while(!in.isEmpty()){
			out.push(in.pop());
		}
		
		display(out);
		
	}
}