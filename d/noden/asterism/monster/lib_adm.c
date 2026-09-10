#include "../asterism.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "Andromeda", "安杜露美妲" );
	add("id",({"administrater","halfling","andromeda"}) );
   set_short( "圖書館館長安杜露美妲" );
	set_long(
		"天下居然有這麼美麗的絕世美女 !! 雖然她的身裁小了一號,\n"
                "但是卻是你曾見過的女子中最美的。就在你瞠瞠地望著她時,\n"
                "她突然抬頭看了看你,對你笑了笑。\n"
	);
	set( "gender", "female" );
	set( "race", "halfling" );
	set( "alignment", 450 );
	set( "time_to_heal", 7 );
	set_natural_armor( 56, 12 );
	set_natural_weapon( 17 , 5 , 8 );
	set("max_hp",350);
	set("hit_points",350);
        set("inquiry",([         
                         "優波羅花": "@@quest1a",
                      ]) ) ;

	set_perm_stat( "kar", 24 );
	set( "wealth/gold", 30 );
	set( "special_defense", ([ "all": 12 ]) );


}

void quest1a(object who)
{
   int a,b ;
   string cmsg,msg ;
     
   a = this_player()->query("astr/questa");
   b = this_player()->query_temp("astr/quest1");
      
   if(!a || !b || b < 3 )
      return notify_fail(can_read_chinese()?
             "你在說什麼 ?? 我一句都聽不懂。\n" :
             ""  ) ;
   

        who->set_temp("astr/quest1",41);  
        cmsg =
            "安杜露美妲用銀鈴般的聲音說道 :\n"
            "      我記得館藏的藏書中有一本關於罕見花卉的,\n"
            "      你去找找看,也許會有些幫助。\n" ;
        msg  = "" ;
            
   write(can_read_chinese()?
           cmsg : msg );
   return ;
}


