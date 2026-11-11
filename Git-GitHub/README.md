# Git and GitHub Documentation

Comprehensive reference, architectural explanations, command workflows, and collaboration guides for version control using **Git** and **GitHub**.

---

## 📖 Table of Contents

- [Overview](#overview)
- [Concepts Learned](#concepts-learned)
  - [1. Principles of Version Control](#1-principles-of-version-control)
  - [2. VCS Architectures (Local, Centralized, Distributed)](#2-vcs-architectures-local-centralized-distributed)
  - [3. Git Internals & The Three Main Areas](#3-git-internals--the-three-main-areas)
  - [4. Git vs. GitHub](#4-git-vs-github)
  - [5. Branching, Merging & Rebase Strategies](#5-branching-merging--rebase-strategies)
  - [6. Merge Conflict Anatomy & Resolution](#6-merge-conflict-anatomy--resolution)
  - [7. Remote Workflows, Collaboration & Code Review](#7-remote-workflows-collaboration--code-review)
  - [8. Tags, Releases & Semantic Versioning](#8-tags-releases--semantic-versioning)
  - [9. Security, Authentication & Repository Hygiene](#9-security-authentication--repository-hygiene)
  - [10. Diagnostics & Troubleshooting](#10-diagnostics--troubleshooting)
- [Important Terminology](#important-terminology)
- [Syntax and Core Command Reference](#syntax-and-core-command-reference)
- [Explanations & Practical Examples](#explanations--practical-examples)
- [Assignment-Based Learning](#assignment-based-learning)
- [Lecture Coverage & Coursework Tracker](#lecture-coverage--coursework-tracker)
- [Key Takeaways & Best Practices](#key-takeaways--best-practices)
- [References & Resources](#references--resources)

---

## 🔍 Overview

Version control is a foundational engineering discipline that systematically tracks modifications to source code, documentation, and configuration files over time. It creates an immutable historical ledger that enables rollback, auditing, and seamless multi-developer collaboration without destructive overwriting.

---

## 💡 Concepts Learned

### 1. Principles of Version Control
- **The "Ad-Hoc" Anti-Pattern:** Manual file backups (`project_final.py`, `project_final_latest_fixed.py`) create ambiguity regarding the canonical version, lack diff visibility, and make multi-author collaboration error-prone.
- **Core Value Proposition:**
  - *For Developers:* Change attribution (who, what, when, why), regression isolation, experimental sandboxing via branches, and non-destructive rollbacks.
  - *For Engineering Projects:* Auditability, reproducibility, continuous integration support, and organized project roadmaps.

### 2. VCS Architectures (Local, Centralized, Distributed)
- **Local VCS:** Revisions stored in an internal database on a single machine; no collaboration support.
- **Centralized VCS (CVCS - e.g., SVN):** A single central server hosts repository history. Developers checkout shallow working copies. *Vulnerability:* The central server represents a single point of failure and requires continuous network access.
- **Distributed VCS (DVCS - e.g., Git):** Every developer's local clone contains the **complete repository history and object graph**. Operations (commit, branch, log, diff) occur locally with zero network latency.

### 3. Git Internals & The Three Main Areas
Git stores all metadata, commit history, and object references inside the hidden `.git/` directory at the project root.

The file lifecycle operates across three distinct logical trees:
1. **Working Directory:** The local filesystem tree where files are actively created, modified, or deleted.
2. **Staging Area (Index):** An intermediate holding zone where specific modifications are assembled using `git add` to prepare an atomic snapshot.
3. **Repository (Local Object Database):** The permanent commit history recorded by `git commit`.

```text
[ Working Directory ]  --- git add --->  [ Staging Area (Index) ]  --- git commit --->  [ Local Repository (.git) ]
         ^                                                                                          |
         |------------------------------ git push / git pull ---------------------------------------|
                                                    |
                                                    v
                                      [ Remote Repository (GitHub) ]
```

### 4. Git vs. GitHub
| Attribute | Git | GitHub |
| :--- | :--- | :--- |
| **Category** | Distributed command-line version control system. | Cloud-based hosting and collaborative engineering platform. |
| **Execution** | Runs locally on the developer machine; works fully offline. | Hosted in the cloud; requires internet connectivity. |
| **Core Functions** | Tracking file deltas, commits, branches, and merges. | Hosting remote repos, Pull Requests, Code Reviews, Issues, CI/CD. |
| **Authentication**| Configured locally (`user.name`, `user.email`) for authorship. | Authenticated via HTTPS (Personal Access Tokens) or SSH keys. |

### 5. Branching, Merging & Rebase Strategies
- **Branch Concept:** A lightweight, movable pointer to a 40-character SHA commit hash. Creating a branch does not duplicate project files.
- **Branch Creation & Switching:** Modern workflow favors `git switch -c <name>` over older overloaded `git checkout -b <name>`.
- **Merging vs. Rebasing:**
  - `git merge`: Integrates independent history branches. Preserves complete historical context and commit topologies, potentially generating a three-way merge commit.
  - `git rebase`: Replays commits from the current feature branch onto the tip of the target branch. Produces a clean, linear commit history by recomputing new commit hashes.
  - *Golden Rule:* Never rebase commits that have already been pushed to a public/shared remote repository.

### 6. Merge Conflict Anatomy & Resolution
A merge conflict occurs when Git cannot deterministically combine divergent modifications to the same line(s) of a file, or when a file was modified in one branch and deleted in another.

**Conflict Markers:**
```text
<<<<<<< HEAD
result = 10         # Active checked-out branch state
=======
result = 20         # Incoming branch state
>>>>>>> feature-login
```
- **Resolution Procedure:** Open the file, evaluate both implementations, manually craft the correct code, remove all delimiter lines (`<<<<<<<`, `=======`, `>>>>>>>`), stage with `git add`, and finalize with `git commit`.

### 7. Remote Workflows, Collaboration & Code Review
- **Remote Operations:**
  - `git fetch`: Downloads new commits, branches, and tags from the remote without altering local working branches.
  - `git pull`: Executes a fetch followed immediately by a merge (or rebase) into the checked-out branch.
  - `git push -u origin <branch>`: Transmits local commits to the remote and establishes tracking upstream.
- **Fork vs. Clone:**
  - *Fork:* Server-side copy of an upstream repository under an independent account on GitHub; used for external open-source contributions.
  - *Clone:* Local physical download of a remote repository onto a workstation.
- **Pull Requests (PR):** Formal review mechanism proposing to merge a feature branch into a target base branch. Enables inline line-level code reviews, automated CI/CD checks, and collaborative sign-offs prior to merging.

### 8. Tags, Releases & Semantic Versioning
- **Git Tags:** Permanent bookmark pointers to specific commits marking milestone versions.
- **Annotated Tags:** `git tag -a v1.0.0 -m "Release message"` stores the tagger, date, and message.
- **Semantic Versioning (`MAJOR.MINOR.PATCH`):**
  - `MAJOR`: Breaking architectural changes.
  - `MINOR`: Backward-compatible new capabilities.
  - `PATCH`: Backward-compatible defect fixes.
- **GitHub Releases:** Packaged assets and release notes generated against Git tags.

### 9. Security, Authentication & Repository Hygiene
- **Credentials:** Connect via HTTPS using Personal Access Tokens (PAT) with least-privilege scopes, or deploy SSH public-key cryptography.
- **Secret Management:** Never commit private keys, passwords, API tokens, or `.env` files.
- **The `.gitignore` Rule:** Adding a file to `.gitignore` only prevents untracked files from being staged; it **does not** purge files already committed to history.

### 10. Diagnostics & Troubleshooting
- **Primary Diagnostic Tool:** `git status` reveals untracked files, unstaged modifications, staged changes, and tracking status relative to upstream.
- **Diff Inspection:**
  - `git diff`: Shows un-staged modifications in the working directory.
  - `git diff --staged`: Compares staged changes against the latest commit (`HEAD`).
  - `git diff HEAD`: Shows all changes (staged and unstaged) relative to `HEAD`.
- **Inspecting Tracked Files:** `git ls-files` queries all files actively indexed by Git.

---

## 🏷️ Important Terminology

| Term | Definition |
| :--- | :--- |
| **Repository (Repo)** | Directory managed by Git containing project assets, object database, branches, and commit ledger inside `.git/`. |
| **Working Directory** | Local sandbox on the filesystem where files are actively edited. |
| **Staging Area (Index)**| Preparation cache staging modified files prior to committing. |
| **Commit** | Cryptographically signed, immutable snapshot of staged changes identified by a unique SHA-1/SHA-256 hash. |
| **`HEAD`** | Pointer referencing the currently checked-out commit or branch. |
| **Branch** | Lightweight, movable pointer targeting an individual commit in the DAG (Directed Acyclic Graph). |
| **Origin** | Conventional alias automatically assigned to the primary remote repository URL. |
| **Upstream (`-u`)** | Default remote branch associated with a local branch for tracking pushes and pulls. |
| **Pull Request (PR)** | Hosted GitHub interface for peer reviewing and proposing branch integrations. |
| **Fork** | Hosted copy of an external repository allowing isolated changes and PR submissions. |
| **Merge Conflict** | State where Git encounters irreconcilable line edits across merging branches requiring manual resolution. |

---

## 💻 Syntax and Core Command Reference

### 1. Initialization & Global Configuration
```bash
# Set author identification (used in commit logs)
git config --global user.name "First Last"
git config --global user.email "email@example.com"

# Verify global settings
git config --global --list

# Initialize repository in current folder
git init
```

### 2. Staging, Committing & History
```bash
# Inspect tree status
git status

# Stage specific file, extension group, or all changes
git add main.py
git add *.py
git add .

# Inspect deltas
git diff                  # Unstaged modifications
git diff --staged         # Staged changes waiting for commit

# Record snapshot
git commit -m "feat: add user authentication validation"

# Inspect commit logs
git log
git log --oneline         # Concise single-line summary with abbreviated hashes
git ls-files              # List all files currently tracked in the index
```

### 3. File Renaming, Deletion & Undoing Changes
```bash
# Tracked file operations
git mv old_name.py new_name.py   # Renames and stages automatically
git rm redundant.py              # Deletes from disk and stages removal

# Unstaging without losing local edits
git restore --staged main.py

# Discarding unstaged local changes (Irreversible)
git restore main.py

# Reverting committed changes safely (creates a new inverse commit)
git revert <commit_id>
```

### 4. Branching & Merging
```bash
# List local branches (* denotes active branch)
git branch

# Create and switch to a feature branch
git switch -c feature-login

# Switch between existing branches
git switch main

# Merge feature branch into active target branch
git switch main
git merge feature-login

# Linear history rebase (local feature branches only)
git switch feature-login
git rebase main
```

### 5. Remote Repositories & Collaboration
```bash
# Connect local repo to GitHub remote
git remote add origin https://github.com/USERNAME/repository.git

# Verify remote URLs
git remote -v

# Rename default branch to main and push with upstream tracking
git branch -M main
git push -u origin main

# Clone an existing remote repository
git clone https://github.com/USERNAME/repository.git

# Synchronize updates from remote
git fetch origin          # Downloads remote data without merging
git pull origin main      # Fetches and merges into active local branch
```

### 6. Tagging & Releases
```bash
# Create annotated release tag
git tag -a v1.0.0 -m "Release version 1.0.0"

# Inspect tag metadata
git show v1.0.0

# Push tag to remote
git push origin v1.0.0
```

---

## 📝 Explanations & Practical Examples

### Standard Feature-Branch Collaboration Workflow
In professional engineering teams, developers never push directly to `main`. The canonical lifecycle:

```text
1. Sync main:         git switch main && git pull
2. Create branch:     git switch -c feature-calculator-ui
3. Implement & test:  (make code modifications)
4. Stage & commit:    git add . && git commit -m "feat: implement calculator UI layout"
5. Push to remote:    git push -u origin feature-calculator-ui
6. Open Pull Request: Propose merge from feature-calculator-ui into main on GitHub
7. Peer Code Review:  Reviewers inspect diffs, test builds pass, approvals granted
8. Merge on GitHub:   PR merged into main branch
9. Local cleanup:     git switch main && git pull
```

---

## 📂 Assignment-Based Learning

| Assignment | Title / Description | Source Files | Detailed Documentation | Status |
| :---: | :--- | :--- | :--- | :---: |
| **Assignment 8** | **Git Basics:** Repo init, author config, file tracking (`readme.txt`), staging, committing, `git diff`, `git restore`, history logs, `git revert`, python program (`vecadd.py`), `git rm`, detached `HEAD` checkout. | [`vecadd.py`](./assignments/Assignment-8/vecadd.py) | [Assignment 8 Documentation](./assignments/Assignment-8/README.md) | ✅ Completed |
| **Assignment 9** | **Git Branching:** Observing `HEAD`, branch creation (`fast`), renaming (`parallel`), switching, parallel dot product with `multiprocessing`, bug fix on `master`, resolving merge conflicts in VS Code, deleting branch, exploring `git stash`. | [`vecadd.py`](./assignments/Assignment-9/vecadd.py) | [Assignment 9 Documentation](./assignments/Assignment-9/README.md) | ✅ Completed |

---

## 📂 Lecture Coverage & Coursework Tracker

| Unit / Lecture | Topic Title | Core Concepts Covered | Status |
| :---: | :--- | :--- | :---: |
| **Lecture 1** | *Version Control Tools: Git and GitHub* | VCS Principles, CVCS vs. DVCS, Three Main Areas, Global Configuration, Staging/Committing, History Logs, `.gitignore`, File Moves/Deletions, Branching, Merging & Conflicts, Rebase, GitHub Remotes, Pull Requests, Code Reviews, Tags/Releases, Common Errors & Diagnostics | ✅ Documented |
| **Assignment 8** | *Git Basics* | Init, Config, Staging, Commit, Diff, Restore, Log, Revert, File Removal, Detached HEAD | ✅ Documented |
| **Assignment 9** | *Git Branching* | Branching, Renaming, Parallel Multiprocessing, Divergence, Merge Conflict Resolution, Stashing | ✅ Documented |

---

## 🎯 Key Takeaways & Best Practices

- **Atomic, Meaningful Commits:** Each commit should represent a single logical unit of change. Write imperative commit messages (`Add division error handling` rather than `updates` or `bug fix`).
- **Never Rewrite Shared History:** Do not rebase, force-push (`--force`), or reset commits that have already been integrated into remote collaborative branches.
- **Clean Hygiene with `.gitignore`:** Exclude virtual environments, build artifacts, compiled bytecode, logs, and sensitive configurations from day one.
- **Inspect Before Committing:** Run `git status` and `git diff --staged` before every commit to ensure no unintended files or secrets are staged.
- **Branches are Cheap:** Always create a dedicated branch for new features, bug fixes, or experimental refactoring to protect the integrity of `main`.

---

## 🔗 References & Resources

- [Official Git Documentation & Reference Manual](https://git-scm.com/doc)
- [Pro Git Book by Scott Chacon and Ben Straub](https://git-scm.com/book/en/v2)
- [GitHub Documentation & Workflow Guides](https://docs.github.com/)
- [GitHub Skills Interactive Tutorials](https://skills.github.com/)
