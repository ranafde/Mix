// Incorrect implementation of classic producer and consumer problem.

class Q{
	int n;
	
	synchronized int get(){ // Will be used by consumer
		System.out.println("Got: "+n);
		return n;
	}
	
	synchronized void put(int n){ // Will be used by producer
		this.n = n;
		System.out.println("Put: "+n);
	}
}

class Producer implements Runnable{
	Q q;
	
	Producer(Q q){
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

class Consumer implements Runnable{
	Q q;
	Consumer(Q q){
		this.q = q;
		new Thread(this, "Consumer").start();
	}
	
	public void run(){
		while(true){
			q.get();
		}
	}
}

public class ProducerConsumerError {
	public static void main(String args[]){
		Q q = new Q();
		new Producer(q);
		new Consumer(q);
		
		System.out.println("Press Control-C to stop.");
	}
}
