public class Main {
    public static void main(String[] args) {
        int i = 2;
        if (i < 0) {
            System.out.println("Ce nombre est négatif !");
        } else {
            if(i == 0)
                System.out.println("Ce nombre est nul !");
            else
                System.out.println("Ce nombre est positif !");
        }

        switch (i) {
            case 0:
                System.out.println("c'est zero");
                break;
            case 1:
                System.out.println("c'est un");
                break;
            default:
                System.out.println("nombre inconnu");
        }


        int x = 10, y = 20;

        int max = (x < y) ? (y < 10) ? y % 10 : y * 2 : x ; //Max vaut 40
    }
}