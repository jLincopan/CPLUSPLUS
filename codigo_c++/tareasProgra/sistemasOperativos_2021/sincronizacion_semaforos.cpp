#include <iostream>
#include <pthread.h>
#include <semaphore.h>

//variables globales que representan los semáforos
sem_t semaforo1, semaforo2 ,semaforo3 ,semaforo4;

void* A(void*);
void* B(void*);
void* C(void*);
void* D(void*); 

int main() {
    //variables que representan los hilos
    pthread_t hilo1, hilo2, hilo3, hilo4;

    //inicializamos los semáforos
    sem_init(&semaforo1, 0, 1);
    sem_init(&semaforo2, 0, 0);
    sem_init(&semaforo3, 0, 0);
    sem_init(&semaforo4, 0, 0);

    //creamos y lanzamos los hilos
    pthread_create(&hilo1,NULL,&A,NULL);
    pthread_create(&hilo2,NULL,&B,NULL);
    pthread_create(&hilo3,NULL,&C,NULL);
    pthread_create(&hilo4,NULL,&D,NULL);

    //estas líneas hacen que el programa principal
    //(la función main en este caso) no finalice
    //antes de que terminen de ejecutarse los 4 hilos
    //ya que si termina antes, los hilos se detendrán
    pthread_join(hilo1,NULL);
    pthread_join(hilo2,NULL);
    pthread_join(hilo3,NULL);
    pthread_join(hilo4,NULL); //con una sola línea bastaría ya que los 4 hilos
                              //están en un bucle infinito
    return 0;
}

//ABBCDD

void * A(void * arg) {   
    while(1) {
        for(int i = 1; i > 0; i--) {
            sem_wait(&semaforo1);
            std::cout<<"A";
        }

        sem_post(&semaforo2);
        sem_post(&semaforo2);

    }
}


void * B(void * arg) {  

    while(1) {

        for(int i = 2; i > 0; i--) {
            sem_wait(&semaforo2);
            std::cout<<"B";
            
        }
        sem_post(&semaforo3);
    }

}

void * C(void * arg) {  
    while(1) {

        for(int i = 1; i > 0; i--) {
            sem_wait(&semaforo3);
            std::cout<<"C";
            
        }
        sem_post(&semaforo4);
        sem_post(&semaforo4);
    }

}

void * D(void * arg) {  
    while(1) {

        for(int i = 2; i > 0; i--) {
            sem_wait(&semaforo4);
            std::cout<<"D";
            
        }
        std::cout<<" ";
        sem_post(&semaforo1);
    }

}
