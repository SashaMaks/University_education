@ToString
public class Class13 {
    @ToString(Mode.YES)
    private String name = "Иван";

    @ToString(Mode.NO)
    private String password = "secret";

    @ToString  // по умолчанию Mode.YES
    private int age = 25;
}
