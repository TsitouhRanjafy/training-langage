package com.generic;

public class Voiture {
    private String marque;

    public Voiture(){
        this.marque = "unknow";
    }
    public Voiture(String marque) {
        this.marque = marque;
    }

    public String getMarque() {
        return marque;
    }

    public void setMarque(String marque) {
        this.marque = marque;
    }

    public String toString(){
        return "Voiture de marque: " + this.marque;
    }
}

class VoitureSansPermis extends Voiture {

    public VoitureSansPermis() {
        super();
    }
    public VoitureSansPermis(String marque) {
        super(marque);
    }

    public int getVitesseMax() {
        return 45;
    }
}