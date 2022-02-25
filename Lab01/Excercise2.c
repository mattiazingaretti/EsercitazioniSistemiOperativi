#include<stdio.h>
#include<string.h>
#define NUM_STATES 5
#define EXIT_CMD "EXIT\n"

/**
 * Dato che 0xAA in decimale è 170 > 128 (quindi non mi basta la codifica ASCII a 7 bit) ho deciso di implementare la logica dell'automa consiederando una 
 * stringa piuttosto che un char.
 **/
 
  
typedef void (*StatePointer)(char*);

StatePointer currentState;

void S1(char* in);
void S2(char* in);
void S3(char* in);
void S4(char* in);
void S5(char* in);

void S1(char* in){
	printf("You are in S1 with input %s \n", in);
	if(strcmp(in, "170\n") == 0){ 
		printf("Transition to S2!\n");	
		currentState = S2;
	}
	return;
}


void S2(char* in){
	printf("You are in S2 with input %s \n", in);
	if(strcmp(in, "U\n") == 0){
		printf("Transition to S3!\n");	
		 currentState = S3; //0x55 <-> "U"
	}else{
		printf("Transition to S1!\n");	
		currentState = S1;
	}
	return;
}

void S3(char* in){
	printf("You are in S3 with input %s \n", in);
	currentState = S4;
	printf("Transition to S4!\n");	
	return;
}

void S4(char* in){
	printf("You are in S4 with input %s \n", in);
}

void S5(char* in){
	printf("You are in S5 with input %s \n", in);
}


int main(){
	currentState = S1;
	char* line;
	size_t size, read;
	
	read = getline(&line, &size, stdin);
	if(read == -1) printf("No line to read!\n"); //TODO: add better error handling.
	else {
		
		while(read >0 ){
			(*currentState)(line);//delego la logica dell'automa allo stato corrente.
			read = getline(&line, &size, stdin);
			if(read == -1) printf("No line to read!\n"); //TODO: fai una funzione senza ripetere sta robba.
			if(strcmp(line, EXIT_CMD) == 0) break;
	
		}
	}
	/*
	//TODO: Implement with different string then 0xAA and use char or unsigned char's-
	unsigned char c; //Così posso assegnare il carattere associato a 0xAA
	c = (unsigned char) getchar();
	
	*/
	return 0;	
}

