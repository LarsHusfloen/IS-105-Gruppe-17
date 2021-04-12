import java.net.*;
import java.io.*;
import java.util.Scanner;

public class echoclient {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); /* Creates a scanner object called sc */

        try {
            Socket sock = new Socket("127.0.0.1", 6017); /* make connection to server socket */
            PrintWriter pout = new PrintWriter(sock.getOutputStream(), true); /* How to write to the socket */
            InputStream in = sock.getInputStream(); /* Where to get the input stream from socket */
            BufferedReader reader = new BufferedReader(new InputStreamReader(in)); /* Output from the server */

            System.out.println("Please insert input: "); /* Print to terminal */
            String bin = sc.nextLine(); /* Assigns the input from user to string bin */
            pout.println(bin); /* Puts bin in the socket */
            sc.close(); /* Closes the scanner */

            String line;
            while ((line = reader.readLine()) != null) {/* True if socket contain anything */
                System.out.println(line); /* Prints in the terminal */
        }
            sock.close(); /* close the socket connection */
        } catch (IOException ioe) {
            System.err.println(ioe); /* Prints exception if it couldnt establish connection to socket and read/write */
        }
    }
}