#include <iostream>
#include <cstdlib>
#include "include/voo.hpp"

using namespace std;

void exibirMenu() {
    cout << "\nEscolha a funcionalidade que deseja usar:\n"<<endl;
    cout << "1 - Cadastrar Astronauta"<<endl;
    cout << "2 - Cadastrar Voo"<<endl;
    cout << "3 - Cadastrar Astronauta em Voo"<<endl;
    cout << "4 - Remover Astronauta de Voo"<<endl;
    cout << "5 - Lancar Voo"<<endl;
    cout << "6 - Explodir Voo"<<endl;
    cout << "7 - Finalizar Voo"<<endl;
    cout << "8 - Listar Todos os Voos"<<endl;
    cout << "9 - Listar Todos os Astronautas Mortos"<<endl;
    cout << "10 - Sair do Menu\n"<<endl;
}


void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    int abrirMenu = 0;
    int escolha,codigoDoVoo;
    bool existeVoo, existeAstronauta;
    Lista<Astronauta*> astronautas;
    Lista<Voo*> voos;

    do {
        cout << "\nDeseja abrir o menu?\n1 - Abrir Menu\n2 - Sair"<<endl;

        while(true){
            cin >> abrirMenu;
            if(abrirMenu == 1 || abrirMenu == 2){
                cin.ignore();
                break;
            }
            cin.clear();
            cin.ignore(1000,'\n');
            limparTela();
            cout << "Opcao invalida. Tente Novamente!"<<endl;
            cout << "\nDeseja abrir o menu?\n1 - Abrir Menu\n2 - Sair"<<endl;
        }
    
        if(abrirMenu == 1) {
            limparTela();
            exibirMenu();

            while(true){
                cin >> escolha;
                if(escolha >=1 && escolha <=10){
                    cin.ignore();
                    break;
                }
                cin.clear();
                cin.ignore(1000,'\n');
                limparTela();
                cout << "Opcao invalida. Tente Novamente!"<<endl;
                exibirMenu();
            }

            switch (escolha) {
                case 1: {
                    limparTela();
                    Astronauta* novoAstronauta = Astronauta::criarAstronauta();
                    if(novoAstronauta != nullptr){
                        astronautas.adicionar(novoAstronauta);
                        cout << "Astronauta cadastrado com sucesso!\n" << endl;
                        break;
                    }

                    cout << "Falha ao cadastrar novo astronauta no sistema!\n" << endl;
                    break;
                }
                case 2: {
                    limparTela();
                    Voo* novoVoo = Voo::criarVoo();
                    voos.adicionar(novoVoo);

                    cout << "Voo cadastrado com sucesso!\n" << endl;
                    break;
                }
                case 3: {
                    limparTela();
                    cout << "Qual o codigo do voo que deseja cadastrar um astronauta?\n";
                    cin >> codigoDoVoo;
                    cin.ignore();

                    existeVoo = false;
                    for(size_t i=0; i<voos.tamanho(); i++){
                        if(voos.buscaPorIndice(i)->obterCodigo() == codigoDoVoo){
                            voos.buscaPorIndice(i)->addAstronauta(astronautas);
                            existeVoo = true;
                        }
                    }

                    if(!existeVoo){
                        cout<<"\nNao existe um voo cadastrado com esse codigo!"<<endl;
                    }
                    break;
                }
                case 4: {
                    limparTela();
                    cout << "Qual o codigo do voo que deseja remover um astronauta?\n";
                    cin >> codigoDoVoo;
                    cin.ignore();

                    existeVoo = false;
                    for(size_t i=0; i<voos.tamanho(); i++){
                        if(voos.buscaPorIndice(i)->obterCodigo() == codigoDoVoo){
                            voos.buscaPorIndice(i)->removerAstronauta();
                            existeVoo = true;
                        }
                    }

                    if(!existeVoo){
                        cout<<"\nNao existe um voo cadastrado com esse codigo!"<<endl;
                    }
                    break;
                }
                case 5: {
                    limparTela();
                    cout << "Qual o codigo do voo que deseja lancar ao infinito?\n";
                    cin >> codigoDoVoo;
                    cin.ignore();

                    existeVoo = false;
                    for(size_t i=0; i<voos.tamanho(); i++){
                        if(voos.buscaPorIndice(i)->obterCodigo() == codigoDoVoo){
                            voos.buscaPorIndice(i)->lancarVoo();
                            existeVoo = true;
                        }
                    }

                    if(!existeVoo){
                        cout<<"\nNao existe um voo cadastrado com esse codigo!"<<endl;
                    }
                    break;
                }
                case 6: {
                    limparTela();
                    cout << "Qual o codigo do voo que deseja explodir?\n";
                    cin >> codigoDoVoo;
                    cin.ignore();

                    existeVoo = false;
                    for(size_t i=0; i<voos.tamanho(); i++){
                        if(voos.buscaPorIndice(i)->obterCodigo() == codigoDoVoo){
                            voos.buscaPorIndice(i)->explodirVoo();
                            existeVoo = true;
                        }
                    }    
                    if(!existeVoo){
                        cout<<"\nNao existe um voo cadastrado com esse codigo!"<<endl;
                    }
                    break;
                }
                case 7: {
                    limparTela();
                    cout << "Qual o codigo do voo que deseja finalizar?\n";
                    cin >> codigoDoVoo;
                    cin.ignore();

                    existeVoo = false;
                    for(size_t i=0; i<voos.tamanho(); i++){
                        if(voos.buscaPorIndice(i)->obterCodigo() == codigoDoVoo){
                            voos.buscaPorIndice(i)->finalizarVoo();
                            existeVoo = true;
                        }
                    }

                    if(!existeVoo){
                        cout<<"\nNao existe um voo cadastrado com esse codigo!"<<endl;
                    }
                    break;
                }
                case 8: {
                    limparTela();
                    existeVoo = false;
                    cout <<"\nVOOS EM PLANEJAMENTO:\n" << endl;
                    for(size_t i=0; i<voos.tamanho(); i++){
                        if(voos.buscaPorIndice(i)->obterEstado() == EM_PLAN){
                            existeVoo = true;
                            voos.buscaPorIndice(i)->listarPassageiros();
                        }
                    }
                    if(!existeVoo){
                        cout <<"\nNao existem voos em planejamento no momento!\n" << endl;
                    }
                
                    existeVoo = false;
                    cout <<"\nVOOS EM CURSO:\n" << endl;
                    for(size_t i=0; i<voos.tamanho(); i++){
                        if(voos.buscaPorIndice(i)->obterEstado() == EM_CURSO){
                            existeVoo = true;
                            voos.buscaPorIndice(i)->listarPassageiros();
                        }
                    }
                    if(!existeVoo){
                        cout <<"\nNao existem voos em curso no momento!\n" << endl;
                    }

                    existeVoo = false;
                    cout <<"\nVOOS FINALIZADOS:\n" << endl;
                    for(size_t i=0; i<voos.tamanho(); i++){
                        if(voos.buscaPorIndice(i)->obterEstado() == FINALIZADO){
                            existeVoo = true;
                            voos.buscaPorIndice(i)->listarPassageiros();
                        }
                    }
                    if(!existeVoo){
                        cout <<"\nNao existem voos finalizados no momento!\n" << endl;
                    }
                    break;
                }
                case 9: {
                    limparTela();
                    existeAstronauta = false;
                    for(size_t i=0; i<astronautas.tamanho(); i++){
                        if(astronautas.buscaPorIndice(i)->estaVivo() == false){
                            existeAstronauta = true;
                            cout<<"NOME: "<< astronautas.buscaPorIndice(i)->obterNome() <<endl;
                            cout<<"CPF: "<< astronautas.buscaPorIndice(i)->obterCPF() <<endl;
                            cout<<"VOOS PARTICIPADOS:\n"<<endl;

                            for(size_t j=0; j<voos.tamanho(); j++){
                                if(voos.buscaPorIndice(j)->obterEstado() == FINALIZADO){
                                    if(voos.buscaPorIndice(j)->astronautaEstaPresente(astronautas.buscaPorIndice(i)->obterCPF())){
                                        cout<<"- Voo "<< voos.buscaPorIndice(j)->obterCodigo() <<"\n"<<endl;
                                    }
                                }
                            }
                        }
                    }
                    if(!existeAstronauta){
                        cout<<"\nNenhum astronauta morreu durante um voo ate o momento!\n"<<endl;
                    }
                    break;
                }
                case 10: {
                    limparTela();
                    break;
                }
                default: {
                    break;
                }
            }
        }
    } while(abrirMenu == 1);

    astronautas.limpar();
    voos.limpar();
    return 0;
}