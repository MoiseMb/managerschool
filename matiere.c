#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structure.h"



//************************ Fonction Pour ajouter une matiere ************************

void recup_matiere(char car[],Matiere *matiere1){

     char temp[3][20];
    int j=0,k=0;

    for (int i = 0; i < strlen(car); i++)
    {
        if (car[i]==';'|| car[i]=='\n')
        {
            temp[j][k]='\0';
            j++;k=0;
        }
         else{

            temp[j][k]=car[i];
            k++;
         }

    }

    matiere1->reference=atoi(temp[0]);
    strcpy(matiere1->libelle,temp[1]);
    matiere1->coefficient=atoi(temp[2]);
}







int  verification_matiere(int rech){
    FILE *mat=fopen("matiere.csv","r");
    char car[200];
    Matiere matiere1;

    int test=0;
    while(!feof(mat)){
        fgets(car,200,mat);
        recup_matiere(car,&matiere1);

        if (matiere1.reference==rech)
        {
           fclose(mat);
           test=1;
           return test;
        }

    }

    fclose(mat);
    return test;
}




void  ajout_matiere(){
     FILE * mat=fopen("matiere.csv","a"); // on ouvre de le fichier etuidant en mode ecriture a la fin.


    if (mat==NULL){
        printf("Erreur lors de  l'ouverture du fichier \n");  //Pour tester si l ouverture du fichier c'est bien passe.
        fclose(mat);
        exit(1);
    }

    Matiere matiere1;

    do{
    printf("Veuillez saisir le reference de la matiere :");
    scanf("%d",&matiere1.reference);
    if (verification_matiere(matiere1.reference)==1 || matiere1.reference<0)
    {
        printf("\aErreur choix indisponible\n");
    }

    }while(verification_matiere(matiere1.reference)==1 || matiere1.reference<0);
    printf("Veuillez saisir le nom de la matiere :");
    getchar();
    fgets(matiere1.libelle,20,stdin);
    enlever_retourligne(matiere1.libelle);
    printf("Veuillez saisir le cofficient de la matiere :");
    scanf("%d",&matiere1.coefficient);
   



    fprintf(mat,"\n%d;%s;%d",matiere1.reference,matiere1.libelle,matiere1.coefficient);
    
    printf("Operation terminer avec succes\n\n");

    fclose(mat);

}


void modification_matiere(){

 FILE *mat=fopen("matiere.csv","r");
 FILE  *tmp=fopen("fichtemp.csv","w");

 Matiere matiere1,nouvelle_dt;
 int recherche,test=0;

  char car[200];
 char entete[50]="reference;libelle;coefficient";

 printf("Saisir la reference de  la matiere  :");
 scanf("%d",&recherche);

 while (!feof(mat)){

        fgets(car,200,mat);

        recup_matiere(car,&matiere1);    
        if (recherche==matiere1.reference){
    
        test=1;
        break;
    }
 }
 fclose(mat);
 if(test!=1){

     printf("\n\aErreur la reference de la matiere saisi n existe pas\n\n");
    fclose(tmp);
    return;
 }else
 {
      printf("\n\t+----------------------------------------+\n");
    printf("\t|            matiere a modifier          | \n");
    printf("\t+----------------------------------------+\n");
    printf("\t| nom          :  %-20s   |\n",matiere1.libelle);
    printf("\t+----------------------------------------+\n");
    printf("\t| reference    :  %-20d   |  \n",matiere1.reference );
    printf("\t+----------------------------------------+\n");
    printf("\t| coefficient  :  %-20d   |\n",matiere1.coefficient );
    printf("\t+----------------------------------------+\n\n");

 }
    getchar();
    printf("saisir le nouveau nom \n");
    fgets(nouvelle_dt.libelle,20,stdin);
    enlever_retourligne(nouvelle_dt.libelle);
    printf("saisir le nouveau coefficient \n");
    scanf("%d",&nouvelle_dt.coefficient);
    

    mat=fopen("matiere.csv","r");

    fgets(car,200,mat);

    fputs(entete,tmp);

    while(!feof(mat)){

        fgets(car,200,mat);
        recup_matiere(car,&matiere1);

    if(matiere1.reference==recherche){
    fprintf(tmp,"\n%d;%s;%d",matiere1.reference,nouvelle_dt.libelle,nouvelle_dt.coefficient);
    }else{
    fprintf(tmp,"\n%d;%s;%d",matiere1.reference,matiere1.libelle,matiere1.coefficient);
    }
 }
printf("\nmodification reusit !!\n\n");
 fclose(tmp);
 fclose(mat);
 remove("matiere.csv");
 rename("fichtemp.csv","matiere.csv");

}
void recherche_matiere(){

    FILE *mat=fopen("matiere.csv","r");

Matiere matiere1;
 int recherche,test=0;
 char car[200];

 printf("Saisir la reference de  la matiere  :");
 scanf("%d",&recherche);

 while (!feof(mat)){


        fgets(car,200,mat);
        recup_matiere(car,&matiere1);

        if (recherche==matiere1.reference){
            test=1;
    printf("\n\t+---------------------------------------+\n");
    printf("\t|            matiere Rechercher         | \n");
    printf("\t+---------------------------------------+\n");
    printf("\t| nom          :  %-20s  |\n",matiere1.libelle);
    printf("\t+---------------------------------------+\n");
    printf("\t| reference    :  %-20d  |  \n",matiere1.reference );
    printf("\t+---------------------------------------+\n");
    printf("\t| coefficient  :  %-20d  |\n",matiere1.coefficient );
    printf("\t+---------------------------------------+\n\n");
        
        break;
    }
 }
 
  fclose(mat);
  if (test!=1)
 {
     printf("\n\aErreur la reference de la matiere saisi n existe pas\n\n");
     return;
 }


}



void supression_matiere(){

 FILE *mat=fopen("matiere.csv","r");
 FILE  *tmp=fopen("fichtemp.csv","w");

 Matiere matiere1;
 int recherche,test;

  char car[200];
 char entete[50]="reference;libelle;coefficient";

 printf("Saisir la reference de  la matiere  :");
 scanf("%d",&recherche);

 while (!feof(mat)){

        fgets(car,200,mat);

        recup_matiere(car,&matiere1);    
        if (recherche==matiere1.reference){
    
        test=1;
        break;
    }
 }
 fclose(mat);
 if(test!=1){

     printf("\n\aErreur la reference de la matiere saisi n existe pas\n\n");
    fclose(tmp);
    return;
 }else
 {
      printf("\n\t+----------------------------------------+\n");
    printf("\t|            matiere a suprimmer         | \n");
    printf("\t+----------------------------------------+\n");
    printf("\t| nom          :  %-20s   |\n",matiere1.libelle);
    printf("\t+----------------------------------------+\n");
    printf("\t| reference    :  %-20d   |  \n",matiere1.reference );
    printf("\t+----------------------------------------+\n");
    printf("\t| coefficient  :  %-20d   |\n",matiere1.coefficient );
    printf("\t+----------------------------------------+\n\n");

 }
  char rep;
    printf("Voulez-vous  vraiment  suprimmer la matiere (y/n)\n");
    getchar();
    scanf("%c",&rep);
    if (rep=='n')
    {
        printf("\nsupression Annuler !!\n\n");
        fclose(tmp);
        fclose(mat);
        return;
    }
        mat=fopen("matiere.csv","r");

    fgets(car,200,mat);
    fputs(entete,tmp);


    while(!feof(mat)){

        fgets(car,200,mat);

        recup_matiere(car,&matiere1);

    if(matiere1.reference==recherche){
        continue;

    }else{
    fprintf(tmp,"\n%d;%s;%d",matiere1.reference,matiere1.libelle,matiere1.coefficient);
    }
 }
printf("\nOperation terminer , supression reussit !\n\n");
 fclose(tmp);
 fclose(mat);
 remove("matiere.csv");
 rename("fichtemp.csv","matiere.csv");

}

void liste_matiere(){
     Matiere matiere1;
     char car[200];
    
    
  FILE * mat=fopen("matiere.csv","r");
  fgets(car,200,mat);

    printf("+---------------------------------------------------------------+\n");
    printf("| reference Matiere |   libelle Matiere   | coefficient Matiere |\n");
    printf("+---------------------------------------------------------------+\n");

    while(!feof(mat)){

        fgets(car,200,mat);

        recup_matiere(car,&matiere1);

    printf("|%-19d|%-21s|%-21d|\n",matiere1.reference,matiere1.libelle,matiere1.coefficient);
    printf("+---------------------------------------------------------------+\n");

 }
 printf("\nAffichage Terminer\n");

fclose(mat);
}



void associer_matiere(){
    FILE * sefaire=fopen("se_faire.csv","a");

    Se_Faire faire;

    do{

        do{
             printf("Saisir la reference de la matiere a associer\n");
             scanf("%d",&faire.reference_matiere);

             if (verification_matiere(faire.reference_matiere)!=1)
             {
                printf("\nErreur la matiere saisi n existe pas\n");
             }

        }while(verification_matiere(faire.reference_matiere)!=1);

        do{

            printf("Veuillez nous indiquer le code de la classe ou l'on doit associer la matiere\n");
            scanf("%d",&faire.code_classe);
            if (verificcation_classe(faire.code_classe)!=1)
            {
                printf("\nLa classe saisi n existe pas\n");
            }

        }while(verificcation_classe(faire.code_classe)!=1);


     


        if (verification_sefaire(faire.reference_matiere,faire.code_classe)==1 )
         {
             printf("\nCette matiere est deja associer a cette classe \n");
         }

        

        }while(verification_sefaire(faire.reference_matiere,faire.code_classe)==1 );


         
     
     



         fprintf(sefaire, "\n%d;%d",faire.code_classe,faire.reference_matiere);

         fclose(sefaire);

         printf("\nOperation terminer !! Association reussit\n\n");

}


void desassocier_matiere(){
    FILE *tmp=fopen("tmpo.csv","w");
    FILE *fait=fopen("se_faire.csv","r");

    

    char car[200];

    Se_Faire faire;
    int test,classe,matiere;


        do{
             printf("Saisir la reference de la matiere a dissocier\n");
             scanf("%d",&matiere);

             if (verification_matiere(matiere)!=1)
             {
                printf("\nErreur la matiere saisi n existe pas\n");
             }

        }while(verification_matiere(matiere)!=1);

        do{

            printf("Veuillez nous indiquer le code de la classe de la matiere pour dissociation\n");
            scanf("%d",&classe);
            if (verificcation_classe(classe)!=1)
            {
                printf("\nLa classe saisi n existe pas\n");
            }

        }while(verificcation_classe(classe)!=1);






        if (verification_sefaire(matiere,classe)==1 )
         {
            printf("\nAssociation trouver\n\n");

            printf("\t+---------------------------------+\n");
            printf("\t| code classe        :  %-8d  |\n",classe);
            printf("\t+---------------------------------+\n");
            printf("\t| reference matiere  :  %-8d  |\n",matiere);
            printf("\t+---------------------------------+\n");
         }else{

            printf("\nCette Association n existe pas encore\n\n");
            fclose(tmp);
            return;
         }

         char rep;
        printf("Voulez-vous  vraiment  suprimmer cette association (y/n)\n");
        getchar();
        scanf("%c",&rep);
    if (rep=='n')
    {
        printf("\nsupression Annuler !!\n\n");
        fclose(tmp);
        fclose(fait);
        return;
    }

    char entete[50]="code_classe;reference_matiere";
    fputs(entete,tmp);
    fgets(car,200,fait);

    while(!feof(fait)){

        fgets(car,200,fait);
        recup_sefaire(car,&faire);

        if(faire.code_classe==classe && faire.reference_matiere==matiere){
            continue;
        }
        else{
            fprintf(tmp, "\n%d;%d",faire.code_classe,faire.reference_matiere );
        }

    }

    fclose(tmp);
    fclose(fait);
    remove("se_faire.csv");
    rename("tmpo.csv","se_faire.csv");

    printf("\nOperation terminer !! disociation reussit  \n\n");



    }
