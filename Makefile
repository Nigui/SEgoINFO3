# app name
app = Stratego.bin

# extension to compile
srcExt = c

# directories
srcDir = src
objDir = obj
binDir = bin

# debug option (=1 for debugging ; =0 no include debug information)
debug = 1

# compiler options
CFlags = -Wall
# linker options
LDFlags = -rdynamic
# library names
libs = lowStrategy.so
# additionnal library directories
libDir = libs/

all:
	@echo "Compilation des fichiers de jeu ..."
	gcc -Wall src/*.c -o bin/stratego -ldl -lm -lSDLmain -lSDL -lSDL_ttf
	@echo "OK"
	@echo "Compilation des fichiers de librairie ..."
	gcc -fPIC -c srcLib/*.c
	@echo "OK"
	@mv *.o libs/
	@echo "Création de la librairie ..."
	gcc -shared -o libs/lowStrategy.so libs/lowStrategy.o
	@echo "OK"

installJeu:
	@echo "Compilation des fichiers de jeu ..."
	gcc -Wall src/*.c -o bin/stratego -ldl -lm -lSDLmain -lSDL -lSDL_ttf
	@echo "OK"

installLib:
	@echo "Compilation des fichiers de librairie ..."
	gcc -fPIC -c srcLib/*.c
	@echo "OK"
	@mv *.o libs/
	@echo "Création de la librairie ..."
	gcc -shared -o libs/lowStrategy.so libs/lowStrategy.o
	@echo "OK"

clean:
	@echo "Suppression des fichiers de jeu compilé ..."
	@$(RM) -r bin/	
	@mkdir -p bin
	touch bin/StrategoLog.txt
	@echo "OK"
	@echo "Suppression des fichiers compilé de la librairie ..."
	@$(RM) -r libs/
	@mkdir -p libs
	@echo "OK"
