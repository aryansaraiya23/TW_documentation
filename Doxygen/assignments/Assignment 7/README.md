# Assignment 7 – Multi-File C++ Documentation with Doxygen

Multi-file C++ **Calculation Engine** project documented using Doxygen (v1.9.8) to generate cross-referenced HTML pages, a Todo list, collaboration/include diagrams, and a compiled PDF reference manual.

- **Configuration:** [`Doxyfile`](./Doxyfile)
- **Source Files:** [`Logger.h`](./Logger.h), [`CalculationEngine.h`](./CalculationEngine.h), [`main.cpp`](./main.cpp)
- **Generated Outputs:** [`refman.pdf`](./refman.pdf) *(23 pages)*, [`html_screenshot_mainpage.png`](./html_screenshot_mainpage.png)

---

## 📁 Files in Assignment 7

| File | Brief Description |
| :--- | :--- |
| [`Doxyfile`](./Doxyfile) | Doxygen configuration setting `PROJECT_NAME = "Calculation Engine"`, `INPUT` files, `EXTRACT_ALL = YES`, `EXTRACT_PRIVATE = YES`, HTML output (`doc_html`), LaTeX output (`doc_latex`), and `GENERATE_TODOLIST = YES`. |
| [`Logger.h`](./Logger.h) | Defines the project `@mainpage`, `LogLevel` enum (`INFO`, `WARNING`, `ERROR`), and `Logger` class with constructor, `log()` method, and private members (`name_`, `level_`). |
| [`CalculationEngine.h`](./CalculationEngine.h) | Defines the `CalculationEngine` class using a private `Logger` (`logger_`) and implements `power_calculation(base, exponent)` with `@details`, `@param`, `@return`, and `@todo`. |
| [`main.cpp`](./main.cpp) | Application entry point that instantiates `CalculationEngine` and prints `2^10` using `power_calculation(2, 10)`. |
| [`html_screenshot_mainpage.png`](./html_screenshot_mainpage.png) | Screenshot of the generated HTML main page (*Calculation Engine Project*) with navigation tabs and file links. |
| [`refman.pdf`](./refman.pdf) | 23-page PDF manual compiled from Doxygen's LaTeX output, containing the Todo List, class/file indices, collaboration & include dependency graphs, and source listings. |

---

## 💡 What I Learnt

- **Configuring `Doxyfile`:** Learned how a minimal `Doxyfile` controls input files, output directories (`doc_html`, `doc_latex`), private member extraction (`EXTRACT_PRIVATE = YES`), and automatic Todo list generation (`GENERATE_TODOLIST = YES`).
- **Multi-File Documentation:** Used `@file` and `@mainpage` to tie multiple headers and `.cpp` files into one unified, cross-referenced reference manual.
- **Documenting C++ Entities:** Practiced documenting classes (`@class`), enums (`@enum`), methods (`@brief`, `@details`, `@param`, `@return`), and inline trailing member/enum comments (`/**< ... */`).
- **Actionable Tracking & Visuals:** Saw how `@todo` aggregates pending tasks into a dedicated Todo List and how Doxygen automatically builds `#include` dependency and class collaboration graphs.
