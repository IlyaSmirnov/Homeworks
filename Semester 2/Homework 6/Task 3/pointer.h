template<typename T>
struct Pointer
{
    Pointer();
    Pointer(T *pointer);
    ~Pointer();

    T *pointer;
};

template<typename T>
Pointer<T>::Pointer() : pointer(nullptr)
{

}

template<typename T>
Pointer<T>::Pointer(T *pointer) : pointer(pointer)
{

}

template<typename T>
Pointer<T>::~Pointer()
{
    delete pointer;
}
