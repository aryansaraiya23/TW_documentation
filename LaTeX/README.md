# LaTeX Documentation

Comprehensive reference, concept guides, syntax explanations, and assignment walkthroughs for **LaTeX** typesetting in Technical Writing.

---

## 📖 Table of Contents

- [Overview](#overview)
- [Concepts Learned](#concepts-learned)
  - [1. Fundamental Principles & Architecture](#1-fundamental-principles--architecture)
  - [2. Document Skeleton & Structure](#2-document-skeleton--structure)
  - [3. Text Formatting & Page Layout](#3-text-formatting--page-layout)
  - [4. Mathematical Typesetting](#4-mathematical-typesetting)
  - [5. Multiline Math, Arrays & Matrices](#5-multiline-math-arrays--matrices)
  - [6. Floats, Tables, Cross-Referencing & Citations](#6-floats-tables-cross-referencing--citations)
  - [7. Advanced Table Styles & Dimensions](#7-advanced-table-styles--dimensions)
  - [8. Colors, Highlights & Scope (xcolor)](#8-colors-highlights--scope-xcolor)
  - [9. Image Transformations & Side-by-Side Layouts](#9-image-transformations--side-by-side-layouts)
  - [10. Programmatic Drawing (picture Environment)](#10-programmatic-drawing-picture-environment)
  - [11. Specialized Document Classes & Matter Architecture](#11-specialized-document-classes--matter-architecture)
  - [12. Page Geometry, Margins & Headers/Footers (fancyhdr)](#12-page-geometry-margins--headersfooters-fancyhdr)
  - [13. Boxes, Lengths & Breaking Mechanics](#13-boxes-lengths--breaking-mechanics)
  - [14. Counters & Numbering Customization](#14-counters--numbering-customization)
  - [15. Automated Indexing (MakeIndex)](#15-automated-indexing-makeindex)
  - [16. External Bibliographies with BibTeX](#16-external-bibliographies-with-bibtex)
  - [17. Diagnostics, Error Handling & TeX Warnings](#17-diagnostics-error-handling--tex-warnings)
- [Important Terminology](#important-terminology)
- [Syntax and Core Commands](#syntax-and-core-commands)
- [Explanations & Practical Examples](#explanations--practical-examples)
- [Lecture Coverage & Coursework Tracker](#lecture-coverage--coursework-tracker)
- [Key Takeaways & Best Practices](#key-takeaways--best-practices)
- [References & Resources](#references--resources)

---

## 🔍 Overview

LaTeX is an open-source document preparation and typesetting system built on Donald Knuth's TeX engine. Developed by Leslie Lamport, it is the standard for academic publications, engineering theses, and mathematical literature. LaTeX enforces a declarative paradigm: the author writes structured plain text, and the compilation engine handles typography, page breaking, numbering, and cross-references.

---

## 💡 Concepts Learned

### 1. Fundamental Principles & Architecture
- **LaTeX vs. Word Processors (WYSIWYG):** In MS Word, effort increases exponentially as document size and complexity grow (formatting glitches, layout shifts). In LaTeX, initial effort is higher due to markup syntax, but effort remains constant regardless of document length.
- **Source and Output Formats:**
  - Input: Plain text files (`.tex`).
  - Supported outputs: PDF (`.pdf`), DVI (`.dvi`), PostScript (`.ps`), and RTF (`.rtf`).
- **Compilation Toolchain:**
  - Modern engines: `pdflatex` compiles `.tex` directly to `.pdf`.
  - Traditional workflow: `latex document.tex` $\rightarrow$ `document.dvi`.
  - Multi-pass compilation: Required for resolving cross-references and bibliographies (`pdflatex` $\rightarrow$ `bibtex` $\rightarrow$ `pdflatex` $\rightarrow$ `pdflatex`).
- **Ecosystem & Editors:**
  - *Offline Distributions/IDEs:* Windows (MiKTeX, TeXnicCenter, TeXstudio), Linux (TeX Live, Kile, TeXstudio).
  - *Cloud Platforms:* Overleaf, Papeeria, CoCalc.

### 2. Document Skeleton & Structure
- **Three Mandatory Components:**
  1. `\documentclass{...}`
  2. `\begin{document}`
  3. `\end{document}`
- **Document Classes:** `article`, `report`, `book`, `letter`, and professional publisher templates (`IEEEtran`, `ACM`).
- **Arguments Syntax:** Mandatory arguments use curly braces `{ }`; optional arguments use square brackets `[ ]` (e.g., `\documentclass[12pt, twocolumn]{article}`).
- **Document Metadata & Title:** Defined via `\title{}`, `\author{}`, `\date{}`, and rendered with `\maketitle` (must be placed after `\begin{document}`).
- **Abstract:** Encapsulated in `\begin{abstract} ... \end{abstract}`, typically right after `\maketitle`.
- **Sectioning Hierarchy:** `\section{}`, `\subsection{}`, `\subsubsection{}`.

### 3. Text Formatting & Page Layout
- **Whitespace Rules:** Consecutive spaces are treated as a single space; single line breaks are ignored; a blank line initiates a new paragraph.
- **Spacing & Indentation:** `\vspace{<length>}` creates vertical space; `\noindent` suppresses paragraph indentation.
- **Special / Reserved Characters:** Symbols with functional syntactic meanings:
  `$ & % # _ { } ~ ^ \`
  - Escaped with backslash: `\$`, `\&`, `\%`, `\#`, `\_`, `\{`, `\}`
  - Non-breaking space: `~`
  - Comments: `%` ignores the remainder of the line.
- **Case Sensitivity:** All LaTeX commands are strictly case-sensitive.
- **Page Styles:** `\pagestyle{style}` accepts:
  - `plain`: Page number at bottom center (default).
  - `headings`: Running section/chapter header and page number at top.
  - `empty`: Suppresses both headers and footers.
- **Hyphenation:** Automatic; discretionary permissible hyphenation points are marked manually with `\-` (e.g., `manu\-script`).
- **Font Sizes:** `\tiny`, `\scriptsize`, `\footnotesize`, `\small`, `\normalsize`, `\large`, `\Large`, `\LARGE`, `\huge`, `\Huge`.
- **Text Alignment:** `flushleft` (left-aligned), `center` (centered), `flushright` (right-aligned).
- **List Environments:**
  - `itemize`: Bulleted, unordered list.
  - `enumerate`: Numbered, ordered list.
  - `description`: Labeled term-definition list (`\item[Label]`).

### 4. Mathematical Typesetting
- **Required Packages:** `amsmath`, `amssymb` for advanced mathematical symbols and formatting.
- **Math Modes:**
  - *Inline Math:* Rendered within running text using `$ ... $` or `\( ... \)`.
  - *Display Math:* Centered on a new line using `\[ ... \]` or `\begin{displaymath} ... \end{displaymath}`.
  - *Numbered Display Math:* Created via `\begin{equation} ... \end{equation}`.
- **Subscripts and Superscripts:** Subscripts use `_` (e.g., `x_i`), superscripts use `^` (e.g., `x^2`). Multi-character tokens must be grouped in braces (`x_{i+1}`, `e^{-x}`).
- **Arithmetic, Fractions & Roots:**
  - Fractions: `\frac{numerator}{denominator}`
  - Roots: `\sqrt{x}` (square root), `\sqrt[n]{x}` ($n$-th root).
  - Binomial coefficient: `\binom{n}{k}`
- **Calculus, Summations & Integrals:**
  - `\sum_{i=1}^{n} x_i`, `\prod_{k=1}^{m} k`, `\int_{0}^{1} x\,dx`, `\int_{0}^{\infty} e^{-x}\,dx`, `\oint`.
- **Symbols, Relations & Logic:**
  - Greek letters: `\alpha`, `\beta`, `\gamma`, `\delta`, `\lambda`, `\pi`, `\theta`, `\rho`, `\sigma`, `\epsilon`.
  - Relations: `\leq`, `\geq`, `\neq`, `\approx`, `\subset`, `\supset`, `\subseteq`, `\supseteq`.
  - Binary Operators: `\times`, `\otimes`, `\oplus`, `\cup`, `\cap`.
- **Accents & Grouping:**
  - `\overbrace{...}^{label}`, `\underbrace{...}_{label}`
  - `\overbracket{...}^{label}`, `\underbracket{...}_{label}`
- **Math Fonts & Typefaces:**
  - `\mathcal{...}` (Calligraphic), `\mathfrak{...}` (Fraktur), `\mathbb{...}` (Blackboard bold).
  - `\mathrm{...}` (Roman), `\mathbf{...}` (Bold), `\mathit{...}` (Italic), `\mathsf{...}` (Sans-serif), `\mathtt{...}` (Teletype).

### 5. Multiline Math, Arrays & Matrices
- **Multiline Equations (`amsmath`):**
  - `multline*`: For equations exceeding a single line. Splits lines with `\\`; first segment aligns left, last segment aligns right.
  - `align*`: Aligns multiple equations using the `&=` anchor syntax.
  - `gather*`: Centers multiple equations without horizontal alignment points.
- **Arrays:**
  - `array` environment inside math mode creates aligned tabular data (`l`, `c`, `r`).
  - Used with `\left\{ ... \right.` to render piecewise functions.
- **Matrices (`amsmath`):**
  - `matrix`: Unenclosed matrix.
  - `pmatrix`: Parentheses `( )`.
  - `bmatrix`: Square brackets `[ ]`.
  - `Bmatrix`: Curly braces `{ }`.
  - `vmatrix`: Single vertical bars `| |` (determinants).
  - `Vmatrix`: Double vertical bars `|| ||` (matrix norms).
  - Row spacing: `\\[6pt]` adds custom vertical space between rows.
  - Inline compact matrices: `\left( \begin{smallmatrix} ... \end{smallmatrix} \right)` prevents line-height disruption.

### 6. Floats, Tables, Cross-Referencing & Citations
- **Tables:** Built using `\begin{tabular}{specs} ... \end{tabular}`. Uses `l`, `c`, `r` alignment, vertical bars `|`, `\hline` for horizontal borders, `&` for column separation, and `\\` for line breaks.
- **Figures:** Enclosed in `figure` floating environment with position specifier `[h]`. Uses `\usepackage{graphicx}`, `\centering`, `\includegraphics[width=...]{...}`, `\caption{}`, and `\label{}`.
- **Automated Cross-Referencing:**
  - `\label{key}` assigns an internal identifier to a section, figure, table, or equation.
  - `\ref{key}` retrieves the generated number.
  - `\pageref{key}` retrieves the page number.
  - Tie references with a non-breaking space `~` (e.g., `Section~\ref{sec:intro}`).
- **Bibliographies:**
  - Managed via `\begin{thebibliography}{widest-label} ... \end{thebibliography}`.
  - Entries declared with `\bibitem{key}`.
  - Cited in text using `\cite{key}`.

### 7. Advanced Table Styles & Dimensions
- **Column Sizing & Wrapping:** Paragraph columns `p{width}` enable fixed column widths with automatic text wrapping.
- **Merging Cells:**
  - Across columns: `\multicolumn{num_cols}{alignment}{content}`.
  - Across rows: `\multirow{num_rows}{width}{content}` (requires `\usepackage{multirow}`).
- **Table Float Placement Parameters:**
  - `h`: Here (current position).
  - `t`: Top of page.
  - `b`: Bottom of page.
  - `p`: Dedicated float page.
  - `!`: Override LaTeX internal float placement thresholds.
  - `H`: Force exact placement at this location (from `float` package).
- **Dimensional Customization:**
  - `\setlength{\arrayrulewidth}{dimen}`: Controls table border line thickness (e.g., `0.5mm`).
  - `\setlength{\tabcolsep}{dimen}`: Sets padding between text and column borders (e.g., `18pt`).
  - `\renewcommand{\arraystretch}{factor}`: Scales row height multiplier (e.g., `1.5`).
  - Explicit row spacing: `\\[0.5ex]` or `\\[1ex]` added directly after row-break delimiters.
- **Table Coloring (`colortbl` package):**
  - Column coloring: `>{\columncolor{color}}` inside column specifications.
  - Row coloring: `\rowcolor{color}` applied at the start of a row.
  - Cell coloring: `\cellcolor{color}` applied to individual cells.

### 8. Colors, Highlights & Scope (xcolor)
- **Engine Setup:** Color is not natively active in standard LaTeX; enabled via `\usepackage{xcolor}`.
- **Text & Math Coloring:**
  - `\textcolor{color}{text}` applies colors to running text and mathematical formulas (`\textcolor{magenta}{E=mc^2}`).
- **Predefined vs. Custom Colors:**
  - Predefined: `red`, `blue`, `green`, `cyan`, `magenta`, `yellow`, `violet`, `teal`, `brown`, `lime`, `gray`, `black`, `white`.
  - Custom color models via `\definecolor{name}{model}{spec}`:
    - `RGB`: Integer range 0–255 (e.g., `{10, 60, 200}`).
    - `HTML`: Hexadecimal strings (e.g., `{FFB6C1}`).
    - `named` mixing: Relative weight mixing (e.g., `{red!80!black}` for 80% red + 20% black).
- **Boxes & Highlights:**
  - `\colorbox{color}{text}`: Solid background highlight.
  - `\fcolorbox{frame_color}{bg_color}{text}`: Bordered frame with distinct background fill.
- **Scope Control:**
  - Localized scope: `{\color{color} ...}` restricts color changes strictly within braces.
  - Declarative switch: `\color{color}` colors all subsequent text until overridden.

### 9. Image Transformations & Side-by-Side Layouts
- **Transformation Options (`graphicx`):**
  - Sizing: `width=...`, `height=...`, `scale=...`
  - Rotation: `angle=30` rotates images counter-clockwise by specified degrees.
  - Cropping: `trim=left bottom right top, clip` cuts margins prior to display.
- **Side-by-Side Images:**
  - Sub-layouts achieved using `minipage` blocks with proportional widths (`0.45\textwidth`), separated by `\quad` or `\hfill`.
  - Captions inside minipages can use `\captionof{figure}{Caption}`.

### 10. Programmatic Drawing (picture Environment)
- **Architecture:** Built-in drawing environment requiring no external graphics packages.
- **Coordinate System & Base Unit:**
  - Coordinates `(x, y)` scale according to `\setlength{\unitlength}{dimen}` (e.g., `1cm`, `0.5cm`).
  - Syntax: `\begin{picture}(width, height) ... \end{picture}`.
- **Placing Objects:** `\put(x, y){object}` specifies the bottom-left coordinate of the target primitive.
- **Geometric Primitives & Vectors:**
  - Lines: `\line(slope_x, slope_y){horizontal_length}`.
  - Vectors (Arrows): `\vector(slope_x, slope_y){horizontal_length}`.
  - Circles: `\circle{diameter}` (open circle) and `\circle*{diameter}` (filled disk).
  - Ovals: `\oval(width, height)`.
- **Text, Frames & Dashed Boxes:**
  - `\makebox(width, height)[pos]{text}` and `\framebox(width, height)[pos]{text}` with positioning flags `l`, `r`, `c`, `t`, `b`.
  - `\dashbox{dash_len}(width, height){text}`: Dashed bounding box.
  - `\shortstack{line1 \\ line2}`: Vertical text stacks within drawing coordinates.
- **Curves & Repetition:**
  - Quadratic Bézier curves: `\qbezier(x1, y1)(control_x, control_y)(x2, y2)`.
  - Repeated patterns: `\multiput(x, y)(dx, dy){count}{object}` repeatedly renders an object across equal increments.

### 11. Specialized Document Classes & Matter Architecture
- **Class Characteristics:**
  - `book`: Supports multi-level structural parts, chapters, and division commands:
    - `\frontmatter`: Roman numeral pagination; suppresses chapter numbering in TOC.
    - `\mainmatter`: Resets page counter to Arabic 1; enables normal numbered chapters.
    - `\backmatter`: Unnumbered chapters for appendices, bibliographies, and indices.
  - `letter`: Designed for formal correspondence using `\signature{}`, `\address{}`, `\begin{letter}{Recipient}`, `\opening{}`, and `\closing{}`.
  - `exam`: Structured for test creation using `\begin{questions}`, `\question`, and `\begin{choices}` / `\choice`.
  - `beamer`: Slide presentation class utilizing `\begin{frame}{Title} ... \end{frame}`.
- **Title Page Customization:**
  - Direct formatting: Sizing and font commands (`\Huge`, `\bfseries`, `\smallskip`) can be embedded inside `\title{}` and `\author{}`.
  - Structural metadata: Manual fields (e.g., supervisors, course codes) are placed under `\maketitle` within centered vertical spaces (`\begin{center}\vspace{1cm}...\end{center}`).

### 12. Page Geometry, Margins & Headers/Footers (fancyhdr)
- **Page Geometry (`geometry`):**
  - Declarative margin configuration: `\usepackage{geometry}` followed by `\geometry{left=2.5cm, right=2.5cm, top=2.5cm, bottom=2.5cm}`.
  - Standard paper options in `\documentclass`: `a4paper`, `letterpaper`.
- **Page Backgrounds:** Entire page tint set with `\pagecolor{color}` (e.g., `\pagecolor{yellow!10}`).
- **Advanced Running Headers & Footers (`fancyhdr`):**
  - Activate via `\pagestyle{fancy}`.
  - Clear default presets using `\fancyhf{}`.
  - Position fields: `\fancyhead[L|C|R]{content}` and `\fancyfoot[L|C|R]{content}` (`\thepage` injects current page number).
- **Styling Headers and Lists:**
  - Section font overrides: `\usepackage{sectsty}` enables `\sectionfont{\Large\bfseries\color{blue}}` and `\subsectionfont{\itshape\color{red}}`.
  - List tuning (`enumitem`): `\setlist[itemize]{label=\textbullet, leftmargin=*}` removes indentations and standardizes markers.
  - System Fonts (`fontspec`): XeLaTeX/LuaLaTeX commands `\setmainfont{}`, `\setsansfont{}`, `\setmonofont{}` allow utilizing OS TrueType/OpenType fonts.

### 13. Boxes, Lengths & Breaking Mechanics
- **Line & Paragraph Controls:**
  - Manual line break: `\\` breaks line without ending paragraph; `\linebreak` stretches text across line.
  - Paragraph generation: Blank line or `\par`.
  - Page breaks: `\newpage` / `\pagebreak` moves text to next page; `\clearpage` flushes all pending floats before breaking.
- **Keeping Elements Together:**
  - `\mbox{text}`: Prevents line break and disables hyphenation inside the box.
  - `\begin{samepage} ... \end{samepage}`: Prevents automatic page breaks across enclosed paragraphs.
- **LaTeX Length Parameters:**
  - `\parindent`: Paragraph indentation length (`\setlength{\parindent}{2em}`).
  - `\parskip`: Vertical space between paragraphs (`\setlength{\parskip}{1em}`).
  - Spacers: `\hspace{length}` (horizontal) and `\vspace{length}` (vertical).
- **Box Types & Manipulation:**
  - Paragraph boxes: `\parbox{width}{text}` creates an inline mini-paragraph of fixed width that wraps text automatically.
  - Framed vs. Unframed: `\framebox[width][align]{text}` (with border) and `\makebox[width][align]{text}` (without border) where `align` is `l`, `c`, or `r`.
  - Vertical offset: `\raisebox{distance}{content}` raises (positive) or lowers (negative) content relative to baseline (e.g., `\raisebox{1ex}{...}`).
  - Horizontal & Vertical Rules: `\rule{width}{height}` draws filled rectangular bars.
  - Box Storage & Reuse: `\newsavebox{\boxname}`, `\savebox{\boxname}{content}`, and `\usebox{\boxname}` avoid re-rendering repetitive graphics or labels.
- **Base Custom Environments (`trivlist`):**
  - `\begin{trivlist} \item ... \end{trivlist}` creates a vertical list without bullet markers. Serves as the structural foundation for authoring custom theorem, definition, or quote environments via `\newenvironment`.

### 14. Counters & Numbering Customization
- **Hierarchy:** Automatically increments across `\section` (1), `\subsection` (1.1), `\subsubsection` (1.1.1).
- **Manual Counter Override:** `\setcounter{section}{3}` causes the subsequent `\section` to be numbered 4.
- **Counter Representation:** Format redefined via `\renewcommand{\thesection}{\Roman{section}}` (`\arabic`, `\roman`, `\Roman`, `\alph`, `\Alph`).
- **Suppressing Numbers (Starred Forms):**
  - Section titles: `\section*{Title}` omits numbering and excludes entry from TOC.
  - Equations: `\begin{equation*} ... \end{equation*}` suppresses formula numbering (requires `amsmath`).

### 15. Automated Indexing (MakeIndex)
- **Architecture:** Programmatic indexing pipeline generating alphabetized back-of-book indices.
- **Setup:** `\usepackage{makeidx}` and `\makeindex` in preamble; `\printindex` at placement point.
- **Index Tagging Syntax (`\index{...}`):**
  - Standard entry: `\index{topic}`
  - Subentry: `\index{topic!subtopic}`
  - Page range: `\index{topic|(}` ... `\index{topic|)}`
  - Cross-reference: `\index{topic|see{target}}`
  - Custom display vs. sort key: `\index{sortkey@VisualDisplay}` (e.g., `\index{alpha@$\alpha$}`)
  - Page number formatting: `\index{topic|emph}` renders page number in italics.
  - Escaping MakeIndex characters (`!`, `@`, `|`, `"`): Preceded by double quote (e.g., `\index{exclaim ("!)}`).
- **Compilation Toolchain:** `latex doc` $\rightarrow$ `makeindex doc` $\rightarrow$ `latex doc`.

### 16. External Bibliographies with BibTeX
- **Architecture:** Decouples bibliographic data into a structured `.bib` database file.
- **Document Commands:**
  - `\bibliographystyle{plain}` specifies citation formatting (e.g., `plain`, `abbrv`, `alpha`, `ieeetr`).
  - `\bibliography{bibfilename}` points to the `.bib` file and prints the bibliography.
  - `\cite{key}` inserts numeric or alphanumeric in-text citations.
- **Standard Entry Types & Required Fields:**
  - `@article`: `author`, `title`, `journal`, `year`.
  - `@book`: `author`/`editor`, `title`, `publisher`, `year`.
  - `@inproceedings`: `author`, `title`, `booktitle`, `year`.
  - `@techreport`: `author`, `title`, `institution`, `year`.
  - `@misc`: Optional fields (`author`, `title`, `howpublished`, `year`).
- **BibTeX Syntax Rules:**
  - Author naming: `"Last, First"` or `"First Last"`; multiple authors separated by `and`; append `and others` for *et al.*
  - Capitalization preservation: Braces around characters or words prevent lowercase normalization (e.g., `title = {The {A}gony of {G}nus}`).
  - Macro definitions: `@string{jgg1 = "Journal of Examples"}` creates reusable publication strings.
- **Multi-pass Compilation Cycle:** `pdflatex doc` $\rightarrow$ `bibtex doc` $\rightarrow$ `pdflatex doc` $\rightarrow$ `pdflatex doc`.

### 17. Diagnostics, Error Handling & TeX Warnings
- **Error Log Anatomy (`.log`):**
  - Error indicator: Diagnostic description of failure (e.g., `! Undefined control sequence.`).
  - Error locator: Line number and current token location (e.g., `l.249 \todzy`).
  - File bracket context: Parentheses indicate opened files `(myfile.tex (subfile.tex ...))`.
- **Common Compilation Errors:**
  - `Bad \line or \vector argument`: Non-standard slope integer or missing dimension.
  - `Bad math environment delimiter`: Mismatched `$` or missing `\right` matching `\left`.
  - `\begin{...} ended by \end{...}`: Mismatched or improperly nested environments.
  - `Missing \begin{document}`: Text or syntax present outside preamble scope.
  - `Lonely \item`: `\item` command used outside a list environment (`itemize`, `enumerate`, `description`).
  - `Option clash for package`: Package loaded twice with incompatible option arguments.
  - `Too many columns in tabular / eqnarray`: Number of `&` exceeds declared column specifications.
- **TeX Resource Warnings:**
  - `Overfull \hbox`: Line exceeds text margin width (unresolved hyphenation/long formula).
  - `Underfull \vbox`: Loose vertical page distribution (insufficient content to fill page).
  - `TeX capacity exceeded`: Infinite macro recursion or excessive nested tokens.
- **Troubleshooting Heuristics:**
  1. Inspect the first reported error in the `.log` (cascading errors usually stem from the first).
  2. Isolate errors by temporarily commenting out suspect blocks.
  3. Recompile frequently after small edits rather than writing long untested blocks.
  4. Isolate issues into a Minimal Working Example (MWE).

---

## 🏷️ Important Terminology

| Term | Definition |
| :--- | :--- |
| **Preamble** | Section preceding `\begin{document}` reserved for packages, macros, and global layout definitions. |
| **Document Class** | Structural template defining overall layout, default fonts, and sectioning commands. |
| **Environment** | A scoped block opened by `\begin{name}` and closed by `\end{name}`. |
| **Float** | Container (`figure`, `table`) that LaTeX positions dynamically for optimal typographical layout. |
| **Delimiter** | Enclosing symbols (parentheses, brackets, braces) sized dynamically with `\left` and `\right`. |
| **BibTeX** | Auxiliary reference-management tool parsing external `.bib` files to generate formatted bibliographies. |
| **`\unitlength`** | Coordinate scaling factor defining base dimensions in the `picture` drawing environment. |
| **`colortbl`** | LaTeX package enabling row, column, and cell color fills within tabular structures. |
| **`xcolor`** | Driver-independent package providing extensive color palette support and color models (RGB, HTML). |
| **`minipage`** | An isolated sub-container acting as an independent miniature page of designated width. |
| **`fancyhdr`** | Package providing complete programmable control over page headers, footers, and rule lines. |
| **`geometry`** | Standard package for configuring paper dimensions, margins, and text body geometry. |
| **MakeIndex** | External utility creating alphabetized indexes with sub-items and page ranges. |
| **`trivlist`** | Primitive list environment without labels used as a structural harness for custom blocks. |
| **`parbox`** | Fixed-width box creating an inline paragraph supporting text wrapping. |

---

## 💻 Syntax and Core Commands

### 1. Document Configuration, Geometry & Headers
```latex
\documentclass[11pt,a4paper]{report}
\usepackage{geometry}
\geometry{left=2.5cm, right=2.5cm, top=2.5cm, bottom=2.5cm}

\usepackage{fancyhdr}
\pagestyle{fancy}
\fancyhf{}
\fancyhead[L]{Project Title}
\fancyhead[R]{\today}
\fancyfoot[C]{Page \thepage}

\usepackage{sectsty}
\sectionfont{\Large\bfseries\color{blue}}

\usepackage{enumitem}
\setlist[itemize]{label=\textbullet, leftmargin=*}
```

### 2. Title Page Customization
```latex
\title{\Huge \bfseries Technical Analysis of Microservices}
\author{\Large Jane Doe \\ \smallskip Department of Computer Science}
\date{August 2026}

\begin{document}
\maketitle

\begin{center}
  \vspace{1cm}
  \textbf{Supervisor:} Dr. Smith \\
  \textbf{Course:} Technical Writing
\end{center}
\end{document}
```

### 3. Advanced Tables & Dimensions
```latex
\setlength{\arrayrulewidth}{0.5mm}
\setlength{\tabcolsep}{14pt}
\renewcommand{\arraystretch}{1.3}

\begin{table}[h!]
\centering
\begin{tabular}{|>{\columncolor{red!20}}|c|c|c|}
\hline
\rowcolor{green!30} \multicolumn{3}{|c|}{Consolidated Summary} \\
\hline
Category & Subcategory & Value \\
\hline
\multirow{2}{4em}{Group A} & Item 1 & 100 \\
                           & Item 2 & \cellcolor{yellow!40} 200 \\
\hline
\end{tabular}
\caption{Demonstration of styled tabular data}\label{tab:styled}
\end{table}
```

### 4. Boxes, Spacing & Break Controls
```latex
% Line and Page Breaks
\newpage          % Move to next page
\clearpage        % Flush floats and start new page
\mbox{No-Break}   % Keep text unbroken on one line

% Paragraph Boxes and Rules
\parbox{5cm}{This text wraps automatically inside a paragraph box.}
\rule{4cm}{1pt}   % Horizontal line

% Vertical Adjustment
\raisebox{1ex}{Elevated} and \raisebox{-1ex}{Lowered}

% Saving and Reusing Boxes
\newsavebox{\mybox}
\savebox{\mybox}{\parbox{4cm}{\framebox[4cm]{Reusable snippet}}}
\usebox{\mybox}
```

### 5. Automated Indexing (`makeidx`)
```latex
% Preamble
\usepackage{makeidx}
\makeindex

% Document Body
\index{Algorithm}
\index{Algorithm!Sorting}
\index{Database|(} % Range start
\index{Database|)} % Range end
\index{speed@\textbf{Speed}} % Formatted display
\index{Linear Search|see{Search}}

\printindex
```

### 6. BibTeX Database Entry & Document Calls
```bibtex
% Entry inside refs.bib
@BOOK{lamport94,
  AUTHOR    = "Leslie Lamport",
  TITLE     = "{\LaTeX}: A Document Preparation System",
  PUBLISHER = "Addison-Wesley",
  YEAR      = 1994,
  ADDRESS   = "Reading, Massachusetts"
}
```
```latex
% In LaTeX document
Cited work: \cite{lamport94}.

\bibliographystyle{plain}
\bibliography{refs}
```

---

## 📝 Explanations & Practical Examples

### Systematic Compilation Cycles
To compile a complete professional document with citations, indices, and cross-references:
```bash
# 1. First pass: builds structure, creates .aux, .idx files
pdflatex document.tex

# 2. Process external references and index
bibtex document
makeindex document

# 3. Second pass: resolves bibliographies and page numbers
pdflatex document.tex

# 4. Third pass: finalizes cross-references and table of contents
pdflatex document.tex
```

---

## 📂 Lecture Coverage & Coursework Tracker

| Unit / Lecture | Topic Title | Core Concepts Covered | Status |
| :---: | :--- | :--- | :---: |
| **Lecture 1** | *Introduction to LaTeX* | Toolchain, Document Classes, Preamble/Body, Formatting, Tables, Figures, References, Bibliography | ✅ Documented |
| **Lecture 2** | *Math Notations, Equations, Array, Matrices, Lists* | Inline/Display Math, Calculus/Summations, Numbered Equations, Delimited Matrices, Arrays, Piecewise | ✅ Documented |
| **Lecture 3** | *Exploring Math Display Styles in LaTeX* | Math Fonts (`\mathbb`, `\mathfrak`), `amsmath` Multiline (`align*`, `gather*`, `multline*`), Spacing | ✅ Documented |
| **Lecture 4** | *Exploring Table Styles in LaTeX* | Multi-column (`\multicolumn`), Multi-row (`\multirow`), Float Flags (`[h!]`), `colortbl` (`\columncolor`, `\rowcolor`, `\cellcolor`), `\tabcolsep`, `\arraystretch` | ✅ Documented |
| **Lecture 5** | *Colours, Figures, and Picture Environment* | `xcolor` palettes & models, Highlights (`\colorbox`, `\fcolorbox`), Graphic Transforms (`angle`, `trim`/`clip`), `minipage` subfigures, 2D CAD `picture` environment | ✅ Documented |
| **Lecture 6** | *Document Styles, Layouts, Boxes, Indexing, BibTeX & Debugging* | `book`/`letter`/`exam`, `geometry`, `fancyhdr`, `sectsty`, `enumitem`, `parbox`/`savebox`/`rule`/`raisebox`, `trivlist`, `makeidx`, BibTeX types, Error parsing | ✅ Documented |
| **Assignments** | *Course Assignments* | Implementation and outputs will be archived in `assignments/` | ⏳ Awaiting Prompts |

---

## 🎯 Key Takeaways & Best Practices

- **Preamble Hygiene:** Keep all package declarations (`\usepackage`) and document-level configurations exclusively in the preamble.
- **Float Placement & Flushing:** Use `\clearpage` before major headings to force pending floats to render, avoiding accumulation at the document end.
- **Beamer Code Frames:** Always append the `[fragile]` option to `frame` environments when including source code or `verbatim` blocks (`\begin{frame}[fragile]`).
- **Debugging Protocol:** Never panic over dozens of compilation errors; fix the very first error indicated in the `.log` file, as later errors are usually downstream consequences.
- **Capitalization Protection in BibTeX:** Always wrap acronyms or proper nouns in `{Braces}` within `.bib` title fields to prevent bibliography styles from converting them to lowercase.

---

## 🔗 References & Resources

- [The Not So Short Introduction to LaTeX2e](https://tobi.oetiker.ch/lshort/lshort.pdf)
- [LaTeX Fancyhdr Package Documentation](https://ctan.org/pkg/fancyhdr)
- [MakeIndex User Guide](https://ctan.org/pkg/makeindex)
- [BibTeX Reference & Usage Guide](https://www.bibtex.org/)
- [Overleaf LaTeX Error Directory](https://www.overleaf.com/learn/latex/Errors)
