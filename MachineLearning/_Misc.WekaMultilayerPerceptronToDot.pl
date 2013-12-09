use Fatal qw(open close);
$curr_node=-1;
print("digraph {\n");
open A,"$ARGV[0]";
while (<A>){
		if(/^Sigmoid Node (\d+)/){
				$curr_node=$1;
		}
		elsif($curr_node!=-1 && /^\s+Node (\d+)\s+([-+]?[0-9]+\.[0-9]{3})/){
				print $1," -> ",$curr_node, "[label=\"$2\"]\n";
		}		
}
print("}");
