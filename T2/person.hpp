#ifndef PERSON_HPP
#define PERSON_HPP

#define NDEBUG 0 // dev = 1 release = 0

#include <iostream>
#include <fstream> 
#include <vector>
#include <algorithm>

using namespace std;

struct personPF{
    string nome;
    string nomeMae;
    string cpf;
    string endereco;
    string telefone;
};

struct personPJ{
    string razaoSocial;
    string cnpj;
    string endereco;
    string telefone;
    size_t capitalSocial;
};

bool LoadDatabase(string path, vector < personPF > &listPF, vector < personPJ > &listPJ);
bool SaveDatabase(string path, const vector < personPF > &listPF, const vector < personPJ > &listPJ);
bool mycomp(string a, string b);
bool SortNames(vector <string > &nameList, const vector < personPF > &listPF, const vector < personPJ > &listPJ);
bool RemovePF(size_t index, vector < personPF > &listPF);
bool RemovePJ(size_t index, vector < personPJ > &listPJ);

#endif