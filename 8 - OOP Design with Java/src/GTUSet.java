/**
 * This class is derived class of Container base class.
 * Has an array and keep a list in this array.
 * @param <T>
 */
public class GTUSet<T> extends GTUContainer<T> {

    protected Object[] SetArray;
    protected int size;
    protected int max_Size;

    GTUSet(){
        SetArray= (T[]) new Object[10];
        size=0;
        max_Size=10;

    }

    public boolean empty() {
        if(size==0)
            return true;

        return false;
    }

    public int size() {
        return size;
    }

    public int max_size() {
        return max_Size;
    }

    public void insert(T e) {

        if(check(e)==1)
            return;

        if(max_Size==0){
            max_Size=10;
            SetArray=(T[]) new Object[max_Size];
        }

        SetArray[size]=e;
        size++;

        if(size >= max_Size){
            Object[] temp = (T[]) new Object[size];
            for(int i=0;i<size;i++)
                temp[i]=SetArray[i];

            max_Size*=2;
            SetArray=null;
            SetArray=(T[]) new Object[max_Size];

            for(int i=0;i<size;i++)
                SetArray[i]=temp[i];
        }
    }

    public void erase(T e) {

        Object[] temp = (T[]) new Object[size];
        int check=0;
        for(int i=0;i<size;i++){
            if(!e.equals(SetArray[i])){

                temp[check]=SetArray[i];
                check++;
            }
        }

        if(check!=size){
            for(int i=0;i<check;i++){
                SetArray[i]=temp[i];
            }
            size--;
        }
    }

    public void clear() {
        size=0;
        max_Size=0;
        SetArray=null;
    }

    public GTUIterator<T> contains(T e) {
        GTUIterator<T> temp =new GTUIterator<>();
        temp.Set_Arr=  SetArray;

        temp.size=size;

        for(int i=0;i<size;i++){
            if(e.equals(SetArray[i])){
                temp.cursor= (T) SetArray[i];
                temp.index=i;
                return temp;
            }
        }
        return null;
    }

    public GTUIterator<T> iterator() {

        GTUIterator<T> temp =new GTUIterator<>();
        temp.Set_Arr=  SetArray;
        temp.cursor= (T) SetArray[0];
        temp.size=size;
        temp.index=0;
        return temp;

    }

    public int check(T e) {

        for (int i=0;i<size;i++){

            if(e.equals(SetArray[i])){
                return 1;
            }
        }

        return 0;
    }
}