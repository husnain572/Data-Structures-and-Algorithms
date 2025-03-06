# Sorting and Bubble Sort Algorithm  

## What is Sorting?  
Sorting is the process of arranging elements in either increasing or decreasing order.  

## Bubble Sort Algorithm  

### Definition:  
Bubble Sort repeatedly swaps two adjacent elements if they are in the wrong order.  

### Given Array:  
`4, 2, 5, 1, 3`

### Sorting Process:
#### Pass 1:
1. Compare `4` and `2` → Swap → `2, 4, 5, 1, 3`
2. Compare `4` and `5` → No swap → `2, 4, 5, 1, 3`
3. Compare `5` and `1` → Swap → `2, 4, 1, 5, 3`
4. Compare `5` and `3` → Swap → `2, 4, 1, 3, 5`

#### Pass 2:
1. Compare `2` and `4` → No swap → `2, 4, 1, 3, 5`
2. Compare `4` and `1` → Swap → `2, 1, 4, 3, 5`
3. Compare `4` and `3` → Swap → `2, 1, 3, 4, 5`
4. Compare `4` and `5` → No swap → `2, 1, 3, 4, 5`

#### Pass 3:
1. Compare `2` and `1` → Swap → `1, 2, 3, 4, 5`
2. Compare `2` and `3` → No swap → `1, 2, 3, 4, 5`
3. Compare `3` and `4` → No swap → `1, 2, 3, 4, 5`
4. Compare `4` and `5` → No swap → `1, 2, 3, 4, 5`

Since no swaps occurred in Pass 3, the array is sorted, and we can stop early.

### Final Sorted Array:
`1, 2, 3, 4, 5`


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
(n-1) + (n-2) + ... + 1 = <sup>n(n-1)</sup>&frasl;<sub>2</sub>

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
