
## Insertion Sort Algorithm  

### Definition  
Insertion Sort repeatedly takes elements from the **unsorted subarray** and inserts them into their **correct position** in the **sorted subarray**.

---

### Example  
Given the array:  
`11, 8, 15, 9, 4`  

#### Sorting Process:
- Start with the second element (index 1) because the first element is considered sorted.
1. Compare 8 with 11 → Insert 8 before 11  
   `8, 11, 15, 9, 4`
2. 15 is already greater than 11 → No change  
   `8, 11, 15, 9, 4`
3. Compare 9 with 15 → Insert 9 between 11 and 15  
   `8, 11, 9, 15, 4` → Then shift 15 and insert 9  
   `8, 9, 11, 15, 4`
4. Compare 4 with all → Insert at beginning  
   `4, 8, 9, 11, 15`

✅ The final sorted array: `4, 8, 9, 11, 15`

---

### Time and Space Complexity  
- **Worst Case Time Complexity**: **O(n²)** (when the array is reverse sorted)  
- **Best Case Time Complexity**: **Ω(n)** (when the array is already sorted)  
- **Average Case Time Complexity**: **Θ(n²)**  
- **Space Complexity**: **O(1)** (in-place sorting)

---

### Applications of Insertion Sort  
✔ Best suited for **small datasets** or **nearly sorted arrays**  
✔ Useful when **new elements are continually added to a sorted list**

---

### Stability  
✔ **Insertion Sort is a stable sorting algorithm**, meaning it **preserves the relative order of equal elements**

---
