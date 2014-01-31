
import java.net.*;
import java.io.*;

public class Client {

	public static void main(String [] args){
		try{
			// make connection to the server socket
			Socket sock = new Socket("127.0.0.1", 6013);

			InputStream in = sock.getInputStream();
			BufferedReader bin = new BufferedReader(new InputStreamReader(in));

			// Read data from the socket
			String line;
			while((line=bin.readLine())!=null)
				System.out.println(line);
			
			// close the socket connection
			sock.close();

		}
		catch(IOException ioe){
			System.err.println(ioe);
		}
	}

}
