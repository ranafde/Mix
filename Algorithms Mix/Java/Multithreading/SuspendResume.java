// Suspend and resume a thread - modern approach

class NewThrd implements Runnable{
	String name;
	Thread t;
	boolean suspendFlag;
	
	NewThrd(String threadname){
		name = threadname;
		t = new Thread(this, name);
		System.out.println("New Thread: "+t);
		suspendFlag = false;
		t.start();
	}
	
	public void run(){
		try{
			for(int i = 15; i > 0; i--){
				System.out.println(name+": "+i);
				Thread.sleep(200);
				synchronized(this){
					while(suspendFlag){
						wait();
					}
				}
			}
		}catch(InterruptedException ie){
			System.out.println(name + " interrupted.");
		}
		System.out.println(name + " exiting.");
	}
	
	void mysuspend(){
		suspendFlag = true;
	}
	
	synchronized void myresume(){
		suspendFlag = false;
		notify();
	}
}

public class SuspendResume {
	public static void main(String args[]){
		NewThrd ob1 = new NewThrd("One");
		NewThrd ob2 = new NewThrd("Two");
		
		try{
			Thread.sleep(1000);
			ob1.mysuspend();
			System.out.println("Suspending thread one.");
			Thread.sleep(1000);
			ob1.myresume();
			System.out.println("Resuming thread one.");
			ob2.mysuspend();
			System.out.println("Suspending thread two.");
			Thread.sleep(1000);
			ob2.myresume();
			System.out.println("Resuming thread two.");
		}catch(InterruptedException ie){
			System.out.println("Main thread interrupred.");
		}
		
		try{
			System.out.println("Waiting for threads to finish.");
			ob1.t.join();
			ob2.t.join();
		}catch(InterruptedException ie){
			System.out.println("Main thread interrupted.");
		}
		
		System.out.println("Main thread exiting.");
	}
}
