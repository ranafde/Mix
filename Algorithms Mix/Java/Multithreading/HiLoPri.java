// Demonstrate to set priorities for threads in Java 
class Clicker implements Runnable{
	long click = 0;
	Thread t;
	private volatile boolean running = true;
	
	public Clicker(int p){
		t = new Thread(this);
		t.setPriority(p);
	}
	
	public void run(){
		while(running)
			click ++;
	}
	
	public void stop(){
		running = false;
	}
	
	public void start(){
		t.start();
	}
}


public class HiLoPri {
	public static void main(String [] args){
		Thread.currentThread().setPriority(Thread.MAX_PRIORITY);
		Clicker hi = new Clicker(Thread.NORM_PRIORITY+2);
		Clicker lo = new Clicker(Thread.NORM_PRIORITY-2);
		
		lo.start();
		hi.start();
		try{
			Thread.sleep(10000);
		}
		catch(InterruptedException ie){
			System.out.println("Main Thread interrupted.");
		}
		
		lo.stop();
		hi.stop();
		
		//Wait for threads to terminate
		try{
			hi.t.join();
			lo.t.join();
		}
		catch(InterruptedException ie){
			System.out.println("InterruptedException");
		}
		System.out.println("Low priority thread: "+lo.click);
		System.out.println("High priority thred: "+hi.click);
	}

}
