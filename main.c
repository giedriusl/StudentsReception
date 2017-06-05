#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include "deque.h"
#include "bigInteger.h"
#define BUFSIZE 10
//Pradiniai duomenys: darbuotuoju produktyvumas, stojanciojo atejimo tikimybe, dokumentu priemimo laikas.
//Rezultatai: papildomas darbo laikas (tvarkymui), darbuotoju uzimtumas procentais.
//Tikslas: patyrineti, kiek laiko reikia skirti prasymu tvarkymui, pasibaigus ju priemimui.

FILE* reader();
void errors(int);

int main()
{
    int err = 0;
    struct deque_struct* applications = NULL;
    applications = createEmpty(applications);

    float probability;
    int secondEmployee;
    int firstEmployee;
    int timeForReception;

    FILE* fr = reader();

    fscanf(fr,"%d",&firstEmployee);
    fscanf(fr,"%d",&secondEmployee);
    fscanf(fr,"%f",&probability);
    fscanf(fr,"%d",&timeForReception);

    int ran;
    int accepted;
    time_t t;
    double randomNo;
    int sum = 0;
    float busyness;

    int freeTime = 0;


    srand((unsigned) time(&t));
    int id = 1;


    while(sum <= timeForReception)
    {
        ran = rand() % 5 + 1;       //po 2 studentus gali ateiti tarp 1-5 minuciu
        sum += ran;

        randomNo = (double)rand() / (double)((unsigned)RAND_MAX + 1);
        if(randomNo <= probability)
        {
            pushBeg(applications,id++); //idejus elementa jis iskart padideja vienetu
        } else
        {
            freeTime++;
        }
        randomNo = (double)rand() / (double)((unsigned)RAND_MAX + 1);
        if(randomNo <= probability)
        {
            pushEnd(applications,id++); //idejus elementa jis iskart padideja vienetu
        } else
        {
            freeTime++;
        }
    }

    accepted = getCount(applications);

    printf("accepted: %d\n",accepted);
    int extraTime = 0 - freeTime;

    while(checkEmpty(applications) == false)
    {
        delBeg(applications, &err);
        extraTime += firstEmployee;  //pirmoji darbuotoja

        if(checkEmpty(applications) == false)
        {
            delEnd(applications, &err);
            extraTime += secondEmployee; //antra darbuotoja

            if(err > 0 && err < 10)
            {
                errors(err);
                return 0;
            }
        } else
        {
            break;
        }
    }

    if(extraTime < 0)
    {
        freeTime = (-1) * extraTime;
        busyness = 100 - (freeTime * 100 / timeForReception);
        int resultOfBusyness = (int)roundf(busyness);
        printf("Busyness: %d proc.\n", resultOfBusyness);
        printf("Free time: %d min\n", freeTime);

    } else
    {
        busyness = 100;
        int resultOfBusyness = (int)roundf(busyness);
        printf("Busyness: %d proc.\n", resultOfBusyness);
        printf("Extra time: %d min\n", extraTime);
    }

    close(fr);
    return 0;
}

FILE* reader()
{
    FILE* fr = NULL;
    fr = fopen("data.txt","r");
    if(fr == NULL)
    {
        errors(1);
    }
    return fr;
}


void errors(int err)
{
    switch(err)
    {
        case 1 :
            printf("Error occured. Error code : %d",err);
            break;
        default :
            printf("Error occured. Error code: unkwnown");
    }
}
