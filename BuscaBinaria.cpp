#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>
#include <algorithm>

using namespace std;

#define MAX 20

// #define SORT_VECTOR 

// *****************************************************************************************
// ** Funcao que imprime as chaves contidas em um vetor de N elementos entre o intevalo [i..f]
// *****************************************************************************************
void imprimeVetorParcial(vector<int> v, int i, int f) {

int k = 0;

    while ( k < i) {
        cout << "-";
        k++;
        }
    while (k <= f) {
        cout << "*";
        k++;
        }
    while (k < v.size() ) {
        cout << "-";
        k++;
        }
    cout << endl;
}

// *****************************************************************************************
// ** Funcao que promove uma busca binaria em um vetor de N elementos ordenados crescente
// *****************************************************************************************
bool buscaBinaria(vector<int> v, int k) {

int i = 0,
    f = v.size()-1;

    while ( i <= f ) { 
        imprimeVetorParcial(v, i, f);
        int m = (i+f) /2;    
        if (k == v.at(m))              // n / 2^l  = 1 
          return true;                 // n = 2^l  => log2(n) = log2(2^l) = l. log2(2)
        if (k < v.at(m))               // l = log2(n) => O(log2(n))
          f = m - 1;                   // l = 10 ==> 2^10 = 1024 
        else                           // l = 11 ==> 2^11 = 2048 
          i = m + 1; 
        }             
    return false;
}

// ********************************************************************
// ********************************************************************
// ********************************************************************
int main() {

vector<int> v;

	cout << "tamanho do vetor = " << v.size() << endl;

    srand ( time(NULL) );

    for (unsigned int i=0; i < MAX; i++) {
        v.push_back(rand() % MAX*10);
        }

    sort(v.begin(), v.end());

    cout << "conteudo de v: " << endl << "---------------" << endl;
    
    imprimeVetorParcial(v, 0 , v.size()-1);
    
    int chave = v.at(rand() % (MAX));

//#ifdef SORT_VECTOR
    cout << "BuscaBinaria por " << chave << " : " << endl << "-------------------" << endl;    
    if (buscaBinaria(v, chave))
/* #else
    cout << "BuscaSeq por " << chave << " : " << endl << "-------------------" << endl;    
    if (buscaSeq(v, chave))
#endif
*/
       cout << "Encontrei a chave " << chave << endl;
    else
       cout << "Nao Encontrei a chave " << chave << endl;


    chave =  MAX * 100;

//#ifdef SORT_VECTOR
    cout << "BuscaBinaria por " << chave << " : " << endl << "-------------------" << endl;    
    if (buscaBinaria(v, chave))
/*
#else
    cout << "BuscaSeq por " << chave << " : " << endl << "-------------------" << endl;    
    if (buscaSeq(v, chave))
#endif
*/
               cout << "Encontrei a chave " << chave << endl;
    else
       cout << "Nao Encontrei a chave " << chave << endl;

    chave = -1;

//#ifdef SORT_VECTOR
    cout << "BuscaBinaria por " << chave << " : " << endl << "-------------------" << endl;    
    if (buscaBinaria(v, chave))
/*
#else
    cout << "BuscaSeq por " << chave << " : " << endl << "-------------------" << endl;    
    if (buscaSeq(v, chave))
#endif
*/
       cout << "Encontrei a chave " << chave << endl;
    else
       cout << "Nao Encontrei a chave " << chave << endl;
   
 	return 0;        
}