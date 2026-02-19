public class Main {
    public static void main(String[] args) {
        int i = 12;
        float j = (float) i;
        double x = (double) i;

        System.out.println("float: "+j+" double: "+x);

        double n = 10, m = 3;
        int result = (int)(n / m);
        double result2 = (double)(n / m);
        double result3 = (double) (n) / (double) (m);
        System.out.println("Le resultat est: " + result);
        System.out.println("Le resultat 2: "+ result2);
        System.out.println("Le resultat 3: "+ result3);

        String s = new String();
        s = s.valueOf(i);
        System.out.println("string: "+s);
        int k = Integer.valueOf(s).intValue();
        System.out.println("integer: "+k);

    }
}