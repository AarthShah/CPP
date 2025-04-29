#include <iostream>
#include <vector>
using namespace std;


class Vehicle {
protected:
    string vehicleID, make, model;
    int year;
    bool isRented;
    double dailyRentalRate;
public:
    Vehicle(string id, string mk, string mdl, int yr, double rate)
        : vehicleID(id), make(mk), model(mdl), year(yr), dailyRentalRate(rate), isRented(false) {}
    
    virtual ~Vehicle() {}
    string getVehicleID() { return vehicleID; }
    bool getIsRented() { return isRented; }
    virtual double calculateRentalCost(int days) = 0;
    virtual void displayDetails() {
        cout << "ID: " << vehicleID << ", Make: " << make << ", Model: " << model
             << ", Year: " << year << ", Daily Rate: $" << dailyRentalRate 
             << ", Rented: " << (isRented ? "Yes" : "No") << endl;
    }
    void rentVehicle() { isRented = true; }
    void returnVehicle() { isRented = false; }
};


class Car : public Vehicle {
    int numberOfDoors;
    string fuelType;
public:
    Car(string id, string mk, string mdl, int yr, double rate, int doors, string fuel)
        : Vehicle(id, mk, mdl, yr, rate), numberOfDoors(doors), fuelType(fuel) {}
    double calculateRentalCost(int days) override {
        return dailyRentalRate * days;
    }
    void displayDetails() override {
        Vehicle::displayDetails();
        cout << "Doors: " << numberOfDoors << ", Fuel Type: " << fuelType << endl;
    }
};


class Motorcycle : public Vehicle {
    string engineType;
    bool hasSidecar;
public:
    Motorcycle(string id, string mk, string mdl, int yr, double rate, string engine, bool sidecar)
        : Vehicle(id, mk, mdl, yr, rate), engineType(engine), hasSidecar(sidecar) {}
    double calculateRentalCost(int days) override {
        return dailyRentalRate * days + (hasSidecar ? 20 * days : 0);
    }
    void displayDetails() override {
        Vehicle::displayDetails();
        cout << "Engine: " << engineType << ", Sidecar: " << (hasSidecar ? "Yes" : "No") << endl;
    }
};


class Truck : public Vehicle {
    double cargoCapacity;
    int numberOfAxles;
public:
    Truck(string id, string mk, string mdl, int yr, double rate, double capacity, int axles)
        : Vehicle(id, mk, mdl, yr, rate), cargoCapacity(capacity), numberOfAxles(axles) {}
    double calculateRentalCost(int days) override {
        return dailyRentalRate * days + (cargoCapacity * 10 * days);
    }
    void displayDetails() override {
        Vehicle::displayDetails();
        cout << "Cargo Capacity: " << cargoCapacity << " cubic meters, Axles: " << numberOfAxles << endl;
    }
};


class RentalSystem {
    vector<Vehicle*> vehicles;
public:
    ~RentalSystem() {
        for (auto v : vehicles) delete v;
    }
    void addVehicle(Vehicle* vehicle) {
        vehicles.push_back(vehicle);
    }
    void displayAvailableVehicles() {
        for (auto v : vehicles) {
            if (!v->getIsRented()) v->displayDetails();
        }
    }
    Vehicle* findVehicle(string vehicleID) {
        for (auto v : vehicles) {
            if (v->getVehicleID() == vehicleID) return v;
        }
        return nullptr;
    }
    void rentVehicle(string vehicleID, int days) {
        Vehicle* v = findVehicle(vehicleID);
        if (v && !v->getIsRented()) {
            v->rentVehicle();
            cout << "Rental Cost: $" << v->calculateRentalCost(days) << endl;
        } else {
            cout << "Vehicle not available for rent." << endl;
        }
    }
    void returnVehicle(string vehicleID) {
        Vehicle* v = findVehicle(vehicleID);
        if (v && v->getIsRented()) {
            v->returnVehicle();
            cout << "Vehicle returned successfully." << endl;
        } else {
            cout << "Vehicle not found or already returned." << endl;
        }
    }
};

int main() {
    RentalSystem system;
    system.addVehicle(new Car("CAR123", "Toyota", "Corolla", 2020, 50, 4, "Petrol"));
    system.addVehicle(new Motorcycle("MOTO456", "Honda", "CBR600RR", 2019, 30, "Inline-4", false));
    system.addVehicle(new Truck("TRUCK789", "Ford", "F-150", 2021, 80, 5, 2));
    
    int choice;
    do {
        cout << "\n1. Display Available Vehicles";
        cout << "\n2. Rent a Vehicle";
        cout << "\n3. Return a Vehicle";
        cout << "\n4. Find Vehicle and Display Details";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        if (choice == 1) {
            system.displayAvailableVehicles();
        } else if (choice == 2) {
            string id;
            int days;
            cout << "Enter Vehicle ID: ";
            cin >> id;
            cout << "Enter number of days: ";
            cin >> days;
            system.rentVehicle(id, days);
        } else if (choice == 3) {
            string id;
            cout << "Enter Vehicle ID: ";
            cin >> id;
            system.returnVehicle(id);
        } else if (choice == 4) {
            string id;
            cout << "Enter Vehicle ID: ";
            cin >> id;
            Vehicle* v = system.findVehicle(id);
            if (v) v->displayDetails();
            else cout << "Vehicle not found." << endl;
        }
    } while (choice != 5);
    
    return 0;
}

