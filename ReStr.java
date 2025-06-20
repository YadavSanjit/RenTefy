public class ReStr {
    public static void main(String[] args) {
       
        if (args.length == 0) {
            System.out.println("Please provide a string!");
            return;
        }

        String str = args[0];
        String revrse = "";
        for( int i = str.length() - 1; i>=0; i--)
        {
            revrse = revrse + str.charAt(i);
        }
        System.out.println("Reversed string: " + revrse);
       
        
       
    }
}