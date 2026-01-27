package org.example.carscrud.repository;

import org.example.carscrud.model.Manufacturer;
import org.springframework.data.jpa.repository.JpaRepository;
import java.util.Optional;

public interface ManufacturerRepository extends JpaRepository<Manufacturer, Long> {
    Optional<Manufacturer> findByName(String name);
}