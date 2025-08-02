import com.sun.jna.Library;
import com.sun.jna.Native;
import com.sun.jna.Platform;

public interface CLibrary extends Library{
    
    // Usando libs do C
       CLibrary INSTANCE = Native.load(Platform.isWindows() ? "msvcrt" : "c", CLibrary.class);
       double cosh(double value);
       void printf(String format, Object... args);
}
