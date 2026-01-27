package org.example.carscrud.controller;

import org.example.carscrud.repository.*;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import java.util.Optional;
import org.springframework.web.bind.annotation.*;


@Controller
@RequestMapping("/models")
public class ModelController {

    private final ModelRepository modelRepo;
    private final ManufacturerRepository manufacturerRepo;

    public ModelController(ModelRepository modelRepo, ManufacturerRepository manufacturerRepo) {
        this.modelRepo = modelRepo;
        this.manufacturerRepo = manufacturerRepo;
    }

    @GetMapping
    public String list(ModelMap model) {
        model.addAttribute("models", modelRepo.findAll());
        return "models/list";
    }

    @GetMapping("/new")
    public String newForm(ModelMap model) {
        model.addAttribute("model", new org.example.carscrud.model.Model());
        model.addAttribute("manufacturers", manufacturerRepo.findAll());
        return "models/form";
    }

    @PostMapping("/create")
    public String create(@ModelAttribute org.example.carscrud.model.Model m) {
        modelRepo.save(m);
        return "redirect:/models";
    }

    @GetMapping("/{id}/edit")
    public String editForm(@PathVariable Long id, ModelMap model) {
        model.addAttribute("model", modelRepo.findById(id).orElseThrow());
        model.addAttribute("manufacturers", manufacturerRepo.findAll());
        return "models/form";
    }

    @PostMapping("/{id}")
    public String update(@PathVariable Long id, @ModelAttribute org.example.carscrud.model.Model m) {
        m.setModelId(id);
        modelRepo.save(m);
        return "redirect:/models";
    }

    @PostMapping("/{id}/delete")
    public String delete(@PathVariable Long id) {
        modelRepo.deleteById(id);
        return "redirect:/models";
    }

    @PostMapping
    public String save(
            @ModelAttribute("model") org.example.carscrud.model.Model modelEntity,
            org.springframework.ui.Model uiModel
    ) {

        Optional<org.example.carscrud.model.Model> existing =
                modelRepo.findByModelNameAndManufacturer(
                        modelEntity.getModelName(),
                        modelEntity.getManufacturer()
                );

        if (existing.isPresent() && !existing.get().getModelId().equals(modelEntity.getModelId())) {
            uiModel.addAttribute("error", "Такая модель у этого производителя уже существует");
            uiModel.addAttribute("manufacturers", manufacturerRepo.findAll());
            return "models/form";
        }

        modelRepo.save(modelEntity);
        return "redirect:/models";
    }
}
