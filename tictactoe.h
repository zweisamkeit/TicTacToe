void clear(void);
void accueil(char pseudo1[128], char pseudo2[128], char *symbole1, char *symbole2);
void initialisation(char plateau[3][3]);
void jouer(char plateau[3][3], int num, char pseudo1[128], char pseudo2[128], char symbole1, char symbole2);
void afficher(char plateau[3][3]);
int gagne(char plateau[3][3], char symbole1, char symbole2);
void vide_buffer(void);
int main(void);
