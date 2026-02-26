import java.lang.annotation.*;

@Target({ElementType.TYPE,  ElementType.FIELD})
@Retention(RetentionPolicy.RUNTIME)

public @interface Cache {
    String[] value() default {};
}
