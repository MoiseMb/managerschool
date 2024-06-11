#include <time.h>


void delay(int number_of_seconds)
{
    int milli_seconds = 5  * number_of_seconds;
  
    clock_t start_time = clock();
  
    while (clock() < start_time + milli_seconds)
        ;
}
int  controle(int choix ,int max){
     while (choix >max || choix <=0){
        printf("erreur le choix n'est pas valide \n saisir a nouveau\n");
        scanf("%d",&choix);
    }
    return choix;
}

void devant () {
    printf("|");
delay(1);
printf("+");
delay(1);
printf("+");
delay(1);
printf("+");
delay(1);
printf("+");
delay(1);
printf("+");
delay(1);
printf("+");
delay(1);
printf("+");
delay(1);
printf("+");
delay(1);
printf("+");
delay(1);
printf("+");
delay(1);
printf("+\t");
delay(1);

}

void derriere () {
delay(1);
printf("+");
delay(1);
printf("+");
delay(1);
printf("+");
delay(1);
printf("+");
delay(1);
printf("+");
delay(1);
printf("+");
delay(1);
printf("+");
delay(1);
printf("+");
delay(1);
printf("+");
delay(1);
printf("+");
delay(1);
printf("+");
delay(1);
printf("|\n");
delay(1);
}
void affichage_menu(){
printf("+---------------------------------------+\n");
printf("|");
printf("\tBIENVENUE Que Desirez Vous ?\t|\n");
printf("+---------------------------------------+\n");
printf("|");
printf("\t----> 1- Etudiants      \t|");
printf("\n");
printf("+---------------------------------------+\n");
printf("|");
printf("\t----> 2- Matieres      \t\t|");
printf("\n");
printf("+---------------------------------------+\n");
printf("|");
printf("\t----> 3- Classes      \t\t|");
printf("\n");
printf("+---------------------------------------+\n");
printf("|");
printf("\t----> 4- Notes      \t\t|");
printf("\n");
printf("+---------------------------------------+\n");
printf("|");
printf("\t----> 5- Quitter     \t\t|\n");
printf("+---------------------------------------+\n");

}
void affichage_menu2(){
printf("+---------------------------------------+\n");
printf("|");
printf("  \tGESTION DES MATIERES\t\t|\n");
printf("+---------------------------------------+\n");
printf("|");
printf("---->  1- Ajouter Une Matiere  \t|\n");
printf("+---------------------------------------+\n");
printf("|");
printf("----> 2 -Modifier Une Matiere \t\t|\n");
printf("+---------------------------------------+\n");
printf("|");
printf("----> 3 -Rechercher Une Matiere \t|\n");
printf("+---------------------------------------+\n");
printf("|");
printf("----> 4 -Suprimmer Une Matiere \t|\n");
printf("+---------------------------------------+\n");
printf("|");
printf("----> 5 -Liste Matieres \t\t|\n");
printf("+---------------------------------------+\n");
printf("|");
printf("----> 6- Associer Matiere  \t\t|\n");
printf("+---------------------------------------+\n");
printf("|");
printf("----> 7 -Desassocier Matiere \t\t|\n");
printf("+---------------------------------------+\n");
printf("|");
printf("----> 8- Menu Principale \t\t|\n");
printf("+---------------------------------------+\n");
}
void affichage_menu1(){
printf("+---------------------------------------+\n");
printf("|");
printf("  \tGESTION DES ETUDIANTS\t\t|\n");
printf("+---------------------------------------+\n");
printf("|");
printf("---->  1- Ajouter Un Etudiant  \t|\n");
printf("+---------------------------------------+\n");
printf("|");
printf("----> 2 -Modifier Un Etudiant \t\t|\n");
printf("+---------------------------------------+\n");
printf("|");
printf("----> 3 -Rechercher Un Etudiant \t|\n");
printf("+---------------------------------------+\n");
printf("|");
printf("----> 4 -Suprimmer Un Etudiant \t|\n");
printf("+---------------------------------------+\n");
printf("|");
printf("----> 5 -Liste Etudiants \t\t|\n");
printf("+---------------------------------------+\n");
printf("|");
printf("----> 6- Menu Principale \t\t|\n");
printf("+---------------------------------------+\n");
}
void affichage_menu3(){
   printf("+---------------------------------------+\n");
printf("|");
printf("  \tGESTION DES CLASSES\t\t|\n");
printf("+---------------------------------------+\n");
printf("|");
printf("---->  1- Ajouter Une Classe  \t\t|\n");
printf("+---------------------------------------+\n");
printf("|");
printf("----> 2 -Modifier Une Classe \t\t|\n");
printf("+---------------------------------------+\n");
printf("|");
printf("----> 3 -Rechercher Une Classe \t|\n");
printf("+---------------------------------------+\n");
printf("|");
printf("----> 4 -Suprimmer Une Classe \t\t|\n");
printf("+---------------------------------------+\n");
printf("|");
printf("----> 5 -Liste Classes \t\t|\n");
printf("+---------------------------------------+\n");
printf("|");
printf("----> 6- Menu Principale \t\t|\n");
printf("+---------------------------------------+\n");
}
void affichage_menu4(){
printf("+-------------------------------------------------------+\n");
printf("|                   GESTION DES NOTES                   |\n");
printf("+-------------------------------------------------------+\n");
printf("|                                                       |\n");
printf("|     +----------------------------------------+        |\n");
printf("|     |          PARTIE AJOUTER                |        |\n");
printf("|     +----------------------------------------+        |\n");
printf("|     |-->   1- Note Etu Dans Une Matiere      |        |\n");
printf("|     +----------------------------------------+        |\n");
printf("|     |-->   2-Note Etu Dans Tous Les Matieres |        |\n");
printf("|     +----------------------------------------+        |\n");
printf("|     |-->   3 -Note Classe Dans Une Matiere   |        |\n");
printf("|     +----------------------------------------+        |\n");
printf("|                                                       |\n");
printf("+-------------------------------------------------------+\n");
printf("|                                                       |\n");
printf("|              --> 4 -MODIFIER Une Note                 |\n");
printf("|                                                       |\n");
printf("+-------------------------------------------------------+\n");
printf("|                                                       |\n");
printf("|              --> 5 -SUPPRIMER Une Note                |\n");
printf("|                                                       |\n");
printf("+-------------------------------------------------------+\n");
printf("|                                                       |\n");
printf("|     +----------------------------------------+        |\n");
printf("|     |         PARTIE AFFICHAGE               |        |\n");
printf("|     +----------------------------------------+        |\n");
printf("|     |-->    6- Note une matiere              |        |\n");
printf("|     +----------------------------------------+        |\n");
printf("|     |-->    7- Note dans toute les Matieres  |        |\n");
printf("|     +----------------------------------------+        |\n");
printf("|                                                       |\n");
printf("+-------------------------------------------------------+\n");
printf("|                                                       |\n");
printf("|              --> 8- Menu Principale                   |\n");
printf("|                                                       |\n");
printf("+-------------------------------------------------------+\n");


}