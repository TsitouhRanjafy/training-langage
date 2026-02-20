public class Main {
    public static void main(String[] args) {

        int j = 20, i = 0;
        try {
            System.out.println(j/i);
        } catch (Exception e) {
            System.out.println("Division par zéro !: "+ e.getMessage());
        } finally {
            System.out.println("action faite systématiquement");
        }
        try {
            Ville v = new Ville("Antananarivo", -34567, "Madagascar");
            System.out.println(v.getNom());
        } catch (NombreHabitantException e) {
            System.out.println(e.getMessage());
        }

    }
}

class NombreHabitantException extends Exception {
    public NombreHabitantException(int nbre) {
        super("Vous essayez d'instancier une classe Ville avec un nombre d'habitants négatif !: "+nbre);
    }
}

class Ville {
    public static int nbreInstances = 0;
    private static int nbreInstancesBis = 0;
    private String nom;
    private String pays;
    private int nbreHabitants;

    public Ville() {
        nom = "Inconnu";
        pays = "Inconnu";
        nbreHabitants = 0;
    }
    public Ville(String nom, int nbre, String pays) throws NombreHabitantException {
        if (nbre < 0)
            throw new NombreHabitantException(nbre);
        else {
            this.nom = nom;
            this.pays = pays;
            this.nbreHabitants = nbre;
        }
    }

    public String getNom() {
        return this.nom;
    }

    public String getPays() {
        return this.pays;
    }

    public int getNbreHabitant() {
        return this.nbreHabitants;
    }

    public static int getNbreInstances() {
        return nbreInstances;
    }

    public static int getNbreInstancesBis() {
        return nbreInstancesBis;
    }
}