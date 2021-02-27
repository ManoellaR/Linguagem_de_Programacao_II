#include "person.hpp"

bool LoadDatabase(string path, vector < personPF > &listPF, vector < personPJ > &listPJ){
    ifstream fileReader(path);
    
    if(fileReader.is_open() == false){
        if(NDEBUG) cout << "Erro" << endl;
        return false;
    }

    string tmp;
    while(getline(fileReader, tmp)){
        if(tmp == "1"){
            personPF f;
            getline(fileReader, tmp);
            f.nome = tmp;
            getline(fileReader, tmp);
            f.nomeMae = tmp;
            getline(fileReader, tmp);
            f.cpf = tmp;
            getline(fileReader, tmp);
            f.endereco = tmp;
            getline(fileReader, tmp);
            f.telefone = tmp;

            listPF.push_back(f);
        }
        else{
            personPJ j;
            getline(fileReader, tmp);
            j.razaoSocial = tmp;
            getline(fileReader, tmp);
            j.cnpj = tmp;
            getline(fileReader, tmp);
            j.endereco = tmp;
            getline(fileReader, tmp);
            j.telefone = tmp;
            getline(fileReader, tmp);
            j.capitalSocial = atoi(tmp.c_str());

            listPJ.push_back(j);
        }
    }
    return true;
}

bool SaveDatabase(string path, const vector < personPF > &listPF, const vector < personPJ > &listPJ){
    ofstream fileWriter(path);

    if(!fileWriter.is_open()){
        if(NDEBUG) cout << "Erro" << endl;
    }

    for(personPF f : listPF){
        fileWriter << "1" << endl;
        fileWriter << f.nome << endl;
        fileWriter << f.nomeMae << endl;
        fileWriter << f.cpf << endl;
        fileWriter << f.endereco << endl;
        fileWriter << f.telefone << endl;
    }
            
    for(personPJ j : listPJ){
        fileWriter << "2" << endl;
        fileWriter << j.razaoSocial << endl;
        fileWriter << j.cnpj << endl;
        fileWriter << j.endereco << endl;
        fileWriter << j.telefone << endl;
        fileWriter << j.capitalSocial << endl;
    }

    fileWriter.close();
    return true;
}

bool mycomp(string a, string b){
	return a<b;
}

bool SortNames(vector <string > &nameList, const vector < personPF > &listPF, const vector < personPJ > &listPJ){

    for(size_t i=0; i<listPF.size(); i++){
        nameList.push_back(listPF.at(i).nome);
    }
    for(size_t i=0; i<listPJ.size(); i++){
        nameList.push_back(listPJ.at(i).razaoSocial);
    }

    sort(nameList.begin(), nameList.end(), mycomp);

    return true;
}

bool RemovePF(size_t index, vector < personPF > &listPF){
    if(index > (listPF.size() - 1) || listPF.size() == 0){
        return false;
    }

    listPF.erase(listPF.begin() + index);

    return true;
}

bool RemovePJ(size_t index, vector < personPJ > &listPJ){
    if(index > (listPJ.size() - 1) || listPJ.size() == 0){
        return false;
    }

    listPJ.erase(listPJ.begin() + index);

    return true;
}