    /***************************************************************************************************************************************************
    *Program to solve Birthday Paradox
    *Author : Jp   
    ***************************************************************************************************************************************************/
    
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <conio.h>
    
    char **bday_mon;
    int *bday,no_of_people,success_trials=0;
    FILE *trial_result;
    
    int number_of_days_in_month(int);
    void compare_bdays(int);
    void print_bdays(int);
    
    int main(){
       
       int i,n;
       int dd,mm,trials;
       time_t t;   
       float prob_success;
       char mon[][4]={"Jan",
                      "Feb",
                      "Mar",
                      "Apr",
                      "May",
                      "Jun",
                      "Jul",
                      "Aug",
                      "Sep",
                      "Oct",
                      "Nov",
                      "Dec"
                      };   
       /*Opening file Birthday Paradox Trial Results.xls to track trails in each run*/
       trial_result=fopen("Birthday Paradox Trial Results.xls","a+");
        
       /* Intializes random number generator */
       srand((unsigned) time(&t));
       
       printf("*****************Birthday Paradox*****************\n\n");
       
       /*Number of people in a room*/
       printf("Enter number of people in room : ");
       scanf("%d",&no_of_people);
       
       /*Number of trials*/
       printf("\nEnter number of trials : ");
       scanf("%d",&trials);
                    
       /*Write Results to Birthday Paradox Trial Results.xls*/
       fprintf(trial_result,"***********************Start of run***********************\n");
       fprintf(trial_result,"Number of people in room = %d\n",no_of_people);
       fprintf(trial_result,"Number of Trials = %d\n",trials);
      
        
       /*allocating memory dynamically for storing birthday and month of people in room*/ 
       bday_mon = malloc(no_of_people * sizeof(char *)); // Allocate row pointers
       bday = malloc(no_of_people * sizeof(int *));
       
       /*allocating memory for storing each month*/
       for(i = 0; i < no_of_people; i++){
             bday_mon[i] = malloc(3 * sizeof(char));
       }
       
       /*Repeating experiment for each trial*/
       for(n=1;n<=trials;n++){
       /* Generating bdays of people randomly */
       for( i = 0 ; i < no_of_people; i++ ) {
            
            /*generate month and days randomly*/
            mm=rand() % 12;
            dd=rand()% number_of_days_in_month(mm)+1; 
            
            /*storing bdays in array*/   
            *(bday_mon+i)= mon[mm];
            *(bday+i)=dd;                
       }
      
      /*print bdays*/
      print_bdays(n);
      /*compare bdays of each person with others in room*/ 
      compare_bdays(n);
      
      /*deallocate dynamically allocated memories*/
      free(bday);
      free(bday_mon);
      
    }
      /*probability of atleast two people having same bday */   
      prob_success=(float)success_trials/trials;
      
      printf("\nNumber of success trials among %d trials = %d\n",trials,success_trials);
      fprintf(trial_result,"\nNumber of success trials among %d trials = %d\n",trials,success_trials);
      printf("\nProbability of atleast two people having same bday among %d people in %d trials = %0.2f\n",no_of_people,trials,prob_success);
      fprintf(trial_result,"\nProbability of atleast two people having same bday among %d people in %d trials = %0.2f\n",no_of_people,trials,prob_success);
      printf("\n***********************End of run***********************\n\n");
      fprintf(trial_result,"***********************End of run***********************\n\n");
      printf("\nYou can view the results of this run in Birthday Paradox Trial Results.xls in same directory where your program is located \n\n");
      printf("\nPress any key to exit...");
      fclose(trial_result);
    
    getch(); 
    return(0);
    }
    
    /*Function to get number of days in a month*/
    int number_of_days_in_month(int mm){
        int no_of_days;
        switch(mm){
                       case 0:{
                             no_of_days=31;
                             break;
                       }
                       case 1:{
                             no_of_days=28;
                             break;
                       }  
                       case 2:{
                             no_of_days=31;
                             break;
                       }
                       case 3:{
                             no_of_days=30;
                             break;
                       } 
                       case 4:{
                             no_of_days=31;
                             break;
                       }
                       case 5:{
                             no_of_days=30;
                             break;
                       }    
                       case 6:{
                             no_of_days=31;
                             break;
                       }
                       case 7:{
                             no_of_days=31;
                             break;
                       } 
                       case 8:{
                             no_of_days=30;
                             break;
                       }
                       case 9:{
                             no_of_days=31;
                             break;
                       }                       
                       case 10:{
                             no_of_days=30;
                             break;
                       }
                       case 11:{
                             no_of_days=31;
                             break;
                       }                    
            }
        return no_of_days;
        }
               
    /*Function to print birthdays of people in room*/
    void print_bdays(int n){
         int i;
         printf("\nBirthdays of %d people in trial no %d\n",no_of_people,n);
         printf("------------------------------------------\n");
         printf("Person\t\tDay\t\tMonth\n");
         for(i=0;i<no_of_people;i++){
             printf("%6d%13d%18s\n",i+1,*(bday+i),*(bday_mon+i));                        
         }
         printf("\n");
    }
    
    /*Function to compare birthdays of each person in a room with others in room*/
    void compare_bdays(int n){
         int i,j,count=0;
         printf("People sharing same birthday\n");
         printf("----------------------------\n");
         printf("Person\t\tDay\t\tMonth\n");
         
         for(i=0;i<no_of_people;i++){
             for(j=0;j<no_of_people;j++){                                 
                    /*This condition is to avoid comparing bday with self*/
                    if(i!=j){
                     
                              if ((strcmp(*(bday_mon+i),*(bday_mon+j))==0)&& (*(bday+i)==*(bday+j))){
                                 printf("%6d%13d%18s\n",i+1,*(bday+j),*(bday_mon+j));
                                 count++;
                              }    
                    }                                  
             }
         }
           
         if(count == 0){
                  printf("NONE\n");
         }
         else{
              success_trials++;
         }
         printf("\nNumber of people having same bday among %d people in trail no %d = %d\n", no_of_people,n,count);
         printf("\n****************************End of Trial %d****************************\n\n",n); 
         fprintf(trial_result,"Number of people having same bday among %d people in trail no %d = %d\n", no_of_people,n,count);         
                                           
    }
/*********************************************************************End of program*********************************************************************/
