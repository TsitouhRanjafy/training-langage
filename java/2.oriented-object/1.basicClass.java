public class Main {
    public static void main(String[] args) {
        System.out.println("ok");


        Ville v = new Ville();
        Ville v1 = new Ville("Marseille", 123456, "France");
        Ville v2 = new Ville("Rio", 321654, "Brésil");

        System.out.println("\n v = "+v.getNom()+" ville de  "+v.getNbreHabitants()+ " habitants se situant en "+v.getPays());
        System.out.println(" v1 = "+v1.getNom()+" ville de  "+v1.getNbreHabitants()+ " habitants se situant en "+v1.getPays());
        System.out.println(" v2 = "+v2.getNom()+" ville de  "+v2.getNbreHabitants()+ " habitants se situant en "+v2.getPays()+"\n\n");

        Ville tmp = new Ville();
        tmp = v1;
        v1 = v2;
        v2 = tmp;

        System.out.println(" v1 = "+v1.getNom()+" ville de  "+v1.getNbreHabitants()+ " habitants se situant en "+v1.getPays());
        System.out.println(" tmp = "+tmp.getNom()+" ville de  "+tmp.getNbreHabitants()+ " habitants se situant en "+tmp.getPays());
        System.out.println(" v2 = "+v2.getNom()+" ville de  "+v2.getNbreHabitants()+ " habitants se situant en "+v2.getPays());
    }
}


class Ville {
    private String nom;
    private String pays;
    private int nbreHabitants;

    public Ville(){
        nom = "Inconnu";
        pays = "Inconnu";
        nbreHabitants = 0;
    }
    public Ville(String pNom, int pNbre, String pPays) {
        nom = pNom;
        pays = pPays;
        nbreHabitants = pNbre;
    }

    public String getNom() {
        return nom;
    }

    public String getPays() {
        return pays;
    }

    public int getNbreHabitants() {
        return nbreHabitants;
    }

    public void setNom(String nom) {
        this.nom = nom;
    }

    public void setPays(String pays) {
        this.pays = pays;
    }

    public void setNbreHabitants(int nbreHabitants) {
        this.nbreHabitants = nbreHabitants;
    }
}

