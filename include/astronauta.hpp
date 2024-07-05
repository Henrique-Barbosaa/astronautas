#include <string>
#include "lista.hpp"

class Astronauta
{
private:
   int idade;
   std::string nome;
   std::string cpf;
   bool disponivel;
   bool vivo;
public:
   Astronauta(std::string nome, std::string cpf, int idade);

   static Astronauta* criarAstronauta();

   const std::string& obterCPF();

   const std::string& obterNome();

   const int& obterIdade();

   bool estaDisponivel();

   bool estaVivo();

   void setDisponivel(bool booleano);

   void setVivo(bool booleano);
};