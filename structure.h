
typedef struct {
    int code;
    char nom[20];
    char niveau[20];
}Classe;

typedef struct {
    int numero;
    char nom[20]; 
    char prenom[20];
    char email[30];
    char date_naissance [20];
    int code_classe;
}Etudiant;


typedef struct {
    int numero_etudiant;
    int reference_matiere;
    float notecc;
    float noteDS;
}etre_note;

typedef struct {
    int reference;
    char libelle[15];
    int  coefficient;
} Matiere;

typedef struct {
    int reference_matiere;
    int code_classe;
}Se_Faire ;

// typedef struct {
//   int   numero_etudiant ;
//    int  code_classe;
// }appartenir;


void enlever_retourligne( char tab[40]);



 // ***** Fonction et procedure Pour etudiant *************

 void valeur_saisir(char car[],Etudiant *etudiant1);

 int verfication_etudiant(int test);

 void  etudiantAjout();

 void modification_etudiant();

 void recherche_etudiant();

 void supression_etudiant();

 void liste_etudiant();

 // **** Focntion Pour classe  ********

 void recup_classe(char car[], Classe *classe1);

 void enlever(char *test);

 int   verificcation_classe(int n);

 void ajouter_classe();

 void modifier_classe();

 void recherche_classe();

 void  supression_classe();

 void liste_classe();


 //fonction et procedure Pour Matiere *******

 void recup_matiere(char car[],Matiere *matiere1);

 int  verification_matiere(int rech);

 void  ajout_matiere();

 void modification_matiere();

 void recherche_matiere();

 void supression_matiere();

 void liste_matiere();

 void associer_matiere();

 void desassocier_matiere();


 //fonction et procedure pour sefaire ******

 void  verification_matiereNom(int rech,Matiere *mt);

 void recup_sefaire(char car[],Se_Faire *faire);

 void recherche_seFaire(int rec);

 int verification_sefaire(int rech,int classe);


 //******** Fonction pour note **********

 void ajout_note_1_1 ();

 void ajout_note_1_All ();

 void infos_etudiant(int rec);

 void infos_matiere(int rech);

 int verfication_note_existant(int r,int n);

 void recup_note(char car[],etre_note *tec);

 int classe_vide(int r);

 int numero_classe(int n);

 void note_classe();

 void af_note(int n,int r);

 void modifier_note();

 void supprimer_note();

 void affiche_une_note ();

 void affiche_note_all_matiere();










  