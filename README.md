# Learning Projects

this is a learning projects where i put the code samples in files based on the language

## Projects

- **[learning-projects](https://github.com/Momokh99/learning-projects)** — C — This repository: programming exercises and code samples organized by language.
- **[NovelFetch](https://github.com/Momokh99/NovelFetch)** — Python — Novel reader & downloader with a Textual TUI and a KivyMD GUI (desktop + Android) over a pluggable scraper core. Browse, translate, and read novels offline.
- **[My-config](https://github.com/Momokh99/My-config)** — Lua — Arch Linux dotfiles for Hyprland with a Tokyo Night theme (Waybar, Wofi, Yazi, Kitty/Alacritty, Zsh, Neovim, Mako).
- **[planner-tui](https://github.com/Momokh99/planner-tui)** — Go — Terminal todo list with a week calendar view, built with Bubble Tea and auto-saved to `~/.todo.json`.
- **[gitprofile](https://github.com/Momokh99/gitprofile)** — Go / Python / C — `gitanalyze`: scans directories for Git repos and prints a GitHub-style contribution grid.
- **[terminal_games](https://github.com/Momokh99/terminal_games)** — C / Python — Collection of terminal games with a reusable C engine (`libeng.so`) and Python TUIs (rock–paper–scissors, number guessing).
- **[kh_Assistant](https://github.com/Momokh99/kh_Assistant)** — Python — Personal assistant project (work in progress).
- **[kh-launcher](https://github.com/Momokh99/kh-launcher)** — Kotlin — App launcher project (work in progress).
- **[homepage](https://github.com/Momokh99/homepage)** — JavaScript — Customizable new-tab page browser extension; widgets in plain ES modules, no UI framework.
- **[VMaker](https://github.com/Momokh99/VMaker)** — QML — Interactive QEMU/KVM + libvirt VM creation helper and an Omarchy bar plugin to list/start/stop VMs (fork).
- **[extensions-source](https://github.com/Momokh99/extensions-source)** — Source code of extensions for [keiyoushi/extensions](https://github.com/keiyoushi/extensions) (fork).
- **[30-Days-Of-Python](https://github.com/Momokh99/30-Days-Of-Python)** — Python — The 30 Days of Python step-by-step learning challenge (fork).
- **[Momokh99](https://github.com/Momokh99/Momokh99)** — Profile README: personal intro and current learning notes.

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