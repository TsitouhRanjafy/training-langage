import java.util.Objects;

public class Main {
    public static void main(String[] args) {
        Capitale cap = new Capitale();
        System.out.println(cap.toString());

        Capitale cap2 = new Capitale("Paris", 654987, "France", "la tour Eiffel");
        Capitale cap3 = new Capitale("Paris", 65497, "France", "la tour Eiffel");
        System.out.println(cap2.toString()); // toString est un méthode heriter dans java
        System.out.println(cap2);
        System.out.println(cap2.equals(cap));
        System.out.println(cap3.equals(cap2));
    }
}

public class Capitale extends Ville {
    private String monument;

    public Capitale() {
        super(); // Ce mot clé appelle le constructeur de la classe mère
        this.monument = "aucun";
    }
    public Capitale(String nom, int hab, String pays, String monument){
        super(nom, hab, pays);
        this.monument = monument;
    }

    public String getMonument() {
        return this.monument;
    }

    public void setMonument(String monument) {
        this.monument = monument;
    }

    public String toString(){
        String str = super.toString() + "\n \t ==>>" + this.monument + " en est un monument";
        return str;
    }


}

class Ville {
    public static int nbreInstances = 0;
    protected static int nbreInstancesBis = 0;
    protected String nom;
    protected String pays;
    protected int nbreHabitants;

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

    // redefinition de méthode
    public String toString(){
        return "\t"+this.nom+" est une ville de "+this.pays+", elle comporte : "+this.nbreHabitants;
    }

    // redéfinition de méthode
    public boolean equals(Object obj) {
        //On vérifie si les références d'objets sont identiques
        if (this == obj)
            return true;

        //On s'assure que les objets sont du même type, ici de type Ville
        if (getClass() != obj.getClass())
            return false;

        //Maintenant, on compare les attributs de nos objets
        Ville other = (Ville) obj;

        return  Objects.equals(other.getNom(), this.getNom()) &&
                Objects.equals(other.getNbreHabitants(), this.getNbreHabitants()) &&
                Objects.equals(other.getPays(), this.getPays());
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