#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	printf(" * SPANZURATOAREA*\n");
 	printf("   _________     \n");
    printf("  |         |    \n");
    printf("  |         0    \n");
    printf("  |        /|\\  \n");          //text cool
    printf("  |        / \\  \n");
    printf("  |              \n\n\n");
    printf("* Apasa enter pentru a continua *\n");
    getchar();                      //asteapta enter pentru a continua
    printf("    * Jucator 1: *\n");
    printf("  * Dati propozitia *\n");
    char prop[1024], prop2[1024];               //declar vectorii pt cuvinte / propozitii
    int litere[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};       //vector care arata dc o litera a fost folosita
    int i, gasit, stop, desen=0;        //mai declar niste variabile
    char img[8][18]={"   _________     ",
    			  	 "  |         |    ",
    				 "  |         0    ",
    				 "  |        /|\\  ",       //grafica care apare dc gresesti
    				 "  |        / \\  ",
    				 "  |             ",
    				 "  |             ",
    				 "  |             "};
    char img2[8][18]={"  _________ ",
    			  	 "  |         |",
    				 "  |",
    				 "  |",
    				 "  |",
    				 "  |",
    				 "  |",
    				 "  |"};
    fgets(prop,1024,stdin);             //citesc cuv/prop
    for(i=0;i<strlen(prop);i++)
    {
    	if(prop[i]==' ')
    		prop2[i]=' ';             //unde este spatiu pun in vec 2 ' ' iar unde este o litera pun '-'
    	else prop2[i]='-';
    	if(prop[i]>96)
    		prop[i]=prop[i]-32;       //transform literele mari in litere mici
    }
    prop2[strlen(prop2)]='\n';      //pun '\n' pentru a putea afisa cu printf
    printf("%s\n",prop2);           //afisez vec2 care este 'cenzurat'

    char lit;   //in variabila asta citesc litera de la tast

    while(desen<7){             //cat timp nu ai gresit de 7 ori jocul continua
    gasit=0;    //in variabila asta retin dc sa gasit sau nu litera
    stop=0;        //in variabila asta retin cate litee mai am de gasit
    for(i=0; i<strlen(prop2); i++)
    	if(prop2[i]=='-')          //numar cate litere mai am de gasit
    		stop++;
    if(stop==0)     //dc nu mai am nici o litera de gasit opresc jocul
    	break;
    system("clear");        //elibereaza ecran ul
    printf("  * Este randul jucatorul-ui 2 *\n\n");
    printf("* Mai ai %d incercari\n",7-desen);      //spune cate incercari mai ai
    if(desen!=0)        //dc ai greseli afiseaza desen ul
    for(i=0; i<8; i++)
    	{
    		if(i<=desen)
    		printf("%s\n",img[i]);
    	else printf("%s\n",img2[i]);
    	}


    printf("%s\n",prop2);       //afiseaza textul 'cenzurat'
    printf("* Da litera:");        //cere litera
    scanf("%c",&lit);             //citeste litera
    if(lit>96)          //dc e litera mica o transforma in litera mare
    	lit=lit-32;
    if(litere[lit-65]==0)       //dc litera a mai fost introdusa nu o mai cauta
    {
    	for(i=0;i<strlen(prop);i++)
    	if(prop[i]==lit)               //cauta litera
    	{
    		gasit++;          //dc o gaseste incrementeaza
    		prop2[i]=prop[i];  //cand o gaseste 'decenzureaza' textul din vec2
    	}
    if(gasit==0)    //dc litera nu a fost gasita scade numarul de incercari ramare
    	desen++;
	}
	litere[lit-65]++;      //dc gaseste numara de cate ori a gasit o
	}
	system("clear");       //elibereaza ecran ul
	printf("Propozitia era: %s",prop);         //afiseaza prop originala
	if(desen==7)
		printf("* Ai pierdut! *\n");          //dc nu mai ai incercari ai pierdut altfel ai castigat
	else printf("* Ai castigat! *\n");
	return 0;
}
