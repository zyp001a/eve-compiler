CEnv:Eve
CEnv.C = Eve.Args[0] + ".c";
CEnv.Out = Eve.Args[0] + ".out";
CEnv = {
		gcc $C -o $Out
		./$Out
}