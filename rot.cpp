#include <iostream>
#include <string>

using namespace std;

string encrypt(const string& input, int rotation) {
    string result = "";

    for (char c : input) {
        if (isalpha(c)) { //so mudo letras, outros caracteres continuam iguais
            char base = isupper(c) ? 'A' : 'a'; //pra ser caps sensitive
            result += static_cast<char>((c - base + rotation) % 26 + base); //para n mudar de letra pra numero etc
        } else {
            result += c;
        }
    }

    return result;
}

int main() {
    int n;
    string input;

    cout << "Digite o numero de rotacao: ";
    cin >> n;

    cin.ignore();  //limpo o buffer de entrada

    cout << "Digite a frase para criptografar: ";
    getline(cin, input); //assim eu ignoro os espacos

    string encrypted = encrypt(input, n);

    cout << "Frase criptografada: " << encrypted << endl;

    return 0;
}
