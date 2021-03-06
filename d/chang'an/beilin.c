
// Room: /chang'an/beilin.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "碑林");
        set("long", @LONG
碑林由于碑石耸立如林而得名。内藏有著名的石刻经书《开成石经》、
《石台孝经》、《大秦景教流行中国碑》、欧阳询的《皇甫诞碑》、颜真
卿的《多塔碑》和《颜氏家庙碑》、柳公权的《玄秘塔碑》、怀素的《千
字文碑》和张旭的《断千字文碑》、李阳冰的《三坟记碑》、以及《宋淳
化秘阁帖》等著名碑石。
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "west"  : __DIR__"nandajie1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}