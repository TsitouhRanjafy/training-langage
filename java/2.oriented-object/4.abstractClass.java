public class Main {
    public static void main(String[] args) {

    }
}

abstract class Animal {

    protected String couleur;
    protected int poids;

    protected void manger(){
        System.out.println("Je mange de la viande.");
    }

    protected void boire(){
        System.out.println("Je bois de l'eau !");
    }

    abstract void deplacement();

    abstract void crier();

    public String toString(){
        String str = "Je suis un objet de la " + this.getClass() + ", je suis " + this.couleur + ", je pèse " + this.poids;
        return str;
    }
}


public abstract class Felin extends Animal {
    void deplacement() {
        System.out.println("Je me déplace seul !");
    }
}

public abstract class Canin extends Animal {
    void deplacement() {
        System.out.println("Je me déplace en meute !");
    }
}

public class Chien extends Canin {

    public Chien(){

    }
    public Chien(String couleur, int poids){
        this.couleur = couleur;
        this.poids = poids;
    }

    void crier() {
        System.out.println("J'aboie sans raison !");
    }
}

public class Loup extends Canin {

    public Loup(){

    }
    public Loup(String couleur, int poids){
        this.couleur = couleur;
        this.poids = poids;
    }

    void crier() {
        System.out.println("Je hurle à la Lune en faisant ouhouh !");
    }
}

public class Lion extends Felin {

    public Lion(){

    }
    public Lion(String couleur, int poids){
        this.couleur = couleur;
        this.poids = poids;
    }

    void crier() {
        System.out.println("Je rugis dans la savane !");
    }
}

