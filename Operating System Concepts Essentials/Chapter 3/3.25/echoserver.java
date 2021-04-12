import java.net.*;
import java.io.*;

public class echoserver {

    public static void main(String[] args) {
        try {
            ServerSocket sock = new ServerSocket(6017); /* Listens for connections */
            Socket client = sock.accept(); /* Establish the connection to the socket */
            PrintWriter pout = new PrintWriter(client.getOutputStream(), true); /* Output location */
            BufferedReader in = new BufferedReader(new InputStreamReader(client.getInputStream())); /* Read the input from the socket */

            String line;
            while ((line = in.readLine()) != null) { /* True if socket contain anything */
                pout.println("Server echo back: " + line); /* Puts it in the socket */
                break; /* Closes the client and server */
            }
            client.close(); /* close the socket */
        } catch (IOException ioe) {
            System.err.println(ioe); /* Prints exception if it couldnt establish connection to socket and read/write */
        }
    }
}