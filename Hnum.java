public class Hnum {
    public static void main(String[] args) {
       
        if (args.length == 0) {
            System.out.println("Please provide some numbers!");
            return;
        }
    
        int Hnum = 0;

        for (int i = 0; i < args.length; i++) {
          
            for (int j = 1; j < args.length; j++) {
          
             if(Integer.parseInt(args[i]) >Integer.parseInt(args[j])) {
                Hnum = Integer.parseInt(args[i]);
            }
             
        }
    }
        System.out.println("Highest number: " + Hnum);
    }
}