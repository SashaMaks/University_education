@Validate({NotNullValidator.class, PositiveValidator.class, EmailValidator.class})
public class Class14 {
    private String name;
    private int age;
    private String email;

    public Class14(String name, int age, String email) {
        this.name = name;
        this.age = age;
        this.email = email;
    }
}

class NotNullValidator {
    public boolean isValid(Object obj) {
        return obj != null;
    }
}

class PositiveValidator {
    public boolean isValid(Number num) {
        return num.doubleValue() > 0;
    }
}

class EmailValidator {
    public boolean isValid(String email) {
        return email != null && email.contains("@");
    }
}