# Assignment 9 – Git Branching

Detailed walkthrough and documentation of Git branching, branch renaming, parallel development, branch divergence, merge conflict resolution, branch deletion, and temporary workspace stashing.

- **Original Assignment PDF:** [`Assignment_9_TW.pdf`](./Assignment_9_TW.pdf)
- **Python Implementation:** [`vecadd.py`](./vecadd.py)

---

## 📋 Tasks Overview

- **Task 1 (Observe HEAD):** `git log --oneline` to inspect `HEAD -> master`
- **Task 2 (Create Branch):** `git branch fast` and `git branch`
- **Task 3 (Rename Branch):** `git branch -m fast parallel`
- **Task 4 (Switch Branch):** `git checkout parallel` and `git status`
- **Task 5 (Parallel Dot Product):** Updated [`vecadd.py`](./vecadd.py) with `multiprocessing.Pool` and committed on `parallel`
- **Task 6 (Fix Bug on Main):** Switched to `master`, updated vector size validation in `vecadd.py`, and viewed `git log --oneline --all --graph`
- **Task 7 (Merge Branch):** `git merge parallel` triggered a merge conflict in `vecadd.py`
- **Task 8 (Resolve Conflicts):** Resolved conflict markers in VS Code, ran `git add vecadd.py` and `git commit`
- **Task 9 (Delete Branch):** `git branch -d parallel` after successful merge
- **Task 10 (Explore Stash):** `git stash push -m "..."`, `git stash list`, and `git stash pop`

---

## 💡 What I Learnt

- **Branch Lifecycle Management:** Learned how to observe `HEAD`, create feature branches (`git branch`), rename them (`git branch -m`), switch between them (`git checkout`), and clean up merged branches (`git branch -d`).
- **Parallel Feature Development:** Practiced isolating new work (parallel `multiprocessing` dot product) on a feature branch while fixing bugs independently on `master`.
- **Resolving Merge Conflicts:** Understood why diverged edits cause conflicts during `git merge` and how to resolve conflict markers cleanly before committing.
- **Temporary Stashing:** Used `git stash push`, `git stash list`, and `git stash pop` to save and restore uncommitted work-in-progress changes.

