inherit ROOM;

void create()
{
        set("short", "紫云崖");
        set("long", @LONG
此处奇景又是一绝，崖岭弯曲回转，东方红日露出云层半截一映，
满天云雾霎时紫色一片，外深内淡，仿佛这崖边的云彩原本就是紫色。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"taohua",
  "west" : __DIR__"wulao",
]));
        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
