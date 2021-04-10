#include "EstruturaDados.hpp"

int main(){
    EstruturaDados Estrutura;
    Fila*  f = (Fila*)  &Estrutura;
    Pilha* p = (Pilha*) &Estrutura;
    char ch;
    int num;

    if(NDEBUG) cout << "NUMBER STORAGE SYSTEM:" << endl;
    if(NDEBUG) cout << "Insira uma opção" << endl;
    if(NDEBUG) cout << "1. Inserir um numero -> PILHA" << endl;
    if(NDEBUG) cout << "2. Inserir um numero -> FILA" << endl;
    if(NDEBUG) cout << "3. Remover um numero -> PILHA" << endl;
    if(NDEBUG) cout << "4. Remover um numero -> FILA" << endl;
    if(NDEBUG) cout << "5. Imprimir indice e valor numero" << endl;
    if(NDEBUG) cout << "6. Sair do Sistema" << endl;

    for(;;){
        cin >> ch;
        if(ch == '1'){
            if(NDEBUG) cout << "Digite o numero que deseja inserir" << endl;
            cin >> num;
            Estrutura.SetValor(num);
        }

        if(ch == '2'){
            if(NDEBUG) cout << "Digite o numero que deseja inserir" << endl;
            cin >> num;
            Estrutura.SetValor(num);
        }

        if(ch == '3'){
            if(Estrutura.GetSize() > 0){
                p->RemoveFrom();
            }
            else{
                if(NDEBUG) cout << "Não há elementos para remover" << endl;
            }
        }

        if(ch == '4'){
            if(Estrutura.GetSize() > 0){
                f->RemoveFrom();
            }
            else{
                if(NDEBUG) cout << "Não há elementos para remover" << endl;
            }
        }

        if(ch == '5'){
            if(Estrutura.GetSize() > 0){
                Estrutura.ShowEstrutura();
            }
            else{
                if(NDEBUG) cout << "Estrutura vazia" << endl;
            }
        }

        if(ch == '6'){
            break;
        }
    }
    return 0;
}