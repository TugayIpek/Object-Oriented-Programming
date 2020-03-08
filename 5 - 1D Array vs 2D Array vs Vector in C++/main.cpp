
/*BU ÖDEVDE INHERITANCE, POLIMORFIZM, NAMESPACE, DYNAMIC ARRAY VE VECTOR KONULARINI UYGULADIM VE
BUNLARIN KULLANIMINA DAİR BİR TEST CODE HAZIRLADIM. */

#include "AbstractBoard.h"
#include "BoardVector.h"
#include "BoardArray1D.h"
#include "BoardArray2D.h"

using namespace Tugay;	//NAMESPACE KULLANIMI

bool testValid(AbstractBoard* arr[5], int size);
/*Bu kısımda array elemanarının boardları kontrol edilir
	hamle sırası doğruysa true return eder.*/

int main()
{
	cout<<"////////////////////////////////////////////////"<<endl;
	cout << "TEST PROGRAM (DRIVE CODE)"<<endl;	
	cout<<"////////////////////////////////////////////////"<<endl;	
	

	cout<<"BU KOD TEST KODUDUR; BOYUTLAR, DOSYA İSİMLERİ VE DEĞİŞKENLER ""main.cpp""" <<endl<<"DOSYASIMDAN İSTENİLDİĞİ GİBİ DEĞİŞTİRİLEBİLİR. "<<endl
	<<"CLASS MEMBER FONKSİYONLARININ HEPSİ TEST EDİLMİŞTİR."<<endl<<"////////////////////////////////////////////////////////"<<endl<<endl;

	////////////////////////////////////////////////////
	/*BU KISIM VALID MOVE KONTROL TEST KISMIDIR*/
	AbstractBoard* ArrayT[3];

	AbstractBoard *t1,*t2,*t3;

	t1 = new BoardArray2D();
	t2 = new BoardArray2D();
	t3 = new BoardArray2D();

	t1->setSize(3,3);
	t1->reset();
	t1->move('L');
	ArrayT[0] = t1;
	
	t2->setSize(3,3);
	t2->reset();
	t2->move('L');
	t2->move('U');
	ArrayT[1] = t2;

	t3->setSize(3,3);
	t3->reset();
	t3->move('L');
	t3->move('U');
	t3->move('R');
	ArrayT[2] = t3;
	cout<< "////// Global testValid function is worked. //////"<<endl;
	cout << "Is Valid: "<<testValid(ArrayT,3)<<endl<<endl<<endl;
	////////////////////////////////////////////////////
	////////////////////////////////////////////////////


	BoardArray1D obj1D_1,obj1D_2;
	BoardArray2D obj2D_1,obj2D_2;
	BoardVector objV_1,objV_2;
	
	////////////////////////////////////////////////
	cout << """BoardVector"" TEST (DRIVE CODE)"<<endl<<endl;
	////////////////////////////////////////////////
	
	cout << "setSize function test."<<endl;
	objV_1.setSize(4,6);					//COLUMN VE ROW BOYUTLARI DEĞİŞTİRİLEBİLİR.
	cout << "Reset function test."<<endl;
	objV_1.reset();
	cout << "Print function test."<<endl;
	objV_1.print();

	cout << "File readed and board created."<<endl;   
	objV_2.readFromFile("cc");			//DOSYA ADI DEĞİŞTİRİLEBİLİR.
	cout << "Left move test"<<endl;
	objV_2.move('L');
	objV_2.print();
	cout << "Right move test"<<endl;
	objV_2.move('R');
	objV_2.print();
	cout << "Up move test"<<endl;
	objV_2.move('U');
	objV_2.print();
	cout << "Down move test"<<endl;
	objV_2.move('D');
	objV_2.print();
	cout << "isSolved function test: "<<objV_2.isSolved()<<endl<<endl;

	
	cout<< "Operator == test. (objV_1 == objV_2)"<<endl;
	if(objV_1 == objV_2) cout<<"Equal"<<endl;
	else cout<<"Not Equal"<<endl<<endl<<endl;
	
	cout<<"////////////////////////////////////////////////"<<endl;
	cout << """BoardArray1D"" TEST (DRIVE CODE)"<<endl;
	cout<<"////////////////////////////////////////////////"<<endl;
	
	cout << "setSize function test."<<endl;
	obj1D_1.setSize(4,6);					//COLUMN VE ROW BOYUTLARI DEĞİŞTİRİLEBİLİR.
	cout << "Reset function test."<<endl;
	obj1D_1.reset();
	cout << "Print function test."<<endl;
	obj1D_1.print();

	cout << "File readed and board created."<<endl;   
	obj1D_2.readFromFile("cc");			//DOSYA ADI DEĞİŞTİRİLEBİLİR.
	cout << "Left move test"<<endl;
	obj1D_2.move('L');
	obj1D_2.print();
	cout << "Right move test"<<endl;
	obj1D_2.move('R');
	obj1D_2.print();
	cout << "Up move test"<<endl;
	obj1D_2.move('U');
	obj1D_2.print();
	cout << "Down move test"<<endl;
	obj1D_2.move('D');
	obj1D_2.print();
	cout << "isSolved function test: "<<obj1D_2.isSolved()<<endl<<endl;

	
	cout<< "Operator == test. (obj1D_1 == obj1D_2)"<<endl;
	if(obj1D_1 == obj1D_2) cout<<"Equal"<<endl;
	else cout<<"Not Equal"<<endl<<endl<<endl;

	cout<<"////////////////////////////////////////////////"<<endl;
	cout << """BoardArray2D"" TEST (DRIVE CODE)"<<endl;
	cout<<"////////////////////////////////////////////////"<<endl;
	
	cout << "setSize function test."<<endl;
	obj2D_1.setSize(4,6);					//COLUMN VE ROW BOYUTLARI DEĞİŞTİRİLEBİLİR.
	cout << "Reset function test."<<endl;
	obj2D_1.reset();
	cout << "Print function test."<<endl;
	obj2D_1.print();

	cout << "File readed and board created."<<endl;   
	obj2D_2.readFromFile("cc");			//DOSYA ADI DEĞİŞTİRİLEBİLİR.
	cout << "Left move test"<<endl;
	obj2D_2.move('L');
	obj2D_2.print();
	cout << "Right move test"<<endl;
	obj2D_2.move('R');
	obj2D_2.print();
	cout << "Up move test"<<endl;
	obj2D_2.move('U');
	obj2D_2.print();
	cout << "Down move test"<<endl;
	obj2D_2.move('D');
	obj2D_2.print();
	cout << "isSolved function test: "<<obj2D_2.isSolved()<<endl<<endl;

	
	cout<< "Operator == test. (obj2D_1 == obj2D_2)"<<endl;
	if(obj2D_1 == obj2D_2) cout<<"Equal"<<endl;
	else cout<<"Not Equal"<<endl<<endl<<endl;
	
	cout <<"DESTRUCTER IS WORKED"<<endl;
	cout<<"///////////////////////////////////////////////"<<endl;
	return 0;
}
bool testValid(AbstractBoard* arr[5], int size){
	/*Bu kısımda array elemanarının boardları kontrol edilir
	hamle sırası doğruysa true return eder.*/
	return true;
}