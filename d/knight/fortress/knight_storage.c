#include <mudlib.h>
#include <money.h>
#include <move.h>

//inherit "/std/room/std_storage";
inherit ROOM;

void create()
{
	::create();
	set_short("A empty room", "騎士公會儲藏室");
	set_long( @C_LONG_DESCRIPTION
你現在來到了一間掛滿了各式武器、盔甲的儲藏室，高等級的騎士們往往
樂於將他們多餘的裝備留在此地讓其他需要的人取用。牆角有個櫃子是用來放
武器的。往南邊是一條走道通往騎士廳。
C_LONG_DESCRIPTION
		);

	set( "light", 1 );
	set( "exits", ([ 
		"south" : "/d/knight/fortress/knight_inner" ]) );
	reset();
}

int clean_up() { return 0; }

void init()
{ 
	add_action( "get_item","get" );
	add_action( "drop_item","drop" );
}

int get_item(string str)
{
	int res,lv,ws,WC,bonus,number,p_wealth;
	object item,player;
	string type;
	mixed *value;
	
	player = this_player();
	lv = player->query_level();
	if( !str || str=="" ) return 0;
	if( str=="all" ) {
		tell_object(player,"請指明你要撿的東西，別太貪心喔。\n" );
		return 1;
		}
	if( !(item = present(str,this_object())) ) return 0;
	if( WC = item->query("weapon_class") ) {
		if( WC >=40 ) {
			bonus = WC/10;
			if( !(ws = player->query("war_score")) || ws < 1999 ){
				if( lv >= 15 ){
					value = item->query("value");
					number = value[0];
					type = value[1];
					p_wealth = player->query("wealth/"+type);
					if( p_wealth < number ) {
						tell_object( player,@A_LONG
你沒有戰功又沒有錢，實在無法放心把東西借給你。
A_LONG
						);
						return 1;
						}
						res = (int)item->move( player );
						if( res==MOVE_TOO_HEAVY ) {
							write( "你拿不動" + item->query("c_name") + "，太重了。\n");
							return 1;
						}
						player->debit( type,number );
						tell_object( player,@B_LONG
為防止你將它變賣，先扣下你與這東西的價值相等的錢，當你歸還時再退錢給你。
B_LONG
						);
						return 1;
					}
				tell_object(player,@C_LONG
你發現附近的騎士們都以不屑的眼神看著你，羞愧之心使你趕快把東西放回原位。
C_LONG
					);
				return 1;
			}
			res = (int)item->move( player );
			if( res==MOVE_TOO_HEAVY ) {
				write( "你拿不動" + item->query("c_name") + "，太重了。\n");
				return 1;
			}
			tell_object( player,@D_LONG
為確保你會將它歸還，先扣你一些戰功作抵押。
D_LONG
			);
			this_player()->add( "war_score", -bonus );
			return 1;
		}
	}
	else return 0;
}

int drop_item(string str)
{
	
	object *inv,env,player,item;
	int WC,ws,i,number,bonus;
	string short,unit,c_name,type;
	mixed *value;
	
	player = this_player();
	c_name = player->query("c_name");
	env = environment(this_player());
	inv = all_inventory(player);
	ws = player->query("war_score");
	if( !str || str=="" ) return 0;
	if( !env ) return 0;
	if( str == "all" ) {
		if( player->query("wizard") ) {
			tell_object( player,"巫師不可以在這裡丟東西喔!!\n" );
			return 1;
		}		
		if( !pointerp(inv) && sizeof(inv)<1 )
			return notify_fail( 
				"你身上沒有任何東西可丟。\n");
		for( i=0; i<sizeof(inv); i++ ) {
			if( !inv[i] || inv[i]->query("prevent_drop") ||
				inv[i]->query("secure") ) continue;
			short = (string)inv[i]->query("short");
			if( !(unit = inv[i]->query("unit")) ) unit = "個";
			if( !short ) short = "某物";
			if( (WC = inv[i]->query("weapon_class")) >= 40 ) {
				bonus = WC/10;
				if( !inv[i]->query("knight_guild") ) {
					write("其他人會感謝你慷慨的捐獻的。\n");
					inv[i]->set("knight_guild",1);
					write( "你丟下一"+unit+short+"。\n");
					tell_room( env,c_name+"丟下一"+unit+short+"。\n",player );
					inv[i]->delete( "on_mounted" );
					inv[i]->move( env );
					player->add("war_score",bonus);
					continue;
					}
				if( !ws || ws < 1999 ) {
					value = inv[i]->query( "value" );
					number = value[0];
					type = value[1];
					write("你果然是守信用的人，這是你的押金，退還給你。\n");
					write( "你丟下一"+unit+short+"。\n");
					tell_room( env,c_name+"丟下一"+unit+short+"。\n",player );
					inv[i]->delete( "on_mounted" );
					inv[i]->move( env );
					player->credit( type,number );
					continue;
					}
				write("你果然是守信用的人。\n");
				write( "你丟下一"+unit+short+"。\n");
				tell_room( env,c_name+"丟下一"+unit+short+"。\n",player );
				inv[i]->delete( "on_mounted" );
				inv[i]->move( env );
				player->add("war_score",bonus);
				continue;
				}
			write( "你丟下一"+unit+short+"。\n");
			tell_room( env,c_name+"丟下一"+unit+short+"。\n",player );
			inv[i]->delete( "on_mounted" );
			inv[i]->move( env );
			continue;
			}
		write( "你將身上所有能丟的東西丟下。\n");
		return 1;
		}
	if( !item=present(str,player) ) return 0;
	if( item->query("prevent_drop") || item->query("secure") ) {
		write( "你沒有辦法將它丟掉!!\n" );
		return 1;
	}
	if( (WC = item->query("weapon_class")) >=40 ) {
		bonus = WC/10;
		if( !item->query("knight_guild") ) {
			tell_object(player,"其他人會感謝你慷慨的捐獻的。\n");
			player->add("war_score",bonus);
			item->set("knight_guild",1);
			item->delete( "on_mounted" );
			return 0;
			}
		if( !ws || ws < 1999 ) {
			value = item->query("value");
			number = value[0];
			type = value[1];
			tell_object(player,"你果然是守信用的人，這是你的押金，退還給你。\n");
			item->delete( "on_mounted" );
			player->credit( type,number );
			return 0;
			}
		tell_object(player,"你果然是守信用的人。\n");
		item->delete( "on_mounted" );
		player->add("war_score",bonus);
		return 0;
	}
}
