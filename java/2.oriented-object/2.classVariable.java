public class Main {
    public static void main(String[] args) {
        System.out.println("you are welcom");

        Ville v = new Ville();
        System.out.println("Le nombre d'instances de la classe Ville est : " + Ville.nbreInstances);
        System.out.println("Le nombre d'instances de la classe Ville est : " + Ville.getNombreInstancesBis());

        Ville v1 = new Ville("Marseille", 1236, "France");
        System.out.println("Le nombre d'instances de la classe Ville est : " + Ville.nbreInstances);
        System.out.println("Le nombre d'instances de la classe Ville est : " + Ville.getNombreInstancesBis());

        Ville v2 = new Ville("Rio", 321654, "Brésil");
        System.out.println("Le nombre d'instances de la classe Ville est : " + Ville.nbreInstances);
        System.out.println("Le nombre d'instances de la classe Ville est : " + Ville.getNombreInstancesBis());
    }
}

public class Ville {
    public static int nbreInstances = 0;
    private static int nbreInstancesBis = 0;

    public Ville() {
        nbreInstances++;
        nbreInstancesBis++;
    }
    public Ville(String pNom, int pNbre, String pPays) {
        nbreInstances++;
        nbreInstancesBis++;
    }

    // a method utilize only a static property is declared static
    public static int getNombreInstancesBis() {
        return nbreInstancesBis;
    }

}