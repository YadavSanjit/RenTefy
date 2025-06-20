public Class Prime { 

    public static void main(String[] args){
        int n = 1000, int i = 0; // Number to check for primality
        for( i = 0; i< Math.sqrt(n); i++){
            if (n%i == 0) {
                System.out.println(i + " is prime.");
            } else {
                System.out.println(i + " is not prime.");
            }
        }
    }
}