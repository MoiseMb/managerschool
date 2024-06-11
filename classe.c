#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structure.h"

void recup_classe(char car[], Classe *classe1){

    char temp[4][20];
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
        classe1->code=atoi(temp[1]);
    strcpy(classe1->niveau,temp[0]);

    strcpy(classe1->nom,temp[2]);
}
void enlever(char *test){
    for (int i = 0; i < strlen(test); i++)
    {
        if (test[i]=='\n')
        {
            test[i]='\0';
        }
    }
}




int   verificcation_classe(int n){
     Classe classe1;

     char car[70];
    
    FILE * cal=fopen("classe.csv","r");
    while(!feof(cal)){
        fgets(car,70,cal);
        recup_classe(car,&classe1);
       
        if(n==classe1.code){
            fclose(cal);
            return 1;

        }
    }

    fclose(cal);
    return -1;

}


void ajouter_classe(){
    int ch;
    Classe classe1;
    FILE * cal=fopen("classe.csv","a");
    printf("Veuillew saisir le code de la  classe\n");
    scanf("%d",&classe1.code);

    while(verificcation_classe(classe1.code)==1){
     printf("code classe invalide \n saisir a nouveau\n"); 
      scanf("%d",&classe1.code);
     }

    printf("Veuillew saisir le nom de la  classe\n");
    getchar();
    fgets(classe1.nom,20,stdin);
    enlever_retourligne(classe1.nom);


do{
    printf("choisir le  niveau de le classe :\n");
    printf("1-licence\n2-master\n");
    scanf("%d",&ch);
    if (ch<1  || ch>2)
    {
        printf("choix invalide\n");
    }

   
    }while(ch<1  || ch>2);
     if (ch==1)
    
        strcpy(classe1.niveau,"licence"); 
    else

         strcpy(classe1.niveau,"Master"); 

    fprintf(cal,"\n%s;%d;%s",classe1.niveau,classe1.code,classe1.nom);


    printf("Operation reussit,Ajout reussit !\n\n");
    fclose(cal);

}


void modifier_classe(){

    FILE *cal=fopen("classe.csv","r");
    FILE *tor=fopen("fichtemp.csv","w");
    char car[70];
    char entete[50]="niveau;code;nom";


    int recherche,test,ch;
    Classe classe1,nouveau,classe3;

    printf("saisir le code de la classe a  modifier\n");
    scanf("%d",&recherche);

    while(!feof(cal)){


        fgets(car,70,cal);
        recup_classe(car,&classe1);

        if(recherche==classe1.code){
            test=1;
            break;

        }


    }
   fclose(cal);
    if (test!=1)
    {

    printf("\nErreur le numero saisi ne correspond a aucune classe\n\n");
        fclose(tor);
        return;
   
    }else{
      printf("\n\t+-------------------------------------------+\n");
        printf("\t|            classe  a modifier             |\n");
        printf("\t+-------------------------------------------+\n");
        printf("\t|     nom      :    %-20s    |\n",classe1.nom );
        printf("\t+-------------------------------------------+\n");
        printf("\t|     code     :    %-20d    |\n",classe1.code );
        printf("\t+-------------------------------------------+\n");
        printf("\t|    niveau    :    %-20s    |\n",classe1.niveau );  
        printf("\t+-------------------------------------------+\n");

    }
    getchar();
    printf("saisir le nouveau nom :");
    
    fgets(nouveau.nom,20,stdin);
    enlever_retourligne(nouveau.nom);


do{
    printf("choisir niveau de le classe :\n");
    printf("1-licence\n2-master\n");
    scanf("%d",&ch);
    if (ch<1  || ch>2)
    {
        printf("choix invalide\n");
    }

   
    }while(ch<1  || ch>2);

     if (ch==1)
    
        strcpy(nouveau.niveau,"licence"); 
    else

         strcpy(nouveau.niveau,"Master"); 



    cal=fopen("classe.csv","r");

     fgets(car,70,cal);
     fputs(entete,tor);
     

    while(!feof(cal)){

     fgets(car,70,cal);
        recup_classe(car,&classe1);
        enlever_retourligne(classe1.nom);


        if (classe1.code==recherche)
        {

            fprintf(tor,"\n%s;%d;%s",nouveau.niveau,classe1.code,nouveau.nom);

        }else{

            fprintf(tor,"\n%s;%d;%s",classe1.niveau,classe1.code,classe1.nom);


        }
    }



    printf("\a\nOperation terminer,Modification reusit\n\n");

    fclose(cal);
    fclose(tor);

    remove("classe.csv");
    rename("fichtemp.csv","classe.csv");
}



void recherche_classe(){


FILE *cal=fopen("classe.csv","r");

int recherche,test;
    Classe classe1;
    char car[70];

    printf("saisir le code de la classe a  recherher\n");
    scanf("%d",&recherche);

    while(!feof(cal)){


             fgets(car,70,cal);
        recup_classe(car,&classe1);
        


        if(recherche==classe1.code){
            test=1;
         
        break;

        }
    }

    if(test==1){
        printf("\n\t+-------------------------------------------+\n");
        printf("\t|         classe  de la rechercher          |\n");
        printf("\t+-------------------------------------------+\n");
        printf("\t|     nom      :    %-20s    |\n",classe1.nom );
        printf("\t+-------------------------------------------+\n");
        printf("\t|     code     :    %-20d    |\n",classe1.code );
        printf("\t+-------------------------------------------+\n");
        printf("\t|    niveau    :    %-20s    |\n",classe1.niveau );  
        printf("\t+-------------------------------------------+\n");
    }else{

        printf("\nErreur le numero saisi ne correspond a aucune classe\n\n");
        return;
    }
    printf("\nrecherche terminer!!\n\n");
    fclose(cal);
}



void  supression_classe(){

    FILE *cal=fopen("classe.csv","r");
    FILE *tor=fopen("fichtemp.csv","w");

    int recherche,test;
    Classe classe1;
    char rep;
    char car[70];

    char entete[50]="niveau;code;nom";

    printf("\nsaisir le code de la classe a  suprimmer\n");
    getchar();
    scanf("%d",&recherche);

    while(!feof(cal)){


           fgets(car,70,cal);
        recup_classe(car,&classe1);


        if(recherche==classe1.code){
            test=1;
            break;
            

        }


    }
   fclose(cal);
    if (test!=1)
    {

        printf("classe inexistante\n");
        fclose(tor);
        return;
        
   
    }else{
        printf("\n\t+-------------------------------------------+\n");
        printf("\t|          classe  a suprimmer              |\n");
        printf("\t+-------------------------------------------+\n");
        printf("\t|     nom      :    %-20s    |\n",classe1.nom );
        printf("\t+-------------------------------------------+\n");
        printf("\t|     code     :    %-20d    |\n",classe1.code );
        printf("\t+-------------------------------------------+\n");
        printf("\t|    niveau    :    %-20s    |\n",classe1.niveau );  
        printf("\t+-------------------------------------------+\n");  

    }
    printf("\nvoulez vous vraiment supprimer la classe (y/n)\n");
    getchar();
    scanf("%c",&rep);
    if(rep!='y'){

        printf("\n\asupression annuler !!\n\n");
        fclose(tor);
        return;
    }

    cal=fopen("classe.csv","r");

    fgets(car,70,cal);
     fputs(entete,tor);


    while(!feof(cal)){

    fgets(car,70,cal);
    recup_classe(car,&classe1);



        if (classe1.code==recherche)
        {

           continue;

        }else{

            fprintf(tor,"\n%s;%d;%s",classe1.niveau,classe1.code,classe1.nom);

        }
    }



    printf("\n\aOperation terminer,supression reussit\n\n");

    fclose(cal);
    fclose(tor);

    remove("classe.csv");
    rename("fichtemp.csv","classe.csv");
}

void liste_classe(){
    Classe classe1;
    FILE *cal=fopen("classe.csv","r");
    char car[70];

      fgets(car,70,cal);

    printf("\n+---------------------------------------------------------+\n");
    printf("|  code classe  |  niveau classe     |      nom  classe   |\n");
    printf("+---------------------------------------------------------+\n");

     while(!feof(cal)){

        fgets(car,70,cal);
        recup_classe(car,&classe1);

         
        

        printf("|%-15d|%-20s|%-20s| \n",classe1.code,classe1.niveau,classe1.nom );


       printf("+---------------------------------------------------------+\n");




    }

    printf("\a\nAffichage liste Terminer !! \n\n");

}