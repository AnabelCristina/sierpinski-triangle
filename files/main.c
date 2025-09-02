#include <stdio.h> 
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <math.h>

#define SIZE 720	

typedef struct Ponto
{
	float x;
	int y;
}Ponto;


/** CALCULO DA ÁREA DO TRIANGULO **/

float areaTriangulo(Ponto a, Ponto b, Ponto c){
    return fabs(((b.x - a.x)*(c.y - a.y) - (c.x - a.x) * (b.y - a.y))/2);
}


/** FUNÇAO QUE DIZ SE UM PONTO ESTA OU NAO DENTRO DE UM TRIANGULO */

int pontoNoTriangulo(Ponto a, Ponto b, Ponto c, int x, int y){
	
	Ponto P;
	P.x = x; 
	P.y = y;
	
	// a area de cada triangulo abaixo precisa ser igual para que o 
	// ponto pertença ao triangulo
	
    float ABC = areaTriangulo(a,b,c);
    float ACT = areaTriangulo(a,c,P);
    float ABT = areaTriangulo(a,b,P);
    float CTB = areaTriangulo(c,P,b);

    if(ABC == ACT+ABT+CTB)
        return 1;

    return 0;
}


/** FUNÇAO QUE PREENCHE UM TRIANGULO, PINTADO PONTO A PONTO **/
/** Na biblioteca grafica SDL2 nao é possivel desenhar e pintar um triangulo**/
/** A solução encontrada foi a de calcular se um ponto esta dentro do triangulo ou nao**/
/** sempre que estiver o ponto é pintado **/

void pintaTriangulo(SDL_Renderer *renderer, Ponto P1, Ponto P2, Ponto P3){
	
	int i,j;
	
	// percorre um retangulo no qual o triangulo esta contido
	// e testa se cada ponto pertence ou nao ao triangulo
	
	for (i = P1.x; i<P2.x;i++){
		for (j = P1.y; j<P3.y; j++){
			if (pontoNoTriangulo(P1,P2,P3, i, j)){
				SDL_RenderDrawPoint(renderer,i,j);
			}		
		}
	}	
}

/**Calcula o ponto do meio de uma reta**/
Ponto midPoint (struct Ponto P1, struct  Ponto P2){
	struct Ponto mp;
	
	mp.x = (P1.x + P2.x)/2;
	mp.y = (P1.y + P2.y)/2;
	
	return mp;
}

/**Função recursiva que gera as iterações do triangulo **/
void criaTriangulo (SDL_Renderer *renderer, int level, struct Ponto P1, struct  Ponto P2, struct Ponto P3){

	struct Ponto P4;
	struct Ponto P5;
	struct Ponto P6;
	
	if (level == 1){
		
		SDL_RenderPresent(renderer);
		
	}
	else {
		
		//calcula o midpoint de cada reta que forma o triangulo
		P4 = midPoint(P1, P2);
		P5 = midPoint(P2, P3);
		P6 = midPoint(P1, P3);
		
		//um triangulo é gerado atraves dos midpoints calculados anteriormente
		//esse triangulo é pintado
		pintaTriangulo(renderer, P6, P5, P4);
		
		//faz chamada recursiva para os 3 triangulos que "sobraram" na figura
		criaTriangulo(renderer, level-1, P1, P4, P6);
		criaTriangulo(renderer, level-1, P4, P2, P5);
		criaTriangulo(renderer, level-1, P6, P5, P3);
	}	
}


int main(int argc, char *argv[]){
	
	int level = 10;
	struct Ponto P1;
	struct Ponto P2;
	struct Ponto P3;
	
	double altura = sqrt(3) * SIZE/2;
	
	//inicia p1, p2 e p3, que sao os pontos que formam o triangulo inicial
	P1.x = 0;
	P1.y = altura;
	P2.x = SIZE;
	P2.y = altura;
	P3.x = SIZE/2;
	P3.y = 0;
	
	//inicia graficos
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window = SDL_CreateWindow("Triangulo de sierpinski", SDL_WINDOWPOS_UNDEFINED,  SDL_WINDOWPOS_UNDEFINED, SIZE, SIZE, SDL_WINDOW_OPENGL);
	SDL_Renderer *renderer = SDL_CreateRenderer (window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	SDL_Event evento;
	
	SDL_SetRenderDrawColor(renderer,255,255,0,255);
	
	int i, j;
	
	
	//preenche o triangulo inicial ponto a ponto
	for (i = P1.x; i<P2.x;i++){
		for (j = P3.y; j<P2.y; j++){
			if (pontoNoTriangulo(P1,P2,P3, i, j)){
				SDL_RenderDrawPoint(renderer,i,j);
			}		
		}
	}
	
	
	int running = 1;
	
	while (running){
		
		
		SDL_SetRenderDrawColor(renderer,255,0,255,255);
		
		//chama função recursiva
		criaTriangulo(renderer, level, P1, P2, P3);
			
		while (SDL_PollEvent(&evento)){
			if (evento.type == SDL_QUIT){
				running = 0;
				break;
			}
		}
		
		
	}
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	
	return 0;
}