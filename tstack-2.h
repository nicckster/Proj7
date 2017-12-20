#ifndef ADTSTACK_TSTACK_H
#define ADTSTACK_TSTACK_H

#include <iostream>
#include <algorithm>

namespace fsu {
    template<typename T, size_t N=100>
    class Stack {
    public:
        void Push(const T &t); // push t onto stack; error if full
        T Pop(); // pop stack and return removed element; error if stack is empty
        T &Top(); // return top element of stack; error if stack is empty
        const T &Top() const; // const version
        size_t Size() const; // return number of elements in stack
        size_t Capacity() const; // return storage capacity [maximum size] of stack
        bool Empty() const; // return 1/true if stack is empty, 0/false if not empty
        void Clear(); // make the stack empty

        Stack(); // default constructor
        Stack(char ofc, int dir); // sets ofc_ and dir_
        Stack(const Stack &); // copy constructor
        ~Stack(); // destructor
        Stack &operator=(const Stack &); // assignment operator

        void Display(std::ostream &os) const; // output stack contents through os - depends on ofc_ and dir_
        void SetOFC(char ofc);

        void SetDIR(int dir);

        void Dump(std::ostream &os) const; // output all private data (for development use only)

    private:
        const size_t capacity_; // = N = size of array - fixed during life of stack
        T data_[N]; // statically declared array of T objects - where T objects are stored
        size_t size_; // current size of stack - dynamic during life of stack

        char ofc_;
        int dir_;
    };

    template<typename T, size_t N>
    std::ostream &operator<<(std::ostream &os, const Stack<T, N> &s) {
        s.Display(os);
        return os;
    }

    template<typename T, size_t N>
    Stack<T, N>::Stack():capacity_(N > 0 ? N : 1) {
        size_ = 0;
        ofc_ = '\0';
        dir_ = 0;
    }

    template<typename T, size_t N>
    Stack<T, N>::Stack(char ofc, int dir):capacity_(N > 0 ? N : 1) {
        size_ = 0;
        ofc_ = ofc;
        dir_ = dir;
    }

    template <typename T, size_t N>
    Stack<T, N>::Stack(const Stack &other):capacity_(other.capacity_) {
        size_ = other.size_;
        ofc_ = other.ofc_;
        dir_ = other.dir_;
        std::copy(std::begin(other.data_), std::end(other.data_), std::begin(data_));
    }

    template <typename T, size_t N>
    Stack<T, N>& Stack<T, N>::operator=(const Stack &rhs){
        if(this != &rhs) {
            size_ = rhs.size_;
            ofc_ = rhs.ofc_;
            dir_ = rhs.dir_;
            std::copy(std::begin(rhs.data_), std::end(rhs.data_), std::begin(data_));
        }
        return *this;
    }

    template <typename T, size_t N>
    Stack<T, N>::~Stack() {

    }

    template <typename T, size_t N>
    void Stack<T, N>::Push(const T &t) {
        if(Empty()){
            data_[size_] = t;
//            std::cout << "Element: " << t << '\n';
            size_++;
        }

        else{
            std::cerr << "Stack Overflow\n";
        }
    }

    template <typename T, size_t N>
    T Stack<T, N>::Pop() {
        if(Size() > 0){
            --size_;
            return data_[size_];
        }
        else{
            std::cerr << "Stack underflow\n";
            return T();
        }

    }

    template <typename T, size_t N>
    T& Stack<T, N>::Top() {
        if(Size() > 0){
            return data_[size_ - 1];
        }
        else{
            std::cerr << "Stack underflow\n";
            return data_[0];
//            throw std::underflow_error("Stack is empty\n");
        }
    }

    template <typename T, size_t N>
    const T& Stack<T, N>::Top() const {
        if(Size() > 0){
            return data_[size_ - 1];
        }
        else{
            std::cerr << "Stack underflow\n";
            return data_[0];
//            throw std::underflow_error("Stack is empty\n");
        }
    }

    template <typename T, size_t N>
    bool Stack<T, N>::Empty() const {
        return size_ <= capacity_;
    }

    template <typename T, size_t N>
    size_t Stack<T, N>::Size() const {
        return size_;
    }

    template <typename T, size_t N>
    size_t Stack<T, N>::Capacity() const {
        return capacity_;
    }

    template <typename T, size_t N>
    void Stack<T, N>::Clear() {
        size_ = 0;
    }

    template <typename T, size_t N>
    void Stack<T, N>::Display(std::ostream &os) const {

        if(dir_ >= 0){
            for(long i = Size()-1; i >= 0; --i){
                os << data_[i];
                if(ofc_ != '\0')
                    os << ofc_;
            }
        }
        else if(dir_ < 0){
            for(long i = Size()-1; i >= 0; --i){
                os << data_[i];
                if(ofc_ != '\0')
                    os << ofc_;
            }
        }

        std::cout << "\n";
    }

    template <typename T, size_t N>
    void Stack<T, N>::SetDIR(int dir) {
        dir_ = dir;
    }

    template <typename T, size_t N>
    void Stack<T, N>::SetOFC(char ofc) {
        ofc_ = ofc;
    }

    template <typename T, size_t N>
    void Stack<T, N>::Dump(std::ostream &os) const {
        os << "Stack: " << *this;
        os << "Capacity: " << capacity_ << "\n";
        os << "Size: " << size_ << "\n";
        os << "OFC: " << ofc_ << "\n";
        os << "DIR: " << dir_ << "\n";
    }
}

//using namespace fsu;
#endif //ADTSTACK_TSTACK_H
