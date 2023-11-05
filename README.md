# STATUS: BETA!

- [x] stdlibCompat.h
- [x] ansiCompat.h
- [x] Play_Sound.h
- [ ] ncursesCompat.h
- [ ] conioCompat.h
- [ ] windowsCompat.h
- [ ] allCompat.h
- [ ] beep.h
- [ ] README.md
- [ ] examples and headers on folders
- [ ] dependencies on README.md
- [ ] Code comments and pretty identation
- [ ] man pages for each header file
    - [ ] roadmap and things Ill not do 
    - [ ] stdlibCompat.h
    - [ ] ansiCompat.h
    - [ ] Play_Sound.h
    - [ ] ncursesCompat.h
    - [ ] conioCompat.h
    - [ ] windowsCompat.h
    - [ ] allCompat.h
- [ ] LICENCE.md
- [ ] ConsultedReferences.md

---

# FAQ
- ncursesCompat makes some ncurses.h functions work on windows with the use of conio.h and windows.h and turns some ncurses.h 
- functions like getch() function work as Windows conio.h getch() to get a "Unified and expected behavior" between Windows and *NIX
- This may not be sutable for production :P, you may prefer using pdcurses, SDL, or wide characters from wchar.h
- stdlibCompat uses deprecated functions in Windows
- this project uses alot of macros to define and redifine functions
- song.wav clip downloaded from https://freemusicarchive.org/music/John_Harrison_with_the_Wichita_State_University_Chamber_Players/The_Four_Seasons_Vivaldi

# Licence
- No guaranties
- Software is as it is
- it is Open Source, dont know which licence yet
- Beep.h from https://github.com/zserge/beep 

# Warnings
-This project is mainly to use with GCC compiler and Glibc, compatibility with Compilers like LLVM/CLANG and/or other C librarys like ulibc, musl or bionic is unkown and most likely may not work as intended. 

- this project has only been tested in Windows 10, linux and MacOS, BSD or other *NIX will probably works with manual patches
- The GNU make is used with the makefiles so no compatibility with BSD Make

# Dependencies
- ncursesCompat may need ncurses and/or ncurses-dev package
- Beep may need libasound2-dev package


