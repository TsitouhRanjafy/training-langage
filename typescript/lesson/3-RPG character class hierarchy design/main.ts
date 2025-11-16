/* INTERFACE POUR LES COMPORTEMENS */
interface IDeplacement {
    SeDeplacer() : void;
}

interface IAttaque {
    Attaquer() : void;
}

interface ISoin {
    Soigner() : void;
}

/* IMPLEMENTATION DE TOUT LES COMPORTEMENTS */
class Marcher implements IDeplacement {
    public SeDeplacer(): void {
        console.log("Marcher");
    }
}

class Voler implements IDeplacement {
    public SeDeplacer(): void {
        console.log("Voler");
    }
}

class Courir implements IDeplacement {
    public SeDeplacer(): void {
        console.log("Courir");
    }
}

class PasAttaque implements IAttaque {
    public Attaquer(): void {
        console.log("Pas d'attaque");
    }
}

class Fusil implements IAttaque {
    public Attaquer(): void {
        console.log("Fusil");
    }
}

class AvecSort implements IAttaque {
    public Attaquer(): void {
        console.log("Avec sort");
    }
}

class PasSoin implements ISoin {
    public Soigner(): void {
        console.log("Pas de soin");
    }
}

class SuperSoin implements ISoin {
    public Soigner(): void {
        console.log("Super Soin");
    }
}

class SoinBase implements ISoin {
    public Soigner(): void {
        console.log("Soin de base");
    }
}


/* CLASS PERSONNAGE */
abstract class Personnage {
    protected deplacement: IDeplacement;
    protected attaque: IAttaque;
    protected soin: ISoin;

    constructor(deplacement: IDeplacement, attaque: IAttaque, soin: ISoin){
        this.deplacement = deplacement;
        this.attaque = attaque;
        this.soin = soin;
    }

    public SeDeplacer(): void {
        this.deplacement.SeDeplacer();
    }

    public Attaquer(): void {
        this.attaque.Attaquer();
    }

    public Soigner(): void {
        this.soin.Soigner();
    }
}

class Roi extends Personnage {
    constructor(){
        super(new Marcher(), new PasAttaque(), new PasSoin());
    }
}

class Soldat extends Personnage {
    constructor(){
        super(new Courir(), new Fusil(), new SoinBase());
    }
}

class Sorcier extends Personnage {
    constructor(){
        super(new Voler(), new AvecSort(), new SoinBase());
    }
}

class Pretre extends Personnage {
    constructor(){
        super(new Marcher(), new PasAttaque(), new SuperSoin());
    }
}

function Main() {
    const roi: Personnage = new Roi();
    const pretre: Personnage = new Pretre();
    const soldat: Personnage = new Soldat();
    const sorcier: Personnage = new Sorcier();

    console.log("\n\nRoi: ");
    roi.SeDeplacer();
    roi.Attaquer();
    roi.Soigner();
    
    console.log("\n\nPrêtre: ");
    pretre.SeDeplacer();
    pretre.Attaquer();
    pretre.Soigner();
    
    console.log("\n\nSoldat: ");
    soldat.SeDeplacer();
    soldat.Attaquer();
    soldat.Soigner();
    
    console.log("\n\nSorcier: ");
    sorcier.SeDeplacer();
    sorcier.Attaquer();
    sorcier.Soigner();
}
Main();