#include <iostream>
#include "stack.h"

//int resta(Stack mayor,Stack menor);
std::string resta(Stack mayor,Stack menor);

template <typename T>
void swap(T& a, T& b);

int main() {
    using std::string;
    Stack mayor{};
    Stack menor{};
    std::cout<<"Ingrese  la operacion: ";
    string texto;
    std::cin>>texto;
    size_t medio {texto.find('-')};
    for(char i: texto.substr(0,medio)){
        int numero = i-'0';
        mayor.push(numero);
    }
    std::cout<<'\t';
    for(char i: texto.substr(medio+1,string::npos)){
        if(i=='=') break;
        int numero = i-'0';
        menor.push(numero);
    }
    std::cout<<resta(mayor,menor)<<'\n';
    return 0;
}

std::string resta(Stack mayor,Stack menor){
    using std::string;
    int extra{};
    string resultado{};
    while (!mayor.isEmpty()){
        int M{mayor.pop()};
        int m{};
        if(!menor.isEmpty()){
            m = menor.pop();
        }
        int op = M-m-extra;
        if(op<0){
            op+=10;
            extra=1;
        }else{
            extra=0;
        }
        resultado+= std::to_string(op);
    }
    int n {static_cast<int>(resultado.length())};
    for(int i{}; i<n/2;i++){
        swap(resultado[i],resultado[n-i-1]);
    }
    return resultado;
}

template <typename T>
void swap(T& a, T& b){
    T aux {a};
    a = b;
    b = aux;
}
