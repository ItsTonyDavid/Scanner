#include <iostream>
#include <string>
using namespace std;
//El scanner debe generar e imprimir la lista de tokens derivados del análisis.
//Si el scanner encuentra un error, debe detenerse y mostrar el mensaje correcto en la pantalla

//Matriz de transiciones.
//[estado no final, transicion]
//estados > 6 = no finales
//estados == 6 = final
//10 == caracter no permitido
int MatrizLaws[6][6]={
    //numeros, letras, parentesis, operadores, ; , otro
    /* Estado 0 */{1, 2, 4, 5, 999, 10},
    /* Estado 1 */{1, 999, 999, 999, 6, 10},   //numero
    /* Estado 2 */{3, 2, 999, 999, 6, 10},     //letras
    /* Estado 3 */{3, 2, 999, 999, 6, 10},     //letra,numero
    /* Estado 4 */{999, 999, 4, 999, 6, 10},   //parentesis
    /* Estado 5 */{999, 999, 999, 999, 6, 10}  //operador
};

int error = 999;

//Metodo que controlará la matriz de estados y transiciones;
//Retornará la columna del valor ingresado
int matrixController(char token){
    
    //Si son numeros de 1 a 9
    if (token >= 48 && token <= 57)
        return 0;
    
    //si son letras A-Z o a-z
    if(token >= 65 && token <= 90 | token >= 97 && token <= 122 )
        return 1;
    
    //si son parentesis
    if(token == '(' | token == ')')
        return 2;
    
    //si es un operador
    if(token == '+' | token == '-' | token == '*' | token == '/')
        return 3;
    
    //si es ;
    if (token == ';')
        return 4;
    
    //si es cualqueir otro caracter no permitido
    else return 5;
}

void encontrarError(string sVariable, int iError){
    
    if(iError == 10){
        cout<<"Hay un caracter no identificado"<<endl;}
    
    if(sVariable[sVariable.length()-1] != ';'){
        cout<<"Cada que termines de escrbir una linea debes de poner un ; "<<endl;
        return;}
    
    if (sVariable[1] >= 48 && sVariable[1] <= 57 | sVariable[0] == '0' ){
        cout<<"Numeros no pueden comenzar con 0 y solo van seguidos de más numeros"<<endl;
        return;}
    
    if(sVariable[0] >= 65 && sVariable[0] <= 90 | sVariable[0] >= 97 && sVariable[0] <= 122 ){
        cout<<"Variables solo empiezan con una letra seguidos unicamente de numeros o más letras"<<endl;
        return ;}
    
    if(sVariable[0] == '('| sVariable[0] == ')'){
        cout<<"Parentesis solo van seguidos de más parentesis"<<endl;
        return;}
    
    if (sVariable[0] == '+' | sVariable[0] == '-' | sVariable[0] == '*' | sVariable[0] == '/'){
        cout<<"Operadores van solos"<<endl;
        return;}
    
}

void Scanner(string sVariable){
    if (sVariable[0] == '0'){
        encontrarError(sVariable, 0);
        return;}
    
    int state = 0, token = 0, transition = 0;
    while (token <= sVariable.length()) {
        transition = matrixController(sVariable[token]);
        state = MatrizLaws[state][transition];
        token++;
        if (state == 6) {
            cout<<"Palabra aceptada en el lenguaje"<<endl;
            return;}
        if (state != 6){
            encontrarError(sVariable, state);
            return;}
    }
    
}

int main(int argc, const char * argv[]) {
    cout<<"ingresar palabra"<<endl;
    string sWord = "";
    cin>>sWord;
    Scanner(sWord);
    return 0;
}
