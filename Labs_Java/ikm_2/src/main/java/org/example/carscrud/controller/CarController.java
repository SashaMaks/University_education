package org.example.carscrud.controller;

import org.example.carscrud.model.*;
import org.example.carscrud.repository.*;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.*;
import java.util.Optional;
import org.springframework.ui.Model;

/**
 * <summary>
 * Контроллер для управления автомобилями (Car).
 * Реализует операции просмотра списка, создания, редактирования,
 * обновления и удаления автомобилей.
 * Также выполняет проверку уникальности VIN-кода.
 * </summary>
 */
@Controller
@RequestMapping("/cars")
public class CarController {

    private final CarRepository carRepo;
    private final ModelRepository modelRepo;

    /**
     * <summary>
     * Конструктор контроллера автомобилей.
     * Инициализирует репозитории автомобилей и моделей.
     * </summary>
     *
     * <param name="carRepo">Репозиторий автомобилей.</param>
     * <param name="modelRepo">Репозиторий моделей автомобилей.</param>
     */
    public CarController(CarRepository carRepo, ModelRepository modelRepo) {
        this.carRepo = carRepo;
        this.modelRepo = modelRepo;
    }

    /**
     * <summary>
     * Отображает список всех автомобилей.
     * </summary>
     *
     * <param name="model">UI‑модель для передачи данных в представление.</param>
     * <return>Шаблон cars/list</return>
     */
    @GetMapping
    public String list(ModelMap model) {
        model.addAttribute("cars", carRepo.findAll());
        return "cars/list";
    }

    /**
     * <summary>
     * Открывает форму создания нового автомобиля.
     * </summary>
     *
     * <param name="model">UI‑модель для передачи данных.</param>
     * <return>Шаблон cars/form</return>
     */
    @GetMapping("/new")
    public String newForm(ModelMap model) {
        model.addAttribute("car", new Car());
        model.addAttribute("models", modelRepo.findAll());
        return "cars/form";
    }

    /**
     * <summary>
     * Создаёт новый автомобиль без проверки VIN.
     * Используется как базовый метод создания.
     * </summary>
     *
     * <param name="car">Сущность автомобиля.</param>
     * <return>Редирект на список автомобилей.</return>
     */
    @PostMapping("/create")
    public String create(@ModelAttribute Car car) {
        carRepo.save(car);
        return "redirect:/cars";
    }

    /**
     * <summary>
     * Открывает форму редактирования автомобиля.
     * </summary>
     *
     * <param name="id">Идентификатор автомобиля.</param>
     * <param name="model">UI‑модель для передачи данных.</param>
     * <return>Шаблон cars/form</return>
     */
    @GetMapping("/{id}/edit")
    public String editForm(@PathVariable Long id, ModelMap model) {
        model.addAttribute("car", carRepo.findById(id).orElseThrow());
        model.addAttribute("models", modelRepo.findAll());
        return "cars/form";
    }

    /**
     * <summary>
     * Обновляет данные автомобиля.
     * </summary>
     *
     * <param name="id">Идентификатор автомобиля.</param>
     * <param name="car">Обновлённая сущность автомобиля.</param>
     * <return>Редирект на список автомобилей.</return>
     */
    @PostMapping("/{id}")
    public String update(@PathVariable Long id, @ModelAttribute Car car) {
        car.setCarId(id);
        carRepo.save(car);
        return "redirect:/cars";
    }

    /**
     * <summary>
     * Удаляет автомобиль по идентификатору.
     * </summary>
     *
     * <param name="id">Идентификатор автомобиля.</param>
     * <return>Редирект на список автомобилей.</return>
     */
    @PostMapping("/{id}/delete")
    public String delete(@PathVariable Long id) {
        carRepo.deleteById(id);
        return "redirect:/cars";
    }

    /**
     * <summary>
     * Сохраняет автомобиль с проверкой уникальности VIN.
     * Если VIN уже существует — возвращает форму с ошибкой.
     * </summary>
     *
     * <param name="car">Сущность автомобиля.</param>
     * <param name="modelAttr">UI‑модель для передачи ошибок и данных.</param>
     * <return>Редирект или форма с ошибкой.</return>
     */
    @PostMapping
    public String save(@ModelAttribute Car car, Model modelAttr) {
        Optional<Car> existing = carRepo.findByVinCode(car.getVinCode());

        if (existing.isPresent() && !existing.get().getCarId().equals(car.getCarId())) {
            modelAttr.addAttribute("error", "Машина с таким VIN уже существует");
            modelAttr.addAttribute("models", modelRepo.findAll());
            return "cars/form";
        }

        carRepo.save(car);
        return "redirect:/cars";
    }
}
