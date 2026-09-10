// This is an example file..
// vodka.c will be used in IRC pub
// Elon@Eastern.Stories Sat  08-13-94
 
// inherit file might change location someday... depends...
inherit "/u/e/elon/drink.c";
 
void create()
{
    ::create();
    seteuid(getuid());
    set_name("vodka","伏特加");
    set_short("vodka","伏特加");
    set_long("A small flat bottle vodka. You see the clear liquid inside.\n",
    "這是一小瓶伏特加, 你可以看見無色的液體在扁瓶中流動.\n");
    set("unit","瓶");
    set("e_unit","bottle");
 
    set("value",({75,"silver"}));
 
// tp, sp, hp effects.. delete those lines if no use.
    set("tp",20);
    set("sp",5);
}
