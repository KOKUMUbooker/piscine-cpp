### To build executable :

```bash
g++ main.cpp utils.cpp solve.cpp -o out
```

### Sample arguments to call the executable with :

#### Example 1 (valid sudoku):

```bash
./out ".96.4...1" "1...6...4" "5.481.39." "..795..43" ".3..8...." "4.5.23.18" ".1.63..59" ".59.7.83." "..359...7"
```

#### Example 2 (invalid inputs or sudokus):

```bash
./out 1 2 3 4
```

```bash
./out
```

```bash
./out ".96.4...1" "1...6.1.4" "5.481.39." "..795..43" ".3..8...." "4.5.23.18" ".1.63..59" ".59.7.83." "..359...7"
```
