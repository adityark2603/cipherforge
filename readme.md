# 📚 Compiler Design: Unit 4 Study Guide

This is a comprehensive summary of **Unit 4: Code Optimization, Code Generation, and Run-Time Environments**.

## 🧠 PART 1: CODE OPTIMIZATION

### 🔹 1. Overview
- **Definition:**  
  A program transformation technique to improve code by reducing resource usage (CPU, Memory) and increasing execution speed.

- **Criteria for Good Optimization:**
  1. **Semantics Preserving** – Must not change program meaning  
  2. **Speed Up** – Should improve execution time  
  3. **Efficiency** – Should not slow down compilation excessively  

- **Methods:**
  - **Control Flow Analysis:** Uses CFG to identify loops and execution order  
  - **Data Flow Analysis:** Tracks variable usage and data movement  

### 🔹 2. Types of Optimization
- **Machine Independent** → Performed on Intermediate Code (IR)  
- **Machine Dependent** → Performed on Target Code (CPU-specific)  

### 🔹 3. Machine-Independent Optimizations

| Technique | Description | Example |
|----------|------------|--------|
| **Constant Folding** | Evaluate constants at compile time | `x = 2 * 30 → x = 60` |
| **Constant Propagation** | Replace variables with known values | `x = 3; y = x + 1 → y = 3 + 1` |
| **CSE** | Remove repeated expressions | `b*c` reused via temp variable |
| **Copy Propagation** | Replace variable copies | `y = x → use x directly` |
| **Dead Code Elimination** | Remove unused code | Delete unused variables |
| **Strength Reduction** | Replace costly ops | `x * 2 → x << 1` |

### 🔹 4. Loop Optimizations
- **Code Motion:** Move loop-invariant code outside  
- **Induction Variables:** Replace multiplication with addition  
- **Loop Unrolling:** Reduce loop overhead by replicating body  

### 🔹 5. DAG Optimization
- **DAG (Directed Acyclic Graph):**
  - Used within a basic block  
  - Helps detect redundant computations  

## ⚙️ PART 2: CODE GENERATION

### 🔹 1. Primary Tasks
1. Instruction Selection  
2. Register Allocation  
3. Register Assignment  
4. Instruction Ordering  

### 🔹 2. Design Issues
- Optimal code generation is **undecidable**  
- Register allocation is **NP-Hard**  
- Target output:
  - Machine Code
  - Relocatable Code
  - Assembly Code  

### 🔹 3. Target Machine Models
- **RISC:** Many registers, simple instructions  
- **CISC:** Fewer registers, complex instructions  
- **Stack-Based:** Uses stack (e.g., JVM)  

### 🔹 4. Addressing Modes
- **Direct:** `ADD R1, a`  
- **Indexed:** `MOV R2, R1(a)`  
- **Indirect:** `MOV R2, 0(R1)`  
- **Immediate:** `LD R1, #100`  

### 🔹 5. Register Management
- **Register Descriptor:** Tracks variables in registers  
- **Address Descriptor:** Tracks variable locations  
- **Spilling:** Move variables to memory when registers are full  

## 🧩 PART 3: RUN-TIME ENVIRONMENTS

### 🔹 1. Memory Layout
- **Code:** Static  
- **Static Data:** Globals  
- **Heap:** Dynamic allocation (grows ↑)  
- **Stack:** Function calls (grows ↓)  

### 🔹 2. Activation Record (Stack Frame)
Contains:
1. Parameters  
2. Return Values  
3. Control Link  
4. Access Link  
5. Saved Registers  
6. Local Variables  
7. Temporaries  

### 🔹 3. Activation Trees
- Represents function execution  
- **Call → Preorder traversal**  
- **Return → Postorder traversal**  
- **Live activations:** Path from root to current node  

### 🔹 4. Accessing Non-Local Data
- **Without Nesting (C):**
  - Locals → Stack  
  - Globals → Static Memory  

- **With Nesting (Pascal, ML):**
  - **Access Links:** Traverse chain (O(n))  
  - **Displays:** Array lookup (O(1))  

### 🔹 5. Register Allocation (Graph Coloring)
1. Liveness Analysis  
2. Interference Graph  
   - Nodes → Variables  
   - Edges → Conflicts  
3. Assign **k colors = k registers**  

## 💡 Quick Exam Tips
- `x * 2 → x << 1` (Strength Reduction)  
- Practice **DAG diagrams**  
- **Next-Use Algorithm:** Two-pass  
- Stack & Heap should grow in opposite directions  

## 🚀 How to Use This
- Great for **last-day revision**
- Convert into flashcards or diagrams
- Practice previous year questions alongside this
