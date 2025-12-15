import java.lang.reflect.Method;
import java.lang.reflect.Field;

public class Processor {
    public static void invokeAll(Object obj) {
        // Получаем класс объекта
        Class<?> clazz = obj.getClass();
        Method[] methods = clazz.getDeclaredMethods();
        for (Method method : methods) {
            // Проверяем, есть ли аннотация @Invoke
            if (method.isAnnotationPresent(Invoke.class)) {
                try {
                    method.setAccessible(true);
                    method.invoke(obj);
                } catch (Exception e) {
                    System.out.println("Ошибка при вызове " + method.getName() + ": " + e.getMessage());
                }
            }
        }
    }

    public static void processDefault(Class<?> clazz) {
        // Проверяем, есть ли аннотация @Default у класса
        if (clazz.isAnnotationPresent(Default.class)) {
            // Получаем аннотацию
            Default ann = clazz.getAnnotation(Default.class);

            Class<?> defaultClass = ann.value();
            System.out.println("Класс: " + clazz.getSimpleName());
            System.out.println("Класс по умолчанию: " + defaultClass.getSimpleName());
        } else {
            System.out.println("У класса " + clazz.getSimpleName() + " нет аннотации @Default");
        }
    }

    public static String ToString(Object obj) {
        try {
            StringBuilder sb = new StringBuilder();
            sb.append(obj.getClass().getSimpleName()).append("[");

            // Берём все поля
            Field[] fields = obj.getClass().getDeclaredFields();
            boolean first = true;

            for (Field field : fields) {
                field.setAccessible(true);

                // Смотрим аннотацию
                ToString ann = field.getAnnotation(ToString.class);

                // Если аннотации нет или она true - добавляем поле
                if (ann == null || ann.value() == Mode.YES) {
                    if (!first) sb.append(", ");
                    sb.append(field.getName()).append("=").append(field.get(obj));
                    first = false;
                }
            }

            sb.append("]");
            return sb.toString();
        } catch (Exception e) {
            return "Ошибка при преобразовании: " + e.getMessage();
        }
    }

    public static void printValidationClasses(Class<?> clazz) {
        // Проверяем, есть ли аннотация @Validate
        if (clazz.isAnnotationPresent(Validate.class)) {
            // Получаем аннотацию
            Validate validate = clazz.getAnnotation(Validate.class);

            // Получаем массив классов
            Class<?>[] validatorClasses = validate.value();

            System.out.println("Класс: " + clazz.getSimpleName());
            System.out.println("Классы для валидации (" + validatorClasses.length + "):");

            // Выводим каждый класс
            for (Class<?> validatorClass : validatorClasses) {
                System.out.println("  - " + validatorClass.getSimpleName());
            }
        } else {
            System.out.println("Класс " + clazz.getSimpleName() + " не имеет аннотации @Validate");
        }
    }
}