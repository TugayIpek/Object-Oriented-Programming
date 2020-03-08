/**
 * This class includes hasNext and next methods.
 * This methods are used for moves in list.
 * @param <T>
 */
public class GTUIterator<T>{

    T cursor;
    Object[] Set_Arr;
    int size;
    int index;

    public boolean hasNext(){
        if(index<size){
            return true;
        }
        return false;
    }

    public T next(){
        if(index==-1)
            index=0;
        index++;
        return (T) Set_Arr[index-1];
    }
}