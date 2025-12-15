public class Class11 {
    @Invoke
    public void doTask() {
        System.out.println("Задача выполнена");
    }

    @Invoke
    private void hiddenTask() {
        System.out.println("Скрытая задача");
    }

    public void regular() {
        System.out.println("Обычный метод");
    }
}