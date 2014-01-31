// correct implementation of classic producer and consumer problem.

class Qq{
	int n;
	boolean valueSet = false;
	
	synchronized int get(){ // Will be used by consumer
		while(!valueSet){
			try{
				wait();
			}
			catch(InterruptedException ie){
				System.out.println("Interruted get");
			}
		}
		
		System.out.println("Got: "+n);
		valueSet = false;
		notify();
		return n;
	}
	
	synchronized void put(int n){ // Will be used by producer
		while(valueSet){
			try{
				wait();
			}
			catch(InterruptedException ie){
				System.out.println("Interrupted put");
			}
		}
		
		this.n = n;
		valueSet = true;
		System.out.println("Put: "+n);
		notify();
	}
}

class Pdr implements Runnable{
	Qq q;
	
	Pdr(Qq q){
		this.q = q;
		new Thread(this, "Producer").start();
	}
	
	public void run(){
		int i = 0;
		while(true){
			q.put(i++);
		}
	}
}

class Cmr implements Runnable{
	Qq q;
	Cmr(Qq q){
		this.q = q;
		new Thread(this, "Consumer").start();
	}
	
	public void run(){
		while(true){
			q.get();
		}
	}
}

public class ProducerConsumer{
	public static void main(String args[]){
		Qq q = new Qq();
		new Pdr(q);
		new Cmr(q);
		
		System.out.println("Press Control-C to stop.");
	}
}

