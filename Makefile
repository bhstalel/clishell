.PHONY = clean

CC		:= gcc
MKDIR		:= mkdir
RMDIR		:= rm -r
INCLUDE		:= ./include
INCLUDES	:= $(wildcard $(INCLUDE)/*.h)
SOURCE		:= ./src
SOURCES		:= $(wildcard $(SOURCE)/*.c)
OBJS		:= $(patsubst $(SOURCE)/%.c,%.o,$(SOURCES))
EXEC		:= bshell
CFLAGS		:= -I$(INCLUDE)
LDFLAGS		:=

ifdef ENABLE_LOG_DEBUG
CFLAGS		+= -DENABLE_LOG_DEBUG
endif

define print
	@echo "\e[92m[INFO]${1}\e[0m"
endef

all: $(EXEC)

$(EXEC): $(OBJS)
	$(call print, "Generating $@ from $+")
	@$(CC) $(LDFLAGS) $^ -o $@

%.o: $(SOURCE)/%.c
	$(call print, "Generating $@ ..")
	@$(CC) $(CFLAGS) -c $<

clean:
	rm -rf $(EXEC) *.o
