import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class filereader {
    public static void main(String[] args) {
        
            FileInputStream exist = new FileInputStream("sanjit.txt");
            FileOutputStream newOne = new FileOutputStream("sanjit2.txt");

            int data;
            while ((data = exist.read()) != -1) {
                newOne.write(data);
            }

            exist.close();
            newOne.close();
            System.out.println("File copied successfully.");
    }
}