# Assignment 2 – Mathematical Typesetting

Exploration of LaTeX mathematical typesetting covering inline vs. block equations, fractions, roots, Greek symbols, math fonts, calculus notation, multi-line `amsmath` environments, and delimited matrices.

- **Source File:** [`source.tex`](./source.tex)
- **Compiled Output:** [`output.pdf`](./output.pdf) 
---

## 🔍 Analysis & Implementation Details

### 1. Document Setup & Preamble
- **Document Class & Packages:** Uses `\documentclass[12pt]{article}` and `\usepackage{amsmath}`.

### 2. Core Concepts Demonstrated
- **Basics (Section 1):** Contrasts inline math (`$E=m.c^{2}$`) with unnumbered display block equations (`\[ v=u+a.t \]`).
- **Fractions & Roots (Section 2):** Combines `\frac{...}{...}` and `\sqrt[]{...}` with subscripted and superscripted variables ($x_i$, $a^2 + b_i^2$, $c_i$).
- **Symbols & Math Fonts (Section 3):**
  - Renders Einstein's field equation using Greek symbols (`\mu`, `\nu`, `\Lambda`, `\kappa`), logic quantifiers (`\forall`, `\exists`), set membership (`\in`), `\mathbf{R}`, `\rightarrow`, and spacing commands (`\quad`, `\:`).
  - Typesets a binomial summation expression using `\mathcal{F}`, `\sum_{k=0}^{n}`, and `\binom{n}{k}`.
- **Calculus (Section 4):** Demonstrates ordinary and partial derivatives (`\frac{du}{dv}`, `\frac{\partial u}{\partial t}`, `\frac{\partial^{2}u}{\partial x^{2}}`) alongside a definite integral (`\int_{0}^{1}`).
- **Multi-line Equations (Section 5):** Inserts a page break (`\newpage`) and demonstrates `amsmath` environments:
  - `gather` vs. `align` for stacked numbered equations.
  - `multline` for wrapping the long cubic expansion of $(x+y+z)^3$ across two lines.
- **Matrices (Section 6):** Compares four `amsmath` matrix delimiters side by side: `matrix` (plain), `bmatrix` (`[...]`), `vmatrix` (`|...|`), and `pmatrix` (`(...)`).

---

## 💡 What I Learnt

- **Inline vs. Display Math:** Learned when to embed equations inline (`$...$`) versus centered display blocks (`\[...\]`).
- **Mathematical Notation:** Practiced typesetting fractions (`\frac`), roots (`\sqrt`), Greek symbols, logic quantifiers (`\forall`, `\exists`), calculus operators (`\partial`, `\int`), and math fonts (`\mathbf`, `\mathcal`).
- **Multi-Line Environments:** Understood how `gather`, `align`, and `multline` handle equation numbering, alignment, and long expressions.
- **Matrix Delimiters:** Learned the different `amsmath` matrix environments (`matrix`, `bmatrix`, `vmatrix`, `pmatrix`) for clean linear algebra formatting.

