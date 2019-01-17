
// Room: /chang'an/yuelaikedian.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "悦来客店");
        set("long", @LONG
这是一家对西北各类人士来说很有名气的客栈。人们到长安来一般都
住在这里，其中也不乏一些西域人，大家贪图的无非一是价格合适，居住
舒服；二能听到些江湖上的许多传闻。
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "west"  : __DIR__"nandajie2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}