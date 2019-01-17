
// Room: /jingzhou/bingyingdamen.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "兵营大门");
        set("long", @LONG
你正站在兵营的门口，由于蒙古兵要再次攻打襄阳的谣言四起，荆州
的守将也在积极备战，面对着一排简陋的营房，可以看到穿着制服的军士
正在操练，不时地传来呐喊声。你最好赶快走开，免得被当做探子抓起来
可冤枉了。
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "south" : __DIR__"zhangjuzhengjie",
                "north" : __DIR__"bingying",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}