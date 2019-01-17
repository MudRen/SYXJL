// Room: /chang'an/laofang.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "牢房");
        set("long", @LONG
这里关押的一般是一些犯了小法或者做了有伤风化的事情的人，反正
也就是象征性地关上一段时间，以示小惩大戒。北墙上挂着一些衣物，南
墙上歪歪扭扭地写着“廉耻”二字。
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "south" : __DIR__"xunbufang",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}