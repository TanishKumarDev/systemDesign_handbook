# Strategy Design Pattern

## 1. What is Strategy Design Pattern?
![](https://media.geeksforgeeks.org/wp-content/uploads/20250911173103416801/Strategy-design-pattern.webp)

![](https://media.geeksforgeeks.org/wp-content/uploads/20240207154820/StrategyDesignPatternExample.webp)

The **Strategy Design Pattern** is a **behavioral design pattern** that allows you to:

* Define a **family of algorithms** or behaviors.
* Encapsulate each algorithm into a **separate class**.
* Make algorithms **interchangeable at runtime** without modifying client code.

**Key idea:** The client selects the appropriate strategy (algorithm) dynamically at runtime.

---

## 2. Why Use Strategy Design Pattern?

Without this pattern:

* You may write all algorithms in a single class.
* Changing algorithms would require **modifying existing code**.
* Code becomes **rigid, hard to maintain, and violates the Open/Closed Principle (OCP)**.
* Reusing algorithms across different contexts leads to **duplication**.

**With Strategy Pattern:**

* Each algorithm is encapsulated in a **separate class**.
* Client can switch algorithms dynamically.
* Code is **flexible, reusable, and maintainable**.

---

## 3. Problem It Solves

Example scenario: **Sorting Application**

* You need to sort a list of integers.
* Sorting algorithm may vary: **Bubble Sort, Merge Sort, Quick Sort**.
* Implementing all algorithms in one class makes code rigid.
* Adding a new algorithm would require **modifying the main class**.
* **Solution:** Use Strategy Pattern to **encapsulate algorithms** and select one dynamically.

---

## 4. Components of Strategy Pattern

| Component               | Description                                                                                                     |
| ----------------------- | --------------------------------------------------------------------------------------------------------------- |
| **Context**             | Class that uses a strategy to perform a task. It maintains a reference to the strategy.                         |
| **Strategy Interface**  | Abstract interface defining a common method (`sort` in sorting example) that all concrete strategies implement. |
| **Concrete Strategies** | Specific implementations of the Strategy interface (BubbleSort, MergeSort, QuickSort).                          |
| **Client**              | Chooses which strategy to use and provides it to the context.                                                   |

---

## 5. Logic of the Pattern

* The **context class** does not know the details of algorithms.
* The **strategy class** encapsulates the algorithm.
* The **client** decides which strategy to use.
* Strategy can be **changed at runtime**, providing dynamic flexibility.

---

## 6. C++ Implementation Example

We will implement a **sorting system** using the Strategy Pattern.

### Step 1: Strategy Interface

```cpp
#include <iostream>
#include <vector>
using namespace std;

class SortingStrategy {
public:
    virtual void sort(vector<int>& arr) = 0;
    virtual ~SortingStrategy() {}
};
```

* `SortingStrategy` defines the **common interface** for all sorting algorithms.

---

### Step 2: Concrete Strategies

```cpp
class BubbleSortStrategy : public SortingStrategy {
public:
    void sort(vector<int>& arr) override {
        cout << "Sorting using Bubble Sort" << endl;
        // Implement Bubble Sort logic here
    }
};

class MergeSortStrategy : public SortingStrategy {
public:
    void sort(vector<int>& arr) override {
        cout << "Sorting using Merge Sort" << endl;
        // Implement Merge Sort logic here
    }
};

class QuickSortStrategy : public SortingStrategy {
public:
    void sort(vector<int>& arr) override {
        cout << "Sorting using Quick Sort" << endl;
        // Implement Quick Sort logic here
    }
};
```

* Each concrete strategy implements its **own sorting algorithm**.
* This makes strategies **interchangeable**.

---

### Step 3: Context Class

```cpp
class SortingContext {
private:
    SortingStrategy* strategy;

public:
    SortingContext(SortingStrategy* strategy) : strategy(strategy) {}

    void setStrategy(SortingStrategy* strategy) {
        this->strategy = strategy;
    }

    void performSort(vector<int>& arr) {
        strategy->sort(arr);
    }
};
```

* Context class holds a reference to a strategy.
* It delegates the sorting task to the strategy.
* Strategy can be **changed anytime** via `setStrategy`.

---

### Step 4: Client Code

```cpp
int main() {
    vector<int> arr1 = {5, 2, 9, 1, 5};
    vector<int> arr2 = {8, 3, 7, 4, 2};
    vector<int> arr3 = {6, 1, 3, 9, 5};

    SortingContext context(new BubbleSortStrategy());
    context.performSort(arr1); // Output: Sorting using Bubble Sort

    context.setStrategy(new MergeSortStrategy());
    context.performSort(arr2); // Output: Sorting using Merge Sort

    context.setStrategy(new QuickSortStrategy());
    context.performSort(arr3); // Output: Sorting using Quick Sort

    return 0;
}
```

✅ **Output:**

```
Sorting using Bubble Sort
Sorting using Merge Sort
Sorting using Quick Sort
```

---

## 7. Stepwise Execution

1. **Client** creates `SortingContext` with `BubbleSortStrategy`.
2. **Context** calls the `sort` method of `BubbleSortStrategy`.
3. Later, client **changes strategy** to `MergeSortStrategy`.
4. **Context** now calls `MergeSortStrategy` without modifying its own code.
5. **Flexible and reusable** — new strategies can be added easily.

---

## 8. Benefits

| Benefit                         | Explanation                                             |
| ------------------------------- | ------------------------------------------------------- |
| **Flexibility**                 | Change algorithm dynamically at runtime.                |
| **Code Reusability**            | Strategies can be reused across contexts.               |
| **Open/Closed Principle (OCP)** | Add new strategies without modifying context or client. |
| **Separation of Concerns**      | Sorting logic is separate from context and client.      |
| **Maintainability**             | Each algorithm is independent and easy to test.         |

---

This explanation includes **what the pattern is, why it is needed, problems it solves, logic behind it, implementation in C++, and benefits** — fully structured and detailed.

---
