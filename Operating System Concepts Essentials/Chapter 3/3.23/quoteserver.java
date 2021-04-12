import java.net.*;
import java.io.*;
import java.util.Random;
import java.util.ArrayList;

public class quoteserver {
    private static ArrayList<String> quotes = new ArrayList<>(); /* Creates an arraylist for String called quotes */
    private static Random rand = new Random(); /* Creates a Random object called rand */

    public static void main(String[] args) {
        quote(); /* Runs the method quote() */
        try {
            ServerSocket sock = new ServerSocket(6017); /* Listens for connections */
            while (true) { /* If connections equals true, run the following code */
                Socket client = sock.accept(); /* Establish the connection to the socket */
                PrintWriter pout = new PrintWriter(client.getOutputStream(), true); /* How to write to the socket */
                pout.println("Quote of the day:"); /* Write the string to the socket */
                pout.println(quotes.get(rand.nextInt(quotes.size()))); /* write the quote to the socket */
                client.close(); /* close the socket and resume */
            }
        } catch (IOException ioe) {
            System.err.println(ioe); /* Prints exception if it couldnt establish connection to socket and read/write */
        }
    }

    private static void quote() { /* Add the following quotes to the arraylist */
        quotes.add("Be yourself; everyone else is already taken.");
        quotes.add("Two things are infinite: the universe and human stupidity; and I'm not sure about the universe.");
        quotes.add("You only live once, but if you do it right, once is enough.");
        quotes.add("Be the change that you wish to see in the world.");
        quotes.add("In three words I can sum up everything I've learned about life: it goes on.");
    }
}