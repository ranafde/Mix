/*
 * Simple multithreaded program that computes factorial and tells if the number input is 
 * even/ odd. Access to the user input is shared (Implemented via common resource)
 * 
 */


import java.util.Scanner;


class Resource{
	int num;
	
	synchronized void getnum(){
		Scanner in = new Scanner(System.in);
		System.out.println("Enter the number: ");
		this.num = in.nextInt();
	}
	
	synchronized int putnum(){
		return this.num; 
	}
	
}

class EvenOdd implements Runnable{
	int n;
	Resource R;
	Thread t;
	String name;
	
	EvenOdd(String name, Resource r){
		this.name = name;
		System.out.println(this.name + " is running.");
		this.R = r;
		t = new Thread(this, this.name);
		t.start();
	}
	
	public void run(){
		R.getnum();
		this.n = R.putnum();
		if(this.n%2 == 0)
			System.out.println("Number input "+this.n+" is even");
		else
			System.out.println("Number input "+this.n+" is odd");
	
		System.out.println(t+" thread is exiting.");
	}
}

public class FactorialMultiThread {
	static int first = 0;
	static int second = 1;
	static int result;
	static int num;
	
	public static void main(String args[]){
		Resource r1 = new Resource(); 
		EvenOdd eo1 = new EvenOdd("EvenOdd", r1);
		
		Thread t = Thread.currentThread();
		t.setName("Factorial Thread");
		System.out.println(t+" thread is running.");
					
		r1.getnum();
		num = r1.putnum();
		
		System.out.println(first+","+second);
		for(int i = 2; i <= num; i++){
			result = first + second;
			System.out.println(result);
			first = second;
			second = result;
		}
		
		System.out.println(t+" thread exiting.");
		
	}

}
