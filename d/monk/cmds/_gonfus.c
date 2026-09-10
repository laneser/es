//#pragma save_binary

// This command is for monk only. It list all gonfus now the monk
// has learned. Created by Angel, almost rewriten by Kyoko@Eastern.Stories.

#include <mudlib.h>

inherit DAEMON;

int cmd_gonfus()
{
	int i, s;
	string *gonfu,  msg, tmp;
	mapping known, exp;

	known = (mapping)this_player()->query("monk_gonfu");
	exp = (mapping)this_player()->query("gonfus_exp");
	if( !known || sizeof(known) == 0 ) {
		write("你目前不會任何功夫。\n");
		return 1;
	}


	msg = "你目前所能使用的功夫有:\n";
	gonfu = keys(known);
	for( i=0; i<sizeof(gonfu); i++ ) {
		if( gonfu[i] == "fist" || gonfu[i]=="heal" ) continue;
		msg +=
		sprintf("%14-s(%14-s)  第%3d重  (熟練經驗值%d) \n", to_chinese(gonfu[i]), 
         	capitalize(gonfu[i]),  known[gonfu[i]], ( exp ? exp[gonfu[i]] : 0 )) ;
       }

	if( gonfu = known["fist"] ) {
		tmp = "\n基本拳法: " ;
		for( i=0; i<sizeof(gonfu); i++ )
			tmp += 
				sprintf("%s(%s), ", to_chinese(gonfu[i]), gonfu[i]) ;
		msg += iwrap(tmp, 60);
	}
	if( gonfu = known["heal"] ) {
		tmp = "\n醫療心法及指法: " ;
		for( i=0; i<sizeof(gonfu); i++ )
			tmp += 
				sprintf("%s(%s), ", to_chinese(gonfu[i]), gonfu[i]) ;
		msg += iwrap(tmp, 60);
	}
        if ( this_player()->query("monk_score") ) {
	msg += sprintf("\n你對少林的貢獻功勞有 %d 點\n\n",(int)this_player()->query("monk_score"));
                                                   }
	write(set_color(msg,"GRN",this_player()));
	return 1;
}

int help()
{
	write( @HELP
用法 : gonfus
這個指令會列出目前你所通曉的功夫以及等級，另外也會列出你目前對少林寺的
貢獻度。

參考 : fist
HELP
	      );
	return 1;
}
