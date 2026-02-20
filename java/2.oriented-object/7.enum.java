public class Main {
    public static void main(String[] args) {
        BeforeEnum b = new BeforeEnum();
        b.fait(BeforeEnum.PARAM1);
        b.fait(BeforeEnum.PARAM2);
        b.fait(4);

        for(Langage lang : Langage.values()){
            if(Langage.JAVA.equals(lang))
                System.out.println("J'aime le : " + lang);
            else
                System.out.println(lang);
        }

        for(Framework fram : Framework.values()) {
            if(Framework.ANGULAR.equals(fram)) {
                System.out.println("J'aime le : " + fram);
            } else  {
                System.out.println(fram);
            }
        }

        Framework f1 = Framework.ANGULAR;
        Framework f2 = Framework.SPRING;
        f1.getLangage();
        f2.getLangage();
    }
}

// BEFORE enumeration
class BeforeEnum {

    public static final int PARAM1 = 1;
    public static final int PARAM2 = 2;

    public void fait(int param) {
        if(param == PARAM1)
            System.out.println("Fait à la façon N°1");
        if(param == PARAM2)
            System.out.println("Fait à la façon N°2");
    }


}

// SULTION ENUM
enum Langage {
    JAVA,
    C,
    CPLUS,
    PHP
}

enum Framework {
    ANGULAR("Framework Angular","Typescript"),
    REACT("Framework React", "Javascript"),
    SPRING("Framework Vue", "Java");

    private String name = "";
    private String langage = "";

    Framework(String name, String langage) {
        this.name = name;
        this.langage = langage;
    }

    public String toString() {
        return this.name;
    }

    public void getLangage() {
        System.out.println("Langage: " + this.langage);
    }
}

