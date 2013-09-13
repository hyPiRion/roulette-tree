CC=$(shell which gcc)
INCLUDEPATH= -Iinclude
CFLAGS+= -std=gnu99 -Wall $(COPT) ${INCLUDEPATH} -g -DRTREE_DEBUG
OBJDIR = obj
OBJS = $(addprefix $(OBJDIR)/,main.o rtree.o)
SUBDIRS = test

EXEC = bin/main

.PHONY: test

$(OBJDIR)/%.o: src/%.c include/%.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(EXEC)

$(EXEC): $(OBJS) bin
	$(CC) $(OBJS) -o $(EXEC)

test: $(OBJS)
	@-$(MAKE) -q -C test $(OBJDIR) || \
	if [ $$? -ne 0 ]; then \
		$(MAKE) --no-print-directory -C test $(OBJDIR); \
		cp $(OBJDIR)/rtree.o test/$(OBJDIR)/rtree.o; \
	fi
	@$(MAKE) --no-print-directory -C test test

clean:
	-rm -rf $(OBJDIR)
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done
purge: clean
	-rm -rf bin
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir purge; \
	done

$(OBJS): | $(OBJDIR)

bin:
	mkdir bin
$(OBJDIR):
	mkdir $(OBJDIR)
