//#pragma save_binary
// create by Kyoko.
#include <mudlib.h>

inherit DAEMON;

int help();

int cmd_spellpower(string str)
{
    int sub;
    string c_sub, type;

	if( !str ) {
		sub = (int)this_player()->query("spell_power");
		write( "你法術的出力目前設成降低"+chinese_number(sub)+"級。\n" );
		return 1;
	} else if( sscanf( str, "%s", type )==1 ) {
		switch(type) {
			case "max"     : sub = 0; break;
			case "regular" : sub = 1; break;
			case "normal"  : sub = 2; break;
			case "minor"   : sub = 3; break;
			case "mini"    : sub = 4; break;
			default : return help();
		}
		this_player()->set("spell_power",sub);
		write( "你法術的出力現在重設成降低"+chinese_number(sub)+"級。\n" );
		return 1;
	} else
		return help();
}

int help()
{
	if( can_read_chinese() )
		write( @C_HELP
指令格式: spellpower [出力]

這個指令讓你用來控制法術出力，可設定為 max, regular, normal, minor, mini
分別代表施法級數為Max, Max-1, Max-2 ... 小於零則以零級計算。
C_HELP
		);
	else write ( @HELP
Usage:	power [type] || power <on|off>

This command let you set the power of spells. You can set 
"max", "regular", "normal", "minor", "mini" 
meaning the level of you casting is Max, Max-1, Max-2 ... smallest is 0.
HELP
    );
    return 1;
}
