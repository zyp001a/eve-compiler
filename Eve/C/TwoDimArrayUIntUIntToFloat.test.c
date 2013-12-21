#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TwoDimArrayUIntUIntToFloat.h"
main(int argc, char **argv){
	uuf_matrix *m;
	uuf_init(&m, 22686, 22686);
	uuf_read_file(m, "/home/zyp/db/data/GO/011313_converted/goa_human.BP.noIEA.011313.res.gene_link.Resnik");
	uuf_cal_file(m, argv[1]);
}
