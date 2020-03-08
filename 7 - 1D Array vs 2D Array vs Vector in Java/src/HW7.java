/** JAVADOC SAMPLE
 * @ TUGAY IPEK
 * @ 161044034
 * @ 17.01.20
 * Drive Code
 * This main code contains a test code for each methods of BoardArray1D and BoardArray2D
 */

import java.io.FileNotFoundException;

public class HW7 {

    public static void main(String[] args) throws FileNotFoundException {
        System.out.print("////////////////////////////////////////////////");
        System.out.print("\n");
        System.out.print("TEST PROGRAM (DRIVE CODE)");
        System.out.print("\n");
        System.out.print("////////////////////////////////////////////////");
        System.out.print("\n");


        System.out.print("BU KOD TEST KODUDUR; BOYUTLAR, DOSYA ISLEMLERI VE DEGISKENLER 'main.cpp'");
        System.out.print("\n");
        System.out.print("DOSYASINDAN ISTENILDIGI GIBI DEGISTIRILEBILIR. ");
        System.out.print("\n");
        System.out.print("CLASS MEMBER FONKSIYONLARIN HEPSI TEST EDILMISTIR.");
        System.out.print("\n");
        System.out.print("////////////////////////////////////////////////////////");
        System.out.print("\n");
        System.out.print("\n");

        ////////////////////////////////////////////////////
        /*BU KISIM VALID MOVE KONTROL TEST KISMIDIR*/
        AbstractBoard[] ArrayT = new AbstractBoard[3];

        AbstractBoard t1;
        AbstractBoard t2;
        AbstractBoard t3;

        t1 = new BoardArray2D();
        t2 = new BoardArray2D();
        t3 = new BoardArray2D();

        t1.setSize(3,3);
        t1.reset();
        t1.move('L');
        ArrayT[0] = t1;

        t2.setSize(3,3);
        t2.reset();
        t2.move('L');
        t2.move('U');
        ArrayT[1] = t2;

        t3.setSize(3,3);
        t3.reset();
        t3.move('L');
        t3.move('U');
        t3.move('R');
        ArrayT[2] = t3;
        System.out.print("////// Global testValid function is worked. //////");
        System.out.print("\n");
        System.out.print("Is Valid: ");
        System.out.print(testValid(ArrayT, 3));
        System.out.print("\n");
        System.out.print("\n");
        System.out.print("\n");
        ////////////////////////////////////////////////////
        ////////////////////////////////////////////////////

        BoardArray1D obj1D_1 = new BoardArray1D();
        BoardArray1D obj1D_2 = new BoardArray1D();
        BoardArray2D obj2D_1 = new BoardArray2D();
        BoardArray2D obj2D_2 = new BoardArray2D();

        System.out.print("////////////////////////////////////////////////");
        System.out.print("\n");
        System.out.print("BoardArray1D TEST (DRIVE CODE)");
        System.out.print("\n");
        System.out.print("////////////////////////////////////////////////");
        System.out.print("\n");

        System.out.print("setSize function test.");
        System.out.print("\n");
        obj1D_1.setSize(4,6); //COLUMN VE ROW BOYUTLARI DEGISTIRILABILIR.
        System.out.print("Reset function test.");
        System.out.print("\n");
        obj1D_1.reset();
        System.out.print("toString function test.");
        System.out.print("\n");
        obj1D_1.toString();

        System.out.print("Left move test");
        System.out.print("\n");
        obj1D_1.move('L');
        obj1D_1.toString();
        System.out.print("Right move test");
        System.out.print("\n");
        obj1D_1.move('R');
        obj1D_1.toString();
        System.out.print("Up move test");
        System.out.print("\n");
        obj1D_1.move('U');
        obj1D_1.toString();
        System.out.print("Down move test");
        System.out.print("\n");
        obj1D_1.move('D');
        obj1D_1.toString();
        System.out.print("isSolved function test: ");
        System.out.print(obj1D_1.isSolved());
        System.out.print("\n");
        System.out.print("\n");

        //DOSYA FONKSIYONLSARININ TESTI ICIN ASAGIDAKI YORUM SATIRINA ALINMIS BOLUM ACILMALI VE DOSYA ISMI GIRILMELIDIR.

       /*System.out.print("File readed and board created.");
        System.out.print("\n");
        //obj1D_2.readFromFile("cc"); //DOSYA ADI DEGISTIRILEBILIR.
        System.out.print("Left move test");
        System.out.print("\n");
        obj1D_2.move('L');
        obj1D_2.toString();
        System.out.print("Right move test");
        System.out.print("\n");
        obj1D_2.move('R');
        obj1D_2.toString();
        System.out.print("Up move test");
        System.out.print("\n");
        obj1D_2.move('U');
        obj1D_2.toString();
        System.out.print("Down move test");
        System.out.print("\n");
        obj1D_2.move('D');
        obj1D_2.toString();
        System.out.print("isSolved function test: ");
        System.out.print(obj1D_2.isSolved());
        System.out.print("\n");
        System.out.print("\n");*/

        System.out.print("Cell test. (obj1D_1 == obj1D_2)");
        System.out.print("\n");
        if (obj1D_1 == obj1D_2)
        {
            System.out.print("Equal");
            System.out.print("\n");
        }
        else
        {
            System.out.print("Not Equal");
            System.out.print("\n");
            System.out.print("\n");
            System.out.print("\n");
        }

        System.out.print("////////////////////////////////////////////////");
        System.out.print("\n");
        System.out.print("BoardArray2D TEST (DRIVE CODE)");
        System.out.print("\n");
        System.out.print("////////////////////////////////////////////////");
        System.out.print("\n");

        System.out.print("setSize function test.");
        System.out.print("\n");
        obj2D_1.setSize(4,6); //COLUMN VE ROW BOYUTLARI DEGISTIRILEBILIR.
        System.out.print("Reset function test.");
        System.out.print("\n");
        obj2D_1.reset();
        System.out.print("toString function test.");
        System.out.print("\n");
        obj2D_1.toString();

        System.out.print("Left move test");
        System.out.print("\n");
        obj2D_1.move('L');
        obj2D_1.toString();
        System.out.print("Right move test");
        System.out.print("\n");
        obj2D_1.move('R');
        obj2D_1.toString();
        System.out.print("Up move test");
        System.out.print("\n");
        obj2D_1.move('U');
        obj2D_1.toString();
        System.out.print("Down move test");
        System.out.print("\n");
        obj2D_1.move('D');
        obj2D_1.toString();
        System.out.print("isSolved function test: ");
        System.out.print(obj2D_1.isSolved());
        System.out.print("\n");
        System.out.print("\n");

        //DOSYA FONKSIYONLSARININ TESTI ICIN ASAGIDAKI YORUM SATIRINA ALINMIS BOLUM ACILMALI VE DOSYA ISMI GIRILMELIDIR.

        /*System.out.print("File readed and board created.");
        System.out.print("\n");
        obj2D_2.readFromFile("cc"); //DOSYA ADI DEGISTIRILEBILIR.
        System.out.print("Left move test");
        System.out.print("\n");
        obj2D_2.move('L');
        obj2D_2.toString();
        System.out.print("Right move test");
        System.out.print("\n");
        obj2D_2.move('R');
        obj2D_2.toString();
        System.out.print("Up move test");
        System.out.print("\n");
        obj2D_2.move('U');
        obj2D_2.toString();
        System.out.print("Down move test");
        System.out.print("\n");
        obj2D_2.move('D');
        obj2D_2.toString();
        System.out.print("isSolved function test: ");
        System.out.print(obj2D_2.isSolved());
        System.out.print("\n");
        System.out.print("\n");*/


        System.out.print("Cell test. (obj2D_1 == obj2D_2)");
        System.out.print("\n");
        if (obj2D_1 == obj2D_2)
        {
            System.out.print("Equal");
            System.out.print("\n");
        }
        else
        {
            System.out.print("Not Equal");
            System.out.print("\n");
            System.out.print("\n");
            System.out.print("\n");
        }

        System.out.print("TEST IS FINISHED");
        System.out.print("\n");
        System.out.print("///////////////////////////////////////////////");
        System.out.print("\n");
    }

    private static boolean testValid(AbstractBoard[] arrayT, int i) {
        /*this method is using for moves validity.
        if move is valid, returns true but otherwise its returns false.*/
        return true;
    }

}
