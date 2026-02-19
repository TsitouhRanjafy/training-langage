public class Main {
    public static void main(String[] args) {
        // transformation
        String chaine = new String("COUCOU TOUT LE MONDE !"), chaine2 = new String();
        chaine2 = chaine.toLowerCase();   //Donne "coucou tout le monde !"
        System.out.println(chaine2);
        System.out.println(chaine.length());

        // comparaison deux string
        if (chaine.equals(chaine2))
            System.out.println("les deux sont de même");
        else
            System.out.println("les deux chaine sont different");

        // indexation
        char car = chaine.charAt(9);
        System.out.println("chaine[9]: "+car);

        String str = new String("la paix niche");
        String str2 = str.substring(3,13);
        System.out.println(str2);

        String mot = new String("anticonstitutionnellement");
        int n = 0;

        n = mot.indexOf('t');           //n vaut 2
        n = mot.lastIndexOf('t');       //n vaut 24
        n = mot.indexOf("ti");          //n vaut 2
        n = mot.lastIndexOf("ti");      //n vaut 12
        n = mot.indexOf('x');           //n vaut -1

        String[] array1 = {"toto", "tata", "titi", "tete"};
        int array2[] = {1,5,5,7,9,5,1,2,63,54,7};
        parcourirTableau(array1);
        parcourirTableau(array2);

    }

    public static double arrondi(double A, int B) {
        return (double)((int) (A * Math.pow(10,B) + .5) ) / Math.pow(A,B);
    }

    static void parcourirTableau(String[] tab) {
        for (String str : tab ) {
            System.out.println(str);
        }
    }

    // surchage méthode
    static void parcourirTableau(int[] tab) {
        for(int str : tab)
            System.out.print(str);
    }
    static void parcourirTableau(String[][] tab) {
        for(String tab2[] : tab) {
            for(String str : tab2)
                System.out.println(str);
        }
    }
    static void parcourirTableau(String[][] tab, int i) {
        for(String tab2[] : tab) {
            for(String str : tab2)
                System.out.println(str);
        }
    }


}