#include<stdio.h>
#include<conio.h>
typedef struct Etudiant{
        char nom[20];
        int  age;
        float note;
      }ETU;

main(){
 FILE *f;
 ETU E[20];
 int i,n;
f=fopen("INFORM.txt","w");
printf("Donnez le nombre des etudiants:");
scanf("%d",&n);
for (i=0;i<n;i++){
  printf("Donnez le nom de l'etudiant %d",i+1);
  scanf("%s",E[i].nom);
  fprintf(f,"le nom de l'etudiant %d est %s :",i+1,E[i].nom);
  
  printf("Donnez l'age de l'etudiant %d",i+1);
  scanf("%d",&E[i].age);
  fprintf(f,"l'age de l'etudiant %d est %s :",i+1,E[i].nom);
    
  printf("Donnez la note de l'etudiant %d",i+1);
  scanf("%f",&E[i].note);
  fprintf(f,"le nom de l'etudiant %d est %s :",i+1,E[i].nom);
   
    }
getch();
}
      
       
       

