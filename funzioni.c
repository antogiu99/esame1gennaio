#include "dati.h"



lista* inizializza(){
  char piva[10],ragionesocia[10],cognome[15],nome[15],email[30],categoria,telefono[10],c;
  int acquisti;
  FILE* archivio;
  archivio=fopen("archivio.txt","r");

  lista* nodo;
  nodo=malloc(sizeof(lista));
  nodo->next=NULL;
  nodo->prev=NULL;
  int i;
  //c=getc(archivio);
  if(archivio==NULL){
    printf("non è stato possibile aprire il file");
    exit(1);
  }

  while(!feof(archivio))
  {



    if(!feof(archivio)){
      printf("entra nell'if\n");
      fscanf(archivio,"%s\n%s\n%s\n%s\n%s\n%s\n%c\n%d\n\n",piva,ragionesocia,cognome,nome,telefono,email,&categoria,&acquisti);
      nodo=push(nodo,piva,ragionesocia,cognome,nome,telefono,email,categoria,acquisti);
      i++;
    }

    if(i==5){
      printf("fine");
      break;
    }
  }
  fclose(archivio);

  return nodo;

}





lista* push(lista* node,char piva[],char ragionesocia[],char cognome[],char nome[],char telefono[],char email[],char categoria,int acquisti)
{
  lista* newnode;
  newnode=malloc(sizeof(lista));

  strcpy(newnode->piva,piva);
  strcpy(newnode->ragionesocia,ragionesocia);
  strcpy(newnode->cognome,cognome);
  strcpy(newnode->nome,nome);
  strcpy(newnode->telefono,telefono);
  strcpy(newnode->email,email);
  newnode->categoria=categoria;
  newnode->acquisti=acquisti;
  newnode->next=NULL;
  newnode->prev=node;
  node->next=newnode;
  return newnode;
}







void salvataggio(lista* nodo){

  FILE* scrittura;

  scrittura=fopen("archivio.txt","a");

  fprintf(scrittura,"\n%s\n%s\n%s\n%s\n%s\n%s\n%c\n%d\n",nodo->piva,nodo->ragionesocia,nodo->cognome,nodo->nome,nodo->telefono,nodo->email,nodo->categoria,nodo->acquisti);

  fclose(scrittura);



}


void visualizza1(lista* nodo){
  while((nodo->prev)!=NULL){
    nodo=nodo->prev;
  }
  nodo=nodo->next;
  while(nodo!=NULL)
  {
  printf("%s\t,%s\t,%s\t,%s\n",nodo->ragionesocia,nodo->nome,nodo->cognome,nodo->telefono);
  nodo=nodo->next;
  }
}

void visualizza2(lista* nodo){
  while((nodo->prev)!=NULL){
    nodo=nodo->prev;
  }
  nodo=nodo->next;
  while(nodo!=NULL)
  {
    if ((nodo->categoria)=='A')
    {
      printf("%s\t,%s\t,%s\t,%s\n",nodo->ragionesocia,nodo->nome,nodo->cognome,nodo->telefono);
    }
  nodo=nodo->next;
  }


}



void inserisci(lista* nodo,char piva[],char ragionesocia[],char cognome[],char nome[],char telefono[],char email[],char categoria,int acquisti){
  lista* newnode;

  nodo=nodo->next;
  while(nodo!=NULL)
  {}
  newnode=malloc(sizeof(lista));

  strcpy(newnode->piva,piva);
  strcpy(newnode->ragionesocia,ragionesocia);
  strcpy(newnode->cognome,cognome);
  strcpy(newnode->nome,nome);
  strcpy(newnode->telefono,telefono);
  strcpy(newnode->email,email);
  newnode->categoria=categoria;
  newnode->acquisti=acquisti;
  newnode->next=NULL;
  newnode->prev=nodo;
  nodo->next=newnode;

}

int determina(lista* nodo){
  int somma=0;

  while((nodo->prev)!=NULL){
    nodo=nodo->prev;
  }
  nodo=nodo->next;
  while(nodo!=NULL)
  {
    if (((nodo->categoria)=='B')&&((nodo->acquisti)>100000))
    {
      somma=somma+1;
    }
  nodo=nodo->next;
  }



}


void visualizza3(lista* nodo){
  char ris[10];
  int min,conta=0;
  min=nodo->acquisti;
  while((nodo->prev)!=NULL){
    nodo=nodo->prev;
  }
  nodo=nodo->next;
  while(nodo!=NULL)
  {
    if ((nodo->next->acquisti)<min)
    {
      min=nodo->next->acquisti;
      strcpy(ris,nodo->next->ragionesocia);
    }
  nodo=nodo->next;
  }

printf("%s\n",ris);
}


/*void ordina(lista* nodo){
  lista ris[20],temp;
  int i=0,s=0,j;
  int min;




  while((nodo->prev)!=NULL){
    nodo=nodo->prev;
  }
  nodo=nodo->next;
  while(nodo!=NULL)
  {
    ris[i]=nodo;
    i=i+1;
    s=i;
  }

  for(i=0;i<s-1;i++)
  {
    min=i;
    for(j=i+1;j<s;j++)
    {
      if (strcmp(ris[j].ragionesocia,ris[min].ragionesocia))
      {
        min=j;

      }
    }

    temp=ris[min];
    ris[min]=lista[i];
    lista[i]=temp;
  }

  for(i=0;i<s-1;i++){
    printf("\n%d\n%s\n%s\n%s\n%s\n%s\n%c\n%d\n",ris[i].piva,ris[i].ragionesocia,ris[i].cognome,ris[i].nome,ris[i].telefono,ris[i].email,ris[i].categoria,ris[i].acquisti);

  }
}*/
