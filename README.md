# Learning Projects

A sandbox repo for learning and practicing programming across several
languages. Each folder covers one language with small exercise programs,
ranging from hello-world basics to small games and TUIs.

## Contents

| Folder        | Language      | What's inside                                   |
| ------------- | ------------- | ----------------------------------------------- |
| [bash/](bash) | Bash          | A simple interactive script                     |
| [c/](c)       | C             | ~28 starter programs (math, loops, arrays, …)   |
| [go/](go)     | Go            | Hello world scratch files + a Bubble Tea TUI app|
| [lua/](lua)   | Lua           | A calculator functions script                   |
| [python/](python) | Python    | Games and quizzes (tkinter, CLI)                |
| [typescript/](typescript) | TypeScript | Basic TS with a strict `tsconfig`      |

## bash/

- `test.bash` — asks for a first and last name and prints a greeting.

## c/

Starter C programming exercises (prompts are in French).

- `addition.c` — adds `n` user-entered numbers.
- `affichage_bonjour.c` — prints a greeting.
- `affiche_nbrs.c` — prints numbers from 0 to `N`.
- `calculator.c` — menu-driven calculator (add / subtract / multiply / divide).
- `change_x_et_y.c` — swaps two variables.
- `cont-to.c` — counts from 0 to `count` (for loop).
- `count_to.c` — counts from 0 to `count` (while loop).
- `def_fonc.c` — function definitions (absolute value, input, display).
- `devision.c` — division.
- `echange_de_nombre.c` — swaps two numbers using pointers.
- `multiplication.c` — multiplication.
- `moyenne1.c`, `moyenne2.c`, `moyenne3.c` — computing averages.
- `name.c` — name handling.
- `n_nombre.c` — working with `n` numbers.
- `one_or_zero.c` — switch statement checking 0 or 1.
- `paire_impaire.c` — checks if a number is even or odd.
- `positive_negative.c` — checks if a number is positive or negative.
- `sais_aff_tab.c` — fills an array and prints its contents.
- `semaine.c` — switch statement mapping a number to a day of the week.
- `slq.c` — pass-by-value demo with an increment function.
- `somme 0_100.c` — sums the integers from 0 to 100.
- `tab_addi.c` — sums a 2×2 matrix.
- `tabl.c` — computes the average of a 10-element array.
- `tempCodeRunnerFile.c` — scratch file.
- `zero_ou_non.c` — checks whether a number is zero.

## go/

- `hello.go`, `hi.go`, `input.go` — hello-world and input scratch files.
- `mm.go` — work-in-progress To-Do app built with the
  [Bubble Tea](https://github.com/charmbracelet/bubbletea) TUI framework.

## lua/

- `calculate.lua` — a `calculate(a, b)` function returning the sum,
  difference, and product of two numbers.

## python/

- `rock_paper_scissors.py` — graphical Rock–Paper–Scissors game built with
  tkinter, with a scoreboard and round history.
- `sorting_hat.py` — a Harry Potter sorting-hat personality quiz (CLI).
- `the_cyclone.py` — ride eligibility checker based on height and credits.
- `day2.py` — exercise scratch file.
- `tempCodeRunnerFile.py` — scratch file with a Rock–Paper–Scissors plan.

## typescript/

TypeScript experiments compiled from `src/` to `dist/` using a strict
`tsconfig.json`.

- `src/index.ts` — basic variables, loop, and a typed `add` function.

## Running the projects

```bash
# Bash
bash bash/test.bash

# C (all files use basic stdio; calculator.c also needs the math lib)
gcc c/calculator.c -o c/calculator -lm && ./c/calculator

# Go (programs share one module, run them individually)
go run ./go/hello.go

# Lua
lua lua/calculate.lua

# Python
python3 python/rock_paper_scissors.py

# TypeScript (requires tsc to be installed)
tsc && node dist/index.js
```