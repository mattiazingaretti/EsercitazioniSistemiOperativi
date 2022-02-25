#include<stdio.h>
#include<assert.h>
#include<string.h>
#define NUM_STATES 5
#define EXIT_CMD "EXIT\n"


typedef void (*StatePointer)(char);

StatePointer currentState;


void S1(char in);
void S2(char in);
void S3(char in);
void S4(char in);
void S5(char in);

void S1(char in){
	if((int) in == -86){ // \0xAA as int = 170 -> char = -86.
		printf("You are in S1 with input %s \n", "\\0xAA");
		printf("Transition to S2!\n");	
		currentState = S2;
	}else{
		printf("You are in S1 with input %c \n", in);
	}
	return;
}


void S2(char in){
	
	if((int) in == 0x55){ //0x55 -> to char = 'U'
		printf("You are in S2 with input %c \n", in);
		printf("Transition to S3!\n");	
		currentState = S3;
	}else{
		printf("You are in S2 with input %c \n", in);
		printf("Transition to S1!\n");	
		currentState = S1;
	}
	return;
}


int X_times = 0;

void S3(char in){
		printf("You are in S3 with input %c : %d\n", in, (int) in);
		printf("Transition to S4!\n");	
		currentState = S4;
		X_times = (int) in;
		(*currentState)(in);
		return;
}


void S4(char in){		
	if(X_times > 0){
		printf("S4 input %c : %d\n (Volte rimanenti : %d)", in, (int) in, X_times);
		printf("Transition to S4!\n");	
		currentState = S4;
		X_times--;
	}else{
		printf("You are in S4 with input %c : %d\n", in, (int) in);
		printf("Transition to S5!\n");	
		currentState = S5;
	}
	return;
}

void S5(char in){
	if((int) in == -86){ // \0xAA as int = 170 -> char = -86.
		printf("You are in S5 with input %s \n", "\\0xAA");
		printf("Transition to S2!\n");	
		currentState = S2;
	}else{
		printf("You are in S5 with input %c \n", in);
		printf("Transition to S1!\n");	
		currentState = S1;
	}
	return;

}


int main(){
	
	currentState = S1;
	
	
	char* line; //stringa
	size_t read, size;
	
	unsigned char input; //char
	
	read = getline(&line, &size, stdin);
	if (read == -1) assert("ao hai fatto i danni \n");
	else if(strcmp(line , EXIT_CMD) == 0)return 0;
	else{
		
		while(read >0 ){			
			if(strcmp(line, "\\0xAA\n") == 0){
				input = (int) 170; //0xAA -> in decimale è 170
			}else{
				input = line[0];
			}
			
			(*currentState)(input);//delego la logica dell'automa allo stato corrente.
			read = getline(&line, &size, stdin);
			if(read == -1) printf("No line to read!\n"); //TODO: fai una funzione senza ripetere sta robba.
			if(strcmp(line, EXIT_CMD) == 0) break;
		}
	}
	
	return 0;
}
