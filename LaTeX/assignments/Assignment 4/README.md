# Assignment 4 – Lists, Colors, Tables & Figures

Practical document demonstrating unordered/ordered/description lists, custom color definitions with `xcolor`, colored boxed text, floating tables, image trimming/cropping, and side-by-side `minipage` figures.

- **Source File:** [`source.tex`](./source.tex)
- **Compiled Output:** [`output.pdf`](./output.pdf)

---

## 🔍 Analysis & Implementation Details

### 1. Document Setup & Preamble
- **Packages:** `graphicx`, `xcolor`, `amsmath`, `caption`, and `colortbl`.
- **Custom Colors:**
  - `\definecolor{color1}{RGB}{200,20,200}` (custom RGB magenta/purple).
  - `\colorlet{color2}{red!60!yellow}` (60% red, 40% yellow mix).

### 2. Core Concepts Demonstrated
- **Lists & Electronic Markup (Section 1):**
  - `itemize` list of formatting technologies ($\LaTeX$, HTML + CSS, Markdown).
  - `enumerate` list of $\LaTeX$ use cases.
  - `description` list contrasting *Presentational*, *Procedural*, and *Descriptive* markup.
- **Tables & Colors (Section 2):**
  - Inline `\textcolor{blue}`, framed boxes (`\fcolorbox{green}{white}{...}`), and highlighted blocks (`\colorbox{orange}{...}`).
  - Custom colors applied inside the Master Theorem recurrence: `\textcolor{color1}{T(n)} = \textcolor{color2}{aT(n/b) + f(n)}`.
  - Fixed-width compilation comparison table (`|p{2.5cm}|p{2cm}|p{2cm}|p{3.5cm}|`) with `\rowcolor{green}` header and `\rowcolor{yellow}` footer flushed onto page 4 after `\clearpage`.
- **Figures & Graphics (Section 3):**
  - **Scaling & Cropping (Section 3.1):** Displays `Mnit_logo.png` first at `scale=0.5`, then cropped (`trim=0 0 0 150, clip`) and scaled to `width=\textwidth` inside floating `figure[h]` environments.
  - **Side-by-Side Minipages (Section 3.2):** Places two `0.45\textwidth` `minipage` blocks separated by `\quad`, using `\captionof{figure}{...}` from the `caption` package so figures sit side by side cleanly.

