RM = rm -f
CP = cp
MAKE = make

SOURCE_DIR = src

all: world

src/Makefile: src/Makefile.dist
	$(CP) $(SOURCE_DIR)/Makefile.dist src/Makefile

depend: src/Makefile
	$(MAKE) -C $(SOURCE_DIR)/ depend

world: depend
	$(MAKE) -C $(SOURCE_DIR)/

clean: src/Makefile
	$(MAKE) -C $(SOURCE_DIR)/ clean
	$(RM) $(SOURCE_DIR)/Makefile
