# Assignment 3 – Advanced Math Arrays & Table Styling

Comprehensive 14-question assignment covering nested mathematical grouping, piecewise functions, partitioned arrays, and a wide range of table formatting techniques including `multirow`, `xcolor`, `colortbl`, `booktabs`, nested tables, and embedded equations.

- **Source File:** [`source.tex`](./source.tex)
- **Compiled Output:** [`output.pdf`](./output.pdf) *(4 pages)*

---

## 🔍 Analysis & Implementation Details

### 1. Document Setup & Preamble
- **Packages:** `amsmath`, `multirow`, `xcolor`, `colortbl`, and `booktabs`.
- **Structure:** Unnumbered sections (`\section*{Que 1}` through `\section*{Que 14}`).

### 2. Question-by-Question Breakdown
- **Que 1 – Brace Grouping:** Nested `\overbrace` and `\underbrace` expressions annotated with `\text{...}`.
- **Que 2 – Partitioned Array:** Matrix headers and dividers constructed with `\left[ \begin{array}{c|ccc} ... \end{array} \right]` and `\hline`.
- **Que 3 – Piecewise Function:** Multi-branch function $f(x)$ built using the `cases` environment, `\dfrac`, and `[4pt]` row spacing.
- **Que 4 – Column-Grouped Matrix:** Matrix column labels above brackets via `\multicolumn` and `\overbrace{\hspace{2cm}}`.
- **Que 5 – Composite Energy Equation:** Combines summations, row/column `bmatrix` vectors, ellipses (`\cdots`, `\vdots`, `\ddots`), and nested `\overbrace`/`\underbrace` blocks alongside matrix $A$.
- **Que 6 – Standard Bordered Table:** Centered `tabular` with vertical/horizontal borders (`|c|c|c|c|c|`, `\hline`).
- **Que 7 – Multi-Column Header:** Spanning header row (`\multicolumn{3}{|c|}`) for *Academic Performance*.
- **Que 8 – Multi-Row Spanning:** Department cells (`CSE`, `ECE`) spanning multiple course rows via `\multirow`.
- **Que 9 – Zebra-Striped Scientific Table:** Deep learning model benchmark table styled with `\rowcolor{blue}`, alternating `\rowcolor{cyan}`, and `\textcolor{white}` headers.
- **Que 10 – Cell-Level Heatmaps:** Individual student score cells shaded with `\cellcolor{green}`, `\cellcolor{yellow}`, and `\cellcolor{red}`.
- **Que 11 – Paragraph Table Cells:** Fixed-width columns (`p{2.7cm}`) wrapping multi-line descriptions of neural network compression techniques.
- **Que 12 – Publication-Grade Table (`booktabs`):** Floating `table[h]` environment using `\toprule`, `\midrule`, `\bottomrule`, right-aligned numeric columns (`lrrrr`), `\caption`, and `\label`.
- **Que 13 – Nested Tables:** Embedded sub-`tabular` blocks inside the *Performance* column for CNN, ResNet, and ViT architectures.
- **Que 14 – Math inside Tables:** Combines inline mathematical loss expressions ($\frac{1}{n}\sum (y - \hat{y}_i)^2$, $-\sum y \log \hat{y}_i$) and Big-$O$ complexities inside table cells.

