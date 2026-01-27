## Максимов Александр ИТ-17-2024
### Вариант 9

# Лабораторная работа №5
## Задание 1
В класс Дробь, добавить интерфейс на два метода: получение вещественного значения, установка числителя и установка знаменателя.
Сгенерировать такую версию дроби, которая будет кэшировать вычисление вещественного значения

#### Решение:
Создадим класс ```Fraction``` который будет содержать:
#### поля
  1. `protected int numerator;` - числитель
  2. `protected int denominator;` - знаменатель
#### конструкторы 
  1. `public Fraction()` - для создания дроби 0/1
  2. `public Fraction(int numerator, int denominator)` - для создания дроби по числителю и знаменателю
#### геттеры
  1. `public int getNumerator()` - возвращает числитель
  2. `public int getDenominator()` - возвращает знаменатель
  3. `public double getDouble()` - возвращает дробь в виде десятичной дроби
#### сеттеры
  1. `public void setFraction(int numerator, int denominator)` - устанавливает в дроби новые числитель и знаменатель
  2. `public void setNumerator(int numerator)` - устанавливает числитель
  3. `public void setDenominator(int denominator)` - устанавливает знаменатель
  4. `public void setFraction(Fraction fraction)` - устанавливает дробь через объект дробь
#### дополнительные методы
  1. `public void simplification()` - метод для упрощения дроби
  2. `public boolean equals(Object obj)` - метод для сравнения дроби и другого объекта
#### преобразование в строку
  1. `public String toString()` - выводит объект в виде “{numerator}/{denominator}”

Создадим интерфейс `Fractions` с объявлением методов
1. `double getDouble()` - получение вещественного значения
2. `void setNumerator(int numerator);` - установка числителя
3. `void setDenominator(int denominator);` - установка знаменателя 

Создадим новый класс `FractionCache` с наследованием класса `Fraction`, переопределим некоторые методы оттуда:
#### поля
  1. `private Double cache` - кэш вещественного числа дроби
#### конструкторы 
  1. `public FractionCache(int numerator, int denominator)` - для создания кэшируемой дроби по числителю и знаменателю
#### дополнительные методы
  1. `public void setFraction(Fraction fraction)` - установить дробь, через дробь, удалить кэш
  2. `public void setNumerator(int numerator)` - установить числитель, удалить кэш
  3. `public void setDenominator(int denominator)` - установить знаменатель, удалить кэш
  4. `public double getDouble()` - получить вещественное значение и кэшироовать его, если кэш пустой, иначе вернуть кэш

<img width="772" height="549" alt="image" src="https://github.com/user-attachments/assets/50c5dac4-c8ca-40b8-a533-444a4c8a7723" />

## Задание 2

#### Количество мяуканий.
Необходимо воспользоваться классом Кот и методом принимающим всех мяукающих из задачи 2.5.4.
Необходимо таким образом передать кота в указанный метод, что бы после окончания его работы узнать сколько раз мяукал кот за время его работы. На рисунке показан пример работы. Перед вызовом метода создаем кота, отправляем ссылку на кота в метод, после окончания его работы выводим количество мяуканий на экран. Кота изменять нельзя.

#### Решение:
Создадим интерфейс `Meowing` с объявлением метода `void meow()` - мяукнуть 

Создадим класс `Cat`
#### поля
  1. `private String name;` - имя
  2. `private int meowCount;` - количество мяуканий
#### конструкторы 
  1. `public Cat(String name)` - для создания кота по имени
  2. `public Cat(String name, int meowCount)` - для создания кота по имени и количеству мяуканий
#### геттеры
  1. `public String getName()` - возвращает имя
  2. `public int getMeowCount()` - возвращает количество мяуканий
#### сеттеры
  1. `public void setName(String name)` - устанавливает имя для кота
  2. `public void setMeowCount(int meowCount)` - устанавливает количество мяуканий
#### дополнительные методы
  1. `public void meow()` - метод для мяукания (вывести мяу и добавить + к счетчику мяуканий)
#### преобразование в строку
  1. `public String toString()` - выводит объект в виде “кот: {name}”

В демонстрации задания создаем список "мяукающих" и добавляем туда созданного ранее кота, далее вызовем метод из класса написанного далее:

Класс `public class MeowEverybody` с методом `public static void makeAllMeow(Meowing... meowables)` - который 3 раза вызовет метод `meow()` для всех "мяукающих"

<img width="608" height="221" alt="image" src="https://github.com/user-attachments/assets/66fb953a-f017-4e78-905f-a655bde28994" />


## Задание 3

Составить программу, которая формирует список L, включив в него по одному разу элементы,
которые входят в список L1, но не входят в список L2.

#### Решение:
Создаем класс `public class ListOperation`
  1. `public static <T> List<T> getDifferenceSimple(List<T> L1, List<T> L2)` - метод который возвращает без повторений значения из L1 которых нету в L2
  2. `private static <T> boolean contains(List<T> list, T element)` - проверяет, есть ли элемент в подаваемом списке 

В Main просто достаточно вызвать getDifferenceSimple и приравнять его к выводимому списку

<img width="542" height="401" alt="image" src="https://github.com/user-attachments/assets/3211c4eb-8a97-4a62-b1b4-4ee344973b28" />


## Задание 4

Имеется список учеников разных школ, сдававших экзамен по информатике, с указанием их фамилии, имени, школы и набранного балла. Напишите программу, которая будет определять номера школ, в которых средний балл выше, чем средний по району. Известно, что информатику сдавали не менее 5 учеников.
На вход программе в первой строке подается количество учеников списке N. В каждой из последующих N строк находится информация в следующем формате:

<Фамилия><Имя><Школа><Балл>

где <Фамилия> – строка, состоящая не более, чем из 20 символов без пробелов, <Имя>– строка, состоящая не более, чем из 20 символов без пробелов, <Школа> – целое число от 1 до 99, <Балл> – целое число от 1 до 100.

#### Решение:
Напишем класс `analyzeSchools`, который анализирует данные об учениках и школах из файла
#### вспомогательные классы
1. Класс `public static class Student` 
##### Поля
  1. `private final String lastName`  - фамилия ученика
  2. `private final String firstName` - имя ученика
  3. `private final int school` - номер школы
  4. `private final int score` - балл ученика
##### Конструкторы
  1. `public Student(String lastName, String firstName, int school, int score)` - создает ученика через фамилию имя школу и балл
##### Геттеры
  1. `public String getLastName()` - возвращает фамилию
  2. `public String getFirstName()` - возвращает имя
  3. `public int getSchool()` - возвращает номер школы
  4. `public int getScore()` - возвращает балл
##### Преобразование в строку
  1. `public String toString()` - выводит данные в формате "Фамилия Имя Школа Балл"

2. Класс `public static class Student`
##### Поля
  1. `private int totalScore` - сумма баллов всех учеников школы
  2. `private int studentCount` - количество учеников в школе
##### Геттеры
  1. `public int getTotalScore()` - возвращает сумму баллов
  2. `public int getStudentCount()` - возвращает количество учеников
  3. `public double getAverage()` - вычисляет средний балл
##### Методы
  1. `public void addScore(int score)` - добавляет балл ученика к статистике
##### Преобразование в строку
  1. `public String toString()` - выводит статистику школы

#### методы для обработки текста
  1. `public List<Student> loadDataFromFile(String fileName) throws IOException` - читаем и проверяем на верность данные полученные из файла
  2. `private Student parseStudent(String line, int lineNumber)` - метод который делит строку из файла на данные
  3. `public List<Integer> analyze(List<Student> students)` - метод для вычисления среднего балла по району, группирования учеников по школам, поиском школ со средним баллом выше среднего и возвратом отсортированного списка таких школ
  4. ` private double calculateDistrictAverage(List<Student> students)` - вычисление среднего балла по району 
  5. `private Map<Integer, Double> calculateSchoolAverages(List<Student> students)` - вычисление среднего балла школы

Сначала мы открываем файл и читаем данные из него, проверяя их на правильность заполнения

если все верно, то делим строку из файла на эллементы
фамилия имя школа балл
если все верно, то создается студент (дополнительный класс созданный в классе, описывающий имя фамилию, школу где учится и балл) и добавляется в список студентов который возвращается

Далее переходим в метод анализа, где сначала вычисляем средний балл по району, далее через `map` делим студентов на школы где они учатся и ищем далее школы со средним баллом выше среднего

<img width="508" height="217" alt="image" src="https://github.com/user-attachments/assets/173a7009-2c73-4e50-b250-a8d2a934002e" />


## Задание 5

Файл содержит текст на русском языке. Какие символы встречаются в одном и только в одном
слове?

#### Решение:
Напишем класс `public class TextAnalyzer` для анализа текста
#### методы для обработки текста
  1. `public Set<Character> analyzeText(String text)` - делим строку по различным символам и пробелам, далее находим уникальные символы слова (через HashSet<> убираем повторы), если символ где-то встречался, то мы добавляем его в словарь `Map<Character, Integer> charFrequency = new HashMap<>();`, если символ до этого нигде не был встречен, то он запишется парой с текущим словом в словарь `Map<Character, String> charFirstWord = new HashMap<>();`, и далее идет формирование результата , что если символ встречался в словаре подсчета частоты встречи символов ровно один раз то он добавляется в результат
  2. `public static String readTextFromFile(String fileName)` - метод нужный только для чтения данных из файла, название которого подается в метод

Сначала читаем данные из файла, затем передаем их в метод `public Set<Character> analyzeText(String text)`, затем выводим

<img width="930" height="308" alt="image" src="https://github.com/user-attachments/assets/33e2c70b-fbe9-49fc-bf85-a59462ffb662" />

## Задание 6

Переписать элементы из очереди L1 в очередь L2 в обратном порядке.

#### Решение:
Напишем класс `QueueReverser` с единственным методом `public static <T> void reverseQueue(Queue<T> L1,Queue<T> L2)` который рекурсивно вытаскивает первый элемент из L1 до того момента пока очередь не опустеет, потом метод начинает просто добавлять элементы в конец L2 и подниматься из рекурсии

В Main мы создадим очереди и произведем вызов метода `reverseQueue(L1, L2)`

<img width="404" height="439" alt="image" src="https://github.com/user-attachments/assets/6f63a63f-99a3-474b-8a8c-27d91a36ad17" />


## Задание 7.1

Необходимо написать стрим:
Дан набор объектов типа Point, необходимо взять все Point в разных координатах, убрать с одинаковыми X,Y, отсортировать по X, отрицательные Y сделать положительными и собрать это все в ломаную (объект типа Polyline)

#### Решение:

Создадим класс `PointOperations()` с единственным методом `public static Polyline processPointsWithStream(List<Point> points)`, в котором через поток мы обрабатываем список точек 
  1. `.sorted(Comparator.comparingDouble(Point::getX))` - сортируем по X
  2. `.map(Point::withPositiveY)` - все отрицательные Y мы берем по модулю координаты Y
  3. `.distinct()` - убираем одинаковые координаты
  4. `.toArray(Point[]::new)` - преобразуем в массив
Возвращаем ломаную из массива точек

В Main мы создаем точки, далее вызваем метод `processPointsWithStream` и выводим полученную ломанную

<img width="427" height="374" alt="image" src="https://github.com/user-attachments/assets/1a715201-3fae-401f-a685-d91f8d8c7ec5" />

## Задание 7.2

Дан текстовый файл со строками, содержащими имя человека и его номер в следующей форме:
Вася:5
Петя:3
Аня:5
Номера людей могут повторяться. У каких-то людей может не быть номера.
Необходимо написать стрим выполняющую следующее: читаются все люди из файла, все имена приводится к нижнему регистру, но с первой буквой в верхнем регистре, убираем из перечня всех людей без номеров, а имена оставшихся группируются по их номеру:
[5:[Вася, Аня], 3:[Петя]]

#### Решение:
Создаем класс `public class PeoplesAndNumbers`
#### вспомогательный класс
Класс `public static class Person`
##### Поля
  1. `private String name`  - имя
  2. `private Integer number` - номер
##### Конструкторы
  1. `public Person(String name, Integer number)` - создает ученика с именем и номером
  2. `public Person(String name)` - создает ученика только именем
##### Геттеры
  1. `public String getName()` - возвращает имя
  2. `public Integer getNumber()` - возвращает номер
  3. `public String getFormattedName()` - возвращает обработаное имя (Начинается с большой буквы и дальше маленькие буквы)
##### Сеттеры
  1. `public void setName(String name)` - устанавливает имя
  2. `public void setNumber(Integer number)` - устанавливает номер
##### Преобразование в строку
  1. `public String toString()` - выводит данные в формате "{name} {если есть номер, то выведет ": {number}", иначе ""}"

#### Дополнительные методы
  1. `public static Map<Integer, List<String>> processFile(String filename) throws IOException` - возвращает словарь данных преобразованый из подаваемой строки (убирает все лишнее и преобразует пару номер-имя, если нет номера, то удалить это имя)
  2. `private static Person parseLine(String line)` - метод используемый в методе `processFile`, он преобразует подаваемую строчку в объект `Person`

В Main мы создаем словарь заполненный данными из `processFile` в который передали называние файла

<img width="163" height="268" alt="image" src="https://github.com/user-attachments/assets/105ce737-5a9a-4726-aae7-edabcddccfb3" />

<img width="656" height="50" alt="image" src="https://github.com/user-attachments/assets/86b90056-5a07-49ec-8eb9-1e046af2c099" />
