/**
 * This class has many methods.
 * This methods are used for makes many operation in list.
 * Operation like; see size, maxsize or erase,clear,insert est.
 * @param <T>
 */
public abstract class GTUContainer <T> {

    public abstract boolean empty();
    public abstract int size();
    public abstract int max_size();
    public abstract void insert(T e);
    public abstract void erase(T e);
    public abstract void clear();
    public abstract  GTUIterator<T> contains(T e);
    public abstract GTUIterator<T> iterator();
    public abstract int check(T e); //helper method

}