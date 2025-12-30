<p align="center">
  <a href="https://github.com/Evgenk2020/puzzle15v2/blob/main/LICENSE">
    <img src="https://img.shields.io/github/license/Evgenk2020/student-experiment" alt="license">
  </a>
  <a href="https://github.com/Evgenk2020/puzzle15v2/commits">
    <img src="https://img.shields.io/github/last-commit/Evgenk2020/student-experiment" alt="last commit">
  </a>
  <a href="https://github.com/Evgenk2020/puzzle15v2">
    <img src="https://img.shields.io/github/repo-size/Evgenk2020/student-experiment" alt="repo size">
  </a>
  <a href="https://github.com/Evgenk2020/puzzle15v2/stargazers">
    <img src="https://img.shields.io/github/stars/Evgenk2020/student-experiment" alt="stars">
  </a>
  <a href="https://github.com/Evgenk2020/puzzle15v2/network/members">
    <img src="https://img.shields.io/github/forks/Evgenk2020/student-experiment" alt="forks">
  </a>
  <a href="https://github.com/Evgenk2020/puzzle15v2">
    <img src="https://img.shields.io/github/languages/top/Evgenk2020/student-experiment" alt="top language">
  </a>
  <a href="https://github.com/Evgenk2020/puzzle15v2/releases">
    <img src="https://img.shields.io/github/v/release/Evgenk2020/student-experiment" alt="latest release">
  </a>
  <!-- Added version badge -->
  <a href="https://github.com/Evgenk2020/puzzle15v2">
    <img src="https://img.shields.io/badge/version-2.0.2-blue" alt="version">
  </a>
</p>

# puzzle15v2

<b>Puzzle 15 for Linux terminal</b>

The 15 Puzzle, also known as the sliding puzzle or Gem Puzzle, is a classic logic puzzle consisting of a 4×4 grid with 15 numbered square tiles and one empty space. The goal is to arrange the tiles in numerical order (1 to 15) by sliding them into the empty space.

![Puzzle 15 screen image](/.img/screen.png)

Arrange the chips with <b>`up` `down` `left`</b> and <b>`right`</b> keys

Press <b>`F1`</b> to restart game

Press <b>`Esc`</b> to exit

<hr>

> You need
> <br>
> [CMake](https://cmake.org/)
> <br>
> to be installed on your Linux system previously

<hr>

<b>To compile and run the game</b>

1. Select empty folder, open terminal and clone the repository

```SH

git clone https://github.com/Evgenk2020/puzzle15v2.git

cd puzzle15v2

```

2. Check for `rpm-build` package to be installed in your system

```SH

rpm -q rpm-build

```

If so you will see `rpm-build-6.0.0-1.fc43.x86_64` or something like that.

If not it will be `package rpm-build is not installed`. Then install it from system repository

```SH

sudo dnf install rpm-build

```

3. Build the Project with `.rpm` setup package for Fedora/CentOS Stream by default

```SH

./build.sh

```

4. Install `.rpm` package from build folder

```SH

sudo dnf install *.rpm

```

<hr>

If using either than Fedora/CentOS Stream change the string `set(assemble_tgz OFF)` in CMakeLists.txt to `set(assemble_tgz ON)` before building the Project. Move `.tar.gz` file to any folder and unpack it.

Then run `fifteen` from unpacked folder.
