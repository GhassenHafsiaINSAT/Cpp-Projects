#include <stdio.h>
#include <pthread.h>


typedef char ALIGN[16];

union header{

    struct {
        size_t size;
        unsigned is_free; 
        union header *next; 
    } s;

    ALIGN stub; 
};  

typedef union header header_t; 
header_t *head, *tail; 

pthread_mutex_t global_malloc_lock;


void free(void *block){
    header_t *header, *tmp; 
    void *programbreak; 

    if(!block)
        return; 

    pthread_mutex_unlock(&global_malloc_lock); 
    header = (header_t*)block -1;

    programbreak = sbrk(0);

    if((char*)block + header->s.size == programbreak){
        if(head == tail){ 
            head = tail = NULL; 
        }
        else{   
                tmp = head; 
                while(tmp){
                    if(tmp->s.next ==tail){
                        tmp->s.next = NULL; 
                        tail = tmp; 
                    }
                    tmp = tmp->s.next; 
                }

            }
            sbrk(0 - sizeof(header_t) -header->s.size); 
            pthread_mutex_unlock(&global_malloc_lock); 
            return; 
    } 
    header->s.is_free = 1; 
    pthread_mutex_unlock(&global_malloc_lock); 

}