#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void welcome() {
    printf("\tGestion de contact!\n");
    printf("***");
    printf("\n0: exit\n1: ajouter \n2: afficher \n3:update \n4: delete \n5:Recherche \n");
}

typedef struct {
	char nom[30];
	char tele[20];
	char email[30];
}contact;

void ajoute(contact c[100],int n){
	int i;
		
	printf("enter votre nom :");
	scanf("%s",&c[n].nom);
		printf("enter numero de telephone :");
	scanf("%s",&c[n].tele);
		printf("enter votre email :");
	scanf("%s",&c[n].email);
	

}



int suprime(contact c[100],char nom[],int n){
	int i,j;
for(i=0;i<n-1;i++){
		if(strcmp(c[i].nom,nom)==0){
			for(j=i+1;j<n;j++){
			c[i]=c[j];
		
			}
			n--;
		   i--;
		}
		return n;
	}	
}
void affiche(contact c[100],int n){
		int i,j;
	for(i=0;i<n;i++){
		printf("votre nom est : %s \n",c[i].nom);
		printf("votre numero de telephone est : %s \n",c[i].tele);
		printf("votre email est  : %s \n",c[i].email);
		printf("--------------------------------------------------\n");
		
	}
	
}

void modifier(contact c[], char nom[], char tele[], char email[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(c[i].nom, nom) == 0) {
            strcpy(c[i].tele, tele);
            strcpy(c[i].email, email);
            return;
        }else printf("nom not found");
    }
}
/*
void recherche(contact c[100],char nom_cherche[],int n){
	int i ;
	for(i=0;i<n-1;i++){
		if(strcmp(c[i].nom,nom_cherche)==0){
			//erure fi affiche svp makadozche 
			affiche(c[i],n);
}
	}
}
*/
int main(){
    int choix;
    contact c[100];
	int n;
    welcome();
    while(1) {
        printf("Entee votre choix: ");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
               ajoute(c,n);
               n++;
                break;
            case 2:
                affiche(c,n);
                break;
            case 3:
               char nom[20];
            	char nv_tele[20];
	            char nv_email[20];
	               
            printf("enter le nom a modfiere:");
	        scanf("%s",&nom);
		
		    printf("enter numero nouve de tele :");
	        scanf("%s",&nv_tele);
		    printf("enter votre nouve email :");
	        scanf("%s",&nv_email);
            modifier(c,nom,nv_tele,nv_email,n);
                break;
            case 4:
			 	char delete_nom[20];
            	printf("entre le nom a suprime :");
	            scanf("%s",&delete_nom);
	            n=suprime(c,delete_nom,n);
                break;
            case 5:
                 char nom_cherche[20];
                 recherche(c,nom_cherche,n);
                break;
            
            case 0:
                printf("exit...");
                exit(0);
            default:
                printf("Default!");

    }
    }
    return (0);}
