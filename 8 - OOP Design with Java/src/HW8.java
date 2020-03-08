/**
 * TUGAY IPEK
 * 161044034
 * 17.01.20
 * Drive Code
 * This main code contains test code for each methods in GTUSet and GTUVector.
 * Each property is tried.
 */
public class HW8 {

    public static void main(String[] args) {
        System.out.print("------>>>>> SET <<<<<------");
        System.out.print("\n");
        System.out.print("------------S1-------------");
        System.out.print("\n");
        System.out.print("\n");
        GTUSet<Integer> S1 = new GTUSet<Integer>();
        GTUSet<String> S2 = new GTUSet<String>();
        //INSERT TEST
        try
        {
            S1.insert(3);
            S1.insert(9);
            S1.insert(2);
            S1.insert(8);
        }
        catch (RuntimeException e)
        {
            System.out.print(e.getMessage());
            System.out.print("\n");
        }
        //INSERT TEST
        try
        {
            S2.insert("tugay");
            S2.insert("ipek");
            S2.insert("umarım");
            S2.insert("dersi");
            S2.insert("geçer");
        }
        catch (RuntimeException e)
        {
            System.out.print(e.getMessage());
            System.out.print("\n");
        }
        //PRINT ELEMENTS
        GTUIterator cursor = S1.iterator();
        System.out.print("{ ");
        while ( cursor.hasNext())
        {
            System.out.print(cursor.next());
            System.out.print(" ");
        }
        System.out.print(" }");
        System.out.print("\n");
        System.out.print("\n");
        //ITERATOR TEST
        GTUIterator<Integer> cursorS1 = S1.iterator();
        System.out.print("Iter Begin ");
        System.out.print(cursorS1.next());
        System.out.print("\n");
        System.out.print("\n");
        //SIZE & MAX. SIZE TEST
        System.out.print("Size : ");
        System.out.print(S1.size());
        System.out.print("\n");
        System.out.print("Max. Size : ");
        System.out.print(S1.max_size());
        System.out.print("\n");
        System.out.print("\n");
        //ERASE TEST
        S1.erase(9);
        System.out.print("Erase: Element 9 is erased.");
        System.out.print("\n");
        System.out.print("\n");
        //PRINT ELEMENTS
        System.out.print("{ ");

        cursor = S1.iterator();

        while ( cursor.hasNext())
        {
            System.out.print(cursor.next());
            System.out.print(" ");
        }
        System.out.print(" }");
        System.out.print("\n");
        System.out.print("\n");
        //CONTAINS TEST
        GTUIterator founded = S1.contains(2); //eger bulamazsa son elemani return eder
        System.out.print("Find(2) : ");
        System.out.print("Element ");
        System.out.print(founded.next());
        System.out.print(" is founded.");
        System.out.print("\n");
        System.out.print("\n");

        System.out.print("------------S2-------------");
        System.out.print("\n");
        System.out.print("\n");
        //PRINT ELEMENTS
        cursor = S2.iterator();
        System.out.print("{ ");
        while (cursor.hasNext())
        {
            System.out.print(cursor.next());
            System.out.print(" ");
        }
        System.out.print(" }");
        System.out.print("\n");
        System.out.print("\n");
        //ITERATOR TEST
        GTUIterator cursorS2 = S2.iterator();
        System.out.print("Iter Begin ");
        System.out.print(cursorS2.next());
        System.out.print("\n");
        System.out.print("\n");
        //SIZE & MAX. SIZE TEST
        System.out.print("Size : ");
        System.out.print(S2.size());
        System.out.print("\n");
        System.out.print("Max. Size : ");
        System.out.print(S2.max_size());
        System.out.print("\n");
        System.out.print("\n");
        //ERASE TEST
        S2.erase("umarım");
        System.out.print("Erase: Element 'umarım' is erased.");
        System.out.print("\n");
        System.out.print("\n");
        //PRINT ELEMENTS
        cursor = S2.iterator();
        System.out.print("{ ");
        while (cursor.hasNext())
        {
            System.out.print(cursor.next());
            System.out.print(" ");
        }
        System.out.print(" }");
        System.out.print("\n");
        System.out.print("\n");
        //CONTAINS TEST

        GTUIterator founded2 = S2.contains("dersi"); //eger bulamaza son elemani return eder
        System.out.print("Find('dersi') : ");
        System.out.print("Element ");
        System.out.print(founded2.next());
        System.out.print(" is founded.");
        System.out.print("\n");
        System.out.print("\n");

        System.out.print("--------------------------");
        System.out.print("\n");
        System.out.print("\n");

        S1.clear();
        S2.clear();

            System.out.print("Sets is clear.");
            System.out.print("\n");
            System.out.print("\n");


        System.out.print("------>>>>> VECTOR <<<<<------");
        System.out.print("\n");
        System.out.print("------------V1-------------");
        System.out.print("\n");
        System.out.print("\n");
        GTUVector<Integer> V1 = new GTUVector<Integer>();
        GTUVector<String> V2 = new GTUVector<String>();
        //INSERT TEST
        try
        {
            V1.insert(3);
            V1.insert(9);
            V1.insert(2);
            V1.insert(8);
        }
        catch (RuntimeException e)
        {
            System.out.print(e.getMessage());
            System.out.print("\n");
        }
        //INSERT TEST
        try
        {
            V2.insert("tugay");
            V2.insert("ipek");
            V2.insert("umarım");
            V2.insert("dersi");
            V2.insert("geçer");
        }
        catch (RuntimeException e)
        {
            System.out.print(e.getMessage());
            System.out.print("\n");
        }
        //PRINT ELEMENTS
        cursor = V1.iterator();
        System.out.print("{ ");
        while (cursor.hasNext())
        {
            System.out.print(cursor.next());
            System.out.print(" ");
        }
        System.out.print(" }");
        System.out.print("\n");
        System.out.print("\n");
        //ITERATOR TEST
        GTUIterator cursorV1 = V1.iterator();
        System.out.print("Iter Begin ");
        System.out.print(cursorV1.next());
        System.out.print("\n");
        System.out.print("\n");
        //SIZE & MAX. SIZE TEST
        System.out.print("Size : ");
        System.out.print(V1.size());
        System.out.print("\n");
        System.out.print("Max. Size : ");
        System.out.print(V1.max_size());
        System.out.print("\n");
        System.out.print("\n");
        //ERASE TEST
        V1.erase(9);
        System.out.print("Erase: Element 9 is erased.");
        System.out.print("\n");
        System.out.print("\n");
        //PRINT ELEMENTS
        cursor = V1.iterator();
        System.out.print("{ ");
        while (cursor.hasNext())
        {
            System.out.print(cursor.next());
            System.out.print(" ");
        }
        System.out.print(" }");
        System.out.print("\n");
        System.out.print("\n");
        //CONTAINS TEST
        GTUIterator foundedV1 = V1.contains(2); //eger bulamazsa son elemani return eder
        System.out.print("Find(2) : ");
        System.out.print("Element ");
        System.out.print(foundedV1.next());
        System.out.print(" is founded.");
        System.out.print("\n");
        System.out.print("\n");

        System.out.print("------------V2-------------");
        System.out.print("\n");
        System.out.print("\n");
        //PRINT ELEMENTS
        cursor = V2.iterator();
        System.out.print("{ ");

        while (cursor.hasNext())
        {
            System.out.print(cursor.next());
            System.out.print(" ");
        }
        System.out.print(" }");
        System.out.print("\n");
        System.out.print("\n");
        //ITERATOR TEST
        GTUIterator cursorV2 = V2.iterator();
        System.out.print("Iter Begin ");
        System.out.print(cursorV2.next());
        System.out.print("\n");
        System.out.print("\n");
        //SIZE & MAX. SIZE TEST
        System.out.print("Size : ");
        System.out.print(V2.size());
        System.out.print("\n");
        System.out.print("Max. Size : ");
        System.out.print(V2.max_size());
        System.out.print("\n");
        System.out.print("\n");
        //ERASE TEST
        V2.erase("umarım");
        System.out.print("Erase: Element 'umarım' is erased.");
        System.out.print("\n");
        System.out.print("\n");
        //PRINT ELEMENTS
        cursor = V2.iterator();
        System.out.print("{ ");

        while (cursor.hasNext())
        {
            System.out.print(cursor.next());
            System.out.print(" ");
        }
        System.out.print(" }");
        System.out.print("\n");
        System.out.print("\n");
        //CONTAINS TEST
        GTUIterator foundedV2 = V2.contains("dersi"); //eger bulamazsa son elemani return eder
        System.out.print("Find('dersi') : ");
        System.out.print("Element '");
        System.out.print(foundedV2.next());
        System.out.print("' is founded.");
        System.out.print("\n");
        System.out.print("\n");

        System.out.print("--------------------------");
        System.out.print("\n");
        System.out.print("\n");

        V1.clear();
        V2.clear();

            System.out.print("Vectors is clear.");
            System.out.print("\n");
            System.out.print("\n");

    }
}
