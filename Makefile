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
CFlags = -ldl -lSDLmain -lSDL -lSDL_ttf -lSDL_image
# object options
OFlags = -fPIC
# linker options
LDFlags = -shared -lm

# library names
lib1 = regicide1.so
lib2 = regicide2.so

all: clean installJeu installLib

installLib:
	@echo ""
	@echo "installLib"
	$(CC) $(OFlags) -c $(srcLibDir)/*.c
	@mv *.o $(libDir)
	@echo "OK"
	@echo "Création des librairies ..."
	$(CC) $(LDFlags) -o $(libDir)/$(lib1) $(libDir)/*.o 
	$(CC) $(LDFlags) -o $(libDir)/$(lib2) $(libDir)/*.o
	@echo "OK"

installJeu:
	@echo ""
	@echo "installJeu"
	$(CC) $(srcDir)/*.c -o $(binDir)/$(app) $(CFlags)
	@echo "Jeu prêt"

clean:
	@echo ""
	@echo "clean"
	@echo "Suppression du jeu ..."
	@$(RM) -r $(binDir)	
	@mkdir -p $(binDir)
	@echo "OK"
	@echo "Suppression de la librairie ..."
	@$(RM) -r $(libDir)
	@mkdir -p $(libDir)
	@echo "OK"
