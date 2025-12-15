import java.lang.annotation.*;

@Target({ElementType.TYPE,  ElementType.FIELD})
@Retention(RetentionPolicy.RUNTIME)
public @interface Default {
    Class<?> value();
}
