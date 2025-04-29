#include <iostream>
#include <string>
#include <stdexcept>

class InsufficientFundsException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Insufficient funds!";
    }
};

class InvalidTransactionException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Invalid transaction!";
    }
};

class DivideByZeroException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Cannot divide by zero!";
    }
};

class BankAccount {
private:
    std::string ownerName;
    double balance;

public:
    BankAccount(const std::string& name, double initialDeposit) {
        if (initialDeposit < 0) {
            throw InvalidTransactionException(); 
        }
        ownerName = name;
        balance = initialDeposit;
    }


    void deposit(double amount) {
        if (amount < 0) {
            throw InvalidTransactionException(); 
        }
        balance += amount;
        std::cout << "Deposited " << amount << " INR. New balance: " << balance << " INR." << std::endl;
    }

 
    void withdraw(double amount) {
        if (amount < 0) {
            throw InvalidTransactionException(); 
        }
        if (amount > balance) {
            throw InsufficientFundsException(); 
        }
        balance -= amount;
        std::cout << "Withdrew " << amount << " INR. New balance: " << balance << " INR." << std::endl;
    }

    void transfer(BankAccount& to, double amount) {
        if (amount < 0) {
            throw InvalidTransactionException(); 
        }
        if (amount > balance) {
            throw InsufficientFundsException();
        }
        balance -= amount;
        to.balance += amount;
        std::cout << "Transferred " << amount << " INR to " << to.ownerName << ". Your new balance: " << balance << " INR." << std::endl;
    }

    void divideBalance(double divisor) {
        if (divisor == 0) {
            throw DivideByZeroException(); 
        }
        balance /= divisor;
        std::cout << "Balance divided by " << divisor << ". New balance: " << balance << " INR." << std::endl;
    }

    void display() const {
        std::cout << "Account Holder: " << ownerName << std::endl;
        std::cout << "Current Balance: " << balance << " INR" << std::endl;
    }
};

int main() {
    try {
        BankAccount account1("Rajesh", 5000); 
        BankAccount account2("Aditi", 2000);  
        
        account1.display();
        account2.display();
        
        account1.deposit(1500); 

        
        account1.withdraw(2000); 

        
        account1.transfer(account2, 1000); 

        
        account1.divideBalance(2); 

    } catch (const InsufficientFundsException& e) {
        std::cout << e.what() << std::endl;
    } catch (const InvalidTransactionException& e) {
        std::cout << e.what() << std::endl;
    } catch (const DivideByZeroException& e) {
        std::cout << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "General error: " << e.what() << std::endl;
    }

    return 0;
}