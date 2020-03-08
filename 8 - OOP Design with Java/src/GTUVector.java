/**
 * This class is derived class of Container base class.
 * Has an vector and keep a list in this vector.
 * @param <T>
 */
public class GTUVector<T> extends GTUContainer<T> {

    protected Object[] VecArray;
    protected int size;
    protected int max_Size;

    GTUVector(){
        VecArray= (T[]) new Object[10];
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
            VecArray=(T[]) new Object[max_Size];
        }

        VecArray[size]=e;
        size++;

        if(size >= max_Size){
            Object[] temp = (T[]) new Object[size];
            for(int i=0;i<size;i++)
                temp[i]=VecArray[i];

            max_Size*=2;
            VecArray=null;
            VecArray=(T[]) new Object[max_Size];

            for(int i=0;i<size;i++)
                VecArray[i]=temp[i];
        }
    }

    public void erase(T e) {

        Object[] temp = (T[]) new Object[size];
        int check=0;
        for(int i=0;i<size;i++){
            if(!e.equals(VecArray[i])){

                temp[check]=VecArray[i];
                check++;
            }
        }

        if(check!=size){
            for(int i=0;i<check;i++){
                VecArray[i]=temp[i];
            }
            size--;
        }
    }

    public void clear() {
        size=0;
        max_Size=0;
        VecArray=null;
    }

    public GTUIterator<T> contains(T e) {
        GTUIterator<T> temp =new GTUIterator<>();
        temp.Set_Arr=  VecArray;

        temp.size=size;

        for(int i=0;i<size;i++){
            if(e.equals(VecArray[i])){
                temp.cursor= (T) VecArray[i];
                temp.index=i;
                return temp;
            }
        }
        return null;
    }

    public GTUIterator<T> iterator() {

        GTUIterator<T> temp =new GTUIterator<>();
        temp.Set_Arr=  VecArray;
        temp.cursor= (T) VecArray[0];
        temp.size=size;
        temp.index=0;
        return temp;

    }

    public int check(T e) {

        for (int i=0;i<size;i++){

            if(e.equals(VecArray[i])){
                return 1;
            }
        }
        return 0;
    }
}