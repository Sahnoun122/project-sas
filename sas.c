#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define Depatement1 "Math"
#define Depatement2 "Physique"
#define Depatement3 "Informatique"
#define Depatement4 "Economie"
#define Depatement5 "Francais"
#define maxstudent 100

#define namelong 50
#define departmrntlong 60


typedef struct{
    int jour, mois, annee;
} datenaissance;

typedef struct {
    int identite;
    char name[namelong];
    char prenome[namelong];
    datenaissance date;
    char department[departmrntlong];
    float generalnote;
} student;

student studs[maxstudent];
int studentcompte = 0;

void ajoutestudent() {
    if (studentcompte >= maxstudent) {
        printf("Depassement du nombre maximum d'etudiants.\n");
        return;
    }
    student nouvestudent;
    printf("entrez le numero unique: ");
    scanf("%d", &nouvestudent.identite);
    printf("entrez le nom: ");
    scanf("%s", nouvestudent.name);
    printf("entrez le prenom: ");
    scanf("%s", nouvestudent.prenome);
    printf("entrez la date de naissance (dd/mm/yyyy): ");
    scanf("%s", nouvestudent.date);
    printf("entrez le departement: ");
    scanf("%s", nouvestudent.department);
    printf("entrez la note generale: ");
    scanf("%f", &nouvestudent.generalnote);
    studs[studentcompte++] = nouvestudent;
    printf("Étudiant ajouté avec succès.\n");
};

void remplirtableau() {
    if (studentcompte >= maxstudent) {
        printf("Le tableau d'etudiants est deja plein.\n");
        return;
    }

    student exemplestudent[4] = {
        {1, "mohamed", "sahnoun", {15, 5, 2000}, Depatement1, 12.5},
        {2, "rihab ", "dadache", {22, 11, 1999}, Depatement2, 8.0},
        {3, "souhaib", "benka", {3, 8, 1998}, Depatement3, 14.0},
        {4, "mohamed", "tawdi", {10, 3, 2001}, Depatement4, 9.5},
        {5, "imran", "barada", {25, 12, 2000}, Depatement5, 11.0},
    };

    int nombrestudent = sizeof(exemplestudent) / sizeof(exemplestudent[0]);

    for (int i = 0; i < nombrestudent; i++) {
        if (studentcompte < maxstudent) {
            studs[studentcompte++] = exemplestudent[i];
        } else {
            printf("Nombre maximum d'etudiants atteint.\n");
            break;
        }
    }

    printf("Tableau d'etudiants rempli avec des donnees d'exemple.\n");
}


void modifierstudent(int identite) {
    for (int i = 0; i < studentcompte; i++) {
        if (studs[i].identite == identite) {
            printf("entrez le nouveau nom: ");
            scanf("%s", studs[i].name);
            printf("entrez le nouveau prenom: ");
            scanf("%s", studs[i].prenome);
            printf("entrez la nouvelle date de naissance (dd/mm/yyyy): ");
            scanf("%s", studs[i].date);
            printf("entrez le nouveau departement: ");
            scanf("%s", studs[i].department);
            printf("entrez la nouvelle note generale: ");
            scanf("%f", &studs[i].generalnote);
            printf("etudiant modifie avec succes.\n");
            return;
        }
    }
    printf("etudiant non trouve.\n");
}

void supprimerstudent(int identite) {
    for (int i = 0; i < studentcompte; i++) {
        if (studs[i].identite == identite) {
            for (int j = i; j < studentcompte - 1; j++) {
                studs[j] = studs[j + 1];
            }
            studentcompte--;
            printf("etudiant supprime avec succes.\n");
            return;
        }
    }
    printf("Étudiant non trouvé.\n");
}



void affichedeatails(int identite) {
    for (int i = 0; i < studentcompte; i++) {
        if (studs[i].identite == identite) {
            printf("Numero unique: %d\n", studs[i].identite);
            printf("Nom: %s\n", studs[i].name);
            printf("Prenom: %s\n", studs[i].prenome);
            printf("Date de naissance: %s\n", studs[i].date);
            printf("Departement: %s\n", studs[i].department);
            printf("Note generale: %.2f\n", studs[i].generalnote);
            return;
        }
    }
    printf("etudiant non trouve.\n");
}



void calculemoyene() {
    char department[departmrntlong];
    printf("entrez le nom du departement: ");
    scanf("%s", department);

    float somme = 0;
    int compte = 0;

    for (int i = 0; i < studentcompte; i++) {
        if (strcmp(studs[i].department, department) == 0) {
            somme += studs[i].generalnote;
            compte++;
        }
    }

    if (compte > 0) {
        printf("La moyenne générale pour le departement %s est: %.2f\n", department, somme / compte);
    } else {
        printf("Aucun etudiant trouve dans le departement.\n");
    }
}

void calculeunivirsite() {
    float somme = 0;
    for (int i = 0; i < studentcompte; i++) {
        somme += studs[i].generalnote;
    }
    printf("La moyenne generale pour l'universite est: %.2f\n", studentcompte > 0 ? somme / studentcompte : 0);
}

void totalstudent() {
    printf("Nombre total d'etudiants inscrits: %d\n", studentcompte);
}

void studensdansdepartment() {
    char departments[maxstudent][departmrntlong];
    int departmentcompte[maxstudent] = {0};
    int nomdepartment = 0;

    for (int i = 0; i < studentcompte; i++) {
        int trouve = 0;

        for (int j = 0; j < nomdepartment; j++) {
            if (strcmp(studs[i].department, departments[j]) == 0) {
                departmentcompte[j]++;
                trouve = 1;
                break;
            }
        }

        if (!trouve) {
            strcpy(departments[nomdepartment], studs[i].department);
            departmentcompte[nomdepartment]++;
            nomdepartment++;
        }
    }

    for (int i = 0; i < nomdepartment; i++) {
        printf("Nombre d'etudiants dans le departement %s: %d\n", departments[i], departmentcompte[i]);
    }
}

void affichebonstudent(float bonne) {
    printf("etudiants ayant une note generale superieure à %.2f:\n", bonne);
    for (int i = 0; i < studentcompte; i++) {
        if (studs[i].generalnote > bonne) {
            affichedeatails(studs[i].identite);
        }
    }
}

void afficher3student() {
    for (int i = 0; i < studentcompte - 1; i++) {
        for (int j = i + 1; j < studentcompte; j++) {
            if (studs[i].generalnote < studs[j].generalnote) {
                student temp = studs[i];
                studs[i] = studs[j];
                studs[j] = temp;
            }
        }
    }

    int topcompte = studentcompte < 3 ? studentcompte : 3;
    printf("Les 3 etudiants ayant les meilleures notes:\n");
    for (int i = 0; i < topcompte; i++) {
        affichedeatails(studs[i].identite);
    }
}

void studentressir() {
    char departments[maxstudent][departmrntlong];
    int passecompte[maxstudent] = {0};
    int nomdepartment = 0;

    for (int i = 0; i < studentcompte; i++) {
        if (studs[i].generalnote >= 10) {
            int trouve = 0;

            for (int j = 0; j < nomdepartment; j++) {
                if (strcmp(studs[i].department, departments[j]) == 0) {
                    passecompte[j]++;
                    trouve = 1;
                    break;
                }
            }

            if (!trouve) {
                strcpy(departments[nomdepartment], studs[i].department);
                passecompte[nomdepartment]++;
                nomdepartment++;
            }
        }
    }

    for (int i = 0; i < nomdepartment; i++) {
        printf("Nombre d'etudiants ayant reussi dans le departement %s: %d\n", departments[i], passecompte[i]);
    }
}

void statistiquer() {
    int choiix;
    float bonne;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Afficher le nombre total d'etudiants inscrits\n");
        printf("2. Afficher le nombre d'etudiants dans chaque departement\n");
        printf("3. Afficher les etudiants ayant une moyenne generale superieure à un seuil\n");
        printf("4. Afficher les 3 etudiants ayant les meilleures notes\n");
        printf("5. Afficher le nombre d'etudiants ayant reussi dans chaque departement\n");
        printf("6. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choiix);

        switch (choiix) {
            case 1:
                totalstudent();
                break;
            case 2:
                studensdansdepartment();
                break;
            case 3:
                printf("Entrez le seuil de note: ");
                scanf("%f", &bonne);
                affichebonstudent(bonne);
                break;
            case 4:
                afficher3student();
                break;
            case 5:
                studentressir();
                break;
            case 6:
                return; // Quitter la fonction de statistiques
            default:
                printf("Choix invalide.\n");
        }
    }
}

void recherchparnom(char* name) {
    int trouve = 0;
    for (int i = 0; i < studentcompte; i++) {
        if (strcmp(studs[i].name, name) == 0) {
            affichedeatails(studs[i].identite);
            trouve = 1;
        }
    }
    if (!trouve) {
        printf("Aucun etudiant trouve avec le nom %s.\n", name);
    }
}

void listpardepartment(char* department) {
    int trouve = 0;
    for (int i = 0; i < studentcompte; i++) {
        if (strcmp(studs[i].department, department) == 0) {
            affichedeatails(studs[i].identite);
            trouve = 1;
        }
    }
    if (!trouve) {
        printf("Aucun etudiant trouve dans le departement %s.\n", department);
    }
}

void rechercheetud() {
    int choiix;
    char name[namelong];
    char department[departmrntlong];

    while (1) {
        printf("1. rechercher un etudiant par son nom\n");
        printf("2. afficher la liste des etudiants inscrits dans un departement specifique\n");
        printf("Choix: ");
        scanf("%d", &choiix);
        getchar();

        switch (choiix) {
            case 1:
                printf("entrez le nom de l'etudiant: ");
                fgets(name, namelong, stdin);
                name[strcspn(name, "\n")] = '\0';
                recherchparnom(name);
                break;
            case 2:
                printf("entrez le departement: ");
                fgets(department, departmrntlong, stdin);
                department[strcspn(department, "\n")] = '\0';
                listpardepartment(department);
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    }
}

void trinumecroissant() {
    for (int i = 0; i < studentcompte - 1; i++) {
        for (int j = i + 1; j < studentcompte; j++) {
            if (strcmp(studs[i].name, studs[j].name) > 0) {
                student temp = studs[i];
                studs[i] = studs[j];
                studs[j] = temp;
            }
        }
    }
    printf("etudiants tries par nom (A à Z).\n");
}

void trinumdecroissant() {
    for (int i = 0; i < studentcompte - 1; i++) {
        for (int j = i + 1; j < studentcompte; j++) {
            if (strcmp(studs[i].name, studs[j].name) < 0) {
                student temp = studs[i];
                studs[i] = studs[j];
                studs[j] = temp;
            }
        }
    }
    printf("etudiants tries par nom (Z à A).\n");
}

void trinotedecroissant() {
    for (int i = 0; i < studentcompte - 1; i++) {
        for (int j = i + 1; j < studentcompte; j++) {
            if (studs[i].generalnote < studs[j].generalnote) {
                student temp = studs[i];
                studs[i] = studs[j];
                studs[j] = temp;
            }
        }
    }
    printf("etudiants tries par note generale (du plus eleve au plus faible).\n");
}

void trinotcroissant() {
    for (int i = 0; i < studentcompte - 1; i++) {
        for (int j = i + 1; j < studentcompte; j++) {
            if (studs[i].generalnote > studs[j].generalnote) {
                student temp = studs[i];
                studs[i] = studs[j];
                studs[j] = temp;
            }
        }
    }
    printf("etudiants tries par note generale (du plus faible au plus eleve).\n");
}

void trireussirdecroissant() {
    for (int i = 0; i < studentcompte - 1; i++) {
        for (int j = i + 1; j < studentcompte; j++) {
            if ((studs[i].generalnote >= 10 && studs[j].generalnote < 10) ||
                (studs[i].generalnote >= 10 && studs[j].generalnote >= 10 &&
                studs[i].generalnote < studs[j].generalnote)) {
                student temp = studs[i];
                studs[i] = studs[j];
                studs[j] = temp;
            }
        }
    }
    printf("etudiants tries par statut de reussite (note >= 10).\n");
}

void tristudent() {
    int choiix;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Trier les etudiants par nom (A à Z)\n");
        printf("2. Trier les etudiants par nom (Z à A)\n");
        printf("3. Trier les etudiants par moyenne generale (du plus eleve au plus faible)\n");
        printf("4. Trier les etudiants par moyenne generale (du plus faible au plus eleve)\n");
        printf("5. Trier les etudiants par statut de reussite\n");
        printf("6. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choiix);
        getchar();

        switch (choiix) {
            case 1:
                trinumecroissant();
                break;
            case 2:
                trinumdecroissant();
                break;
            case 3:
                trinotedecroissant();
                break;
            case 4:
                trinotcroissant();
                break;
            case 5:
                trireussirdecroissant();
                break;
            case 6:
                return; // Quitter la fonction de tri
            default:
                printf("Choix invalide. Veuillez ressayer.\n");
        }
    }
}

  void afficher(){
        for(int i=0;i<4;i++){

            printf("nom: %s\n" ,studs[i].name);

            printf("prenom: %s\n" ,studs[i].prenome);
            printf("date de naissance (dd/mm/yyyy): %d %d %d\n" ,studs[i].date.jour, studs[i].date.mois, studs[i].date.annee);

            printf("departement: %s\n",studs[i].department);

            printf("note generale: %.2f\n",studs[i].generalnote);
            printf("--------------------------------\n");
      };

};
void menuu(){
    int choiix;
    int identite;
    char name[namelong];
    char department[departmrntlong];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Ajouter un etudiant\n");
        printf("2. Afficher les etudiants \n");
        printf("3. Modifier un etudiant\n");
        printf("4. Supprimer un etudiant\n");
        printf("5. Afficher les details d'un etudiant\n");
        printf("6. Calculer la moyenne generale de chaque departement et de l'universite\n");
        printf("7. Afficher les Statistiques\n");
        printf("8. Rechercher un etudiant par\n");
        printf("9. Trier les etudiants\n");
        printf("10. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choiix);
        getchar();

        switch (choiix) {
            case 1:
                ajoutestudent();
                break;
            case 2:
                afficher();
                break;
            case 3:
                printf("entrez le numero unique de l'etudiant à modifier: ");
                scanf("%d", &identite);
                modifierstudent(identite);
                break;
            case 4:
                printf("entrez le numero unique de l'etudiant à supprimer: ");
                scanf("%d", &identite);
                supprimerstudent(identite);
                break;
            case 5:
                printf("entrez le numero unique de l'etudiant: ");
                scanf("%d", &identite);
                affichedeatails(identite);
                break;
            case 6:
                calculemoyene();
                break;
            case 7:
                statistiquer();
                break;
            case 8:
                rechercheetud();
                break;
            case 9:
                tristudent();
                break;
            case 10:
                printf("Quitter le programme.\n");
            default:
                printf("Choix invalide. Veuillez ressayer.\n");
        }
    }

};



int main() {



    remplirtableau();
   menuu();


    return 0;
}
