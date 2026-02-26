import java.lang.reflect.Method;
import java.lang.reflect.Field;

public class Processor {
    public static void invokeAll(Object obj) {
        // Получаем класс объекта
        Class<?> clazz = obj.getClass();
        Method[] methods = clazz.getDeclaredMethods();
        for (Method method : methods) {
            // Проверяем, есть ли аннотация @Invoke у класса
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
            String str;
            str = obj.getClass().getSimpleName() + "[";

            // Берём все поля
            Field[] fields = obj.getClass().getDeclaredFields();
            boolean first = true;

            for (Field field : fields) {
                field.setAccessible(true);

                // Смотрим аннотацию
                ToString ann = field.getAnnotation(ToString.class);

                // Если аннотации нет или она true - добавляем поле
                if (ann == null || ann.value() == Mode.YES) {
                    if (!first) str = str + ", ";
                    str = str + field.getName() + "=" + field.get(obj);
                    first = false;
                }
            }
            str = str + "]";
            return str;
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

    public static void AnnotationTwo(Class<?> clazz) {
        // Проверяем, есть ли аннотация @Two
        if (clazz.isAnnotationPresent(Two.class)) {
            // Получаем аннотацию
            Two annotation = clazz.getAnnotation(Two.class);

            // Читаем и выводим значения свойств
            System.out.println("Выводим данные об анотации перед классом:\nfirst = " + annotation.first() + "\nsecond = " + annotation.second());
        } else {
            System.out.println("Аннотация @Two не найдена на классе " + clazz.getName());
        }
    }

    public static void AnnotationCache(Class<?> clazz) {
        // Проверяем наличие аннотации @Cache
        if (clazz.isAnnotationPresent(Cache.class)) {
            Cache cache = clazz.getAnnotation(Cache.class);
            String[] cacheAreas = cache.value();

            // Проверяем, пустой ли массив
            if (cacheAreas.length == 0) {
                System.out.println("Список кешируемых областей ПУСТ");
            } else {
                System.out.println("Кешируемые области (" + cacheAreas.length + "):");
                for (int i = 0; i < cacheAreas.length; i++) {
                    System.out.println("    " + (i + 1) + ". " + cacheAreas[i]);
                }
            }
        } else {
            System.out.println("Аннотация @Cache отсутствует");
        }
        System.out.println();
    }
}