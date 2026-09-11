#include "almuhara.h"
#define MAX_DRAGON 4
inherit DOORS;
inherit ROOM;
void create()
{
	::create();
	set_short("地下石門");
	set_long( @LONG_DESCRIPTION
你現在來到一個寬闊的石室，這兒似乎是地道的終點。牆壁上散出一股柔柔的光芒，
映著室內的景物，氣氛顯得格外詭異。在你面前是一扇巨大的石門，石門上兩隻栩栩如
生的巨龍彷佛要破壁而出，猙獰的面目令你不寒而慄。在盤踞的雙龍口中似乎有一個小
洞(hole)，你情不自禁地想走上前看個清楚。
LONG_DESCRIPTION
	);
        set( "light",1 );
        set( "mob_num",0 );
	set( "exits", ([ 
		"north" : TOMB"/inner1",
		"up" : TOMB"/down3"
		]));
	create_door( "north","south",
		   (["keyword" : ({"door", "stone"}),
			"name"    : "stone door",
			"c_name"  : "大石門",
			"c_desc"  : "一扇超大的石門，門後不知道有什麼玄機...",
			"lock"    : "TOMBKEY_1",
			"status"  : "locked",
		     ]) );
	add( "c_item_desc", ([
	      	"hole" :@C_ITEM_DESC_1
在你小心翼翼地清除了洞周圍的灰塵、雜物後，發現這是個渾圓的小凹槽，好像
可以放(put)什麼圓圓的小東西。嗯 !! 凹槽上方還刻著一行字(writings)。
C_ITEM_DESC_1
,		"writings" :@C_ITEM_DESC_2
『 先皇陵寢 ， 擅入者死 ！！』 哇，難道這裡就是傳說中東方皇帝的陵墓 ？！
C_ITEM_DESC_2
	   ]));
	   set( "pre_exit_func", ([
	   	"north" : "loop_exit" ]) );
           reset();
}

void init()
{
	add_action( "do_place", "put" );
}

int do_place (string str)
{
	object player,ob;
	string orb;
	int i;
    
    	player = this_player();
    
	if ( !str || str!="orb into hole")
		return 0;

	ob = present( "golden dragon orb" , player);
	if(!ob) {
		tell_object(player,"你身上沒有適合的東西。\n");
		return 1;
	}

 	tell_object( player, 
		    "\n你把金龍珠放進小洞裡。\n"
		    "\n突然傳來一聲巨響，大石門緩緩地打開了\n");
	tell_room( environment(player), 
		player->query("c_cap_name") + "把一顆小東西放進洞裡。\n" 
		"\n突然傳來一聲巨響，大石門緩緩地打開了\n",
		player );
        set_status("north","open");
        update_link("north");		
 	player->set_temp("DRAGON_ORB",1);			
       	ob->remove();
       	return 1;
}

int loop_exit()
{
	object player;
	
	player = this_player();
	if ( !present("golden dragon",this_object())) {	
        if ( query("mob_num") < MAX_DRAGON ) {
		
                if ( !player->query_temp("DRAGON_ORB") ) {
                tell_room( this_object(),
                "\n石門上兩隻巨龍突然眼睛一亮，張牙舞爪地向你飛了過來！！\n"
                         );
                new(MOB"/dragon")->move(this_object());
                new(MOB"/dragon")->move(this_object());
		this_object()->add("mob_num",2);
                return 1;
		}
                else    return 0;
	}
	}
	if ( !player->query("player_invisible") && present( "dragon", this_object() ) ) {
		write("金龍盤旋在北方，使你無法進入。\n" );
		tell_room( this_object(), 
			sprintf("%s想往北走，卻被金龍擋住！\n", player->query("c_cap_name"))
		, player);
		return 1;
	}
	return 0;	 	
}	
