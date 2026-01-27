package org.example.carscrud.controller;

import org.example.carscrud.model.Manufacturer;
import org.example.carscrud.repository.ManufacturerRepository;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;
import java.util.Optional;

@Controller
@RequestMapping("/manufacturers")
public class ManufacturerController {
    private final ManufacturerRepository manufacturerRepo;

    public ManufacturerController(ManufacturerRepository manufacturerRepo) {
        this.manufacturerRepo = manufacturerRepo;
    }

    @GetMapping
    public String list(Model model) {
        model.addAttribute("manufacturers", manufacturerRepo.findAll());
        return "manufacturers/list";
    }

    @GetMapping("/new")
    public String newForm(Model model) {
        model.addAttribute("manufacturer", new Manufacturer());
        return "manufacturers/form";
    }

    @PostMapping("/create")
    public String create(@ModelAttribute Manufacturer manufacturer) {
        manufacturerRepo.save(manufacturer);
        return "redirect:/manufacturers";
    }

    @GetMapping("/{id}/edit")
    public String editForm(@PathVariable Long id, Model model) {
        model.addAttribute("manufacturer", manufacturerRepo.findById(id).orElseThrow());
        return "manufacturers/form";
    }

    @PostMapping("/{id}")
    public String update(@PathVariable Long id, @ModelAttribute Manufacturer manufacturer) {
        manufacturer.setManufacturerId(id);
        manufacturerRepo.save(manufacturer);
        return "redirect:/manufacturers";
    }

    @PostMapping("/{id}/delete")
    public String delete(@PathVariable Long id) {
        manufacturerRepo.deleteById(id);
        return "redirect:/manufacturers";
    }

    @GetMapping("/{id}")
    public String details(@PathVariable Long id, Model model) {
        Manufacturer m = manufacturerRepo.findById(id).orElseThrow();
        model.addAttribute("manufacturer", m);
        model.addAttribute("models", m.getModels()); // если есть связь OneToMany
        return "manufacturers/details";
    }

    @PostMapping
    public String save(@ModelAttribute Manufacturer man, Model modelAttr) {

        Optional<Manufacturer> existing = manufacturerRepo.findByName(man.getName());

        if (existing.isPresent() && !existing.get().getManufacturerId().equals(man.getManufacturerId())) {
            modelAttr.addAttribute("error", "Производитель с таким именем уже существует");
            return "manufacturers/form";
        }

        manufacturerRepo.save(man);
        return "redirect:/manufacturers";
    }

}
