# STATUS: BETA!

---

# General Roadmap

## Compatibility headers headers

- [x] stdlib.h
- [x] ansi.h
- [ ] ncurses.h
- [ ] ncursesColor.h
- [ ] conio.h
- [ ] Beep.h
- [ ] PlaySound.h
- [ ] windows.h
- [ ] allCompat.h

- [ ] README.md
- [ ] examples and headers on folders
- [ ] dependencies on README.md
- [ ] Code comments and pretty identation
- [ ] documentation for each header file
- [ ] LICENCE.md
- [ ] ConsultedReferences.md

---

# Installation

```
git clone https://github.com/ArielParra/c_compatibility_headers
cd c_compatibility_headers
make
```

---

# FAQ

- wide characters from wchar.h will not be considered in this project
- this project uses alot of macros to define and redifine functions
- This may not be sutable for production :P
- song.wav clip downloaded from https://freemusicarchive.org/music/John_Harrison_with_the_Wichita_State_University_Chamber_Players/The_Four_Seasons_Vivaldi

# Alternatives

- ncurses for windows can be done with pdcurses
- conio for \*NIX systems can be done with sandroid Turbo C
- itoa function can be done better with https://github.com/jeaiii/itoa

# Licence

- it is Open Source, dont know which licence yet
- Beep.h forked from https://github.com/zserge/beep

# Warnings

-This project is mainly to use with GCC compiler and Glibc, compatibility with Compilers like LLVM/CLANG and/or other C librarys like ulibc, musl or bionic is unkown and most likely may not work as intended.

- this project allow the use of itoa and gets which are unsafe functions
- this project has only been tested in Windows 10, linux and MacOS, BSD or other \*NIX will probably work
- The GNU make is used for the MAKEFILE so it isnt compatibile with BSD Make

# Dependencies

- ncursesCompat may need ncurses and/or ncurses-dev package
- Beep may need libasound2-dev package for linux
- Play_Sound needs alsa compatible output and aplay command on linuc
- Play_Sound may need sox or ffmpeg for other \*NIX Systems
