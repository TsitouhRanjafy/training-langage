public class Main {
    public static void main(String[] args) {
        int arrayInt[] = {0,2,3,4,5,6};
        double tableauDouble[] = {0.0,1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0};
        char tableauCaractere[] = {'a','b','c','d','e','f','g'};
        String tableauChaine[] = {"chaine1", "chaine2", "chaine3" , "chaine4"};

        // un tableau vide doit avoir nombre case bien définie
        int tab[] = new int[6];
        int[] tab2 = new int[10];

        System.out.println(arrayInt);
        System.out.println(tab);

        // à deux dimension
        int point[][] = {
                {0,2,4,6,8},
                {1,3,5,7,9}
        };

        System.out.println(point.length);
        System.out.println(point[0].length);

    }
}