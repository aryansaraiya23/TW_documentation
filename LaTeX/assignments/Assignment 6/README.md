# Assignment 6 – Document Structure, Fonts, Boxes, Indexing & Bibliography

Advanced XeLaTeX document structuring assignment featuring custom system fonts via `fontspec`, page background coloring, alphabetical section counter manipulation, hyphenation control, reusable boxes (`\savebox`, `\parbox`, `\fbox`, `\rule`), indexing with `imakeidx`, and BibTeX citation compilation.

- **Source File:** [`source.tex`](./source.tex)
- **Compiled Output:** [`output.pdf`](./output.pdf)
- **Build Toolchain:** `xelatex` $\rightarrow$ `makeindex` $\rightarrow$ `bibtex` $\rightarrow$ `xelatex` $\rightarrow$ `xelatex`

---

## 🔍 Analysis & Implementation Details

### 1. Document Setup & Preamble
- **Compiler & Page Geometry:** Compiled with **XeLaTeX** using `\documentclass[a4paper,10pt]{article}` and custom margins via `geometry` (`left=4.5cm, right=4.5cm, top=4cm, bottom=4.5cm`).
- **Fonts (`fontspec`):** Configures `DejaVu Serif` (main), `DejaVu Sans` (sans-serif), and conditional monospace fallback (`Courier New` / `TeX Gyre Cursor` / `DejaVu Sans Mono`) via `\IfFontExistsTF`.
- **Color & Counters:**
  - Warm cream page color: `\definecolor{bg}{RGB}{255,242,229}` and `\pagecolor{bg}`.
  - Alphabetical sections: `\renewcommand{\thesection}{\Alph{section}}`.
- **Indexing & Savebox:** Initializes single-column manual indexing (`\usepackage[noautomatic]{imakeidx}`, `\makeindex[columns=1]`) and pre-allocates `\newsavebox{\msgbox}`.

### 2. Core Concepts Demonstrated
- **Section A – Fonts and Background:** Uses `trivlist` to compare main, sans-serif (`\textsf`), and monospace (`\texttt`) typefaces, and inserts `\index{background}`.
- **Section B – Spacing & Hyphenation:** Contrasts forced line breaks (`\\`) with `\vspace{1cm}`, and disables word hyphenation locally with `{\hyphenpenalty=10000 \exhyphenpenalty=10000 ... \par}` before forcing `\newpage`.
- **Section D – Numbering:** Demonstrates manual counter adjustment (`\setcounter{section}{3}` skips Section C and jumps from B to D) and inserts an unlabelled ellipse equation before `\label{eq:circle}` so dynamic `\ref{eq:circle}` updates to Equation 2.
- **Section E – Boxes and Lines:**
  - Repeats stored text cleanly using `\usebox{\msgbox}`.
  - Wraps text inside `\parbox{5cm}{...}`, inserts vertical `\rule{1mm}{7mm}`, full-width framed `\fbox{\parbox{\dimexpr\textwidth-2\fboxsep-2\fboxrule\relax}{...}}`, and horizontal `\rule{\textwidth}{1pt}`.
  - Cites `\cite{overleaf}` and `\cite{lshort}`.
- **Index & References (Pages 3–4):** Outputs the alphabetical term index (`\printindex`) on page 3 and BibTeX bibliography (`\bibliographystyle{tw_plain}`, `\bibliography{references}`) titled *References* on page 4.

---

## 💡 What I Learnt

- **XeLaTeX & System Fonts:** Learned to configure custom system fonts (`fontspec`, `\IfFontExistsTF`) and page-wide backgrounds (`\pagecolor`) compiled with XeLaTeX.
- **Layout, Counters & Hyphenation:** Practiced adjusting margins via `geometry`, changing section numbering to letters (`\Alph{section}`), skipping section counters (`\setcounter`), and disabling hyphenation (`\hyphenpenalty=10000`).
- **Boxes & Rules:** Used `\savebox`/`\usebox` for reusable text, `\parbox` and `\fbox` for framed blocks, and `\rule` for horizontal/vertical lines.
- **Multi-Pass Indexing & BibTeX:** Understood the full `xelatex -> makeindex -> bibtex -> xelatex -> xelatex` build pipeline for generating an index and bibliography.

