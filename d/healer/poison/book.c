// book.c		五毒秘傳
//
//	放藥方的書
//
//			Lilia

#include <mudlib.h>
#include <conditions.h>

#define LIST_PATH "/d/healer/poison/"

inherit OBJECT;

void init()
{
    add_action("read_book", "read");
}

void create()
{
    seteuid(getuid());
    add("id", ({"drug", "book"}));
    set_name("drug book", "五毒秘傳");
    set_short("drug book", "五毒秘傳");
    set_long("這是一本破破爛爛的書，封面上題著幾個模糊不清的字：『五毒秘傳』\n");
    set("unit", "本");
    set("no_sale", 1);
    set("bulk", 1);
    set("mass", 1);
}

string query_index()
{
    string index;

    index = "毒者，傷身之藥也。故使毒之人，必先明藥理，識本草，理脈氣，\n"
	    "方能製毒而不制於毒。餘自垂髫之齡，蒙先尊之教誨，方窺毒理門\n"
	    "徑之一二，為恐先人神技，至餘失傳，是以筆之於書，以待有緣。\n"
	    "吾門秘方，非不得已而用之，望有緣人切記。\n\n"
	    "				    		 龍女\n";

    return index;
}

int read_book(string str)
{
    object owner;
    int page;
    owner = this_player();

    // 沒戴手套就想碰五毒秘傳的話 .... 嘿嘿 ....
    // 眼魔沒有手

    if ( !(owner->query("armor/hands")) && owner->query("race") != "beholder" ) 
    {
	tell_object(owner, "你的手接觸書頁之後，突然感到一陣麻癢！\n");
        (CONDITION_PREFIX + "simple_poison")->apply_effect(owner, 8, 8);
        return 1;
    }

    if (str == "book" || str == "drug" || str == "五毒秘傳")
    {
	write("你小心地揭開了封面，專心地讀了起來 ...\n\n");
        write(query_index());
	write("\n看了半天實在看不懂她在講什麼，你不禁想趕快找找藥方(list)寫在那裡 ...\n");
	return 1;
    } else if (str == "list") {
        cat(LIST_PATH"list");
        return 1;
    } else if (sscanf(str, "page %d", page) == 1) {
	if (file_exists(LIST_PATH"page" + page))
	{
	    cat(LIST_PATH"page" + page);
	    return 1;
   	} else {
            write("你翻來翻去，就是找不著這頁，似乎是被人撕去了 ....\n");
            return 1;
	}
    } else {	
	return notify_fail("讀什麼？\n");
    }
}


