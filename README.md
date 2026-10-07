# Smart Delivery Planning – Fractional Knapsack

## Problem Statement

A delivery company has a vehicle with a fixed carrying capacity and several packages. Each package has a specific weight and value/profit.

The vehicle can carry packages up to its maximum capacity. A complete package or a fraction of a package can be selected.

The objective is to maximize the total value carried by the vehicle using the **Fractional Knapsack Greedy Algorithm**.

## Objectives

* Understand and implement the Greedy Method.
* Calculate the Value/Weight ratio for each package.
* Arrange packages in decreasing order of Value/Weight ratio.
* Select complete packages whenever possible.
* Select a fraction of a package when the remaining capacity is insufficient.
* Calculate and display the maximum achievable value.
* Analyze the time complexity of the solution.

## Features

The program is menu-driven and provides the following options:

1. Enter Package Details
2. Display Package Details
3. Calculate Value/Weight Ratio
4. Sort Packages by Ratio
5. Find Maximum Value
6. Display Selected Packages
7. Exit

## Algorithm

The program follows these steps:

1. Enter the number of packages.

2. Enter the value and weight of each package.

3. Calculate the Value/Weight ratio:

   `Ratio = Value / Weight`

4. Sort all packages in decreasing order of their ratio using **Selection Sort**.

5. Start selecting packages from the package with the highest ratio.

6. If the complete package fits, select it completely.

7. If it does not fit, select the required fraction of that package.

8. Continue until the vehicle capacity is full.

9. Display the total weight used and maximum value obtained.

## Example

### Input

| Package | Value | Weight |
| ------- | ----: | -----: |
| 1       |    40 |      5 |
| 2       |    30 |     10 |
| 3       |    50 |      5 |
| 4       |    20 |      4 |

**Vehicle Capacity = 15**

### Value/Weight Ratios

| Package | Value | Weight | Ratio |
| ------- | ----: | -----: | ----: |
| 1       |    40 |      5 |  8.00 |
| 2       |    30 |     10 |  3.00 |
| 3       |    50 |      5 | 10.00 |
| 4       |    20 |      4 |  5.00 |

After sorting:

1. Package 3 → Ratio = 10.00
2. Package 1 → Ratio = 8.00
3. Package 4 → Ratio = 5.00
4. Package 2 → Ratio = 3.00

The vehicle has a capacity of **15**.

* Package 3 → 5 kg → Value = 50
* Package 1 → 5 kg → Value = 40
* Package 4 → 4 kg → Value = 20
* Remaining capacity = 1 kg
* Package 2 → 1/10 fraction → Value = 3

Therefore:

**Total Weight Used = 15 kg**

**Maximum Value = 113**

## Technologies Used

* **Language:** C
* **Algorithm:** Fractional Knapsack
* **Technique:** Greedy Method
* **Sorting:** Selection Sort
* **Data Structures:** Arrays

## Time Complexity

The program uses **Selection Sort** to arrange packages according to their Value/Weight ratio.

* Calculating ratios: **O(n)**
* Selection Sort: **O(n²)**
* Selecting packages: **O(n)**

Therefore, the overall time complexity is:

### **O(n²)**

The dominant operation is Selection Sort.

### Space Complexity

The program uses arrays to store package information.

Therefore, the space complexity is:

### **O(n)**

## Functions Used

| Function                    | Purpose                                              |
| --------------------------- | ---------------------------------------------------- |
| `enterDetails()`            | Accepts package values, weights and vehicle capacity |
| `displayDetails()`          | Displays package information                         |
| `calculateRatio()`          | Calculates Value/Weight ratios                       |
| `sortPackages()`            | Sorts packages in decreasing ratio order             |
| `findMaximumValue()`        | Applies the Fractional Knapsack greedy algorithm     |
| `displaySelectedPackages()` | Displays selected fractions, weight and value        |
| `main()`                    | Provides the menu-driven interface                   |

## AOA Concepts Covered

* Greedy Method
* Fractional Knapsack
* Value/Weight Ratio
* Selection Sort
* Arrays
* Functions
* Time Complexity
* Space Complexity

## How to Run

### 1. Compile

```bash
gcc fractional_knapsack.c -o fractional_knapsack
```

### 2. Run

**Windows:**

```bash
fractional_knapsack.exe
```

**Linux / macOS:**

```bash
./fractional_knapsack
```

## Conclusion

The Fractional Knapsack problem is efficiently solved using the **Greedy Method** by selecting packages in decreasing order of their Value/Weight ratio.

Since fractions of packages are allowed, selecting the package with the highest value per unit weight at each step produces the maximum possible value for the given vehicle capacity.
