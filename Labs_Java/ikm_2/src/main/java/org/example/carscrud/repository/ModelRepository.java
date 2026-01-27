package org.example.carscrud.repository;

import org.example.carscrud.model.Model;
import org.example.carscrud.model.Manufacturer;
import org.springframework.data.jpa.repository.JpaRepository;
import java.util.Optional;

public interface ModelRepository extends JpaRepository<Model, Long> {
    Optional<Model> findByModelNameAndManufacturer(String modelName, Manufacturer manufacturer);
}