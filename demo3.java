import java.util.Scanner;

public class demo3 {
    public static void main(String[] args){
         System.out.println("enter any integer:");
        
            Scanner in = new Scanner(System.in);
           
            String sam = in.nextLine();

            int value = Integer.parseInt(sam);
             System.out.println("integer in string:"+ value);

             try {
                
             } catch (NumberFormatException e) {
                System.out.println(e.getMessage());
             }
        
    }
}