using System;

public interface IDeplacement {
    void SeDeplacer();
}

public interface IAttaque {
    void Attaquer();
}

public interface ISoin {
    void Soigner();
}

public class Marcher : IDeplacement {
    public void SeDeplacer(){
        Console.WriteLine("Marcher");
    }
}

public class Voler : IDeplacement {
    public void SeDeplacer(){
        Console.WriteLine("Voler");
    }
}

public class Courir : IDeplacement {
    public void SeDeplacer(){
        Console.WriteLine("Courir");
    }
}

public class PasAttaque : IAttaque {
    public void Attaquer() {
        Console.WriteLine("Pas d'attaque");
    }
} 

public class Fusil : IAttaque {
    public void Attaquer() {
        Console.WriteLine("Fusil");
    }
} 

public class AvecSort : IAttaque {
    public void Attaquer() {
        Console.WriteLine("Avec un sort");
    }
} 

public class PasSoin: ISoin {
    public void Soigner(){
        Console.WriteLine("Pas de soin");
    }
}

public class SoinBase : ISoin {
    public void Soigner(){
        Console.WriteLine("Soin de base");
    }
}

public class SuperSoin : ISoin {
    public void Soigner(){
        Console.WriteLine("Super Soin");
    }
}


public abstract class Personnage {
    protected  IDeplacement deplacement;
    protected  IAttaque attaque;
    protected  ISoin soin;

    public Personnage(){}
    public Personnage(IDeplacement deplacement,  IAttaque attaque, ISoin soin){
        this.deplacement = deplacement;
        this.attaque = attaque;
        this.soin = soin;
    }
    
    public void SeDeplacer() {
        this.deplacement.SeDeplacer();
    }

    public void Soigner(){
        this.soin.Soigner();
    }

    public void Attaquer(){
        this.attaque.Attaquer();
    }
}

public class Roi : Personnage {
    public Roi() : base(new Marcher(), new PasAttaque(), new PasSoin()) {}
}

public class Soldat : Personnage {
    public Soldat() : base(
        new Courir(),
        new Fusil(),
        new SoinBase()
    ){}
}

public class Sorcier : Personnage {
    public Sorcier(){
        this.deplacement = new Voler();
        this.attaque = new AvecSort();
        this.soin = new SoinBase();
    }
}

public class Pretre : Personnage {
    public Pretre() : base(
        new Marcher(),
        new PasAttaque(),
        new SuperSoin()
    ){}
}

public static class Program {
    public static void Main() {
        Personnage roi = new Roi();
        Personnage pretre = new Pretre();
        Personnage soldat = new Soldat();
        Personnage sorcier = new Sorcier();

        Console.WriteLine("Roi: ");
        roi.SeDeplacer();
        roi.Attaquer();
        roi.Soigner();
    }
}

