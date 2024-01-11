# STATUS: BETA!

---

# General Roadmap

## Compatibility headers

- [x] stdlib.h
- [x] ansi.h
- [ ] ncurses.h
- [ ] ncursesColor.h
- [ ] conio.h
- [ ] Beep.h
- [ ] PlaySound.h
- [ ] windows.h
- [ ] allCompat.h

## Other points to cover

- [ ] README.md
- [ ] examples and headers on folders
- [ ] Code comments and identation
- [ ] documentation for each header file
- [ ] LICENCE.md
- [ ] ConsultedReferences.md

---

# Installation

```sh
git clone https://github.com/ArielParra/c_compatibility_headers
cd c_compatibility_headers/
make
cd Beep/
make
```

---

# FAQ

- Im using ncurses.h to create my conio.h implementation
- wide characters from wchar.h will not be considered in this project
- this project uses alot of macros to define and redifine functions
- This may not be sutable for production :P
- song.wav clip downloaded from https://freemusicarchive.org/music/John_Harrison_with_the_Wichita_State_University_Chamber_Players/The_Four_Seasons_Vivaldi

# Alternatives

- [tapio rlutil](https://github.com/tapio/rlutil)
- [pdcurses](https://pdcurses.org/)
- [justinmeza wincurses](https://github.com/justinmeza/wincurses)
- [ncurses MinGW Port](https://invisible-island.net/ncurses/#download_mingw)
- [Sandroid Turbo C conio.h](https://www.sandroid.org/TurboC/index.html)
- [jeaiii itoa - Fast integer to ascii](https://github.com/jeaiii/itoa)
- [Baltasarq cscrutil](https://github.com/Baltasarq/cscrutil)
- [zoelabbb conio.h using termios](https://github.com/zoelabbb/conio.h/tree/master)

# Licence

- This project is Open Source, dont know which licence yet
- Beep.h forked from https://github.com/zserge/beep

# Warnings

- This project is think to use only with GCC compiler and Glibc, compatibility with Compilers like LLVM/CLANG and/or other C librarys like ulibc, musl or bionic is unkown and most likely may not work as intended.
- this project allow the use of itoa and gets which are unsafe functions.
- this project has only been tested in Windows 10, linux and MacOS, BSD or other \*NIX will probably work
- The GNU make is used for the MAKEFILE so it isnt compatibile with BSD Make
- Functions are defined in the headers which may lead to ODR violations

# Dependencies

- ncurses.h and conio.h may need ncurses and/or ncurses-dev package
- Beep.h may need libasound2-dev or alsa-lib package for linux
- PlaySound.h needs alsa compatible output and aplay command on linuc
- PlaySound.h may need sox or ffmpeg for other \*NIX Systems
