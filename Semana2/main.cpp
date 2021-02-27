#include "dictionary.hpp"

int main()
{  
    cout << "Entre com um nome de arquivo para leitura : ";
    
    string path;
    cin >> path;    
    cout << endl << "O arquivo a ser lido é: " << path << endl;
    
    vector< string > wordlist;
    if(LoadDictionary(path, wordlist) == false)
    {
        cout << "Erro, arquivo não encontrado" << endl;
        return 1;
    }
    
    /*for(size_t i=0; i<wordlist.size(); i++)
    {
        cout << wordlist.at(i) << endl;
    } */
    
    //localizar uma palavra na lista de palavras
    cout << "Digite uma palavra para buscar :";
    string query;
    cin >> query;
    cout << endl;
    
    if (SearchString(wordlist, query))
        cout << "achei"<< endl;
    else
        cout << "palavra não encontrada" << endl;


    cout << "Digite uma palavra para buscar todas as ocorrências :";
    cin >> query;
    vector <string> substrlist = SearchSubstrings(wordlist, query);
    for(size_t i=0; i>substrlist.size(); i++){
        cout << substrlist.at(i) << "->" << substrlist.at(i).length() << endl;
    }

    return 0;
}


