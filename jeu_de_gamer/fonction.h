void showStartMessage();
int affichageMenu();//Ecran d'accueil et choix jouer charger etc
int GameStart();
int deplacement(int *x, int *y,int *lvl, int *attaque,int *defense,int *batterie,int *pv, int *name, int *xp, int *or, int *potion, int *iphone); // permet se deplacer sur la carte
int carte(int *x, int *y,int *lvl, int *attaque,int *defense,int *batterie,int *pv, int *name, int *xp, int *or, int *potion, int *iphone); // donne la position du joueur
int Googlemap(int *x, int *y,int *lvl, int *attaque,int *defense,int *batterie,int *pv, int *name, int *xp, int *or, int *potion, int *iphone); // permet de connaitre la distance entre le joueur et le boss
int niveau(int *x, int *y,int *lvl, int *attaque,int *defense,int *batterie,int *pv, int *name, int *xp, int *or, int *potion, int *iphone); // fonction qui fais passer de niveau apres les combats
int combat(int *x, int *y,int *lvl, int *attaque,int *defense,int *batterie,int *pv, int *name, int *xp, int *or, int *potion, int *iphone);
int Boss(int *x, int *y,int *lvl, int *attaque,int *defense,int *batterie,int *pv, int *name, int *xp, int *or, int *potion, int *iphone);
int fin();
