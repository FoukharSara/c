#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "arbre.h"


int menu () {
printf ("\n\n GESTION D'ARBRES \n\n");
printf ("\n\n ARBRES BINAIRES \n\n");
printf (" 0 - Fin du programme\n");
printf ("\n");
printf (" 1 - Création de l'arbre généalogique\n");
				//whaaaat
printf (" 2 - Création de l'arbre de l'expression arithmétique\n");
printf ("\n");
printf (" 3 - Parcours préfixé\n");
printf (" 4 - Parcours infixé\n");
printf (" 5 - Parcours postfixé\n");
printf (" 6 – Trouver Noeud \n");
printf (" 7 - Taille \n");
printf (" 8 - Hauteur \n");
printf (" 9 - Parcours en Largeur \n");
printf ("\n");
printf ("Votre choix ? ");
int cod; scanf ("%d", &cod); getchar();
printf ("\n");
return cod;
}

void main(){
	Arbre *A2;
	Arbre *A1;
	Noeud *racine = cNd((char*)"Samir",
	cNd((char*)"Kamal",
	cNd((char*)"Yassine",
	NULL,
	cNd((char*)"Hind",NULL,
	cf((char*)"Yasmine"))),
	cNd((char*)"Sarah",
	cf((char*)"Karim"),
	NULL)),
	NULL);
	Noeud* racine1 = cNd((char*)"-",cNd((char*)"*",cNd((char*)"+",cf((char*)"a"),cf((char*)"b")),cNd((char*)"-",cf((char*)"c"),cf((char*)"d"))),cf((char*)"e"));
	booleen fini = faux;
	while(!fini){
		switch(menu() ){
			case 0:
				fini = vrai;
				break;
			case 1: {
				Arbre* A1;
				A1= creerArbre(racine,afficher,NULL);
				break;
			}
			case 2:{
				Arbre* A2;
				A2= creerArbre(racine1,afficher,NULL);
				break;
			} 
			case 3:{
				printf("Arbre genealogique : ");
				prefixe(racine, afficher);
				printf("\nArbre Arithmetique : ");
				prefixe(racine1,afficher);
				break;
			}
			case 4:{
				printf("Arbre genealogique : ");
				infixe(racine, afficher);
				printf("\nArbre Arithmetique : ");
				infixe(racine1, afficher);
				break;
			}
			case 5:{
				printf("Arbre genealogique : ");
				postfixe(racine, afficher);
				printf("\nArbre Arithmetique : ");
				postfixe(racine1, afficher);
				break;
			}
			case 6 : {
				printf("Trouver Neoud dans Arbre genealogique \n\n");
				printf("Saisir le Noeud : ");
				char trouve[20];scanf("%S",trouve);
				if(trouverNoeud(racine,trouve,NULL)!=NULL){
					printf("Le Noeud %s existe.",trouverNoeud(racine,trouve,NULL)->reference);
				}else{
					printf("Le Noeud est introuvable. ");
				}
				printf("\nTrouver Noeud dans arithmetique\n\n");
				printf("Saisir le Noeud : ");
				char trouve1[20];scanf("%s",trouve1);
				
				if(trouverNoeud(racine1,trouve1,NULL)!=NULL){
					printf("Le Neoud %s existe",trouverNoeud(racine,trouve1,NULL)->reference);
				}
				else{
					printf("Le Noeud est introuvable.");
				}
				break;
			}
			case 7 :{
				printf("Taille Arbre genealique : ");
				printf("%d",taille(racine));
				printf("Taille Arbre arithmetique : ");
				printf("%d",taille(racine1));
				break;
			}
			case 8 : {
				printf("Hauteur Arbre genealique : ");
				printf("%d",hauteur(racine));
				printf("Hauteur Arbre arithmetique : ");
				printf("%d",hauteur(racine1));
				break;
			}
			case 9 : {
				printf("Arbre genealique : ");
				enLargeur(racine,afficher);
				printf("\nArbre arithmetique : ");
				enLargeur(racine1,afficher);
				break;
			}
		}
	}
}





