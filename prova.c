#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
//funzioni
int checkuser(char *);
int frecce(char *);
void superuser();
void user();

//variabili globali
int typeuser;
int carlock = 1;
int bkhome = 1;
int quit= 0;
int exitflag=1;
int lampeggi=3;
char tasto;
char tmp;

//inizio programma
int main (int argc, char *argv[]){

//apro la funzione per capire chi è l'utente
typeuser= checkuser(argv[1]);

//apro la funzione in base all'utente
if(typeuser==0)
    user();
else
    superuser();

return 0;
}

//identifico quale user sta loggando
int checkuser(char *arg){
//se non ha inserito 2244 è user
if(arg == NULL){
        printf("Welcome User\n");
            return 0;
    }
//effettuo una comparazione tra quello che ha inserito l'utente e il codice 2244, se uguali allora è un superuser
else if( strcmp(arg, "2244") ==0 ){
    printf("Welcome Superuser\n");
        return 1;
    }
else{
    printf("Unknown mode:\n");
        printf("Launching User mode\n");
            return 0;
    }
//ritorno al main
}




void user(){
char comando[5];
int ctrl=1;
//appena si apre la schermata per la prima volta mostra subito setting automobile
printf("Inserire freccia su o freccia giù per scorrere l'elenco, invio per tornare alla home quando si è in un sottomenù.\n");
while(exitflag!=0){

if(ctrl==1){
    printf("Setting automobile: \n");
        scanf(" %3s", comando);
        
        //freccia su
        if(frecce(comando)==1 ){
            ctrl=6;
            }
        //freccia giù
        else if(frecce(comando)==2 ){
            ctrl++;
            }
        else{
            printf("Premere freccia su o giù, destra per entrare nel sottomenù se esistente.\n");
            }
    }
    
else if(ctrl==2){
    printf("Data: 15/06/2014 \n");
        scanf(" %3s", comando);
        
        //freccia su
        if(frecce(comando)==1 ){
            ctrl--;
        }
        //freccia giù
        else if(frecce(comando)==2 ){
            ctrl++;
        }
        else{
            printf("Premere freccia su o giù, destra per entrare nel sottomenù se esistente.\n");
        }
}

else if (ctrl == 3) {
    printf("Ora: 15:32 \n");
    scanf(" %3s", comando);
        
        //freccia su
        if (frecce(comando) == 1)
                ctrl--;
        else if (frecce(comando) == 2)
                ctrl++;
        else{
            printf("Premere freccia su o giù, destra per entrare nel sottomenù se esistente.\n");
        }
    }
        
else if (ctrl == 4) {
      if (carlock==1)
          printf("Blocco automatico porte: ON \n");
      else
          printf("Blocco automatico porte: OFF \n");

      scanf(" %3s", comando);
          
            if (frecce(comando) == 1)
                ctrl--;
            else if (frecce(comando) == 2)
                ctrl++;
            
            //sottomenù
            else if (frecce(comando) == 3){
                  if (carlock==1)
                        printf("Blocco automatico porte: ON \n");
                  else
                        printf("Blocco automatico porte: OFF \n");
                    while(quit==0){
                        scanf(" %3s", comando);
                                if(carlock==1){
                                    if(frecce(comando) == 1 || frecce(comando) == 2){
                                        carlock=0;
                                          printf("Set Blocco automatico porte: OFF\n");  
                                          }
                                      }
                                else if(carlock==0){
                                    if(frecce(comando) == 1 || frecce(comando) == 2){
                                        carlock=1;
                                          printf("Set Blocco automatico porte: ON\n");
                                        }
                                    }
                                if(frecce(comando) == 5){
                                    quit=1;
                                }
                      }
                quit=0;
              } 
          else{
                printf("Premere freccia su o giù, destra per entrare nel sottomenù se esistente.\n");
              }
      }

          
else if (ctrl == 5) {
        if(bkhome)
            printf("Back-home: ON \n");
        else
            printf("Back-home: OFF \n");
            scanf(" %3s", comando);

                if (frecce(comando) == 1)
                    ctrl--;
                else if (frecce(comando) == 2)
                    ctrl++;
                else if (frecce(comando) == 3){
                            if(bkhome)
                                printf("Back-home: ON \n");
                            else
                                printf("Back-home: OFF \n");
                                
                                while(quit==0){
                                    scanf(" %3s", comando);
                                        if(bkhome==1){
                                              if(frecce(comando) == 1 || frecce(comando) == 2){
                                                  bkhome=0;
                                                      printf("Back-home: OFF \n");
                                                }
                                            }
                                        else if(bkhome==0){
                                              if(frecce(comando) == 1 || frecce(comando) == 2){
                                                  bkhome=1;
                                                      printf("Back-home: ON \n");
                                                  }
                                              }
                                        if(frecce(comando) == 5){
                                                quit=1;
                                          }
                                  }
                      quit=0;
                }
                else{
                    printf("Premere freccia su o giù, destra per entrare nel sottomenù se esistente.\n");
                }
        }
         
else if (ctrl == 6) {
            printf("Check olio \n");
            scanf(" %3s", comando);
            
            if (frecce(comando) == 1)
                ctrl--;
            else if (frecce(comando) == 2)
                ctrl = 1;
            else{
                printf("Premere freccia su o giù, destra per entrare nel sottomenù se esistente.\n");
            }
        }
    }
}


int frecce(char *comando) {
    if (comando[2] == 'A')
        return 1; // Freccia su
    else if (comando[2] == 'B')
        return 2; // Freccia giù
    else if (comando[2] == 'C')
        return 3;
    else if (comando[2] == 'D')
        return 4;
    else if (comando[0] == '\n')
        return 5;
    else
        return 0;
}


void superuser(){
char comando[4];
int ctrl=1;
//appena si apre la schermata per la prima volta mostra subito setting automobile
printf("Inserire freccia su o freccia giù per scorrere l'elenco, invio per tornare alla home quando si è in un sottomenù.\n");
while(exitflag!=0){

if(ctrl==1){
    printf("Setting automobile (supervisor): \n");
        scanf(" %3s", comando);
        
        //freccia su
        if(frecce(comando)==1 ){
            ctrl=8;
            }
        //freccia giù
        else if(frecce(comando)==2 ){
            ctrl++;
            }
        else{
            printf("Premere freccia su o giù, destra per entrare nel sottomenù se esistente.\n");
            }
    }
    
else if(ctrl==2){
    printf("Data: 15/06/2014 \n");
        scanf(" %3s", comando);
        
        //freccia su
        if(frecce(comando)==1 ){
            ctrl--;
        }
        //freccia giù
        else if(frecce(comando)==2 ){
            ctrl++;
        }
        else{
            printf("Premere freccia su o giù, destra per entrare nel sottomenù se esistente.\n");
        }
}

else if (ctrl == 3) {
    printf("Ora: 15:32 \n");
    scanf(" %3s", comando);
        
        //freccia su
        if (frecce(comando) == 1)
                ctrl--;
        else if (frecce(comando) == 2)
                ctrl++;
        else{
            printf("Premere freccia su o giù, destra per entrare nel sottomenù se esistente.\n");
        }
    }
        
else if (ctrl == 4) {
      if (carlock==1)
          printf("Blocco automatico porte: ON \n");
      else
          printf("Blocco automatico porte: OFF \n");

      scanf(" %3s", comando);
          
            if (frecce(comando) == 1)
                ctrl--;
            else if (frecce(comando) == 2)
                ctrl++;
            
            //sottomenù
            else if (frecce(comando) == 3){
                  if (carlock==1)
                        printf("Blocco automatico porte: ON \n");
                  else
                        printf("Blocco automatico porte: OFF \n");
                    while(quit==0){
                        scanf(" %3s", comando);
                                if(carlock==1){
                                    if(frecce(comando) == 1 || frecce(comando) == 2){
                                        carlock=0;
                                          printf("Set Blocco automatico porte: OFF\n");  
                                          }
                                      }
                                else if(carlock==0){
                                    if(frecce(comando) == 1 || frecce(comando) == 2){
                                        carlock=1;
                                          printf("Set Blocco automatico porte: ON\n");
                                        }
                                    }
                                if(frecce(comando) == 5){
                                    quit=1;
                                }
                      }
                quit=0;
              } 
          else{
                printf("Premere freccia su o giù, destra per entrare nel sottomenù se esistente.\n");
              }
      }
      

          
else if (ctrl == 5) {
        if(bkhome)
            printf("Back-home: ON \n");
        else
            printf("Back-home: OFF \n");
            scanf(" %3s", comando);

                if (frecce(comando) == 1)
                    ctrl--;
                else if (frecce(comando) == 2)
                    ctrl++;
                else if (frecce(comando) == 3){
                            if(bkhome)
                                printf("Back-home: ON \n");
                            else
                                printf("Back-home: OFF \n");
                                
                                while(quit==0){
                                    scanf(" %3s", comando);
                                        if(bkhome==1){
                                              if(frecce(comando) == 1 || frecce(comando) == 2){
                                                  bkhome=0;
                                                      printf("Set Back-home: OFF \n");
                                                }
                                            }
                                        else if(bkhome==0){
                                              if(frecce(comando) == 1 || frecce(comando) == 2){
                                                  bkhome=1;
                                                      printf("Set Back-home: ON \n");
                                                  }
                                              }
                                        if(frecce(comando) == 5){
                                                quit=1;
                                          }
                                  }
                      quit=0;
                }
                else{
                    printf("Premere freccia su o giù, destra per entrare nel sottomenù se esistente.\n");
                }
        }
         
else if (ctrl == 6) {
            printf("Check olio \n");
            scanf(" %3s", comando);
            
            if (frecce(comando) == 1)
                ctrl--;
            else if (frecce(comando) == 2)
                ctrl++;
            else{
                printf("Premere freccia su o giù, destra per entrare nel sottomenù se esistente.\n");
            }
        }
else if (ctrl == 7){
        printf("Frecce direzione \n");
        scanf(" %3s", comando);
        
        if (frecce(comando) == 1)
                ctrl--;
        else if (frecce(comando) == 2)
                ctrl++;
        //sottomenu
        else if (frecce(comando) == 3){
                if(lampeggi==2)
                    printf("Lampeggi modalità autostrada: 2\n");
                else if(lampeggi==3)
                    printf("Lampeggi modalità autostrada: 3\n");
                else if(lampeggi==4)
                    printf("Lampeggi modalità autostrada: 4\n");
                else if(lampeggi==5)
                    printf("Lampeggi modalità autostrada: 5\n");
                
                        while(quit==0){
                            scanf(" %c", &tasto);
                                //numeri minori uguali di 2
                                if(tasto <= '2'){
                                        lampeggi=2;
                                            printf("Set lampeggi 2\n");
                                      }
                                //numero 3
                                else if(tasto == '3'){
                                          lampeggi=3;
                                              printf("Set lampeggi 3\n");
                                        }
                                //numero 4
                                else if(tasto == '4'){
                                          lampeggi=4;
                                              printf("Set lampeggi 4\n");
                                      }
                                //numeri maggiori uguali di 5
                                else if(tasto >= '5'){
                                          lampeggi=5;
                                              printf("Set lampeggi 5\n");
                                      }
                                if(tasto == '\n' || tasto == '\r'){
                                                quit=1;
                                          }
                        }
            }
        else{
            printf("Premere freccia su o giù, destra per entrare nel sottomenù se esistente.\n");
            }
    }
else if (ctrl == 8){
        printf("Reset pressione gomme\n");
            scanf(" %3s", comando);
                //freccia su
                if(frecce(comando) == 1)
                    ctrl--;
                //freccia giu
                else if (frecce(comando) == 2)
                    ctrl=1;
                //freccia dx
                else if(frecce(comando) == 3)
                            printf("Pressione gomme resettata\n");
      }
    
}
}
