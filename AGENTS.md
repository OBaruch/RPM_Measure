# Contributor & Agent Guidelines

Rules for anyone, human or automated, who changes this repository.

## Hard Rules

1. **Do not modify `src/spinnerRPM_v2.2/spinnerRPM_v2.2.ino`.** It is the preserved original implementation (2021). Do not reformat it, re-comment it, fix it or convert its line endings. Its Git blob must remain `2ab79fb87d5423beb8c4a75c4dd43a0c77a26115`.
2. **Do not modify `LICENSE`.**
3. **Label every claim** in documentation as Confirmed, Inferred or Unknown when it is not directly obvious from the code. Do not invent the course, board, sensor or purpose.
4. **Do not add infrastructure** the project never had (CI, containers, package managers, linters, test frameworks) unless explicitly requested.

## Where Things Go

| Content | Location |
|---|---|
| Original sketch (read-only) | `src/spinnerRPM_v2.2/` |
| Explanatory docs | `docs/` |
| Intent / spec / plan | `docs/sdlc/` |
| Ideas and known issues | `docs/possible-improvements.md` (documented, never applied to the original) |
| A new functional version | a **new** sketch folder, e.g. `src/spinnerRPM_v3/`, with its own intent/spec/plan |

## Workflow for Changes

1. Update or add `docs/sdlc/intent.md` → `spec.md` → `plan.md` before changing anything.
2. Keep changes on a feature branch and submit them through a pull request.
3. Before opening the PR, verify integrity:
   ```bash
   git ls-files -s src/spinnerRPM_v2.2/spinnerRPM_v2.2.ino   # 2ab79fb…
   ```
