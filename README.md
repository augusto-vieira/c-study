# •	Padrão de Design - Padrão de Fábrica 

O padrão de fábrica é um dos padrões de design mais usados ​​em Java. Esse tipo de padrão de design está incluído no padrão de criação, pois esse padrão fornece uma das melhores maneiras de criar um objeto.

No padrão de fábrica, criamos o objeto sem expor a lógica de criação ao cliente e nos referimos ao objeto recém-criado usando uma interface comum.

## Implementação

Vamos criar uma **interface Shape** e classes implementando a interface Shape. Uma classe de fábrica **ShapeFactory** é definida como uma próxima etapa.

**FactoryPatternDemo** , nossa classe demo usará ShapeFactory para obter um objeto Shape . Ele vai passar informações ( CÍRCULO / RETANGLE / QUADRADO ) para a ShapeFactory para obter o tipo de objeto de que precisa.

![Diagrama](https://www.tutorialspoint.com/design_pattern/images/factory_pattern_uml_diagram.jpg)


Uma **Pilha** é um tipo especial de **Lista**.

Inserções e exclusões de elementos ocorrem apenas no início da Pilha.

![Pilha Estatica](https://github.com/augusto-vieira/LinguagemC_Pilha/blob/master/PilhaEstatica/img/gif/Push_Pop.gif)

1. **Aplicações:**
    - Análise de uma expressão matemática 
    - Avaliação de expressão pós-fixa
    - Converter uma expressão in-fixa para pós-fixa
    - Converter um número decimal para binário
    - Gerenciamento de memória
    - Problemas de Backtracking
    - etc


2. **Em uma "Pilha" podemos realizar as seguintes operações básicas::**
    - Criação da pilha
    - Inserção de um elemento no "início"
    - Exclusão de um elemento do "inicio"
    - Acesso a um elemento do "inicio"
    - Destruição da Pilha
    - etc


3. **Essas operações dependem do tipo de alocação de memória usa**
    - **Estática**
    - Dinâmica

Alocação estática:  

>- O espaço de memória é alocada no momento da compilação
>-  Existe a definição do número máximo de elementos da “Pilha”
>- Acesso sequencial: elementos consecutivos da memória 


## **Pilha Estática**
Tipo de "Pilha" onde o sucessor de um elemento ocupa a posição física seguinte do mesmo(uso de "array").

![Pilha pi](https://github.com/augusto-vieira/LinguagemC_Pilha/blob/master/PilhaEstatica/img/Pilha_pi.png)


Definimos a Pilha em dois arquivos.

**"PilhaSequencial.h" :** Definir
- Os protótipos das funções
- O tipo de dado armazenado na pilha
- O ponteiro "pilha"
- Tamanho do vetor usado na pilha

**"PilhaSequencial.h" :** Definir
- O tipo de dados  "pilha"
- Implementar as suas funções. 


**Algumas informações básicas sobre a pilha:**
 - Tamanho
 - Se está cheia



>Em uma "Pilha" a inserção é sempre no início/topo. Também existe o caso em que a inserção é feita em uma “Pilha” que está vazia.
>
>**Cuidado:** não se pode inserir em uma pilha cheia.

>Em uma "Pilha" a remoção é sempre no seu início/topo.
>
>**Cuidado:** não se pode remover de uma pilha vazia.

> Em uma "Pilha" a consulta se dá apenas ao elemento que está no seu início.


``` C
/* PilhaSequencial.h */

// tamanho máximo do vetor que representa a pilha
#define MAX 100

// elemento/dado que será armazena em cada posição do vetor pilha
struct aluno
{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct pilha Pilha;
```

``` c
/* PilhaSequencial.c */
#include<stdio.h>
#include <stdlib.h>

#include "PilhaSequencial.h"

struct pilha
{
   int qtd;
   struct aluno dados[MAX]; 
};
``` 
Passo 1: Criar interface
#### Shape.java
``` java
public interface Shape {
   void draw();
}
```

Passo 2: Criar as classes e implementar a Inteface
#### Rectangle.java
``` java
public class Rectangle implements Shape {

   @Override
   public void draw() {
      System.out.println("Inside Rectangle::draw() method.");
   }
}
```
#### Square.java
``` java
public class Square implements Shape {

   @Override
   public void draw() {
      System.out.println("Inside Square::draw() method.");
   }
}
```
#### Circle.java
``` java
public class Circle implements Shape {

   @Override
   public void draw() {
      System.out.println("Inside Circle::draw() method.");
   }
}
```
Passo 3: Criar uma Classe(fábrica) para gerar os objetos das classes com base nas informações fornecidas
#### ShapeFactory.java
``` java
public class ShapeFactory {
	
   //usa o método getShape para obter o tipo de forma do objeto
   public Shape getShape(String shapeType){
      if(shapeType == null){
         return null;
      }		
      if(shapeType.equalsIgnoreCase("CIRCLE")){
         return new Circle();
         
      } else if(shapeType.equalsIgnoreCase("RECTANGLE")){
         return new Rectangle();
         
      } else if(shapeType.equalsIgnoreCase("SQUARE")){
         return new Square();
      }
      
      return null;
   }
}
```
Passo 4: Usa o Factory para obter o objeto da classe, passando uma informação do tipo.

#### FactoryPatternDemo.java
``` java
public class FactoryPatternDemo {

   public static void main(String[] args) {
      ShapeFactory shapeFactory = new ShapeFactory();

      //Obtém um objeto do tipo Círculo e chama seu método de desenho.
      Shape shape1 = shapeFactory.getShape("CIRCLE");

      //Chama o método de desenho do Círculo
      shape1.draw();

      //Obtém um objeto do tipo Retangulo e chama seu método de desenho.
      Shape shape2 = shapeFactory.getShape("RECTANGLE");

      //Chama o método de desenho do Retangulo
      shape2.draw();

      //Obtém um objeto do tipo do Quadrado e chama seu método de desenho.
      Shape shape3 = shapeFactory.getShape("SQUARE");

       //Chama o método de desenho do Quadrado
      shape3.draw();
   }
}
```

#### Output:

``` 
Inside Circle::draw() method.
Inside Rectangle::draw() method.
Inside Square::draw() method.
```

# Implementação em C

 **Definição:**

    - Classe =  typedef de uma struct
    - Atributos = variáveis (int,char, ...)
    - Métodos =  funções
        - método private = funções static



### Referência:
- https://www.tutorialspoint.com/design_pattern/factory_pattern.htm


