# puzzle15v2

<b>Puzzle 15 for Linux terminal</b>

The 15 Puzzle, also known as the sliding puzzle or Gem Puzzle, is a classic logic puzzle consisting of a 4×4 grid with 15 numbered square tiles and one empty space. The goal is to arrange the tiles in numerical order (1 to 15) by sliding them into the empty space.

![Puzzle 15 screen image](/.img/screen.png)

Arrange the chips with <b>`up` `down` `left`</b> and <b>`right`</b> keys

Press <b>`F1`</b> to restart game

Press <b>`Esc`</b> to exit

<hr>

<b>To compile and run the game</b>

1. Clone the Repository

```SH

git clone https://github.com/Evgenk2020/puzzle15v2.git

cd puzzle15v2

```

2. Check for `rpm-build` package to be installed in your system. If not, install it from system repository

```SH

sudo dnf install rpm-build

```

3. Build the Project with .rpm setup package for Fedora/CentOS Stream by default.

```SH

./build.sh

```

4. Install .rpm package from build folder

```SH

cd build && sudo dnf install *.rpm

```

<hr>

If using either than Fedora/CentOS Stream change the first string `set(assemble_tgz OFF)` in CMakeLists.txt to `set(assemble_tgz ON)` before building the Project. Move `.tar.gz` file to any folder and unpack it. Then run `fifteen` from unpacked folder.
