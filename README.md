# 	Padrão de Design - Padrão de Fábrica 

O padrão de fábrica é um dos padrões de design mais usados ​​em Java. Esse tipo de padrão de design está incluído no padrão de criação, pois esse padrão fornece uma das melhores maneiras de criar um objeto.

No padrão de fábrica, criamos o objeto sem expor a lógica de criação ao cliente e nos referimos ao objeto recém-criado usando uma interface comum.

## Implementação

Vamos criar uma **interface Shape** e classes implementando a interface Shape. Uma classe de fábrica **ShapeFactory** é definida como uma próxima etapa.

**FactoryPatternDemo** , nossa classe demo usará ShapeFactory para obter um objeto Shape . Ele vai passar informações ( CÍRCULO / RETANGLE / QUADRADO ) para a ShapeFactory para obter o tipo de objeto de que precisa.

![Diagrama](https://www.tutorialspoint.com/design_pattern/images/factory_pattern_uml_diagram.jpg)

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

![DiagramaEmC](https://github.com/augusto-vieira/LinguagemC_Design_Patterns/blob/master/Design%20patterns/img/Patterns.png)

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


### Referência:
- https://www.tutorialspoint.com/design_pattern/factory_pattern.htm


