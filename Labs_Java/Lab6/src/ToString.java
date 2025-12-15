import java.lang.annotation.*;

@Target({ElementType.TYPE,  ElementType.FIELD})
@Retention(RetentionPolicy.RUNTIME)
public @interface ToString {
    Mode value() default Mode.YES;
}
