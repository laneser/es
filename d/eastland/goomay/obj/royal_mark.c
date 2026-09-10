#include <../goomay.h>

inherit OBJECT;

void create()
{
	seteuid( getuid() );
	set_name( "royal mark", "御賜金牌" );
	add( "id", ({ "mark" }) );
	set_short( "御賜金牌" );
	set_long(
		"這是一面御賜金牌，有了它，你就有了相當於當今皇上的權力。必要時你\n"
		 "可以把它亮(show)出來嚇嚇人 !\n"
	);
	set( "unit", "面" );
	set( "weight", 5 );
	set( "value", ({ 100, "silver" }) );
	set( "no_sale", 1 );
}

void init()
{
        add_action( "show_me", "show");
}

int show_me(string arg)
{
	string who,item;
	object target,ob;

        if( !arg || arg=="" || sscanf( arg, "%s to %s", item,who)!=2 )
                return notify_fail("你要亮(show)什麼給(to)誰看啊？\n");

	if (item != "mark")
                return notify_fail("這東西有什麼好現的？愛現 !!\n");

	if (!target=present(who,environment(this_player()))) 
		return notify_fail("這裡沒有這個人 !!\n" );
	
	if ( (string)target->query("name") == "Hsin the scribe" ) 
	{
		if ( !target->query("show") ) {
                tell_object( this_player(), @SHOW
邢師爺叫道：「原來是欽差大臣駕到，小的這就去通知史大人出來迎接。
請大人稍候 !! 來人啊 ... 有請大人」他急急忙忙的命人傳訊。


不久，後堂轉出一個身穿官服的人，對你長揖道：「古梅縣令史耀前躬迎
欽差大人，不知大人枉駕有何見教」
SHOW
		);
		new(Mob"migastrate" )->move(environment(environment()) );
			  target->set("show",1);
			  return 1;
			  }
		
	}
        else if ( (string)target->query("name") == "Captain of Policeman")
        {
		if ( !target->query("show")) {
                tell_object(this_player(), 
                "段捕頭叫道：「原來是欽差大臣駕到，大人要查監嗎？唉 ... 這個 ...。\n"
		"這個是監牢的鑰匙，請大人離去之前務必記得交還下官 !! 」。\n"
		"段飛鷹給你一把鐵鑰匙。\n");

		ob=new( Obj"key1" );
		ob->move( environment(this_object()) );
		target->set("show",1);
		return 1;
		}
	}
		tell_object( target ,this_player()->query("c_name")+"拿出一塊東西在你面前亂晃。\n");
                tell_object( this_player(), 
                target->query("c_name")+"道：「好大一塊金子啊 !! 值不少錢喔 !! 」\n");
                return 1;
}
