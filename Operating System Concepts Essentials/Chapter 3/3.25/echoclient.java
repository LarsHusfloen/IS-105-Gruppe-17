import java.net.*;
import java.io.*;
import java.util.Scanner;

public class echoclient {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Insert input: ");

        try {
            Socket sock = new Socket("127.0.0.1", 6017); /* make connection to server socket */
            InputStream in = sock.getInputStream(); /* Where to get the input stream from socket */
            String bin = sc.nextLine(); /* Read the quote from the socket */
            PrintWriter pout = new PrintWriter(sock.getOutputStream(), true); /* How to write to the socket */
            pout.println(bin);
            BufferedReader reader = new BufferedReader(new InputStreamReader(in));
            sc.close();

            String line;
            while ((line = reader.readLine()) != null) {/* True if socket contain anything */
                System.out.println(line); /* Prints in the terminal */
                
            }
            sock.close(); /* close the socket connection */
            //pout.close();
            //reader.close();
            
        } catch (IOException ioe) {
            System.err.println(ioe); /*
                                      * Prints exception if it couldnt establish connection to socket and read/write
                                      */
        }
    }
}