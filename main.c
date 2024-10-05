#include <stdio.h>
#include <string.h>

char nom[20][20];
char prenom[20][20];
char telephon[20][14];
int age[20];
char statut[20][20];
int reference[20];
char date_de_reservation[20][15];
int x,i;
int f=0;
int ref[20];
int sup[20];

 void ajouter()
{
    printf("ajouter donne de reservation %d:\n",x+1);
    printf(" nom  :\t");
    scanf("%s",nom[x]);
    printf("prenom :\t");
    scanf("%s",prenom[x]);
    printf("telephon :\t");
    scanf("%s",telephon[x]);
    printf("age:\t");
    scanf("%d",&age[x]);
    printf("Statut (valide, reporte, annule, traite):\t");
    scanf("%s",statut[x]);
    printf("refrence :%d\n",x+1);
    printf("date de reservation 'xx-xx-xxxx':\t");
    scanf("%s",date_de_reservation[x]);
    x++;




}
void afficher(){
   for(i=0;i<x;i++){
        printf("#################\n");
    printf("%s\n",nom[i]);
    printf("%s\n",prenom[i]);
    printf("%s\n",telephon[i]);
    printf("%d\n",age[i]);
    printf("%s\n",statut[i]);
    printf("%s\n",date_de_reservation[i]);

   }
}
void modifier(){
    printf("entre la reference de reservation vous souhaitez modifier");
    scanf("%s",&ref);
    for(i=0;i<x;i++){
          if(reference[i]=ref){
                printf("nouveau nom: ");
            scanf("%s", nom[i]);
            printf("nouveau prenom: ");
            scanf("%s", prenom[i]);
            printf("nouveau telephon: ");
            scanf("%s",telephon[i]);
            printf("nouvel age: ");
            scanf("%s",&age[i]);
            printf("nouveau statut: ");
            scanf("%s", statut[i]);

            printf("nouvelle date: ");
            scanf("%s",date_de_reservation[i]);

          printf("les informations a ete mise a jour");
          f=1;
          break;
    }
    }
    if (!f) {
        printf("reservation non trouvee.\n");}


}
void supprimer(){

          printf("Entrer le ref de reservation que vous voulez supprimer:\n");
          scanf("%s", &sup);
          for(i = 0; i < x; i ++)
         {
             if(reference[i]=sup)
             {
                 strcpy(nom[i],nom[x-1]);
                 strcpy(prenom[i],prenom[x-1]);
                 strcpy(telephon[i],telephon[x-1]);
                 age[i]=age[x-1];
                 strcpy(statut[i],statut[x-1]);
                 strcpy(date_de_reservation[i],date_de_reservation[x-1]);


                 x--;
                f=1;
                printf("Le reservation est supprime\n");
                break;

}
}      if (!f) {
        printf("reservation non trouvee.\n");}
}
void recherche_refrence() {
    int reff;

    printf("entrez la reference : ");
    scanf("%d", &reff);

    for (int i = 0; i < x; i++) {
        if (reference[i]=reff) {
            printf("\n---------------------------------------------\n");
            printf("reference: %d\n", reference[i]);
            printf("nom: %s\n", nom[i]);
            printf("prenom: %s\n", prenom[i]);
            printf("telephone: %s\n", telephon[i]);
            printf("age: %d\n", age[i]);
            printf("statut: %s\n", statut[i]);
            printf("date: %s\n", date_de_reservation[i]);
            return;

        }
    }
    printf("reservatino non trouver");
    }
void recherche_nom() {
    char nomm[20];
    printf("entrez le nom : ");
    scanf("%s", &nomm);

    for (int i = 0; i < x; i++) {
        if (strcmp(nomm,nom[i])==0) {
            printf("\n---------------------------------------------\n");
            printf("reference: %d\n", reference[i]);
            printf("nom: %s\n", nom[i]);
            printf("prenom: %s\n", prenom[i]);
            printf("telephone: %s\n", telephon[i]);
            printf("age: %d\n", age[i]);
            printf("statut: %s\n", statut[i]);
            printf("date: %s\n", date_de_reservation[i]);
            return;
        }
    }
    printf("reservatino non trouver");
}
void recherche(){
       printf("1_recherche per ref\n");
       printf("2_recheche par nom\n");
       int choixderecherche;
       printf("entrer your choix");
       scanf("%d",&choixderecherche);
       switch(choixderecherche){
       case 1 :
           recherche_refrence();
           break;
       case 2 :
           recherche_nom();
           break;
       default :
        printf("choix failed");
        break;


       }
}
void calculerMoyenneAge() {
    int somme = 0;
    for (int i = 0; i < x; i++) {
        somme += age[i];
    }
    int moyenne = somme / x;
    printf("La moyenne d'âge des patients ayant réservé est de %d ans.\n", moyenne);
    return;
}
void afficherPatientsParTrancheAge() {
    int patients0_18 = 0;
    int patients19_35 = 0;
    int patients36Plus = 0;
    for (int i = 0; i < x; i++) {
        if (age[i] <= 18) {
            patients0_18++;
        } else if (age[i] <= 35) {
            patients19_35++;
        } else {
            patients36Plus++;
        }
    }
    printf("Nombre de patients par tranche d'âge :\n");
    printf("  0-18 ans : %d patients\n", patients0_18);
    printf("  19-35 ans : %d patients\n", patients19_35);
    printf("  36+ ans : %d patients\n", patients36Plus);
    return;
}
void statistique(){
    printf("1_calcluer moyenne d'age\n");
    printf("2_Afficher le nombre de patients par tranche d'âge\n");
    int choix_st;
     printf("entrer your choix");
     scanf("%d",&choix_st);
     switch(choix_st){
       case 1 :
           calculerMoyenneAge();
           break;
       case 2 :
           afficherPatientsParTrancheAge();
           break;
       default :
        printf("choix failed");
        break;
}
}

int main(){

    int choix;
    do{
    printf("menu\n");
    printf("1_ajouter\n");
    printf("2_afficher\n");
    printf("3_modifier\n");
    printf("4_supprimer\n");
    printf("5_recherche  \n");
    printf("6_statistique\n");
    printf("7_quitter\n");
    printf("choix");
    scanf("%d",&choix);

    switch(choix){
        case 1 :
             ajouter();
            break;
        case 2 :
             afficher();
            break;
        case 3 :
             modifier();
            break;
        case 4 :
            supprimer();
            break;
        case 5 :
            recherche();
            break;
        case 6:
            statistique();
            break;
        case 7 :
            printf(" au revoir");
            break;
}

}
    while(choix!=7);
    return 0;
}
