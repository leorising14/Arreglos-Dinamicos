/* 
 * File:   main.c
 * Author: Gabriel
 *
 * Created on 15 de junio de 2015, 18:49
 */

#include <stdio.h>
#include <stdlib.h>

//typedef struct hola sthola;
typedef struct sthola{
int cont;
int data;
struct sthola *p2next;
}sthola;


void addblock(int dato, sthola *lista);                     //si agrego bloque, le indico el dato a usar y la direccion de mi estructura
void delblock(int num_of_block_to_del,sthola *lista);
sthola* readblock(int num_of_blok_to_read, sthola *lista);

void addblock(int dato,sthola *lista){
int i;
sthola *ptr= (sthola*) calloc(1,sizeof(sthola));        //asigno el puntero al nuevo bloque, reservando memoria y haciendo un casteo del puntero
sthola *recorrer=lista;                                 //creo un nuevo puntero utilizado para recorrer
if(lista == NULL){                                     //en caso de que el arreglo este vacio
lista->cont=0;                                          //su ubicacion es 0
lista->p2next=ptr;                                      
ptr->data=dato;
ptr->p2next=NULL;
}else {for(i=0;(recorrer->p2next)!=NULL;recorrer=recorrer->p2next){i++;}    //recorro el arreglo dinàmico hasta llegar al ultimo elemento
        ptr->cont=i;
        recorrer->p2next=ptr;
        ptr->data=dato;
        ptr->p2next=NULL;
            }

}

void delblock(int num_of_block_to_del,sthola *lista){
sthola *recorrer=lista;
sthola *bup=lista;
for (;(recorrer->cont)<(num_of_block_to_del-1);recorrer=recorrer->p2next){
}
bup=recorrer;
recorrer=recorrer->p2next;
bup->p2next=recorrer->p2next;
free(recorrer);
}

sthola* readblock(int num_of_block_to_read, sthola *lista){
sthola *recorrer=lista;
for(;(recorrer->cont)<(num_of_block_to_read);recorrer=recorrer->p2next);
return recorrer;
}

int main(int argc, char** argv) {

    sthola* test = NULL;   
    addblock(15, test);
    addblock(30, test);
    printf("El dato es: %d",readblock(1,test)->data);
    printf("El dato es: %d",readblock(2,test)->data);

    
    return(EXIT_SUCCESS);
}