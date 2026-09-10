#include <../hole.h>

inherit ARMOR;
void create()
{
        set_name( "@@name","火麟戰甲" );
        add( "id", ({ "plate" }) );
        set_short( "@@short" );
        set_long(@LONG
	這是一件刀槍不入的盔甲，據說是當年邪神殺
	了火麒麟後用火麒麟身上的鱗片配合金蠶絲編
	成的。
LONG
        );
        set( "unit","件" );
        set( "type","body" );
        set( "material","knight" );
        set( "armor_class",25 );
        set( "special_defense",([ "evil":20,"cold":30 ]) );
        set( "weight",170 );
        set( "value",({ 220,"gold" }) );
        set( "no_sale",1 );
        set( "equip_func","equip_plate" );
        set( "unequip_func","unequip_plate" );        
}

string name(){ return set_color( "Fire Plate","HIR" ); }
string short(){ return set_color( "火麟戰甲","HIR" ); }

void equip_plate()
{
	string cla,him,bonus;
	object player,env;
	int AC;
	
	player=this_player();
	env=environment(player);
	AC = (int)player->query_level()*2+2;
	bonus=player->query( "knighthood" );
	him=player->query( "c_name" );
	cla=player->query( "class" );
	if( cla!="knight" ) {
		tell_object(player,"\n只有戰士才能發揮它的特殊效用。\n\n");
		tell_room(env,"\n\n忽然傳來一陣烤肉的香味，不知道是誰在烤肉。\n\n"
		"你循著香味看去....原來是"+him+"身上的毛髮和皮膚全被烤焦了。\n\n",player);
	}
	else{
		tell_room(env,"\n\n你看見"+him+"穿上「火麟戰甲」後，雙眼赤紅如火，\n"
		"全身散發出一股邪惡的氣息，彷佛死神降臨人世。\n\n",player);
		tell_object(player,"\n\n忽然一股無形的力量籠罩著你，你覺得身上下奇熱無比，\n"
		"彷佛有股力量要衝破你的身體。\n\n");
	        set( "armor_class",AC );
	        switch(bonus){
		 	case "baron":
		 		set( "defense_bonus",2 );
		 		return ;
		 		break;
		 	case "vicomte":
		 		set( "defense_bonus",4 );
		 		return ;
		 		break;
		 	case "earl":
		 		set( "defense_bonus",6 );
		 		return ;
		 		break;
		 	case "marquess":
		 		set( "defense_bonus",8 );
		 		return ;
		 		break;
		 	case "duke":
		 		set( "defense_bonus",10 );
		 		return ;
		 		break;
		}
         return ;
        }
        return ;
}

void unequip_plate()
{
	set( "armor_class",25 );
	delete( "defense_bonus" );
	return ;
}