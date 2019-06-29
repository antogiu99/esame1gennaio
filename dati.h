#include <stdio.h>
#include <stdlib.h>
#include<string.h>


struct lista{

  char piva[10];
  char ragionesocia[10];
  char cognome[15];
  char nome[15];
  char telefono[10];
  char email[30];
  char categoria;
  int acquisti;
  struct lista* next;
  struct lista* prev;
};

typedef struct lista lista;


lista* inizializza();
lista* push(lista* node,char piva[],char ragionesocia[],char cognome[],char nome[],char telefono[],char email[],char categoria,int acquisti);
void salvataggio(lista* nodo);
void visualizza1(lista* nodo);
void visualizza2(lista* nodo);
void inserisci(lista* nodo,char piva[],char ragionesocia[],char cognome[],char nome[],char telefono[],char email[],char categoria,int acquisti);
int determina(lista* nodo);
void visualizza3(lista* nodo);
void ordina(lista* nodo);
