//#pragma save_binary
// create by Kyoko.
#include <mudlib.h>

inherit DAEMON;

int help();
void write_power_message(int spell_power);

int cmd_spellpower(string str)
{
    int sub;
    string type;
    
	if( !str ) {
		write_power_message(sub);
		return 1;
	} 
	else if( sscanf( str, "%s", type )==1 ) {
		if (!sub = atoi(type))
			switch(type) {
				case "0"	   :
				case "max"     : sub = 0; break;
				case "regular" : sub = -1; break;
				case "normal"  : sub = -2; break;
				case "minor"   : sub = -3; break;
				case "mini"    : sub = -4; break;
				default : return help();
			}
		this_player()->set("spell_power",sub);
		write_power_message(sub);
		return 1;
	} else
		return help();
}


void write_power_message(int spell_power)
{
	string *sp_msg = ({ "最大", "稍高", "一般", "略低", "最小" });
	
		spell_power = (int)this_player()->query("spell_power");
		if ((spell_power <=0) && (spell_power>-5))
			write( "你正打算以"+sp_msg[-spell_power]+"的能力施展法術。\n");
		else if (spell_power>0)
			write( "你將固定施展"+chinese_number(spell_power)+"級的法術。\n");
		else if (spell_power<=-5)
			write( "你將以非常小的法力來施展法術。\n");
	return;
}

int help()
{
		write( @C_HELP
指令格式: spellpower [出力]

這個指令讓你用來控制法術出力，可設定為 max, regular, normal, minor, mini
分別代表施法級數為最大法術等級, 最大法術等級減一, 最大法術等級減二... 等等
小於零則以零級計算。
出力的部份也可以使用數字代替, 0 表示最大出力, -1, -2, -3, -4 與上述的 
regular, normal, minor, mini 同。
正數表示強制限定施展某級的法術, 如 spellpower 3 表示將施展第三級的法術。
當然, 超過你的所施法術的最大等級時還是照最大等級計算。
C_HELP
		);
    return 1;
}
