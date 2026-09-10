#include </u/t/takeda/takeda.h>
inherit ARMOR;

void init()
{
object holder;
string name;

 holder = environment(this_object());
 name=(string)holder->query("name");
 if (name!="mercury") {
 this_object()->remove();
                    }


add_action("cure","makeup");
}

int cure(string arg)
{
	object dest,owner;
	
	owner = environment();
	if( !arg || arg=="" )
		return notify_fail("Usage: makeup <someone>\n");
	if( !dest= present(arg, environment(this_player()) ) )
		return notify_fail("That is not here!\n");
	if( !living(dest) )
		return notify_fail("Only living things can be healed!\n");
	tell_room(environment(this_player()),"\n\n " +owner->query("c_cap_name")+"拿起筆在你的臉上塗來塗去．\n\n");
	tell_room(environment(this_player()),"\n 此時你注意到四周的空間開始聚集了大量的水霧，這不是傳說中水星的神秘力量嗎？？ \n");
	tell_room(environment(this_player()),"\n 突然間，水星之筆散發出了水霧包圍了"+dest->query("c_cap_name")+".....\n");
        tell_room(environment(this_player()),"\n 當所有的水霧慢慢的消失之後，"+dest->query("c_cap_name")+"發現他已經恢復到最佳狀況．\n");
	dest->set("hit_points", (int)dest->query("max_hp"));
	dest->set("spell_points", (int)dest->query("max_sp"));
	dest->set("talk_points", (int)dest->query("max_tp"));
	dest->set("force_points", (int)dest->query("max_fp"));	
	dest->set("endurance_points", (int)dest->query("max_ep"));
	write("Ok.\n");
	return 1;
}


void create()
{
        set_name( "mercury pen", "水星之筆" );
        add( "id", ({ "pen" }) );
        set_short( "mercury pen", "水星之筆" );
        set_long(
        "This a pen of mercury!\n",
	"這是一隻水星之筆擁有治癒傷口的力量．\n"
	);
        set("no_sell",1);
        set( "type", "shield" );
        set( "prevent_drop",1);
        set( "armor_class", 80 );
        set( "defense_bonus",20 );
        set( "extra_stat",(["con":1970]));
        set( "weight", 1 );
}
int query_auto_load() { return 1; }
