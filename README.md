# STATUS: BETA!

- [x] stdlibCompat.h
- [x] ansiCompat.h
- [x] Play_Sound.h
- [ ] ncursesCompat.h
- [ ] allCompat.h
- [ ] beep.h
- [ ] README.md
- [ ] LICENCE.md
- [ ] ConsultedReferences.md

---

# FAQ
This may not be sutable for production :P
stdlibCompat uses deprecated functions in Windows
song.wav clip downloaded from https://freemusicarchive.org/music/John_Harrison_with_the_Wichita_State_University_Chamber_Players/The_Four_Seasons_Vivaldi

# Licence
No guaranties
Software is as it is
it is Open Source, dont know which licence yet

# Warnings
This project is mainly to use with GCC compiler and Glibc, compatibility with Compilers like LLVM/CLANG and/or other C librarys like ulibc, musl or bionic is unkown and most likely may not work as intended. 

this project has only been tested in Windows 10, linux and MacOS, BSD or other *NIX will probably works with manual patches
The GNU make

ncursesCompat may need ncurses and/or ncurses-dev package 

Beep may need libasound2-dev package


