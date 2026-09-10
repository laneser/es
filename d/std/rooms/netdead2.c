// The Netdead Room, clooect all users who are net-dead, 
// will clean up every 30 mins
// created by Kyoko, 5-11-1994.

#include <mudlib.h>

inherit ROOM;

string *where = ({ "/d/noden/12,3.noden","/d/noden/17,8.noden",
		"/d/noden/2,15.noden","/d/eastland/9,9.east",
		"/d/eastland/7,17.east","/d/deathland/city/c5"
		}) ;
void create()
{
	::create();
	set_short("時間的縫隙" );
	set_long(
		"你現在身處於時間的縫隙，舉目所及是燦爛炫目的七彩光芒，\n"
		"空間中矗立著無數的門(door)，據說可以通到世界各地。\n"
	);
	set("light", 1);
    set("c_item_desc",(["door":
	"這是一些泛著七彩光芒的門，你可以挑一扇進去(enter)看看。\n"
     ]));
}

void init() 
{
	add_action("do_enter","enter");
}

int do_enter(string arg)
{
	string move_to;
	int hp;
        if( !arg || arg!="door" )
            return notify_fail("進入哪裡？\n" );
	write("你挑了一扇門走進去，突然，腳下一個踩空....\n" );
	tell_room( this_object(),
            this_player()->query("c_name") + "走進一扇門裡，消失了...\n",
                this_player() );
	move_to = where[random(sizeof(where))];
	this_player()->move_player( move_to, "SNEAK" );
	write("你碰～的一聲跌在地上，摔得屁股痛死了 ...\n");
	this_player()->add("hit_points",-(int)this_player()->query("hit_points")/10);
	tell_object(this_player(),sprintf("( 你%s )\n",(string)"/adm/daemons/statsd"->status_string(this_player())));
	tell_room( move_to ,
            this_player()->query("c_name") + "咻～～的一聲掉了下來，摔得四腳朝天。\n",
                this_player() );
        return 1;
}

int receive_object(object arg)
{
	string msg ;
	object* all_inv;
	if(living(arg)) return 1 ;    
	if (base_name(arg)=="/std/statue") return 1;
	tell_room(environment(this_player()),
              arg->query("c_name")+"被一個黑洞吞噬，瞬間就消失了。\n");
	all_inv=all_inventory(arg);
	all_inv->remove();
	arg->remove();
	return 0;
}
