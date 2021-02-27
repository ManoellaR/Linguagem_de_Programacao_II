#include "person.hpp"

int main(){

    vector < personPF > listPF;
    vector < personPJ > listPJ;

    if(LoadDatabase("database.dat", listPF, listPJ) == false){
        if(NDEBUG) cout << "Database file not found. Creating a new one" << endl;
    }

    for(; ;){
        SaveDatabase("database.dat", listPF, listPJ);

        if(NDEBUG) cout << "MY PAPA'S COMPANY - SIG" << endl;
        if(NDEBUG) cout << "Select an option:" << endl;
        if(NDEBUG) cout << "1. Add PF..." << endl;
        if(NDEBUG) cout << "2. Add PJ..." << endl;
        if(NDEBUG) cout << "3. Remove PF Index..." << endl;
        if(NDEBUG) cout << "4. Remove PJ Index..." << endl;
        if(NDEBUG) cout << "5. Print Names in Ascending Order" << endl;
        if(NDEBUG) cout << "6. Exit" << endl;

        if(NDEBUG) cout << "Enter an option: ";
        char ch;
        cin >> ch;

        cin.ignore();

        if(ch == '1'){
            personPF f;
            if(NDEBUG) cout << "Digite todos os dados da pessoa (nome, nomeMae, cpf, endereco, telefone): " << endl;
            getline(cin, f.nome);
            getline(cin, f.nomeMae);
            getline(cin, f.cpf);
            getline(cin, f.endereco);
            getline(cin, f.telefone);

            listPF.push_back(f);

            continue;
        }
        if(ch == '2'){
            personPJ j;
            if(NDEBUG) cout << "Digite todos os dados da pessoa (razaoSocial, cnpj, endereco, telefone, capitalSocial): " << endl;
            getline(cin, j.razaoSocial);
            getline(cin, j.cnpj);
            getline(cin, j.endereco);
            getline(cin, j.telefone);
            cin >> j.capitalSocial;

            listPJ.push_back(j);

            continue;
        }
        if(ch == '3'){
            size_t index;
            if(NDEBUG) cout << "Digite o indice da pessoa física a ser removida" << endl;
            cin >> index;
            if(!RemovePF(index, listPF)){
                if(NDEBUG) cout << "Indice inválido" << endl;
            }
            
            continue;
        }
        if(ch == '4'){
            size_t index;
            if(NDEBUG) cout << "Digite o indice da pessoa jurídica a ser removida" << endl;
            cin >> index;
            if(!RemovePJ(index, listPJ)){
                if(NDEBUG) cout << "Indice inválido" << endl;
            }
            
            continue;
        }
        if(ch == '5'){
            cout << "Names in Ascending Order: " << endl;
            vector < string > nameList;
            SortNames(nameList, listPF, listPJ);

            for(size_t i=0; i < nameList.size(); i++){
                cout << nameList.at(i) << endl;
            }

            continue;
        }
        if(ch == '6'){
            break;
        }
    }

    return 0;
}