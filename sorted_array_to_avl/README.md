# Array to AVL

## Requirements

### General

- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 14.04 LTS
- Your programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
- All your files should end with a new line
- A README.md file, at the root of the folder of the project, is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- You are not allowed to use global variables
- No more than 5 functions per file
- You are allowed to use the standard library
- In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
- The prototypes of all your functions should be included in your header file called binary_trees.h
- Don’t forget to push your header file
- All your header files should be include guarded

## More Info

### Data structures

### Basic Binary Tree

```
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
```

### AVL Tree

`typedef struct binary_tree_s avl_t;`

## Print function

To match the examples in the tasks, you are given [this function](https://github.com/hs-hq/0x1C.c)

This function is used only for visualisation purpose. You don’t have to push it to your repo. It may not be used during the correction

### 0x1C.c

Functions to print binary trees in a pretty way

```
                           .----------------------(006)-------.
                      .--(001)-------.                   .--(008)--.
                 .--(-02)       .--(003)-------.       (007)     (009)
       .-------(-06)          (002)       .--(005)
  .--(-08)--.                           (004)
(-09)     (-07)
```

[Original code](Original code from http://stackoverflow.com/a/13755911/5184480)
