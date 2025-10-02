# 🟢 What is Low-Level Design (LLD)?

* LLD is the **blueprint for developers**.
* It converts **HLD (high-level design: architecture, frameworks, databases, integrations)** into **detailed class designs, interactions, and algorithms**.
* It defines:

  * Classes
  * Methods
  * Data structures
  * Interactions (via UML diagrams)
  * Design patterns

---

# 🔑 HLD vs LLD

| Feature  | HLD (High Level Design)                                                                       | LLD (Low Level Design)                                                                        |
| -------- | --------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------- |
| Focus    | Architecture, tech stack, components                                                          | Detailed classes, methods, interactions                                                       |
| Scope    | “What the system will do”                                                                     | “How each part will be implemented”                                                           |
| Examples | Database: MySQL or MongoDB?  <br> Use REST or GraphQL?  <br> Service-to-service communication | Define `User`, `Order`, `Cart` classes <br> How login flow works <br> Which algorithms to use |
| Diagram  | Block diagrams, architecture diagrams                                                         | UML class, sequence, activity diagrams                                                        |

---

# 🧱 Steps to Create LLD

### 1. **Understand OOP Principles**

* Encapsulation
* Inheritance
* Polymorphism
* Abstraction

👉 These help map **real-world entities → objects/classes**.

---

### 2. **Analyze and Break Down Components**

* Identify **entities** → `User`, `Product`, `Order`
* Define **relationships** (association, aggregation, composition, generalization, realization).
* Ensure **SOLID principles**.

---

### 3. **Use Design Patterns**

* Creational → Singleton, Factory
* Structural → Adapter, Composite
* Behavioral → Observer, Strategy

👉 Helps **reuse best practices** and reduce code duplication.

---

### 4. **Use UML Diagrams**

* **Class Diagram** → Classes + relationships
* **Sequence Diagram** → Object interaction over time
* **Activity Diagram** → Workflows
* **State Diagram** → Object state changes
* **Use Case Diagram** → User interactions

---

### 5. **Follow SOLID Principles**

* **S**: Single Responsibility Principle
* **O**: Open/Closed Principle
* **L**: Liskov Substitution Principle
* **I**: Interface Segregation Principle
* **D**: Dependency Inversion Principle

---

# 📝 Example: Online Food Delivery System (LLD)

### HLD (big picture)

* Mobile app + backend APIs
* Uses MySQL for data
* Payment via third-party service

---

### LLD (detailed)

**Entities (classes)**:

* `User`
* `Restaurant`
* `MenuItem`
* `Order`
* `Payment`

---

### UML (simplified class diagram)

```
User -------- places --------> Order -------- contains --------> MenuItem
 |                                  |
 |                                  v
 |                             Payment (Strategy Pattern)
 |
 v
Restaurant (has MenuItems)
```

---

### C++ Implementation (simplified)

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Menu Item
class MenuItem {
    string name;
    double price;
public:
    MenuItem(string n, double p) : name(n), price(p) {}
    string getName() const { return name; }
    double getPrice() const { return price; }
};

// Order (Composition -> contains MenuItems)
class Order {
    vector<MenuItem> items;
public:
    void addItem(const MenuItem& item) {
        items.push_back(item);
    }
    double getTotal() const {
        double total = 0;
        for (auto& i : items) total += i.getPrice();
        return total;
    }
    void showOrder() const {
        cout << "Order contains:\n";
        for (auto& i : items) cout << "- " << i.getName() << " : $" << i.getPrice() << endl;
        cout << "Total: $" << getTotal() << endl;
    }
};

// User places Order
class User {
    string name;
public:
    User(string n) : name(n) {}
    void placeOrder(Order& order) {
        cout << name << " placed an order.\n";
        order.showOrder();
    }
};

int main() {
    User u("Alice");
    Order o;
    o.addItem(MenuItem("Burger", 5.99));
    o.addItem(MenuItem("Fries", 2.99));

    u.placeOrder(o);
    return 0;
}
```

### ✅ Output

```
Alice placed an order.
Order contains:
- Burger : $5.99
- Fries : $2.99
Total: $8.98
```

---

# ⚡ Benefits of LLD

* Clear understanding of **what to code**
* Easier **debugging & scaling**
* Faster development (blueprint ready)
* Clean & maintainable code (SOLID + design patterns)

---

# 🎯 Best Practices

* Always design **modular** components
* Use **interfaces & abstractions**
* Prefer **composition over inheritance** when possible
* Apply **error handling & validation** in the design
* Write **UML diagrams before coding**

