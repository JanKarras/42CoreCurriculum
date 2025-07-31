<p align="center">
  <img src="assets/ChatGPT Image 28. Juli 2025, 19_03_20.png" alt="push swap demo" width="500"/>
</p>

## Introduction

A 42 school algorithm project where the goal is to sort a stack of integers using a limited set of operations (sa, pb, ra, etc.). The program implements a custom sorting algorithm that tries to produce a small (but not necessarily optimal) number of operations to sort the input.

## 🧾 Input

The program expects a list of integers as command-line arguments.
Each number must be separated by a space. The following constraints apply:

- The list **must not contain duplicate values**.
- All inputs must be **valid 32-bit signed integers**.
- The number of arguments is limited only by the bounds of the integer type.

### 🔹 Example Input (small set, ≤ 5 elements):
```bash
./push_swap 10 -5 1 5 -12
```
### 🔹 Example Input (big set, ≤ 5 elements):
```bash
./push_swap -4757 -3611 643 -1771 -4818 4903 -2991 1636 4716 -4711 3861 178 2854 -2258 -3131 3952 -3512 3081 -3362
```

### 🔹 Example Input with Checker
``` bash
./push_swap 3 2 1 | ./checker 3 2 1
```

## Task
To sort the input, we were given two stacks that we were only allowed to manipulate using 11 specific operations.

| Operation | Description                                                                 |
|-----------|-----------------------------------------------------------------------------|
| sa        | Swaps the top two elements of Stack A                                       |
| sb        | Swaps the top two elements of Stack B                                       |
| ss        | Executes `sa` and `sb` simultaneously                                       |
| pa        | Pushes the top element from Stack B onto Stack A                            |
| pb        | Pushes the top element from Stack A onto Stack B                            |
| ra        | Rotates Stack A upwards (first element becomes last)                        |
| rb        | Rotates Stack B upwards                                                     |
| rr        | Executes `ra` and `rb` simultaneously                                       |
| rra       | Rotates Stack A downwards (last element becomes first)                      |
| rrb       | Rotates Stack B downwards                                                   |
| rrr       | Executes `rra` and `rrb` simultaneously                                     |

## Algorithm

Our algorithm is based on a cost-optimized heuristic: for each number in the stack, we calculate the most efficient way to move it into its final position using the allowed instructions. The goal is to keep the total number of operations relatively low, even for large inputs.

How it works:
🔁 Pushing phase:

- We analyze all values in Stack A and compute how "cheap" it is to push each one to Stack B using a combination of pb, rb, rr, rrb, etc.

- We then select the best candidate (lowest cost) and perform the corresponding moves.

- This process continues until Stack A contains only a few elements.

⚙️ Sorting the leftovers:

- Once only a small set of elements remains in Stack A, we sort them directly (e.g., with sa, ra, or rra).

📥 Pulling phase:

- We now move all elements back from Stack B to Stack A using a sequence of pa commands.

- Each element is inserted into the correct position using pre-calculated rotations.

🧭 Final rotation:

- After all elements are back in Stack A, we apply several ra operations to bring the smallest element to the top, completing the sort.

The result is a stack sorted in ascending order using a well-balanced mix of push, rotate, and swap operations, optimized per element during execution.

## ✅ Checker
To verify the correctness of the sorting algorithm, we implemented a custom checker program.

The checker receives the same list of integers as the original program and reads the list of operations (e.g., pb, ra, pa, etc.) from stdin — typically the output of ./push_swap.

It then simulates the operations step by step and finally checks whether:

- Stack A is sorted in ascending order, and

- Stack B is empty.

If both conditions are met, the checker prints:
```bash
OK
```

Otherwise, it reports:

``` bash
KO
```
This allows us to validate not just the logic of our algorithm but also the correctness of any optimization we apply during development.

## 📊 Visualizer

<p>To visualize the operations and sorting process, you can use the following online tool: </p>
https://push-swap42-visualizer.vercel.app/

<p></p>

<p>▶️ How to use it:</p>
<p>1. Run push_swap with your input:</p>

```bash
./push_swap 3 2 1
```

<p>2. Copy the output from the terminal:</p>

```bash
pb
pb
sa
pa
pa
```

<p>3. Open the visualizer and:</p>

- Paste your input numbers (e.g. 3 2 1) in the top field.
- Paste the operations in the bottom field.

<p>4. Hit “Start” to see the sorting process step-by-step.</p>
