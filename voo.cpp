#include "include/voo.hpp"
#include <iostream>
#include <iomanip>

const int larguraNome = 20;
const int larguraCPF = 15;
const int larguraIdade = 8;

Voo::Voo(int codigo){
    this->codigo = codigo;
    this->estado = EM_PLAN;
}

int Voo::obterCodigo(){
    return this->codigo;
}

Estado Voo::obterEstado(){
    return this->estado;
}

void Voo::addAstronauta(const Lista<Astronauta*>& astronautas){
    if(this->estado != EM_PLAN){
        std::cout<<"Nao foi possivel adicionar o astronauta, pois o voo nao esta em fase de planejamento.\n"<<std::endl;
        return;
    }

    std::string cpf;
    std::cout<<"Qual o CPF do astronauta que deseja adicionar no Voo?"<<std::endl;
    std::getline(std::cin,cpf);

    for(size_t i=0;i < this->passageiros.tamanho(); i++){
        if(this->passageiros.buscaPorIndice(i)->obterCPF() == cpf){
            std::cout<<"\nO astronauta dono do CPF informado ja esta cadastrado no voo.\n"<<std::endl;
            return;
        }
    }

    for(size_t i=0;i < astronautas.tamanho(); i++){
        if(astronautas.buscaPorIndice(i)->obterCPF() == cpf){
            this->passageiros.adicionar(astronautas.buscaPorIndice(i));
            std::cout<<"Astronauta cadastrado com sucesso no voo de codigo " << this->codigo << std::endl;
            return;
        }
    }
    std::cout<<"Nao existe nenhum astronauta com o CPF informado.\n"<<std::endl;
}

void Voo::removerAstronauta(){
    if(this->estado != EM_PLAN){
        std::cout<<"O voo nao esta em fase planejamento, logo nao é possivel remover nenhum astronauta.\n"<<std::endl;
        return;
    }

    std::string cpf;
    std::cout<<"Qual o CPF do astronauta que deseja remover do Voo?"<<std::endl;
    std::getline(std::cin,cpf);

    for(size_t i=0; i<this->passageiros.tamanho(); i++){
        if(passageiros.buscaPorIndice(i)->obterCPF() == cpf){
            this->passageiros.remover(i);
            std::cout<<"Astronauta removido com sucesso no voo de codigo " << this->codigo << std::endl;
            return;
        }
    }
    std::cout<<"\nO astronauta dono desse cpf nao esta cadastrado nesse voo.\n"<<std::endl;
}

void Voo::lancarVoo(){
    if(this->estado != EM_PLAN){
        std::cout<<"\nO voo nao pode ser lancado, pois nao esta em fase de planejamento.\n"<<std::endl;
        return;
    }
    if(this->passageiros.tamanho() < 1){
        std::cout<<"\nO voo nao pode ser lancado, pois nao tem astronautas cadastrados nele\n"<<std::endl;
        return;
    }

    for(size_t i=0; i<this->passageiros.tamanho(); i++){
        if(passageiros.buscaPorIndice(i)->estaDisponivel() == false){
            std::cout<<"\nLancamento cancelado. Existem passageiros que nao estao disponiveis para o voo neste momento.\n"<<std::endl;
            return;
        }
    }

    this->estado = EM_CURSO;
    for(size_t i=0; i<this->passageiros.tamanho(); i++){
        passageiros.buscaPorIndice(i)->setDisponivel(false);
    }

    std::cout<<"Lancamento feito com sucesso. Voo em curso!\n"<<std::endl;
}

Voo* Voo::criarVoo(){
    int codigo;

    std::cout<<"Qual o codigo do Voo?"<<std::endl;
    std::cin >> codigo;

    return new Voo(codigo);
}

void Voo::explodirVoo(){
    if(this->estado != EM_CURSO){
        std::cout<<"O voo nao pode ser explodido, pois nao esta em curso.\n"<<std::endl;
        return;
    }

    for(size_t i=0; i<this->passageiros.tamanho(); i++){
        this->passageiros.buscaPorIndice(i)->setVivo(false);
    }

    this->estado = FINALIZADO;
    this->bemSucedido = false;
    std::cout<<"\nExplosao concluida com sucesso. Descansem em paz! #RIP\n"<<std::endl;
}

void Voo::finalizarVoo(){
    if(this->estado != EM_CURSO){
        std::cout<<"O voo nao pode ser finalizado, pois nao esta em curso.\n"<<std::endl;
        return;
    }

    for(size_t i=0; i<this->passageiros.tamanho(); i++){
        this->passageiros.buscaPorIndice(i)->setDisponivel(true);
    }

    this->estado = FINALIZADO;
    this->bemSucedido = true;
    std::cout<<"\nVoo de codigo "<< this->codigo<< " finalizado com sucesso. Os astronautas estao de volta!\n"<<std::endl;
}

void Voo::listarPassageiros(){
    std::cout<<"\nVoo "<< this->codigo << ":\n"<<std::endl;
    if(this->passageiros.tamanho() < 1){
        std::cout<<"Este voo nao possui passageiros cadastrados!\n"<<std::endl;
        return;
    }

    std::cout<<std::left<<std::setw(larguraNome)<< "Nome" << "|"
             <<std::left<<std::setw(larguraCPF)<< "CPF" << "|"
             <<std::left<<std::setw(larguraIdade)<< "Idade" << "|" <<std::endl;

    std::cout<<std::string(larguraNome, '-') << "+"
             <<std::string(larguraCPF, '-') << "+"
             <<std::string(larguraIdade, '-') << "+"
             <<std::endl;


    for(size_t i=0; i<this->passageiros.tamanho(); i++){
        Astronauta* astronauta = passageiros.buscaPorIndice(i);
        std::string nomeFormatado;

        if(astronauta->obterNome().size() > larguraNome){
            nomeFormatado = astronauta->obterNome().substr(0,larguraNome - 4);
            nomeFormatado += "... ";
        } else {
            nomeFormatado = astronauta->obterNome();
            nomeFormatado += std::string(larguraNome - astronauta->obterNome().size(),' ');
        }

        std::cout<<std::setw(larguraNome)<< nomeFormatado<< "|"
                 <<std::setw(larguraCPF)<< astronauta->obterCPF()<< "|"
                 <<std::setw(larguraIdade)<<astronauta->obterIdade()<< "|" << std::endl;
    }

    if(this->estado == FINALIZADO){
        if(this->bemSucedido == true){
            std::cout<<"\nFinalizado COM SUCESSO!\n"<<std::endl;
            return;
        }
        std::cout<<"\nFinalizado SEM SUCESSO\n"<<std::endl;
    }
}

bool Voo::astronautaEstaPresente(std::string cpf){
    for(size_t i=0; i<this->passageiros.tamanho(); i++){
        if(passageiros.buscaPorIndice(i)->obterCPF() == cpf){
            return true;
        }
    }
    return false;
}