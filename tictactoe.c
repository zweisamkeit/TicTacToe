/* Titre : Tic Tac Toe -- Version 1 (console)
 * Auteur : Zweisamkeit
 * Création : 6 mai 2016
 * Dernière modification : 6 mai 2016 
 * Licence : GNU GPL
 * Contact : contact@zweisamkeit.fr */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "tictactoe.h"

#define taille_plateau 3
#define taille_pseudo 128

void clear(void){
  system("clear");}

void accueil(char pseudo1[taille_pseudo], char pseudo2[taille_pseudo], char *symbole1, char *symbole2){
  char alphanum[62]={'a','z','e','r','t','y','u','i','o','p','q','s','d','f','g','h','j','k','l','m','w','x','c','v','b','n','A','Z','E','R','T','Y','U','I','O','P','Q','S','D','F','G','H','J','K','L','M','W','X','C','V','B','N','0','1','2','3','4','5','6','7','8','9'};
  printf("\n\n\t\t\t%s\n","~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
  printf("\n\t\t\t %s\n","Tic Tac Toe -- Zweisamkeit -- Licence GNU GPL");
  printf("\n\t\t\t%s\n\n","~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
  printf("\n\t%s","Entrez le pseudo du joueur 1, ainsi que le symbole qu'il utilisera [pseudo symbole] : ");
  scanf("%s %c",pseudo1, symbole1);
  vide_buffer();
  if (strchr(alphanum,*symbole1)==NULL){ 
    printf("\n\t\t%s","Erreur : Symbole invalide, choisissez un caractère alpha-numérique");
    main();}
  printf("\n\t%s","Entrez le pseudo du joueur 2, ainsi que le symbole qu'il utilisera [pseudo symbole] : ");
  scanf("%s %c",pseudo2,symbole2);
  vide_buffer();
  if (strchr(alphanum,*symbole2)==NULL){
    printf("\n\t\t%s","Erreur : Symbole invalide, choisissez un caractère alpha-numérique");
    main();}
  if (strcmp(pseudo1,pseudo2)==0){
    printf("\n\t\t%s","Erreur : Pseudos identiques");
    main();}
  if (symbole1==symbole2){
    printf("\n\t\t%s","Erreur : Symboles identiques");
    main();}}

void initialisation(char plateau[taille_plateau][taille_plateau]){
  int i,j;
  for (i=0;i<taille_plateau;i++){
    for (j=0;j<taille_plateau;j++){
      plateau[i][j]='.';}}}

void jouer(char plateau[taille_plateau][taille_plateau], int num, char pseudo1[taille_pseudo], char pseudo2[taille_pseudo], char symbole1, char symbole2){
  int i,j;
  if (num==1){
    printf("\t\t\t%s %s",pseudo1,": Quelle case voulez-vous jouer ? [ligne,colonne] ");
    scanf("%i,%i",&i,&j); // Gérer le cas où l'entrée n'est pas de la bonne forme
    vide_buffer();
    if (i>2 || j>2 || i<0 || j<0){
      printf("\n\t\t\t\t%s\n\n","Erreur : Dépassement du plateau");
      jouer(plateau,num,pseudo1,pseudo2,symbole1,symbole2);}
    else if (plateau[i][j]==symbole1 || plateau[i][j]==symbole2) {
      printf("\n\t\t\t\t%s\n\n","Erreur : Case déjà jouée");
      jouer(plateau,num,pseudo1,pseudo2,symbole1,symbole2);}
    else 
      plateau[i][j]=symbole1;}
  else {
    printf("\t\t\t%s %s",pseudo2,": Quelle case voulez-vous jouer ? [ligne,colonne] ");
    scanf("%i,%i",&i,&j);
    vide_buffer();
    if (i>2 || j>2 || i<0 || j<0){
      printf("\n\t\t\t\t%s\n\n","Erreur : Dépassement du plateau");
      jouer(plateau,num,pseudo1,pseudo2,symbole1,symbole2);}
    else if (plateau[i][j]==symbole1 || plateau[i][j]==symbole2) {
      printf("\n\t\t\t\t%s\n\n","Erreur : Case déjà jouée");
      jouer(plateau,num,pseudo1,pseudo2,symbole1,symbole2);}
    else 
      plateau[i][j]=symbole2;}}

void afficher(char plateau[taille_plateau][taille_plateau]){
  clear();
  int i,j;
  printf("\n\n\t\t\t\t\t~~~~~~ Plateau ~~~~~~\n\n\n\n");
  printf("\t\t\t\t\t\t%s\n\n\n","0     1     2");
  for (i=0;i<taille_plateau;i++){
   printf("\t\t\t\t\t%i\t",i);
   for (j=0;j<taille_plateau;j++)
     printf("%c     ",plateau[i][j]);
   printf("\n\n\n");}
  printf("\n\n\t\t\t\t\t%s\n\n","~~~~~~~~~~~~~~~~~~~~~");}

int gagne(char plateau[taille_plateau][taille_plateau], char symbole1, char symbole2){
  int i,j;
  char symbole;
  for (i=0;i<taille_plateau;i++){
    if (plateau[i][0]==plateau[i][1] && plateau[i][1]==plateau[i][2]){
      if (plateau[i][0]==symbole1)
        return 1;
      else if (plateau[i][0]==symbole2)
        return 2;
      else
        return 0;}}
  for (j=0;j<taille_plateau;j++){
      if (plateau[0][j]==plateau[1][j] && plateau[1][j]==plateau[2][j]){
        if (plateau[0][j]==symbole1)
          return 1;
        else if (plateau[0][j]==symbole2)
          return 2;
        else
          return 0;}}
  if ((plateau[0][0]==plateau[1][1] && plateau[1][1]==plateau[2][2]) || (plateau[0][2]==plateau[1][1] && plateau[1][1]==plateau[2][0])){
    if (plateau[1][1]==symbole1)
      return 1;
    else if (plateau[1][1]==symbole2)
      return 2;
    else
      return 0;}
  return 0;}

/* Fonction permettant de vider le buffer de saisie après un scanf (évite les débordements de tampon) */

void vide_buffer(void){
  int c;
  while ((c = getchar ()) != '\n' && c != EOF);}

int main(void){
  clear();
  char plateau[taille_plateau][taille_plateau];
  initialisation(plateau);
  char pseudo1[taille_pseudo],pseudo2[taille_pseudo],symbole1,symbole2;
  accueil(pseudo1,pseudo2,&symbole1,&symbole2);
  afficher(plateau);
  int i=0,bool=0;
  while (i<=9 && !bool){
      jouer(plateau,1,pseudo1,pseudo2,symbole1,symbole2);
      afficher(plateau);
      i++;
      if (gagne(plateau,symbole1,symbole2)==1 || i==9){
        bool=1;
        break;}
      jouer(plateau,2,pseudo1,pseudo2,symbole1,symbole2);
      afficher(plateau);
      i++;
      if (gagne(plateau,symbole1,symbole2)==2 || i==9){
        bool=1;
        break;}}
  char decision;
  if (gagne(plateau,symbole1,symbole2)==0)
    printf("\t\t\t\t\t   %s\n\n","Partie nulle...");
  else if (gagne(plateau,symbole1,symbole2)==1)
    printf("\t\t\t\t\t   %s %s\n\n",pseudo1,"a gagné !");
  else if (gagne(plateau,symbole1,symbole2)==2)
    printf("\t\t\t\t\t   %s %s\n\n",pseudo2,"a gagné !");
  return 0;}
