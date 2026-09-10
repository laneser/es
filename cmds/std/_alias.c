//#pragma save_binary

/*
 * alias user command
 * this is from portals
 * One of them wrote it, again.
 * In the course of time it grew into part of the TMI-2 mudlib, via the
 * old TMI mudlib. In any event, you should leave this header on. Moby
 * added it in 4-9-93.
 */

#include <alias.h>
#include <mudlib.h>
#include <body.h>

inherit DAEMON;

void print_aliases(mapping n, mapping x)
{
	int i;
	string *tmp;

	tmp = keys(n);
	if(sizeof(tmp)) {
		write( "您設定了 "+sizeof(tmp)+" 個替代指令:\n");
		tmp = sort_array(tmp, "sort_keys", this_object());

		for(i = 0; i < sizeof(tmp); i++)
			printf("  %-10s = %s\n", tmp[i], n[tmp[i]]);
	}
	tmp = keys(x);
	if(sizeof(tmp)) {
		write( "和 "+sizeof(tmp)+" 替代動詞:\n");
		tmp = sort_array(tmp, "sort_keys", this_object());

		for(i = 0; i < sizeof(tmp); i++)
			printf("	%-15s %s\n",tmp[i],x[tmp[i]]);
	}
	else if( !sizeof(keys(n)) )
		write("您目前沒有設定任何替代指令。\n");
}

int cmd_alias(string str)
{
	int i, sl;
	int index;
	string verb,cmd,*elements,tmp1,tmp2;
	mapping alias;
	object act_ob;

	act_ob = previous_object();

	if(str == "-global") {
		print_aliases((mapping)GA_SERVER->query_global_aliases(),
			(mapping)GA_SERVER->query_global_xaliases());
		return 1;
	}

	if(str == "-clear") {
		act_ob->clear_aliases();
		return 1;
	}

	alias = (mapping)act_ob->query_aliases();
	if(!alias) alias = ([]);
	// reset alias table if too many, added by Kyoko.
 	elements = keys(alias);
	if( sizeof(elements) > MAX_ALIAS_NUMBER ) {
		write( @SORRY
對不起, 為了增快 ES 的速度, alias 最多只能設定 40 個....
你 alias 的數目太多已經被 reset 了, 請重新設定。
SORRY
);
		act_ob->clear_aliases();
		return 1;
	}

	if(!str) {
		if(!elements || !sizeof(elements) )
			write("你目前沒有定義任何替代指令。\n");
		else
			print_aliases((mapping)act_ob->query_nalias(),
						  (mapping)act_ob->query_xalias()
			);
		return 1;
	}

	//  Strip out the leading spaces in the command request
	while(str[0] == ' ') str = str[1..strlen(str)-1];
	if(sscanf(str,"%s %s", verb, cmd) == 2) {
		if (!verb || verb == "" || verb == " ")
			return notify_fail("你必須指定一個動詞給替代指令。\n");

		if((verb=="alias") || (verb=="unalias") || (verb=="go") )
			return notify_fail (sprintf("你不能用 %s 這個字當動詞。\n",verb));

		if((sscanf(cmd,"%s,"+verb+",%s",tmp1,tmp2)==2) ||
		   (sscanf(cmd,"do "+verb+",%s",tmp1)==1) ||
		   ((sscanf(cmd,"%s,"+verb+"%s",tmp1,tmp2)==2) && tmp2=="") )
			return notify_fail("你不能把相同的命令放到替代指令中 !!\n");

		if(environment(this_player())) { // it's probably not a new player
			// Players demand this .... by Annihilator@Eastern.Stories (12-26-93)
			if( strsrch(cmd, '$')==-1 ) cmd += " $*";
			if( !alias[verb] )
				// set Max alias number, added by Kyoko.
				if( sizeof(elements) < MAX_ALIAS_NUMBER )
				  write(
					"加入新的替代指令 "+verb+" ( 替代 "+cmd+" ) .... OK.\n");
				else {
				  write(
					"你已經設定太多的替代指令了, 請先殺掉一些。\n");
				  return 1;
				}
			else
			     if(strlen(cmd)>MAX_ALIAS_SIZE)
			       {  write("你的替代指令長度大於容許值,請試著改短一點。\n") ;
			          return 1;
			       }
			     else
				  write("修改舊有替代指令 "+verb+" ( 改為 "+cmd+" ) .... OK.\n");
		}
		act_ob->add_alias(verb,cmd);
		return 1;
	}

	if(!alias[str]) {
		write(
			"你並沒有設定 \""+str+"\" 這個替代指令。\n");
		return 1;
	}

	printf("%-15s%s\n",str,alias[str]);
	return 1;
}

protected int sort_keys(string a, string b) {  return strcmp(a, b);  }

void help()
{
write(@HELP
一般參數: -clear  刪除全部定義.

alias			查看全部定義.
alias <alias> <command>	定義<alias>是<command>.
alias <alias>		檢查定義<alias>.
unalias <alias>		刪除定義<alias>.

可替換的變量:
	$# - 替代數字或文字.
	$* - 替代任何事件.

HELP
);
}
