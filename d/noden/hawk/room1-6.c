//room1-6.c
#include <mudlib.h>
#include <stats.h>
#include <conditions.h>
#include "mudlib.h"
#include "hawk.h"
inherit ROOM;
int moves;
void create()
{
        ::create();
        set_short("石板小徑");
        set_light(1);
        set_long( @LONG_DESCRIPTION
走到這裡，遠遠的你可以看到一座奇型怪狀的城，不過讓你覺得奇怪的是，
這座城似乎在緩緩的移動著。兩旁的森林(forest)被砍伐掉了許多，大概是拿去
作為建設城堡的原料吧。
    你注意路邊傳來一陣陣的水聲，不過你四處望望，還是搞不清楚這聲音
是從哪邊傳來的。
LONG_DESCRIPTION
        );
          set( "exits", ([
                  "southwest" : HAWK"room1-7",
                  "north" : HAWK"room1-5",
                  ]) );
        set("c_item_desc",([
                "forest":"@@to_forest",
                "fountain":"@@to_fountain"
                ]) );
        reset();
}//end of creat

void init()
{
        add_action("do_search","search");
        add_action("to_drink","drink");
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str=="southwest" || str=="north" )
                return 0;
        write("啊! 不好....\n\n");
        tell_room(environment(this_player()),
                "你看到有人失足了!\n",this_player());
        this_player()->receive_damage(70);
        this_player()->move_player(HAWK"room1-18","SNEAK");
        tell_room(environment(this_player()),
                "你看到"+(string)this_player()->query("c_name")+
                "從高聳的絕壁上摔下來!\n"+
                "竟然沒死! 真是命大啊!\n",this_player());
        return 1;
}

string to_forest()
{
        return "整個森林都被砍得光禿禿的，難道這些人都不懂得要水土保持嗎？？\n";
}

int to_drink(string s)
{
        if ((s == "fountain") || (s == "water"))
        {
                if (moves == 0)
                {
                        tell_object(this_player(),"What?\n");
                        return 1;
                }

                if (moves == 3)
                {
                        tell_object(this_player(),@LONG
水已經被喝光光了，你不禁開始咒罵哪個討厭鬼讓你沒水喝。
LONG
                        );
                        return 1;
                }  

                if ( ( this_player()->query_temp("touch_ball")==1) &&
                        (this_player()->query_temp("drink_water")==0) )
                {
                        tell_object(this_player(),
                        "你把嘴巴靠近這噴水池，努力的開始喝水池裡的水。\n");
                        this_player()->set_temp("drink_water",1);
                        (CONDITION_PREFIX + "simple_poison")->
                                apply_effect( this_player(),8, 10 );
                return 1;
                }
                if ( this_player()->query_temp("touch_ball") == 0)
                {
                        tell_object(this_player(),
                        "你喝了幾口，就覺得全身不大對勁，眼前一片金星亂冒，"+
                        "而且七孔流血。\n你感到一陣麻痺，一轉眼你已經倒在地上"+
                        "爬不起來了。\n");
                        (CONDITION_PREFIX + "simple_poison")->
                                apply_effect( this_player(),8, 10 );
                        (CONDITION_PREFIX + "slow")->
                                apply_effect( this_player(),8, 5 );
                        (CONDITION_PREFIX + "bleeding")->
                                apply_effect( this_player(),8, 8, 10 );
                return 1;
                }

                if (this_player()->query_temp("drink_water") == 1);
                {
                        tell_object(this_player(),
                        "你一口接著一口的把水池裡的水給喝完了，周圍的人都給"+
                        "了你熱烈的掌聲。\n不過這種虛榮心的滿足還是比不過你身"+
                        "體上的病痛，你覺得還是好好歇會兒比較恰當。\n");
                        (CONDITION_PREFIX + "simple_poison")->
                                apply_effect( this_player(),8, 10 );
                        this_player()->set_temp("drink_water",2);
                        moves = 3;
                return 1;
                }
		
        }
        if ((s != "water") && (s != "fountain"))
        {
                tell_object(this_player(),
                        "What?\n");
                return 1;
        }
}
int do_search(string s)
{
        object obj;
        if (s == "forest")
        {
        	moves = 1;
        	tell_object(this_player(),@LONG
你在森林的深處找到了一條清徹的小溪，原來就是你剛剛聽到的水聲，
你沿著河流慢慢往上走，看到了一個泛著慘綠色的噴水池(fountain)。
你心裡覺得奇怪，不知道這個噴泉池放在這邊幹嘛。
LONG
		);

		call_out("smell",10,this_player() );
        	return 1;
        	}

        if (s == "fountain")
        {
        switch(moves)
                {
                case 3:
                        tell_object(this_player(),
                                "你在噴水池底長的青苔裡找到一張小紙片。\n");
                        obj = new("/u/s/smore/obj/paper.c");
                        obj->move(this_player());
                        moves = 4;
                        return 1;
                case 2:
                        tell_object(this_player(),
                                "你把你的手伸近噴泉....不過那麼噁心"+
                                "的水....你想想還是算了。\n");
                        return 1;
                case 1:
                        tell_object(this_player(),
                                "你覺得沒事還是不要找事做比較好！\n");
                        return 1;

                case 0:
                        tell_object(this_player(),
                                "你找了又找，並沒有發現任何東西。\n");
                        return 1;
                case 4:
                        tell_object(this_player(),
                                "你找了又找，並沒有發現任何東西。\n");
                        return 1;
                }
        }

        if ((s != "fountain") || (s != "forest"))
        {
                tell_object(this_player(),
                        "你找了又找，並沒有發現任何東西。\n");
                return 1;
        }
}

string to_fountain()
{
        if (moves == 0)
        {
                return "哪來的噴泉啊？你走暈頭了吧....\n";
        }

        if (moves == 1)
        {
                moves = 2;
                return "這是一個年久失修的噴水池，池邊長滿了青苔，聯帶著連"+
                       "噴出來的泉水也被染成噁心的綠色，因此看起來似乎深不"+
                       "見底，不曉得裡面還會不會有啥噁心的東西放在裡面。\n";
        }
        if ((moves == 3) || (moves == 4))
        {
                return "噴水池的水不知道被誰給喝的一乾二淨了。\n";
        }
}

int smell()
{
	string name;
	name = (string)this_player()->query("name");
	tell_object(this_player(),
		"你忽然覺得口乾舌燥，可能是到處砍殺過度勞累吧。" );
	if (present(name,this_object() ))
	{
		tell_object(this_player(),@LONG
你看著眼前的泉水....
好像勉強可以喝(drink)....
LONG
		);
		return 1;
	}
	tell_object(this_player(),@LONG
你想到剛剛找到的那個
噴水池(fountain)，覺得雖然噁心，不過喝(drink)一些應該沒有大礙。
LONG
	);
	return 1;
}

void reset()
{
        ::reset();
        moves = 0;
}
