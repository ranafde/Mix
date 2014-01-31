// Illustrate synchronization in Java


// This method has the function call which is shared among threads
class Callme{
	//synchronized void call(String msg){
	void call(String msg){
		System.out.print("["+msg);
		try{
			Thread.sleep(1000);
		}
		catch(InterruptedException ie){
			System.out.println("Interrupted.");
		}
		System.out.println("]");
	}
}

class Caller implements Runnable{
	String msg;
	Callme target;
	Thread t;
	public Caller(Callme targ, String s){
		target = targ;
		msg = s;
		t = new Thread(this);
		t.start();
	}
	
	public void run(){
		synchronized(target){
			target.call(msg);
		}
		System.out.println("HI");
			
	}
}


class Synchronize {
	public static void main(String args[]){
		Callme target = new Callme();
		Caller ob1 = new Caller(target, "Hello");
		Caller ob2 = new Caller(target, "Synchronized");
		Caller ob3 = new Caller(target, "World");
		
		try{
			ob1.t.join();
			ob2.t.join();
			ob3.t.join();
		}catch(InterruptedException ie){
			System.out.println("Interrupted main");
		}
	}
}
