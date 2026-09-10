#include <mudlib.h>
#include "../hawk.h"
inherit MONSTER;

// 這隻算是半完成品吧 ..... 如果 QC 時特攻還有問題就先把特攻關掉

void create ()
{
        object obj1,obj2,obj3,obj4;
        ::create();
        set_level(19);
        set_name("Hawkman Chief Flamen","鳥人族總祭司");
        add("id",({"","hawkman","flamen"}) );
        set_short("鳥人族總祭司");
        set_long(@C_LONG
你看到一個白髮蒼蒼的鳥人，身上的羽毛都已經脫落了，但是依然神采亦
亦的站在大廳，看來他一定會長命百歲的。他主管著左右兩扇門(door)後的
祭壇。他發現了你正看著他，於是轉過頭對你和藹的笑了一下。
C_LONG
        );
        set( "gender", "male" );
        set( "race", "hawkman");
        set( "unit", "位" );
        set("inquiry",([
              "square":"@@ask_square",
                "door":"@@ask_door",
	"destroy":"@@ask_destroy",
                        ]) );
        set( "alignment",-800);
        set_perm_stat( "dex", 15 );
        set_perm_stat( "str", 15 );
        set_perm_stat( "int", 27 );
        set_skill( "dodge" , 100 );
        set_skill( "unarmed" , 50 );
        set ("max_hp", 1000 );
        set ("hit_points", 1000 );
        set_natural_weapon( 53 , 28 , 45 );
        set_natural_armor( 10 , 20 );
        set( "aim_difficulty",
                ([ "critical":40,"weakest":70,"ganglion":30,"vascular":50 ]) );
        set ("special_defense",([
                "monk": 20, "scholar": 20, "evil": 80,
                "divine": -20, "all": 30]) );
        set( "tactic_func","my_tactic");
        equip_armor(ARMOR"magerobe.c");
        equip_armor(ARMOR"star_arm.c");
        obj1 = new(OBJ"square_obj");
        obj2 = new(OBJ"square_obj");
        obj3 = new(OBJ"square_obj");
        obj4 = new(OBJ"square_obj");
        obj1->move(this_object() );
        obj2->move(this_object() );
        obj3->move(this_object() );
        obj4->move(this_object() );

}


int ask_door()
{
        tell_object(this_player(),@LONG
鳥人族總祭司對你親切的笑了一笑，說：
    左右兩扇門都可以通到武鬥場(square)，不過善良的與邪惡的卻有不一
樣的路，想想你一路走來，你所走的路正指引著你該往哪走....不過，邪惡
的人啊，請往黑暗的路走吧。
LONG
        );

        return 1;
}

int ask_square()
{
        tell_object(this_player(),@LONG
總祭師說：
    武鬥場是我們鳥人族的比武的地方，不過最近多了一些邪惡的怪物盤踞在
裡面，如果有人肯進去幫我們消滅(destroy)那些怪物的話，那該有多好。
LONG
        );
        return 1;
}

int ask_destroy()
{
        if (!present("amulet",this_object() ))
        {
                tell_object(this_player(),@LONG
鳥人祭師說道:
嗯....今天已經太多人跟我說要幫忙了，可是因為競技場是由神聖的結界所支
撐的，沒辦法讓太多人進去，你還是等下次吧。
LONG
                );
                return 1;
        }

        tell_object(this_player(),@LONG
鳥人祭師說道:
哦，你願意幫助我們嗎? 送你這個護身符, 可以當做武鬥場的入場證明
LONG
        );
        command("give amulet to "+(string)this_player()->query("name") );
        return 1;
}


int my_tactic()
{
        object victim,tape;
        string name;
        int dex,choice;
        if (!victim = query_attacker()) return 0;
        name =(string)victim->query("c_name");
        dex = victim->query_perm_stat("dex");
        if( !victim ) return 0;
        choice = random(4);
        switch(choice)
        {
                case 0 : return 0;
                         break;

                case 1 :
                if ( random(dex) > 15 ) return 0;
                if ( victim->query_temp("no_hearing") ) return 0;
                tell_room(environment(victim),"\n老祭司伸出雙手，飛快的在"+
                        name + "的雙耳輕拍一下。\n",victim);
                tell_object(victim,@C_LONG
老祭司伸出雙手，在你的雙耳上輕拍了一下，你頓時感到雙耳一陣劇痛。
............
[你聾了。]
C_LONG
                );
                victim->set_temp("no_hearing",1);
                victim->receive_special_damage("none",30);
                victim->set_temp("block_message",1);
                return 1;
                break;

                case 2 :
                if ( random(dex) > 12 ) return 0;
                if ( victim->query_temp("no_sight") ) return 0;
                tell_room(environment(victim),
                        "\n老祭司伸出右手虛晃一招，忽然用左手"
                        + "的食中二指往"+ name + "的雙眼插去，只見"+ name
                        + "痛得在地上滾來滾去。\n",victim);

// 如果耳朵已經聾了就看不到下面的 message .... 不知道怎麼辦ㄌㄟ ....

                tell_object(victim,@LONG
老祭司伸出右手虛晃一招，忽然左手飛快的往你臉上招呼，食中二指正中
你的雙眼。你雙眼一陣巨痛，恐怕是凶多吉少。
[ 你瞎了。]
LONG
                );
                victim->set_temp("no_sight",1);
                victim->receive_damage(15);
                victim->set("blind",1);
                return 1;
                break;

                case 3 :
                if ( victim->query_temp("no_sound") ) return 0;
                if ( random(dex) > 12 ) return 0;
                tell_room(environment(victim),
                        "\n老祭司身形飄渺, 忽然一記重拳直擊在"
                        + name + "的喉嚨，只見" + name
                        +"臉色大變。\n",victim);

                tell_object(victim,@LONG
老祭司一記重拳正中你的喉嚨，你只覺得他似乎微微捏了你的喉頭一下，
接著就發現你一個字都講不出來了~~~~~

[ 你啞了。]
LONG

                );

                victim->receive_damage(30);
                victim->set_temp("no_sound",1);
                tape=new(OBJ"tape");
                tape->move(victim);
                return 1;
                break;

                }
        return 1;
}
