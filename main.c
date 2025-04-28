#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int i, j, k;

typedef struct
{
    char telepules[3];
    int ora;
    int perc;
    char irany[4];
    int sebesseg;
    int homerseklet;
} adat_elem;

typedef adat_elem adat_tomb[500];

typedef struct
{
    char nev[3];
    int legnagyobb;
    int legkisebb;
    int osszes;
    int hany_adat;
    int egy;
    int ketto;
    int harom;
    int negy;
    int kozephomerseklet;
} varos_adat;

typedef varos_adat varos_tomb[20];

void feladat1(adat_elem *homerseklet_adatai, int *sorok_szama, varos_adat *varos_adatai, int *varosok_szama)
{
    FILE *f = fopen("tavirathu13.txt", "r");
    i = 0;
    *varosok_szama = 0;
    while (!feof(f))
    {
        fscanf(f, "%s %2d%2d %3s%2d %d\n", homerseklet_adatai[i].telepules, &homerseklet_adatai[i].ora, &homerseklet_adatai[i].perc, homerseklet_adatai[i].irany, &homerseklet_adatai[i].sebesseg, &homerseklet_adatai[i].homerseklet);
        //printf("%s %02d:%02d %s %02d %d\n", homerseklet_adatai[i].telepules, homerseklet_adatai[i].ora, homerseklet_adatai[i].perc, homerseklet_adatai[i].irany, homerseklet_adatai[i].sebesseg, homerseklet_adatai[i].homerseklet);

        for (j = 0; j < *varosok_szama; j++)
        {
            if (!strcmp(varos_adatai[j].nev, homerseklet_adatai[i].telepules))
            {
                break;
            }
        }
        if (j == *varosok_szama)
        {
            strcpy(varos_adatai[j].nev, homerseklet_adatai[i].telepules);
            (*varosok_szama)++;
        }

        i++;
    }
    *sorok_szama = i;
    //printf("\n%d\n", *sorok_szama);
    fclose(f);
}

void feladat2(adat_elem *homerseklet_adatai, int sorok_szama)
{
    char bekert_telepules[3];
    printf("2. feladat\nAdja meg egy telepules kodjat! Telepules: ");
    scanf("%s", bekert_telepules);
    for (i = sorok_szama; i > 0; i--)
    {
        if (!strcmp(bekert_telepules, homerseklet_adatai[i].telepules))
        {
            printf("Az utolso meresi adat a megadott telepulesrol  %02d:%02d-kor erkezett.", homerseklet_adatai[i].ora, homerseklet_adatai[i].perc);
            break;
        }
    }
}
void feladat3(adat_elem *homerseklet_adatai, int sorok_szama)
{
    int legalacsonyabb = 50, legmagasabb = 0;
    for (i = 0; i < sorok_szama; i++)
    {
        if (homerseklet_adatai[i].homerseklet > legmagasabb)
        {
            legmagasabb = homerseklet_adatai[i].homerseklet;
        }
        if (homerseklet_adatai[i].homerseklet < legalacsonyabb)
        {
            legalacsonyabb = homerseklet_adatai[i].homerseklet;
        }
    }
    printf("\n3. feladat");
    for (i = 0; i < sorok_szama; i++)
    {
        if (homerseklet_adatai[i].homerseklet == legalacsonyabb)
        {
            printf("\nA legalacsonyabb homerseklet: %s %02d:%02d %d fok.", homerseklet_adatai[i].telepules, homerseklet_adatai[i].ora, homerseklet_adatai[i].perc, legalacsonyabb);
            break;
        }
    }
    for (i = 0; i < sorok_szama; i++)
    {
        if (homerseklet_adatai[i].homerseklet == legmagasabb)
        {
            printf("\nA legmagasabb homerseklet: %s %02d:%02d %d fok.", homerseklet_adatai[i].telepules, homerseklet_adatai[i].ora, homerseklet_adatai[i].perc, legmagasabb);
            break;
        }
    }
}

void feladat4(adat_elem *homerseklet_adatai, int sorok_szama)
{
    int szelcsend = 1;
    printf("\n4. feladat");
    for (i = 0; i < sorok_szama; i++)
    {
        if (!strcmp(homerseklet_adatai[i].irany, "000") && homerseklet_adatai[i].sebesseg == 0)
        {
            printf("\n%s %02d:%02d", homerseklet_adatai[i].telepules, homerseklet_adatai[i].ora, homerseklet_adatai[i].perc);
        }
        szelcsend = 0;
    }
    if (szelcsend)
    {
        printf("\nNem volt szelcsend a meresek idejen.");
    }
}

void feladat5(adat_elem *homerseklet_adatai, int sorok_szama, varos_adat *varos_adatai, int varosok_szama)
{
    for (j = 0; j < varosok_szama; j++)
    {
        varos_adatai[j].legkisebb = 50;
        //printf("\n%s %d %d", varos_adatai[j].nev, varos_adatai[j].legkisebb, varos_adatai[j].legnagyobb);
    }
    for (j = 0; j < varosok_szama; j++)
    {
        for (i = 0; i < sorok_szama; i++)
        {
            if (!strcmp(homerseklet_adatai[i].telepules, varos_adatai[j].nev))
            {
                if (varos_adatai[j].legkisebb > homerseklet_adatai[i].homerseklet)
                {
                    varos_adatai[j].legkisebb = homerseklet_adatai[i].homerseklet;
                }
                if (varos_adatai[j].legnagyobb < homerseklet_adatai[i].homerseklet)
                {
                    varos_adatai[j].legnagyobb = homerseklet_adatai[i].homerseklet;
                }


                if (homerseklet_adatai[i].ora == 1 || homerseklet_adatai[i].ora == 7 || homerseklet_adatai[i].ora == 13 || homerseklet_adatai[i].ora == 19)
                {
                    varos_adatai[j].osszes += homerseklet_adatai[i].homerseklet;
                    varos_adatai[j].hany_adat++;
                    switch (homerseklet_adatai[i].ora)
                    {
                    case 1:
                        varos_adatai[j].egy = 1;
                        break;
                    case 7:
                        varos_adatai[j].ketto = 1;
                        break;
                    case 13:
                        varos_adatai[j].harom = 1;
                        break;
                    case 19:
                        varos_adatai[j].negy = 1;
                        break;
                    }
                }
            }
        }
        varos_adatai[j].kozephomerseklet = varos_adatai[j].osszes / varos_adatai[j].hany_adat;
        if (varos_adatai[j].osszes % varos_adatai[j].hany_adat >= 5)
        {
            varos_adatai[j].kozephomerseklet++;
        }
    }
    printf("\n5. feladat");
    for (j = 0; j < varosok_szama; j++)
    {
        printf("\n%s ", varos_adatai[j].nev);
        if (varos_adatai[j].egy == 0 || varos_adatai[j].ketto == 0 || varos_adatai[j].harom == 0 || varos_adatai[j].negy == 0)
        {
            printf("NA; ");
        }
        else
        {
            printf("Kozephomerseklet: %02d; ", varos_adatai[j].kozephomerseklet);
        }
        printf("Homerseklet-ingadozas: %d", varos_adatai[j].legnagyobb - varos_adatai[j].legkisebb);
    }
}

void feladat6(adat_elem *homerseklet_adatai, int sorok_szama, varos_adat *varos_adatai, int varosok_szama)
{
    char fajl_nev[8];
    for (j = 0; j < varosok_szama; j++)
    {
        strcpy(fajl_nev, varos_adatai[j].nev);
        strcat(fajl_nev, ".txt");
        FILE *f = fopen(fajl_nev, "w");
        fprintf(f, "%s\n", varos_adatai[j].nev);
        for (i = 0; i < sorok_szama; i++)
        {
            if (!strcmp(varos_adatai[j].nev, homerseklet_adatai[i].telepules))
            {
                fprintf(f, "%02d:%02d ", homerseklet_adatai[i].ora, homerseklet_adatai[i].perc);
                for (k = 0; k < homerseklet_adatai[i].sebesseg; k++)
                {
                    fprintf(f, "#");
                }
                fprintf(f, "\n");
            }
        }
        fclose(f);
    }
    printf("\n6. feladat\nA fajlok elkeszultek.");
}

int main()
{
    adat_tomb homerseklet_adatai = {0};
    varos_tomb varos_adatai = {0};
    int sorok_szama, varosok_szama;
    feladat1(homerseklet_adatai, &sorok_szama, varos_adatai, &varosok_szama);
    feladat2(homerseklet_adatai, sorok_szama);
    feladat3(homerseklet_adatai, sorok_szama);
    feladat4(homerseklet_adatai, sorok_szama);
    feladat5(homerseklet_adatai, sorok_szama, varos_adatai, varosok_szama);
    feladat6(homerseklet_adatai, sorok_szama, varos_adatai, varosok_szama);
    return 0;
}
