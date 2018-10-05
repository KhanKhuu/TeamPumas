#ifndef myvector_h
#define myvector_h

template <typename Type>
class myVector {
private:
    Type* array;
    int array_capacity;
    int vector_size;
public:
    //Constructors
    myVector(int n = 10, Type value = Type())//:
    /*vector_size(0),*/
    /*array_capacity(std::max(1, n))*/ {
        //array = new Type[array_capacity];
        initialize(n);
        if (value) {
            for ( ; n > 0; n--) {
                push_back(value);
            }
        }
    }
    
    //Destructor
    ~myVector() {delete [] array; array = nullptr;}
    
    //Exceptions
    class underflow {};
    
    //Accessors
    Type front() {return !empty() ? array[0] :
        throw underflow();}
    Type back() {return !empty() ? array [size() - 1] :
        throw underflow();}
    Type* begin() {return array;}
    Type* end() {return (array + (size() - 1));}
    int size() {return vector_size;}
    int capacity() {return array_capacity;}
    bool empty() {return !vector_size;}
    Type at(int const);
    void clear();
    
    //Mutators
    void push_back(Type const& val);
    Type pop_back();
    void double_capacity();
    void initialize(int n = 10);
    //myVector& operator=(const myVector&);
};

template <typename Type>
void myVector<Type>::push_back(Type const& val) {
    if (size() == capacity()) {
        double_capacity();
    }
    array[vector_size++] = val;
}

template <typename Type>
Type myVector<Type>::pop_back() {
    if (empty()) {
        throw underflow();
    }
    return array[--vector_size];
}

template <typename Type>
void myVector<Type>::double_capacity() {
    Type* temp_array = new Type[2 * capacity()];
    for (int i = 0; i < capacity(); i++) {
        temp_array[i] = array[i];
    }
    delete [] array;
    array = temp_array;
    array_capacity *= 2;
}

template <typename Type>
Type myVector<Type>::at(int const index) {
    return !(index > (size() - 1) && index < 0) ? *(array + index) : throw underflow();
}

template <typename Type>
void myVector<Type>::clear() {
    delete [] array;
    initialize();
    
    /*
    array = new Type[10];
    vector_size = 0;
    array_capacity = 10;
     */
}
template <typename Type>
void myVector<Type>::initialize(int n) {
    array_capacity = std::max(1, n);
    array = new Type[array_capacity];
    vector_size = 0;
 
}

// Hello underworld

/*
template <typename Type>
myVector<Type>& myVector<Type>::operator=(const myVector<Type>& rhs) {
    myVector newVector;
}
*/

#endif /* myvector_h */
