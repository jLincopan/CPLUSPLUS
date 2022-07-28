#include <iostream>
#include <string>

using namespace std;

//Programa simple que implementa un cifrado por sustitución

int main() {
    string alphabet("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ");
    string      key("3529804616qazwsxedcrfvtgbyhnujmikolpQAZWSXEDCRFVTGBYHNUJMIKOLP-");

    string frase;
    string frase_cifrada;
    cout << "Ingrese una frase para codificar:\n" << endl; 
    getline(cin, frase);

    size_t posicion_letra = 0;
    for(size_t contador = 0; contador < size_t(frase.size()); contador++) {
            posicion_letra = alphabet.find(frase.at(contador));
            frase_cifrada.insert(contador, 1, key.at(posicion_letra));
    }

    cout << "\nFrase cifrada:\n" << endl;
    cout << frase_cifrada << endl;
    return 0;
}