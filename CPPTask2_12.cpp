#include <iostream>
#include <string>

// Базовый класс "Компонент"
class Component {
protected:
    std::string name;

public:
    Component(const std::string& componentName) : name(componentName) {}

    virtual void displayInfo() const = 0;
};

// Класс "Процессор", наследуется от "Компонент"
class Processor : public Component {
private:
    double clockSpeed;

public:
    Processor(const std::string& processorName, double speed)
        : Component(processorName), clockSpeed(speed) {}

    void displayInfo() const override {
        std::cout << "Processor: " << name << ", Clock Speed: " << clockSpeed << " GHz\n";
    }
};

// Класс "Память", наследуется от "Компонент"
class Memory : public Component {
private:
    int capacity;

public:
    Memory(const std::string& memoryName, int memCapacity)
        : Component(memoryName), capacity(memCapacity) {}

    void displayInfo() const override {
        std::cout << "Memory: " << name << ", Capacity: " << capacity << " GB\n";
    }
};

// Класс "Системная плата", наследуется от "Компонент"
class Motherboard : public Component {
public:
    Motherboard(const std::string& motherboardName) : Component(motherboardName) {}

    void displayInfo() const override {
        std::cout << "Motherboard: " << name << "\n";
    }
};

// Класс "Устройство ввода/вывода", наследуется от "Компонент"
class IODevice : public Component {
public:
    IODevice(const std::string& deviceName) : Component(deviceName) {}

    void displayInfo() const override {
        std::cout << "I/O Device: " << name << "\n";
    }

    void input() {
        std::cout << "Input from " << name << "\n";
    }

    void output() {
        std::cout << "Output to " << name << "\n";
    }
};

int main() {
    // Создание компонентов персонального компьютера
    Processor processor("Intel i7", 3.5);
    Memory memory("Corsair Vengeance", 16);
    Motherboard motherboard("ASUS ROG Strix");
    IODevice ioDevice("Logitech Keyboard");

    // Вывод информации о компонентах
    processor.displayInfo();
    memory.displayInfo();
    motherboard.displayInfo();
    ioDevice.displayInfo();

    // Взаимодействие с устройством ввода/вывода
    ioDevice.input();
    ioDevice.output();

    return 0;
}
