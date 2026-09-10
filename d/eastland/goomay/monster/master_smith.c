
#include "/d/eastland/goomay/goomay.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(18);
        set_name( "Master of blacksmith", "劍廬主人－段鐵" );
        add ("id",({ "blacksmith","master"}));
        set_short( "劍廬主人－段鐵");
        set("unit","位");
        set_long(
@C_LONG
他就是有當今天下第一鑄劍師的劍廬主人段鐵，段家鑄劍已經有幾百年的歷
史了，其中段鐵是最傑出的，傳說他除了冶煉金屬的本事一流以外，還擁有
將魔法注入武器中的能力，所以他親手鍛造的武器可以發出超越一般武器的
可怕威力。不過，他近年來已經很少親自動手了，而專心於弟子的訓練，所
以劍廬的鍛造技術仍然冠絕當世。
C_LONG
);
        set ("gender", "male");
        set ("race", "dwarf");
        set_natural_armor( 90, 20 );
	set_natural_weapon(25,5,15 );
        set_perm_stat( "str", 30 );
        set_perm_stat( "kar", 25 );
        set_perm_stat( "int", 25 );
        set_perm_stat( "dex", 30 );
        set_skill( "longblade", 100 );
        set_skill( "parry", 100 );
	set("hit_points",1200);
	set("max_hp",1200);
        set( "special_defense", ([ "all": 40 ]) );
	set( "wealth/gold",100);
        wield_weapon( Obj"love_sword" );
        equip_armor( Obj"lovekey" );
        set( "inquiry", ([
                "fire"  : "@@ask_fire",
		"weapon" : "@@ask_weapon",
		"key" : "@@ask_key", 
        ]) );

}
int ask_key()
{
   tell_object(this_player(),
@ASK_KEY
段鐵說道：有個鎖住的門啊！嗯．．讓我想想．．．．．．．．．．
我知道我的族人中有人一直保存著一塊先祖所鑄的封印，也許對你會
有幫助，你可以到礦坑裡面去問問看，他應該還在裡邊做監工！
ASK_KEY
);
}
int ask_weapon()
{
        object me ;
        me=this_player();
        if( (int)this_player()->query_quest_level("Goddess_statue") > 1 ){
                tell_object(me,
                "段鐵笑道：「恩人 !! 段鐵願意隨時為你效勞，但是你要給我適當的材料啊 !!」\n"
			    );
                return 1;
	}
        else
        {
                tell_object(me,
                "段鐵嘆道：「我哪有這心情啊？爐子沒火啊 !!」\n");
		return 1;
	}
}

int receive_metal()
{
   object ob;
 if (this_player()->query_temp("get_magnetite")){
      tell_object(this_player(),
@METAL
段鐵拿起磁鐵礦看了看道：嗯！這的確是我們家中珍貴的魔法磁鐵礦，想
不到竟然可以重回到我們手裡，真是太感謝你了，我拿出一些做成武器來
答謝你吧！
  說完，段鐵便轉身回到火爐邊開始工作
METAL
);
   call_out("make_weapon",3,this_player());
}else{
	tell_object(this_player(),
@NOGET
段鐵看了看你之後說：你又不是打死巨人的英雄，不過還是謝謝你把磁鐵
礦送回來．
NOGET
);
}
}
int receive_cloth()
{
        object ob ;
	tell_object(this_player(),
@CLOTH
段鐵訝異地接過破布片，然後仔細地讀了起來，他嘆了一口氣道：「原來
如此 !! 難怪有不準移動爐子的祖訓，我還以為只是迷信而已，看來現在
正是火妖轉形的時刻了，請你務必幫我這個忙，你可以把爐子(furnace)
移開看看 ..
CLOTH
	);
}

int ask_fire()
{
	object me ;
	me=this_player();
        if( (int)this_player()->query_quest_level("Goddess_statue") > 1 ){
		tell_object(me,
		"段鐵笑道：「多謝恩人的關心 !! 現在的爐火很正常」。\n");
		return 1;
	}
	else
	{
                tell_object(me,
@FIRE
段鐵嘆道：「唉 !! 沒想到這種事居然發生在我身上，我一直以為它只是個
傳說，現在真叫我給碰上了，我的爐子最近出了問題，爐火怎麼也升不起來
，古老的傳說說這是火妖作祟，如果取得火妖身上的火之精就可以使爐火重
燃，可是我上哪兒去找火妖呢？還有一大批訂單要趕，唉 !! 看來劍廬的信
譽要掃地了。
FIRE
			    );
	return 1;
	}
}
int fix_symbol(object me)
{
	object ob;
	tell_object(me,"段鐵站了起來，拿著一面金光閃閃的東西，滿臉滿意的笑容。\n");
	ob = new(Obj"royal_mark");
	ob->move(this_object());
	command("give mark to "+me->query("name"));
	command("smile "+me->query("name"));
	return 1;
}
int make_weapon(object hero)
{
        object ob;
        tell_object(hero,"段鐵站了起來，拿著一把通體銀白的匕首，向你走了過來．\n");
        ob = new("/d/eastland/goomay_mine/obj/dagger");
	ob->move(this_object());
	ob->set("master",hero->query("name"));
	command("give dagger to "+hero->query("name"));
	command("smile "+hero->query("name"));
	return 1;
}
int accept_item(object me,object item)
{
	string name;

	name = (string) item->query("name") ;
	
	if ( name !="fire element" && name !="broken cloth" 
		&& name !="broken symbol"  ||
	 (int)this_player()->query_quest_level("Goddess_statue") > 2 ) {
	   if (name== "magic magnetite"){
	   item->remove();
   receive_metal();
	   return 1;
	       }
        tell_object(me,
	"段鐵搖搖頭：「謝謝 !! 我不需要這東西 !!」\n");

        command("give "+(string)item->query("name")+" to "+lower_case((string)me->query("name")));
        return 1;
	}
	if ( name=="broken cloth")
	{
	item->remove();
	receive_cloth();
	return 1;
	}
	if ( name == "broken symbol" ) {
	 if ((int)this_player()->query_quest_level("Goddess_statue") != 2 ) {
		tell_object(me,
			    "段鐵搖搖頭：「謝謝 !! 我不需要這東西 !!」\n");
		command("give "+(string)item->query("name")+" to "+lower_case((string)me->query("name")));
		return 1;
	 }
		item->remove();

		tell_object(me,@SYMBOL
段鐵把金塊翻來覆去的看，不斷的喃喃自語，然後轉過身去在一張小桌子
前面坐下來，開始專心的工作。
SYMBOL
		);
		call_out("fix_symbol",5,me);
		return 1;
	}
       if ((int)this_player()->query_quest_level("Goddess_statue") != 1 ) {
     tell_object(me,
        "段鐵搖搖頭：「謝謝 !! 我不需要這東西 !!」\n");

        command("give element to "+(string)me->query("name"));
        return 1;
	  }

     tell_object(me,
@MISSION
段鐵高興的抱住你大笑道：「謝謝你 !! 你真是我段家的恩人，劍廬又可以
繼續工作了，今後有什麼需要我段鐵的地方，請你儘管吩咐 !!」
段鐵又道：「我的這位旅行武鬥家朋友，他精通空手搏擊的技巧，你可以去
試試運氣」
他將火之精放入爐中，瞬時爐火轉青，所有的鐵匠都大聲歡呼，開始努力工
作，一時之間，打鐵的叮噹聲又響成一片。

MISSION
		);
	tell_object(me,set_color(
			"你感染了鐵匠們的快樂，覺得精神為之一爽 ! [你得到 3000 點經驗]\n","HIY")
		    );
                item->remove();
	me->finish_quest("Goddess_statue",2);
	me->gain_experience( 3000 );

        return 1;
}
