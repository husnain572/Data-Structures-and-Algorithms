# Sorting and Bubble Sort Algorithm  

## What is Sorting?  
Sorting is the process of arranging elements in either increasing or decreasing order.  

## Bubble Sort Algorithm  

### Definition:  
Bubble Sort repeatedly swaps two adjacent elements if they are in the wrong order.  

### Example:  
#### Given the array:  
`4, 2, 5, 1, 3`  

#### Sorting process:  
1. `4, 2, 1, 5, 3`  
2. `4, 2, 1, 3, 5`  

For **n** elements, the sorting process requires **n-1 passes** to place all elements in their correct positions.  

Thus, for **n** elements, **n-1 passes** are required.  

---

## Maximum Number of Swaps in Worst Case (Bubble Sort)  

#### Example (Sorting from Descending to Ascending Order):  
**Initial Array:** `50, 40, 30, 20, 10`  

1st pass: **4 swaps** → `(n-1)`  
2nd pass: **3 swaps** → `(n-2)`  
3rd pass: **2 swaps** → `(n-3)`  
4th pass: **1 swap** → `(n-4)`  

**Total number of swaps:**  
\[
(n-1) + (n-2) + ... + 1 = \frac{n(n-1)}{2}
\]  
(Sum of first **(n-1)** natural numbers)  

---

## Bubble Sort Time and Space Complexity  
- **Time Complexity**:  
  - **Worst and Average Case:** **O(n²)**  
- **Space Complexity**:  
  - **O(1)** *(In-place Sorting)*  

---

## Stable and Unstable Sorting  
- **Stable Sort:** Maintains the relative order of equal elements.  
- **Unstable Sort:** May change the relative order of equal elements.  

Bubble Sort is a **stable sorting algorithm** since it does not swap equal elements unnecessarily.  
