IDIR=./include
LDIR=./lib
BDIR=./bin
SDIR=./src
ODIR=$(SDIR)/obj

CC=gcc
LDFLAGS=-O2 -Wall -c
CFLAGS=-O2 -Wall -g -lmnl
INCLUDE=-I$(IDIR)

_REQS=wifi_scan

OBJS=$(ODIR)/$(B).o $(foreach req,$(_REQS),$(patsubst %,$(ODIR)/%,$(req).o))

$(B): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(BDIR)/$(B) $(OBJS) 

$(ODIR)/$(B).o: $(SDIR)/$(B).c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(ODIR)/%.o: $(LDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@


.PHONY: clean fullclean

clean:
	rm -f $(ODIR)/*.o

fullclean:
	rm -f $(ODIR)/*.o $(BDIR)/*

depend::
	makedepend -s "# DO NOT DELETE" -- $(LIBS) -- $(SRC)
# DO NOT DELETE
