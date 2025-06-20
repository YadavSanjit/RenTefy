public class EvnOdd {
    public static void main(String[] args) {
       
        if (args.length == 0) {
            System.out.println("Please provide a string!");
            return;
        }
          
        int i = 0;
          if ( Integer.parseInt(args[i])%2 == 0){
            System.out.println(args[i] + "is even");
          }else {
            System.out.println(args[i] + "is odd");
          }
        
       
    }
}