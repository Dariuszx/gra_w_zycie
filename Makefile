
all:
	@cd bin; make gra_w_zycie
debug:
	@cd bin; make debug

.PHONY: clean

clean: 	
	@cd bin; make clean

clean_data:
	cd data; rm -r *

