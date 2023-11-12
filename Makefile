# Paths
SRCDIR := src
INCDIR := $(SRCDIR)/include
OBJDIR := build
OBJ := $(OBJDIR)/raycalc
SRC := $(wildcard $(SRCDIR)/*.c)

# Flags
CFLAGS = -Wall -std=c99 -I$(INCDIR) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -DPLATFORM_DESKTOP -o $@

# Commands
CC= gcc
RM := rm -rf
MKDIR := mkdir -p

# Targets
.PHONY: all clean raycalc

all: raycalc

raycalc: $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $(SRC)

$(SRC): | $(OBJDIR)

$(OBJDIR):
	$(MKDIR) $(OBJDIR)

clean:
	$(RM) $(OBJDIR)
