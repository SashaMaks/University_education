package org.example.carscrud.repository;

import org.example.carscrud.model.Car;
import org.springframework.data.jpa.repository.JpaRepository;
import java.util.Optional;

public interface CarRepository extends JpaRepository<Car, Long> {
    Optional<Car> findByVinCode(String vinCode);
}
