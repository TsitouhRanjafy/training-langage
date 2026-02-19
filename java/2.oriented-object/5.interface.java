

public class Main {
    public static void main(String[] args) {
        Chien c1 = new Chien();
        c1.faireCalin();
        c1.boire();

        Chien c2 = new Chien("Gris bleuté", 20);
        System.out.println(c2.getCouleur());
        c2.faireLeChouille();

    }
}


public interface Rintintin {
    public void faireCalin();
    public void faireLeBeau();
    public void faireLeChouille();
}


abstract class Animal {
    protected String couleur;
    protected int poids;

    protected void manger() {
        System.out.println("Je mange de la viande.");
    }

    protected void boire() {
        System.out.println("Je bois de l'eau !");
    }

    public int getPoids() {
        return poids;
    }

    public String getCouleur() {
        return couleur;
    }
}

public class Chien extends Animal implements Rintintin {
    public Chien() {}
    public Chien(String couleur, int poinds) {
        this.couleur = couleur;
        this.poids = poinds;
    }

    void crier() {

    }

    public void faireCalin() {
        System.out.println("Je te fais un gros calin");
    }

    public void faireLeBeau() {
        System.out.println("Je fais le beau");
    }

    public void faireLeChouille() {
        System.out.println("Je fais de grosses léchouilles...");
    }
}