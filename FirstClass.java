
class Student {
    int sub1;
    int sub2;
    int sub3;
    int sub4;
    int sub5;
Student(int sub1, int sub2, int sub3, int sub4, int sub5) {
    this.sub1 = sub1;
    this.sub2 = sub2;
    this.sub3 = sub3;
    this.sub4 = sub4;
    this.sub5 = sub5;
}

public void printin() {
    int total = sub1 + sub2 + sub3 + sub4 + sub5;
    int perce = (total * 100) / 500;
    System.out.println("The percentage is: " + perce + "%");
}

}



public class FirstClass {
  public static void main(String args[]) {
   
Student san = new Student(90, 34, 23, 34, 56);
san.printin();
   
 
}
}

