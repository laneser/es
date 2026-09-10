#include <mudlib.h>
inherit OBJECT;
void create()
{
        set_name("petals", "花瓣");
        set_short("petals", "花瓣");
        set_long(@LONG
This is a lot of petals . sprinkle it at somebody will bring fun.
LONG
, @CLONG
婚禮或慶點時用的花瓣，當它被撒(sprinkle)向空中時，將會形成一幅絕美的圖案。\n
CLONG
        );
        set("unit", "把");
        set( "weight", 0 );
        set ("value", ({ 10, "silver" }) );
        seteuid( getuid() );
}

void init()
{
        add_action("do_use","sprinkle");
}

int do_use(string arg)
{
        string cmsg, cmsg1, cmsg2;
        object target;

        if ( !arg || arg=="" )
	return  notify_fail( 
                "你想對誰撒花瓣 ？  uasge : sprinkle <who> \n" );

        target = present( arg , environment(this_player() )) ;
	if ( !target )
	return notify_fail( "這裡沒有這個人。\n" );

        if (target == this_player()) 
                {
                   write(
                        "你把花瓣撒向天空，霎時天空落下一陣花雨。\n" );
                  tell_room( environment(this_player()), 
			             target->query("c_name") +
                         "將一把花瓣撒向天空，霎時落下一陣繽紛花雨， 你覺得有點心醉。\n",
			  this_player() );  
                  remove() ;
                  return 1 ;       
                }
        else {
                cmsg = "你將花瓣向"+
                        target->query("c_name") +
                        "的身上一撒，霎時構成一幅人面桃花相映紅的圖案。\n";
                cmsg1 = this_player()->query("c_name")+
                        "將花瓣灑向"+
                        target->query("c_name") +
                        "的身上，霎時構成一幅人面桃花相映紅的圖案。\n";
                cmsg2 = this_player()->query("c_name")+
                        "將一把花瓣向你灑來，在繽紛的花瓣雨中，你覺得心醉了。\n";

                tell_object( this_player(), cmsg );
                tell_room( environment(this_player()), cmsg1 ,
                        ({ this_player(), target }) );
                tell_object( target, cmsg2 );

                remove();
                return 1;
        }
}
