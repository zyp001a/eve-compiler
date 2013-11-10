#!/usr/bin/perl
@EPATH = qw(
/home/zyp/dna/core/src/root
.
);
sub ExistFile{
		my $f = shift;
		for my $p (@EPATH){
				if(-f "$p/$1"){
						return "$p/$1";
				}
				elsif(-f "$p/$1.e"){
						return "$p/$1.e";
				}
				elsif(-f "$p/$1.eve"){
            return "$p/$1.eve";
        }
		}
		return 0;
}
while ($line=<STDIN>){
		if($line =~ /^Load\s*\(?((?:\\.|[^(\\\)|;)])+)\)?[;\n\r]/){
				$file = ExistFile($1);
				if(!$file){
						print STDERR "$1 or $1.e not exist\n\t at line $.: $line\n";
        }			
				system qq(cat $file | ./pp);
		}
		else{
				chomp $line;
				print "$line\n";
		}
}

