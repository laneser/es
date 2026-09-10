#include <mudlib.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level( 9 );
        set_name( "Hsin the scribe", "邢師爺" );
        add( "id", ({ "scribe","hsin" }) );
        set_short( "邢師爺" );
        set_long(
@LONG
邢師爺留了兩撇稀稀疏疏的小鬍子，穿著一身青衫，他本來是一位私塾老師
由於他對於衙門的一切文書往來十分內行，因此被現任縣太爺(magistrate)
重用，他是一個好好先生，只要不是什麼殺人放火的大罪，到了他手上總會
有機會翻身，他是一個值得託付的人。
LONG
        );
        set( "gender", "male" );
	set("race","elf");
	set( "alignment",600);
        set_natural_armor( 40, 10 );
        set_natural_weapon( 13, 9, 16 );
        set_perm_stat( "str", 15 );
        set_perm_stat( "int", 20 );
        set_perm_stat( "dex", 15 );
        set_skill( "dodge", 100 );
        set_skill( "parry", 100 );
        set_skill( "target",80);
        set_skill( "concentrate",80);
        set_skill( "elemental",80);

        set( "tactic_func", "my_tactic" );
        set( "spells/sleet",2);
        set("spell_power",0);

	set( "defense_type","parry");
        set( "hit_points", 250 );
        set( "max_hp", 250 );
	set( "wealth/gold",10);
		set("spell_levels/elemental",15);
        set( "special_defense", ([ "all": 20 ]) );
        set( "inquiry", ([
                "statue"  : "@@ask_statue",
		"magistrate" : "@@ask_magistrate",
        ]) );

}
int my_tactic()
{
        object victim;
        if( random(20)>6 || !(victim= query_attacker()) ) return 0;
        if( this_object()->query_temp("cast_busy") )
                return 0;
        if( (int)this_player()->query("spell_points") < 60 )
                set( "spell_points",query("max_mp"));
        command("cast sleet at "+(string)victim->query("name"));
}

int ask_magistrate()
{
        object me ;
        me=this_player();
        if ( (int)me->query_quest_level("Goddess_statue")> 2)
        {
        tell_object(me,
        "邢師爺道：「謝謝您救了縣太爺一命，他現在已經好多了 !!」\n");
        return 1;
	}
        else
        {
        tell_object(me,@C_MAGI
邢師爺道：「縣太爺公務繁忙，沒有時間見外人，如果沒有公務上的需要，他是
不會見你的，有事就由我為你轉達吧 !!」
C_MAGI
        );
                return 1;
}
}
int ask_statue()
{
        object me ;
        me=this_player();
        if ( (int)me->query_quest_level("Goddess_statue")>2)
        {
	tell_object(me,
	"邢師爺道：「月神像不是已經找回來了嗎？不過還是謝謝您救太爺一命 !!」\n");
	return 1;
	}
        else
        {
        tell_object(me,@C_STATUE
邢師爺道：「嗯 !! 這個嘛 !! 說來話長 ～～ 本來我們已經抓到那個江洋大盜了
不料他狡猾成性，死也不肯把贓物交出來，段捕頭用了幾次刑他就裝死裝昏的，後
來太爺只好把他還押候審，不料他居然趁獄卒不備，夥同一個死囚偷偷挖地道逃了
，現在我們正傾全力追捕他們。所以呢 !! 那個月神像就 .. 還要再等一段時間嘍」
C_STATUE
        );
                return 1;
}
}
