#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structure.h"





// void recup_matiere2(char car[],Matiere *matiere1){

//      char temp[3][20];
//     int j=0,k=0;

//     for (int i = 0; i < strlen(car); i++)
//     {
//         if (car[i]==';'|| car[i]=='\n')
//         {
//             temp[j][k]='\0';
//             j++;k=0;
//         }
//          else{

//             temp[j][k]=car[i];
//             k++;
//          }

//     }

//     matiere1->reference=atoi(temp[0]);
//     strcpy(matiere1->libelle,temp[1]);
//     matiere1->coefficient=atoi(temp[2]);
// }





void enlever_retourligne( char tab[40]){   ///cette fonction sert a enlever le retour a la  ligne de fgets

   int taille;

    taille=strlen(tab);         // on remplace la  dernier par le caractere de fin
    tab[taille-1]='\0';
 }

 

void  verification_matiereNom(int rech,Matiere *mt){

    
    FILE *mat=fopen("matiere.csv","r");
    char car[200];
    Matiere matiere1;


    while(!feof(mat)){
        fgets(car,200,mat);
        recup_matiere(car,&matiere1);

        if (matiere1.reference==rech)
        {
            strcpy(mt->libelle,matiere1.libelle);
            mt->reference=matiere1.reference;
            mt->coefficient=matiere1.coefficient;

           fclose(mat);
          
           return ;
        }

    }

}





void recup_sefaire(char car[],Se_Faire *faire){

    int j=0,k=0;
    char temp[2][20];


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
    faire->code_classe=atoi(temp[0]);
    faire->reference_matiere=atoi(temp[1]);

}



void recherche_seFaire(int rec){

    FILE *se_faire=fopen("se_faire.csv","r");
    FILE *tmp=fopen("tempo.csv","w");
    char entete[10]="ref";

    Se_Faire faire;

    char car[200];

    fputs(entete,tmp);

    while(!feof(se_faire)){

        fgets(car,200,se_faire);

        recup_sefaire(car,&faire);

        if (rec==faire.code_classe)
        {
            
            fprintf(tmp, "\n%d",faire.reference_matiere );
        }


    }

    fclose(se_faire);
    fclose(tmp);
}





int verification_sefaire(int rech,int classe){
    FILE *faire=fopen("se_faire.csv","r");
    Se_Faire f;
    char car[200];

    while (!feof(faire)){
        fgets(car,200,faire);
        recup_sefaire(car,&f);

        if (rech==f.reference_matiere && classe==f.code_classe)
        {
            
            fclose(faire);
            return 1;
        }

    }
    fclose(faire);
    return -1;

}