#STRATEGO
#Réalisation par Guillaume NICOLAS, Thomas LE GOUGAUD, Florian BONNIEC, Jonathan GAC
#Voir le readme.txt pour information concernant le Makefile
#-------------------------------------------------------------------------------------

# app name
app = Stratego

# extension to compile
CC = gcc

# directories game
srcDir = src
binDir = bin

#directories library
srcLibDir = srcLib
libDir = libs

# compiler options
CFlags = -ldl -lSDLmain -lSDL -lSDL_ttf
# object options
OFlags = -fPIC
# linker options
LDFlags = -shared -lm

# library names
lib1 = lowStrategy1.so
lib2 = lowStrategy2.so

all: installJeu

installJeu:
	@echo "Compilation des fichiers de jeu ..."
	$(CC) $(OFlags) -c $(srcDir)/*.c
	@mv *.o $(binDir)
	@echo "OK"
	@echo "Compilation des fichiers de librairie ..."
	$(CC) $(OFlags) -c $(srcLibDir)/*.c
	@mv *.o $(libDir)
	@echo "OK"
	@echo "Création de la librairie ..."
	$(CC) $(LDFlags) -o $(libDir)/$(lib1) $(libDir)/*.o 
	$(CC) $(LDFlags) -o $(libDir)/$(lib2) $(libDir)/*.o
	@echo "OK"
	@echo "Création du jeu ..."
	$(CC) $(srcDir)/*.c -o $(binDir)/$(app) $(CFlags)
	@echo "Jeu prêt"

installLib:
	@echo "Compilation des fichiers de librairie ..."
	$(CC) $(OFlags) -c $(srcLibDir)/*.c
	@mv *.o $(libDir)
	@echo "OK"
	@echo "Création des librairies ..."
	$(CC) $(LDFlags) -o $(libDir)/$(lib1) $(libDir)/*.o 
	$(CC) $(LDFlags) -o $(libDir)/$(lib2) $(libDir)/*.o
	@echo "OK"

clean:
	@echo "Suppression des fichiers de jeu compilé ..."
	@$(RM) -r $(binDir)	
	@mkdir -p $(binDir)
	@echo "OK"
	@echo "Suppression des fichiers compilé de la librairie ..."
	@$(RM) -r $(libDir)
	@mkdir -p $(libDir)
	@echo "OK"
