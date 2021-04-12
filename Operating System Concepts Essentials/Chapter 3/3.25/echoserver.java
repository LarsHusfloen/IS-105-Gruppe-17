import java.net.*;
import java.io.*;

public class echoserver {

    public static void main(String[] args) {

        try {
            ServerSocket sock = new ServerSocket(6017); /* Listens for connections */
            while (true) { /* If connections equals true, run the following code */
                Socket client = sock.accept(); /* Establish the connection to the socket */
                PrintWriter pout = new PrintWriter(client.getOutputStream(), true); /* How to write to the socket */
                BufferedReader in = new BufferedReader(new InputStreamReader(client.getInputStream())); /* Read the quote from the socket */

                
                String line;
                while ((line = in.readLine()) != null){ /* True if socket contain anything */
                    pout.println("Server echo back: " + line); /* Prints in the terminal */
                }
                client.close(); /* close the socket and resume */
                //in.close();
                //pout.close();
            }
        } catch (IOException ioe) {
            System.err.println(ioe); /*
                                      * Prints exception if it couldnt establish connection to socket and read/write
                                      */
        }
    }
}