CheckUserSpace.Dir = "/home/zyp/record"
CheckUserSpace._Eval = "
~du -smc /home/* >@|Dir|/du-`date +'%m-%d-%y'`-protein &
~du -smc /serverDNA/* >@|Dir|/du-`date +'%m-%d-%y'`-dna &
~du -smc /homeold/* >@|Dir|/du-`date +'%m-%d-%y'`-rna &
"