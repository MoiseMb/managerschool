#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structure.h"
#include <unistd.h>






void valeur_saisir(char car[],Etudiant *etudiant1) { // Cette fonction sert a separer les differents champs pour une ligne

    
    char temp[6][20],j=0,k=0;
    
    
    for (int i = 0; i < strlen(car); i++)
    {
        if (car[i]==';')
        {
            temp[j][k]='\0';
            j++;k=0;
        }
         else{
            temp[j][k]=car[i];
            k++;
         }

      
    }
  
  etudiant1->numero=atoi(temp[0]);
  strcpy(etudiant1->nom,temp[1]);
  strcpy(etudiant1->prenom,temp[2]);
  strcpy(etudiant1->email,temp[3]);
  strcpy(etudiant1->date_naissance,temp[4]);
  etudiant1->code_classe=atoi(temp[5]);

}




int verfication_etudiant(int test){
    
    Etudiant etudiant1;
    char car[200];

    FILE *etu=fopen("etudiant.csv","r");
    if (etu==NULL)
    {
        printf("Erreur lors de l'ouverture\n");
    }else{

    

    while (!feof(etu)){

    fgets(car,200,etu);
    valeur_saisir(car,&etudiant1);
    if (test==etudiant1.numero){

    fclose(etu);
    return 1;

    }
    }

    fclose(etu);
    
}
    return 3;
}


//******************* Fonction Pour ajouter un etudiant *********************************

void  etudiantAjout(){
     FILE * E=fopen("etudiant.csv","a"); // on ouvre de le fichier etuidant en mode ecriture a la fin.

    if (E==NULL){
        printf("Erreur lors de  l'ouverture du fichier \n");  //Pour tester si l ouverture du fichier c'est bien passe.
        fclose(E);
        exit(1);
    }else{

    Etudiant etudiant1;
    do{
    printf("Veuillez saisir le numero de l'etudiant :");
    scanf("%d",&etudiant1.numero);
    if (verfication_etudiant(etudiant1.numero)==1 || etudiant1.numero <=0)
    {
       printf("Erreur le  numero saisi n'est pas disponible\n");
    }

    }while(verfication_etudiant(etudiant1.numero)==1 || etudiant1.numero <=0);


     do{
    printf("Veuillez saisir le code de la classe  de l'etudiant :");
    scanf("%d",&etudiant1.code_classe);

    if (verificcation_classe(etudiant1.code_classe)!=1)
    {
        printf("code classe inexistante\n saisir a nouveau\r"); 
    }

    }while(verificcation_classe(etudiant1.code_classe)!=1);
    

    
    getchar();
    printf("Veuillez saisir le nom de l'etudiant :");
    
    fgets(etudiant1.nom,20,stdin);
    enlever_retourligne(etudiant1.nom);
    printf("Veuillez saisir le prenom de l'etudiant :");
    
    fgets(etudiant1.prenom,20,stdin);
    enlever_retourligne(etudiant1.prenom);
    printf("Veuillez saisir le mail de l'etudiant :");
    
    fgets(etudiant1.email,30,stdin);
    enlever_retourligne(etudiant1.email);
    
    printf("Veuillez saisir la date de naissance de l'etudiant (JJ-MM-AA) :");
    
    fgets(etudiant1.date_naissance,20,stdin);
    enlever_retourligne(etudiant1.date_naissance);
   

    fprintf(E,"\n%d;%s;%s;%s;%s;%d",etudiant1.numero,etudiant1.nom,etudiant1.prenom,etudiant1.email,etudiant1.date_naissance,etudiant1.code_classe);
    
    printf("\nOperation terminer avec succes\n\n");

    fclose(E);
}
}


//*************** Fonction pour la modifier d un etudiant **************************


void modification_etudiant(){

 FILE *etu=fopen("etudiant.csv","r");
 FILE  *tmp=fopen("fichtemp.csv","w");


 Etudiant etudiant1,nouvelle_dt;

 char entete[55]="numero;nom;prenom;email;date_de_naissance;code_classe";

 int recherche,test,entier;

 char car[200];
 printf("Saisir le numero de l'etudiant a chercher :");
 scanf("%d",&recherche);

 while (!feof(etu)){


    fgets(car,200,etu);
    valeur_saisir(car,&etudiant1);

    if (recherche==etudiant1.numero){
    
        test=1;
        break;
    }
 }
 fclose(etu);
 if(test!=1){
    printf("\nErreur le numero saisi ne correspond a aucun etudiant\n\n");
    fclose(tmp);
    return;
 }else
 {
    printf("\n\t+--------------------------------------------+\n");
    printf("\t|             etudiant a modifier            |\n");
    printf("\t+--------------------------------------------+\n");
    printf("\t| nom               :  %-20s  |\n",etudiant1.nom);
    printf("\t+--------------------------------------------+\n");
    printf("\t| prenom            :  %-20s  | \n",etudiant1.prenom );
    printf("\t+--------------------------------------------+\n");
    printf("\t| email             :  %-20s  |\n",etudiant1.email );
    printf("\t+--------------------------------------------+\n");
    printf("\t| date de naissance :  %-20s  |\n",etudiant1.date_naissance );
    printf("\t+--------------------------------------------+\n");
    printf("\t| Code de classe    :  %-20d  |\n",etudiant1.code_classe );
    printf("\t+--------------------------------------------+\n");

 }
    getchar();
    printf("saisir le nouveau nom \n");
    fgets(nouvelle_dt.nom,20,stdin);
    enlever_retourligne(nouvelle_dt.nom);
    printf("saisir le nouveau prenom \n");
    fgets(nouvelle_dt.prenom,20,stdin);
    enlever_retourligne(nouvelle_dt.prenom);
    printf("saisir le nouveau email\n");
    fgets(nouvelle_dt.email,30,stdin);
    enlever_retourligne(nouvelle_dt.email);
    printf("saisir la date de naissance \n");
    fgets(nouvelle_dt.date_naissance,20,stdin);
    enlever_retourligne(nouvelle_dt.date_naissance);

    etu=fopen("etudiant.csv","r");
    fputs(entete,tmp);
    fgets(car,200,etu);
    
    while(!feof(etu)){

    fgets(car,200,etu);
    valeur_saisir(car,&etudiant1);

    if(etudiant1.numero==recherche){
        fprintf(tmp,"\n%d;%s;%s;%s;%s;%d",etudiant1.numero,nouvelle_dt.nom,nouvelle_dt.prenom,nouvelle_dt.email,nouvelle_dt.date_naissance,etudiant1.code_classe);
    }else{
        fprintf(tmp,"\n%d;%s;%s;%s;%s;%d",etudiant1.numero,etudiant1.nom,etudiant1.prenom,etudiant1.email,etudiant1.date_naissance,etudiant1.code_classe);
    }
 }
printf("modification reussie !\n\n");
 fclose(tmp);
 fclose(etu);
 remove("etudiant.csv");
 rename("fichtemp.csv","etudiant.csv");

} 


//*************************** fonction pour la recherche d un etudiant **********************


void recherche_etudiant(){
    int recherche,test=0;
    Etudiant etudiant1;
    char car[200];
    

    FILE *etu=fopen("etudiant.csv","r");

    printf("Saisir le numero de l'etudiant a chercher :");
    scanf("%d",&recherche);

    while (!feof(etu)){

    fgets(car,200,etu);
    valeur_saisir(car,&etudiant1);
 
    if (recherche==etudiant1.numero){
        test=1;
    
        break;
    }
   

}
 fclose(etu);
if(test!=1){
    printf("\nErreur le numero saisi ne correspond a aucun etudiant\n\n");
    return;
}else{
    printf("\n\t+--------------------------------------------+\n");
    printf("\t|             etudiant rechercher            |\n");
    printf("\t+--------------------------------------------+\n");
    printf("\t| nom               :  %-20s  |\n",etudiant1.nom);
    printf("\t+--------------------------------------------+\n");
    printf("\t| prenom            :  %-20s  | \n",etudiant1.prenom );
    printf("\t+--------------------------------------------+\n");
    printf("\t| email             :  %-20s  |\n",etudiant1.email );
    printf("\t+--------------------------------------------+\n");
    printf("\t| date de naissance :  %-20s  |\n",etudiant1.date_naissance );
    printf("\t+--------------------------------------------+\n");
    printf("\t| Code de classe    :  %-20d  |\n",etudiant1.code_classe );
    printf("\t+--------------------------------------------+\n");
    
}
}

// ***************** Fonction pour la supression dun etudiant ***********************


void supression_etudiant(){

     FILE *etu=fopen("etudiant.csv","r");
     FILE  *tmp=fopen("fichtemp.csv","w");

     char car[200];
    char entete[55]="numero;nom;prenom;email;date_de_naissance;code_classe";

     Etudiant etudiant1,nouvelle_dt;
     int recherche,test;

     printf("Saisir le numero de l'etudiant a suprimmer :");
     scanf("%d",&recherche);

     while (!feof(etu)){

    fgets(car,200,etu);
    valeur_saisir(car,&etudiant1);
    
        if (recherche==etudiant1.numero){
        
            test=1;
            break;
        }
     }
     fclose(etu);
     if(test==1){

        printf("\n\t+--------------------------------------------+\n");
    printf("\t|             etudiant a suprimmer           |\n");
    printf("\t+--------------------------------------------+\n");
    printf("\t| nom               :  %-20s  |\n",etudiant1.nom);
    printf("\t+--------------------------------------------+\n");
    printf("\t| prenom            :  %-20s  | \n",etudiant1.prenom );
    printf("\t+--------------------------------------------+\n");
    printf("\t| email             :  %-20s  |\n",etudiant1.email );
    printf("\t+--------------------------------------------+\n");
    printf("\t| date de naissance :  %-20s  |\n",etudiant1.date_naissance );
    printf("\t+--------------------------------------------+\n");
    printf("\t| Code de classe    :  %-20d  |\n",etudiant1.code_classe );
    printf("\t+--------------------------------------------+\n");
    
     }else
     {
       
        printf("\a\nErreur le numero saisi ne correspond a aucun etudiant\n\n");
        fclose(tmp);
        return;
     }
    char rep;
    printf("Voulez-vous  vraiment  suprimmer l'etudiant (y/n)\n");
    getchar();
    scanf("%c",&rep);
    if (rep=='n')
    {
        fclose(tmp);
        fclose(etu);

        printf("\nSupression Annuler\n\n");
        return;
    }
    etu=fopen("etudiant.csv","r");

    fputs(entete,tmp);
    fgets(car,200,etu);

    while(!feof(etu)){

    fgets(car,200,etu);
    valeur_saisir(car,&etudiant1);

    if(etudiant1.numero==recherche){
        continue;
    }else{
        fprintf(tmp,"\n%d;%s;%s;%s;%s;%d",etudiant1.numero,etudiant1.nom,etudiant1.prenom,etudiant1.email,etudiant1.date_naissance,etudiant1.code_classe);
    }
 }
printf("\n\nOperation terminer ,supression reussit\n\n");
 fclose(tmp);
 fclose(etu);
 remove("etudiant,csv");
 rename("fichtemp.csv","etudiant.csv");

}

//    ********************Fonction Pour la  liste des etudiants***************************
void liste_etudiant(){
     Etudiant etudiant1;
     char car[200];
    
    
  FILE * etu=fopen("etudiant.csv","r");

    execl("/bin/clear","clear",NULL); //facultative pour effacer le terminal avant l'affichage
    fgets(car,200,etu);
    printf("\n\t Liste des Etudiant\n\n");

    printf("+-----------------------------------------------------------------------------------------------------------+\n");
    printf("| N0   |       PRENOM       |        NOM         |         EMAIL         |  DATE DE NAISSANCE  |    CLASSE  |\n");
    printf("+-----------------------------------------------------------------------------------------------------------+\n");
    while(!feof(etu)){

    fgets(car,200,etu);
    

    valeur_saisir(car,&etudiant1);


  printf("|%-6d|%-20s|%-20s|%-23s|%-21s|%-12d|\n",etudiant1.numero,etudiant1.prenom,etudiant1.nom,etudiant1.email,etudiant1.date_naissance,etudiant1.code_classe );
    printf("+-----------------------------------------------------------------------------------------------------------+\n");


    
 }
 printf("\nOperation Terminer ! Afficahge Reussit\n\n");

fclose(etu);
}