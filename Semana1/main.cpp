#include "dictionary.hpp"

using namespace std;

int main(){
    cout << "entre o nome do arquivo para leitura: ";
    string path;
    cin >> path;
    cout << endl << "O arquivo a ser lido é: " << path << endl;

    if (LoadDictionary(path) == false){
        cout << "Erro arquivo não encontrado" << endl;
        return 1;
    }

    return 0;
}