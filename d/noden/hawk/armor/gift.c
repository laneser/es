#include <mudlib.h>

inherit ARMOR;

void create()
{
            set_name( "Gods gift","眾神的禮讚" );
            add( "id", ({ "gift","gods gift" }) );
            set_short( "眾神的禮讚" );
            set_long(@LONG
    這是奧林帕斯山上眾神賜與人間最強的防具，唯有具有高度智慧與強大力
量的人才有能力使用它。你仔細端詳這件足以覆蓋住你全身的寶物，上面所刻
精美絕倫的龍鳳紋正是諸神的證明。
LONG );
	set( "armor_class",20 );
	set( "defense_bonus",40);
	set( "type", "misc" );
            set( "equip_func","wear_func");
            set( "unequip_func","unwear_func");
	set( "weight", 120);
            set( "value" ,({ 410, "silver" }) );
}

void wear_func()
{
        string guild;
        guild = this_player()->query( "class" );
        set( "material", guild );
}

void unwear_func()
{
        set( "material", "cloth" );
}

int stop_wear(object player)
{
        player = this_player();

        if ( (player->query("armor/head")) || (player->query("armor/arms"))
          || (player->query("armor/misc")) || (player->query("armor/legs"))
          || (player->query("armor/finger")) )
        {
                write( "你穿了某種和諸神的禮讚相沖突的防具!\n");
                return 1;
        }

        else if ( (int)player->query_perm_stat("int") < 14 )
        {
                write( "諸神認為你是個笨蛋，不願你糟蹋這個禮物!\n");
                return 1;
        }
        else return 0;
}

void init()
{
        add_action( "do_wear", "wear");
}

int do_wear(string str)
{
        object wea1, wea2, obj, *ob, player, armor;
        string type, verb;
        int i;

        player = this_player();
        armor = this_object();
        obj = present( str, player );

        if ( !str || str == "" ) return 0;

        if ( str == "gift" || str == "gods gift" )
                return stop_wear( player );

        if ( str == "all" )
         {
                ob = all_inventory( player );

                if(!(player->query("armor/head")||player->query("armor/arms")
                  || player->query("armor/misc")||player->query("armor/legs")
                  || player->query("armor/finger") ) )
                 {
                        if ( !armor->query( "equipped" ) )
                         {
                                if ( !stop_wear( player ) )
                                 {
                                        armor->equip();
                                        armor->set( "equipped", 1 );
                                        write( "你順利地穿上眾神的禮讚。\n" );
                                        tell_room( environment(player),
                                                player->query("c_name")
                                                + "利地穿上眾神的禮讚。\n",
                                                player );
                                 }
                         }
                 }

                for ( i=0; i<sizeof(ob); i++ )
                 {
                        type = (string)ob[i]->query( "type" );

                        if ( !(ob[i]->query( "armor_class" )
                            || ob[i]->query( "defense_bonus" ) )
                            || ob[i]->query( "equipped" )
                            || player->query( "armor/" + type ) )
                                continue;

                        if ( ob[i] == armor ) continue;
                        if ( player->block_wear( ob[i] ) ) continue;
                        if ( ob[i]->stop_equip( player ) ) continue;

                        if ( type == "head" || type == "arms"
                          || type == "misc" || type == "legs"
                          || type == "finger" )
                         {
                                if ( armor->query( "equipped" ) ) continue;
                         }

                        if ( type == "shield" )
                         {
                                wea1 = player->query( "weapon1" );
                                wea2 = player->query( "weapon2" );

                                if( wea2 ) continue;
                                if( wea1 && (int)wea1->query("nosecond") == 1 )
                                         continue;
                         }

                        switch ( ob[i]->query( "equip_level" ) )
                         {
                                case 0 : verb = "順利地";   break;
                                case 1 : verb = "勉強地";   break;
                                case 2 : verb = "硬生生地"; break;
                                default : verb = "";        break;
                         }

                        switch ( type )
                         {
                                case "body":
                                case "legs":
                                case "feet":
                                case "cloak": verb += "穿上"; break;
                                case "head":
                                case "finger":
                                case "hands":
                                case "misc": verb += "戴上"; break;
                                case "globe": verb += "張開"; break;
                                case "shield": verb += "用手拿起"; break;
                                case "saddle": verb += "裝配上"; break;
                                case "kernel": verb += "吞下"; break;
                                case "arms":
                                case "tail": verb += "套上"; break;
                                default: verb += "穿上"; break;
                         }

                        ob[i]->equip();
                        write( "你" + verb
                               + (string)ob[i]->query("c_name") + "。\n" );
                        tell_room( environment( player ),
                                        (string)player->query( "c_name" )
                                        + verb
                                        + (string)ob[i]->query("c_name")
                                        + "。\n", player );
                 }
                write( "Ok.\n" );
                return 1;
         }

        if ( !obj ) return 0;

        type = obj->query( "type" );

        if ( type == "head" || type == "arms" || type == "misc"
          || type == "legs" || type == "finger" )
         {
                if ( armor->query( "equipped" ) )
                 {
                        write( "你已經穿了同類型的護甲了。\n" );
                        return 1;
                 }
                else return 0;
         }
        else return 0;
}
