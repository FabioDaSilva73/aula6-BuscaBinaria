#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>
#include <algorithm>

using namespace std;

#define MAX 20

#define SORT_VECTOR 0

// *****************************************************************************************
// ** Funcao que imprime as chaves contidas em um vetor de N elementos entre o intevalo [i..f]
// *****************************************************************************************
void imprimeVetorParcial(vector<int> v, unsigned int i, unsigned int f) {

unsigned int k = 0;

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

// ********************************************************************
// ** Funcao que promove uma busca sequencial em um vetor de N elementos
// ********************************************************************
bool buscaSeq(vector<int> v, int k) {

    for (unsigned int i = 0 ; i < v.size() ; i++) {
        imprimeVetorParcial(v, i, v.size()-1); 
        if (v[i] == k)                                  // [1..N] => Melhor Caso: O(1)
            return true; 
        }                                               //        => Pior Caso  : O(n) 
                                                        //        => Caso Medio : O(n/2) = O(n)
    return false;
}

// *****************************************************************************************
// ** Funcao que promove uma busca sequencial em um vetor de N elementos ordenados crescente
// *****************************************************************************************
bool buscaSeqOrd(vector<int> v, int k) {

unsigned int i = 0; 

    while ( (i < v.size()) && (v[i] < k) ) {     // Melhor Caso: chave é o primeiro O(1) 
        imprimeVetorParcial(v, i, v.size()-1);
        i++;                                    //              k e menor que v[0] O(2)=O(1)    
        }
    if ( i == v.size() )                        // Pior Caso:   chave ser o ultimo O(2n-1)=O(n)
        return false;                           //              k e maior que v[n-1] O(2n)=O(n)

    if (v[i] == k)                              // Caso Medio: O(n/2) = O(n)
        return true;

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

#ifdef SORT_VECTOR
    sort(v.begin(), v.end());
#endif

    cout << "conteudo de v: " << endl << "---------------" << endl;
    
    imprimeVetorParcial(v, 0 , v.size()-1);
    
    int chave = v.at(rand() % (MAX));

#ifdef SORT_VECTOR
    cout << "BuscaSeqOrd por " << chave << " : " << endl << "-------------------" << endl;    
    if (buscaSeqOrd(v, chave))
#else
    cout << "BuscaSeq por " << chave << " : " << endl << "-------------------" << endl;    
    if (buscaSeq(v, chave))
#endif

       cout << "Encontrei a chave " << chave << endl;
    else
       cout << "Nao Encontrei a chave " << chave << endl;


    chave =  MAX * 100;

#ifdef SORT_VECTOR
    cout << "BuscaSeqOrd por " << chave << " : " << endl << "-------------------" << endl;    
    if (buscaSeqOrd(v, chave))
#else
    cout << "BuscaSeq por " << chave << " : " << endl << "-------------------" << endl;    
    if (buscaSeq(v, chave))
#endif
               cout << "Encontrei a chave " << chave << endl;
    else
       cout << "Nao Encontrei a chave " << chave << endl;

    chave = -1;

#ifdef SORT_VECTOR
    cout << "BuscaSeqOrd por " << chave << " : " << endl << "-------------------" << endl;    
    if (buscaSeqOrd(v, chave))
#else
    cout << "BuscaSeq por " << chave << " : " << endl << "-------------------" << endl;    
    if (buscaSeq(v, chave))
#endif
       cout << "Encontrei a chave " << chave << endl;
    else
       cout << "Nao Encontrei a chave " << chave << endl;
   
 	return 0;        
}