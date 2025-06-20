class Employee {
    int id;
    String name;
    int salary;

    Employee(int id, String name, int salary) {
        this.id = id;
        this.name = name;
        this.salary = salary;
    }

   public void getSalary(){
    int ASalary = salary *12;
    System.out.println("The annual Salary is: "+ASalary);
}

}
public class Empl {

    public static void main(String args[]) {
        Employee san = new Employee(1, "Sanjit", 10000);
        // san.getSalary();
        int num = 22;
        if (num % 2 == 0)
        {
            System.out.println("the number:" + num + "is even");
        } else{
            System.out.println("the number:" + num + " is odd");
        }
    }
}