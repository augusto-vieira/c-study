# 	Acesando bibliotecas nativas com JNA e JNI  

Existem certas situações que precisamos usar código compilado nativamente para uma arquitetura específica para realizar determinadas tarefas. Alguns motivos são:
   
   - A necessidade de lidar com algum hardware.
   - Melhoria de desempenho para um processo muito exigente
   - Uma biblioteca existente que queremos reutilizar em vez de reescrevê-la em Java.
   - Acesso a driver e API fornecido através de DLL(Dynamic Link Library) ou SO (Shared Object)

Neste caso, a Oracle disponibiliza duas alternativas para acessar bibliotecas nativas em Java, o JNI (Java Native Interface) e o JNA (Java Native API).

### **JNI - Java Native Interface**

O padrão de fábrica é um dos padrões de design mais usados ​​em Java. Esse tipo de padrão de design está incluído no padrão de criação, pois esse padrão fornece uma das melhores maneiras de criar um objeto.

No padrão de fábrica, criamos o objeto sem expor a lógica de criação ao cliente e nos referimos ao objeto recém-criado usando uma interface comum.

O que é JNA e JNI?
Diferenças de JNA e JNI ?
Quando usar JNA ou JNI? 

### **JNA - Java Native API**
Precisamos baixar o jar que pode ser encontrado no [repositório oficial do JNA.](https://github.com/java-native-access/jna)

   * Para invocar o código em C diretamente do Java, precisamos criar uma interface que representará a nossa biblioteca nativa. Esta interface deve herdar de com.sun.jna.Library:
#### CLibrary.java
``` java
import com.sun.jna.Library;
import com.sun.jna.Native;
import com.sun.jna.Platform;

public interface CLibrary extends Library{

// Usando libs do C
      CLibrary INSTANCE = Native.load(Platform.isWindows() ? "msvcrt" : "c", CLibrary.class);
      double cosh(double value);
      void printf(String format, Object... args);
}
```

#### MinhaLibC.java
``` java

import com.sun.jna.Library;
  
public interface MinhaLibC extends Library{
      void helloWorld();
}
```

#### MinhaLibC.java
``` java

import com.sun.jna.Native;
import com.sun.jna.Platform;

public class Main {

   public static void main(String[] args) {

   // CLibrary lib = Native.load(Platform.isWindows()?"msvcrt":"c", CLibrary.class);
      CLibrary lib = CLibrary.INSTANCE;

      double result = lib.cosh(1);
      System.out.printf("O valor eh : %2f\n", result);
      lib.printf("Printf do C ...\n");

      //MinhaLibC mylib =  (MinhaLibC) Native.load(Platform.isWindows()?"Test.dll":"c", MinhaLibC.class);
      // MinhaLibC mylib =  Native.load(Platform.isWindows()?"myLib":"c", MinhaLibC.class);

      MinhaLibC mylib =  Native.load(Platform.isLinux()?"myLib":"c", MinhaLibC.class);
      mylib.helloWorld();
   }
}
```
Compilando código Java:
// necessário adicionar o jar da jna no classpath
javac -classpath jna-jpms-5.8.0.jar:jna-platform-jpms-5.8.0.jar CLibrary.java Main.java MinhaLibC.java

Executar:
java -cp jna-jpms-5.8.0.jar:. Main

## Implementação

Vamos criar uma **interface Shape** e classes implementando a interface Shape. Uma classe de fábrica **ShapeFactory** é definida como uma próxima etapa.

**FactoryPatternDemo** , nossa classe demo usará ShapeFactory para obter um objeto Shape . Ele vai passar informações ( CÍRCULO / RETANGLE / QUADRADO ) para a ShapeFactory para obter o tipo de objeto de que precisa.

![Diagrama](https://www.tutorialspoint.com/design_pattern/images/factory_pattern_uml_diagram.jpg)



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

      //Obtém um objeto do tipo Retângulo e chama seu método de desenho.
      Shape shape2 = shapeFactory.getShape("RECTANGLE");

      //Chama o método de desenho do Retângulo
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

![DiagramaEmC](https://github.com/augusto-vieira/LinguagemC_Design_Patterns/blob/master/Design%20patterns/img/Patterns.png)


Passo 1: Criar um arquivo **Shape.h**, declamos neste arquivo uma struc(Shape_t) que representa nossa Classe de interface.
#### Shape.h
``` C
typedef struct 
{
   // Representa nosso Método draw():void em Java
   void(*draw)(void);
} Shape_t;

``` 
Passo 2: Criar um arquivo **Rectangle.h** e **Rectangle.c**, que representa a criação da nossa Classe e Implementação da Interface.
#### Rectangle.h
``` C
#include "Shape.h"

typedef struct 
{
   // A Classe Rectangle_t recebe o Método draw()
   Shape_t *draw;
} Rectangle_t;

// Método que irá instanciar o objeto Retângulo
Shape_t new_Rectangle();
``` 
#### Rectangle.c
``` C
#include <stdio.h>
#include "Rectangle.h"

// Método Retângulo
static void rectangle_draw()
{
   printf("Inside Rectangle::draw() method.\n");
}

Shape_t new_Rectangle()
{
   // Atribui o método do Retângulo rectangle_draw() ao draw do objeto retangulo
   Shape_t retangulo =
   {
      .draw = rectangle_draw
   };

   // Retorna o objeto
   return retangulo;
}
``` 

#### Square.h
``` C
#include "Shape.h"

typedef struct 
{
   // A Classe Square_t recebe o Método draw()
   Shape_t *draw;
} Square_t;

// Método que irá instanciar o objeto Square
Shape_t new_Square();
``` 
#### Square.c
``` C
#include <stdio.h>
#include "Square.h"

// Método Quadrado
static void square_draw()
{
   printf("Inside Square::draw() method.\n");
}

Shape_t new_Square()
{
   // Atribui o método do Quadrado square_draw() ao draw do objeto quadrado
   Shape_t quadrado =
   {
      .draw = square_draw
   };

   return quadrado;
}
``` 

#### Circle.h
``` C
#include "Shape.h"

typedef struct 
{
   // A Classe Circle_t recebe o Método draw()
   Shape_t *draw;
} Circle_t;

// Método que irá instanciar o objeto Circle
Shape_t new_Circle();
``` 
#### Circle.c
``` C
#include <stdio.h>
#include "Circle.h"

// Método Circle
static void circulo_draw()
{
    printf("Inside Circle::draw() method.\n");
}

Shape_t new_Circle()
{
   // Atribui o método do Circulo circulo_draw() ao draw do objeto circulo
   Shape_t circulo =
   {
      .draw = circulo_draw
   };
   
   // Retorna o objeto
   return circulo;
}
``` 

#### ShapeFactory.h
``` C
#include "Shape.h"

typedef struct 
{
   // A Classe ShapeFactory recebe o Método getShape()
   Shape_t (*getShape)(const char *shapeType);
} ShapeFactory;

// Método que irá instanciar o objeto ShapeFactory
ShapeFactory new_ShapeFactory();
``` 

#### ShapeFactory.c
``` C
#include <stdio.h>
#include <string.h>

#include "ShapeFactory.h"
#include "Shape.h"

#include "Circle.h"
#include "Square.h"
#include "Rectangle.h"

// Método getShape para obter o objeto do tipo de forma
Shape_t get_draw(const char *shapeType)
{
    // Objeto forma
    Shape_t forma;

    if( !(strcmp(shapeType, "CIRCULO")))
    {
      // Cria o objeto Circulo e atribui no objeto forma
      forma =  new_Circle();
    }
    
    if( !(strcmp(shapeType, "SQUARE")))
    {
      // Cria o objeto Quadrado e atribui no objeto forma
      forma = new_Square();	
        
    }		
    
    if( !(strcmp(shapeType, "RECTANGLE")))
    {
      // Cria o objeto Retâgunlo e atribui no objeto forma
      forma =  new_Rectangle(); 
    }
    
   // Retorna o objeto
   return forma;	 		
}

ShapeFactory new_ShapeFactory()
{
   ShapeFactory shapeFactory;
   // Atribui o método get_draw(const char *shapeType) ao getShape do objeto shapeFactory
   
   shapeFactory.getShape = get_draw;

   // Retorna o objeto
   return shapeFactory;
}
``` 
Passo 4: Criar um arquivo **main.c**, para obter o objeto da classe passando uma informação como tipo dela.

#### main.c
``` C
#include <stdio.h>

#include "Shape.h"
#include "ShapeFactory.h"

int main(void)
{
  ShapeFactory shapeFactory = new_ShapeFactory();

  Shape_t shape = shapeFactory.getShape("CIRCULO");
  shape.draw();

  shape = shapeFactory.getShape("SQUARE");
  shape.draw();

  shape = shapeFactory.getShape("RECTANGLE");
  shape.draw();

return 0;
}
``` 
#### Output:

``` 
Inside Circle::draw() method.
Inside Rectangle::draw() method.
Inside Square::draw() method.
```

### Referência:
- https://www.tutorialspoint.com/design_pattern/factory_pattern.htm


