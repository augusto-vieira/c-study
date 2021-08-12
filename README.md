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
```bash
$ javac -classpath jna-jpms-5.8.0.jar:jna-platform-jpms-5.8.0.jar Main.java CLibrary.java MinhaLibC.java

```
Executar:
```bash
// necessário adicionar o jar da jna no classpath
$ java -cp jna-jpms-5.8.0.jar:. Main
```


## Implementação

#### .java
``` java
}
```
#### .java
``` java
}
```
#### .java
``` java
}
```





### Referência:
- https://docs.oracle.com/javase/8/docs/technotes/tools/unix/classpath.html
- https://www.baeldung.com/java-jna-dynamic-libraries
- https://www.techbeamers.com/write-a-simple-jna-program-in-java/

