#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <unistd.h>
#include "fonction.h"

int affichageMenu()
{
    int iphone = 0;
    int ptiphone = &iphone;
    int potion = 0;
    int ptpotion = &potion;
    int or = 0;
    int ptor = &or;
    int pv = 50;
    int attaque = 5;
    int defense = 1;
    int batterie = 0;
    int exp = 0;
    int lvl = 1;
    int ptbatterie = &batterie;
    int ptxp = &exp; //pointeur de l'xp du joueur
    int ptlvl = &lvl; //pointeur du niveau du joueur
    int ptatt = &attaque; //pointeur de l'attaque du joueur
    int ptdef = &defense; //pointeur de la defense du joueur
    int ptpv = &pv; // pointeur des pv du joueur
    int x = 0; // position en ordonné du joueur
    int y = 0; // position en abscisse du joueur
    int *pointeurx = &x; // pointeur de l'abscisse
    int *pointeury = &y; // pointeur de l'ordonné
    int choixMenu;
    printf(" /***\n");
    printf("  *       __  ___     _                            \n");
    printf("  *      /  |/  /__ _(_)__    __ _  ___ ___  __ __ \n");
    printf("  *     / /|_/ / _ `/ / _ \  /  ' \/ -_) _ \/ // / \n");
    printf("  *    /_/  /_/\_,_/_/_//_/ /_/_/_/\__/_//_/\_,_/ \n");
    printf("  *                                             \n");
    printf("  */\n\n");
    printf("1.Creer une nouvelle partie\n");
    printf("2.Charger une partie\n");
    printf("3.A propos\n");
    printf("4.Quitter\n\n\n");
    printf("\nVotre choix?\n\n");
    scanf("%d", &choixMenu);
    char Name[100];
    int *pointeurname = &Name;
    switch (choixMenu)
    {
    case 1:
        printf("\nEntrez votre nom ?:\n\n");
        scanf("%s",&Name);
        printf("Bonjour %s\n",Name);
        sleep(2);
        printf("Le nom d'un vrai guerrier \n");
        sleep(2);
        GameStart();
        sleep(2);
        printf(" \n");
        carte(pointeurx,pointeury,ptlvl,ptatt,ptdef,ptbatterie,ptpv,pointeurname,ptxp,ptor,ptpotion,ptiphone);
        break;
    case 2:
        printf("Desole cette fonctionnalite n'est pas disponible\n");
        printf("vous devez acheter la version Premium pour acceder a cette fonction \n");
        affichageMenu();
        break;
    case 3:
        printf("C'est le meilleur jeu de ta vie\n\n");
        affichageMenu();
        break;
    case 4:
        printf("AuRevoir");
        exit(0);
        break;
    }
    return 0;
}

void showStartMessage() // Show Game Logo
{
  printf(" ########  ##          ###     ######  ##    ##       ########  #######  ########  ########  ######  ########      \n");
  sleep(1);
  printf(" ##     ## ##         ## ##   ##    ## ##   ##        ##       ##     ## ##     ## ##       ##    ##    ##         \n");
   sleep(1);
  printf(" ##     ## ##        ##   ##  ##       ##  ##         ##       ##     ## ##     ## ##       ##          ##      \n");
   sleep(1);
  printf(" ########  ##       ##     ## ##       #####          ######   ##     ## ########  ######    ######     ##  \n");
   sleep(1);
  printf(" ##     ## ##       ######### ##       ##  ##         ##       ##     ## ##   ##   ##             ##    ##      \n");
   sleep(1);
  printf(" ##     ## ##       ##     ## ##    ## ##   ##        ##       ##     ## ##    ##  ##       ##    ##    ## \n ");
   sleep(0.5);
  printf("########  ######## ##     ##  ######  ##    ##       ##        #######  ##     ## ########  ######     ## \n");
}

int GameStart(){
    int ReponseUser;
    printf("welcome to The Broceliande Forest \n");
    sleep(2);
    printf("Une foret pleine de mystere et de surprise \n");
    printf("Pret a relever les defies ?? :\n");
    sleep(2);
    printf("1 -Oui \n");
    printf("2- Non \n");
    printf("3 - BLC \n");
    scanf("%d",&ReponseUser);
    switch (ReponseUser)
    {
    case 1:
    printf("Bonne chance guerrier \n");
        break;
    case 2:
        printf("Prend Tes couilles en main Monsieur \n");
        printf("vous n'avez pas le choix \n");
        break;
    case 3:
    printf("Mdr il s'en BLC \n");
    printf("Bonne chance alors \n");
        break;

    }

}
int combat(int *x, int *y,int *lvl, int *attaque,int *defense,int *batterie,int *pv, int *name, int *xp, int *or, int *potion, int *iphone)
{
    int pvmonstre = 10;
    int atkmonstre = 3;
    int defmonstre = 1;
    int damageJ = *attaque - defmonstre;
    int damageM = atkmonstre - *defense;
    int choixCombatUser;
    while (pvmonstre > 0 | *pv > 0)
    {
    printf("Hp : %d\n",*pv);
    printf("Hp monstre : %d\n\n",pvmonstre);
    printf("Que voulez vous faire ?\n\n");
    printf("1. Attaquer avec le couteau \n");
    printf("2. Attaquer avec le nokia 3310\n");
    printf("3. Utiliser une potion\n");
    printf("4. Courir ou detaller pour les intimes \n");
    printf("5. Roupiller\n");
    scanf("%d",&choixCombatUser);
    switch (choixCombatUser)
    {
    case 1:
        printf("vous poignardez l'ennemi avec son couteau\n");
        pvmonstre = pvmonstre - damageJ;
        printf("l'ennemi perds %d point de vie\n",damageJ);
        if (pvmonstre<=0)
        {
            printf("victoire !!\n");
            niveau(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
        }
        printf("l'ennemi vous attaque\n");
        *pv = *pv - damageM;
        printf("vous perdez %d point de vie\n",damageM);
        if(*pv < 1)
        {
            printf("tu as perdu, honte a toi\n");
            printf("   ####    ##   #    # ######     ####  #    # ###### #####   \n");
            sleep(1);
            printf("  #    #  #  #  ##  ## #         #    # #    # #      #    #         \n");
            sleep(1);
            printf("  #      #    # # ## # #####     #    # #    # #####  #    #       \n");
            sleep(1);
            printf("  #  ### ###### #    # #         #    # #    # #      #####  \n");
            sleep(1);
            printf("  #    # #    # #    # #         #    #  #  #  #      #   #      \n");
            sleep(1);
            printf("   ####  #    # #    # ######     ####    ##   ###### #    #\n ");
            sleep(2);
            affichageMenu();
        }
        break;
    case 2:
        if(*batterie < 1)
            printf("Vous n'avez plus de batterie\n");
        else
        {
            printf("vous envoiez des ondes negatives sur l'ennemi\n");
            batterie = batterie - 1;
            pvmonstre = pvmonstre - (*attaque + 1);
            if (pvmonstre<=0)
            {
                printf("victoire !!\n");
                niveau(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
            }
            printf("l'ennemi vous attaque\n");
            *pv = *pv - damageM;
            printf("vous perdez %d point de vie\n",damageM);
        }
        if(*pv < 1)
        {
            printf("Vous avez perdu honte a toi\n");
            printf("   ####    ##   #    # ######     ####  #    # ###### #####   \n");
            sleep(1);
            printf("  #    #  #  #  ##  ## #         #    # #    # #      #    #         \n");
            sleep(1);
            printf("  #      #    # # ## # #####     #    # #    # #####  #    #       \n");
            sleep(1);
            printf("  #  ### ###### #    # #         #    # #    # #      #####  \n");
            sleep(1);
            printf("  #    # #    # #    # #         #    #  #  #  #      #   #      \n");
            sleep(1);
            printf("   ####  #    # #    # ######     ####    ##   ###### #    #\n ");
            sleep(2);
            affichageMenu();
        }
        break;
    case 3:
        *potion = *potion - 1;
        *pv = *pv + 10;
        printf("vous gagnez 10 points de vie\n");
        printf("l'ennemi vous attaque\n");
        *pv = *pv - damageM;
        printf("vous perdez %d point de vie\n",damageM);
        if(*pv < 1)
        {
            printf("tu as perdu, honte a toi\n");
            printf("   ####    ##   #    # ######     ####  #    # ###### #####   \n");
            sleep(1);
            printf("  #    #  #  #  ##  ## #         #    # #    # #      #    #         \n");
            sleep(1);
            printf("  #      #    # # ## # #####     #    # #    # #####  #    #       \n");
            sleep(1);
            printf("  #  ### ###### #    # #         #    # #    # #      #####  \n");
            sleep(1);
            printf("  #    # #    # #    # #         #    #  #  #  #      #   #      \n");
            sleep(1);
            printf("   ####  #    # #    # ######     ####    ##   ###### #    #\n ");
            sleep(2);
            affichageMenu();
        }
        break;
    case 4:
        printf("vous vous enfuyez tel un lache\n");
        deplacement(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
        break;
    case 5:
        printf("vous faites la sieste en plein combat\n");
        printf("l'ennemi vous attaque\n");
        *pv = *pv - atkmonstre;
        if(*pv < 1)
        {
            printf("vous avez perdu honte a toi\n");
            printf("   ####    ##   #    # ######     ####  #    # ###### #####   \n");
            sleep(1);
            printf("  #    #  #  #  ##  ## #         #    # #    # #      #    #         \n");
            sleep(1);
            printf("  #      #    # # ## # #####     #    # #    # #####  #    #       \n");
            sleep(1);
            printf("  #  ### ###### #    # #         #    # #    # #      #####  \n");
            sleep(1);
            printf("  #    # #    # #    # #         #    #  #  #  #      #   #      \n");
            sleep(1);
            printf("   ####  #    # #    # ######     ####    ##   ###### #    #\n ");
            sleep(2);
            affichageMenu();
        }
        break;
    }
    }
}
int Boss(int *x, int *y,int *lvl, int *attaque,int *defense,int *batterie,int *pv, int *name, int *xp, int *or, int *potion, int *iphone)
{
    int paralysie = 0;
    int pvmonstre = 100;
    int atkmonstre = 15;
    int defmonstre = 3;
    int ulti = 4;
    int damageJ = *attaque - defmonstre;
    int damageM = atkmonstre - *defense;
    int choixCombatUser;
    while (pvmonstre > 0 | *pv > 0)
    {
        printf("Hp : %d\n",*pv);
        printf("Hp Boss : %d\n\n",pvmonstre);
        if(paralysie == 1)
        {
            printf("vous etes paralyse, vous ne pouvez pas bouger\n");
            printf("le boss vous attaque\n");
            *pv = *pv - damageM;
            printf("vous perdez %d point de vie\n",damageM);
            ulti = ulti + 1;
            if(*pv < 1)
            {
                printf("tu as perdu, honte a toi\n");
                printf("   ####    ##   #    # ######     ####  #    # ###### #####   \n");
                sleep(1);
                printf("  #    #  #  #  ##  ## #         #    # #    # #      #    #         \n");
                sleep(1);
                printf("  #      #    # # ## # #####     #    # #    # #####  #    #       \n");
                sleep(1);
                printf("  #  ### ###### #    # #         #    # #    # #      #####  \n");
                sleep(1);
                printf("  #    # #    # #    # #         #    #  #  #  #      #   #      \n");
                sleep(1);
                printf("   ####  #    # #    # ######     ####    ##   ###### #    #\n ");
                sleep(2);
                fin();
            }
            paralysie = 0;
            printf("vous n'etes plus paralyse\n");
        }
        else
        {
            printf("Que voulez vous faire ?\n\n");
            printf("1. attaquer avec le couteau \n");
            printf("2. attaquer avec le nokia 3310\n");
            printf("3. utiliser une potion\n");
            printf("4. courir ou detaller pour les intimes \n");
            printf("5. roupiller\n");
            scanf("%d",&choixCombatUser);
            switch (choixCombatUser)
            {
            case 1:
                printf("vous poignardez l'ennemi avec son couteau\n");
                pvmonstre = pvmonstre - damageJ;
                printf("l'ennemi perds %d point de vie\n",damageJ);
                if (pvmonstre<=0)
                {
                    printf("victoire !!\n");
                    fin();
                }
                    printf("il reste %d points de vie a l'ennemi\n",pvmonstre);
                if(ulti > 3)
                {
                    printf("le boss attaque avec son taser\n");
                    *pv = *pv - atkmonstre;
                    printf("vous perdez %d point de vie\n",damageM);
                    printf("vous etes paralyse pendant 1 tour\n",damageM);
                    ulti = 0;
                }
                else
                {
                    printf("le boss vous attaque\n");
                    *pv = *pv - damageM;
                    printf("vous perdez %d point de vie\n",damageM);
                }
                if(*pv < 1)
                {
                    printf("tu as perdu, honte a toi\n");
                     printf("   ####    ##   #    # ######     ####  #    # ###### #####   \n");
            sleep(1);
            printf("  #    #  #  #  ##  ## #         #    # #    # #      #    #         \n");
            sleep(1);
            printf("  #      #    # # ## # #####     #    # #    # #####  #    #       \n");
            sleep(1);
            printf("  #  ### ###### #    # #         #    # #    # #      #####  \n");
            sleep(1);
            printf("  #    # #    # #    # #         #    #  #  #  #      #   #      \n");
            sleep(1);
            printf("   ####  #    # #    # ######     ####    ##   ###### #    #\n ");
            sleep(2);
            fin();
                }
                ulti = ulti + 1;
                break;
            case 2:
                if(*batterie < 1)
                    printf("tu n'as plus de batterie\n");
                else
                {
                    printf("vous envoiez des ondes negatives sur l'ennemi\n");
                    batterie = batterie - 1;
                    pvmonstre = pvmonstre - (*attaque + 1);
                    if (pvmonstre<=0)
                    {
                        printf("victoire !!\n");
                        fin();
                    }
                    if(ulti > 3)
                    {
                        printf("le boss attaque avec son taser\n");
                        *pv = *pv - atkmonstre;
                        printf("vous perdez %d point de vie\n",damageM);
                        printf("vous etes paralyse pendant 1 tour\n",damageM);
                        paralysie = 1;
                        ulti = 0;
                    }
                    else
                    {
                        printf("le boss vous attaque\n");
                        *pv = *pv - damageM;
                        printf("vous perdez %d point de vie\n",damageM);
                    }
                        ulti = ulti + 1;
                    if(*pv < 1)
                    {
                        printf("tu as perdu, honte a toi\n");
                        printf("   ####    ##   #    # ######     ####  #    # ###### #####   \n");
                        sleep(1);
                        printf("  #    #  #  #  ##  ## #         #    # #    # #      #    #         \n");
                        sleep(1);
                        printf("  #      #    # # ## # #####     #    # #    # #####  #    #       \n");
                        sleep(1);
                        printf("  #  ### ###### #    # #         #    # #    # #      #####  \n");
                        sleep(1);
                        printf("  #    # #    # #    # #         #    #  #  #  #      #   #      \n");
                        sleep(1);
                        printf("   ####  #    # #    # ######     ####    ##   ###### #    #\n ");
                        sleep(2);
                        fin();
                    }
                }
            break;
            case 3:
                *potion = *potion - 1;
                *pv = *pv + 10;
                printf("vous gagnez 10 points de vie\n");
                if(ulti > 3)
                {
                    printf("le boss attaque avec son taser\n");
                    *pv = *pv - atkmonstre;
                    printf("vous perdez %d point de vie\n",damageM);
                    printf("vous etes paralyse pendant 1 tour\n",damageM);
                    ulti = 0;
                }
                else
                {
                    printf("le boss vous attaque\n");
                    *pv = *pv - damageM;
                    printf("vous perdez %d point de vie\n",damageM);
                }
            break;
            case 4:
                printf("Le boss vous empeche de fuir\n");
            break;
            case 5:
                printf("vous faites la sieste en plein combat\n");
                printf("l'ennemi vous attaque\n");
                *pv = *pv - atkmonstre;
                ulti = ulti + 1;
            if(*pv < 1)
            {
                printf("tu as perdu, honte a toi\n");
                printf("   ####    ##   #    # ######     ####  #    # ###### #####   \n");
                sleep(1);
                printf("  #    #  #  #  ##  ## #         #    # #    # #      #    #         \n");
                sleep(1);
                printf("  #      #    # # ## # #####     #    # #    # #####  #    #       \n");
                sleep(1);
                printf("  #  ### ###### #    # #         #    # #    # #      #####  \n");
                sleep(1);
                printf("  #    # #    # #    # #         #    #  #  #  #      #   #      \n");
                sleep(1);
                printf("   ####  #    # #    # ######     ####    ##   ###### #    #\n ");
                sleep(2);
                fin();
            }
            break;
            }
        }
    }
}


int niveau(int *x, int *y,int *lvl, int *attaque,int *defense,int *batterie,int *pv, int *name, int *xp, int *or, int *potion, int *iphone) // on l'appelle apres un combat
{
    int ajoutlvl = 50;
    *xp = *xp + 35;
    *or = *or + 10;
    int bientot = ajoutlvl - *xp;
    printf("vous obtenez 35 d'xp ainsi que 10 pieces d'or\n");
    if(*xp < ajoutlvl)
        printf("il vous manque %d d'xp pour passer au niveau suivant \n",bientot);
    while (*xp > ajoutlvl)
    {
            *lvl = *lvl + 1;
            ajoutlvl = ajoutlvl * 2 + 30;
            *attaque = *attaque + 1;
            *defense = *defense + 1;
            printf("tu passe niveau %d\n", *lvl);
    }
    deplacement(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
}

int Googlemap(int *x, int *y,int *lvl, int *attaque,int *defense,int *batterie,int *pv, int *name, int *xp, int *or, int *potion, int *iphone) // le joueur peut l'appeller en dehors d'un combat
{
    printf("un kilometre represente 1 map (1 deplacement)\n");
    if (*x == 0 && *y == 0)
    {
        printf("le boss se trouve a 5 kilometres d'ici\n");
        deplacement(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
    }
    if (*x == 0 && *y == 1)
    {
        printf("le boss se trouve a 4 kilometres d'ici\n");
        deplacement(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
    }
    if (*x == 0 && *y == 2)
    {
        printf("le boss se trouve a 3 kilometres d'ici\n");
        deplacement(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
    }
    if (*x == 0 && *y == 3)
    {
        printf("le boss se trouve a 2 kilometres d'ici\n");
        deplacement(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
    }
    if (*x == 1 && *y == 3)
    {
        printf("le boss se trouve a 1 kilometre d'ici\n");
        deplacement(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
    }
    if (*x == -1 && *y == 2)
    {
        printf("le boss se trouve a 4 kilometres d'ici\n");
        deplacement(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
    }
    if (*x == -2 && *y == 2)
    {
        printf("le boss se trouve a 5 kilometres d'ici\n");
        deplacement(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
    }
}
int deplacement(int *x, int *y,int *lvl, int *attaque,int *defense,int *batterie,int *pv, int *name, int *xp, int *or, int *potion, int *iphone) // on se deplace avec cette fonction
{
    int direction;
    printf("Que veux tu faire ?\n\n");
    printf("1. Aller  vers le nord\n");
    printf("2. Aller vers l'ouest\n");
    printf("3. Aller vers l'est\n");
    printf("4. Aller vers le sud\n");
    if(*iphone > 0)
    {
        printf("5. utiliser googlemap\n");
    }
    printf("6. Revenir au Menu principal \n");
    scanf("%d",&direction);
    switch (direction)
    {
    case 1:
        *y = *y + 1;
        carte(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
        break;
    case 2:
        *x = *x - 1;
        carte(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
        break;
    case 3:
        *x = *x + 1;
        carte(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
        break;
    case 4:
        *y = *y - 1;
        carte(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
        break;
    case 5:
        Googlemap(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
         break;
    case 6 :
        affichageMenu();
        break ;
    }


}

int carte(int *x, int *y,int *lvl, int *attaque,int *defense,int *batterie,int *pv, int *name, int *xp, int *or, int *potion, int *iphone) // on l'appelle apres un deplacement
{
    int intru = 1;
    int choix = 0;
    int choixb;
    if (*x == 0 && *y == 0)
    {
        printf("Vous etes au plein Milieu de la foret\n");
        sleep(1);
        printf("vous avez un marchand qui se trouve juste a votre droit \n");
        printf("Rendez vous  chez le marchand \n");
        sleep(1);
        printf("pieces d'or : %d \n",*or);
        printf("%s que veux tu faire ? \n\n",name);
        printf("1. acheter des potions a 10 pieces d'or\n");
        printf("2. consultez son inventaire\n");
        printf("3. s'en aller\n");
        scanf("%d",&choix);
        switch(choix)
        {
        case 1:
            if(*or<10)
            {
                printf("vous n'avez pas assez de pieces d'or\n");
                carte(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
            }
            else
            {
                printf("vous obtenez une potion\n");
                *potion = *potion + 1;
                *or = *or - 10;
                carte(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
            }
            break;
        case 2:
            while(intru = 1)
            {
                printf("%d Pieces d'or\n",*or);
                printf("Couteau x1\n");
                printf("Potion x%d\n",*potion);
                printf("Iphone x%d\n",*iphone);
                printf("hp %d\n\n",*pv);
                printf("1. Utiliser une potion\n");
                printf("2. Quitter l'inventaire\n");
                scanf("%d",&choixb);
                if(choixb == 2)
                    carte(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
                if(choixb == 1)
                {
                    if(*potion < 1)
                    {
                        printf("vous n'avez  plus de potion\n");
                    }
                    else
                    {
                        if (*pv == 50)
                        {
                            printf("vous etes au max de votre hp\n");
                            carte(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
                        }
                        *potion = *potion - 1;
                        *pv = *pv + 10;
                        if (*pv > 50)
                        {
                            *pv = 50;
                        }
                        printf("vous gagnez 10 points de vie\n");
                        printf("vous avez %d points de vie\n",*pv);
                    }
                }
            }
        case 3:
            *y = 1;
            carte(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
        break;
        }
    }
    if (*x == 0 && *y == 1)
    {
        printf("vous arrivez dans une jungle <Temple des singes>\n");
        deplacement(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
    }
    if (*x == 0 && *y == 2)
    {
        printf("vous vous deplacez toujours dans la jungle <Temple des singes>\n");
        printf("c'est quoi ce bruit!!!!!!!!!!!\n");
        sleep(1);
        printf("Un singe geant a deux tetes vous attaque \n");
        combat(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
    }
    if (*x == 0 && *y == 3)
    {
        printf("vous arrivez jungle <Temple des NTIC >\n");
        printf("Houps c'est quoi ca !!! \n");
        printf("vous avez trouve une batterie !!\n");
        *batterie = *batterie + 1;
        printf("%s met la batterie dans son inventaire\n",name);
        deplacement(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
    }
    if (*x == 1 && *y == 3)
    {
        printf("comment c'est noir ici !!");
        printf("vous arrivez dans une grotte\n");
        combat(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
    }
    if (*x == 2 && *y == 3)
    {
        printf("vous ouvrez une grande porte\n");
        printf("c'est quoi ses squellettes !!!! \n");
        printf("vous arrivez dans l'antre du boss\n");
        sleep(1);
        printf("QUI OSE ME DERANGER PENDANT MA SIESTE \n");
        printf("c'est l'heure du duel\n");
        Boss(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
        deplacement(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
    }
    if (*x == -1 && *y == 2)
    {
        printf("vous arrivez dans une zone rocheuse\n");
        printf("Attention vous pouvez glisser \n");
        deplacement(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
    }
    if (*x == -2 && *y == 2)
    {
        printf("vous arrivez dans la prairie paisible\n");
        sleep(1);
        printf ("Tiens un Sac \n");
        if(*iphone < 1)
        {
            printf("vous avez trouve un iphone !!!\n");
            *iphone = *iphone + 1;
            printf("%s met iphone dans son inventaire\n",name);
            printf("un iphone permet d'utiliser google map pour trouver le boss plus facilement\n");
            deplacement(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
        }
        else
            deplacement(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
    }
    if (*x == 0 && *y == -1)
    {
        printf("vous  ne pouvez pas aller par la\n");
        *x = 0;
        *y = 0;
        deplacement(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
    }
    if (*x == 1 && *y == 0)
    {
        printf("vous  ne pouvez pas aller par la\n");
        *x = 0;
        *y = 0;
        deplacement(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
    }
    if (*x == -1 && *y == 0)
    {
        printf("vous  ne pouvez pas aller par la\n");
        *x = 0;
        *y = 0;
        deplacement(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
    }
    if (*x == 1 && *y == 1)
    {
        printf("vous  ne pouvez pas aller par la\n");
        *x = 0;
        *y = 1;
        deplacement(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
    }
    if (*x == -1 && *y == 1)
    {
        printf("tu ne peux pas aller par la\n");
        *x = 0;
        *y = 1;
        deplacement(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
    }
    if (*x == 1 && *y == 2)
    {
        printf("vous  ne pouvez pas aller par la\n");
        *x = 0;
        *y = 2;
        deplacement(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
    }
    if (*x == -2 && *y == 1)
    {
        printf("vous  ne pouvez pas aller par laa\n");
        *x = -2;
        *y = 2;
        deplacement(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
    }
    if (*x == -3 && *y == 2)
    {
        printf("vous  ne pouvez pas aller par la\n");
        *x = -2;
        *y = 2;
        deplacement(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
    }
    if (*x == -2 && *y == 3)
    {
        printf("vous  ne pouvez pas aller par la\n");
        *x = -2;
        *y = 2;
        deplacement(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
    }
    if (*x == -1 && *y == 3)
    {
        printf("vous  ne pouvez pas aller par la\n");
        *x = -1;
        *y = 2;
        deplacement(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
    }
    if (*x == 0 && *y == 4)
    {
        printf("vous  ne pouvez pas aller par la\n");
        *x = 0;
        *y = 3;
        deplacement(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
    }
    if (*x == 1 && *y == 4)
    {
        printf("vous  ne pouvez pas aller par la\n");
        *x = 1;
        *y = 3;
        deplacement(x,y,lvl,attaque,defense,batterie,pv,name,xp,or,potion,iphone);
    }
}
int fin()
{
    printf("Merci d'avoir jouer\n\n");
    printf("Mettez nous un A svp");
    exit(0);
}

