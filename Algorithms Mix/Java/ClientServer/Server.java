
import java.io.*;
import java.net.*;


public class Server {

	public static void main(String[] args){
		try{
			
			ServerSocket sock = new ServerSocket(6013);
			
			//listen for connections
			while(true){
				Socket client = sock.accept();
				
				PrintWriter pout = new PrintWriter(client.getOutputStream(), true);
				
				// write data here date to the socket
				pout.println(new java.util.Date().toString());
				
				//close socket and resume
				// listen for connections
				
				client.close();
				
			}
		}
		catch(IOException ioe){
			System.err.println(ioe);
		}
	}
}
