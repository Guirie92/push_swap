# Push Swap

A fast **push_swap** implementation in C, capable of sorting any arbitrary amount of **integers** using a **k-sort/chunk–sort algorithm**, designed to minimize operations and remain performant even on larger inputs.

---

## Overview

The aim of *push_swap* is to sort integers using only limited stack operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`,`rra`, `rrb`, and `rrr`).  
This implementation uses two stacks: **A** (initial values) and **B** (temporary space), combined with a chunk-based sorting that pushes elements in ordered ranges to reduce operation count.

### Why chunk sorting?

1. Values are normalized (ranked 0 → n-1)
2. Data set is sliced into progressively sorted chunks
3. Elements are pushed from A → B based on chunk size + counter (forming a V/K shape)
4. Stack B is reintegrated into A in sorted order (finding MAX quickly in B)

This approach keeps operation cost low and scales well on inputs containing hundreds of numbers.

---

## Stack Representation

```c
typedef struct s_stack
{
	int		*arr;
	int		head;
	int		size;
	int		cap;
}	t_stack;
```

Stacks behave as **circular virtual arrays**, meaning:

| Field | Purpose |
|---|---|
| *arr  | the integer list |
| head | the top index in the circular buffer |
| size | current element count |
| cap  | total allocated capacity |

Because the structure is circular, **push/pop/rotate/reverse-rotate all run in O(1)**: no shifting and no pointer-heavy memory movement.

---

## ⚡ Efficiency Highlights
  
✔ Single arr buffer reused during parsing + duplicate check + rank conversion  
✔ Sorting and chunk logic optimized for minimal operations  
✔ Ranking uses **quicksort O(n log n)**

Normalizing to ranks lets chunk slicing be math-based, and it helps find the max number in the last phase of the algorithm, where you pass the max from B to A, since we know max is `n - 1` (`n` being the size of the array).

---

## Build & Run

```bash
make
./push_swap 4 3 2 5 1
```

Check against checker:

```bash
ARG="4 3 2 5 1"; ./push_swap $ARG | ./checker_linux $ARG
```

---

## Future Improvements

- Hybrid LIS × chunk mode experimentation
- Looking MAX numbers from both sides at a time, meeting in the middle
