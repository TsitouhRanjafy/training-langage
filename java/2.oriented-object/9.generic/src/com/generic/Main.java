package com.generic;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class Main {
    public static void main(String[] args) {
        Solo<Integer> s = new Solo<Integer>(23);
        Solo<Double> sd = new Solo<Double>(12.87467858);
        Solo<Float> sf = new Solo<Float>(12.2f);
        System.out.println(sd.getValeur());
        System.out.println(sf.getValeur());
        System.out.println(s.getValeur());

        Double d = 12.0;
        Character c = 'C';
        ArrayList al = new ArrayList();
        //Avant Java 5 il fallait faire al.add(new Integer(12))
        //Depuis Java 5 il suffit de faire
        al.add(12);
        System.out.println(al.getFirst());

        Duo<String, Boolean> dual = new Duo<String, Boolean>("toto", true);
        System.out.println("Valeur de l'objet dual : val1 = " + dual.getValeur1() + ", val2 = " + dual.getValeur2());

        Duo<Double, Character> dual2 = new Duo<Double, Character>(12.2585, 'C');
        System.out.println("Valeur de l'objet dual2 : val1 = " + dual2.getValeur1() + ", val2 = " + dual2.getValeur2());


        // avec les collections
        System.out.println("------------------------------");
        System.out.println("Liste de String");
        List<String> listeString= new ArrayList<String>();
        listeString.add("Une chaîne");
        listeString.add("Une autre");
        listeString.add("Encore une autre");
        listeString.add("Allez, une dernière");
        System.out.println(listeString);

        //List n'acceptant que des instances de Voiture ou de ses sous-classes grace à wildcard (?)
        // Mais le list serait en lecture seul
        List<? extends Voiture> listVoitureSP = new ArrayList<VoitureSansPermis>();

        List<Voiture> v1 = new ArrayList<Voiture>();
        v1.add(new Voiture("Toyota"));
        v1.add(new Voiture("Suziki"));
        afficher(v1);
    }

    static void afficher(List<? extends Voiture> list) {
        for (Voiture v : list)
            System.out.println(v.toString());
    }

    // accept une list de n'import quel type
    static void afficher2(List<?> anyList) {
        System.out.println(anyList);
    }
}
