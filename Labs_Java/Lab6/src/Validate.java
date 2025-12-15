import java.lang.annotation.*;

@Target({ElementType.TYPE,  ElementType.ANNOTATION_TYPE})
@Retention(RetentionPolicy.RUNTIME)
public @interface Validate {
    Class<?>[] value();
}
