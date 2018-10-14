#ifndef myvector_h
#define myvector_h

#include <cstring>
#include <type_traits>
#include <initializer_list>

template <typename Type>
class myVector {
private:
    Type* array;
    int vector_capacity;
    int vector_size;
public:
    //Constructors
    myVector(int n = 0, Type value = Type()) {
        initialize(n + 10);
        if (value) {
            for ( ; n > 0; n--) {
                push_back(value);
            }
        }
    }
    
    //Copy Constructor
    myVector(myVector& vectorToCopy) {
        initialize();
        *this = vectorToCopy;
    }
    
    //Destructor
    ~myVector() {delete [] array; array = nullptr;}
    
    //Exceptions
    class underflow {};
    class not_trivially_copyable{};
    
    //Accessors
    Type front() {return !empty() ? array[0] :
        throw underflow();}
    Type back() {return !empty() ? array [size() - 1] :
        throw underflow();}
    Type* begin() {return array;}
    Type* end() {return (array + (size() - 1));}
    int size() const {return vector_size;}
    int capacity() {return vector_capacity;}
    bool empty() {return !vector_size;}
    Type at(int const) const;
    void clear();
    
    //Mutators
    void push_back(Type const& val);
    Type pop_back();
    void increase_capacity();
    void initialize(int n = 10);
    myVector& operator=(const myVector&);
    void erase(int);
    void insert(int, Type);
    void shrink_to_fit();
    void resize(int, Type val = Type());
    void swap(myVector<Type>&);
    void assign(int, const Type&);
    void assign(std::initializer_list<Type> list);
};

template <typename Type>
void myVector<Type>::push_back(Type const& val) {
    if (size() == capacity()) {
        increase_capacity();
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
void myVector<Type>::increase_capacity() {
    Type* temp_array = new Type[1.5 * capacity()];
    std::is_trivially_copyable<Type>::value ? memcpy(temp_array, array, size() * sizeof(Type)) : throw not_trivially_copyable();
    delete [] array;
    array = temp_array;
    vector_capacity = 1.5 * capacity();
}

template <typename Type>
Type myVector<Type>::at(int const index) const {
    return !(index > (size() - 1) || index < 0) ? *(array + index) : throw underflow();
}

template <typename Type>
void myVector<Type>::clear() {
    delete [] array;
    initialize();
}

template <typename Type>
void myVector<Type>::initialize(int n) {
    vector_capacity = std::max(1, n);
    array = new Type[vector_capacity];
    vector_size = 0;
}


template <typename Type>
myVector<Type> &myVector<Type>::operator=(const myVector<Type>& rhs) {
    if(this == &rhs) {
        return *this;
    }
    else {
        clear();
        resize(rhs.size());
        memcpy(array, rhs.array, (rhs.size() * sizeof(Type)));
        //for(int i = 0; i < rhs.size(); i++) {
          //  push_back(rhs.at(i));
        //}
    }
    return *this;
}

template <typename Type>
void myVector<Type>::erase(int position) {
    memcpy(array +position, array + (position + 1), ((array +(size() - 1) -  array + (position + 1)) * sizeof(Type)));
    array[size() -1] = Type();
    vector_size--;
}

template <typename Type>
void myVector<Type>::insert(int position, Type value) {
    if (position > size()) {
        throw underflow();
    }
    else if( position == size()) {
        push_back(value);
    }
    else {
        if(size() == capacity()) {
            increase_capacity();
        }
        Type *temp_array = new Type[capacity()];
        std::is_trivially_copyable<Type>::value ? memcpy(temp_array, array, position * sizeof(Type)) : throw not_trivially_copyable();
        temp_array[position] = value;
        memcpy(temp_array + (position + 1), array + position, (size() - position) * sizeof(Type));
        
        delete [] array;
        vector_size++;
        array = temp_array;
    }
}

template <typename Type>
void myVector<Type>::shrink_to_fit() {
    Type* temp_array = new Type[size()];
    std::is_trivially_copyable<Type>::value ? memcpy(temp_array, array, size() * sizeof(Type)) : throw not_trivially_copyable();
    delete [] array;
    vector_capacity = size();
    array = temp_array;
}

template <typename Type>
void myVector<Type>::resize(int newSize, Type val) {
    newSize = std::max(0, newSize);
    
    if(newSize < size()) {
        Type *temp_array = new Type[newSize + 10];
        std::is_trivially_copyable<Type>::value ? memcpy(temp_array, array, newSize * sizeof(Type)) : throw not_trivially_copyable();
        delete [] array;
        array = temp_array;
        vector_capacity = newSize + 10;
        
    }
    else if(newSize > size()) {
        if(newSize > capacity()) {
            Type *temp_array = new Type[newSize + 10];
            std::is_trivially_copyable<Type>::value ? memcpy(temp_array, array, newSize * sizeof(Type)) : throw not_trivially_copyable();
            delete [] array;
            array = temp_array;
            vector_capacity = newSize + 10;
        }
        for(int i = size(); i < newSize; i++) {
            push_back(val);
        }
    }
    vector_size = newSize;
}

template <typename Type>
void myVector<Type>::swap(myVector<Type>& inVector) {
    myVector<Type> tempVector = inVector;
    inVector = *this;
    *this = tempVector;
}

template <typename Type>
void myVector<Type>::assign(int count, const Type &val) {
    clear();
    for (int i = 0; i < count; i++) {
        push_back(val);
    }
}

template <typename Type>
void myVector<Type>::assign(std::initializer_list<Type> list) {
    clear();
    resize(list.size());
    std::is_trivially_copyable<Type>::value ? memcpy(array, list.begin(), sizeof(Type) * list.size()) : throw not_trivially_copyable();
}

#endif /* myvector_h */
