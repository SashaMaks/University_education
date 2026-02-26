@Cache({"users", "products", "orders"})
class DataService {
    // содержимое класса
}

// Класс с одной кешируемой областью
@Cache("sessions")
class SessionManager {
    // содержимое класса
}

// Класс с пустым массивом (значение по умолчанию)
@Cache
class DefaultCacheClass {
    // содержимое класса
}

// Класс без аннотации
class NoCacheClass {
    // содержимое класса
}