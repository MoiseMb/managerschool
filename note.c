#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structure.h"


void recup_note(char car[],etre_note *tec){

    char t[4][10];

    int j=0,k=0;

    for (int i = 0; i < strlen(car); i++)
    {
         if (car[i]==';')
         {
            t[j][k]='\0';
            j++;k=0;
         }else{
            t[j][k]=car[i];
            k++;
         }
    }

    tec->reference_matiere=atoi(t[0]);
    tec->numero_etudiant=atoi(t[1]);
    tec->notecc=atoi(t[2]);
    tec->noteDS=atoi(t[3]);

}

int classe_vide(int r){

    FILE *se_faire=fopen("se_faire.csv","r");

    Se_Faire fr;
    char car[100];

    while(!feof(se_faire)){

        fgets(car,100,se_faire);
        recup_sefaire(car,&fr);

        if (r==fr.code_classe)
        {
            fclose(se_faire);
            return 1;
        }
    }
    fclose(se_faire);
    return 0;
}

int numero_classe(int n){

     FILE *etu = fopen ("etudiant.csv" ,"r");
    char car[200];

    Etudiant classe;

    while (!feof(etu))
    {
        fgets(car,200,etu);
        valeur_saisir(car,&classe);
            if (n==classe.numero)
            {
                fclose(etu);
                return classe.code_classe;
            }
    }


    fclose(etu);
    return 1;

}

void infos_etudiant(int rec){

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
    if (rec==etudiant1.numero){

        printf("\n\t+--------------------------------------------+\n");
    printf("\t|             etudiant Numero :   %-5d      |\n",rec);
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

    fclose(etu);
    return ;

    }
    }

    fclose(etu);
    
}
}
int verfication_note_existant(int r,int n){

    FILE *note=fopen("note.csv","r");

    etre_note nt;
    char car[200];

    fgets(car,200,note);


    while(!feof(note)){

        fgets(car,200,note);
        recup_note(car,&nt);
        

        if(r==nt.reference_matiere && n==nt.numero_etudiant){

            fclose(note);

            return 1;
        }
    }


  fclose(note);

    return 0;


}



void infos_matiere(int rech){

      FILE *mat=fopen("matiere.csv","r");
    char car[200];
    Matiere matiere1;

    
    while(!feof(mat)){
        fgets(car,200,mat);
        recup_matiere(car,&matiere1);

        if (matiere1.reference==rech)
        {

            printf("\n\t+---------------------------------------+\n");
            printf("\t|            matiere                    | \n");
            printf("\t+---------------------------------------+\n");
            printf("\t| nom          :  %-20s  |\n",matiere1.libelle);
            printf("\t+---------------------------------------+\n");
            printf("\t| reference    :  %-20d  |  \n",matiere1.reference );
            printf("\t+---------------------------------------+\n");
            printf("\t| coefficient  :  %-20d  |\n",matiere1.coefficient );
            printf("\t+---------------------------------------+");
           fclose(mat);
           
           return ;
        }

    }
    fclose(mat);

    return ;
}


void af_note(int n,int r){
    FILE *note=fopen("note.csv","r");

    etre_note nt;

    
    char car[200];

    fgets(car,200,note);


    while(!feof(note)){

        fgets(car,200,note);
        recup_note(car,&nt);
        

        if(n==nt.reference_matiere && r==nt.numero_etudiant){


            infos_matiere(n);
            printf("\n");
            printf("\t|           note CC           :  %-5g  |\n",nt.notecc);
            printf("\t+---------------------------------------+\n");
            printf("\t|           note DS           :  %-5g  |\n",nt.noteDS);
            printf("\t+---------------------------------------+\n\n");

           break;

        
            fclose(note);

        }
    }


  fclose(note);







}
void recup_matier_note(int n,Matiere *matiere1){

    FILE *mat=fopen("matiere.csv","r");


    char car[200];
    Matiere matr2;

    while(!feof(mat)){

        fgets(car,200,mat);
        recup_matiere(car,&matr2);

        if (n==matr2.reference)
        {
           matiere1->reference=n;
           matiere1->coefficient=matr2.coefficient;
           strcpy(matiere1->libelle,matr2.libelle);

           break;
        }
    }

    fclose(mat);

}

void af_note_liste(int n,int r){
    FILE *note=fopen("note.csv","r");

    etre_note nt;
    Matiere matiere1;

    
    char car[200];

    fgets(car,200,note);


    while(!feof(note)){

        fgets(car,200,note);
        recup_note(car,&nt);
      
        

        if(n==nt.reference_matiere && r==nt.numero_etudiant){

              recup_matier_note(n,&matiere1);


            printf("\t|  %-5d  |      %-5d      |  %-20s  |    %-5g   |    %-5g   |\n",n,matiere1.coefficient,matiere1.libelle,nt.notecc,nt.noteDS);
            printf("\t+------------------------------------------------------------------------------+\n");
          
           break;

        
            fclose(note);

        }
    }


  fclose(note);






}

void ajout_note_1_1 ()
{
    FILE * note = fopen("note.csv","a");

 etre_note b;

 do
{
printf("Veuillez nous donner le numero le numero de l'etudiant\n");
scanf("%d" ,&b.numero_etudiant);
    if(verfication_etudiant(b.numero_etudiant)!=1)
    {
        printf("Numero inexistant\n ");
    }
}while(verfication_etudiant(b.numero_etudiant)!=1);

do{
printf("Veuillez nous donner la reference de la matiere\n");
scanf("%d" ,&b.reference_matiere);
if (verification_matiere(b.reference_matiere)!=1)
    {
        printf("La reference saisi n'existe pas\n ");
    }
}while(verification_matiere(b.reference_matiere)!=1);

int classe=numero_classe(b.numero_etudiant);



if (verification_sefaire(b.reference_matiere,classe)!=1)
{
    printf("\nLa matiere referencier n est pas enseigner dans la classe\n\n" );

    fclose(note);

    return;
}



if (verfication_note_existant(b.reference_matiere,b.numero_etudiant)==1)
{
    printf("\nL'etudiant est deja note dans cette matiere \n\n");
    
    fclose(note);

    return;
}


infos_etudiant(b.numero_etudiant);

infos_matiere(b.reference_matiere);
printf("\n\n");




printf("Veuillez nous donner la note de CC\n");
scanf("%f" ,&b.notecc);
printf("Veuillez nous donner la note de DS\n");
scanf("%f" ,&b.noteDS);

fprintf(note ,"\n%d;%d;%g;%g",b.reference_matiere,b.numero_etudiant,b.notecc,b.noteDS);

printf("\nOperation terminer ! Ajout reussit\n\n");

fclose(note);

}

void ajout_note_1_All ()
{
    FILE *note = fopen("note.csv","a");

     etre_note Lanote;
    int numero;

do{
        printf("Veuillez nous renseigner le numero de l'etudiant\n");
        scanf("%d" ,&numero);
        if(verfication_etudiant(numero)!=1)
    {
        printf("Etudiant inexistant\n saisir a nouveau\r");
    }
}while(verfication_etudiant(numero)!=1);

    infos_etudiant(numero);


    
    char cr[10];

    int ref;
    int classe=numero_classe(numero);


    if (classe_vide(classe)!=1)
    {
        printf("\n La classe de l etudiant n est associer a aucune matiere\n\n");
        fclose(note);
        return;
    }

    recherche_seFaire(classe);

    FILE *tmp=fopen("tempo.csv","r");

    

    fgets (cr,10,tmp);

    while(!feof(tmp)){

    fgets (cr,10,tmp);
    ref=atoi(cr);

    

    if (verfication_note_existant(ref,numero)==1)
    {
        continue;

    }

    

    infos_matiere(ref);
    printf("\n\n");

    printf("saisir la note de controle continue :\n");
    scanf ("%f",&Lanote.notecc);

    printf("saisir la note d'exam :\n");
    scanf ("%f",&Lanote.noteDS);

    fprintf(note ,"\n%d;%d;%g;%g",ref,numero,Lanote.notecc,Lanote.noteDS);





    }

    fclose(tmp);
    fclose(note);
    remove("tempo.csv");



    



    

}


void note_classe(){

    etre_note nt;

    int classe,matiere;

    do
    {
        printf("\n Saisir le code de classe :\n");
        scanf("%d",&classe);

        if (verificcation_classe(classe)!=1)
        {
            printf("Cette classe n existe pas \n");
        }

    } while (verificcation_classe(classe)!=1);

     do
    {
        printf("\n Saisir la reference de la matiere:\n");
        scanf("%d",&matiere);

        if (verification_matiere(matiere)!=1)
        {
            printf("La reference de la matiere saisi n existe pas\n");        
        }

    } while (verification_matiere(matiere)!=1);


    if (verification_sefaire(matiere,classe)!=1)
    {
        printf("\nLa matiere referencier n est pas enseigner dans la classe\n\n" );
        return;
    }

    infos_matiere(matiere);
    printf("\n\n");

    FILE *note=fopen("note.csv","a");

    FILE *etu=fopen("etudiant.csv","r");

    char car[200];
    Etudiant etudiant1;

    while(!feof(etu)){

        fgets(car,200,etu);
        valeur_saisir(car,&etudiant1);

        if (classe==etudiant1.code_classe)
        {

            if (verfication_note_existant(matiere,etudiant1.numero)==1)
            {
                continue;
            }
            infos_etudiant(etudiant1.numero);

            printf("saisir la note de controle continue :\n");
            scanf ("%f",&nt.notecc);

            printf("saisir la note d'exam :\n");
            scanf ("%f",&nt.noteDS);

            fprintf(note ,"\n%d;%d;%g;%g",matiere,etudiant1.numero,nt.notecc,nt.noteDS);

            printf("\nEtudiant suivant\n");

        }

    }

    fclose(etu);

    fclose(note);

    printf("\nOperation Terminer ! ajout reussit \n\n");
}


void modifier_note(){

   
    int numero,matiere;


 do
{
printf("Veuillez nous donner le numero le numero de l'etudiant\n");
scanf("%d" ,&numero);
    if(verfication_etudiant(numero)!=1)
    {
        printf("Etuidant  inexistant\n");
    }
}while(verfication_etudiant(numero)!=1);




     do
    {
        printf("\n Saisir la reference de la matiere:\n");
        scanf("%d",&matiere);

        if (verification_matiere(matiere)!=1)
        {
            printf("La reference de la matiere saisi n existe pas\n");        
        }

    } while (verification_matiere(matiere)!=1);


    if (verfication_note_existant(matiere,numero)!=1){

        printf("\nL'etudiant n est pas encore noter dans cette matiere\n\n");
        return;
    }

    int classe=numero_classe(numero);

    if (verification_sefaire(matiere,classe)!=1)
    {
          printf("\nLa matiere referencier n est pas enseigner dans la classe\n\n" );
          return;
    }
     printf("\n Note de l etudiant Trouver \n");

    infos_etudiant(numero);

    af_note(matiere,numero);

    float nv_notecc,nv_noteds;

    do{
    printf("Saisir la nouvelle note de note de controle continue (noteCC)\n");
    scanf("%f",&nv_notecc);

    }while(nv_notecc<0);

    do{
    printf("Saisir la nouvelle note de note d'examen (noteDS)\n");
    scanf("%f",&nv_noteds);

    }while(nv_noteds<0);


    FILE *note=fopen("note.csv","r");
    FILE *tmp=fopen("temp.csv","w");

    char entete[60]="reference;numero;noteCC;noteDS";

    char car[200];

     etre_note nt;

    fgets(car,200,note);
    fputs(entete,tmp);


    while(!feof(note)){

        fgets(car,200,note);
        recup_note(car,&nt);
        if (matiere==nt.reference_matiere && numero==nt.numero_etudiant)
        {
           fprintf(tmp,"\n%d;%d;%g;%g",nt.reference_matiere,nt.numero_etudiant,nv_notecc,nv_noteds);
        }else{
            fprintf(tmp,"\n%d;%d;%g;%g",nt.reference_matiere,nt.numero_etudiant,nt.notecc,nt.noteDS);
        }
    }

    fclose(note);
    fclose(tmp);

    remove("note.csv");
    rename("temp.csv","note.csv");


    printf("\nOperation Terminer ! Modification Reussit\n\n");






}

void supprimer_note(){

   
    int numero,matiere;


 do
{
printf("Veuillez nous donner le numero le numero de l'etudiant\n");
scanf("%d" ,&numero);
    if(verfication_etudiant(numero)!=1)
    {
        printf("Etuidant  inexistant\n");
    }
}while(verfication_etudiant(numero)!=1);




     do
    {
        printf("\n Saisir la reference de la matiere:\n");
        scanf("%d",&matiere);

        if (verification_matiere(matiere)!=1)
        {
            printf("La reference de la matiere saisi n existe pas\n");        
        }

    } while (verification_matiere(matiere)!=1);


    if (verfication_note_existant(matiere,numero)!=1){

        printf("\nL'etudiant n est pas encore noter dans cette matiere\n\n");
        return;
    }

    int classe=numero_classe(numero);

    if (verification_sefaire(matiere,classe)!=1)
    {
          printf("\nLa matiere referencier n est pas enseigner dans la classe\n\n" );
          return;
    }
     printf("\n Note de l etudiant Trouver \n");

    infos_etudiant(numero);

    af_note(matiere,numero);

    char r;

    

 
    printf("Voulez_vous vraiment effectuer cette Supression(Y/N)\n");
    getchar();
    scanf("%c",&r);

 

    if ( r=='n' || r=='N')
    {
        printf("\nSuppression Annuler \n\n");
        return;
    }




    FILE *note=fopen("note.csv","r");
    FILE *tmp=fopen("temp.csv","w");

    char entete[60]="reference;numero;noteCC;noteDS";

    char car[200];

     etre_note nt;

    fgets(car,200,note);
    fputs(entete,tmp);


    while(!feof(note)){

        fgets(car,200,note);
        recup_note(car,&nt);
        if (matiere==nt.reference_matiere && numero==nt.numero_etudiant)
        {
           continue;
        }else{
            fprintf(tmp,"\n%d;%d;%g;%g",nt.reference_matiere,nt.numero_etudiant,nt.notecc,nt.noteDS);
        }
    }

    fclose(note);
    fclose(tmp);

    remove("note.csv");
    rename("temp.csv","note.csv");


    printf("\nOperation Terminer ! Supression Reussit\n\n");






}


void affiche_une_note (){


        int numero,matiere;


 do
{
printf("Veuillez nous donner le numero le numero de l'etudiant\n");
scanf("%d" ,&numero);
    if(verfication_etudiant(numero)!=1)
    {
        printf("Etuidant  inexistant\n");
    }
}while(verfication_etudiant(numero)!=1);




     do
    {
        printf("\n Saisir la reference de la matiere:\n");
        scanf("%d",&matiere);

        if (verification_matiere(matiere)!=1)
        {
            printf("La reference de la matiere saisi n existe pas\n");        
        }

    } while (verification_matiere(matiere)!=1);


    if (verfication_note_existant(matiere,numero)!=1){

        printf("\nL'etudiant n est pas encore noter dans cette matiere\n\n");
        return;
    }

    int classe=numero_classe(numero);

    if (verification_sefaire(matiere,classe)!=1)
    {
          printf("\nLa matiere referencier n est pas enseigner dans la classe\n\n" );
          return;
    }
     printf("\n Note de l etudiant Trouver \n");

    infos_etudiant(numero);

    af_note(matiere,numero);


    printf("\nOperation Terminer ! affichage reussit\n\n");
}


void affiche_note_all_matiere(){

    int numero,ref;
    do
    {
        printf("Veuillez nous donner le numero le numero de l'etudiant\n");
        scanf("%d" ,&numero);
        if(verfication_etudiant(numero)!=1)
        {
            printf("Etuidant  inexistant\n");
        }
    }while(verfication_etudiant(numero)!=1);

    int classe=numero_classe(numero);

     if (classe_vide(classe)!=1)
    {
        printf("\n La classe de l etudiant n est associer a aucune matiere\n\n");
        
        return;
    }


    infos_etudiant(numero);

    recherche_seFaire(classe);

    FILE *tmp=fopen("tempo.csv","r");
   
    char cr[10];

    fgets (cr,10,tmp);
    
     printf("\n\t+------------------------------------------------------------------------------+\n");
    printf("\t|   REF   |   coefficient   |        Libelle         |  Note CC   |   Note DS  |\n");
    printf("\t+------------------------------------------------------------------------------+\n");

    while(!feof(tmp)){

    fgets (cr,10,tmp);
    ref=atoi(cr);

   

    if (verfication_note_existant(ref,numero)!=1)
    {
        continue;

    }else{
        af_note_liste(ref,numero);
    }
    }

    fclose(tmp);

    printf("\n Operation Terminer ! affichage Reussit\n\n");



}







