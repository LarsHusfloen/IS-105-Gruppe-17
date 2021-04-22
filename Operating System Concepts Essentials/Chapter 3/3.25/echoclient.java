import java.net.*;
import java.io.*;
import java.util.Scanner;

public class echoclient {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); 

        try {
            Socket sock = new Socket("127.0.0.1", 6017);                            /* make connection to server socket */
            PrintWriter pout = new PrintWriter(sock.getOutputStream(), true);       /* How to write to the socket */
            InputStream in = sock.getInputStream();                                 /* Where to get the input stream from socket */
            BufferedReader reader = new BufferedReader(new InputStreamReader(in));  /* Output from the server */

            System.out.println("Please insert input: "); 
            String bin = sc.nextLine(); /* Assigns the input from user to string bin */
            pout.println(bin);          /* Puts bin in the socket */
            sc.close();                 /* Closes the scanner */

            do {
                System.out.println(reader.readLine()); 
            } while (reader.read() != -1);  /* Runs until the end of the stream */
            
            sock.close(); /* close the socket connection */
            System.exit(0);
        } catch (IOException ioe) {
            System.err.println(ioe); /* Prints exception if it couldnt establish connection to socket and read/write */
        }
    }
}
