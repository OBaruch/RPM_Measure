# Plan — Repository Reorganization

Back to [README](../../README.md) · Previous: [Intent](intent.md) · [Specification](spec.md)

This plan covers the **repository refactor** (structure and documentation). It does not cover any change to the sketch's code; that is explicitly out of scope.

## 1. Starting Point

```
RPM_Measure/
├── LICENSE
└── spinnerRPM_v2.2.ino
```

- 2 commits (2021-02-20), author Baruch Lopez.
- No README, docs, assets, data or configuration.

## 2. Constraints

| ID | Constraint |
|---|---|
| C-1 | The sketch content must stay byte-for-byte identical (including CRLF line endings). |
| C-2 | `LICENSE` stays unchanged. |
| C-3 | Only facts supported by the repository are stated as confirmed. Inferences and unknowns are labeled. |
| C-4 | No infrastructure the original project never had (CI, Docker, linters, build tools, tests). |
| C-5 | Folders are created only when they hold real content. |

## 3. Tasks

| # | Task | Output | Status |
|---|---|---|---|
| T1 | Inventory every file and the Git history | [project-context.md](../project-context.md) evidence table | Done |
| T2 | Record baseline integrity of the sketch | Git blob + SHA-256 (see §4) | Done |
| T3 | Move the sketch to `src/spinnerRPM_v2.2/` with `git mv` (Arduino needs the folder name to match the sketch name) | Moved file, history kept | Done |
| T4 | Protect line endings with `.gitattributes` (`*.ino -text`) | `.gitattributes` | Done |
| T5 | Write README | [README.md](../../README.md) | Done |
| T6 | Write context, code overview and improvement notes | `docs/*.md` | Done |
| T7 | Write intent, spec and plan | `docs/sdlc/*.md` | Done |
| T8 | Add contributor/agent guardrails | [AGENTS.md](../../AGENTS.md) | Done |
| T9 | Add a minimal `.gitignore` | `.gitignore` | Done |
| T10 | Verify integrity after the move (§4) | Matching hashes | Done |

**Deliberately not created:** `data/`, `assets/`, `examples/`, `archive/`, `docs/original/` (no such material existed), and `architecture.md` (a 45-line single-file sketch has no architecture to describe beyond the flow already in the README and spec).

## 4. Verification

Integrity of the sketch before and after the move:

| Check | Before (`spinnerRPM_v2.2.ino`) | After (`src/spinnerRPM_v2.2/spinnerRPM_v2.2.ino`) |
|---|---|---|
| Git blob | `2ab79fb87d5423beb8c4a75c4dd43a0c77a26115` | `2ab79fb87d5423beb8c4a75c4dd43a0c77a26115` |
| SHA-256 | `bad7ace4834fec620787aa90b257f8957cbc627b7610cd287146f32897bacfea` | `bad7ace4834fec620787aa90b257f8957cbc627b7610cd287146f32897bacfea` |
| Size | 760 bytes | 760 bytes |

To re-check at any time:

```bash
git ls-files -s src/spinnerRPM_v2.2/spinnerRPM_v2.2.ino   # blob must be 2ab79fb…
sha256sum src/spinnerRPM_v2.2/spinnerRPM_v2.2.ino          # must be bad7ace4…acfea
git diff --stat 0bf59a1 -M -- '*.ino'                      # must show a pure rename (100% similarity)
```

**Not verified:** compilation and behavior on real hardware. No board or toolchain was available, and the original hardware setup is undocumented.

## 5. Future Work (outside this plan)

Any functional evolution of the sketch (see [possible-improvements.md](../possible-improvements.md)) should get its own intent → spec → plan cycle and live in a **new** sketch folder (for example `src/spinnerRPM_v3/`), leaving `src/spinnerRPM_v2.2/` untouched as the historical baseline.
