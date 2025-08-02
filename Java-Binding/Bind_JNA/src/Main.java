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
