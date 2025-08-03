#include <iostream>
using namespace std;

// Pair class template
template <class T>
class Pair {
private:
    T values[2];

public:
    Pair();                     // Default constructor
    Pair(T a, T b);             // Parameterized constructor
    T getmax();                 // Inline
    T getmin();                 // Declared here, defined outside

    // Friend function declaration
    template <class U>
    friend ostream& operator<<(ostream& out, const Pair<U>& p);
};

// Default constructor
template <class T>
Pair<T>::Pair() {
    values[0] = T();
    values[1] = T();
}

// Parameterized constructor
template <class T>
Pair<T>::Pair(T a, T b) {
    values[0] = a;
    values[1] = b;
}

// getmax inline
template <class T>
T Pair<T>::getmax() {
    if (values[0] > values[1])
        return values[0];
    else
        return values[1];
}

// getmin defiined outside
template <class T>
T Pair<T>::getmin() {
    if (values[0] < values[1])
        return values[0];
    else
        return values[1];
}

// Friend function for ostream <<
template <class U>
ostream& operator<<(ostream& out, const Pair<U>& p) {
    out << "(" << p.values[0] << ", " << p.values[1] << ")";
    return out;
}

// Sequence class template
template <class T, int N>
class Sequence {
private:
    T memblock[N];

public:
    void setmember(int x, T value);
    T getmember(int x);
};

template <class T, int N>
void Sequence<T, N>::setmember(int x, T value) {
    if (x >= 0 && x < N)
        memblock[x] = value;
}

template <class T, int N>
T Sequence<T, N>::getmember(int x) {
    if (x >= 0 && x < N)
        return memblock[x];
    return T();  // Default-initialized if out of bounds
}

// Main function for Exercise 5
int main() {
    Pair<double> y(2.23, 3.45);
    Sequence<Pair<double>, 5> myPairs;

    myPairs.setmember(0, y);
    cout << myPairs.getmember(0) << '\n';

    return 0;
}
