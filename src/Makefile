MAKEFLAGS += -r -R
# get the definition origin of `MAKEVAL
MV_ORIG   := $(origin MAKEVAL)
ifeq ($(MAKEVAL),)
MAKEVAL   := defined in makefile
endif

.PHONY: all
all:
	@echo $(MAKEFLAGS) $(MAKEVAL)
	@echo "Origin: $(MV_ORIG); invoking sub-make..."
	@echo "------------------------------------------------"
	$(MAKE) --no-print-directory -f dump-env.mk $@