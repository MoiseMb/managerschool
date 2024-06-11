#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structure.h"
#include "affichage.h"

int main ()
{

menu :{

  int choix,choix2;
affichage_menu();

printf("Veuillez nous indiquer le lieu ou vous souhaiter vous rendre\n");
scanf("%d",&choix);
choix=controle(choix,5);
switch (choix) {
    case 1 : 
    {
      sous_menu1:{
      affichage_menu1();
      printf("veuillez choisir une operation\n");
      scanf("%d",&choix2);
      choix2=controle(choix2,6);
        switch(choix2){
         case 1 :{

            etudiantAjout();
            goto sous_menu1;
            break;

            }
        
      
    
        case 2:{

            modification_etudiant();
            goto sous_menu1;
             break;
            }
            case 3:{

            recherche_etudiant();
            goto sous_menu1;
             break;
            }
            case 4:{

            supression_etudiant();
            goto sous_menu1;
             break;
            }
            case 5:{

            liste_etudiant();
            goto sous_menu1;
             break;
            }
            case 6 :{
              
              goto menu;
              break;
            }
     
    }
      }
    break;
    }

    case 2:
    {
        sous_menu2 :{
            affichage_menu2();
            printf("veuillez choisir une operation\n");
            scanf("%d",&choix2);
            choix2=controle(choix2,8);
            switch(choix2){
            case 1:{
              ajout_matiere();
              goto sous_menu2;
              break;
            }
            case 2:{
              modification_matiere();
              goto sous_menu2;
              break;
            }
             case 3:{
              recherche_matiere();
              goto sous_menu2;
              break;
            }
            case 4:{
              supression_matiere();
              goto sous_menu2;
              break;
            }
            case 5:{
              liste_matiere();
              goto sous_menu2;
              break;
            }
            case 6:{
             associer_matiere();
             goto sous_menu2;
              break;
            }
            case 7:{
             desassocier_matiere();
             goto sous_menu2;
              break;
            }

            case 8:{
             
              goto menu;
              break;
            }
            }
        }
      break;
    
    }
    case 3:
    {
        sous_menu3:
        {
        affichage_menu3();
        printf("veuillez choisir une operation\n");
        scanf("%d",&choix2);
        choix2=controle(choix2,6);

        switch(choix2){

                   
            case 1:{

                    ajouter_classe();
                    goto sous_menu3;
                    break;
                }
                case 2:{

                    modifier_classe();
                    goto sous_menu3;
                    break;
                }
                case 3:{

                    recherche_classe();
                    goto sous_menu3;
                    break;
                }

                 case 4:{

                    supression_classe();
                    goto sous_menu3;
                    break;
                }
                 case 5:{

                    liste_classe();
                    goto sous_menu3;
                    break;
                }
                 case 6:{

                    
                    goto menu;
                    break;
                }
                
            }
        }
        break;
    }
    sous_menu4 :
    {
    case 4:
    {
      affichage_menu4();
       printf("veuillez choisir une operation\n");
      scanf("%d",&choix2);
      choix2=controle(choix2,9);

      switch(choix2)
      {
        case 1:
        {
          ajout_note_1_1();
          goto sous_menu4;
          break;
        }
        case 2:
        {
          ajout_note_1_All ();
          goto sous_menu4;
          break;
        }
        case 3:
        {
          note_classe ();
          goto sous_menu4;
          break;
        }
        case 4:
        {
          modifier_note();
          goto sous_menu4;
          break;
        }
         case 5:
        {
          supprimer_note();
          goto sous_menu4;
          break;
        }

        case 6:
        {
          affiche_une_note ();
          goto sous_menu4;
          break;
        }

         case 7:
        {
          affiche_note_all_matiere();
          goto sous_menu4;
          break;
        }
        case 8:
        {
           goto menu;
            break;
        }

      }

      break;
    }
    }
    case 5:
    {

        printf("\n\n \t     BYE !!!!\n\n");
      exit(1);
    }

} 
}

}
