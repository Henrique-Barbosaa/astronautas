#include "astronauta.hpp"

enum Estado{
   EM_PLAN,
   EM_CURSO,
   FINALIZADO
};

class Voo
{
private:
   int codigo;
   bool bemSucedido;
   Estado estado;
   Lista<Astronauta*> passageiros;

public:
   Voo(int codigo);

   int obterCodigo();

   Estado obterEstado();

   bool astronautaEstaPresente(std::string cpf);
   
   void addAstronauta(const Lista<Astronauta*>& astronautas);

   void removerAstronauta();

   void lancarVoo();

   void explodirVoo();

   void finalizarVoo();

   void listarPassageiros();

   static Voo* criarVoo();
};