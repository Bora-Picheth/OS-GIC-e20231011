# OS Lab 3 — File Systems, Wildcards, and Links

## Observations
- **Wildcards:** `?` matches exactly one character (`market1.txt`, `market2.txt`), whereas `*` matches zero or more characters (including `market12.txt`).
- **Hard vs. Soft Links:** Renaming the original report broke the symbolic link (dangling) while the hard link continued reading the original inode. Creating a replacement file with the old name was the surprising behavior: the symbolic link automatically resolved to the new file's content because it stores a pathname, while the hard link remained isolated to the original inode.
- **Relative Targets:** Using relative paths ensures symbolic links stay valid even if the parent workspace folder is moved or renamed.
