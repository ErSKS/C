#include<stdio.h>
#include<conio.h>
typedef struct{
 char name[30];
 int id;
 float salary;
}employee;

int main()
{
 int n,i,j;
 FILE *fptr;
 employee e[10], temp;
 /* Opening file in write-binary read mode */
 fptr = fopen("empSort.txt","wb+");
 if(fptr == NULL){
  printf("File error!");
  //exit(1);
  getch();
 }
 printf("Enter how many records: ");
 scanf("%d",&n);

 /* Reading from console and storing them in structure array */
 for(i=0;i < n;i++){
 	printf("Enter Name, ID & Salary of Employee#%d: ", i+1);
 	scanf("%s%d%f",e[i].name, &e[i].id, &e[i].salary);
  	fwrite(&e[i],sizeof(e[i]),1, fptr); //Writing info. to File
 }
 rewind(fptr);
 /* Reading from file and storing them in structure array */
 for(i=0;i < n;i++){
  fread(&e[i],sizeof(e[i]),1, fptr);
 }
 /* Sorting */
 for(i=0;i< n-1;i++){
  for(j=i+1;j< n;j++){
   if(e[i].salary>e[j].salary){
    temp = e[i];
    e[i] = e[j];
    e[j] = temp;
   }
  }
 }
 /* Displaying sorted list */
 printf("\nSorted (by Salary) List:\n");
 for(i=0;i< n;i++){
  printf("Name = %-20sID = %-8dSalary = %.2f\n",e[i].name, e[i].id, e[i].salary);
 }
 fclose(fptr);
 getch();
 return 0;
}
