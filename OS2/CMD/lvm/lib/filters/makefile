#
# A Makefile for lvm.lib
# (c) osFree project,
# author, date
#

PROJ     = filters
srcfiles = $(p)filter$(e) $(p)filter-composite$(e) $(p)filter-md$(e) $(p)filter-persistent$(e) $(p)filter-regex$(e) $(p)filter-sysfs$(e)
ADD_COPT = -dDEVMAPPER_SUPPORT &
           -i=$(MYDIR)..$(SEP)datastruct -i=$(MYDIR)..$(SEP)misc -i=$(MYDIR)..$(SEP)config -i=$(MYDIR)..$(SEP)commands &
           -i=$(MYDIR)..$(SEP)log -i=$(MYDIR)..$(SEP)metadata -i=$(MYDIR)..$(SEP)device -i=$(MYDIR)..$(SEP)uuid &
           -i=$(MYDIR)..$(SEP)display -i=$(MYDIR)..$(SEP)format_text -i=$(MYDIR)..$(SEP)activate -i=$(MYDIR)..$(SEP)mm &
           -i=$(MYDIR)..$(SEP)locking -i=$(MYDIR)..$(SEP)cache -i=$(MYDIR)..$(SEP)label -i=$(MYDIR)..$(SEP)filters &
           -i=$(MYDIR)..$(SEP)activate -i=$(MYDIR)..$(SEP)..$(SEP)devmapper$(SEP)lib -bd
TARGETS  = $(PATH)$(PROJ).lib
DEST = none

!include $(%ROOT)/mk/libsos2.mk

$(TARGETS): $(OBJS)
 @$(MAKE) $(MAKEOPT) library=$(TARGETS) library
