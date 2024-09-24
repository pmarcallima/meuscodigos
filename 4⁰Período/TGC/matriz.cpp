

#include <iostream>

using namespace std;

class Celula {
public:
  Celula *inf;
  Celula *sup;
  Celula *esq;
  Celula *dir;
  int elemento;
  Celula(int elemento) {}
  Celula() {
    elemento = 0;
    inf = NULL;
    sup = NULL;
    esq = NULL;
    dir = NULL;
  }
};
class Matriz {
public:
  int linha;
  int coluna;
  Celula *inicio;
  Matriz() {
    linha = 0;
    coluna = 0;
    inicio = NULL;
  }

  void criarMatriz() {
    Celula *tmp = new Celula();
    inicio = tmp;
    Celula *l = inicio;
    for (int i = 1; i < coluna; i++) {
      tmp->dir = new Celula();
      tmp->dir->esq = tmp;
      tmp = tmp->dir;
    }
    for (int i = 1; i < linha; i++) {
      l->inf = new Celula();
      l->inf->sup = l;
      l = l->inf;
      tmp = l;
      for (int j = 1; j < coluna; j++) {
        tmp->dir = new Celula();
        tmp->dir->esq = tmp;
        tmp = tmp->dir;
        tmp->sup = tmp->esq->sup->dir;
        tmp->sup->inf = tmp;
      }
    }
  }
  bool inserir(int numero) {
    Celula *y;
    Celula *u;
    y = inicio;
    u = inicio;

    while (y != NULL && u != NULL) {
      while (u != NULL) {
        if (u->elemento == 0) {
          u->elemento = numero;
          return true;
        } else if (u->elemento == numero) {
          cout << "\nNumero ja existente na Matriz\n";
          return false;
        }

        u = u->dir;
      }
      y = y->inf;
      u = y;
    }
    return false;
  }
  void reorganizar(Celula *u, Celula *y) {

    while (u != NULL && y != NULL && u->elemento != 0) {
      while (u->dir != NULL && u->elemento != 0) {
        u->elemento = u->dir->elemento;
        u = u->dir;
        u->elemento = 0;
      }
      if (y->inf != NULL && y->elemento != 0) {
        u->elemento = y->inf->elemento;
      }

      y = y->inf;
      u = y;
    }
  }
  bool pesquisar(int numero) {
    Celula *y;
    Celula *u;
    y = u = inicio;

    for (int i = 0; i < linha; i++) {
      for (int j = 0; j < coluna; j++) {
        if (u->elemento == numero) {
          return true;
        }
        u = u->dir;
      }
      y = y->inf;
      u = y;
    }
    return false;
  }

  int remover(int numero) {
    Celula *y;
    Celula *u;
    y = u = inicio;

    for (int i = 0; i < linha; i++) {
      for (int j = 0; j < coluna; j++) {
        if (u->elemento == numero) {
          int tmp = u->elemento;
          reorganizar(u, y);
          return tmp;
        }
        u = u->dir;
      }
      y = y->inf;
      u = y;
    }
    return -1;
  }
  void mostrarMatriz() {
    Celula *y;
    Celula *u;
    u = y = inicio;

    cout << "\n";
    for (int i = 0; i < linha; i++) {
      cout << "|";
      for (int j = 0; j < coluna; j++) {
        cout << u->elemento << "|";
        u = u->dir;
      }
      cout << "\n";
      y = y->inf;
      u = y;
    }
  }
};
int main() {

  int num;
  int escolha;
  Matriz *m = new Matriz();
  bool loop = true;
  cout << "--------------------Bem vindo---------------------\n";
  cout << "\nDigite o numero de linhas da nova matriz\n";
  cin >> m->linha;
  cout << "\nDigite o numero de  colunas da nova matriz\n";
  cin >> m->coluna;
  m->criarMatriz();
  cout << "\nCriada matriz " << m->linha << "x" << m->coluna
       << " com sucesso!!\n";
  while (loop) {
    cout << "\n                Escolha uma opcao\n\n";
    cout << "1- Criar uma matriz nova\n2- Inserir elemento\n3- Remover "
            "elemento\n4- Pesquisar elemento\n5- Ver a matriz\n6- Sair\n";
    cin >> escolha;
    switch (escolha) {
    default:

      break;
    case 1:
      cout << "\nDigite o numero de linhas da nova matriz\n";
      cin >> m->linha;
      cout << "\nDigite o numero de  colunas da nova matriz\n";
      cin >> m->coluna;
      m->criarMatriz();
      cout << "\nCriada matriz " << m->linha << "x" << m->coluna
           << " com sucesso!!\n";
      break;
    case 2:
      cout << "\nDigite o numero a ser inserido\n";
      cin >> num;
      if (m->inserir(num) == true)
        cout <<"\n"<< num << " Inserido com sucesso!!\n";
      break;
    case 3:
      cout << "\nDigite o numero a ser removido\n";
      cin >> num;
      num = m->remover(num);
      if (num == -1)
        cout << "\nNumero nao encontrado\n";
      else
        cout << "\nO numero " << num << " foi removido com sucesso!!\n";
      break;
    case 4:
      cout << "\nDigite o numero a ser pesquisado\n";
      cin >> num;
      if (m->pesquisar(num) == true)
        cout << "\nO numero " << num << " foi encontrado com sucesso!!\n";
      else
        cout << "\nO numero " << num << " não foi encontrado\n";
      break;
    case 5:
      m->mostrarMatriz();
      break;
    case 6:
      loop = false;
      break;
    }
  }
  delete (m);
}
