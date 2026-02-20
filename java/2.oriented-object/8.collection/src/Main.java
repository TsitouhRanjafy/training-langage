import java.util.*;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        // Linkedlist
        List l = new LinkedList();
        l.add(1);
        l.add("toto");
        l.add(12.20f);

        for (int i = 0; i < l.size(); i++) {
            System.out.println("Element à l'index "+ i +" = " + l.get(i));
            System.out.println("\tParcours avec itérateur");
            ListIterator li = l.listIterator();
            System.out.print("\t");
            while (li.hasNext()) {
                System.out.print(li.next());
                if (li.hasNext())
                    System.out.print(",");
                else
                    System.out.print("\n");
            }
        }

        // ArrayList
        ArrayList al = new ArrayList();
        al.add(1);
        al.add("str");
        al.add(12.20f);
        al.add('d');

        for (int i = 0; i < al.size(); i++) {
            System.out.println(al.get(i));
        }

        // HashTable (accept duplicate)
        System.out.println("---------------------------------------------------------------------");
        Hashtable ht = new Hashtable();
        ht.put(1, "printemps");
        ht.put(10, "été");
        ht.put(12, "autonome");
        ht.put(45, "hiver");

        Enumeration e = ht.elements();
        while (e.hasMoreElements())
            System.out.println(e.nextElement());
        System.out.println("key 1 = " + ht.get(1));

        // HashSet (no duplicate)
        System.out.println("---------------------------------------------------------------------");
        HashSet hs = new HashSet();
        hs.add("toto");
        hs.add(12);
        hs.add('d');

        Iterator it = hs.iterator();
        while(it.hasNext())
            System.out.println(it.next());
        System.out.println(".");
        Object[] obj = hs.toArray();
        for(Object o : obj)
            System.out.println(o);

    }
}