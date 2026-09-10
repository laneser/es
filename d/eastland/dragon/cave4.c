
#include "../layuter.h"

inherit ROOM;

void create()
{
	::create();
	set_short("龍穴");
	set_long( @C_LONG_DESCRIPTION
當你進入此洞穴時你發現此處是一個火山熔洞，四周都是奇怪的火紅色岩石，並且
有時有一些奇怪的岩石結晶，當其被火光映照之時，會反射出絢麗的光線，加上原有的
火紅構成一副優美的景色，令你幾乎忘了身在何處。此處的角落有一石碑(stele)。
C_LONG_DESCRIPTION
	);
	set("item_desc",([
	   "stele" : @STELE
	   此處是龍人族的禁地，如有違令進入者，格殺勿論 !!!!
STELE
 ]));
    set("objects",([
       "guard":Ldmonster"guard"]));
	set( "light", 0 );
	set( "exits", ([
	    "west" : Lcave"cave20",
		"southeast" : Lcave"cave3"
	]) );
	set("pre_exit_func",([
	     "west" : "exits_open"]));

	reset();
}

int exits_open()
{
  if (present("guard",this_object() )){
       write ("龍人守衛擋住你並且說道：前方是禁地你不能進入\n");
       return 1;
       }
   else return 0;
 }     
