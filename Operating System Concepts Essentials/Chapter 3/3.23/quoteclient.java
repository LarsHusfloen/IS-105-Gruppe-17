import java.net.*;
import java.io.*;

public class quoteclient {
    public static void main(String[] args) {
        try {
            Socket sock = new Socket("127.0.0.1", 6017); /* make connection to server socket */
            InputStream in = sock.getInputStream(); /* Where to get the input stream from socket */
            BufferedReader bin = new BufferedReader(new InputStreamReader(in)); /* Read the quote from the socket */
            
            String line;
            while ((line = bin.readLine()) != null) /* True if socket contain anything */
                System.out.println(line); /* Prints in the terminal */
            sock.close(); /* close the socket connection */
        } catch (IOException ioe) {
            System.err.println(ioe); /* Prints exception if it couldnt establish connection to socket and read/write */
        }
    }
}