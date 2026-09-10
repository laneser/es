// This is an example file..
// pepsi.c, unit is can (罐裝)
// Elon@Eastern.Stories Mon  08-01-94
 
inherit "/d/translate/tmp/drink.c";
 
void create()
{
    ::create();
    seteuid(getuid());
    set_name("pepsi","百事可樂");
    set_short("Pepsi Cola","百事可樂");
    set_long("Pepsi, Uh-Huh!\n",
    "新生代的百事可樂.\n");
    set("unit","罐");  // 瓶, 杯, 罐, 袋(?)
    set("e_unit","can"); // can, bottle, cup, bag(?)
    set("value",({45,"silver"}));
    set("tp",45);
}
