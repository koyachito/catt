# catt

**catt** is a small terminal animation command written in C.

When you run `catt`, a cat walks across your terminal.

Inspired by [`sl`](https://github.com/mtoyoda/sl), but redesigned as a cat-themed terminal toy using C and ncurses.

![catt demo](demo.gif)

## Status

This project is currently a prototype.

Implemented:

* Basic terminal animation
* Cat ASCII art
* Walking animation frames
* Safe drawing when the cat moves off-screen
* ncurses-based screen control
* Makefile build

Planned:

* `-m` option: make the cat say `meow`
* `-n` option: show multiple cats
* `-d` option: dog mode
* Man page
* Japanese README

## Requirements

* C compiler
* ncurses
* make

On Ubuntu:

```bash
sudo apt update
sudo apt install build-essential libncurses-dev
```

## Build

```bash
make
```

## Usage

```bash
./catt
```

The cat slides from the right side of the terminal to the left.

## Project structure

```text
catt/
├── README.md
├── Makefile
├── catt.c
├── demo.gif
└── .gitignore
```

Additional files such as `catt.h`, man pages, and Japanese documentation may be added as the project grows.

## Development notes

This project started as a C/ncurses practice project based on reading the structure of `sl`.

The current implementation separates the main flow into small functions:

* `init_screen()` initializes ncurses
* `run_animation()` controls the animation loop
* `draw_cat()` draws the current cat frame
* `draw_text_safe()` draws only visible characters inside the terminal
* `close_screen()` restores the terminal state

The cat animation uses multiple ASCII-art frames.
The body stays mostly fixed while the legs change between frames to create a walking effect.

## Roadmap

* [x] Slide a static cat from right to left
* [x] Add walking animation frames
* [ ] Add `-m` option for `meow`
* [ ] Add `-n` option for multiple cats
* [ ] Add `-d` option for dog mode
* [ ] Add man page
* [ ] Add install target
* [ ] Add Japanese README

## License

MIT License
