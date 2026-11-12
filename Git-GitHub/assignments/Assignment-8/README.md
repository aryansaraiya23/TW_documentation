# Assignment 8 – Git Basics

Detailed walkthrough and documentation of basic Git commands covering repository initialization, author configuration, staging, committing, inspecting diffs, restoring changes, viewing history, reverting commits, removing files, and checking out detached `HEAD` states.

- **Original Assignment PDF:** [`Assignment_8_TW.pdf`](./Assignment_8_TW.pdf)
- **Python Implementation:** [`vecadd.py`](./vecadd.py)

---

## 📋 Tasks Overview

- **Task 1 (Initialize):** `git --version`, `git init`
- **Task 2 (Configure):** `git config user.name`, `git config user.email`
- **Task 3 (Stage):** Created `readme.txt`, ran `git add readme.txt` and `git status`
- **Task 4 (Commit):** `git commit -m "Adding first file."`
- **Task 5 (Diff):** `git diff` to inspect changes in `readme.txt`
- **Task 6 (Restore):** `git restore readme.txt` and `git restore --staged readme.txt`
- **Task 7 (Log):** `git log` to view commit history
- **Task 8 (Revert):** `git revert <commit-hash>` to undo a commit cleanly
- **Task 9 (Python Program):** Added and committed [`vecadd.py`](./vecadd.py) (vector dot product), verified with `git log --oneline`
- **Task 10 (Remove):** `git rm readme.txt` and committed deletion
- **Task 11 (Detached HEAD):** `git checkout <earlier-commit-hash>` to inspect an earlier snapshot
- **Task 12 (Return):** `git checkout master` to return to the branch tip

---

## 💡 What I Learnt

- **Repository Setup & Tracking:** Learned how `git init`, `git config`, `git add`, `git status`, and `git commit` establish a versioned project history.
- **Inspecting & Undoing Changes:** Practiced viewing line-level diffs (`git diff`), discarding unstaged edits (`git restore`), unstaging files (`git restore --staged`), and safely reversing past commits (`git revert`).
- **File Deletion & Time Travel:** Used `git rm` to remove tracked files and `git checkout <hash>` / `git checkout master` to inspect historical snapshots in detached `HEAD` state.

