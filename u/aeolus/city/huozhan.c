// Room: /d/city/huozhan.c

inherit ROOM;

void init();

void create()

{

set("short", "货栈");

set("long", @LONG

        这里是一间货栈，也是旅行客商们储放货物，运送转交

的地方，扬州是中原的一个大城镇，所以货栈往来的货物相当的

多，因此成为少数几个设有货栈的地方，各地的货栈大多数都互

相连系，因此商业十分发达，忙碌的货栈也常常是缺钱的人打零

工的地方，因为货栈的工作量不固定，有大批货物进来的时候往

往需要平常十几倍的人手，但是货栈的利润又少，因此雇不起长

期的工人　。

LONG

);

set("exits", ([ /* sizeof() == 1 */

"east" : "/d/wudang/wdroad1",

]));

set("objects", ([

"/d/city/npc/foreman" : 1,

"/d/city/npc/obj/crate" : 3,

]));

set("no_fight", 1);

setup();

}

