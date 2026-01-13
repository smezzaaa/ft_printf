*This project has been created as part of the 42 curriculum by smeza-ro.*

---

# ft_printf

## 📄 Description

**ft_printf** is a lightweight reimplementation of the standard C `printf` function. The goal of the project is to reproduce the behavior of `printf` for a subset of conversion specifiers while ensuring correct handling of flags, field width, precision, and edge cases. This project focuses on robustness, clarity of parsing logic, and efficient formatting without using high-level formatting helpers from the C standard library.


## 🔧 Features

- Supported conversion specifiers: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`.
- Flags supported: `-` (left-justify), `0` (zero padding), width (number or `*`), precision (number or `*`), and `.` for precision.
- Proper handling of `NULL` strings, pointers, signed/unsigned integers, and edge values (e.g., INT_MIN).
- Minimal heap allocation; formatting uses stack buffers where appropriate for performance.


## ⚠️ Limitations

- Length modifiers (like `hh`, `h`, `l`, `ll`) are not implemented.
- Floating-point conversions (`%f`, `%e`, `%g`) are not implemented.


## ▶️ Instructions

1. Clone the repository and enter the project root.
2. Compile using the provided `Makefile`:

```bash
make
```

3. Use `./test` or link `libftprintf.a` in your test programs, or run any provided tester:

```bash
gcc -Wall -Wextra -Werror main.c libftprintf.a -o test
./test
```

4. Useful make rules:
- `make` / `make all` — build the library and any sample programs
- `make clean` — remove object files
- `make fclean` — remove objects and binaries
- `make re` — `fclean` then `all`


## 💡 Usage examples

```c
ft_printf("Hello, %s!\n", "world");
ft_printf("Hex: %#x, Dec: %08d\n", 255, 42);

// Expected outputs similar to standard printf for the supported features.
```


## 📚 Resources

- `man 3 printf` — official reference for formatting behavior
- ISO C standard and K&R for integer and string handling
- Articles and tutorials on format-string parsing and safe output
- Online resources (StackOverflow threads and blog posts) describing corner cases and edge behavior

**AI usage:** This README and the algorithm explanation were drafted with the help of GitHub Copilot (Raptor mini (Preview)) to suggest phrasing, structure, and examples. AI was used for: drafting documentation, clarifying algorithm descriptions, and brainstorming test cases. All code and final decisions were implemented and reviewed by the author.


## 🧠 Algorithm and Data Structures (detailed explanation & justification)

### Overview

ft_printf implements a two-phase approach:

1. **Parsing:** Walk the format string character-by-character. When encountering a `%`, parse the format token into a `format` structure capturing flags, width, precision, and specifier.
2. **Formatting / Emission:** For each parsed token, fetch necessary `va_arg` values, format data according to the parsed parameters, and write the output to the target (typically STDOUT) while counting printed characters.

This approach keeps responsibilities separate (parsing vs. printing) and makes the code easier to test and reason about.


### Primary data structure: `t_format` (example fields)

- `char specifier;`           // 'c', 's', 'd', 'i', 'u', 'x', 'X', 'p', '%'
- `int width;`                // width from number or -1 for not specified
- `int precision;`            // precision value or -1 for not specified
- `bool left;`                // '-' flag
- `bool zero;`                // '0' flag
- `bool dot;`                 // whether precision was provided

Justification: A compact struct captures all configuration derived from a single `%` token, enabling formatting functions to act on a single, consistent source of truth.


### Parsing details

- Parse flags in a fixed order: look for `-` and `0` and set struct fields accordingly.
- Width: if an integer is found, store it; if `*`, read next `va_arg` as an `int`.
- Precision: if `.` is present, parse digits or `*` similarly. If `.` present without digits, treat precision as 0.
- Specifier: final character after flags/width/precision.

This deterministic parsing ensures consistent behavior that mirrors `printf` semantics and is simple to test.


### Formatting details (by specifier)

- `%c`: print single character. If width > 1, pad with spaces on left or right depending on `-` flag.

- `%s`: print string (use `"(null)"` for `NULL` pointers if desired). Precision limits the number of printed characters. Width and `-` control alignment.

- `%p`: print pointer as `0x` followed by hexadecimal digits (lowercase). A `NULL` pointer is typically printed as `(nil)` or `0x0` depending on chosen behavior — document the choice and handle consistently.

- `%d`, `%i`: signed decimal. Record sign separately, work with absolute value for digit extraction. Precision affects zero-padding (precision overrides `0` flag). Width determines space padding; left-justify `-` supersedes zero padding.

- `%u`, `%x`, `%X`: unsigned integer formatting. Convert using base 10 or base 16 algorithms. For `%X`, use uppercase hex digits.

- `%%`: print a literal `%`.


### Integer conversion algorithm (implementation details)

- Use a fixed-size stack buffer large enough for the largest representation (e.g., 64 bits -> 20 digits decimal + sign and null terminator).
- Convert numbers by repeatedly dividing by base and storing remainders in the buffer (digits in reverse order), then reverse the buffer slice.
- Complexity: O(k) where k is the number of digits; overall complexity per conversion is linear in the number of produced characters.

Justification: This avoids heap allocations and is fast for common integer sizes.


### Padding & field logic (interaction rules)

- If precision is specified for numeric conversions, the `0` flag is ignored.
- Left-justified (`-`) means padding is on the right; otherwise padding is on the left.
- For numbers, precision controls minimum digits (leading zeros inserted if necessary); width controls overall field size (spaces added to reach width after considering sign and precision).

These rules mirror `printf` and ensure consistent, predictable formatting.


### Memory & performance considerations

- Prefer stack buffers for conversions to avoid dynamic memory overhead.
- Use minimal helper allocations; use `write()` in as few calls as practical or buffer output per-call to limit system calls.
- The parser is O(m) where m is the format string length; total time is O(output_length + m).


## ✅ Testing & Validation

- Create test cases that compare `ft_printf` output and printed length against `printf` for supported specifiers.
- Test edge cases: large widths, zero/negative widths via `*`, precision edge cases, `NULL` pointers/strings, INT_MIN/INT_MAX, zero values with precision 0, etc.


---

## 👤 Author

smeza-ro


---
