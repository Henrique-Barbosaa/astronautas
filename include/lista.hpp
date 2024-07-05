#include <vector>

template <typename T>
class Lista
{
private:
  std::vector<T> lista;
public:
  void adicionar(const T& item){
    this->lista.push_back(item);
  }

  size_t tamanho() const{
    return this->lista.size();
  }

  T buscaPorIndice(size_t i) const{
    return this->lista[i];
  }

  void remover(size_t indice){
    auto it = this->lista.begin() + indice;
    this->lista.erase(it);
  }

  void limpar(){
    for (size_t i = 0; i < this->lista.size(); i++){
      delete this->lista[i];
    }
    this->lista.clear();
  }
};
