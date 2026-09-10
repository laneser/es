
// A basic hockshop with a basic storeroom.

#include <move.h>
#include <mudlib.h>
#include <money.h>

inherit ROOM;
inherit COINVALUE;

 object storeroom;

object init_storeroom();

void create()
{
	seteuid(getuid());
	::create();
	set_short( "當鋪" );
        set_long( @LONG_DESCRIPTION
你現在走進了一間佈置得相當考究的廳院，門口一爿藍色的布簾上寫著
四個大字「東方第一當」，牆上有一張紙，大概是說一些當鋪的行事規
矩，烏檀木做成的隔窗後面正有一位老朝奉對著你笑。
LONG_DESCRIPTION
                );

      set("c_item_desc",(["paper":@C_LONG
這是一張十分陳舊的泛黃皮紙，上面被人用烏亮的濃墨揮灑著
流利的隸書，使你看的心曠神怡。寫著 ：
          
    親愛的同仁老當客戶大爺們，小店一向秉持誠信態度為客戶服務    
，然為避免不必要之糾紛，特此公告小鋪之條規以昭大信，盼小店與
客戶共同遵循，相互規矩為是。下列條規 ：
             
    一、物品當值均以時價折抵保管費後計算。
     ⒈鏡曜疃嘀喚郵芡晃豢突拇偽９芪小�
    三、所託物品在本店盤點時間之前未取者視同流當，小店得任意處置。
    四、取回託物時本鋪得酌量收取保管費與利息。
                   
    小店的營業項目有： 當物 (pawn)、贖回當物(take)、查詢當物(list)
，請您多多照顧小店的生意。謝謝 !!
       
    有需要託物服務的請面洽本鋪大朝奉。                
C_LONG
]));
                                                            
                                                            


	/* Force the warehouse to load, if it's not loaded  */
	storeroom = init_storeroom();
}

void init()
{
	add_action("list", "list");
	add_action("take", "take");
	add_action("impawn", "pawn");
//	add_action("enter_storeroom", "storeroom");
}

object init_storeroom()
{
	object *room, stroom;
	int i;

	room = children("/std/shop/storeroom");
	for(i=0; i<sizeof(room); i++) {
		if( (string)room[i]->query("linked_shop")==base_name(this_object()) )
			return room[i];
	}
	stroom = new("/d/eastland/goomay/storeroom");
	if( stroom ) return stroom;
	else throw( "Shop: Error in loading storeroom.\n" );
}


void convert_value( object ob )
{
	mixed *value;
	int val;

	value = ob->query( "value" );
	if( !value || !pointerp(value) ) {
		ob->delete("value");
		return;
	}
	if( !intp(value[0]) || value[0]==0 || !stringp(value[1]) ) {
		ob->delete("value");
		return;
	}
	val = value[0] * coinvalue( value[1] ) / coinvalue("silver");
	if( val==0 ) val = 1;
	ob->set( "value", ({ val, "silver" }) );
	return;
}

int list(string arg)
{
	int i, number;
	mixed *value;
	mixed *ob;
	string type;

	write("你當在這裡的物品有 :\n");

	/* Objects in local storage */
	ob = all_inventory(storeroom);
	if( arg && arg!="" ) 
	   ob = filter_array(ob, "filter_inv", this_object(), arg);
	
	for (i=0; i<sizeof(ob); i++)
	{
	if ((string)ob[i]->query("owner") != (string)this_player()->query("name")) continue;
		value = ob[i]->query("value");
		if (!value) continue;
		type = value[1];
		number = value[0]*3/4;
		if (number==0) continue;

			printf("  %-34s %5d %s\n", ob[i]->query("short")
			+ "(" + ob[i]->query("name") + ")",
			number, to_chinese(type + " coin") );
	}

	return 1;
}

int filter_inv(object ob, string name)
{
	if( name=="weapons" && !undefinedp(ob->query("weapon_class")) ) return 1;
	if( name=="armors" && !undefinedp(ob->query("armor_class")) ) return 1;
	else return (int)ob->id(name);
}

int take(string str)
{
	int number, res, skill,i,j;
	string type, unit,owner;
	object ob;
	mixed *value;
	mixed *ob2,*ob3;

	owner=this_player()->query("name");
	/* Look for the object, first in central storage then in local storage. */
	if (!str)
		return notify_fail( 
			"您要贖回什麼？\n");

        if( str && str!="" )
	{
        ob2 = all_inventory(storeroom);
        for (i=0; i<sizeof(ob2); i++)
        {
	if ((string)ob2[i]->query("owner") != owner) continue;
	ob3=ob2[i]->query("id");
	for (j=0; j<sizeof(ob3); j++)
	  {
		if (ob3[j] != str) continue;
		else 
		{
			ob=ob2[i];
			i=sizeof(ob2)-1;
			j=sizeof(ob3)-1;
		}
	  }
	}

	}

	if (!ob)
		return notify_fail(
			"你沒有在店裡當過這樣的東西。\n");

	value = ob->query("value");
	if( !value) {
		ob->remove();
		return notify_fail( 
			"這樣東西不應該出現店裡....。\n");
	}
	type = value[1];
	number = value[0]*3/4;
	if( number==0) {
		ob->remove();
		return notify_fail( 
			"這樣東西不應該出現店裡....。\n");
	}
	skill = this_player()->query_skill("trading");
	number -= number * random(skill) / 300;

	// Check to see if the player has exact change.
	if( this_player()->debit( type, number ) ) {
		// See if the player can carry the object.
		res = ob->move(this_player());
		if (res==MOVE_OK) {
			ob->delete("owner");
			if( skill > 0 ) write( 
				"經過一番討價還價，");
			if( !(unit = ob->query("unit")) ) unit = "個";
			write(
				"你花 " + number + " 枚" + to_chinese(type + " coin") + "贖回一" + unit + ob->query("short") + "。\n");
			tell_room( this_object(), 
				this_player()->query("c_name")+"贖回一"+unit+ob->query("short")+"。\n",
				this_player());
			return 1 ;
		} else {
			// Give him his money back.
			this_player()->credit( type , number );
			return notify_fail(
				"你已經扛不動其他東西了。\n");
		}
	}

	return notify_fail(
		"你身上沒有合適的錢幣能贖回這樣東西。\n");
}
/*
int in_storeroom( object item ) {
    object *items;
    string item_name;
    int i, count, storage;
    
    items = all_inventory(storeroom);
    if( !storeroom->query("storage") ) storage = 1;
    else storage = (int)storeroom->query("storage");
    if( storage < 1 ) storage = 1;
    count = 0;
    if( !sizeof(items) ) return 0;
    item_name = (string)item->query("name");
    for( i=0; i<sizeof(items); i++ )
      if( item_name == (string)items[i]->query("name") )
        count++;
      if( count >= storage ) return 1;
    return 0;
}
*/

int impawn(string str)
{
	int *rate, i, j, l, will_remove, res, skill;
	object ob,*ob2 ;
	string type, unit;
	mixed *value ;
	int number ;

	skill = this_player()->query_skill( "trading" );
        if (this_player()->query("make-up")) return notify_fail("本店不和戴面具的客人交易。\n");
	if (!str) 
		return notify_fail( 
			"你要當什麼東西？\n");

	ob = present(str, this_player()) ;
	if (!ob)
		return notify_fail( 
			"你沒有這樣東西。\n");
	if ( this_player()->query("make-up"))
		return notify_fail("請先去除化裝後再來當東西 !!\n");

	convert_value(ob);
	value = ob->query("value");
	if( !value )
		return notify_fail( 
			"那東西不值錢\n");

	ob2 = all_inventory(storeroom);
	j=0;
	for (i=0; i<sizeof(ob2); i++)
	{
        if ((string)ob2[i]->query("owner") != (string)this_player()->query("name")) continue;
	j++;
	}
	if (j>=4)
	return notify_fail( 
	"你已經當了四件東西在店裡了。\n" );
    number = value[0]*3/4 ;
	if (!this_object()->query("rating"))
	  number = number * SHOP_SALES_FRAC;
	else {
	rate = (int *)this_object()->query("rating");
	  number = number * rate[0] / rate[1];
	}
	number -= number * ( 75 - skill ) / 200;
	if(number>1000) number = 1000;

	if( ob->query("prevent_drop") || ob->query("secure") ||
		ob->query("prevent_insert") )
		return notify_fail(
			"你不能當這樣東西。\n");
	type = value[1];

	res = ob->move(storeroom) ;
	if (res != MOVE_OK)
		return notify_fail( 
			"對不起，商店不收這種東西。\n");

	this_player()->credit(type, number) ;
	ob->set("owner",this_player()->query("name"));
	if( !(unit = ob->query("unit")) ) unit = "個";
	write( 
		"你當掉"+ob->query("short")+"，獲得 "+ number +" 塊"+ to_chinese(type+" coin")+"。\n");
	tell_room( this_object(), 
		this_player()->query("c_name")+"當掉一"+unit+ob->query("short")+"。\n",
		this_player() );

	return 1;
}

int enter_storeroom()
{
	if (!wizardp(this_player())) return 0;
	this_player()->move(storeroom);
	write( "你偷偷溜進店裡的儲藏室.\n");
	say( this_player()->query("c_name") + "突然不見了.\n");
	return 1 ;
}

object storeroom() { return storeroom; }

void clean_up() { return 0; }
