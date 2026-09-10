inherit MONSTER;
int will_die = 0;
#include "../hawk.h"
void create()
{
        ::create();
        set_level(19);
        set_name( "Hawkman Leader Adolph", "鳥人領袖 阿道夫" );
        add ("id", ({ "adolph","leader","hawkman"}) );
        set_short( "鳥人領袖 阿道夫" );
        set_long(@C_LONG
阿道夫是現任鳥人族的領袖，武藝雖比不上哥哥維多(Vito)，但也是相當
不俗。身上所穿的天空系列裝備，是天空之城世代相傳的神聖裝備，只有鳥人
族的領袖有資格擁有它。擁有了天空之城神聖之力的保護阿道夫可說是不死之
身，想用平常的方法打敗他是不可能的，只要他的心中沒有恐懼之心，神聖之
力的保護就是沒有破綻的。
C_LONG
        );
        set( "race", "hawkman" );
        set( "gender", "male" );
	set( "alignment", -2000);
        set_perm_stat( "str", 30 );
        set_perm_stat( "dex", 18 );
        set_perm_stat( "kar", 10 );
        set_perm_stat( "pie", 17 );
        wield_weapon(WEAPON"skysword.c");
        equip_armor(ARMOR"samulet.c");
        //equip_armor(ARMOR"shelmet.c");
        equip_armor(ARMOR"splate.c");
        //equip_armor(ARMOR"slegs.c");
        equip_armor(ARMOR"sshield.c");
        //equip_armor(ARMOR"sfoots.c");
        //equip_armor(ARMOR"sarms.c");
//	 equip_armor(ARMOR"sgloves.c");
        set("special_defense",
                (["all":50, "cold":70, "fire":65, "electric":0,
                        "evil":50, "none":70, ]));
        set("max_hp",900);
        set("hit_points",800);
        set( "inquiry", ([
                "vito" : "@@ask_vito",
                "juraken" : "@@ask_juraken",
                        ]) );
        set_skill( "dodge", 60 );
        set_skill( "parry", 80 );
        set_skill( "block", 80 );
	set_skill( "longblade", 100);
        set( "aim_difficulty",([ "weakest":50,"critical":100,"vascular":90,"ganglion":40
]) );
	set_natural_armor(40,20);
	set_natural_weapon( 15, 15, 36);
        set( "tactic_func","my_tactic");
        set( "wealth/silver", 800);
}

void init()
{
        object ob;
        npc::init();
        if( !(ob= this_player()) || !userp(ob) ) return;
        if( ob->query_temp("kill_me") )
        {
                kill_ob( ob );
        }
        if( ob->query_temp("control_flesh") == 2 )
        {
                command("scream");
                will_die = 1;
        }
}

int ask_vito()
{
        tell_object(this_player(),@LONG
阿道夫狂笑三聲，大聲叫道：哈哈，你提那個死掉的人幹嘛，欺負我那麼久，
終於輪到我了吧！！
你覺得阿道夫好像有點瘋瘋癲癲，不知道為什麼對他自己的親哥哥也如此怨憤，不
禁搖搖頭。
LONG
        );
        return 1;
}

int ask_juraken()
{
        tell_object(this_player(),@LONG
阿道夫說道：呵呵，老裘是我的好朋友，幫了我很多的忙，上次塔姆姆族的
進攻也是靠他我們才贏的。有人抱怨說因為他的關係我們跟塔姆姆族也成了敵人
，那又有啥關係呢？幫助朋友是義不容辭的，不是嗎？
LONG
        );
        return 1;
}

void report(object holder, object victim )
{
   seteuid(getuid());
   tell_object( victim,
   sprintf("( 你%s )\n","/adm/daemons/statsd"->status_string(victim)));
}

int my_tactic()
{
        object victim;
        if (!victim = query_attacker()) return 0;
	if (random(100) > 13 ) return 0;
        tell_room(environment(victim),
"\n\n阿道夫喃喃自語，忽然手間聚集了一顆璀璨的光球，直擊在"+
(string)victim->query("c_name")+"的頭上。\n\n",victim
        );

        tell_object(victim,set_color(sprintf(
"阿道夫大喝一聲：『看我的乾坤六絕光彈。』\n突然手中的光球往你直"+
"擊了過來，一圈璀燦的光環籠罩在你身旁，明亮的光線\n讓你眼睛睜都"+
"睜不開。......你赫然發現自己雙眼都看不到東西了\n"),"HIY")
 );
        victim->receive_special_damage( "energy", random(15)+40 );
        report(victim,victim);
        victim->set("blind",1);
        return 1;
}

int die()
{
        if (will_die != 1)
        {
                object *ob,killer;
                int i;
                set( "exp_reward",300 );
                ob = all_inventory(this_object());

                for( i=0; i<sizeof(ob); i++ )
                        ob[i]->remove();


                tell_room( environment(this_object()),@LONG

天空守護徽章放出一道金光，阿道夫身上的傷又全部癒合了。

阿道夫狂笑道：「哇哈哈～～我是不死的～～～我是無敵的～～～。你們這些蝦兵
蟹將不要再丟人現眼了....」

阿道夫將裝備一一穿起之後又朝著敵人衝了過去。
LONG
                ,this_object() );
                killer = query("last_attacker");
                killer->set_temp("kill_me",1);
		set( "alt_corpse","/u/s/smore/mob/adolph.c");
                ::die(1);
                return 1;
        }

        tell_room( environment(this_object() ),@LONG

阿道夫長嘆一聲：「想不到這個世界上還有人可以擊敗我～～～～」
LONG
        ,this_object() );
        ::die(1);
        return 1;
}
