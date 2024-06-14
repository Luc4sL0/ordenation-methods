/* 
 * File:   main.cpp
 * Author: Lucas Lopes Baroni
 *
 * Created on 27 de maio de 2024, 16:08
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <time.h>

#define QUANTITY 100000

using namespace std;

/* Ordenation methods class */


int myGrowVector[QUANTITY];
int myDownVector[QUANTITY];
int myAleatoryVector[QUANTITY];

int menuOption() //The function returns the user selected option.
{
    int choice = 0;
    
    cout<<"Bem vindo ao Menu"<<endl<<endl;
    cout<<"Essa aplicação fornece os seguintes recursos:"<<endl<<endl;
    cout<<"MENU:"<<endl<<endl<<"1 - BubbleSort"<<endl<<"2 - InsertionSort"<<endl<<"3 - SelectionSort"<<endl<<endl<<"0 - Sair"<<endl<<endl;
    
    do
    {
        if(choice != 0)
            cout<<"Opção Inválida! Escolha novamente"<<endl;
        cout<<"Opção escolhida: ";
        cin>>choice;
    } while(choice < 1 && choice > 3);
    
    return choice;
}
unsigned long int bubbleSort(int v[], int length)
{
    unsigned long int bubbleInteractions = 0;
    int aux, n = 0;
    bool onOrder = false;
    while(!onOrder)
    {
        for (int i = 0; i < length - n; i++){
            if (v[i] > v[i + 1] && i + 1 < length - n) {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                bubbleInteractions += 4; //The vector is used 4 times.
            }
            bubbleInteractions += 2; //The condition use the vector 2 times.
        }
        if(n == length)
            onOrder = true;
        else
            n++;
    }
    return bubbleInteractions;
}
unsigned long int insertionSort(int v[], int length)
{
    unsigned long int insertionInteractions = 0;
    int aux, back;
    for(int i = 1; i < length; i++)
    {
        aux = v[i];
        back = i -1;
        while(back >= 0 && v[back] > aux)
        {
            v[back + 1] = v[back];
            back = back - 1;
            insertionInteractions += 2; //The vector is used times inside while loop.
        }
        v[back + 1] = aux; 
        insertionInteractions += 3; //The vector is used 2 times in for and 1 time in while condition.
    }
    return insertionInteractions;
}
unsigned long int selectionSort(int v[], int length)
{
    unsigned long int selectionInteractions = 0;
    int aux = 0, pos = 0;
    for(int i = 0; i < length; i++)
    {
        aux = v[i];
        pos = i;
        for(int j = i + 1; j < length; j++)
        {
            if(v[j] < aux)
            {
                aux = v[j];
                pos = j;
                selectionInteractions++; //The vector is used 1 time inside if.
            }
            selectionInteractions += 1; //The vector is used 1 time in if condition.
        }
        v[pos] = v[i];
        v[i] = aux;
        selectionInteractions += 4; //the vector is used 4 times inside for loop.
    }
    return selectionInteractions;
}
void showVector(int* v, int length)
{
    for(int i = 0; i < length; i++)
    {
        cout<<*(v + i)<<endl;
    }
}

void vectorGrow()
{
    for(int i = 0; i < QUANTITY; i++)
    {
        myGrowVector[i] = i;
    }
}

void vectorDown()
{
    for(int i = QUANTITY; i >= 0; i--)
    {
        myDownVector[QUANTITY - i] = i;
    }
}
void vectorAleatory()
{
    int generatedPosition = 0;
    for(int i = 0; i < QUANTITY; i++)
        myAleatoryVector[i] = -1;
    
    for(int x = 0, actualPos = 0; x < QUANTITY; x++)
    {
        generatedPosition = 0 + rand() % QUANTITY;
        if(actualPos + generatedPosition >= QUANTITY)
            actualPos = (actualPos + generatedPosition)%QUANTITY;
        else
            actualPos += generatedPosition;
        
        if(myAleatoryVector[actualPos] == -1)
            myAleatoryVector[actualPos] = x;
        else
        {
            while(myAleatoryVector[actualPos] != -1)
            {
                actualPos++;
                if(actualPos >= QUANTITY)
                {
                    actualPos = (actualPos + actualPos)%QUANTITY;
                }
            }
            myAleatoryVector[actualPos] = x;
        }
        
    }
}

int main(int argc, char** argv) {
    
    srand(time(NULL));
    
    
    int userChoice;
    do {
        
        vectorGrow();
        vectorDown();
        vectorAleatory();
        userChoice = menuOption();
        
        switch (userChoice) {
            case 1:
                cout << "Essa é a ordenação por BubbleSort." << endl;
                cout<<"CRESCENTE - Número de interações: "<<bubbleSort(myGrowVector, QUANTITY)<<endl;
                cout<<"DECRESCENTE - Número de interações: "<<bubbleSort(myDownVector, QUANTITY)<<endl;
                cout<<"ALEATÓRIO - Número de interações: "<<bubbleSort(myAleatoryVector, QUANTITY)<<endl;
                break;
            case 2:
                cout << "Essa é a ordenação por InsertionSort." << endl;
                cout<<"CRESCENTE - Número de interações: "<<insertionSort(myGrowVector, QUANTITY)<<endl;
                cout<<"DECRESCENTE - Número de interações: "<<insertionSort(myDownVector, QUANTITY)<<endl;
                cout<<"ALEATÓRIO - Número de interações: "<<insertionSort(myAleatoryVector, QUANTITY)<<endl;
                break;
            case 3:
                cout << "Essa é a ordenação por SelectionSort." << endl;
                cout<<"CRESCENTE - Número de interações: "<<selectionSort(myGrowVector, QUANTITY)<<endl;
                cout<<"DECRESCENTE - Número de interações: "<<selectionSort(myDownVector, QUANTITY)<<endl;
                cout<<"ALEATÓRIO - Número de interações: "<<selectionSort(myAleatoryVector, QUANTITY)<<endl;
                break;
        }
    }while(userChoice != 0);
    
    return 0;
}

