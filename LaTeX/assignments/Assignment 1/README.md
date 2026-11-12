# Assignment 1 – Introduction to LaTeX

Foundational LaTeX document demonstrating document class options, automatic table of contents generation, special character escaping, numbered lists, inline and numbered display equations, cross-referencing, and `natbib` bibliography citations.

- **Source File:** [`source.tex`](./source.tex)
- **Compiled Output:** [`output.pdf`](./output.pdf) *(2 pages)*

---

## Analysis & Implementation Details

### 1. Document Setup & Preamble
- **Document Class:** `\documentclass[12pt,a4paper]{article}` configures a 12pt global font size and overrides the default `letter` paper size to `a4paper`.
- **Packages:** `amsmath` (for `\eqref` and math layout) and `natbib` (for author-year citations via `\citep` and `\citet`).
- **Title & Navigation:** `\title{Assignment 1}`, `\author{Aryan Saraiya}`, `\date{}` (suppresses date), rendered via `\maketitle` followed by `\tableofcontents`.

### 2. Core Concepts Demonstrated
- **Whitespace & Escaping (Section 1):** Documents how LaTeX collapses multiple spaces/line breaks while treating blank lines as paragraph breaks, and demonstrates escaping reserved characters (`\%`, `\$`, `\&`, `\#`, `\_`, `\{`, `\}`).
- **Document Options & Code Formatting (Section 1.1):** Explains `article` class options using `\texttt{...}` and inline verbatim `\verb|\documentclass[12pt,a4paper]{article}|`.
- **Lists (Section 1.2):** Numbered list created with the `enumerate` environment.
- **Inline Math & Citations (Section 2):** Renders mass-energy equivalence `$e = mc^2$` inline with parenthetical citation `\citep{einstein1905}`.
- **Numbered Equations & Cross-Referencing (Section 3):**
  - Displays the time-dependent Schrödinger equation inside an `equation` environment labeled `\label{eq:schrodinger}` using `\hbar`, `\frac{\partial}{\partial t}`, `\nabla^2`, and `\left[ ... \right]`.
  - Cross-references the equation dynamically with `Equation~\eqref{eq:schrodinger}` alongside textual citation `\citet{schrodinger1926}`.
- **Bibliography:** Configured with `\bibliographystyle{agu}` and `\bibliography{physics}`, producing formatted references for Einstein (1905) and Schrödinger (1926) on page 2.

---

## What I Learnt

- **Document Setup & Navigation:** Learned how `[12pt,a4paper]` configures global typography and page dimensions, and how `\tableofcontents` auto-generates section links.
- **LaTeX Text Rules:** Understood whitespace collapsing, paragraph breaks, and escaping reserved characters (`\%`, `\$`, `\&`, `\#`, `\_`, `\{`, `\}`).
- **Math & Cross-Referencing:** Practiced writing numbered equations (`equation` + `\label`) and referencing them dynamically with `\eqref`.
- **Citations with `natbib`:** Learned the difference between parenthetical (`\citep`) and textual (`\citet`) citations linked to a `.bib` file.

