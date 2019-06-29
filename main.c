#include "dati.h"



int main(){

  int scelta;
  lista* archivio;
  int ris;
  char piva[10];
  char ragionesocia[10];
  char cognome[15];
  char nome[15];
  char telefono[10];
  char email[30];
  char categoria;
  int acquisti;


  printf("1) Inizializza archivio\n");
  printf("2) Salvataggio dati dell'archivio\n");
  printf("3) Visualizza tutte le aziende\n");
  printf("4) Visualizza tutte le aziende della categoria A\n");
  printf("5) Inserisci un'azienda\n");
  printf("6) Conta tutte le aziende della categoira B con acquisti anno >100000\n");
  printf("7) Visualizza tutte le aziende(o una sola azienda)con acquisti anno minimo\n");
  printf("8) Ordina tutte le aziende\n");
  printf("0) Uscita dal programma\n");
  do{

  scanf("%d",&scelta);

  switch(scelta){
    case 1:
    archivio=inizializza();
    break;
    case 2:
    salvataggio(archivio);
    break;
    case 3:
    visualizza1(archivio);
    break;
    case 4:
    visualizza2(archivio);
    break;
    case 5:
    inserisci(archivio,piva,ragionesocia,cognome,nome,telefono,email,categoria,acquisti);
    break;
    case 6:
    ris=determina(archivio);
    printf("le aziende sono %d",ris);
    break;
    case 7:
    visualizza3(archivio);
    break;
    case 8:
    //ordina(archivio);
    printf("funzione non disponibile");
    break;
    default:
    printf("errore");
  }
}while(scelta>0);
return 0;
}
