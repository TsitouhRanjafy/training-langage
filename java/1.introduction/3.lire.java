import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Entrer un mot: ");
        String str = sc.nextLine();
        System.out.println("Vous avez entrer: "+str);

        System.out.println("Saisissez un nombre: ");
        int a = sc.nextInt(); // nextDouble(), nextByte(), etc, ...
        System.out.println("Votre nombre: "+a);
    }
}