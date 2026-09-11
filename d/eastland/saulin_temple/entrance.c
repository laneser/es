#include "saulin_temple.h"
#define SLAB_FILE "/d/eastland/data/brassman.txt"

inherit ROOM;

void create()
{
        ::create();
        set_short( "銅人陣入口" );
        set_long(
@C_LONG
你現在來到了少林寺聞名天下的銅人陣前，這兒是少林寺為了測驗門下弟
子是否具備了足夠的能力去除妖辟邪、主持正義，而設置的試煉。能夠通過這
兒考驗的少林弟子都是其同儕中的佼佼者，出外則代表少林寺，因此少林寺眾
弟子莫不視能通過銅人陣為最大的榮耀。當然也有些弟子因為六根不淨而想還
俗，此時少林的長老們就會以通過銅人陣與否，來決定其是否可以還俗。你看
到旁邊立了塊石碑(slab)，上面有些字。
C_LONG
        );
 	set_outside("eastland");
 	set( "enter", 0);
        set( "exits", ([
        	"east" : SAULIN"stone_path3",
                "south" : SAULIN"grass2",
                "west" : SAULIN"grass0"
        ]) );
        set( "item_desc", ([
        	"slab" : "@@read_slab" ]) );
        set( "objects", ([
        	"elder#1" : "/d/eastland/saulin_temple/brass/obj/elder" ]) );
}

void init() 
{
	add_action("do_answer", "answer");
}

int do_answer(string str)
{
	object obj;
	obj = this_player();
	
	if( !str || str == "" ) return 0;
	if( !obj->query_temp("brassman") ) return 0;
	
	if( str == "yes" ) {
		if( this_object()->query("enter") ) {
			tell_object(obj,
				"慧元大師唱了聲佛號，說道：已經有人進入銅人陣了。\n" );
			return 1; };
		if( (int)obj->query("monk_score") < 3600 ) {
			tell_object(obj,
				"慧元大師說道：你對少林寺的貢獻不夠，不得進入。\n" );
			return 1; };
	 	if( (string)obj->query("class") != "monk" ) {
			tell_object(obj,
				"慧元大師唱了聲佛號，說道：少林重地，施主請留步。\n" );
			return 1; };
		if( (int)obj->query_level() < 14 ) {
			tell_object(obj,
				"慧元大師唱了聲佛號，說道：你能力不足，還是不要輕易冒險吧。\n" );
			return 1; };
		if( (int)obj->query("18brass") ) {
			tell_object(obj,
				"慧元大師說道：你已通過考驗了。\n" );
			return 1; };
		tell_object(obj,
			"慧元大師說道：阿彌陀佛。銅人陣過關不易，若是你覺得體力不支的話\n"
			"	      ，以擊壁(knock wall)為號，自然有人會救你出來，千\n"
			"	      萬不要逞強。請先準備一下吧 !!\n" );
		obj->set_temp("block_command",1);
		call_out("enter_brass",4,this_player());
		return 1;
		}
	else return 0;
}

int enter_brass(object who) 
{
	tell_object(who,
			"慧元大師打開了一道暗門，將你送了進去。\n" );
	who->delete_temp("block_command");
	who->move_player(SAULIN"brass/zeng1","SNEAK");
	this_object()->set("enter",1); 
	return 1;}

int clean_up() { return 0; }

string read_slab()
{
	this_player()->more(SLAB_FILE);
	return "\n";
}
