
// Room: /chang'an/changjie.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����һ�����֣���Զ�����õ�ͷ�����߶��Ǹ߸ߵ�Ժǽ�����²ȵ���
��ʯ�̳ɵ�·�档
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"gulou",
                "west"  : __DIR__"jiekou4",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}