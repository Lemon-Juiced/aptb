# aptb
**aptb** (Apt Bundle) is a wrapper for the `apt` package manager, bundling several commonly used commands into a single, convenient interface.

## Usage
```sh
aptb <verb> [parameters...]
```

## Commands

| Verb / Alias              | Description                        | Param Limit | Parameters Description                  | Result                                                      |
|--------------------------|------------------------------------|-------------|-----------------------------------------|-------------------------------------------------------------|
| delete                   | Deletes the provided packages      | Limited*    | The packages being targeted             | Runs `apt remove`, `apt purge`, and `apt autoremove` on the specified packages. |
| li, list-installed       | List installed packages            | 0           | N/A                                     | Runs `apt list --installed`.                                |
| lis, list-installed-search | Search installed packages by term  | 1           | The search term to filter on            | Runs `apt list --installed` and filters results using `grep <search_term>`. |

*The limit for `delete` is 512 bytes (arbitrary; users will likely never reach this).

### Examples

- Delete packages:
  ```sh
  aptb delete <package1> <package2>
  ```

- List installed packages:
  ```sh
  aptb li
  # or
  aptb list-installed
  ```

- Search installed packages:
  ```sh
  aptb lis <package>
  # or
  aptb list-installed-search <package>
  ```