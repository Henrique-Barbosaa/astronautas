#include "include/astronauta.hpp"
#include <iostream>

Astronauta::Astronauta(std::string nome, std::string cpf, int idade){
    this->nome = nome;
    this->cpf = cpf;
    this->idade = idade;
    this->disponivel = true;
    this->vivo = true;
}

const std::string& Astronauta::obterCPF(){
    return this->cpf;
}

const std::string& Astronauta::obterNome(){
    return this->nome;
}

const int& Astronauta::obterIdade(){
    return this->idade;
}

void Astronauta::setDisponivel(bool booleano){
    this->disponivel = booleano;
}

void Astronauta::setVivo(bool booleano){
    this->vivo = booleano;
}

bool Astronauta::estaDisponivel(){
    return this->disponivel;
}

bool Astronauta::estaVivo(){
    return this->vivo;
}

Astronauta* Astronauta::criarAstronauta(){
    int idade;
    std::string nome;
    std::string cpf;

    std::cout<<"Qual o nome do Astronauta?\n";
    std::getline(std::cin,nome);

    std::cout<<"Qual o CPF do Astronauta?\n";
    std::getline(std::cin,cpf);

    std::cout<<"Qual a idade do Astronauta?\n";
    std::cin >> idade;
    std::cin.ignore();

    if(idade <= 0){
        std::cout<<"\nIdade Invalida!\n"<<std::endl;
        return nullptr;
    }

    return new Astronauta(nome,cpf,idade);
}