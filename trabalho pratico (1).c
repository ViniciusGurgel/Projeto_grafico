/* Codigo criado por Vinícius Gurgel Serrão e Guilherme Nobrega Gomes Dantas */

#include<math.h> //Operações matemáticas
#include<stdio.h> //Inclui as funções entradas e saídas do programa
#include<locale.h> // necessário para usar setlocale
#include<stdlib.h> // Interface da biblioteca stdlib
#include<windows.h>
void reta_algoritmoDDA(void); // Função para imprimir uma reta utilizando o algoritmo DDA
int calculo_reta_DDA(int x0, int y0, int x1, int y1); // Função para calcular e imprimir a reta utilizando o algoritmo DDA
void imprimir_valoresDDA(int x0, int y0, int x1, int y1,int step); // Função para imprimir valores do algoritmo DDA
void reta_algoritmoBresenham(void); // Função para imprimir o plano cartesiano utilizando o algoratimo Bresenham
int calculo_reta_Bresenham(int X0,int Y0,int X1,int Y1); // Função para calcular e imprimir a reta utilizando o algoritmo Bresenham
void imprimir_reta_Bresenham(int X0,int Y0,int X1,int Y1); // Função para imprimir as váriaveis da reta utilizando o algoritmo Bresenham
void circulo_algoritmoBresenham(void); // Função que auxilia o calculo do circulo utilizando o algoritmo de Bresenham
void calculo_circulo_Bresenham(int Xc,int Yc,int raio); // Função que  calcula o circulo utilizando o algoritmo de Bresenham
void imprimir_valores_circulo_Bresenham(int Xc,int Yc,int raio); // Função que imprime os pontos contidos no circulo
void pixel(int X,int Y); //Função que auxilia a imprimir os pixels
void planocartesiano(void); // Função que imprime o plano cartesiano
void irParaXY(int x, int y); // Função que faz o apontamento para o X e Y
int setX(int x); // Função que calcula o valor de X no plano cartesiano
int setY(int y); // Função que calcula o valor de Y no plano cartesiano
void sair(int opcao); // Função que permite o usuario voltar, sair ou continuar


// Método para imprimir uma reta utilizando o algoritmo DDA
void reta_algoritmoDDA(){
    int X0,Y0,X1,Y1;
    system("cls");
    printf("\n RETA Algoritmo DDA\n");
    printf("Escolha o valor inicial de X: ");
    scanf("%d",&X0);
    printf("\n-------------------\n");
    printf("Escolha o valor inicial de Y: ");
    scanf("%d",&Y0);
    printf("\n-------------------\n");
    printf("Escolha o valor final de X: ");
    scanf("%d",&X1);
    printf("\n-------------------\n");
    printf("Escolha o valor final de Y: ");
    scanf("%d",&Y1);
    planocartesiano();
    int step = calculo_reta_DDA(X0,Y0,X1,Y1);
    imprimir_valoresDDA(X0,Y0,X1,Y1,step);
    sair(1); // chama a função sair e passa o parâmetro 1
}


// Método para calcular e imprimir a reta utilizando o algoritmo DDA
int calculo_reta_DDA(int x0,int y0,int x1,int y1){
    int step,deltaX,deltaY;
    float Xinc,Yinc,X = x0,Y = y0;
    deltaX = x1 - x0; // Calcula o deltaX
    deltaY = y1 - y0; // Calcula o deltaY
    step = fabs(deltaX) > fabs(deltaY) ? fabs(deltaX) : fabs(deltaY); // Pega o maior valor entre o deltaX e deltaY e atribui a step
    Xinc = (float) deltaX / step;
    Yinc = (float) deltaY / step;
    for (int aux = 0; aux <= step; aux++) {
        pixel(X,Y); // Chama a função pixel para "pintar" no plano cartesiano
        X = X + Xinc;
        Y = Y + Yinc;
    }
    return step;
}

// Método para imprimir valores do algoritmo DDA
void imprimir_valoresDDA(int x0,int y0,int x1,int y1,int step){
    irParaXY(setX(-50),setY(-25));
    int deltaX,deltaY,aux;
    float Xinc,Yinc,X = x0,Y = y0;
    deltaX = x1 - x0;
    deltaY = y1 - y0;
    Xinc = (float) deltaX / step;
    Yinc = (float) deltaY / step;
    printf("\n-----------------\n");
    printf("Step = %d",step); // Imprime o valor do step
    printf("\n-----------------\n");
    printf("Xinc = %.2f\n"
           "Yinc = %.2f",Xinc,Yinc); // Imprime o valor de
    printf("\n-----------------\n");
    printf("Pontos encontrados: (X,Y)\n");
    for (aux = 0; aux <= step; aux++) {
        printf("Pontos encontrados (%.f,%.f)\n",round(X),round(Y));
        X = X + Xinc;
        Y = Y + Yinc;
    }
    printf("\n-----------------\n");
}


// Método para imprimir o plano cartesiano utilizando o algoratimo Bresenham
void reta_algoritmoBresenham(){
    int X0,Y0,X1,Y1;
    system("cls");
    printf("\n RETA Algoritmo Bresenham\n");
    printf("Escolha o valor inicial de X: ");
    scanf("%d",&X0);
    printf("\n-------------------\n");
    printf("Escolha o valor inicial de Y: ");
    scanf("%d",&Y0);
    printf("\n-------------------\n");
    printf("Escolha o valor final de X: ");
    scanf("%d",&X1);
    printf("\n-------------------\n");
    printf("Escolha o valor final de Y: ");
    scanf("%d",&Y1);
    planocartesiano();
    calculo_reta_Bresenham(X0,Y0,X1,Y1); // chama a função calculo_reta_Bresenham e passa os parâmetros X,Y inicial e final
    imprimir_reta_Bresenham(X0,Y0,X1,Y1);
    sair(2); // chama a função sair e passa o parâmetro 2
}

// Método para calcular e imprimir a reta utilizando o algoritmo Bresenham
int calculo_reta_Bresenham(int X0,int Y0,int X1,int Y1){
    int deltaX = X1 - X0;
    int deltaY = Y1 - Y0;
    int p = 2 * (deltaX - deltaY); // define P = 2 *(Δx - Δy )
    int inc_Y = (Y0 < Y1) ? 1 : -1; // define inc_Y, 1 caso Y inicial seja menor do que Y final, caso contrario -1.
    int inc_X_Y = (X0 < X1) ? 1 : -1; // define inc_X_Y, 1 caso X inicial seja menor do que X final, caso contrario -1.
    int x = X0;
    int y = Y0;
    while(y != Y1){
        pixel(x,y); // Chama a função pixel para "pintar" no plano cartesiano
        if(p < 0){
            p += 2 * deltaY;; // Se p < 0, o próximo ponto será (x+1, y) e recalcula p=p+2Δy
        }else{
            p += 2 * (deltaY - deltaX); // Se p >= 0, o próximo ponto será (x+1, y+1) e recalcula p= p+2(Δy – Δx)
            x += inc_X_Y;
        }
        y += inc_Y;
    }
    pixel(x,y);
    return 0;
}


// Método para imprimir as váriaveis da reta utilizando o algoritmo Bresenham
void imprimir_reta_Bresenham(int X0,int Y0,int X1,int Y1){
    irParaXY(setX(-50),setY(-25));
    int deltaX = X1 - X0;
    int deltaY = Y1 - Y0;
    int p = 2 * (deltaX - deltaY);
    int inc_Y = (Y0 < Y1) ? 1 : -1;
    int inc_X_Y = (X0 < X1) ? 1 : -1;
    printf("\n-----------------\n");
    printf("Pontos encontrados: (X,Y)\n");
    while(Y0 != Y1){
        printf("Pontos encontrados: (%d,%d)\n",X0,Y0);
        if(p < 0){
            p += 2 * deltaX; // Se p < 0, o próximo ponto será (x+1, y) e recalcula p=p+2Δy
        }else{
            p += 2 * (deltaX - deltaY); // Se p >= 0, o próximo ponto será (x+1, y+1) e recalcula p= p+2(Δy – Δx)
            X0 += inc_X_Y;
        }
        Y0 += inc_Y;
    }
    printf("Pontos encontrados: (%d,%d)\n",X0,Y0);
    printf("\n-----------------\n");
}

// Método que auxilia o calculo do circulo utilizando o algoritmo de Bresenham
void circulo_algoritmoBresenham(){
    int XC,YC,raio;
    system("cls");
    printf("\n Circulo Algoritmo Bresenham\n");
    printf("Escolha o valor central do circulo  (X): ");
    scanf("%d",&XC);
    printf("\n-------------------\n");
    printf("Escolha o valor central do circulo (Y): ");
    scanf("%d",&YC);
    printf("\n-------------------\n");
    printf("Escolha o raio do circulo: ");
    scanf("%d",&raio);
    planocartesiano();
    calculo_circulo_Bresenham(XC,YC,raio);
    imprimir_valores_circulo_Bresenham(XC,YC,raio);
    sair(3); // chama a função sair e passa o parâmetro 3
}


// Método que  calcula o circulo utilizando o algoritmo de Bresenham
void calculo_circulo_Bresenham(int Xc,int Yc,int raio){
    int x = 0, y = raio;
    int p = 1 - raio;
    while (x <= y) {
        pixel(Xc + x, Yc + y); // Oct: 1 , Xn: X , Yn: Y
        pixel(Xc + y, Yc + x); // Oct: 2 , Xn: Y , Yn: X
        pixel(Xc - y, Yc + x); // Oct: 3 , Xn: -Y , Yn: X
        pixel(Xc - x, Yc + y); // Oct: 4 , Xn: -X , Yn: Y
        pixel(Xc - x, Yc - y); // Oct: 5 , Xn: -X , Yn: -Y
        pixel(Xc - y, Yc - x); // Oct: 6 , Xn: -Y , Yn: -X
        pixel(Xc + y, Yc - x); // Oct: 7 , Xn: Y , Yn: -X
        pixel(Xc + x, Yc - y); // Oct: 8 , Xn: X , Yn: -Y
        x++;
        if (p < 0) {
            p += 2*x + 1; // Se p for negativo, então calcula-se um novo p=p+2x+1
        } else {
            p += 2*(x - y) + 1; // caso contrário, decrementa-se y e calcula-se p=p+2(x-y)+1
            y--;
        }
    }
}

// Método que imprime os pontos contidos no circulo
void imprimir_valores_circulo_Bresenham(int Xc,int Yc,int raio){
    irParaXY(setX(-50),setY(-25));
    int x = 0, y = raio;
    int p = 1 - raio;
    printf("\n-----------------\n");
    while (x <= y) {
        printf("Pontos encontrados: (%d,%d)\t(%d,%d)\n",Xc + x, Yc + y, Xc + y, Yc + x); // Oct: 1 , Xn: X , Yn: Y && Oct: 2 , Xn: Y , Yn: X
        printf("Pontos encontrados: (%d,%d)\t(%d,%d)\n",Xc - y, Yc + x, Xc - x, Yc + y); // Oct: 3 , Xn: -Y , Yn: X && Oct: 4 , Xn: -X , Yn: Y
        printf("Pontos encontrados: (%d,%d)\t(%d,%d)\n",Xc - x, Yc - y, Xc - y, Yc - x); // Oct: 5 , Xn: -X , Yn: -Y && Oct: 6 , Xn: -Y , Yn: -X
        printf("Pontos encontrados: (%d,%d)\t(%d,%d)\n",Xc + y, Yc - x, Xc + x, Yc - y); // Oct: 7 , Xn: Y , Yn: -X && Oct: 8 , Xn: X , Yn: -Y
        x++;
        if (p < 0) {
            p += 2*x + 1; // Se p for negativo, então calcula-se um novo p=p+2x+1
        } else {
            p += 2*(x - y) + 1; // caso contrário, decrementa-se y e calcula-se p=p+2(x-y)+1
            y--;
        }
    }
    printf("\n-----------------\n");

}

// Método que auxilia a imprimir os pixels
void pixel(int X,int Y){
    irParaXY(setX(round(X)),setY(round(Y)));
    printf("%c",219);
}



//Método que faz o apontamento das coordenadas X e Y
void irParaXY(int x, int y) {
    COORD coord;
    coord.X = (short) x;
    coord.Y = (short) y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Método que imprime o plano cartesiano na tela
void planocartesiano(void) {
    int vertical, horizontal;
    for (vertical = 14; vertical < 55 ; vertical++) {//Reta que separa o plano na vertical
        irParaXY(118, vertical);
        printf("|");
    }
    for (horizontal = 18; horizontal < 219; horizontal++) {//Reta que separa o plano na horizontal
        irParaXY(horizontal, 34);
        printf("-");
    }
    irParaXY(118, 34);
    printf("X");//Ponto central
}

// Método que calcula o valor de X no plano cartesiano
int setX(int x){
    return (x + 118);
}

// Método que calcula o valor de Y no plano cartesiano
int setY(int y){
    return (-y + 34);
}


// Método que permite o usuario voltar, sair ou continuar
void sair(int opcao){
    int escolha;
    printf("Escolha o numero refente ao desafio desejado:\n"
           "(0) - Sair\n"
           "(1) - Voltar ao menu principal\n"
           "(2) - Continuar com outras variaveis\n"
           "\n\nOp%cão escolhida: ",135);
    scanf("%d",&escolha);
    switch(escolha){
    case 0:
        exit(0);
    case 1:
        system("cls");
        main();
    case 2:
        switch(opcao){
        case 1:
            reta_algoritmoDDA();
        case 2:
            reta_algoritmoBresenham();
        case 3:
            circulo_algoritmoBresenham();
        }
    }
}



void main() {
    // setlocale(LC_ALL,"Portuguese");
    int escolha;
    printf("Escolha o numero referente ao desafio desejado:\n"
            "(0) - Sair\n"
            "(1) - Imprime uma reta (Algoritmo DDA)\n"
            "(2) - Imprime uma reta (Algoritmo de Bresenham)\n"
            "(3) - Imprime o tra%cado de um circulo (Algoritmo de Bresenham)\n"
            "\n\nOp%cao escolhida: ",135,135);
    scanf("%d",&escolha);
    switch(escolha){
        case 0:
            exit(0);
        case 1:
            reta_algoritmoDDA();
        case 2:
            reta_algoritmoBresenham();
        case 3:
            circulo_algoritmoBresenham();
        }
}
