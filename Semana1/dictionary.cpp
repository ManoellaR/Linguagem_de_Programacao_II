#include "dictionary.hpp"

bool LoadDictionary(string path){
    ifstream filereader;
    filereader.open(path);

    if(filereader.is_open() == false)
        return false;

    string word;
    cout << path << " aberto." << endl << "Digite a palavra a ser buscada: ";
    cin >> word;
    cout << endl;

    string line;
    vector<string> match;
    int cont = 0;
    while(getline(filereader, line)){
        if (line.find(word, 0) < line.length()){
            match.push_back(line);
            cout << match[cont] << endl;
            cont++;
        }
    }

    if (cont == 0){
        cout << "Palavra não encontrada." << endl;
    }

    filereader.close();

    return true;
}