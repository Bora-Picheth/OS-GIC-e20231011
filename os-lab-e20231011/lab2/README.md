# Lab 2 — Linux Navigation and File Management: individual report

Copy this template to `lab2/README.md` in your own course repository. Follow [the instructions](lab2-instruction.md). Your prediction, debrief and checkpoint answers are already saved by `oslab`; do not copy them here. The marks come from those records and your evidence files; this report is your own record of the lab.

- Student name/ID: Bora Picheth e20231011
- Ubuntu username: gic-bora-picheth
- My values (`oslab values lab2`): file1 = sales north.txt, file2 = vendor list.txt, owner = Audit, reader = Engineering, third = Support
- Files: `evidence/paths.txt`, `evidence/tree.txt`, `evidence/checkpoint.txt`

## What I Did

| Step | My command | Current folder when I ran it |
|---|---|---|
| Move the first file (relative destination) | `mv "incoming/sales north.txt" reports/` | `~/oslab-work/lab2` |
| Move the second file (absolute paths) | `mv "$OSLAB_WORKSPACE/lab2/incoming/vendor list.txt" "$OSLAB_WORKSPACE/lab2/reports/"` | `~/oslab-work/lab2` |
| Read the report from my reader department (relative path) | `cat "../../reports/sales north.txt"` | `~/oslab-work/lab2/TechCorp/Engineering` |
| The path error I made on purpose, and its message | `cat "reports/sales north.txt"` resulted in `cat: 'reports/sales north.txt': No such file or directory` | `~/oslab-work/lab2/TechCorp/Engineering` |
| The relative path that fixed it | `../../reports/sales north.txt` | `~/oslab-work/lab2/TechCorp/Engineering` |

## Explanation

A correct file name will still return a "No such file or directory" error if your terminal is currently in a different folder than the file, and you do not provide a valid relative or absolute path directing the system to it. The `mv` command removes the file from its original location and places it in a new one, just like when I moved `sales north.txt` out of the `incoming/` folder. In contrast, the `cp` command duplicates the file so it exists in both places, which is what happened when I copied the files from `reports/` to `TechCorp/Audit/` while keeping the originals in `reports/`.

## What My Tests Do Not Prove

Using `ls` only proves that a file exists and has a specific name, but it does not prove that the data inside the file matches the original. To actually prove the contents are identical byte-for-byte, I had to use the `cmp` command.

## Plus / Challenge (only if you did them)

My one-command move from the `mess/c` folder was `mv "../a/b/lost file.txt" found.txt`. To copy the file into the third department (`TechCorp/Support/`), I needed `3` sets of `..` segments.

## AI Note (optional)

I used an AI to help troubleshoot syntax errors when setting environment variables and combining terminal commands without line breaks. The AI suggested running commands one at a time and using `cat >` to manually push file contents into my checkpoint text file when the `oslab checkpoint` generator could not be re-run, which I tested by running `oslab check lab2` to confirm the milestone passed.