# System Design

This repository contains **notes, explanations, and examples** of all **23 Gang of Four (GoF) Design Patterns** – organized into **Creational, Structural, and Behavioral** categories.

Useful for **System Design interviews** and **LLD preparation**.

---

## 📂 Topics

### **1. Creational Patterns (5)**

👉 *How objects are created (focus on instantiation).*

1. **Factory Method** – One method to create objects, subclasses decide which class to instantiate.
2. **Abstract Factory** – Factory of factories (creates families of related objects).
3. **Singleton** – Only one instance exists globally (like Logger, Config).
4. **Prototype** – Create new objects by cloning existing ones.
5. **Builder** – Step-by-step construction of complex objects.

---

### **2. Structural Patterns (7)**

👉 *How classes/objects are combined to form larger structures.*

1. **Adapter** – Convert one interface into another (plug adapter).
2. **Bridge** – Separate abstraction from implementation so both can vary.
3. **Composite** – Tree structure (whole-part), e.g., files & folders.
4. **Decorator** – Add new features dynamically without altering original class.
5. **Facade** – Simplified interface hiding complex subsystems.
6. **Flyweight** – Share common data to save memory (used in text editors for characters).
7. **Proxy** – Placeholder controlling access to real object (e.g., virtual proxy, security proxy).

---

### **3. Behavioral Patterns (11)**

👉 *How objects interact, communicate, and share responsibilities.*

1. **Chain of Responsibility** – Pass request along a chain until handled.
2. **Command** – Encapsulate requests as objects (undo/redo systems).
3. **Interpreter** – Define grammar and interpret expressions.
4. **Mediator** – Central object controls communication between many objects.
5. **Memento** – Save & restore object state (like checkpoints).
6. **Observer** – One-to-many notification (e.g., event listeners).
7. **State** – Change behavior based on internal state (like traffic light).
8. **Strategy** – Select algorithm at runtime (sorting strategies).
9. **Template Method** – Skeleton algorithm, subclasses fill in steps.
10. **Visitor** – Add new operations without changing object structure.
11. **Iterator** – Sequential access to elements without exposing internal details.

---

✅ **Total = 23 patterns**

* Creational → 5
* Structural → 7
* Behavioral → 11



---

## 🎯 Interview Questions
📖 Reference:
